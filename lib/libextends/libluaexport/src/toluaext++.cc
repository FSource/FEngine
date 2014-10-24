#include <string.h>
#include "math/FsMathUtil.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "lua.h"
#include "lauxlib.h"
#include "tolua_event.h"
#include "toluaext++.h"

#ifdef __cplusplus
} /* extern "C" */
#endif


#include "FsObject.h"

#define TOLUA_REFID_FUNCTION_MAPPING "tolua_reffunction_mapping"
#define TOLUA_REFID_TABLE_MAPPING  "tolua_table_mapping"
NS_FS_USE


TOLUA_API void toluaext_open(lua_State* L)
{
	/* register function table */
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING); /*statck "str"  table */
	lua_newtable(L);
	lua_rawset(L,LUA_REGISTRYINDEX);

	/* register table table */
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING); /*statck "str"  table */
	lua_newtable(L);
	lua_rawset(L,LUA_REGISTRYINDEX);
}



TOLUA_API void toluaext_pushfsobject(lua_State* L,Faeris::FsObject* value)
{
	if (value == NULL)
	{
		lua_pushnil(L);
	}
	else
	{
		const char* type=value->className();
		luaL_getmetatable(L, type);
		lua_pushstring(L,"tolua_ubox");
		lua_rawget(L,-2);        /* stack: mt ubox */
		if (lua_isnil(L, -1)) {
			lua_pop(L, 1);
			lua_pushstring(L, "tolua_ubox");
			lua_rawget(L, LUA_REGISTRYINDEX);
		};
		lua_pushlightuserdata(L,value);
		lua_rawget(L,-2);                       /* stack: mt ubox ubox[u] */

		if (lua_isnil(L,-1))
		{
			lua_pop(L,1);                          /* stack: mt ubox */
			lua_pushlightuserdata(L,value);
			*(void**)lua_newuserdata(L,sizeof(void *)) = value;   /* stack: mt ubox u newud */
			lua_pushvalue(L,-1);                   /* stack: mt ubox u newud newud */
			lua_insert(L,-4);                      /* stack: mt newud ubox u newud */
			lua_rawset(L,-3);                      /* stack: mt newud ubox */
			lua_pop(L,1);                          /* stack: mt newud */
			/*luaL_getmetatable(L,type);*/
			lua_pushvalue(L, -2);			/* stack: mt newud mt */
			lua_setmetatable(L,-2);			/* stack: mt newud */


#ifdef LUA_VERSION_NUM
			if(value->m_scriptData==-1)
			{
				lua_pushvalue(L, TOLUA_NOPEER);
			}
			else
			{
				toluaext_push_luatable(L,value->m_scriptData);
			}
			lua_setfenv(L, -2);
#endif
		}
		else
		{
			/* check the need of updating the metatable to a more specialized class */
			lua_insert(L,-2);                       /* stack: mt ubox[u] ubox */
			lua_pop(L,1);                           /* stack: mt ubox[u] */
			lua_pushstring(L,"tolua_super");
			lua_rawget(L,LUA_REGISTRYINDEX);        /* stack: mt ubox[u] super */
			lua_getmetatable(L,-2);                 /* stack: mt ubox[u] super mt */
			lua_rawget(L,-2);                       /* stack: mt ubox[u] super super[mt] */
			if (lua_istable(L,-1))
			{
				lua_pushstring(L,type);                 /* stack: mt ubox[u] super super[mt] type */
				lua_rawget(L,-2);                       /* stack: mt ubox[u] super super[mt] flag */
				if (lua_toboolean(L,-1) == 1)   /* if true */
				{
					lua_pop(L,3);	/* mt ubox[u]*/
					lua_remove(L, -2);
					return;
				}
			}
			/* type represents a more specilized type */
			/*luaL_getmetatable(L,type);             // stack: mt ubox[u] super super[mt] flag mt */
			lua_pushvalue(L, -5);					/* stack: mt ubox[u] super super[mt] flag mt */
			lua_setmetatable(L,-5);                /* stack: mt ubox[u] super super[mt] flag */
			lua_pop(L,3);                          /* stack: mt ubox[u] */
		}
		lua_remove(L, -2);	/* stack: ubox[u]*/
	}
}

TOLUA_API int toluaext_to_luafunction(lua_State* L,int lo,int def)
{
	static int s_function_ref_id=1;
	if(!lua_isfunction(L,lo)) return 0;

	s_function_ref_id++;
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING);  
	lua_rawget(L,LUA_REGISTRYINDEX);			 /* stack: fun .... mapping */
	lua_pushinteger(L,s_function_ref_id);    /* stack: fun .... mapping refid */
	lua_pushvalue(L,lo); 					 /* stack: fun .... mapping refid func */
	lua_rawset(L,-3);						 /* stack: fun .... mapping  */
	lua_pop(L,1);
	return s_function_ref_id;
}

TOLUA_API void toluaext_push_luafunction(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);			    /* stack: ... mapping refid */
	lua_rawget(L,-2);						/* stack: ... mapping func */
	lua_remove(L,-2);						/* stack: ... func */

}

TOLUA_API void toluaext_remove_luafunction(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);               /* stack: ... mapping refid */
	lua_pushnil(L);	                        /* stack: ... mapping refid nil */
	lua_rawset(L,-3);                       /* stack: ... mapping */
	lua_pop(L,1);

}


TOLUA_API int toluaext_is_luafunction(lua_State* L,int lo,const char* type,int def,tolua_Error* err)
{
	if(lua_gettop(L)>=Math::abs(lo)&&lua_isfunction(L,lo))
	{
		return 1;
	}
	err->index=lo;
	err->array=0;
	err->type="[function]";
	return 0;
}

/* lua table */
TOLUA_API int toluaext_is_luatable(lua_State* L,int lo,const char* type,int def,tolua_Error* err)
{
	if(lua_gettop(L)>=Math::abs(lo)&&lua_istable(L,lo))
	{
		return 1;
	}
	if(lua_gettop(L)>=Math::abs(lo)&&lua_isnil(L,lo))
	{
		return 1;
	}
	err->index=lo;
	err->array=0;
	err->type="[table]";
	return 0;
}

TOLUA_API int toluaext_isenum(lua_State* L,int lo,const char* type,int def,tolua_Error* err)
{
	return tolua_isnumber(L,lo,def,err);
}

TOLUA_API int toluaext_toenum(lua_State* L,int lo,int def)
{
	return (int) tolua_tonumber(L,lo,def);
}





static int _table_handle_nu=0;

TOLUA_API void toluaext_remove_luatable(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);               /* stack: ... mapping refid */
	lua_pushnil(L);	                        /* stack: ... mapping refid nil */
	lua_rawset(L,-3);                       /* stack: ... mapping */
	lua_pop(L,1);
	_table_handle_nu--;

}

TOLUA_API void toluaext_push_luatable(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);			    /* stack: ... mapping refid */
	lua_rawget(L,-2);						/* stack: ... mapping t */
	lua_remove(L,-2);						/* stack: ... t */

}

TOLUA_API int toluaext_get_luatable_nu()
{
	return _table_handle_nu;
}


TOLUA_API int toluaext_to_luatable(lua_State* L,int lo,int def)
{
	static int s_table_ref_id=1;
	if(!lua_istable(L,lo)) return -1;

	s_table_ref_id++;
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING);  
	lua_rawget(L,LUA_REGISTRYINDEX);			 /* stack: fun .... mapping */
	lua_pushinteger(L,s_table_ref_id);    /* stack: fun .... mapping refid */
	lua_pushvalue(L,lo); 					 /* stack: fun .... mapping refid func */
	lua_rawset(L,-3);						 /* stack: fun .... mapping  */
	lua_pop(L,1);
	_table_handle_nu++;
	return s_table_ref_id;
}


TOLUA_API int toluaext_fscollector(lua_State* L)
{
	FsObject* ob=(FsObject*) tolua_tousertype(L,1,0);
	ob->decRef();
	return 0;
}



static int toluaext_newmetatable (lua_State* L, const char* name)
{
	int r = luaL_newmetatable(L,name);

	#ifdef LUA_VERSION_NUM /* only lua 5.1 */
	if (r) {
		lua_pushvalue(L, -1);
		lua_pushstring(L, name);
		lua_settable(L, LUA_REGISTRYINDEX); /* reg[mt] = type_name */
	};
	#endif

	if (r)
		toluaext_classevents(L); /* set meta events */
	lua_pop(L,1);
	return r;
}


TOLUA_API void toluaext_usertype (lua_State* L, const char* type)
{
 char ctype[128] = "const ";
 strncat(ctype,type,120);

	/* create both metatables */
 if (toluaext_newmetatable(L,ctype) && toluaext_newmetatable(L,type))
	 tolua_mapsuper(L,type,ctype);             /* 'type' is also a 'const type' */
}













