/*************************************************************************/
/*  FsAndroidMain.cc                                                     */
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
#include <jni.h>

#include "FsMacros.h"
#include "mgr/FsMeshMgr.h"
#include "mgr/FsMaterial3DMgr.h"

#include "sys/FsSys.h"
#include "FsGlobal.h"

#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
#include "FsFaerisModule.h"
#include "support/util/FsScriptUtil.h"

#include "stage/FsScene.h"
#include "demoStart/DemoStartLayer.h"

NS_FS_USE
extern "C"
{
	jint JNI_OnLoad(JavaVM* vm, void* reserved)
	{



		Sys::setJavaVM(vm);

		return JNI_VERSION_1_4;
	}
}


NS_FS_BEGIN 
void _FsScriptExtends_Finalize(FsObject* ob)
{
}

void FsAndroid_Main_Start()
{
	FsFaeris_ModuleInit();

	RenderDevice* r=Global::renderDevice();
	Window* win=Global::window();
	r->setRenderTarget(win);
	r->setClearColor(Color(0,0,0));

	Global::setMeshMgr(MeshMgr::create());
	Global::setMaterial3DMgr(Material3DMgr::create());


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

	Scene *scene= Scene::create();
	DemoStartLayer* layer = DemoStartLayer::create();
	scene->push(layer);
	Global::director()->run(scene);

}

NS_FS_END

