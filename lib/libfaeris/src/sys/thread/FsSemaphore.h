#ifndef _FS_SEMAPHORE_H_
#define _FS_SEMAPHORE_H_ 

#include <semaphore.h>
#include "FsMacros.h"

NS_FS_BEGIN
class Semaphore 
{
	public:
		Semaphore();
		Semaphore(unsigned int num);
		virtual ~Semaphore();

	public:
		int wait();
		int wait(long ms);
		int trywait();

		int post();
		int post(int count);

	private:
		sem_t m_sem;
};



NS_FS_END 




#endif /*_FS_SEMAPHORE_H_*/
