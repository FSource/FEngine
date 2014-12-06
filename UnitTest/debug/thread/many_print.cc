#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "sys/FsThread.h"
#include "sys/FsMutex.h"


NS_FS_USE

class MyThread:public Thread
{
	public:
		MyThread(Mutex*  m,int times)
		{
			m_times=times;
			m_mutex=m;
		}

	public:
		void run()
		{
			for(int i=0;i<m_times;i++)
			{
				m_mutex->lock();
				printf("BEGIN Thread %lx Printf(%d)\n\t %lxThis is a Good\nEND\n",(long)this,i,(long)this);
				m_mutex->unlock();
			//	sleep(1);
			}
		}
	private:
		Mutex* m_mutex;
		int m_times;
};


int main()
{
	MyThread* t[10];
	Mutex m;

	for(int i=0;i<10;i++)
	{
		t[i]=new MyThread(&m,10);

	}
	for(int i=0;i<10;i++)
	{
		t[i]->start();
	}

	sleep(2);
	for(int i=0;i<10;i++)
	{
//		t[i]->cancel();
		delete t[i];
	}

	return 0;
}

