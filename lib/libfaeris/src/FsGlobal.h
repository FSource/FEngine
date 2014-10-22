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
#include "mgr/FsSprite2DDataMgr.h"
#include "mgr/FsProgramMgr.h"


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
	FS_GLOBAL_H(ProgramMgr,programMgr,setProgramMgr);


};
NS_FS_END 

#endif /*_FS_GLOBAL_H_*/






