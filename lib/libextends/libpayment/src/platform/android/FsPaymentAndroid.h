#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class Payment:public FsObject
{
	public:
		void init(const char* msg);
		void setConfig(const char* config);
		int billing(const char* name,const char* msg);

	public:
		virtual billingFinish(int trade_id,int ret_code,const char* msg);
};



NS_FS_END






