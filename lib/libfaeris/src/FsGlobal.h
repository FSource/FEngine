/*************************************************************************/
/*  FsGlobal.h                                                           */
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


#ifndef _FS_GLOBAL_H_
#define _FS_GLOBAL_H_

#include "FsMacros.h"

#include "scheduler/FsScheduler.h"
#include "stage/FsDirector.h"
#include "graphics/FsRenderDevice.h"

#include "sys/event/FsTouchDispatcher.h"
#include "sys/event/FsSysDispatcher.h"
#include "sys/event/FsKeypadDispatcher.h"
#include "sys/event/FsInputTextDispatcher.h"

#include "sys/FsWindow.h"
#include "extends/FsScriptEngine.h"
#include "mgr/FsTextureMgr.h"
#include "mgr/FsFontTTFMgr.h"
#include "mgr/FsFontBitmapMgr.h"
#include "mgr/FsSprite2DDataMgr.h"
#include "mgr/FsProgramSourceMgr.h"
#include "mgr/FsMeshMgr.h"
#include "mgr/FsMaterial3DMgr.h"
#include "mgr/FsFelisScriptMgr.h"
#include "mgr/FsClassMgr.h"





#define FS_GLOBAL_H(t,get,set) \
	public: \
		static void set(t* v) \
		{ \
			FS_SAFE_ASSIGN(m_##t,v); \
		}\
		static t* get() \
		{\
			return m_##t; \
		}\
		static void drop##t() \
		{\
			m_##t=NULL; \
		}\
	private: \
		static t* m_##t

#define FS_GLOBAL_CC(t,get,set) \
	t* Global::m_##t=NULL


NS_FS_BEGIN

class FsDict;
class Global
{
	FS_GLOBAL_H(Scheduler,scheduler,setScheduler);
	FS_GLOBAL_H(TouchDispatcher,touchDispatcher,setTouchDispatcher);
	FS_GLOBAL_H(SysDispatcher,sysDispatcher,setSysDispatcher);
	FS_GLOBAL_H(KeypadDispatcher,keypadDispatcher,setKeypadDispatcher);
	FS_GLOBAL_H(InputTextDispatcher,inputTextDispatcher,setInputTextDispatcher);

	FS_GLOBAL_H(Director,director,setDirector);
	FS_GLOBAL_H(Window,window,setWindow);
	FS_GLOBAL_H(RenderDevice,renderDevice,setRenderDevice);
	FS_GLOBAL_H(ScriptEngine,scriptEngine,setScriptEngine);

	/* mgr */
	FS_GLOBAL_H(TextureMgr,textureMgr,setTextureMgr);
	FS_GLOBAL_H(FontTTFMgr,fontTTFMgr,setFontTTFMgr);
	FS_GLOBAL_H(Sprite2DDataMgr,sprite2DDataMgr,setSprite2DDataMgr);
	FS_GLOBAL_H(ProgramSourceMgr,programSourceMgr,setProgramSourceMgr);
	FS_GLOBAL_H(MeshMgr,meshMgr,setMeshMgr);
	FS_GLOBAL_H(Material3DMgr,material3DMgr,setMaterial3DMgr);
	FS_GLOBAL_H(FelisScriptMgr,felisScriptMgr,setFelisScriptMgr);
	FS_GLOBAL_H(ClassMgr,classMgr,setClassMgr);

	FS_GLOBAL_H(FontBitmapMgr,fontBitmapMgr,setFontBitmapMgr);

};
NS_FS_END 

#endif /*_FS_GLOBAL_H_*/






