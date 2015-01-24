/*************************************************************************/
/*  FsLuaHttpRequest.cc                                                  */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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

