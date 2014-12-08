#include "support/data/FsZipReader.h"
#include "unzip.h"
#include "sys/io/FsMemFile.h"
#include "sys/io/FsSegFile.h"
#include "sys/io/FsFile.h"


NS_FS_BEGIN




static voidpf _ZipReader_OpenFileFunc(voidpf opaque,const char* filename,int mode)
{
	return (voidpf) filename;
}

static uLong _ZipReader_ReadFileFunc(voidpf opaque,voidpf stream,void* buf,uLong size)
{
	FsFile* file=(FsFile*)stream;
	int readbyte=file->read(buf,size);
	return readbyte;
}

static long _ZipReader_TellFileFunc(voidpf opaque,voidpf stream)
{
	FsFile* file=(FsFile*)stream;
	return file->tell();
}


static int _ZipReader_CloseFileFunc(voidpf opaque,voidpf stream)
{
	return 0;
}


static int _ZipReader_ErrorFileFunc(voidpf opaque,voidpf stream)
{
	FS_TRACE_WARN("Zip Reader Io Error");
	return 0;
}

static long _ZipReader_SeekFileFunc(voidpf opaque,voidpf stream,uLong offset,int origin)
{
	FsFile* file=(FsFile*)stream;
	switch(origin)
	{
		case  ZLIB_FILEFUNC_SEEK_CUR:
			file->seek(offset,E_FileSeek::CUR);
			break;

		case ZLIB_FILEFUNC_SEEK_END:
			file->seek(offset,E_FileSeek::END);
			break;
			
		case ZLIB_FILEFUNC_SEEK_SET:
			file->seek(offset,E_FileSeek::SET);
			break;
	}
	return 0;
}

static zlib_filefunc_def  _zlib_func=
{
	_ZipReader_OpenFileFunc,
	_ZipReader_ReadFileFunc,
	0,
	_ZipReader_TellFileFunc,
	_ZipReader_SeekFileFunc,
	_ZipReader_CloseFileFunc,
	_ZipReader_ErrorFileFunc,
	0,
};




ZipReader* ZipReader::create(FsFile* file)
{
	unzFile unz_file=unzOpen2((const char*) file,&_zlib_func);
	if(unz_file==NULL)
	{
		return NULL;
	}

	ZipReader* ret=new ZipReader();
	ret->init(file,unz_file);
	return ret;
}

const char* ZipReader::className()
{
	return FS_ZIP_READER_CLASS_NAME;
}

ZipReader::ZipReader()
{
	m_unzfile=0;
	m_stream=0;
}

ZipReader::~ZipReader()
{
	destruct();
}

bool ZipReader::init(FsFile* file,void* unz_file)
{
	m_stream=file;
	file->addRef();
	m_unzfile=unz_file;
	return true;
}

void ZipReader::destruct()
{
	if(m_unzfile)
	{
		unzClose(m_unzfile);
		m_unzfile=0;
	}
	if(m_stream)
	{
		m_stream->decRef();
		m_stream=0;
	}
}

FsFile* ZipReader::takeFile(const char* filename)
{
	if(unzLocateFile(m_unzfile,filename,true)!=UNZ_OK)
	{
	//	FS_TRACE_INFO("File(%s) Not Found In Zip Package",filename);
		return NULL;
	}

	unz_file_info file_info;
	if(unzGetCurrentFileInfo(m_unzfile,&file_info,NULL,0,NULL,0,NULL,0)!=UNZ_OK)
	{
		FS_TRACE_WARN("Can't Get Current File Info");
		return NULL;
	}


	/* file compressed, so uncompress it and return memfile */
	if(file_info.compression_method!=0)
	{
		if(unzOpenCurrentFile(m_unzfile)!=UNZ_OK)
		{
			FS_TRACE_WARN("Open Current File Failed");
			return NULL;
		}

		int file_size=file_info.uncompressed_size;
		MemFile* ret=MemFile::create(file_size);
		char* buffer=(char*)ret->getInternalBuffer();

		int read_byte=unzReadCurrentFile(m_unzfile,buffer,file_size);

		if(read_byte!=file_size)
		{
			FS_TRACE_WARN("Can't Read Full Size Of File");
			ret->decRef();
			unzCloseCurrentFile(m_unzfile);
			return NULL;
		}

		unzCloseCurrentFile(m_unzfile);
		return ret;

	}
	else  /* file is store in the zip package */
	{
		int file_size=file_info.uncompressed_size;
		int offset=unzextGetFileOffset(m_unzfile);
		SegFile* file=SegFile::create(m_stream,offset,file_size);
		return file;
	}

}

NS_FS_END



















