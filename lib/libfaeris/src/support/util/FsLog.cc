/*************************************************************************/
/*  FsLog.cc                                                             */
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


#include <stdio.h>
#include "FsLog.h"
#include "FsConfig.h"
#include "sys/io/FsFile.h"
#include "sys/io/FsVFS.h"
#include <stdarg.h>


NS_FS_BEGIN

FileLog* FileLog::ms_stdoutFileLog=NULL;


static void FsLog_FormatLogBuffer(char* buf,ulong size,
								   const char* fmt,va_list ap)
{
	uint msg_len=vsnprintf(buf,size-1,fmt,ap);
	buf[msg_len]='\0';
}

static void FsLog_FormatLogTagBuffer(char* buf,ulong size,
								const char* tag,const char* fmt,
								va_list ap)
{
	uint fmtbyte=snprintf(buf,size-1,"%s:",tag);
	uint msg_len=vsnprintf(buf+fmtbyte,size-1-fmtbyte,fmt,ap);
	buf[fmtbyte+msg_len]='\0';

}

void FsLog::tagLog(const char* tag,const char* fmt,...)
{
	char buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	logMsg(buf);
}
void FsLog::log(const char* fmt,...)
{
	char buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);

	logMsg(buf);
}


FileLog* FileLog::create(const char* filename)
{

	FsFile* f=VFS::createFile(filename,VFS::FS_IO_CREATE|VFS::FS_IO_APPEND);
	if(f==NULL)
	{
		return NULL;
	}
	FileLog* fl=new FileLog(f);
	return fl;
}


FileLog* FileLog::getStdoutFileLog()
{
	if(ms_stdoutFileLog==NULL)
	{
		ms_stdoutFileLog=new FileLog(VFS::getStdout());
	}
	return ms_stdoutFileLog;
}


FileLog::FileLog(FsFile* file)
{
	m_file=file;
}

void FileLog::logMsg(const char* msg)
{
	m_file->writeStr("%s\n",msg);
}

FileLog::~FileLog()
{
	delete m_file;
}








NS_FS_END

#if FS_PLATFORM_OS(FS_OS_WIN32) || FS_PLATFORM_OS (FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_OSX) || FS_PLATFORM_OS(FS_OS_IOS)
	#include "platform/FsLogDefault.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "platform/FsLogAndroid.cc"
#elif 
    #error "Unkown Platform For Log"
#endif
