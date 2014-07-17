/*
** Lua binding: FsLibFaerisExt
** Generated automatically by tolua++-1.0.92 on 07/17/14 17:01:23.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsLibFaerisExt_open (lua_State* tolua_S);

#include "FsLuaExport.h"
#include "FsGpsProvider.h"
#include "FsLuaExport.h"
#include "luaext/FsLuaPayment.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"GpsProvider");
 toluaext_usertype(tolua_S,"FsObject");
 tolua_usertype(tolua_S,"LuaPayment");
}

/* method: create of class  GpsProvider */
#ifndef TOLUA_DISABLE_tolua_FsLibFaerisExt_GpsProvider_create00
static int tolua_FsLibFaerisExt_GpsProvider_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GpsProvider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GpsProvider* tolua_ret = (GpsProvider*)  GpsProvider::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GpsProvider");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLastKnownLocation of class  GpsProvider */
#ifndef TOLUA_DISABLE_tolua_FsLibFaerisExt_GpsProvider_getLastKnownLocation00
static int tolua_FsLibFaerisExt_GpsProvider_getLastKnownLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GpsProvider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GpsProvider* self = (GpsProvider*)  tolua_tousertype(tolua_S,1,0);
  float latitude = ((float)  tolua_tonumber(tolua_S,2,0));
  float longitude = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLastKnownLocation'", NULL);
#endif
  {
   self->getLastKnownLocation(&latitude,&longitude);
   tolua_pushnumber(tolua_S,(lua_Number)latitude);
   tolua_pushnumber(tolua_S,(lua_Number)longitude);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLastKnownLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  LuaPayment */
#ifndef TOLUA_DISABLE_tolua_FsLibFaerisExt_Payment_getInstance00
static int tolua_FsLibFaerisExt_Payment_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaPayment",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaPayment* tolua_ret = (LuaPayment*)  LuaPayment::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaPayment");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: purgeInstance of class  LuaPayment */
#ifndef TOLUA_DISABLE_tolua_FsLibFaerisExt_Payment_purgeInstance00
static int tolua_FsLibFaerisExt_Payment_purgeInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaPayment",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaPayment::purgeInstance();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'purgeInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  LuaPayment */
#ifndef TOLUA_DISABLE_tolua_FsLibFaerisExt_Payment_init00
static int tolua_FsLibFaerisExt_Payment_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPayment",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPayment* self = (LuaPayment*)  tolua_tousertype(tolua_S,1,0);
  const char* msg = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   self->init(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setConfig of class  LuaPayment */
#ifndef TOLUA_DISABLE_tolua_FsLibFaerisExt_Payment_setConfig00
static int tolua_FsLibFaerisExt_Payment_setConfig00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPayment",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPayment* self = (LuaPayment*)  tolua_tousertype(tolua_S,1,0);
  const char* config = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setConfig'", NULL);
#endif
  {
   self->setConfig(config);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setConfig'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: billing of class  LuaPayment */
#ifndef TOLUA_DISABLE_tolua_FsLibFaerisExt_Payment_billing00
static int tolua_FsLibFaerisExt_Payment_billing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPayment",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPayment* self = (LuaPayment*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* msg = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'billing'", NULL);
#endif
  {
   int tolua_ret = (int)  self->billing(name,msg);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'billing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FsLibFaerisExt_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"GpsProvider","GpsProvider","FsObject",NULL);
  tolua_beginmodule(tolua_S,"GpsProvider");
   tolua_function(tolua_S,"create",tolua_FsLibFaerisExt_GpsProvider_create00);
   tolua_function(tolua_S,"getLastKnownLocation",tolua_FsLibFaerisExt_GpsProvider_getLastKnownLocation00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"FS_PAYMENT_SUCCESS",FS_PAYMENT_SUCCESS);
  tolua_constant(tolua_S,"FS_PAYMENT_CANCEL",FS_PAYMENT_CANCEL);
  tolua_constant(tolua_S,"FS_PAYMENT_FAILED",FS_PAYMENT_FAILED);
  tolua_constant(tolua_S,"FS_PAYMENT_ERROR",FS_PAYMENT_ERROR);
  tolua_cclass(tolua_S,"Payment","LuaPayment","FsObject",NULL);
  tolua_beginmodule(tolua_S,"Payment");
   tolua_function(tolua_S,"getInstance",tolua_FsLibFaerisExt_Payment_getInstance00);
   tolua_function(tolua_S,"purgeInstance",tolua_FsLibFaerisExt_Payment_purgeInstance00);
   tolua_function(tolua_S,"init",tolua_FsLibFaerisExt_Payment_init00);
   tolua_function(tolua_S,"setConfig",tolua_FsLibFaerisExt_Payment_setConfig00);
   tolua_function(tolua_S,"billing",tolua_FsLibFaerisExt_Payment_billing00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsLibFaerisExt (lua_State* tolua_S) {
 return tolua_FsLibFaerisExt_open(tolua_S);
};
#endif

