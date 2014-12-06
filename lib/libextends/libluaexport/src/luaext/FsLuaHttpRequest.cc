#include "FsLuaHttpRequest.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"

#include "tolua++.h"
#include "toluaext++.h"

NS_FS_BEGIN

LuaHttpRequest* LuaHttpRequest::create()
{
	return new LuaHttpRequest;
}

const char* LuaHttpRequest::className()
{
	return FS_LUA_HTTP_REQUEST_CLASS_NAME;
}



void LuaHttpRequest::onSyncReponse(HttpReponse* reponse)
{
	int lua_table=m_scriptData;
	struct lua_State* l_state=((LuaEngine*)Global::scriptEngine())->getLuaState();

	if(lua_table==-1)
	{
		return ;
	}

	toluaext_push_luatable(l_state,lua_table);  /* statck:table */
	if(!lua_istable(l_state,-1))
	{
		lua_remove(l_state,-1);
		return ;
	}
	lua_pushstring(l_state,"onReponse"); /*stack:table fname */
	lua_gettable(l_state,-2);  /* statck: table func */
	lua_remove(l_state,-2);  /* statck: func */
	if(!lua_isfunction(l_state,-1))
	{
		lua_remove(l_state,-1);
		return ;
	}

	int code=reponse->getReponseCode();

	uint8_t* data_buf=NULL;
	int data_len=0;
	reponse->getData(&data_buf,&data_len);


	uint8_t* error_buf=NULL;
	int error_len=0;
	reponse->getErrorBuf(&error_buf,&error_len);

	this->addRef();
	toluaext_pushfsobject(l_state,this);
	lua_pushinteger(l_state,code);
	lua_pushlstring(l_state,(char*)data_buf,data_len);
	lua_pushlstring(l_state,(char*)error_buf,error_len);
	if(lua_pcall(l_state,4,0,0))
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(l_state,-1));
		lua_remove(l_state,-1);
		return ;
	}
}


NS_FS_END

