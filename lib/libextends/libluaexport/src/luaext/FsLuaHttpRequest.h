#ifndef _FS_LUA_HTTP_REQUEST_H_
#define _FS_LUA_HTTP_REQUEST_H_ 


#include "FsLuaMacros.h"
#include "sys/network/FsHttpRequest.h"
#include "sys/network/FsHttpReponse.h"




NS_FS_BEGIN
class LuaHttpRequest:public HttpRequest 
{
	public:
		static LuaHttpRequest* create();

	public:
		void onSyncReponse(HttpReponse* reponse);

	public:
		virtual const char* className();

};

NS_FS_END 

#endif /*_FS_LUA_HTTP_REQUEST_H_*/

