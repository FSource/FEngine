#include "toluaext_event.h"
#include "stdio.h"
static toluaext_newindex_handle s_new_index_handle=0;

void toluaext_register_newindex_failed_handle(toluaext_newindex_handle handle)
{
	s_new_index_handle=handle;
}

static int toluaext_storeatubox (lua_State* L, int lo)
{
#ifdef LUA_VERSION_NUM
	lua_getfenv(L, lo);  		/* stack: t,k,v, env */
	if (lua_rawequal(L, -1, TOLUA_NOPEER)) {
		if(s_new_index_handle)
		{
			lua_pop(L,1);
			s_new_index_handle(L,lo);
		}
		else 
		{
			return -1;
		}
	};

	lua_insert(L, -3);
	lua_settable(L, -3); /* on lua 5.1, we trade the "tolua_peers" lookup for a settable call */
	lua_pop(L, 1);
#else
	/* stack: key value (to be stored) */
	lua_pushstring(L,"tolua_peers");
	lua_rawget(L,LUA_REGISTRYINDEX);        /* stack: k v ubox */
	lua_pushvalue(L,lo);
	lua_rawget(L,-2);                       /* stack: k v ubox ubox[u] */
	if (!lua_istable(L,-1))
	{
		lua_pop(L,1);                          /* stack: k v ubox */
		lua_newtable(L);                       /* stack: k v ubox table */
		lua_pushvalue(L,1);
		lua_pushvalue(L,-2);                   /* stack: k v ubox table u table */
		lua_rawset(L,-4);                      /* stack: k v ubox ubox[u]=table */
	}
	lua_insert(L,-4);                       /* put table before k */
	lua_pop(L,1);                           /* pop ubox */
	lua_rawset(L,-3);                       /* store at table */
	lua_pop(L,1);                           /* pop ubox[u] */
#endif
	return 0;
}

static int toluaext_class_index_event (lua_State* L)
{
	int t = lua_type(L,1);
	if (t == LUA_TUSERDATA)
	{
		/* Access alternative table */
#ifdef LUA_VERSION_NUM /* new macro on version 5.1 */
		lua_getfenv(L,1);
		if (!lua_rawequal(L, -1, TOLUA_NOPEER)) {
			lua_pushvalue(L, 2); /* key */
			lua_gettable(L, -2); /* on lua 5.1, we trade the "tolua_peers" lookup for a gettable call */
			if (!lua_isnil(L, -1))
				return 1;
		};
#else
		lua_pushstring(L,"tolua_peers");
		lua_rawget(L,LUA_REGISTRYINDEX);        /* stack: obj key ubox */
		lua_pushvalue(L,1);
		lua_rawget(L,-2);                       /* stack: obj key ubox ubox[u] */
		if (lua_istable(L,-1))
		{
			lua_pushvalue(L,2);  /* key */
			lua_rawget(L,-2);                      /* stack: obj key ubox ubox[u] value */
			if (!lua_isnil(L,-1))
				return 1;
		}
#endif
		lua_settop(L,2);                        /* stack: obj key */
		/* Try metatables */
		lua_pushvalue(L,1);                     /* stack: obj key obj */
		while (lua_getmetatable(L,-1))
		{                                       /* stack: obj key obj mt */
			lua_remove(L,-2);                      /* stack: obj key mt */
			if (lua_isnumber(L,2))                 /* check if key is a numeric value */
			{
				/* try operator[] */
				lua_pushstring(L,".geti");
				lua_rawget(L,-2);                      /* stack: obj key mt func */
				if (lua_isfunction(L,-1))
				{
					lua_pushvalue(L,1);
					lua_pushvalue(L,2);
					lua_call(L,2,1);
					return 1;
				}
			}
			else
			{
				lua_pushvalue(L,2);                    /* stack: obj key mt key */
				lua_rawget(L,-2);                      /* stack: obj key mt value */
				if (!lua_isnil(L,-1))
					return 1;
				else
					lua_pop(L,1);
				/* try C/C++ variable */
				lua_pushstring(L,".get");
				lua_rawget(L,-2);                      /* stack: obj key mt tget */
				if (lua_istable(L,-1))
				{
					lua_pushvalue(L,2);
					lua_rawget(L,-2);                      /* stack: obj key mt value */
					if (lua_iscfunction(L,-1))
					{
						lua_pushvalue(L,1);
						lua_pushvalue(L,2);
						lua_call(L,2,1);
						return 1;
					}
					else if (lua_istable(L,-1))
					{
						/* deal with array: create table to be returned and cache it in ubox */
						void* u = *((void**)lua_touserdata(L,1));
						lua_newtable(L);                /* stack: obj key mt value table */
						lua_pushstring(L,".self");
						lua_pushlightuserdata(L,u);
						lua_rawset(L,-3);               /* store usertype in ".self" */
						lua_insert(L,-2);               /* stack: obj key mt table value */
						lua_setmetatable(L,-2);         /* set stored value as metatable */
						lua_pushvalue(L,-1);            /* stack: obj key met table table */
						lua_pushvalue(L,2);             /* stack: obj key mt table table key */
						lua_insert(L,-2);               /*  stack: obj key mt table key table */
						storeatubox(L,1);               /* stack: obj key mt table */
						return 1;
					}
				}
			}
			lua_settop(L,3);
		}
		lua_pushnil(L);
		return 1;
	}
	else if (t== LUA_TTABLE)
	{
		module_index_event(L);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int toluaext_class_newindex_event (lua_State* L)
{
	int t = lua_type(L,1);
	if (t == LUA_TUSERDATA)
	{
		/* Try accessing a C/C++ variable to be set */
		lua_getmetatable(L,1);
		while (lua_istable(L,-1))                /* stack: t k v mt */
		{
			if (lua_isnumber(L,2))                 /* check if key is a numeric value */
			{
				/* try operator[] */
				lua_pushstring(L,".seti");
				lua_rawget(L,-2);                      /* stack: obj key mt func */
				if (lua_isfunction(L,-1))
				{
					lua_pushvalue(L,1);
					lua_pushvalue(L,2);
					lua_pushvalue(L,3);
					lua_call(L,3,0);
					return 0;
				}
			}
			else
			{
				lua_pushstring(L,".set");
				lua_rawget(L,-2);                      /* stack: t k v mt tset */
				if (lua_istable(L,-1))
				{
					lua_pushvalue(L,2);
					lua_rawget(L,-2);                     /* stack: t k v mt tset func */
					if (lua_iscfunction(L,-1))
					{
						lua_pushvalue(L,1);
						lua_pushvalue(L,3);
						lua_call(L,2,0);
						return 0;
					}
					lua_pop(L,1);                          /* stack: t k v mt tset */
				}
				lua_pop(L,1);                           /* stack: t k v mt */
				if (!lua_getmetatable(L,-1))            /* stack: t k v mt mt */
					lua_pushnil(L);
				lua_remove(L,-2);                       /* stack: t k v mt */
			}
		}
		lua_settop(L,3);                          /* stack: t k v */

		/* then, store as a new field */
		if( toluaext_storeatubox(L,1) ==-1 )
		{
			luaL_error(L,"can't index, data filed not set");
		}
	}
	else if (t== LUA_TTABLE)
	{
		module_newindex_event(L);
	}
	return 0;
}

TOLUA_API void toluaext_classevents (lua_State* L)
{
	lua_pushstring(L,"__index");
	lua_pushcfunction(L,toluaext_class_index_event);
	lua_rawset(L,-3);
	lua_pushstring(L,"__newindex");
	lua_pushcfunction(L,toluaext_class_newindex_event);
	lua_rawset(L,-3);

	lua_pushstring(L,"__add");
	lua_pushcfunction(L,class_add_event);
	lua_rawset(L,-3);
	lua_pushstring(L,"__sub");
	lua_pushcfunction(L,class_sub_event);
	lua_rawset(L,-3);
	lua_pushstring(L,"__mul");
	lua_pushcfunction(L,class_mul_event);
	lua_rawset(L,-3);
	lua_pushstring(L,"__div");
	lua_pushcfunction(L,class_div_event);
	lua_rawset(L,-3);

	lua_pushstring(L,"__lt");
	lua_pushcfunction(L,class_lt_event);
	lua_rawset(L,-3);
	lua_pushstring(L,"__le");
	lua_pushcfunction(L,class_le_event);
	lua_rawset(L,-3);
	lua_pushstring(L,"__eq");
	lua_pushcfunction(L,class_eq_event);
	lua_rawset(L,-3);

	lua_pushstring(L,"__call");
	lua_pushcfunction(L,class_call_event);
	lua_rawset(L,-3);

	lua_pushstring(L,"__gc");
	lua_pushstring(L, "tolua_gc_event");
	lua_rawget(L, LUA_REGISTRYINDEX);
	/*lua_pushcfunction(L,class_gc_event);*/
	lua_rawset(L,-3);
}

