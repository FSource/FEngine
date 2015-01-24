/*************************************************************************/
/*  FsFile.cc                                                            */
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

