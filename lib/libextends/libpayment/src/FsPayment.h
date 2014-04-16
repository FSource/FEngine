#include "FsMacros.h" 

NS_FS_BEGIN 

enum
{
	FS_PAYMENT_SUCCESS=0,
	FS_PAYMENT_CANCEL=1,
	FS_PAYMENT_FAILED=2,
	FS_PAYMENT_ERROR=3,
};

class Payment;

void FsPayment_SetGlobal(Payment* ment);
Payment* FsPayment_GetGlobal();
void FsPayment_DropGlobal();


/* Note: 1.When Create Payment Class, Caller Must addRef It Before Call 
 * 		 Any Interface To Avoid Crash 
 * 		 2.When Create it, User Must Call FsPayment_SetGlobal();
 */

/* @interface:
 *
 *		void init(const char* msg)
 *		@param:{
 *			"msg": used to init Payment,used json data format 
 *		}
 *
 *
 * 		void setConfig(const char* config)
 * 		@param{
 * 			"config": information about Payment,used json data format
 * 		}
 *
 * 		
 * 		int billing(const char* name,const char* msg)
 * 		@param{
 * 			"name": paycode name
 * 			"msg": extra information 
 * 		}
 * 		@return: the trade_id used to identify  billing 
 *
 *
 *
 * 		void billingFinish(int trade_id,int ret_code,const char* msg);
 * 		@description:when Payment finish,this interface will called. 
 * 		@param{
 * 			"trade_id": the trade_id about the billing,user can use to identify the billing
 * 			"ret_code": the result about the billing
 * 			"msg": extra msg about the billing
 * 		}
 *
 */

NS_FS_END 

#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/fake/FsPaymentFake.h"

#elif FS_PLATFORM_OS(FS_OS_WIN32)
	#include "platform/fake/FsPaymentFake.h"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/android/FsPaymentAndroid.h"
#else 
	#error "unsupport platform"
#endif













