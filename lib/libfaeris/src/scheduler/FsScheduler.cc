#include "scheduler/FsScheduler.h"
#include "scheduler/FsSchedulerTarget.h"
#include "scheduler/FsTask.h"
#include "sys/FsSys.h"
#include "extends/FsScriptEngine.h"
#include "FsGlobal.h"

NS_FS_BEGIN
const char* Scheduler::className() 
{
	return FS_SCHEDULER_CLASS_NAME;
}

Scheduler* Scheduler::create()
{
	Scheduler* ret=new Scheduler();
	return ret;
}

void Scheduler::start()
{
	m_stop=false;
}
void Scheduler::stop()
{
	m_stop=true;
}
void Scheduler::setFps(int fps)
{
	m_fps=fps;
	m_intervalTime=(float)( m_fps<=0?0.0f:1000.0f/(float)m_fps);
}

void Scheduler::mainLoop()
{
	//long begin_time=m_timer.now();
	float last_time=m_timer.now();

	float diff_time=0,cur_time=0;

	while(!m_stop)
	{
		cur_time=m_timer.now();

		if(m_sheduleWithMilliSecond) 
		{
			diff_time=cur_time-last_time;
		}
		else 
		{
			diff_time=(cur_time-last_time)/1000.0f;

		}

		update(diff_time);

		
		while(m_timer.now()-cur_time<=m_intervalTime){}
		
		
	
		/*
		if(sleep_time>0)
		{
			Sys::usleep((long)sleep_time);
		}
		*/

		
		
	
		last_time=cur_time;
	}
}

void Scheduler::add(SchedulerTarget* s,int priority)
{
	assert(priority<PRIORITY_NU&&priority>=0);
	assert(!hasTarget(s,priority));
	m_target[priority]->push(s);
}
void Scheduler::remove(SchedulerTarget* s,int priority)
{
	assert(priority<PRIORITY_NU&&priority>=0);
	assert(hasTarget(s,priority));
	m_target[priority]->remove(s);

}
void Scheduler::remove(SchedulerTarget* s)
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		if(hasTarget(s,i))
		{
			m_target[i]->remove(s);
		}
	}
	assert(!hasTarget(s));
}

Scheduler::Scheduler()
{
	init();
}
Scheduler::~Scheduler()
{
	destruct();
}


bool Scheduler::hasTarget(SchedulerTarget* target,int priority)
{
	int target_nu=m_target[priority]->size();
	for(int i=0;i<target_nu;i++)
	{
		SchedulerTarget* t=(SchedulerTarget*)m_target[priority]->get(i);
		if(t==target)
		{
			return true;
		}
	}
	return false;
}

bool Scheduler::hasTarget(SchedulerTarget* target)
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		if(hasTarget(target,i))
		{
			return true;
		}
	}
	return false;
}

void Scheduler::scheduleWithMiliSecond(bool enable)
{
	m_sheduleWithMilliSecond=enable;
}








void Scheduler::runASyncTask(Task* t)
{
	m_taskLock->lock();
	m_taskPending->push(t);
	m_taskLock->unlock();
}

void Scheduler::runTask(Task* t)
{
	m_taskHanding->push(t);
}



void Scheduler::init()
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]=FsSlowArray::create();
	}
	m_stop=false;
	m_fps=60;
	m_intervalTime=(1.0f/60.0f)*1000;

	m_sheduleWithMilliSecond=false;

	m_taskHanding=FsArray::create();
	m_taskPending=FsArray::create();

	FS_NO_REF_DESTROY(m_taskPending);
	FS_NO_REF_DESTROY(m_taskHanding);

	m_taskLock=new Mutex();
}

void Scheduler::destruct()
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		FS_SAFE_DEC_REF(m_target[i]);
		m_target[i]=NULL;
	}

	FS_DESTROY(m_taskPending);
	FS_DESTROY(m_taskHanding);

	FS_DELETE(m_taskLock);


}

float Scheduler::update(float dt)
{

	float update_begin=m_timer.now();
	/* run sync task,
	 * swap task pending queue and handing queue 
	 * for minimize lock time 
	 */ 
	m_taskLock->lock();
	if(m_taskPending->size()!=0)
	{
		FsArray* tmp=m_taskHanding;
		m_taskHanding=m_taskPending;
		m_taskPending=tmp;
	}
	m_taskLock->unlock();

	/* running all pend task */
	int task_nu=m_taskHanding->size();
	for(int i=0;i<task_nu;i++)
	{
		Task* t=(Task*)m_taskHanding->get(i);
		t->run();
	}
	m_taskHanding->clear();


	float perframe_time=m_intervalTime;

	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]->lock();
		int target_nu=m_target[i]->size();
		for(int j=0;j<target_nu;j++)
		{
			SchedulerTarget* target=(SchedulerTarget*)m_target[i]->get(j);
			target->update(i,dt);
		}
		m_target[i]->unlock();
		m_target[i]->flush();
	}

	

	float update_end=m_timer.now();

	return (float)(perframe_time-(update_end-update_begin));
}

NS_FS_END





















