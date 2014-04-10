#include <string.h>


#ifdef __cplusplus
extern "C"
{
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua_event.h"
#include "toluaext++.h"
#include "lua_cjson.h"
#ifdef __cplusplus
} /* extern "C" */
#endif



#include "FsLuaMacros.h"
#include "FsLuaEngine.h"
#include "luaexport/FsLuaExport.h"
#include "FsGlobal.h"
#include "support/util/FsLog.h"
#include "sys/io/FsVFS.h"
#include "sys/event/FsTouchDispatcher.h"


#define FS_LUA_ENGINE_CLASS_NAME "LuaEngine"


NS_FS_BEGIN



LuaEngine* LuaEngine::create()
{
	LuaEngine* ret=new LuaEngine();
	return ret;
}



LuaEngine::LuaEngine()
{
	m_state=lua_open();

	/* init lua libs */
	luaL_openlibs(m_state);

	/* init tolua++ */
	toluaext_open(m_state);

	luaopen_cjson(m_state);

#if FS_CONFIG(FS_EXPORT_LIB_FAERIS)
	/* init faeris interface */
	tolua_FsLibFaeris_open(m_state);
#endif 




#if FS_CONFIG(FS_EXPORT_LIB_LUA_FUNC)
	tolua_FsLuaFuncExport_open(m_state);
	tolua_FsLibLuaScript_open(m_state);
#endif /* FS_EXPORT_LIB_LUA_FUNC */


#if FS_CONFIG(FS_EXPORT_LIB_SPINE_SPRITE)
	tolua_FsSpineSprite_open(m_state);
#endif 

#if FS_CONFIG(FS_EXPORT_LIB_BOX2D) 
	tolua_Box2D_open(m_state);
#endif

#if FS_CONFIG(FS_EXPORT_LIB_SENSOR)
	tolua_FsLibSensor_open(m_state);
#endif 

}


LuaEngine::~LuaEngine()
{
	lua_gc(m_state,LUA_GCCOLLECT,0);
	lua_close(m_state);
	m_state=NULL;
}


int LuaEngine::executeString(const char* codes)
{
	int ret=luaL_dostring(m_state,codes);
	if(ret!=0)
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
		lua_pop(m_state,1);
		return -1;
	}
	return 0;
}



#define FS_DEFALUT_LUA_BUFFER_SIZE 2048
static  char s_buffer[FS_DEFALUT_LUA_BUFFER_SIZE];

static const char* s_file_lua_reader(lua_State* L,void* data,size_t* size) 
{
	FsFile* file=(FsFile*)data;
	int readbyte=file->read(s_buffer,FS_DEFALUT_LUA_BUFFER_SIZE);
	if(readbyte<0)
	{
		return 0;
	}

	*size=readbyte;
	return s_buffer;
}

int LuaEngine::executeFile(const char* filename)
{
	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FsUtil_Log("[LUA_ERROR] File Not Found %s", filename);
		return -1;
	}
	if(lua_load(m_state,s_file_lua_reader,file,filename)||lua_pcall(m_state,0,LUA_MULTRET,0))
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
		lua_pop(m_state,1);
		file->decRef();
		return -1;
	}
	file->decRef();
	return 0;
}


void LuaEngine::pushInteger(int value)
{
	lua_pushinteger(m_state,value);
}
void LuaEngine::pushNumber(double value)
{
	lua_pushnumber(m_state,value);
}
void LuaEngine::pushString(const char* str)
{
	lua_pushstring(m_state,str);
}
void LuaEngine::pushBoolean(bool value)
{
	lua_pushboolean(m_state,value);
}
void LuaEngine::pushFsObject(FsObject* ob)
{
	toluaext_pushfsobject(m_state,ob);
}

void LuaEngine::pushUserType(void* value,const char* type)
{
	tolua_pushusertype(m_state,value,type);
}

void LuaEngine::pushCFunction(CFunction func)
{

	lua_pushcfunction(m_state,func);
}

void LuaEngine::pop()
{
	lua_pop(m_state,1);
}
int LuaEngine::toInteger(int index)
{
	return lua_tointeger(m_state,index);
}
float LuaEngine::toNumber(int index)
{
	return (float)lua_tonumber(m_state,index);
}
bool LuaEngine::toBoolean(int index)
{
	return lua_toboolean(m_state,index);
}

const char* LuaEngine::toString(int index)
{
	return lua_tostring(m_state,index);
}


void LuaEngine::setGlobalCFunction(const char* name,CFunction func)
{
	lua_pushcfunction(m_state,func);
	lua_setfield(m_state,LUA_GLOBALSINDEX,name);
}

void LuaEngine::setGlobalUserType(const char* name,void* data,const char* type)
{
	tolua_pushusertype(m_state,data,type);
	lua_setfield(m_state,LUA_GLOBALSINDEX,name);
}



/* call back */
bool LuaEngine::callFunctionInTable(int lua_table,const char* func_name,int argnu,int retnu,const char* fmt,...)
{

	int top=lua_gettop(m_state);

	if(lua_table==-1)
	{
		return false;
	}
	toluaext_push_luatable(m_state,lua_table);  /* statck:table */
	if(!lua_istable(m_state,-1))
	{
		lua_remove(m_state,-1);
		return false;
	}
	lua_pushstring(m_state,func_name); /*stack:table fname */
	lua_gettable(m_state,-2);  /* statck: table func */
	lua_remove(m_state,-2);  /* statck: table */
	if(!lua_isfunction(m_state,-1))
	{
		lua_remove(m_state,-1);
		return false;
	}


	va_list ap;
	va_start(ap,fmt);

	int rel_arg=0;
	char pstr;
	const char* src=fmt;
	while((pstr=*(src++)))
	{
		switch(pstr)
		{
			case 'n':
				{
					float value=(float)va_arg(ap,double);
					pushNumber(value);
					rel_arg++;
				}
				break;
			case 'i':
				{
					int value=va_arg(ap,int);
					pushInteger(value);
					rel_arg++;
				}
				break;
			case 'f':
				{
					FsObject* value=va_arg(ap,FsObject*);
					pushFsObject(value);
					rel_arg++;
				}
				break;
			case 's':
				{
					const char* value=va_arg(ap,const char*);
					pushString(value);
					rel_arg++;
				}
				break;
			case 'b':
				{
					bool value=(bool)va_arg(ap,int);
					pushBoolean(value);
					rel_arg++;
				}
				break;
			case 'u':
				{
					void* value=va_arg(ap,void*);
					src++;        					 /* skip '<' */
					char t_pchar;
					std::string t_name;
					while((t_pchar=*(src++))!='>')   /* get type name */
					{
						t_name.append(1,t_pchar);
					}
					pushUserType(value,t_name.c_str());
					rel_arg++;
					break;
				}
			default:
				{
					FS_TRACE_WARN("Unkown Format Type");
				}
		}
	}
	va_end(ap);

	if(argnu!=rel_arg)
	{
		FS_TRACE_WARN("Some Error For Args(needarg=%d,realarg=%d)",argnu,rel_arg);
		lua_settop(m_state,top);
		return false;
	}
	if(lua_pcall(m_state,argnu,retnu,0))
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
		lua_remove(m_state,-1);
		return false;
	}
	return true;
}


bool LuaEngine::callFunctionInName(const char* luaFunc, const char* argt, ...) const
{
	lua_getglobal(m_state, luaFunc);
	int argn = argt ? strlen(argt) : 0;

	va_list ap;
	va_start(ap, argt);

	for (int i=0; i<argn; i++)
	{
		switch (argt[i])
		{
		case 'c':
			{
				const char* str = va_arg(ap, const char*);
				lua_pushstring(m_state, str);
			}
			break;
		case 'p':
			{
				void* p = va_arg(ap, void*);
				lua_pushlightuserdata(m_state, p);
			}
			break;
		case 'i':
			{
				int v = va_arg(ap, int);
				lua_pushinteger(m_state, v);
			}
			break;
		case 'f':
			{
				double d = va_arg(ap, double);
				lua_pushnumber(m_state, d);
			}
			break;
		}
	}

	if(lua_pcall(m_state,argn,0,0))
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
		lua_remove(m_state,-1);
		return false;
	}

	return true;

}



/* no args */
bool LuaEngine::callFunctionInTable(int lua_table,const char* func_name,int retnu)
{
	return callFunctionInTable(lua_table,func_name,0,retnu,"");
}


bool LuaEngine::callFunction(int lua_function,const char* name,const char* fmt,...)
{
	return true;
}



/* lua function */
void LuaEngine::removeLuaFunction(int refid)
{
	toluaext_remove_luafunction(m_state,refid);
}

void LuaEngine::pushLuaFunction(int refid)
{
	toluaext_push_luafunction(m_state,refid);
}

/* lua table */
void LuaEngine::removeLuaTable(int refid)
{
	toluaext_remove_luatable(m_state,refid);
}

void LuaEngine::pushLuaTable(int refid)
{
	toluaext_push_luatable(m_state,refid);
}


bool LuaEngine::call(int argu,int retnu)
{
	if(lua_pcall(m_state,argu,retnu,0))
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
		lua_remove(m_state,-1);
		return false;
	}
	return true;
}


void LuaEngine::releaseData(int data)
{
	toluaext_remove_luatable(m_state,data);
}
int LuaEngine::collectGarbage()
{
	lua_gc(m_state,LUA_GCCOLLECT,0);
	return 0;
}

const char*  LuaEngine::className()
{
	return FS_LUA_ENGINE_CLASS_NAME;
}



void _FsScriptExtends_Finalize(FsObject* ob) 
{

	LuaEngine* engine=(LuaEngine*)Global::scriptEngine();
	if(engine)
	{
		engine->callFunctionInTable(ob->m_scriptData,"onFinalize",1,0,"u<FsObject>",ob);
	}
}


NS_FS_END














