/*************************************************************************/
/*  FsFgzReader.cc                                                       */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include <string.h>
#include "support/data/FsFgzReader.h"
#include "support/util/FsDict.h"
#include "support/util/FsString.h"
#include "sys/io/FsSegFile.h"
#include "sys/io/FsMemFile.h"
#include "sys/io/FsFile.h"
#include "support/data/FsDeflate.h"


NS_FS_BEGIN

static char _FgzGLobalMagicNu[8]=FS_FGZ_MAGIC_NU;
static char _FgzFileMagicNu[8]=FS_FGZ_FILE_MAGIC_NU;



typedef struct  
{
	uint8_t 	m_magicNu[8]; 
	uint32_t 	m_fileNu;
	uint32_t	m_offset;

}FgzGlobalHeader;


typedef struct 
{
	uint8_t  m_magicNu[8];
	uint32_t m_method;
	uint32_t m_ensize;
	uint32_t m_unsize;
	uint32_t m_crc32;
	uint32_t m_filenameLength;
}FgzFileHeader;



class FgzFileInfo:public FsObject
{
	public:
		static FgzFileInfo* create()
		{
			return new FgzFileInfo();
		}


	public:
		virtual const char* className()
		{
			return "FgzFileInfo";
		}

	public:
		void setFileName(const char* name)
		{
			FsString* str=FsString::create(name);
			FS_SAFE_ASSIGN(m_filename,str);
		}
		void setDataOffset(uint32_t offset)
		{
			m_dataOffset=offset;
		}

	protected:
		FgzFileInfo()
		{
			m_filename=NULL;
		}

		virtual ~FgzFileInfo()
		{
			FS_SAFE_DEC_REF(m_filename);
		}


	public:
		FsString* m_filename;
		FgzFileHeader m_header;
		uint32_t m_dataOffset;
};


FgzReader* FgzReader::create(FsFile* file)
{
	FgzReader* ret=new FgzReader();
	if(!ret->init(file))
	{
		delete ret;
		ret=NULL;
	}
	return ret;
}




FsFile* FgzReader::takeFile(const char* filename)
{
	FgzFileInfo* info=(FgzFileInfo*)m_files->lookup(filename);
	FsFile* ret=NULL;

	if(info==NULL)
	{
		//FS_TRACE_INFO("Can't Find File(%s) In FgzPackage",filename);
		return NULL;
	}

	if(info->m_header.m_method==FS_FGZ_STORE)
	{
		ret=SegFile::create(
				m_stream,
				info->m_dataOffset,
				info->m_header.m_unsize);

	}
	else if(info->m_header.m_method==FS_FGZ_DEFLATE)
	{
		uint32_t file_size=info->m_header.m_unsize;
		ret=MemFile::create(file_size);
		char* buffer=(char*) (((MemFile*)ret)->getInternalBuffer());
		char* compress_buf=new char[info->m_header.m_ensize];

		do{
			if(m_stream->seek(info->m_dataOffset,E_FileSeek::SET)==-1)
			{
				ret->decRef();
				delete[] compress_buf;
				ret=NULL;
				break;
			}

			if(m_stream->read(compress_buf,info->m_header.m_ensize)!=(int)info->m_header.m_ensize)
			{
				ret->decRef();
				delete[] compress_buf;
				ret=NULL;
				break;
			}

			if(FsDeflate_UnCompress(
					(const uint8_t*) compress_buf,
					info->m_header.m_ensize,
					(uint8_t*) buffer,
					&file_size)==-1)
			{
				ret->decRef();
				delete[] compress_buf;
				ret=NULL;
				break;
			}

			delete[] compress_buf;
			compress_buf=NULL;
		}while(0);
	}
	else 
	{
		FS_TRACE_WARN("UnSupport Compress Method");
	}

	FS_SAFE_ADD_REF(ret);

	return ret;
}

const char* FgzReader::className()
{
	return "FgzReader";
}

FgzReader::FgzReader()
{
	m_files=NULL;
	m_stream=NULL;
}

FgzReader::~FgzReader()
{
	destruct();
}

bool FgzReader::init(FsFile* file)
{
	FgzGlobalHeader g_header;
	int i,file_nu=0,file_data_pos=0;
	FsDict* fileset=FsDict::create();

	int file_name_length;
	int current_offset;
	char* name_buf=NULL;
	FgzFileInfo* info=NULL;



	int ret=file->seek(0,E_FileSeek::SET);
	if(ret<0)
	{
		goto error;
	}

	/* read global header */
	ret=file->read(&g_header,sizeof(g_header));
	if(ret!=sizeof(g_header))
	{
		FS_TRACE_WARN("Can't Read Global Header Info For FgzPackage");
		goto error;
	}

	if(memcmp(&g_header.m_magicNu,_FgzGLobalMagicNu,8)!=0)
	{
		FS_TRACE_WARN("File Is Not FgzPackage");
		goto error;
	}

	file_nu=g_header.m_fileNu;

	current_offset=g_header.m_offset;

	for(i=0;i<file_nu;i++)
	{

		ret=file->seek(current_offset,E_FileSeek::SET);
		if(ret<0)
		{
			FS_TRACE_WARN("Seek Error");
			goto error;
		}


		info=FgzFileInfo::create();

		ret=file->read(&info->m_header,sizeof(info->m_header));

		/* read file header */
		if(ret!=sizeof(info->m_header))
		{
			FS_TRACE_WARN("FgzPackage Damaged");
			info->decRef();
			goto error;
		}

		/* compare file header */
		if(memcmp(&info->m_header,_FgzFileMagicNu,8)!=0)
		{
			FS_TRACE_WARN("FgzPackage Damaged");
			info->decRef();
			goto error;
		}

		/* read file name */
		file_name_length=info->m_header.m_filenameLength;
		name_buf=new char[file_name_length+1];
		ret=file->read(name_buf,file_name_length);

		if(ret!=file_name_length)
		{
			delete[] name_buf;
			info->decRef();
			goto error;
		}
		name_buf[file_name_length]='\0';

		info->setFileName(name_buf);
		delete[] name_buf;

		file_data_pos=current_offset+sizeof(FgzFileHeader)+info->m_header.m_filenameLength;
		info->setDataOffset(file_data_pos);




		/* update current offset to read next file */
		current_offset+=sizeof(FgzFileHeader)+info->m_header.m_filenameLength+info->m_header.m_ensize;

		//FS_TRACE_INFO("add File %s",info->m_filename->cstr());
		fileset->insert(info->m_filename,info);
		info=NULL;
	}

	file->addRef();
	m_stream=file;
	m_files=fileset;

	return true;

error:
	fileset->decRef();
	return false;
}

void FgzReader::destruct()
{
	FS_SAFE_DEC_REF(m_files);
	FS_SAFE_DEC_REF(m_stream);
}



NS_FS_END






















