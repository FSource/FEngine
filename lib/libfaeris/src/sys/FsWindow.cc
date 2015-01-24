/*************************************************************************/
/*  FsWindow.cc                                                          */
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


#include "sys/FsWindow.h"
#include "graphics/FsRenderDevice.h"



NS_FS_BEGIN


Window::Window()
{
	m_renderDevice=NULL;
	m_window=NULL;
	m_caption=FS_DEFAULT_WINDOW_NAME;
}

const char* Window::className()
{
	return FS_WINDOW_CLASS_NAME;
}

NS_FS_END


#if FS_PLATFORM_OS(FS_OS_LINUX)  || FS_PLATFORM_OS(FS_OS_OSX)
	#include "platform/glfw/FsGlfwWindow.cc"
#elif FS_PLATFORM_OS(FS_OS_WIN32)
	#include "platform/glfw/FsGlfwWindow.cc"
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/android/FsWindowAndroid.cc"
#else 
	#error "UnSupport Platform"
#endif 

