/*************************************************************************/
/*  FsLayerCallBackExt.cc                                                */
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


