/*************************************************************************/
/*  FsLuaExport.h                                                        */
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

#include "luaext/FsObjectCallBackExt.h"
#include "luaext/FsEntityCallBackExt.h"
#include "luaext/FsLayerCallBackExt.h"
#include "luaext/FsSceneCallBackExt.h"
#include "luaext/FsActionCallBackExt.h"


#if defined(FS_OS_WIN32)
	#pragma warning (disable:4800)
#endif   /*FS_OS_WIN32 */



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
