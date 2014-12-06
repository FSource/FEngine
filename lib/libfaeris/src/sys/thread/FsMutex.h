#ifndef _FS_MUTEX_H_
#define _FS_MUTEX_H_

#include <pthread.h>
#include "FsMacros.h"

NS_FS_BEGIN

class Mutex 
{
	public:
		Mutex();
		virtual ~Mutex();

	public:
		int lock(); 
		int trylock();
		int unlock();
	private:
		pthread_mutex_t m_mutex;
};


NS_FS_END



#endif /* _FS_MUTEX_H_ */
