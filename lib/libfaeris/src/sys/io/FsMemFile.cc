/*************************************************************************/
/*  FsMemFile.cc                                                         */
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
#include "sys/io/FsMemFile.h"

#define FS_MEM_FILE_DEFAULT_SIZE 128

NS_FS_BEGIN
MemFile* MemFile::create()
{
	MemFile* ret=new MemFile;
	if(!ret->init())
	{
		delete ret;
	}
	return ret;
}

MemFile* MemFile::create(ulong len)
{
	MemFile* ret=new MemFile;
	if(!ret->init(len))
	{
		delete ret;
	}
	return ret;
}

MemFile* MemFile::create(const void* mem,ulong len)
{
	MemFile* ret=new MemFile;
	if(!ret->init(mem,len))
	{
		delete ret;
	}
	return ret;
}

long MemFile::read(void* buf,long len)
{
	assert(m_pos<=m_length);
	if(m_pos+len>=m_length)
	{
		len=m_length-m_pos;
	}
	if(len==0)
	{
		return 0;
	}
	memcpy(buf,m_mem+m_pos,len);
	m_pos+=len;

	return len;
}

long MemFile::write(const void* buf,long len)
{
	ensureMore(len);
	memcpy(m_mem+m_pos,buf,len);
	m_pos+=len;
	return len;
}

long MemFile::seek(long offset,E_FileSeek where)
{
	switch(where)
	{
		case E_FileSeek::SET:
			m_pos=offset;
			break;
		case E_FileSeek::CUR:
			m_pos+=offset;
			break;
		case E_FileSeek::END:
			m_pos=m_length+offset;
	}

	if(m_pos>m_length)
	{
		m_pos=m_length;
	}

	/*
	if(m_pos<0) 
	{
		m_pos=0;
	}
	*/

	return m_pos;
}
long MemFile::tell()
{
	return m_pos;
}

int MemFile::close()
{
	/* Do Nothing Here */
	return 0;
}


const char* MemFile::className()
{
	return FS_MEM_FILE_CLASS_NAME;
}


void* MemFile::getInternalBuffer()
{
	return m_mem;
}


MemFile::MemFile()
{
	m_mem=NULL;
	m_length=0;
	m_cap=0;
	m_pos=0;
}

MemFile::~MemFile()
{
	if(m_mem)
	{
		delete[] m_mem;
	}
}

bool MemFile::init()
{
	m_mem=new uint8_t[FS_MEM_FILE_DEFAULT_SIZE];
	m_length=0;
	m_cap=FS_MEM_FILE_DEFAULT_SIZE;
	m_pos=0;
	return true;
}
bool MemFile::init(ulong len)
{
	ensureMore(len);
	return true;
}

bool MemFile::init(const void* mem,ulong len)
{
	ensureMore(len);
	memcpy(m_mem,mem,len);
	return true;
}

void MemFile::ensureMore(ulong len)
{
	ulong old_length=m_length;
	if(m_pos+len>m_length)
	{
		m_length=m_pos+len;
	}

	if(m_length>m_cap)
	{
		ulong new_size=m_cap==0?FS_MEM_FILE_DEFAULT_SIZE:m_cap;

		while(new_size<m_length)
		{
		   	new_size<<=1;
		}

		uint8_t* new_men=new uint8_t[new_size];
		if(m_mem)
		{
			memcpy(new_men,m_mem,old_length);
			delete[] m_mem;
		}
		m_mem=new_men;
		m_cap=new_size;
	}
}

NS_FS_END

