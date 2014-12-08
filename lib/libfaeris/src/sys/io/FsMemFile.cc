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

