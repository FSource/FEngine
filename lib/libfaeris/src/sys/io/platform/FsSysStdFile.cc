#include <stdio.h>

NS_FS_BEGIN

SysFile* SysFile::ms_stdout=NULL;
SysFile* SysFile::ms_stdin=NULL;
SysFile* SysFile::ms_stderr=NULL;

SysFile* SysFile::getStdout()
{
	if(ms_stdout==NULL)
	{
		ms_stdout=new SysFile(stdout);
		ms_stdout->addRef();
	}
	return ms_stdout;
}
SysFile* SysFile::getStdin()
{
	if(ms_stdin==NULL)
	{
		ms_stdin=new SysFile(stdin);
		ms_stdin->addRef();
	}
	return ms_stdin;
}
SysFile* SysFile::getStderr()
{
	if(ms_stderr==NULL)
	{
		ms_stderr=new SysFile(stderr);
		ms_stderr->addRef();
	}
	return ms_stderr;
}


SysFile* SysFile::create(const char* name,uint mode)
{
	FILE* f=NULL;
	switch(mode)
	{
		case FsFile::FS_IO_RDONLY:
			f=fopen(name,"rb");
			break;
		case FsFile::FS_IO_WRONLY:
		case FsFile::FS_IO_RDWR:
			f=fopen(name,"r+b");
			break;
		case FsFile::FS_IO_APPEND:
			f=fopen(name,"ab");
			break;
		case FsFile::FS_IO_TRUNC:
			f=fopen(name,"wb");
			break;
		case FsFile::FS_IO_CREATE:
			f=fopen(name,"w+b");
			break;
		default:
			if(mode&FsFile::FS_IO_TRUNC)
			{
				f=fopen(name,"w+b");
			}
			else if(mode&FsFile::FS_IO_APPEND)
			{
				f=fopen(name,"ab");
			}
			else if(mode&FsFile::FS_IO_APPEND&FsFile::FS_IO_CREATE)
			{
				f=fopen(name,"a+b");
			}
			else
			{
				f=fopen(name,"r+b");
			}
			break;
	}
	
	if(f==NULL)
	{
	//	FS_TRACE_ERROR("Open File(%s) Failed",name);
		return NULL;
	}
	return new SysFile(f);
}

long SysFile::read(void* buf,long length)
{
	long readbyte=fread(buf,1,length,m_platfromFile);
	return readbyte;
}

long SysFile::write(const void* buf,long length)
{
	return fwrite(buf,1,length,m_platfromFile);
}
long SysFile::seek(long offset,E_FileSeek where)
{
	long ret;
	switch(where)
	{
		case E_FileSeek::CUR:
			ret=fseek(m_platfromFile,offset,SEEK_CUR);
			break;
		case E_FileSeek::SET:
			ret=fseek(m_platfromFile,offset,SEEK_SET);
			break;
		case E_FileSeek::END:
			ret=fseek(m_platfromFile,offset,SEEK_END);
			break;
		default:
			ret=-1;
	}
	return ret;
}
long SysFile::tell()
{
	return ftell(m_platfromFile);
}
int SysFile::close()
{
	int ret=0;
	if(m_platfromFile)
	{
		ret=fclose(m_platfromFile);
		m_platfromFile=NULL;
	}
	return ret;
}
SysFile::~SysFile()
{
	if(m_platfromFile!=NULL)
	{
		fclose(m_platfromFile);
		m_platfromFile=NULL;
	}
}

NS_FS_END
