/*
** Lua binding: FsLibPay
** Generated automatically by tolua++-1.0.92 on 11/13/13 19:49:04.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsLibPay_open (lua_State* tolua_S);

#include "FsTest.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Test (lua_State* tolua_S)
{
 Test* self = (Test*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Test");
}

/* method: new of class  Test */
#ifndef TOLUA_DISABLE_tolua_FsLibPay_Test_new00
static int tolua_FsLibPay_Test_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Test",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Test* tolua_ret = (Test*)  Mtolua_new((Test)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Test");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Test */
#ifndef TOLUA_DISABLE_tolua_FsLibPay_Test_new00_local
static int tolua_FsLibPay_Test_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Test",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Test* tolua_ret = (Test*)  Mtolua_new((Test)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Test");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: printSelf of class  Test */
#ifndef TOLUA_DISABLE_tolua_FsLibPay_Test_printSelf00
static int tolua_FsLibPay_Test_printSelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Test",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Test* self = (Test*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'printSelf'", NULL);
#endif
  {
   self->printSelf();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'printSelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FsLibPay_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Test","Test","",tolua_collect_Test);
  #else
  tolua_cclass(tolua_S,"Test","Test","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Test");
   tolua_function(tolua_S,"new",tolua_FsLibPay_Test_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibPay_Test_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibPay_Test_new00_local);
   tolua_function(tolua_S,"printSelf",tolua_FsLibPay_Test_printSelf00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsLibPay (lua_State* tolua_S) {
 return tolua_FsLibPay_open(tolua_S);
};
#endif

