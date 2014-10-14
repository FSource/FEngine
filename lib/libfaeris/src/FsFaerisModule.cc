#include "FsFaerisModule.h"
#include "FsGlobal.h"
#include "scheduler/FsScheduler.h"
#include "stage/FsDirector.h"
#include "graphics/FsRender.h"
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

#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsScriptUtil.h"


NS_FS_BEGIN

int FsFaeris_ModuleInit()
{

	VFS::moduleInit();

	ObjectMgr* ob_mgr=ObjectMgr::create();
	FS_NO_REF_DESTROY(ob_mgr);
	Global::setObjectMgr(ob_mgr);


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


	FontTTFMgr* font_mgr=FontTTFMgr::create();
	FS_NO_REF_DESTROY(font_mgr);
	Global::setFontTTFMgr(font_mgr);

	Sprite2DDataMgr* sprite_mgr=Sprite2DDataMgr::create();
	FS_NO_REF_DESTROY(sprite_mgr);
	Global::setSprite2DDataMgr(sprite_mgr);


	ProgramMgr* prog_mgr=ProgramMgr::create();
	FS_NO_REF_DESTROY(prog_mgr);
	prog_mgr->loadPreDefineShader();
	Global::setProgramMgr(prog_mgr);




	/* register scheduler target */
	scheduler->add(touch_dispatcher,Scheduler::HIGH);
	scheduler->add(sys_dispatcher,Scheduler::HIGH);
	scheduler->add(key_dispatcher,Scheduler::HIGH);
	scheduler->add(input_text_dispatcher,Scheduler::HIGH);

	scheduler->add(director,Scheduler::MIDDLE);
	scheduler->add(director,Scheduler::LOW);
	scheduler->add(director,Scheduler::LOWEST);

	/* set Global */

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
	ObjectMgr* ob_mgr=Global::objectMgr();
	TextureMgr* tex_mgr=Global::textureMgr();
	FontTTFMgr* font_mgr=Global::fontTTFMgr();
	Sprite2DDataMgr* sprite_mgr=Global::sprite2DDataMgr();
	ProgramMgr* prog_mgr=Global::programMgr();




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
	FS_DESTROY(font_mgr);
	FS_DESTROY(sprite_mgr);
	FS_DESTROY(ob_mgr);
	FS_DESTROY(prog_mgr);




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
	Global::dropSprite2DDataMgr();
	Global::dropObjectMgr();
	Global::dropProgramMgr();
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














