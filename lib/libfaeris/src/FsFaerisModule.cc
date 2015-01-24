/*************************************************************************/
/*  FsFaerisModule.cc                                                    */
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


#include "FsFaerisModule.h"
#include "FsGlobal.h"
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
#include "mgr/FsProgramSourceMgr.h"

#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsScriptUtil.h"


NS_FS_BEGIN

int FsFaeris_PlatformInit();

int FsFaeris_ModuleInit()
{

	VFS::moduleInit();



	Scheduler* scheduler=Scheduler::create();
	FS_NO_REF_DESTROY(scheduler);
	Global::setScheduler(scheduler);


	TouchDispatcher* touch_dispatcher=TouchDispatcher::create();
	FS_NO_REF_DESTROY(touch_dispatcher);
	Global::setTouchDispatcher(touch_dispatcher);


	SysDispatcher* sys_dispatcher=SysDispatcher::create();
	FS_NO_REF_DESTROY(sys_dispatcher);
	Global::setSysDispatcher(sys_dispatcher);

	KeypadDispatcher* key_dispatcher=KeypadDispatcher::create();
	FS_NO_REF_DESTROY(key_dispatcher);
	Global::setKeypadDispatcher(key_dispatcher);


	InputTextDispatcher* input_text_dispatcher=InputTextDispatcher::create();
	FS_NO_REF_DESTROY(input_text_dispatcher);
	Global::setInputTextDispatcher(input_text_dispatcher);



	Director* director=Director::create();
	FS_NO_REF_DESTROY(director);
	Global::setDirector(director);


	Window* window=Window::create();
	FS_NO_REF_DESTROY(window);
	Global::setWindow(window);

	RenderDevice* render=RenderDevice::create();
	FS_NO_REF_DESTROY(render);
	Global::setRenderDevice(render);

	TextureMgr* tex_mgr=TextureMgr::create();
	FS_NO_REF_DESTROY(tex_mgr);
	Global::setTextureMgr(tex_mgr);


	FontTTFMgr* font_ttf_mgr=FontTTFMgr::create();
	FS_NO_REF_DESTROY(font_ttf_mgr);
	Global::setFontTTFMgr(font_ttf_mgr);

	FontBitmapMgr* font_bmp_mgr=FontBitmapMgr::create();
	FS_NO_REF_DESTROY(font_bmp_mgr);
	Global::setFontBitmapMgr(font_bmp_mgr);




	Sprite2DDataMgr* sprite_mgr=Sprite2DDataMgr::create();
	FS_NO_REF_DESTROY(sprite_mgr);
	Global::setSprite2DDataMgr(sprite_mgr);


	ProgramSourceMgr* prog_s_mgr=ProgramSourceMgr::create();
	FS_NO_REF_DESTROY(prog_s_mgr);
	prog_s_mgr->loadPreDefineShader();
	Global::setProgramSourceMgr(prog_s_mgr);

	FelisScriptMgr* flis_mgr=FelisScriptMgr::create();
	FS_NO_REF_DESTROY(flis_mgr);
	Global::setFelisScriptMgr(flis_mgr);


	ClassMgr* cls_mgr=ClassMgr::create();
	FS_NO_REF_DESTROY(cls_mgr);
	Global::setClassMgr(cls_mgr);
	cls_mgr->preRegisterClass();






	/* register scheduler target */
	scheduler->add(touch_dispatcher,Scheduler::HIGH);
	scheduler->add(sys_dispatcher,Scheduler::HIGH);
	scheduler->add(key_dispatcher,Scheduler::HIGH);
	scheduler->add(input_text_dispatcher,Scheduler::HIGH);

	scheduler->add(director,Scheduler::MIDDLE);
	scheduler->add(director,Scheduler::LOW);
	scheduler->add(director,Scheduler::LOWEST);

	/* set Global */

	render->setRenderTarget(window);
	render->setClearColor(Color(0,0,0));

	FsFaeris_PlatformInit();

	return 0;
}


int FsFaeris_ModuleExit()
{
	Scheduler* scheduler=Global::scheduler();


	/* scheduler target */
	TouchDispatcher* touch_dispatcher=Global::touchDispatcher();
	SysDispatcher* sys_dispatcher=Global::sysDispatcher();
	KeypadDispatcher* key_dispatcher=Global::keypadDispatcher();
	InputTextDispatcher* input_text_dispatcher=Global::inputTextDispatcher();

	Director* director=Global::director();


	/* window and render */
	Window* window=Global::window();
	RenderDevice* render=Global::renderDevice();

	/* manager */
	TextureMgr* tex_mgr=Global::textureMgr();
	FontTTFMgr* font_ttf_mgr=Global::fontTTFMgr();
	FontBitmapMgr* font_bmp_mgr=Global::fontBitmapMgr();
	Sprite2DDataMgr* sprite_mgr=Global::sprite2DDataMgr();
	ProgramSourceMgr* prog_s_mgr=Global::programSourceMgr();

	FelisScriptMgr* felis_mgr=Global::felisScriptMgr();
	ClassMgr* cls_mgr=Global::classMgr();


	/* remove scheduler target */
	scheduler->remove(sys_dispatcher,Scheduler::HIGH);
	scheduler->remove(touch_dispatcher,Scheduler::HIGH);
	scheduler->remove(key_dispatcher,Scheduler::HIGH);
	scheduler->remove(input_text_dispatcher,Scheduler::HIGH);

	scheduler->remove(director,Scheduler::MIDDLE);
	scheduler->remove(director,Scheduler::LOW);
	scheduler->remove(director,Scheduler::LOWEST);





	/* destroy */
	FS_DESTROY(render);
	FS_DESTROY(window);

	FS_DESTROY(scheduler);
	FS_DESTROY(director);

	/* scheduler target */
	FS_DESTROY(touch_dispatcher);
	FS_DESTROY(sys_dispatcher);
	FS_DESTROY(key_dispatcher);
	FS_DESTROY(input_text_dispatcher);

	/* mgr */
	FS_DESTROY(tex_mgr);
	FS_DESTROY(font_ttf_mgr);
	FS_DESTROY(font_bmp_mgr);
	FS_DESTROY(sprite_mgr);
	FS_DESTROY(prog_s_mgr);
	FS_DESTROY(felis_mgr);
	FS_DESTROY(cls_mgr);





	VFS::moduleExit();



	/* clear global value */
	Global::dropScheduler();
	Global::dropTouchDispatcher();
	Global::dropSysDispatcher();
	Global::dropDirector();
	Global::dropWindow();
	Global::dropRenderDevice();
	Global::dropTextureMgr();
	Global::dropFontTTFMgr();
	Global::dropFontBitmapMgr();
	Global::dropSprite2DDataMgr();
	Global::dropProgramSourceMgr();
	Global::dropFelisScriptMgr();
	Global::dropClassMgr();
	return 0;
}

void FsFaeris_ConfigResourceMgr(ResourceMgr* mgr,FsDict* dict)
{
	FsArray* array=ScriptUtil::getArray(dict,"searchPath");
	if(!array)
	{
		return;
	}

	int path_nu=array->size();
	for(int i=0;i<path_nu;i++)
	{
		FsString* s_path=ScriptUtil::getString(array,i);
		if(s_path)
		{
			mgr->addSearchPath(s_path->cstr());
		}
	}
}


#if FS_PLATFORM_OS(FS_OS_WIN32)
	#define FS_CONFIGURE_FILE "win32.fgame"
#elif FS_PLATFORM_OS(FS_OS_LINUX)
	#define FS_CONFIGURE_FILE "linux.fgame"
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#define FS_CONFIGURE_FILE "android.fgame"
#elif FS_PLATFORM_OS(FS_OS_OSX)
	#define FS_CONFIGURE_FILE "osx.fgame"
#elif FS_PLATFORM_OS(FS_OS_IOS)
	#define FS_CONFIGURE_FILE "ios.fgame"
#endif 



int FsFaeris_LoadConfig(const char* filename)
{
	const char* config=FS_CONFIGURE_FILE;
	if(filename)
	{
		config=filename;
	}

	FsFile* file=VFS::createFile(config);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Find Config File(%s)",config);
		return -1;
	}

	FsDict* dict=ScriptUtil::parseScript(file);
	file->decRef();

	if(!dict)
	{
		FS_TRACE_INFO("Can't Parse Config File(%s)",config);
		return -1;
	}
	FsFaeris_LoadConfig(dict);
	dict->decRef();

	return 0;
}



int FsFaeris_LoadConfig(FsDict* dict)
{
	FsDict* mgr=ScriptUtil::getDict(dict,"mgr"); 
	if(mgr)
	{
		FsFaeris_ConfigManager(mgr);
	}

	FsDict* vfs=ScriptUtil::getDict(dict,"vfs");
	if(vfs)
	{
		FsFaeris_ConfigVFS(vfs);
	}


	FsDict* win=ScriptUtil::getDict(dict,"win");
	if(win)
	{
		FsFaeris_ConfigWin(win);
	}

	FsDict* env=ScriptUtil::getDict(dict,"evn");
	if(env)
	{
		FsFaeris_ConfigENV(env);
	}

	return 0;
}



int FsFaeris_ConfigManager(FsDict* dict)
{
	/* texture mgr */
	FsDict* texmgr=ScriptUtil::getDict(dict,"textureMgr");
	if(texmgr)
	{
		TextureMgr* mgr=Global::textureMgr();
		if(mgr)
		{
			FsFaeris_ConfigResourceMgr(mgr,texmgr);
		}
	}


	/* FontTTFDataMgr */
	FsDict* fontmgr=ScriptUtil::getDict(dict,"fontTTFDataMgr");
	if(fontmgr)
	{
		FontTTFMgr* mgr=Global::fontTTFMgr();
		if(mgr)
		{
			FsFaeris_ConfigResourceMgr(mgr,fontmgr);
		}
	}


	/* Sprite2DDataMgr */
	FsDict* spritemgr=ScriptUtil::getDict(dict,"sprite2DDataMgr");
	if(spritemgr)
	{
		Sprite2DDataMgr* mgr=Global::sprite2DDataMgr();
		if(mgr)
		{
			FsFaeris_ConfigResourceMgr(mgr,spritemgr);
		}
	}
	return 0;
}

int FsFaeris_ConfigVFS(FsDict* dict)
{
	/* filter */
	FsArray* filters=ScriptUtil::getArray(dict,"nameFilter");
	if(filters)
	{
		int filter_nu=filters->size();
		for(int i=0;i<filter_nu;i++)
		{
			FsDict* f=ScriptUtil::getDict(filters,i);
			if(f)
			{
				FsString* type= ScriptUtil::getString(f,"type");
				if(!type)
				{
					continue;
				}

				if(type->equal("prefix"))
				{
					FsString* value=ScriptUtil::getString(f,"value");
					if(value)
					{
						VFS::PrefixNameFilter* prefix_filter=VFS::PrefixNameFilter::create(value->cstr());
						VFS::addFilter(prefix_filter);
					}
				}


			}
		}
	}

	/* package */
	FsArray* map_package=ScriptUtil::getArray(dict,"mapPackage");
	if(map_package)
	{
		int package_nu=map_package->size();
		for(int i=0;i<package_nu;i++)
		{
			FsDict* p=ScriptUtil::getDict(map_package,i);
			if(!p) continue;

			FsString*  map_path=ScriptUtil::getString(p,"mapPath");
			FsString*  map_type=ScriptUtil::getString(p,"packageType");
			FsString*  map_url=ScriptUtil::getString(p,"url");


			FsString*  map_priority=ScriptUtil::getString(p,"priority");
			int priority=VFS::FS_MAP_LOW;
			if( map_priority)
			{
				if(map_priority->equal("high"))
				{
					priority=VFS::FS_MAP_HIGH;
				}
				else 
				{
					priority=VFS::FS_MAP_LOW;
				}
			}


			if(map_path&&map_type&&map_url)
			{
				if(map_type->equal("zip"))
				{

					Package* package=Package::create(map_url->cstr(),Package::PACKAGE_ZIP);
					if(package)
					{
						VFS::mapPackage(map_path->cstr(),package,priority);
					}

				}
				else if(map_type->equal("fgz"))
				{

					Package* package=Package::create(map_url->cstr(),Package::PACKAGE_FGZ);
					if(package)
					{
						VFS::mapPackage(map_path->cstr(),package,priority);
					}

				}
			}
		}
	}
	return 0;
}

int FsFaeris_ConfigWin(FsDict* dict)
{
	int width,height;
	Window* win=Global::window();
	if(win==NULL)
	{
		return 0;
	}

	if(ScriptUtil::getInteger(dict,"width",&width)&&
			ScriptUtil::getInteger(dict,"height",&height))
	{

		win->setSize(width,height);
	}

	FsString* caption=ScriptUtil::getString(dict,"caption");
	if(caption)
	{
		win->setCaption(caption->cstr());
	}
	return 0;
}

int FsFaeris_ConfigENV(FsDict* dict)
{
	/*TODO*/
	return 0;
}

NS_FS_END




/* PLATFORM INIT */

#if FS_PLATFORM_OS(FS_OS_WIN32) || FS_PLATFORM_OS(FS_OS_LINUX) ||FS_PLATFORM_OS(FS_OS_OSX) 
NS_FS_BEGIN
int FsFaeris_PlatformInit()
{
	Global::window()->show();
	Global::director()->setAutoSwapBuffers(true);

	return 0;
}
NS_FS_END

#elif FS_PLATFORM_OS(FS_OS_ANDROID) 
#include <jni.h>
#include "sys/FsSys.h"
#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
NS_FS_BEGIN
int FsFaeris_PlatformInit() 
{
	/* set root dir */
	std::string data_dir(Sys::currentDir());
	VFS::setRoot(data_dir.c_str());
	FS_TRACE_INFO("root dir(%s)",data_dir.c_str());

	/* map apk to vfs */
	std::string apk_path(Sys::apkPath());
	Package* package=Package::create(apk_path.c_str(),Package::PACKAGE_ZIP);

	FS_TRACE_INFO("apk path=%s",apk_path.c_str());


	if(package==NULL)
	{
		FS_TRACE_WARN("load package %s  failed",apk_path.c_str());
	}
	else 
	{
		VFS::mapPackage("",package,VFS::FS_MAP_HIGH);
	}

	/* add extern filter */
	char buf[1024];
	sprintf(buf,"/mnt/sdcard/fgame/%s/",Sys::packageName());
	FS_TRACE_INFO("extern read(%s)",buf);

	VFS::PrefixNameFilter*  sdcard_filter=VFS::PrefixNameFilter::create(buf);
	VFS::addFilter(sdcard_filter);

	/* add name filter */
	VFS::PrefixNameFilter* assets_filter=VFS::PrefixNameFilter::create("assets/");
	VFS::addFilter(assets_filter);
}
NS_FS_END


#elif FS_PLATFORM_OS(FS_OS_IOS)

#endif 


