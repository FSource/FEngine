/*
** Lua binding: FsLibSensor
** Generated automatically by tolua++-1.0.92 on 02/20/14 06:00:51.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsLibSensor_open (lua_State* tolua_S);

#include "FsLuaExport.h"
#include "FsGpsProvider.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 toluaext_usertype(tolua_S,"FsObject");
 tolua_usertype(tolua_S,"GpsProvider");
}

/* method: create of class  GpsProvider */
#ifndef TOLUA_DISABLE_tolua_FsLibSensor_GpsProvider_create00
static int tolua_FsLibSensor_GpsProvider_create00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_FsLibSensor_GpsProvider_getLastKnownLocation00
static int tolua_FsLibSensor_GpsProvider_getLastKnownLocation00(lua_State* tolua_S)
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

/* Open function */
TOLUA_API int tolua_FsLibSensor_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"GpsProvider","GpsProvider","FsObject",NULL);
  tolua_beginmodule(tolua_S,"GpsProvider");
   tolua_function(tolua_S,"create",tolua_FsLibSensor_GpsProvider_create00);
   tolua_function(tolua_S,"getLastKnownLocation",tolua_FsLibSensor_GpsProvider_getLastKnownLocation00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsLibSensor (lua_State* tolua_S) {
 return tolua_FsLibSensor_open(tolua_S);
};
#endif

