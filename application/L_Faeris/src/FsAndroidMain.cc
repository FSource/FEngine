
#include <jni.h>

#include "FsMacros.h"
#include "FsLuaEngine.h"

#include "FsGlobal.h"
#include "FsFaerisModule.h"

#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"

#include "sys/FsSys.h"
#include "support/util/FsScriptUtil.h"


NS_FS_USE
extern "C"
{
	jint JNI_OnLoad(JavaVM* vm, void* reserved)
	{
		LuaEngine* engine=LuaEngine::create();
		Global::setScriptEngine(engine);

		Sys::setJavaVM(vm);

		return JNI_VERSION_1_4;
	}
}


NS_FS_BEGIN 

void FsAndroid_Main_Start()
{
	FsFaeris_ModuleInit();

	RenderDevice* r=Global::renderDevice();
	Window* win=Global::window();
	r->setRenderTarget(win);
	r->setClearColor(Color(0,0,0));


	/* configure vfs */


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

	FsFile* fgame=VFS::createFile("android.fgame");
	FS_NO_REF_DESTROY(fgame);

	if(fgame!=NULL)
	{
		FsDict* dict=NULL;
		FsDict* script=NULL;
		FsString* entry=NULL;
		ScriptEngine* sc=NULL;
		do
		{
			dict=ScriptUtil::parseScript(fgame);
			if(dict==NULL)
			{
				break;
			}
			FsFaeris_LoadConfig(dict);

			script=ScriptUtil::getDict(dict,"script");
			if(script==NULL)
			{
				break;
			}
			FsString* entry=ScriptUtil::getString(script,"entry");
			if(entry==NULL)
			{
				break;
			}
			sc=Global::scriptEngine();
			sc->executeFile(entry->cstr());

		}while(false);

		FS_SAFE_DEC_REF(dict);
	}
	else 
	{
		ScriptEngine* sc=Global::scriptEngine();
		sc->executeFile("main.lua");
	}
	FS_SAFE_DESTROY(fgame);
}

NS_FS_END 


