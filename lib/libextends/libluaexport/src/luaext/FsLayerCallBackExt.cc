#include "FsLayerCallBackExt.h"
#include "FsObjectCallBackExt.h"

#include "FsGlobal.h"
#include "FsLuaEngine.h"

#include "stage/layer/FsLayer.h"


NS_FS_BEGIN

static void FsLLayer_onUpdate(Layer* ly,float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onUpdate",2,0,"fn",ly,dt))
	{
		ly->update(dt);
	}
}



static void FsLLayer_onDraw(Layer* ly,RenderDevice* render)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();

	if(!se->callFunctionInTable(ly->m_scriptData,"onDraw",2,0,"ff",ly,render))
	{
		ly->draw(render);
	}
}

static bool FsLLayer_onTouchBegin(Layer* ly,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchBegin",3,1,"fnn",ly,x,y))
	{
		return ly->touchBegin(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}


static bool FsLLayer_onTouchMove(Layer* ly,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchMove",3,1,"fnn",ly,x,y))
	{
		return ly->touchMove(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchEnd(Layer* ly,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchEnd",3,1,"fnn",ly,x,y))
	{
		return  ly->touchEnd(x,y);
	}

	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchesBegin(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesBegin",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesBegin(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchesPointerDown(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesPointerDown",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesPointerDown(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}
static bool FsLLayer_onTouchesMove(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesMove",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesMove(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}
static bool FsLLayer_onTouchesPointerUp(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesPointerUp",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesPointerUp(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchesEnd(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesEnd",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesEnd(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}


void FsLLayer_CallBackAssign(Layer* ly)
{
	FsLFsObject_CallBackAssign(ly);

	ly->onUpdate=FsLLayer_onUpdate;
	ly->onDraw=FsLLayer_onDraw;
	ly->onTouchBegin=FsLLayer_onTouchBegin;
	ly->onTouchMove=FsLLayer_onTouchMove;
	ly->onTouchEnd=FsLLayer_onTouchEnd;

	ly->onTouchesBegin=FsLLayer_onTouchesBegin;
	ly->onTouchesPointerDown=FsLLayer_onTouchesPointerDown;
	ly->onTouchesMove=FsLLayer_onTouchesMove;
	ly->onTouchesPointerUp=FsLLayer_onTouchesPointerUp;
	ly->onTouchesEnd=FsLLayer_onTouchesEnd;

}

NS_FS_END 


