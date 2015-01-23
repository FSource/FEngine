/*************************************************************************/
/*  FsLuaSysEventListener.cc                                             */
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








