/*************************************************************************/
/*  FsSysWin32.cc                                                        */
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


#include <Windows.h>
#include  <direct.h>  
#include  <stdio.h>  
#include <string>


NS_FS_BEGIN

void Sys::usleep(long time)
{
	Sleep(time);
}

const char* Sys::currentDir()
{
    _getcwd(m_tempBuf, FS_SYS_TEMP_BUF_SIZE); 
	return m_tempBuf;
}


int Sys::mkdir(const char* dir_name)
{
	int ret=CreateDirectory(dir_name,NULL);
	if(ret)
	{
		return 0;
	}
	else 
	{
		return -1;
	}
}

bool Sys::isDir(const char* dir_name)
{
	int ret=GetFileAttributes(dir_name);
	if(ret==FILE_ATTRIBUTE_DIRECTORY)
	{
		return true;
	}
	else 
	{
		return false;
	}
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




