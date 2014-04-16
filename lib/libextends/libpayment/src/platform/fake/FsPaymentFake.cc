#include "FsPayment.h"
#include "scheduler/FsTask.h"
#include "scheduler/FsScheduler.h"
#include "FsGlobal.h"

NS_FS_BEGIN

class PaymentTask:public Task
{
	public:
		static PaymentTask* create(Payment* payment,int trade_id,int ret_code,const char* msg)
		{
			return new PaymentTask(payment,trade_id,ret_code,msg);
		}

	public:

		virtual void run()
		{
			m_payment->billingFinish(trade_id,ret_code,msg);
		}

	protected:
		PaymentTask(Payment* payment,int trade_id,int ret_code,const char* msg)
		{
			m_payment=payment;
			FS_SAFE_ADDREF(payment);

			m_tradeId=trade_id;
			m_retcode=ret_code;
			m_msg=std::string(msg);
		}

		virtual ~Payment()
		{
			FS_SAFE_DECREF(m_payment);
		}

	private:
		Payment* m_payment;
		int m_tradeId;
		int m_retcode;
		std::string m_msg;

}



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
	FsDict* config=NULL;

	/* First Find Platform  Config */
#if FS_PLATFORM_OS(FS_OS_WIN32)
	config=ScriptUtil::getDict(ret,"win32");
#elif FS_PLATFORM_OS(FS_OS_LINUX)
	config=ScriptUtil::getDict(ret,"linux");
#endif 

	/* Second Find Fake Config */
	if(!config)
	{
		config=ScriptUtil::getDict(ret,"fake");
	}

	if(!config)
	{
		FS_TRACE_WARN("can't find win32 config in config");
		ret->decRef();
		return;
	}

	FS_SAFE_ASSIGN(m_payinfo,config);
	ret->decRef();
}

int Payment:billing(const char* name,const char* msg)
{
	m_tradeId++;

	if(m_payinfo==NULL)
	{
		const char* ret_msg="{\"msg\":\"Payment Not Set Config Info\"}"
		pendBillingResult(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
		return m_tradeId;
	}

	FsDict* paycode=ScriptUtil::getDict(m_payinfo,"paycodes");
	if(!paycode)
	{
		const char* ret_msg="{\"msg\":\"PayCodes Not Exist"\"}";
		pendBillingResult(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
		return m_tradeId;
	}

	FsDict* namecode=ScriptUtil::getDict(paycode,name);

	if(!namecode)
	{
		const char ret_msg[256];
		sprintf(ret_msg,"{"\"msg\":\"Can't Get Paycode(%s) Config\"",name);
		pendBillingResult(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
		return m_tradeId;
	}


	FsString* result=ScriptUtil::getString(namecode,"result");

	if(!result)
	{
		const char* ret_msg[256];
		sprintf(ret_msg,"{"\"msg\":\"Paycode(%s) Result Not Config\"",name);
		pendBillingResult(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
		return m_tradeId;
	}

	if(result->equal("success"))
	{
		const char* ret_msg="{\"msg\":\"success\"}";
		pendBillingResult(m_tradeId,FS_PAYMENT_SUCCESS,ret_msg);
		return m_tradeId;
	}
	else if (result->equal("failed"))
	{
		const char* ret_msg="{\"msg\":\"failed\"}";

		pendBillingResult(m_tradeId,FS_PAYMENT_FAILED,ret_msg);
		return m_tradeId;
	}
	else if(result->equal("cancel"))
	{
		const char* ret_msg="{\"msg\":\"failed\"}";
		pendBillingResult(m_tradeId,FS_PAYMENT_CANCEL,ret_msg);
		return m_tradeId;
	}
	else if(result->equal("error"))
	{
		const char* ret_msg="{\"msg\":\"error\"}";
		pendBillingResult(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
		return m_tradeId;
	}
	else 
	{
		const char* ret_msg="{\"msg\":\"unkown result\"";
		pendBillingResult(m_tradeId,FS_PAYMENT_ERROR,ret_msg);
		return m_tradeId;
	}

	return m_tradeId;
}


void Payment::billingFinish(int trade_id,int ret_code,const char* msg)
{
	/* Not Nothing Here
	 * SubClass Need Override it 
	 */
}

void Payment::pendBillingResult(int trade_id,int ret_code,const char* msg)
{
	PaymentTask* task=PaymentTask::create(trade_id,ret_code,msg);
	Global::scheduler():runTask(task);
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










