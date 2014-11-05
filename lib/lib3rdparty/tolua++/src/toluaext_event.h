#ifndef _TOULAEXT_EVENT_H_
#define _TOULAEXT_EVENT_H_ 

#include "tolua++.h"

typedef void (*toluaext_newindex_handle)(lua_State* L,int lo);

TOLUA_API void  toluaext_register_newindex_failed_handle(toluaext_newindex_handle handle);

#endif /*_TOULAEXT_EVENT_H_*/

