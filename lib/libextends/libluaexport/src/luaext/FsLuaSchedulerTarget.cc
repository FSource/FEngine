#include "luaext/FsLuaSchedulerTarget.h"
#include "FsLuaEngine.h"
#include "FsGlobal.h"

NS_FS_BEGIN

void LuaSchedulerTarget::onUpdate(int priority,float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onUpdate",3,0,"fin",this,priority,dt))
	{
		SchedulerTarget::update(priority,dt);
	}
}

void LuaSchedulerTarget::update(int priority,float dt)
{
	onUpdate(priority,dt);
}
const char* LuaSchedulerTarget::className()
{
	return FS_LUA_SCHEDULER_TARGET_CLASS_NAME;
}



NS_FS_END

