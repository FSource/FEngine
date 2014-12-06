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


