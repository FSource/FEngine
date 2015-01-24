/*************************************************************************/
/*  FsThread.cc                                                          */
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


#include <string.h>

#include "sys/thread/FsThread.h"

NS_FS_BEGIN
static void* FsThread_Run(void* t)
{
	((Thread*)t)->run();
	return NULL;
}


Thread::Thread()
{
	m_init=false;
	memset(&m_tid,0,sizeof(pthread_t));
}

Thread::~Thread()
{
	if(m_init)
	{
		m_init=false;
	}
}

int Thread::start()
{
	if(m_init)
	{
		FS_TRACE_WARN("Thread Already Init");
		return -1;
	}

	int ret=pthread_create(&m_tid,NULL,FsThread_Run,this);
	if(ret<0)
	{
		FS_TRACE_WARN("Start Thread Failed");
		ret=-1;
	}
	else
	{
		m_init=true;
	}
	return ret;
}

int Thread::join()
{
	if(!m_init)
	{
		FS_TRACE_WARN("Thread Not Init");
		return -1;
	}
	int ret=pthread_join(m_tid,NULL);
	if(ret<0)
	{
		ret=-1;
		FS_TRACE_WARN("Join Thread Failed");
	}
	return ret;
}

int Thread::detach()
{
	if(!m_init)
	{
		FS_TRACE_WARN("Thread Not Init");
		return -1;
	}

	int ret=pthread_detach(m_tid);
	if(ret<0)
	{
		ret=-1;
		FS_TRACE_WARN("Detach Thread Failed");
	}
	return ret;
}

int Thread::cancel()
{
	return 0;

	/* do NoThing, because android not support */

	/*
	if(!m_init)
	{
		FS_TRACE_WARN("Thread Not Init");
		return -1;
	}

	int ret=pthread_cancel(m_tid);
	if(ret<0)
	{
		ret=-1;
		FS_TRACE_WARN("Cancel Thread Failed");
	}
	return ret;
	*/
}

NS_FS_END


