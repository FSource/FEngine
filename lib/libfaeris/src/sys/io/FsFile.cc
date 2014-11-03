#include "FsFile.h"
#include "stdarg.h"
#include "stdio.h"
NS_FS_BEGIN
const char* FsFile::className()
{
	return FS_FILE_CLASS_NAME;
}

long FsFile::writeStr(const char* fmt,...)
{
	int cnt=1024;
	long fmt_byte=0;

	while(1)
	{
		char* buffer=new char[cnt];

		va_list argptr;
		va_start(argptr,fmt);
		fmt_byte=vsnprintf(buffer,cnt,fmt,argptr);
		va_end(argptr);
		if(fmt_byte<cnt)
		{
			buffer[fmt_byte]='\0';
			write(buffer,fmt_byte);
			delete[] buffer;
			break;
		}
		cnt*=2;
		delete[] buffer;
	}
	return  fmt_byte;
}

long FsFile::getLength()
{
	long cur_pos=tell();
	seek(0,E_FileSeek::END);

	long length=tell();
	seek(cur_pos,E_FileSeek::SET);
	return length;
}

const char* FsFile::getFileName()
{
	return  m_filename.c_str();
}

void FsFile::setFileName(const char* name)
{
	if(name)
	{
		m_filename=name;
	}
}





NS_FS_END

