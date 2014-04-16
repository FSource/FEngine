#include "FsPayment.h"
#include "scheduler/FsTask.h"
#include "scheduler/FsScheduler.h"
#include "FsGlobal.h"
#include "support/util/FsScriptUtil.h"

NS_FS_BEGIN

static int S_TradeId=0;

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
			m_payment->billingFinish(m_tradeId,m_retcode,m_msg.c_str());
		}

	protected:
		PaymentTask(Payment* payment,int trade_id,int ret_code,const char* msg)
		{
			m_payment=payment;
			FS_SAFE_ADD_REF(payment);

			m_tradeId=trade_id;
			m_retcode=ret_code;
			m_msg=std::string(msg);
		}

		virtual ~PaymentTask()
		{
			FS_SAFE_DEC_REF(m_payment);
		}

	private:
		Payment* m_payment;
		int m_tradeId;
		int m_retcode;
		std::string m_msg;

};

static void S_PendBillingResult(Payment* payment,int trade_id,int ret_code,const char* msg)
{
	PaymentTask* task=PaymentTask::create(payment,trade_id,ret_code,msg);
	Global::scheduler()->runTask(task);
}




void Payment::init(const char* msg)
{

}

void Payment::setConfig(const char* value)
{
}

int Payment::billing(const char* config)
{
	S_TradeId++;

	FsDict* namecode=ScriptUtil::parseJson(config);
	FsString* result=ScriptUtil::getString(namecode,"result");

	if(!result)
	{
		char ret_msg[256];
		sprintf(ret_msg,"{\"msg\":\"Paycode Result Not Set\"}");

		S_PendBillingResult(this,S_TradeId,FS_PAYMENT_ERROR,ret_msg);

		namecode->decRef();
		return S_TradeId;
	}


	if(result->equal("success"))
	{
		const char* ret_msg="{\"msg\":\"success\"}";
		S_PendBillingResult(this,S_TradeId,FS_PAYMENT_SUCCESS,ret_msg);
	}
	else if (result->equal("failed"))
	{
		const char* ret_msg="{\"msg\":\"failed\"}";

		S_PendBillingResult(this,S_TradeId,FS_PAYMENT_FAILED,ret_msg);
	}
	else if(result->equal("cancel"))
	{
		const char* ret_msg="{\"msg\":\"failed\"}";
		S_PendBillingResult(this,S_TradeId,FS_PAYMENT_CANCEL,ret_msg);
	}
	else if(result->equal("error"))
	{
		const char* ret_msg="{\"msg\":\"error\"}";
		S_PendBillingResult(this,S_TradeId,FS_PAYMENT_ERROR,ret_msg);
	}
	else 
	{
		const char* ret_msg="{\"msg\":\"unkown result\"";
		S_PendBillingResult(this,S_TradeId,FS_PAYMENT_ERROR,ret_msg);
	}


	namecode->decRef();
	return S_TradeId;
}


void Payment::billingFinish(int trade_id,int ret_code,const char* msg)
{
	/* Not Nothing Here
	 * SubClass Need Override it 
	 */
}



Payment::Payment()
{
}

Payment::~Payment()
{
}





NS_FS_END










