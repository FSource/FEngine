#include "FsPayMM.h"
#include "tolua++.h"


/* Exported function */
TOLUA_API int  tolua_FsPayMM_open (lua_State* tolua_S);

NS_FS_BEGIN

static PayMM* S_payMM=NULL;

PayMM* PayMM::getInstance()
{
	if(S_payMM==NULL)
	{
		S_payMM=new PayMM();
		FS_NO_REF_DESTROY(S_payMM);
	}

	return S_payMM;
}


void PayMM::purgeInstance()
{
	if(S_payMM)
	{
		FS_DESTROY(S_payMM);
		S_payMM=NULL;
	}
}

void PayMM::init(const char* appid,const char* appkey)
{

}

std::string PayMM::order(const char* paycode)
{

}

void PayMM::billingFinish(const std::string& id,int status)
{

}


void PayMM::initFinish()
{

}


void Fs_PayMM_Moduel_Init()
{
	LuaScriptEngine* engine=Global::scriptEngine();
	struct lua_State* st=engine->getLuaState();
	tolua_FsPayMM_open(st);
}


void Fs_PayMM_Moduel_Exit()
{

}



NS_FS_END

