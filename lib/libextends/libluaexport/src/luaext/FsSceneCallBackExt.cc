/*************************************************************************/
/*  FsSceneCallBackExt.cc                                                */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include "FsLuaEngine.h"
#include "FsGlobal.h"
#include "stage/FsScene.h"


#include "FsObjectCallBackExt.h"
#include "FsSceneCallBackExt.h"

NS_FS_BEGIN

static void FsLScene_onEnter(Scene* sn)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onEnter",1,0,"f",sn))
	{
		sn->enter();
	}
}
static void FsLScene_onExit(Scene* sn)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onExit",1,0,"f",sn))
	{
		sn->exit();
	}
}
static void FsLScene_onUpdate(Scene* sn,float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onUpdate",2,0,"fn",sn,dt))
	{
		sn->update(dt);
	}
}
static void FsLScene_onDraw(Scene* sn,RenderDevice* render)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();

	if(!se->callFunctionInTable(sn->m_scriptData,"onDraw",2,0,"ff",sn,render))
	{
		sn->draw(render);
	}
}

static void FsLScene_onTouchBegin(Scene* sn,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchBegin",3,0,"fnn",sn,x,y))
	{
		sn->touchBegin(x,y);
	}
}

static void FsLScene_onTouchMove(Scene* sn,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchMove",3,0,"fnn",sn,x,y))
	{
		sn->touchMove(x,y);
	}
}


static void FsLScene_onTouchEnd(Scene* sn,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchEnd",3,0,"fnn",sn,x,y))
	{
		sn->touchEnd(x,y);
	}
}

static void FsLScene_onTouchesBegin(Scene* sn,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchesBegin",3,0,"fiu<TouchEvent>",sn,event->getPointsNu(),event))
	{
		sn->touchesBegin(event);
	}
}

static void FsLScene_onTouchesPointerDown(Scene* sn,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchesPointerDown",3,0,"fiu<TouchEvent>",sn,event->getPointsNu(),event))
	{
		sn->touchesPointerDown(event);
	}

}
static void FsLScene_onTouchesMove(Scene* sn,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchesMove",3,0,"fiu<TouchEvent>",sn,event->getPointsNu(),event))
	{
		sn->touchesMove(event);
	}
}
static void FsLScene_onTouchesPointerUp(Scene* sn,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchesPointerUp",3,0,"fiu<TouchEvent>",sn,event->getPointsNu(),event))
	{
		sn->touchesPointerUp(event);
	}

}
static void FsLScene_onTouchesEnd(Scene* sn,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onTouchesEnd",3,0,"fiu<TouchEvent>",sn,event->getPointsNu(),event))
	{
		sn->touchesEnd(event);
	}
}

static void FsLScene_onKeypadEvent(Scene* sn,int type,int keycode)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onKeypadEvent",3,0,"fii",sn,type,keycode))
	{
		sn->keypadEvent(type,keycode);
	}
}

static void FsLScene_onInputTextEvent(Scene* sn,const char* value,int length)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(sn->m_scriptData,"onInputText",2,0,"fs",sn,value))
	{
		FS_TRACE_WARN("onInputText %s",value);
		sn->inputTextEvent(value,length);
	}
}


void FsLScene_CallBackAssign(Scene* sn)
{
	FsLFsObject_CallBackAssign(sn);
	sn->onEnter=FsLScene_onEnter;
	sn->onExit=FsLScene_onExit;
	sn->onUpdate=FsLScene_onUpdate;
	sn->onDraw=FsLScene_onDraw;
	sn->onTouchBegin=FsLScene_onTouchBegin;
	sn->onTouchMove=FsLScene_onTouchMove;
	sn->onTouchEnd=FsLScene_onTouchEnd;
	sn->onTouchesBegin=FsLScene_onTouchesBegin;
	sn->onTouchesPointerDown=FsLScene_onTouchesPointerDown;
	sn->onTouchesMove=FsLScene_onTouchesMove;
	sn->onTouchesPointerUp=FsLScene_onTouchesPointerUp;
	sn->onTouchesEnd=FsLScene_onTouchesEnd;
	sn->onKeypadEvent=FsLScene_onKeypadEvent;
	sn->onInputTextEvent=FsLScene_onInputTextEvent;

}







NS_FS_END 




