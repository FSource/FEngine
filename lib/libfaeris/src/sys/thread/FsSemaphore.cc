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
		FS_TRACE_WARN("Wait Failed"):
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
