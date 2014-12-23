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

