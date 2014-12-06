#ifndef _FS_LUA_SCHEDULER_TARGET_H_
#define _FS_LUA_SCHEDULER_TARGET_H_

#include "FsMacros.h"
#include "FsLuaMacros.h"
#include "scheduler/FsSchedulerTarget.h"

NS_FS_BEGIN

class LuaSchedulerTarget:public SchedulerTarget 
{
	public:
		static LuaSchedulerTarget* create()
		{
			return new LuaSchedulerTarget();
		}
	public:
		virtual void onUpdate(int priority,float dt);
		virtual void update(int priority,float dt);
		virtual const char* className();
};



NS_FS_END



#endif /*_FS_LUA_SCHEDULER_TARGET_H_*/



