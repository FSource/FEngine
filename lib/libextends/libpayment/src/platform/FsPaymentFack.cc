#include "FsPayment.h"

NS_FS_BEGIN

void Payment::init(const char* msg)
{

}

void Payment::setConfig(const char* config)
{
	FsDict* ret=ScriptUtil::parseJson(config);
	if(!ret)
	{
		FS_TRACE_WARN("parse json string failed");
		return;
	}

	FsDict* win32_config=ScriptUtil::getDict(ret,"win32");

	if(!win32_config)
	{
		FS_TRACE_WARN("can't find win32 config in config");
		ret->decRef();
		return;
	}

	FS_SAFE_ASSIGN(m_payinfo,win32_config);
	ret->decRef();
}

int Payment:billing(const char* name,const char* msg)
{
	m_tradeId++;

	if(m_payinfo==NULL)
	{
		const char* ret_msg="{\"msg\":\"Payment Not Set Config Info\"}"
		billingFinish(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
	}

	FsDict* paycode=ScriptUtil::getDict(m_payinfo,"paycodes");
	if(!paycode)
	{
		const char* ret_msg="{\"msg\":\"PayCodes Not Exist"\"}";
		billingFinish(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
	}

	FsDict* namecode=

}


Payment::Payment()
{
	m_payinfo=NULL;
}

Payment::~Payment()
{
	FS_SAFE_DESTORY(m_payinfo);
}

NS_FS_END

