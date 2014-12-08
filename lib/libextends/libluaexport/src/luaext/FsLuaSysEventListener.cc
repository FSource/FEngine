#include "FsLuaMacros.h"
#include "FsGlobal.h"
#include "luaext/FsLuaSysEventListener.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN

const char* LuaSysEventListener::className()
{
	return FS_LUA_SYS_EVENT_LISTENER_CLASS_NAME;
}


LuaSysEventListener* LuaSysEventListener::create()
{
	LuaSysEventListener* ret=new LuaSysEventListener;
	return ret;
}

void LuaSysEventListener::onForeground()
{

	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onForeground",1,0,"f",this);
}

void LuaSysEventListener::onBackground()
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onBackground",1,0,"f",this);
}

void LuaSysEventListener::onExit()
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onExit",1,0,"f",this);
}

void LuaSysEventListener::onQuit()
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onQuit",1,0,"f",this);
}

void LuaSysEventListener::foreground()
{
	onForeground();
}
void LuaSysEventListener::background()
{
	onBackground();
}
void LuaSysEventListener::exit()
{
	onExit();
}
void LuaSysEventListener::quit()
{
	onQuit();
}

LuaSysEventListener::LuaSysEventListener()
{

}
LuaSysEventListener::~LuaSysEventListener()
{

}

NS_FS_END








