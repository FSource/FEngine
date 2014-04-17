#ifndef _FS_PAYMENT_H_H_
#define _FS_PAYMENT_H_H_

#include "FsMacros.h" 
#include "FsObject.h"

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


class Payment:public FsObject 
{
	public:

		/*
		 *void init(const char* msg)
		 *@param:{
		 *		"msg": used to init Payment,used json data format 
		 *}
		 */
		void init(const char* msg);


		/*
		 * void setConfig(const char* config)
		 * @param{
		 * 		"config": information about Payment,used json data format
		 * 	}
		 */
		void setConfig(const char* config);


		/*int billing(const char* msg)
		 *@param{
		 *		"name": paycode name
		 * 		"msg": extra information 
		 * 	}
		 * 	@return: the trade_id used to identify  billing 
		 */
		int billing(const char* name,const char* msg);

	public:
		/*@description:when Payment finish,this interface will called. 
		 *@param{
		 *		"trade_id": the trade_id about the billing,user can use to identify the billing
		 * 		"ret_code": the result about the billing
		 * 		"msg": extra msg about the billing
		 *}
		 */

		virtual void billingFinish(int trade_id,int ret_code,const char* msg);


	protected:
		Payment();
		virtual ~Payment();

};


NS_FS_END 

#endif /*_FS_PAYMENT_H_H_*/



