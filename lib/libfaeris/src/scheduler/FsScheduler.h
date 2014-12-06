#ifndef _FS_SCHEDULER_H_
#define _FS_SCHEDULER_H_

#include "FsMacros.h"
#include "FsObject.h"
#include "support/util/FsSlowArray.h"
#include "sys/FsTimer.h"
#include "sys/thread/FsMutex.h"

NS_FS_BEGIN
class SchedulerTarget;
class Task;
class Scheduler :public FsObject
{
	public:
		enum
		{
			HIGHEST=0,
			HIGH,
			MIDDLE,
			LOW,
			LOWEST,
			PRIORITY_NU,
		};

	public:
		static Scheduler* create();

	public:
		/* inherit FsObject */
		const char* className() ;

	public:
		void start();
		void stop();
		void setFps(int fps);
		void mainLoop();
		float update(float dt);
		bool isRunning()
		{
			return !m_stop;
		}

	public:
		void add(SchedulerTarget* s,int priority);
		void remove(SchedulerTarget* s,int priority);
		void remove(SchedulerTarget* s);
		bool hasTarget(SchedulerTarget* target,int priority);
		bool hasTarget(SchedulerTarget* target);
		void scheduleWithMiliSecond(bool enable);


	public:

		void runTask(Task* t);

		/* used for other thread to pend task event to game */
		void runASyncTask(Task* t);

	protected:
		Scheduler();
		~Scheduler();
		void init();
		void destruct();

	private:
		/* scheduler target */
		FsSlowArray* m_target[PRIORITY_NU];
		bool m_stop;
		int m_fps;
		float m_intervalTime;

		Timer m_timer;


		/* sync task */
		FsArray* m_taskHanding;
		FsArray* m_taskPending;
		Mutex* m_taskLock;

		/* capcity old */
		bool m_sheduleWithMilliSecond;



};

NS_FS_END


#endif /*_FS_SCHEDULER_H_*/























