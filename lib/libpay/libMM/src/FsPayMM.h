#ifndef _FS_PAY_MM_H_
#define _FS_PAY_MM_H_

#include <string>

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class PayMM:public FsObject
{
	public:
		static PayMM* getInstance();
		static void purgeInstance();

	public:
		void init(const char* appid,const char* appkey);
		std::string order(const char* paycode);

	public:
		virtual void billingFinish(const std::string& id,int status);
		virtual void initFinish();

	protected:
		PayMM();
		~PayMM();
};


void Fs_PayMM_Moduel_Init();
void Fs_PayMM_Moduel_Exit();


NS_FS_END

#endif /*_FS_PAY_MM_H_*/

