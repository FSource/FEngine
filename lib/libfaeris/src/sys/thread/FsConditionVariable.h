#ifndef _FS_CONDITION_VARIABLE_H_
#define _FS_CONDITION_VARIABLE_H_

#include <pthread.h>
#include "FsMacros.h"

NS_FS_BEGIN 
class Mutex;
class ConditionVariable 
{
	public:
		ConditionVariable();
		~ConditionVariable();

	public:
		int wait(Mutex* mutex);
		int signal();
		int broadcast();

	private:
		pthread_cond_t m_cond;
};




NS_FS_END 




#endif /*_FS_CONDITION_VARIABLE_H_*/

