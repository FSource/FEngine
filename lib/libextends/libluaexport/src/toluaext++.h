#ifndef _TOLUA_EXT_H_
#define _TOLUA_EXT_H_

#include "tolua++.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace Faeris
{
	class FsObject;
}

TOLUA_API void toluaext_open(lua_State* L);

/* fs object */
TOLUA_API void toluaext_fsobject(lua_State* l,const char* name);


TOLUA_API void toluaext_pushfsobject(lua_State* l,Faeris::FsObject* ob);

TOLUA_API inline void toluaext_pushfsobject2(lua_State* l,void* ob,const char* name)
{
	return toluaext_pushfsobject(l,(Faeris::FsObject*)ob);
}


/* lua function */
TOLUA_API int toluaext_is_luafunction(lua_State* L,
		int lo,
		const char* type,
		int def,
		tolua_Error* err);


TOLUA_API int toluaext_isenum(lua_State* L,int lo,const char* type,int def,tolua_Error* err);
TOLUA_API int toluaext_toenum(lua_State* L,int lo,int def);


TOLUA_API int  toluaext_to_luafunction(lua_State* L,int lo,int def);
TOLUA_API void toluaext_push_luafunction(lua_State* L,int refid);
TOLUA_API void toluaext_remove_luafunction(lua_State* L,int refid);


/* lua table */
TOLUA_API int  toluaext_is_luatable(lua_State* L,
		int lo,
		const char* type,
		int def,
		tolua_Error* err);

TOLUA_API int toluaext_new_luatable(lua_State* L);
TOLUA_API int  toluaext_to_luatable(lua_State* L,int lo,int def);
TOLUA_API void toluaext_remove_luatable(lua_State* L,int refid);
TOLUA_API void toluaext_push_luatable(lua_State* L,int refid);
TOLUA_API int toluaext_get_luatable_nu();




TOLUA_API int toluaext_fscollector(lua_State* L);


TOLUA_API void toluaext_classevents(lua_State* L);
TOLUA_API void toluaext_usertype(lua_State* L,const char* type);
TOLUA_API void toluaext_fsobject_newindex_failed_handle(lua_State* L,int lo);





#ifdef __cplusplus
}
#endif

#endif /*_TOLUA_HACK_H_*/


























