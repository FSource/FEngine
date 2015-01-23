/*************************************************************************/
/*  FsSysFile.h                                                          */
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


#ifndef _FAERY_SYS_FILE_H_
#define _FAERY_SYS_FILE_H_

#include "FsMacros.h"
#include "FsFile.h"


#if FS_PLATFORM_OS(FS_OS_WIN32) || FS_PLATFORM_OS(FS_OS_LINUX) ||FS_PLATFORM_OS(FS_OS_ANDROID) ||FS_PLATFORM_OS(FS_OS_OSX)
	#include<stdio.h>
	typedef FILE* SysFilePlateform ;
#else 
	#error "Error Platform For SysFile"
#endif 


NS_FS_BEGIN
class SysFile:public FsFile 
{
	public:
		static SysFile* create(const char* name,uint mode=FsFile::FS_IO_RDONLY);
		static SysFile* getStdout();
		static SysFile* getStderr();
		static SysFile* getStdin();

	private:
		static SysFile* ms_stdout;
		static SysFile* ms_stdin;
		static SysFile* ms_stderr;
	public:
		virtual long read(void* buf,long length);
		virtual long write(const void* buf,long length);
		virtual long seek(long offset,E_FileSeek where);
		virtual int close();
		virtual long tell();
		virtual ~SysFile();
		virtual const char* className();
	protected:
		SysFile(SysFilePlateform f){m_platfromFile=f;}
	private:
		SysFilePlateform m_platfromFile;
};
NS_FS_END

#endif  /*_FAERY_SYS_FILE_H_*/


