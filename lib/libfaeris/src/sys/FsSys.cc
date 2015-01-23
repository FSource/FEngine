/*************************************************************************/
/*  FsSys.cc                                                             */
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


#include "FsConfig.h"
#include "sys/FsSys.h"

#include "support/util/FsString.h"
#include "support/util/FsDict.h"

NS_FS_BEGIN

FsDict* Sys::m_env=NULL;
char Sys::m_tempBuf[FS_SYS_TEMP_BUF_SIZE];
const char* Sys::getEnv(const char* key)
{
	if(m_env==NULL) return NULL;

	FsString* ret=(FsString*)m_env->lookup(key);
	if(ret)
	{
		return ret->cstr();
	}
	return NULL;

}
void Sys::setEnv(const char* key,const char* value)
{
	if(key==NULL||value==NULL) return ;
	if(m_env==NULL)
	{
		m_env=FsDict::create();
	}
	FsString* t_key=FsString::create(key);
	FsString* t_value=FsString::create(value);
	m_env->insert(t_key,t_value);
}

NS_FS_END 



#if FS_PLATFORM_OS(FS_OS_LINUX)  ||  FS_PLATFORM_OS(FS_OS_OSX)
	#include "platform/linux/FsSysLinux.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/android/FsSysAndroid.cc"

#elif FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/win32/FsSysWin32.cc"

#else 
	#error "Unsupport Os"
#endif  /*FS_PLATFORM_OS*/

