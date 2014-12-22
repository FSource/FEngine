#ifndef _FS_LUA_FAERIS_H_
#define _FS_LUA_FAERIS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua_event.h"
#include "toluaext++.h"
#ifdef __cplusplus
} /* extern "C" */
#endif

#include "FsMacros.h"
#include "FsObject.h"
#include "luaext/FsCallBackExt.h"

#if defined(FS_OS_WIN32)
	#pragma warning (disable:4800)
#endif   /*FS_OS_WIN32 */
NS_FS_USE

typedef int LUA_FUNCTION;
typedef int LUA_TABLE;

TOLUA_API int  tolua_Box2D_open (lua_State* tolua_S);
TOLUA_API int  tolua_FsLibAudio_open (lua_State* tolua_S);
TOLUA_API int  tolua_FsLibFaeris_open (lua_State* tolua_S);

TOLUA_API int  tolua_FsLuaFuncExport_open(lua_State* l);
TOLUA_API int  tolua_FsLibLuaScript_open (lua_State* tolua_S);

TOLUA_API int  tolua_FsLibNetwork_open (lua_State* tolua_S);

TOLUA_API int  tolua_FsSpineSprite_open (lua_State* tolua_S);


TOLUA_API int  tolua_FsLibFaerisExt_open (lua_State* tolua_S);


#endif /*_FS_LUA_FAERIS_H_*/
