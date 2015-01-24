/*************************************************************************/
/*  FsSemaphore.cc                                                       */
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


#include "sys/thread/FsSemaphore.h"
#include "pthread.h"

NS_FS_BEGIN

Semaphore::Semaphore()
{
	int ret=sem_init(&m_sem,0,1);
	if(ret!=0)
	{
		FS_TRACE_WARN("sem init failed");
	}
	
}


Semaphore::Semaphore(unsigned int num)
{
	int ret=sem_init(&m_sem,0,num);
	if(ret!=0)
	{
		FS_TRACE_WARN("sem init failed");
	}
}

Semaphore::~Semaphore()
{
	sem_destroy(&m_sem);
}

int Semaphore::wait()
{
	int ret=sem_wait(&m_sem);
	if(ret<0)
	{
		FS_TRACE_WARN("Wait Failed");
		return -1;
	}
	return 0;
}

int Semaphore::wait(long ms)
{

	/*FIXME: sem_timedwait Need Absolute Time to 1970 */
	assert(0);
	
	//struct timespec time={0,0};

	
	/*
	clock_gettime(CLOCK_REALTIME, &time);
	*/

	/*
	time.tv_sec+=ms/1000;
	time.tv_nsec+=(ms%1000)*1000*1000;

	if(time.tv_nsec> 1000*1000*1000)
	{
		time.tv_sec++;
		time.tv_nsec-=1000*1000*1000;
	}

	int ret=sem_timedwait(&m_sem,&time);
	if(ret<0)
	{
		//FS_TRACE_WARN("Wait %ld ms Failed",ms);
		return -1;
	}
	*/
	return 0;
}

int Semaphore::trywait()
{
	int ret=sem_trywait(&m_sem);

	if(ret<0)
	{
		ret =-1;
	}
	return ret;
}




int Semaphore::post()
{
	int ret=sem_post(&m_sem);
	if(ret<0)
	{
		FS_TRACE_WARN("Post Failed");
		ret=-1;
	}
	return ret;
}

int Semaphore::post(int count)
{
	for(int i=0;i<count;i++)
	{
		int ret=sem_post(&m_sem);
		if(ret<0)
		{
			FS_TRACE_WARN("Post Failed");
		}
	}
	return 0;
}







NS_FS_END
