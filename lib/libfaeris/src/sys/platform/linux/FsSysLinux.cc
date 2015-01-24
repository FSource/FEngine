/*************************************************************************/
/*  FsSysLinux.cc                                                        */
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


#include <sys/stat.h>

#include <unistd.h>
#include <errno.h>
#include <time.h>

#include "sys/FsSys.h"

NS_FS_BEGIN
/*
FsLong Sys::getTime()
{
	return 0;

}
*/
void Sys::usleep(long time)
{
	struct timespec req= { time/1000, (time%1000)*1000000 };
	struct timespec rem;
	int ret=0;
	while(1)
	{
		ret=nanosleep(&req,&rem);
		if(ret==-1)
		{
			if(errno==EINTR)
			{
				req=rem;
				nanosleep(&req,&rem);
				continue;
			}
		}
		break;
	}
}

const char* Sys::currentDir()
{
	char* ret=getcwd(m_tempBuf,FS_SYS_TEMP_BUF_SIZE);
	return ret;
}



int Sys::mkdir(const char* dir_name)
{
	int ret=::mkdir(dir_name,0775);
	return ret;
}


bool Sys::isDir(const char* dir_name)
{
	struct stat st;
	if (stat(dir_name, &st) != 0)
    {
		return false;
    }
    else if (!S_ISDIR(st.st_mode))
    {
		return false;
    }
	return true;

}

void Sys::openInputTextDialog(const char* title,const char* msg,
							int input_mode,int input_flag,
							int return_type,int max_length)
{

}

void Sys::openNetSettingInterface()
{

}


NS_FS_END

