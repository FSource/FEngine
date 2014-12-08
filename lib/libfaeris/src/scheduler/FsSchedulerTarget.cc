#include "scheduler/FsSchedulerTarget.h"
#include "scheduler/FsScheduler.h"

NS_FS_BEGIN

const char* SchedulerTarget::className()
{
	return FS_SCHEDULER_TARGET_CLASS_NAME;
}
void SchedulerTarget::update(int /*priority*/,float dt)
{
}

SchedulerTarget::SchedulerTarget()
{
}

SchedulerTarget::~SchedulerTarget()
{
}


NS_FS_END

