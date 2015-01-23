/*************************************************************************/
/*  FsLuaTouchEventListener.cc                                           */
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







