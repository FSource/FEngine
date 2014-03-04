#include "FsMacros.h"
#include "FsFaerisModule.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"
#include "sys/io/FsPackage.h"
#include "sys/io/FsVFS.h"
#include "support/util/FsPathUtil.h"
#include "support/util/FsScriptUtil.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"

//#include "FsxAccessModule.h"


#if FS_PLATFORM_OS(FS_OS_WIN32)
	#define FS_CONFIGURE_FILE "win32.fgame"
#elif FS_PLATFORM_OS(FS_OS_LINUX)
	#define FS_CONFIGURE_FILE "linux.fgame"
#endif 

NS_FS_USE


int main(int argc,char** argv)
{
	FsDict* dict=NULL;
	FsDict* script=NULL;
	FsString* entry=NULL;
	LuaEngine* engine=NULL;
	FsFile* file=NULL;


	const char* config=FS_CONFIGURE_FILE;
	if(argc==2)
	{
		config=argv[1];

	}

	FsFaeris_ModuleInit();


		/* get share object */
	Window* win=Global::window();
	Render* render=Global::render();

	win->setPosition(100,100);
	win->show();
	render->setRenderTarget(win);
	render->setClearColor(Color(0,0,0));

	/* check where script stop running */
	Global::director()->setAutoSwapBuffers(true);


	std::string path=std::string(config);
	path=PathUtil::toStdPath(path.c_str());

	std::string dir_name=PathUtil::getDirName(path.c_str());
	if(dir_name!= std::string(""))
	{
			dir_name+=std::string("/");
	}
	VFS::setRoot(dir_name.c_str());

	std::string file_name=PathUtil::getFileName(path.c_str());

	FS_TRACE_INFO("fgame path is %s, dir=%s,file=%s",config,dir_name.c_str(),file_name.c_str());

	file=VFS::createFile(file_name.c_str());


	if(file==NULL)
	{
		goto error;
	}

	dict=ScriptUtil::parseScript(file);
	file->decRef();



	if(!dict)
	{
		FS_TRACE_WARN("file(%s) is bad format",config);
		goto error;
	}

	FsFaeris_LoadConfig(dict);

	script=ScriptUtil::getDict(dict,"script");
	if(!script)
	{
		dict->decRef();
		goto error;
	}


	entry=ScriptUtil::getString(script,"entry");

	if(!entry)
	{
		FS_TRACE_WARN("Can't Find Script Entry");
		script->decRef();
		dict->decRef();
		goto error;
	}

	engine=LuaEngine::create();
	FS_NO_REF_DESTROY(engine);
	Global::setScriptEngine(engine);


	engine->executeFile(entry->cstr());
	dict->decRef();

	Global::scheduler()->mainLoop();

	/* exit */
	Global::sysDispatcher()->clearPending();
	Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::EXIT));
	Global::sysDispatcher()->flush();


	/* relese resource */

error:
	FsFaeris_ModuleExit();
	if(engine)
	{
		Global::dropScriptEngine();
		FS_DESTROY(engine);
	}
	return 0;
}


