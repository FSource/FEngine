#include "FsLuaMacros.h"
#include "FsLuaEngine.h"
#include "luaext/FsLuaTouchEventListener.h"
#include "FsGlobal.h"


NS_FS_BEGIN

const char* LuaTouchEventListener::className()
{
	return FS_LUA_TOUCH_EVENT_LISTENER_CLASS_NAME;
}


LuaTouchEventListener* LuaTouchEventListener::create()
{
	LuaTouchEventListener* ret=new LuaTouchEventListener();
	return ret;
}


/* override supper */

void LuaTouchEventListener::touchesBegin(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchesBegin",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event);
}
void LuaTouchEventListener::touchesPointerDown(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchesPointerDown",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event);
}
void LuaTouchEventListener::touchesMove(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchesMove",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event);
}
void LuaTouchEventListener::touchesPointerUp(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchesPointerUp",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event);
}
void LuaTouchEventListener::touchesEnd(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchesEnd",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event);
}


void LuaTouchEventListener::touchBegin(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchBegin",3,0,"fnn",this,x,y);
}

void LuaTouchEventListener::touchMove(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchMove",3,0,"fnn",this,x,y);
}

void LuaTouchEventListener::touchEnd(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchEnd",3,0,"fnn",this,x,y);
}


NS_FS_END 







