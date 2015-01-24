/*************************************************************************/
/*  FsConditionVariable.cc                                               */
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


#include "FsConditionVariable.h"
#include "FsMutex.h"

NS_FS_BEGIN

ConditionVariable::ConditionVariable()
{
	int ret=pthread_cond_init(&m_cond,NULL);
	if(ret!=0)
	{
		FS_TRACE_WARN("ConditionVariable Init Failed");
	}
}

ConditionVariable::~ConditionVariable()
{
	int ret=pthread_cond_destroy(&m_cond);
	if(ret!=0)
	{
		FS_TRACE_WARN("Destory ConditionVariable Failed");
	}
}

int ConditionVariable::wait(Mutex* mutex)
{
	int ret=pthread_cond_wait(&m_cond,&mutex->m_mutex);
	if(ret<0)
	{
		return -1;
	}
	return 0;
}

int ConditionVariable::signal()
{
	int ret=pthread_cond_signal(&m_cond);
	if(ret<0)
	{
		return -1;
	}
	return 0;
}

int ConditionVariable::broadcast()
{
	int ret=pthread_cond_broadcast(&m_cond);
	if(ret<0)
	{
		return -1;
	}
	return 0;
}






NS_FS_END

