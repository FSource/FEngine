#ifndef _FS_SCHEDULER_TARGET_H_
#define _FS_SCHEDULER_TARGET_H_

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class Scheduler;
class SchedulerTarget:public FsObject
{
	public:
		virtual void update(int priority,float dt)=0;
		virtual const char* className();

	protected:
		SchedulerTarget();
		virtual ~SchedulerTarget();

	private:
};

NS_FS_END
#endif /*_FS_SCHEDULER_TARGET_H_*/

