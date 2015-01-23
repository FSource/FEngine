/*************************************************************************/
/*  FsWin32Main.cc                                                       */
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
#include "FsMacros.h"
#include "FsFaerisModule.h"
#include "FsGlobal.h"
#include "sys/io/FsPackage.h"
#include "sys/io/FsVFS.h"
#include "support/util/FsPathUtil.h"
#include "support/util/FsScriptUtil.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "mgr/FsMeshMgr.h"
#include "mgr/FsMaterial3DMgr.h"

//#include "FsxAccessModule.h"
#include "stage/FsScene.h"
#include "demoStart/DemoStartLayer.h"

NS_FS_BEGIN 
void _FsScriptExtends_Finalize(FsObject* ob)
{
}
NS_FS_END

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
	FsFile* file=NULL;


	const char* config=FS_CONFIGURE_FILE;
	if(argc==2)
	{
		config=argv[1];

	}

	FsFaeris_ModuleInit();


		/* get share object */
	Window* win=Global::window();
	RenderDevice* render=Global::renderDevice();

	win->setPosition(100,100);
	win->show();
	win->setCaption("Reality Game Engine Demo");
	render->setRenderTarget(win);
	render->setClearColor(Color(0,0,0));

	/* check where script stop running */
	Global::director()->setAutoSwapBuffers(true);
	Global::scheduler()->setFps(0);


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



	Global::setMeshMgr(MeshMgr::create());
	Global::setMaterial3DMgr(Material3DMgr::create());


	/*  Create Scene 
	*	Global::director():run(scene) 
	*/
	Scene *scene= Scene::create();
	DemoStartLayer* layer = DemoStartLayer::create();
	scene->push(layer);
	Global::director()->run(scene);


	Global::scheduler()->mainLoop();

	/* exit */
	Global::sysDispatcher()->clearPending();
	Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::EXIT));
	Global::sysDispatcher()->flush();



error:
	FsFaeris_ModuleExit();
	return 0;
}


