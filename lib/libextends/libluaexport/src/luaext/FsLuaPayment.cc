#include "FsLuaMacros.h"
#include "luaext/FsLuaAction.h"
#include "FsLuaEngine.h"
#include "FsGlobal.h"

#include "FsLuaPayment.h"

NS_FS_BEGIN

LuaPayment* LuaPayment::getInstance()
{
	Payment* ret=FsPayment_GetGlobal();
	if(ret==NULL)
	{
		ret=new LuaPayment();
		FsPayment_SetGlobal(ret);
	}
	return (LuaPayment*)ret;
}


void LuaPayment::billingFinish(int trade_id,int ret_code,const char* msg)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onBillingFinish",4,0,"fiis",this,trade_id,ret_code,msg);
}


const char* LuaPayment::className()
{
	return FS_LUA_PAYMENT_CLASS_NAME;
}


LuaPayment::LuaPayment()
{

}

LuaPayment::~LuaPayment()
{

}


NS_FS_END



