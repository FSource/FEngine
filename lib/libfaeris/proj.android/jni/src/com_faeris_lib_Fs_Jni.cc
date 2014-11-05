#include "com_faeris_lib_Fs_Jni.h"
#include "FsGlobal.h"
#include "FsFaerisModule.h"

#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"

#include "sys/FsSys.h"
#include "support/util/FsScriptUtil.h"


NS_FS_USE

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    moduleInit
 * Signature: ()V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_moduleInit
(JNIEnv *, jclass)
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

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    moduleExit
 * Signature: ()V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_moduleExit
(JNIEnv *, jclass)
{
	FsFaeris_ModuleExit();
}


/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onForeground
 * Signature: ()V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onForeground
(JNIEnv *, jclass)
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new SysEvent(SysDispatcher::FOREGROUND));
		dispatcher->flush();
	}
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onBackground
 * Signature: ()V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onBackground
(JNIEnv *, jclass)
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new SysEvent(SysDispatcher::BACKGROUND));
		dispatcher->flush();
	}
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onQuit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onQuit
  (JNIEnv *, jclass)
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new SysEvent(SysDispatcher::QUIT));
		dispatcher->flush();
	}
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onExit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onExit
  (JNIEnv *, jclass)
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new SysEvent(SysDispatcher::EXIT));
		dispatcher->flush();
	}
}



	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onKeyEventBack
(JNIEnv *, jclass)
{

}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onKeyEventMenu
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onKeyEventMenu
(JNIEnv *, jclass);


/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onInputText
 * Signature: (Ljava/lang/String;)V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onInputText
(JNIEnv* env, jclass, jstring value)
{
	const char* t_value=env->GetStringUTFChars(value,NULL);
	InputTextDispatcher* dispatcher=Global::inputTextDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new InputTextEvent(t_value));
	}
	env->ReleaseStringUTFChars(value,t_value);
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesBegin
 * Signature: (IFF)V
 */

	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesBegin
(JNIEnv*, jclass, jint id, jfloat x, jfloat y)
{
	TouchDispatcher* dispatcher= Global::touchDispatcher();
	if(dispatcher)
	{
		TouchPoint p(id,x,y);
		dispatcher->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_BEGIN,1,&p));
	}
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesPointerDown
 * Signature: (IFF)V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesPointerDown
(JNIEnv *, jclass, jint id, jfloat x, jfloat y)
{
	TouchDispatcher* dispatcher= Global::touchDispatcher();
	if(dispatcher)
	{
		TouchPoint p(id,x,y);
		dispatcher->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_POINTER_DOWN,1,&p));
	}
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesMove
 * Signature: (I[I[F[F)V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesMove
(JNIEnv* env, jclass, jint point_nu, jintArray ids, jfloatArray xs, jfloatArray ys)
{
	TouchDispatcher* dispatcher= Global::touchDispatcher();
	if(dispatcher)
	{
		jint* t_id=new jint[point_nu];
		jfloat* t_x=new jfloat[point_nu];
		jfloat* t_y=new jfloat[point_nu];

		env->GetIntArrayRegion(ids, 0, point_nu, t_id);
		env->GetFloatArrayRegion(xs, 0, point_nu, t_x);
		env->GetFloatArrayRegion(ys, 0, point_nu, t_y);

		TouchPoint* points= new TouchPoint[point_nu];
		for(int i=0;i<point_nu;i++)
		{
			points[i].id=t_id[i];
			points[i].x=t_x[i];
			points[i].y=t_y[i];
		}

		dispatcher->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_MOVE,point_nu,points));
		delete[] t_id;
		delete[] t_x;
		delete[] t_y;
		delete[] points;
	}
}




/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesPointerUp
 * Signature: (IFF)V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesPointerUp
(JNIEnv *, jclass, jint id, jfloat x, jfloat y)
{
	TouchDispatcher* dispatcher= Global::touchDispatcher();
	if(dispatcher)
	{
		TouchPoint p(id,x,y);
		dispatcher->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_POINTER_UP,1,&p));
	}
}


/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesEnd
 * Signature: (IFF)V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesEnd
(JNIEnv *, jclass, jint id , jfloat x, jfloat y)
{
	TouchDispatcher* dispatcher= Global::touchDispatcher();
	if(dispatcher)
	{
		TouchPoint p(id,x,y);
		dispatcher->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_END,1,&p));
	}
}




/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onResize
 * Signature: (II)V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onResize
(JNIEnv *, jclass, jint width, jint height)
{
	Window* window=Global::window();
	if(window)
	{
		window->setSize(width,height);
	}
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onUpdate
 * Signature: (F)F
 */
	JNIEXPORT jfloat JNICALL Java_com_faeris_lib_Fs_1Jni_onUpdate
(JNIEnv *, jclass, jfloat dt)
{
	return Global::scheduler()->update(dt);
}


/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    setEnv
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
	JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_setEnv
(JNIEnv * env, jclass, jstring key, jstring value)
{
	const char* t_key=env->GetStringUTFChars(key,NULL);
	const char* t_value=env->GetStringUTFChars(value,NULL);
	Sys::setEnv(t_key,t_value);
	env->ReleaseStringUTFChars(key,t_key);
	env->ReleaseStringUTFChars(value,t_value);
}

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    schedulerStop
 * Signature: ()Z
 */
	JNIEXPORT jboolean JNICALL Java_com_faeris_lib_Fs_1Jni_schedulerStop
(JNIEnv *, jclass)
{
	Scheduler* s=Global::scheduler();
	if(s)
	{
		return !s->isRunning();
	}
	return true;
}
#ifdef __cplusplus
}
#endif
