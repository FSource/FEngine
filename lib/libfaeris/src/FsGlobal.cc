/*************************************************************************/
/*  FsGlobal.cc                                                          */
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


#include "FsGlobal.h"


NS_FS_BEGIN

FS_GLOBAL_CC(Scheduler,scheduler,setScheduler);
FS_GLOBAL_CC(TouchDispatcher,touchDispatcher,setTouchDispatcher);

FS_GLOBAL_CC(SysDispatcher,sysDispatcher,setSysDispatcher);

FS_GLOBAL_CC(KeypadDispatcher,keypadDispatcher,setKeypadDispatcher);

FS_GLOBAL_CC(InputTextDispatcher,inputTextDispatcher,setInputTextDispatcher);


FS_GLOBAL_CC(Director,director,setDirector);

FS_GLOBAL_CC(Window,window,setWindow);
FS_GLOBAL_CC(RenderDevice,render,setRender);

FS_GLOBAL_CC(ScriptEngine,scriptEngine,setScriptEngine);


/* mgr */
FS_GLOBAL_CC(TextureMgr,textureMgr,setTextureMgr);
FS_GLOBAL_CC(FontTTFMgr,FontTTFMgr,setFontTTFMgr);
FS_GLOBAL_CC(Sprite2DDataMgr,sprite2DDataMgr,setSprite2DDataMgr);
FS_GLOBAL_CC(ProgramSourceMgr,programSourceMgr,setProgramSourceMgr);

FS_GLOBAL_CC(MeshMgr,meshMgr,setMeshMgr);
FS_GLOBAL_CC(Material3DMgr,material3DMgr,setMaterial3DMgr);

FS_GLOBAL_CC(FelisScriptMgr,felisScriptMgr,setFelisScriptMgr);

FS_GLOBAL_CC(ClassMgr,classMgr,setClassMgr);

FS_GLOBAL_CC(FontBitmapMgr,fontBitmapMgr,setFontBitmapMgr);

NS_FS_END






































