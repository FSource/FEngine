/*************************************************************************/
/*  toluaext++.h                                                         */
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


























