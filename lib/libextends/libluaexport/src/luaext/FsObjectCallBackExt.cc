#include "FsObjectCallBackExt.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN


static void FsLFsObject_onFinalize(FsObject* ob)
{
	LuaEngine* engine=(LuaEngine*)Global::scriptEngine();
	if(engine)
	{
		engine->callFunctionInTable(ob->m_scriptData,"onFinalize",1,0,"u<FsObject>",ob);
	}
}

void FsLFsObject_CallBackAssign(FsObject* ob)
{
	ob->onFinalize=FsLFsObject_onFinalize;
}













NS_FS_END 

