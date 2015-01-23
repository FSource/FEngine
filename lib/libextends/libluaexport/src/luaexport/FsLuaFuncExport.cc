/*************************************************************************/
/*  FsLuaFuncExport.cc                                                   */
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


#include <string>
#include <string.h>

#include "tolua++.h"

#include "FsLuaExport.h"
#include "support/data/FsEncrypt.h"
#include "support/data/FsMd5.h"
#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
#include "support/util/FsLog.h"
#include "FsLuaEngine.h"
#include "FsGlobal.h"
#include "sys/FsSys.h"


NS_FS_USE

/* all function */
int luaf_xorstring(lua_State* l)
{
	size_t data_len,key_len;
	const char* data=luaL_checklstring(l,1,&data_len);
	const char* key=luaL_checklstring(l,2,&key_len);

	uint8_t* data_out=NULL;
	uint data_out_len=0;

	FsEncrypt_Xor( (uint8_t*)data,  
					data_len,

				    (uint8_t**) &data_out, 
					 &data_out_len,

				    (uint8_t*)key, 
					(uint)key_len
					);

	lua_pushlstring(l,(char*)data_out,data_out_len);
	delete[] data_out;

	return 1;
}

int luaf_escstring(lua_State* l)
{
	size_t data_len;
	const char* data=luaL_checklstring(l,1,&data_len);

	std::string ret;
	for(size_t i=0;i<data_len;i++)
	{
		uint8_t cur=data[i];
		switch(cur)
		{
			case '\a':
				ret.append("\\a");
				break;
			case  '\b':
				ret.append("\\b");
				break;
			case '\n':
				ret.append("\\n");
				break;
			case '\r':
				ret.append("\\r");
				break;
			case '\t':
				ret.append("\\t");
				break;
			case '\v':
				ret.append("\\v");
				break;
			case '\\':
				ret.append("\\\\");
				break;
			case '\"':
				ret.append("\\\"");
				break;
			case '\'':
				ret.append("\\\'");
				break;
			case '[':
				ret.append("\\[");
				break;
			case ']':
				ret.append("\\]");
				break;
			default:
				ret.append(1,cur);
		}
	}
	lua_pushlstring(l,ret.c_str(),ret.size());
	return 1;
}


int luaf_savefile(lua_State* l)
{
	size_t file_name_len,data_len;
	const char* file_name=luaL_checklstring(l,1,&file_name_len);
	const char* data=luaL_checklstring(l,2,&data_len);


	int ret=VFS::saveFile(file_name,(const uint8_t*)data,data_len);
	lua_pushinteger(l,ret);
	return 1;
}


int luaf_loadfile(lua_State* l)
{
	const char* file_name=luaL_checkstring(l,1);

	uint8_t* data=NULL;
	uint data_len=0;
	int ret=VFS::loadFile(file_name,&data,&data_len);
	if(ret==-1)
	{
		lua_pushnil(l);
	}
	else 
	{
		lua_pushlstring(l,(const char*) data,data_len);
		delete[] data;
	}
	return 1;
}

int luaf_log(lua_State* l)
{
	const char* info=luaL_checkstring(l,1);
	FsUtil_Log("%s",info);
	return 0;
}
int luaf_logtag(lua_State* l)
{
	const char* tag=luaL_checkstring(l,1);
	const char* info=luaL_checkstring(l,2);
	FsUtil_Log(tag,info);
	return 0;
}

int luaf_import(lua_State* l)
{
	const char* file=luaL_checkstring(l,1);

	LuaEngine* engine=(LuaEngine*)Global::scriptEngine();
	if(engine==NULL)
	{
		lua_pushboolean(l,false);
	}
	if(engine->executeFile(file)==0)
	{
		lua_pushboolean(l,true);
	}
	else 
	{
		FS_TRACE_WARN("Can't f_import File(%s)",file);
		lua_pushboolean(l,false);
	}
	return 1;
}

int luaf_exit(lua_State* l)
{
	Scheduler* s=Global::scheduler();
	s->stop();
	return 0;
}

int luaf_setenv(lua_State* l)
{
	const char* key=luaL_checkstring(l,1);
	const char* value=luaL_checkstring(l,2);

	Sys::setEnv(key,value);
	return 0;
}

int luaf_mappackage(lua_State* l)
{
	const char* package_name=luaL_checkstring(l,1);
	const char* dir=luaL_checkstring(l,2);
	const char* type=luaL_checkstring(l,3);

	Package* package=NULL;
	if (strcmp(type,"zip")==0 ){

		package=Package::create(package_name,Package::PACKAGE_ZIP);
	}
	else if(strcmp(type,"fgz")==0){
		package=Package::create(package_name,Package::PACKAGE_FGZ);

	}
	else 
	{
		lua_pushboolean(l,false);
		return 1;
	}


	if( package==NULL )
	{
		lua_pushboolean(l,false);
		return 1;
	}


	VFS::mapPackage(dir,package);
	FS_SAFE_DEC_REF(package);
	lua_pushboolean(l,true);

	return 1;
}


int luaf_getenv(lua_State* l)
{
	const char* key=luaL_checkstring(l,1);
	const char* value=Sys::getEnv(key);

	if(value==NULL)
	{
		lua_pushnil(l);
	}
	else
	{
		lua_pushstring(l,value);
	}
	return 1;

}

int luaf_gettablehandlenu(lua_State* l)
{

	int nu=toluaext_get_luatable_nu();
	lua_pushinteger(l,nu);

	return 1;
}

int luaf_md5binary(lua_State* l)
{
	size_t msg_length=0;
	const char* msg=luaL_checklstring(l,1,&msg_length);

	char ret[FS_MD5_HASHSIZE];
	FsMd5_ToBinaryBit(msg,msg_length,ret);
	lua_pushlstring(l,ret,FS_MD5_HASHSIZE);
	return 1;
}

int luaf_md5string(lua_State* l)
{
	size_t msg_length=0;
	const char* msg=luaL_checklstring(l,1,&msg_length);

	char ret[FS_MD5_HASHSIZE*2+1];
	FsMd5_ToString(msg,msg_length,ret);
	lua_pushlstring(l,ret,FS_MD5_HASHSIZE*2);
	return 1;
}

int luaf_tofsobject(lua_State* l)
{
	void* data=lua_touserdata(l,-1);
	FsObject* fobject=(FsObject*) data;
	toluaext_pushfsobject(l,fobject);
	return 1;
}

static const struct luaL_reg luafuncs[]=
{
	{"f_xorstring",luaf_xorstring},
	{"f_escstring",luaf_escstring},
	{"f_savefile",luaf_savefile},
	{"f_loadfile",luaf_loadfile},
	{"f_log",luaf_log},
	{"f_logtag",luaf_logtag},
	{"f_import",luaf_import},
	{"f_exit",luaf_exit},
	{"f_getenv",luaf_getenv},
	{"f_setenv",luaf_setenv},
	{"f_mappackage",luaf_mappackage},
	{"f_gettablehandlenu",luaf_gettablehandlenu},
	{"f_md5string",luaf_md5string},
	{"f_md5binary",luaf_md5binary},
	{"f_tofsobject",luaf_tofsobject},
	{NULL,NULL},
};




int tolua_FsLuaFuncExport_open(lua_State* l)
{
	for(int i=0;luafuncs[i].name&&luafuncs[i].func;i++)
	{
		lua_pushcfunction(l, luafuncs[i].func);
		lua_setglobal(l, luafuncs[i].name);
	}

	return 0;
}

