#include "sys/io/FsSegFile.h"

NS_FS_BEGIN 


const char* SegFile::className()
{
	return FS_SEG_FILE_CLASS_NAME;
}


SegFile* SegFile::create(FsFile* file,uint32_t offset,uint32_t length)
{
	SegFile* ret=new SegFile;
	if(!ret->init(file,offset,length))
	{
		delete ret;
		ret=NULL;
	}

	return ret;
}

long SegFile::read(void* buf,long length)
{
	if(m_stream==NULL)
	{
		FS_TRACE_WARN("File Close Or Error");
		return -1;
	}

	int rest=m_length-m_curpos;

	if(rest==0)    /* no data to read */
	{
		return 0;
	}

	if(length>rest)  /* not enough data to read */
	{
		length=rest;
	}


	m_stream->seek(m_offset+m_curpos,E_FileSeek::SET);
	int readbyte=m_stream->read(buf,length);
	if(readbyte>0)
	{
		m_curpos+=readbyte;
	}
	return readbyte;
}

long SegFile::write(const void* buf,long length)
{
	if(m_stream==NULL)
	{
		FS_TRACE_WARN("File Closed Or Error");
		return -1;
	}

	int rest=m_length-m_curpos;
	if(rest==0)
	{
		return 0;
	}

	if(length>rest)
	{
		length=rest;
	}

	m_stream->seek(m_offset+m_curpos,E_FileSeek::SET);
	int writebyte=m_stream->write(buf,length);
	if(writebyte>0)
	{
		m_curpos+=writebyte;
	}
	return writebyte;
}

long SegFile::seek(long offset,E_FileSeek where)
{
	if(m_stream==NULL)
	{
		FS_TRACE_WARN("File Closed Or Error");
		return -1;
	}

	int pos=0;
	switch(where)
	{
		case E_FileSeek::SET:
			{
				pos=offset;
			}
			break;
		case E_FileSeek::CUR: 
			{
				pos=m_curpos+offset;
			}
			break;
		case E_FileSeek::END:
			{
				pos=m_length+offset;
			}
			break;
	}
	if(pos<0)
	{
		m_curpos=0;
	}
	else if(pos>(int)m_length)
	{
		m_curpos=m_length;
	}
	else 
	{
		m_curpos=pos;
	}
	return 0;
}


int SegFile::close()
{
	if(m_stream==NULL)
	{
		FS_TRACE_WARN("File Closed Or Error");
		return -1;
	}

	m_stream->decRef();
	m_stream=NULL;
	return 0;
}


long SegFile::tell()
{
	if(m_stream==NULL)
	{
		FS_TRACE_WARN("File Closed Or Error");
		return -1;
	}

	return m_curpos;
}


long SegFile::getLength()
{
	if(m_stream==NULL)
	{
		FS_TRACE_WARN("File Closed Or Error");
		return -1;
	}

	return m_length;
}

SegFile::~SegFile()
{
	destruct();
}


SegFile::SegFile()
{
	m_stream=0;
	m_offset=0;
	m_length=0;
	m_curpos=0;
}

void SegFile::destruct()
{
	FS_SAFE_DEC_REF(m_stream);
	m_stream=0;
	m_offset=0;
	m_length=0;
	m_curpos=0;
}

bool SegFile::init(FsFile* file,uint32_t offset,uint32_t length)
{
	FS_SAFE_ADD_REF(file);
	m_stream=file;
	m_offset=offset;
	m_length=length;
	m_curpos=0;
	return true;
}







NS_FS_END 






















