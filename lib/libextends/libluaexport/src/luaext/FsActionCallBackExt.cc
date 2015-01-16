
#include "FsActionCallBackExt.h"
#include "FsObjectCallBackExt.h"

#include "stage/action/FsAction.h"
#include "stage/action/FsFixTimeAction.h"

#include "FsGlobal.h"
#include "FsLuaEngine.h"


NS_FS_BEGIN


/* ---------------------- Action ------------------*/


static bool FsLAction_onUpdate(Action* an,ActionTarget* target,float dt,float* out)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(an->m_scriptData,"onUpdate",3,2,"ffn",an,target,dt))
	{
		return an->update(target,dt,out);
	}
	bool ret=se->toBoolean(-2);
	*out=se->toNumber(-1);
	se->pop();
	se->pop();
	return ret;
}

static bool FsLAction_onRun(Action* an,ActionTarget* target,float dt,float* out)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(an->m_scriptData,"onRun",3,2,"ffn",an,target,dt))
	{
		return an->run(target,dt,out);
	}
	bool ret=se->toBoolean(-2);
	*out=se->toNumber(-1);
	se->pop();
	se->pop();
	return ret;
}

static void FsLAction_onBegin(Action* an)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(an->m_scriptData,"onBegin",1,0,"f",an))
	{
		return an->begin();
	}
}

static void FsLAction_onFinish(Action* an)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(an->m_scriptData,"onFinish",1,0,"f",an))
	{
		return an->finish();
	}
}

static bool FsLAction_onRestart(Action* an)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(an->m_scriptData,"onRestart",1,1,"f",an))
	{
		return an->restart();
	}

	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;

}



void FsLAction_CallBackAssign(Action* an)
{
	FsLFsObject_CallBackAssign(an);

	//an->onUpdate=FsLAction_onUpdate;
	an->onRun=FsLAction_onRun;
	an->onBegin=FsLAction_onBegin;
	an->onFinish=FsLAction_onFinish;
	//an->onRestart=FsLAction_onRestart;
}


/*--------------------- FixTimeAction ---------------------- */

static void FsLFixTimeAction_onStep(FixTimeAction* an,ActionTarget* at,float percent)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(an->m_scriptData,"onStep",3,0,"ffn",an,at,percent))
	{
		return an->step(at,percent);
	}
}

void FsLFixTimeAction_CallBackAssign(FixTimeAction* an)
{
	FsLAction_CallBackAssign(an);
	an->onStep=FsLFixTimeAction_onStep;
}






NS_FS_END

