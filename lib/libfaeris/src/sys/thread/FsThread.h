#ifndef _FS_THREAD_H_
#define _FS_THREAD_H_

#include <pthread.h>

#include "FsMacros.h"


NS_FS_BEGIN 
class Thread 
{
	public:
		Thread();
		virtual ~Thread();

	public:
		int start();   /* start the thread */
		int join();	   /* wait the thread to exit */
		int cancel();
		int detach();  /* detach the thread */

	public:
		virtual void run()=0;

	private:
		pthread_t m_tid;
		bool m_init;
};


NS_FS_END 

#endif /* _FS_THREAD_H_ */ 
