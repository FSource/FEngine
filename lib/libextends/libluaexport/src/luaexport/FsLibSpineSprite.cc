/*
** Lua binding: FsSpineSprite
** Generated automatically by tolua++-1.0.92 on 08/26/14 02:55:59.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsSpineSprite_open (lua_State* tolua_S);

#include "FsLuaExport.h"
#include "FsSpineSprite.h"
#include "luaext/FsLuaEntity.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Color4f (lua_State* tolua_S)
{
 Color4f* self = (Color4f*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 toluaext_usertype(tolua_S,"SpineSprite");
 toluaext_usertype(tolua_S,"Render");
 tolua_usertype(tolua_S,"Program");
 toluaext_usertype(tolua_S,"LuaSpineSprite");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Color4f");
 tolua_usertype(tolua_S,"TextureMaterial");
 toluaext_usertype(tolua_S,"Entity");
}

/* method: setColor of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setColor00
static int tolua_FsSpineSprite___SpineSprite_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setColor01
static int tolua_FsSpineSprite___SpineSprite_setColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color4f",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  Color4f c = *((Color4f*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(c);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsSpineSprite___SpineSprite_setColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_getColor00
static int tolua_FsSpineSprite___SpineSprite_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color4f tolua_ret = (Color4f)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color4f)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color4f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color4f));
     tolua_pushusertype(tolua_S,tolua_obj,"Color4f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setOpacity00
static int tolua_FsSpineSprite___SpineSprite_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float opacity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpacity of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_getOpacity00
static int tolua_FsSpineSprite___SpineSprite_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOpacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlend of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setBlend00
static int tolua_FsSpineSprite___SpineSprite_setBlend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  int eq = ((int)  tolua_tonumber(tolua_S,2,0));
  int src = ((int)  tolua_tonumber(tolua_S,3,0));
  int dst = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlend'", NULL);
#endif
  {
   self->setBlend(eq,src,dst);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlend of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setBlend01
static int tolua_FsSpineSprite___SpineSprite_setBlend01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  int src = ((int)  tolua_tonumber(tolua_S,2,0));
  int dst = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlend'", NULL);
#endif
  {
   self->setBlend(src,dst);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsSpineSprite___SpineSprite_setBlend00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaterial of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_getMaterial00
static int tolua_FsSpineSprite___SpineSprite_getMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaterial'", NULL);
#endif
  {
   TextureMaterial* tolua_ret = (TextureMaterial*)  self->getMaterial();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TextureMaterial");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterial of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setMaterial00
static int tolua_FsSpineSprite___SpineSprite_setMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TextureMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  TextureMaterial* mat = ((TextureMaterial*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterial'", NULL);
#endif
  {
   self->setMaterial(mat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getShader of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_getShader00
static int tolua_FsSpineSprite___SpineSprite_getShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getShader'", NULL);
#endif
  {
   Program* tolua_ret = (Program*)  self->getShader();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Program");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getShader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setShader of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setShader00
static int tolua_FsSpineSprite___SpineSprite_setShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Program",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  Program* shader = ((Program*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShader'", NULL);
#endif
  {
   self->setShader(shader);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkin of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setSkin00
static int tolua_FsSpineSprite___SpineSprite_setSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* skin = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setSkin(skin);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateAnimation of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_updateAnimation00
static int tolua_FsSpineSprite___SpineSprite_updateAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateAnimation'", NULL);
#endif
  {
   self->updateAnimation(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setAnimation00
static int tolua_FsSpineSprite___SpineSprite_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* anim = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'", NULL);
#endif
  {
   self->setAnimation(anim);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playAnimation of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_playAnimation00
static int tolua_FsSpineSprite___SpineSprite_playAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,SpineSprite::ANIM_LOOP));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playAnimation'", NULL);
#endif
  {
   self->playAnimation(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startAnimation of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_startAnimation00
static int tolua_FsSpineSprite___SpineSprite_startAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,SpineSprite::ANIM_LOOP));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startAnimation'", NULL);
#endif
  {
   self->startAnimation(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopAnimation of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_stopAnimation00
static int tolua_FsSpineSprite___SpineSprite_stopAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopAnimation'", NULL);
#endif
  {
   self->stopAnimation();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAnimationPlaying of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_isAnimationPlaying00
static int tolua_FsSpineSprite___SpineSprite_isAnimationPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAnimationPlaying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAnimationPlaying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAnimationPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCurTime of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_setCurTime00
static int tolua_FsSpineSprite___SpineSprite_setCurTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCurTime'", NULL);
#endif
  {
   self->setCurTime(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCurTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurTime of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_getCurTime00
static int tolua_FsSpineSprite___SpineSprite_getCurTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getCurTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDurationTime of class  SpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite___SpineSprite_getDurationTime00
static int tolua_FsSpineSprite___SpineSprite_getDurationTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SpineSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSprite* self = (SpineSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDurationTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDurationTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDurationTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaSpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite_SpineSprite_create00
static int tolua_FsSpineSprite_SpineSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSpineSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LuaSpineSprite* tolua_ret = (LuaSpineSprite*)  LuaSpineSprite::create(filename);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaSpineSprite");
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

/* method: onDraw of class  LuaSpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite_SpineSprite_draw00
static int tolua_FsSpineSprite_SpineSprite_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSpineSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSpineSprite* self = (LuaSpineSprite*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onUpdate of class  LuaSpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite_SpineSprite_update00
static int tolua_FsSpineSprite_SpineSprite_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSpineSprite* self = (LuaSpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onUpdate'", NULL);
#endif
  {
   self->onUpdate(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchBegin of class  LuaSpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite_SpineSprite_touchBegin00
static int tolua_FsSpineSprite_SpineSprite_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSpineSprite* self = (LuaSpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchBegin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchBegin(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchMove of class  LuaSpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite_SpineSprite_touchMove00
static int tolua_FsSpineSprite_SpineSprite_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSpineSprite* self = (LuaSpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchMove'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchMove(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchEnd of class  LuaSpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite_SpineSprite_touchEnd00
static int tolua_FsSpineSprite_SpineSprite_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSpineSprite* self = (LuaSpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchEnd'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchEnd(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onHit2D of class  LuaSpineSprite */
#ifndef TOLUA_DISABLE_tolua_FsSpineSprite_SpineSprite_hit2D00
static int tolua_FsSpineSprite_SpineSprite_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSpineSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSpineSprite* self = (LuaSpineSprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onHit2D'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onHit2D(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hit2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FsSpineSprite_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"__SpineSprite","SpineSprite","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__SpineSprite");
   tolua_constant(tolua_S,"ANIM_LOOP",SpineSprite::ANIM_LOOP);
   tolua_constant(tolua_S,"ANIM_START",SpineSprite::ANIM_START);
   tolua_constant(tolua_S,"ANIM_END",SpineSprite::ANIM_END);
   tolua_function(tolua_S,"setColor",tolua_FsSpineSprite___SpineSprite_setColor00);
   tolua_function(tolua_S,"setColor",tolua_FsSpineSprite___SpineSprite_setColor01);
   tolua_function(tolua_S,"getColor",tolua_FsSpineSprite___SpineSprite_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsSpineSprite___SpineSprite_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsSpineSprite___SpineSprite_getOpacity00);
   tolua_function(tolua_S,"setBlend",tolua_FsSpineSprite___SpineSprite_setBlend00);
   tolua_function(tolua_S,"setBlend",tolua_FsSpineSprite___SpineSprite_setBlend01);
   tolua_function(tolua_S,"getMaterial",tolua_FsSpineSprite___SpineSprite_getMaterial00);
   tolua_function(tolua_S,"setMaterial",tolua_FsSpineSprite___SpineSprite_setMaterial00);
   tolua_function(tolua_S,"getShader",tolua_FsSpineSprite___SpineSprite_getShader00);
   tolua_function(tolua_S,"setShader",tolua_FsSpineSprite___SpineSprite_setShader00);
   tolua_function(tolua_S,"setSkin",tolua_FsSpineSprite___SpineSprite_setSkin00);
   tolua_function(tolua_S,"updateAnimation",tolua_FsSpineSprite___SpineSprite_updateAnimation00);
   tolua_function(tolua_S,"setAnimation",tolua_FsSpineSprite___SpineSprite_setAnimation00);
   tolua_function(tolua_S,"playAnimation",tolua_FsSpineSprite___SpineSprite_playAnimation00);
   tolua_function(tolua_S,"startAnimation",tolua_FsSpineSprite___SpineSprite_startAnimation00);
   tolua_function(tolua_S,"stopAnimation",tolua_FsSpineSprite___SpineSprite_stopAnimation00);
   tolua_function(tolua_S,"isAnimationPlaying",tolua_FsSpineSprite___SpineSprite_isAnimationPlaying00);
   tolua_function(tolua_S,"setCurTime",tolua_FsSpineSprite___SpineSprite_setCurTime00);
   tolua_function(tolua_S,"getCurTime",tolua_FsSpineSprite___SpineSprite_getCurTime00);
   tolua_function(tolua_S,"getDurationTime",tolua_FsSpineSprite___SpineSprite_getDurationTime00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SpineSprite","LuaSpineSprite","SpineSprite",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"SpineSprite");
   tolua_constant(tolua_S,"ANIM_LOOP",LuaSpineSprite::ANIM_LOOP);
   tolua_constant(tolua_S,"ANIM_START",LuaSpineSprite::ANIM_START);
   tolua_constant(tolua_S,"ANIM_END",LuaSpineSprite::ANIM_END);
   tolua_function(tolua_S,"create",tolua_FsSpineSprite_SpineSprite_create00);
   tolua_function(tolua_S,"draw",tolua_FsSpineSprite_SpineSprite_draw00);
   tolua_function(tolua_S,"update",tolua_FsSpineSprite_SpineSprite_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsSpineSprite_SpineSprite_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsSpineSprite_SpineSprite_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsSpineSprite_SpineSprite_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsSpineSprite_SpineSprite_hit2D00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsSpineSprite (lua_State* tolua_S) {
 return tolua_FsSpineSprite_open(tolua_S);
};
#endif

