#ifndef _FS_LUA_PAYMENT_H_
#define _FS_LUA_PAYMENT_H_

#include "FsPayment.h"

NS_FS_BEGIN

class LuaPayment:public Payment
{
	public:

		static LuaPayment* getInstance();
		static void purgeInstance();

	public:
		virtual void billingFinish(int trade_id,int ret_code,const char* msg);
		virtual const char* className();

	protected:
		LuaPayment();
		~LuaPayment();

};

NS_FS_END 


#endif /*_FS_LUA_PAYMENT_H_*/


