
#include <jni.h>

#include "FsMacros.h"
#include "FsLuaEngine.h"

#include "sys/FsSys.h"
#include "FsGlobal.h"


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

