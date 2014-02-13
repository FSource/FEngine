/*
** Lua binding: FsLibFaeris
** Generated automatically by tolua++-1.0.92 on 02/13/14 08:14:29.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsLibFaeris_open (lua_State* tolua_S);

#include "FsLuaExport.h"
#include "FsGlobal.h"
#include "FsObject.h"
#include "FsMacros.h"
#include "stage/FsActionTarget.h"
#include "stage/entity/FsEntity.h"
#include "luaext/FsLuaEntity.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsQuad2D.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsLabelTTF.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsSprite2D.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsLabelBitmap.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsParticle2DEmitter.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsParticle2DEffect.h"
#include "stage/entity/FsVertexPolygon.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsPanel.h"
#include "luaext/FsLuaEntity.h"
#include "stage/entity/FsButton.h"
#include "luaext/FsLuaEntity.h"
#include "mgr/FsResource.h"
#include "mgr/FsTextureMgr.h"
#include "mgr/FsSprite2DDataMgr.h"
#include "mgr/FsResourceMgr.h"
#include "mgr/FsObjectMgr.h"
#include "scheduler/FsScheduler.h"
#include "luaext/FsLuaSchedulerTarget.h"
#include "luaext/FsLuaScene.h"
#include "stage/FsDirector.h"
#include "stage/layer/FsLayer.h"
#include "luaext/FsLuaLayer.h"
#include "stage/layer/FsLayer2D.h"
#include "graphics/FsRender.h"
#include "graphics/FsColor.h"
#include "graphics/FsFontTTF.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsFontBitmap.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsMatrix4.h"
#include "math/FsRect2D.h"
#include "sys/FsWindow.h"
#include "sys/FsKeyCode.h"
#include "sys/FsSys.h"
#include "sys/FsTimer.h"
#include "luaext/FsLuaTouchEventListener.h"
#include "luaext/FsLuaSysEventListener.h"
#include "sys/event/FsTouchDispatcher.h"
#include "sys/event/FsSysDispatcher.h"
#include "sys/event/FsKeypadDispatcher.h"
#include "stage/action/FsAction.h"
#include "luaext/FsLuaAction.h"
#include "stage/action/FsMoveByAction.h"
#include "stage/action/FsMoveToAction.h"
#include "stage/action/FsPauseAction.h"
#include "stage/action/FsRotateZByAction.h"
#include "stage/action/FsRotateZToAction.h"
#include "stage/action/FsScaleByAction.h"
#include "stage/action/FsScaleToAction.h"
#include "stage/action/FsSeqAction.h"
#include "media/FsAudioEngine.h"
#include "FsLuaExport.h"
#include "FsLuaExport.h"
#include "sys/network/FsHttpEngine.h"
#include "luaext/FsLuaHttpRequest.h"
#include "sys/network/FsHttpReponse.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Timer (lua_State* tolua_S)
{
 Timer* self = (Timer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Rect2D (lua_State* tolua_S)
{
 Rect2D* self = (Rect2D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Matrix4 (lua_State* tolua_S)
{
 Matrix4* self = (Matrix4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 toluaext_usertype(tolua_S,"TouchEventListener");
 tolua_usertype(tolua_S,"Sprite2DDataMgr");
 toluaext_usertype(tolua_S,"FontTTF");
 tolua_usertype(tolua_S,"TouchEvent");
 toluaext_usertype(tolua_S,"Director");
 toluaext_usertype(tolua_S,"AudioEngine");
 toluaext_usertype(tolua_S,"Layer");
 toluaext_usertype(tolua_S,"Texture2D");
 tolua_usertype(tolua_S,"ObjectMgr");
 toluaext_usertype(tolua_S,"ColorLayer");
 toluaext_usertype(tolua_S,"RotateZByAction");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"ActionTarget");
 toluaext_usertype(tolua_S,"LuaParticle2DEffect");
 toluaext_usertype(tolua_S,"LuaLabelTTF");
 toluaext_usertype(tolua_S,"Button");
 toluaext_usertype(tolua_S,"FsArray");
 toluaext_usertype(tolua_S,"FontBitmap");
 toluaext_usertype(tolua_S,"LuaAction");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Timer");
 toluaext_usertype(tolua_S,"LuaQuad2D");
 toluaext_usertype(tolua_S,"TextureMgr");
 toluaext_usertype(tolua_S,"LuaTouchEventListener");
 toluaext_usertype(tolua_S,"LuaHttpRequest");
 tolua_usertype(tolua_S,"LuaSchedulerTarget");
 toluaext_usertype(tolua_S,"Scheduler");
 toluaext_usertype(tolua_S,"SysDispatcher");
 tolua_usertype(tolua_S,"Rect2D");
 toluaext_usertype(tolua_S,"MoveToAction");
 tolua_usertype(tolua_S,"Channel");
 tolua_usertype(tolua_S,"Vector3");
 toluaext_usertype(tolua_S,"SchedulerTarget");
 toluaext_usertype(tolua_S,"ScaleToAction");
 toluaext_usertype(tolua_S,"Scene");
 toluaext_usertype(tolua_S,"HttpEngine");
 tolua_usertype(tolua_S,"Particle2DEmitter");
 toluaext_usertype(tolua_S,"ScaleByAction");
 tolua_usertype(tolua_S,"FsFile");
 tolua_usertype(tolua_S,"LuaVertexPolygon");
 toluaext_usertype(tolua_S,"RotateZToAction");
 toluaext_usertype(tolua_S,"Sprite2D");
 
 toluaext_usertype(tolua_S,"LuaPanel");
 toluaext_usertype(tolua_S,"MoveByAction");
 toluaext_usertype(tolua_S,"LuaColorLayer");
 tolua_usertype(tolua_S,"Matrix4");
 toluaext_usertype(tolua_S,"Action");
 toluaext_usertype(tolua_S,"Render");
 tolua_usertype(tolua_S,"KeypadEvent");
 toluaext_usertype(tolua_S,"LuaButton");
 toluaext_usertype(tolua_S,"Quad2D");
 toluaext_usertype(tolua_S,"LabelTTF");
 toluaext_usertype(tolua_S,"LuaLabelBitmap");
 toluaext_usertype(tolua_S,"TouchDispatcher");
 toluaext_usertype(tolua_S,"SeqAction");
 toluaext_usertype(tolua_S,"Layer2D");
 toluaext_usertype(tolua_S,"LuaLayer2D");
 toluaext_usertype(tolua_S,"FsObject");
 tolua_usertype(tolua_S,"TouchPoint");
 toluaext_usertype(tolua_S,"ResourceMgr");
 toluaext_usertype(tolua_S,"LuaScene");
 toluaext_usertype(tolua_S,"LuaSysEventListener");
 tolua_usertype(tolua_S,"Sys");
 toluaext_usertype(tolua_S,"PauseAction");
 toluaext_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"Global");
 toluaext_usertype(tolua_S,"Panel");
 toluaext_usertype(tolua_S,"Window");
 toluaext_usertype(tolua_S,"LuaEntity");
 tolua_usertype(tolua_S,"Vector4");
 toluaext_usertype(tolua_S,"LuaColorQuad2D");
 toluaext_usertype(tolua_S,"LuaSprite2D");
 tolua_usertype(tolua_S,"ButtonState");
 toluaext_usertype(tolua_S,"SysEventListener");
 toluaext_usertype(tolua_S,"Resource");
 toluaext_usertype(tolua_S,"Particle2DEffect");
 tolua_usertype(tolua_S,"VertexPolygon");
 toluaext_usertype(tolua_S,"LabelBitmap");
 toluaext_usertype(tolua_S,"ColorQuad2D");
}

/* method: scheduler of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_scheduler00
static int tolua_FsLibFaeris_share_scheduler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scheduler* tolua_ret = (Scheduler*)  Global::scheduler();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Scheduler");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scheduler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchDispatcher of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_touchDispatcher00
static int tolua_FsLibFaeris_share_touchDispatcher00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TouchDispatcher* tolua_ret = (TouchDispatcher*)  Global::touchDispatcher();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"TouchDispatcher");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchDispatcher'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: director of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_director00
static int tolua_FsLibFaeris_share_director00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Director* tolua_ret = (Director*)  Global::director();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Director");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'director'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sysDispatcher of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_sysDispatcher00
static int tolua_FsLibFaeris_share_sysDispatcher00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SysDispatcher* tolua_ret = (SysDispatcher*)  Global::sysDispatcher();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"SysDispatcher");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sysDispatcher'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: window of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_window00
static int tolua_FsLibFaeris_share_window00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Window* tolua_ret = (Window*)  Global::window();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Window");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'window'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: render of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_render00
static int tolua_FsLibFaeris_share_render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Render* tolua_ret = (Render*)  Global::render();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Render");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: textureMgr of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_textureMgr00
static int tolua_FsLibFaeris_share_textureMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TextureMgr* tolua_ret = (TextureMgr*)  Global::textureMgr();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"TextureMgr");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'textureMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sprite2DDataMgr of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_sprite2DDataMgr00
static int tolua_FsLibFaeris_share_sprite2DDataMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Sprite2DDataMgr* tolua_ret = (Sprite2DDataMgr*)  Global::sprite2DDataMgr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite2DDataMgr");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sprite2DDataMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: objectMgr of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_share_objectMgr00
static int tolua_FsLibFaeris_share_objectMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ObjectMgr* tolua_ret = (ObjectMgr*)  Global::objectMgr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ObjectMgr");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'objectMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObjectNu of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_getObjectNu00
static int tolua_FsLibFaeris_FsObject_getObjectNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  FsObject::getObjectNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObjectNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: refCnt of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_refCnt00
static int tolua_FsLibFaeris_FsObject_refCnt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'refCnt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->refCnt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'refCnt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addRef of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_addRef00
static int tolua_FsLibFaeris_FsObject_addRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addRef'", NULL);
#endif
  {
   self->addRef();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decRef of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_decRef00
static int tolua_FsLibFaeris_FsObject_decRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'decRef'", NULL);
#endif
  {
   self->decRef();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRefDelete of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_setRefDelete00
static int tolua_FsLibFaeris_FsObject_setRefDelete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRefDelete'", NULL);
#endif
  {
   self->setRefDelete(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRefDelete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRefDelete of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_getRefDelete00
static int tolua_FsLibFaeris_FsObject_getRefDelete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRefDelete'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getRefDelete();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRefDelete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_destroy00
static int tolua_FsLibFaeris_FsObject_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'", NULL);
#endif
  {
   self->destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: autoDestroy of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_autoDestroy00
static int tolua_FsLibFaeris_FsObject_autoDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'autoDestroy'", NULL);
#endif
  {
   self->autoDestroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'autoDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: className of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FsObject_className00
static int tolua_FsLibFaeris_FsObject_className00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'className'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->className();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'className'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_scriptData of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_get_FsObject_data
static int tolua_get_FsObject_data(lua_State* tolua_S)
{
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_scriptData'",NULL);
#endif
   toluaext_push_luatable(tolua_S,self->m_scriptData);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_scriptData of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_set_FsObject_data
static int tolua_set_FsObject_data(lua_State* tolua_S)
{
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_scriptData'",NULL);
   if((!toluaext_is_luatable(tolua_S,2,"LUA_TABLE",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  if(self->m_scriptData!=-1) 
	{
		toluaext_remove_luatable(tolua_S,self->m_scriptData); 
	}
	self->m_scriptData=toluaext_to_luatable(tolua_S,2,0);
	if(self->m_scriptData==-1)
	{
		lua_pushvalue(tolua_S,TOLUA_NOPEER);
		lua_setfenv(tolua_S,1);
	}
	else 
	{
		toluaext_push_luatable(tolua_S,self->m_scriptData);
		lua_setfenv(tolua_S,1);
	}
	
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: doAction of class  ActionTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ActionTarget_doAction00
static int tolua_FsLibFaeris_ActionTarget_doAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActionTarget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Action",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActionTarget* self = (ActionTarget*)  tolua_tousertype(tolua_S,1,0);
  Action* action = ((Action*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doAction'", NULL);
#endif
  {
   self->doAction(action);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAction of class  ActionTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ActionTarget_removeAction00
static int tolua_FsLibFaeris_ActionTarget_removeAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActionTarget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Action",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActionTarget* self = (ActionTarget*)  tolua_tousertype(tolua_S,1,0);
  Action* action = ((Action*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAction'", NULL);
#endif
  {
   self->removeAction(action);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearAction of class  ActionTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ActionTarget_clearAction00
static int tolua_FsLibFaeris_ActionTarget_clearAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActionTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActionTarget* self = (ActionTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearAction'", NULL);
#endif
  {
   self->clearAction();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopAction of class  ActionTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ActionTarget_stopAction00
static int tolua_FsLibFaeris_ActionTarget_stopAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActionTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActionTarget* self = (ActionTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopAction'", NULL);
#endif
  {
   self->stopAction();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isActionStop of class  ActionTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ActionTarget_isActionStop00
static int tolua_FsLibFaeris_ActionTarget_isActionStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActionTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActionTarget* self = (ActionTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isActionStop'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isActionStop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isActionStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resumeAction of class  ActionTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ActionTarget_resumeAction00
static int tolua_FsLibFaeris_ActionTarget_resumeAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActionTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActionTarget* self = (ActionTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resumeAction'", NULL);
#endif
  {
   self->resumeAction();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resumeAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateAction of class  ActionTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ActionTarget_updateAction00
static int tolua_FsLibFaeris_ActionTarget_updateAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActionTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActionTarget* self = (ActionTarget*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateAction'", NULL);
#endif
  {
   self->updateAction(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: localToWorld of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_localToWorld00
static int tolua_FsLibFaeris___Entity_localToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'localToWorld'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->localToWorld(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'localToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: worldToLocal of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_worldToLocal00
static int tolua_FsLibFaeris___Entity_worldToLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'worldToLocal'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->worldToLocal(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'worldToLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChild of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_addChild00
static int tolua_FsLibFaeris___Entity_addChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Entity* n = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChild'", NULL);
#endif
  {
   self->addChild(n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParent of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getParent00
static int tolua_FsLibFaeris___Entity_getParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParent'", NULL);
#endif
  {
   Entity* tolua_ret = (Entity*)  self->getParent();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_remove00
static int tolua_FsLibFaeris___Entity_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Entity* n = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detach of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_detach00
static int tolua_FsLibFaeris___Entity_detach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detach'", NULL);
#endif
  {
   self->detach();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detach'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearChild of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_clearChild00
static int tolua_FsLibFaeris___Entity_clearChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearChild'", NULL);
#endif
  {
   self->clearChild();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: takeAllChild of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_takeAllChild00
static int tolua_FsLibFaeris___Entity_takeAllChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'takeAllChild'", NULL);
#endif
  {
   FsArray* tolua_ret = (FsArray*)  self->takeAllChild();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FsArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'takeAllChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: childNu of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_childNu00
static int tolua_FsLibFaeris___Entity_childNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'childNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->childNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'childNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLayer of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getLayer00
static int tolua_FsLibFaeris___Entity_getLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayer'", NULL);
#endif
  {
   Layer* tolua_ret = (Layer*)  self->getLayer();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Layer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLocalMatrix of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getLocalMatrix00
static int tolua_FsLibFaeris___Entity_getLocalMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLocalMatrix'", NULL);
#endif
  {
   Matrix4* tolua_ret = (Matrix4*)  self->getLocalMatrix();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLocalMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWorldMatrix of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getWorldMatrix00
static int tolua_FsLibFaeris___Entity_getWorldMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWorldMatrix'", NULL);
#endif
  {
   Matrix4* tolua_ret = (Matrix4*)  self->getWorldMatrix();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWorldMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateLocalMatrix of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_updateLocalMatrix00
static int tolua_FsLibFaeris___Entity_updateLocalMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateLocalMatrix'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->updateLocalMatrix();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateLocalMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateWorldMatrix of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_updateWorldMatrix00
static int tolua_FsLibFaeris___Entity_updateWorldMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateWorldMatrix'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->updateWorldMatrix();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateWorldMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateAllWorldMatrix of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_updateAllWorldMatrix00
static int tolua_FsLibFaeris___Entity_updateAllWorldMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateAllWorldMatrix'", NULL);
#endif
  {
   self->updateAllWorldMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateAllWorldMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getPosition00
static int tolua_FsLibFaeris___Entity_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getPosition01
static int tolua_FsLibFaeris___Entity_getPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   self->getPosition(&x,&y,&z);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
   tolua_pushnumber(tolua_S,(lua_Number)z);
  }
 }
 return 3;
tolua_lerror:
 return tolua_FsLibFaeris___Entity_getPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getPositionX00
static int tolua_FsLibFaeris___Entity_getPositionX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPositionX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPositionX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getPositionY00
static int tolua_FsLibFaeris___Entity_getPositionY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPositionY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPositionY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getPositionZ00
static int tolua_FsLibFaeris___Entity_getPositionZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionZ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPositionZ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPositionZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getScale00
static int tolua_FsLibFaeris___Entity_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getScale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaleX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getScaleX00
static int tolua_FsLibFaeris___Entity_getScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaleX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getScaleX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaleY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getScaleY00
static int tolua_FsLibFaeris___Entity_getScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaleY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getScaleY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaleZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getScaleZ00
static int tolua_FsLibFaeris___Entity_getScaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaleZ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getScaleZ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaleZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotate of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getRotate00
static int tolua_FsLibFaeris___Entity_getRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotate'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getRotate();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotateX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getRotateX00
static int tolua_FsLibFaeris___Entity_getRotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotateX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRotateX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotateY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getRotateY00
static int tolua_FsLibFaeris___Entity_getRotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotateY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRotateY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotateZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getRotateZ00
static int tolua_FsLibFaeris___Entity_getRotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotateZ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRotateZ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_rotate00
static int tolua_FsLibFaeris___Entity_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(rx,ry,rz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_rotateX00
static int tolua_FsLibFaeris___Entity_rotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateX'", NULL);
#endif
  {
   self->rotateX(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_rotateY00
static int tolua_FsLibFaeris___Entity_rotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateY'", NULL);
#endif
  {
   self->rotateY(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_rotateZ00
static int tolua_FsLibFaeris___Entity_rotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateZ'", NULL);
#endif
  {
   self->rotateZ(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_scale00
static int tolua_FsLibFaeris___Entity_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(sx,sy,sz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_scaleX00
static int tolua_FsLibFaeris___Entity_scaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleX'", NULL);
#endif
  {
   self->scaleX(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_scaleY00
static int tolua_FsLibFaeris___Entity_scaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleY'", NULL);
#endif
  {
   self->scaleY(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_scaleZ00
static int tolua_FsLibFaeris___Entity_scaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleZ'", NULL);
#endif
  {
   self->scaleZ(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_move00
static int tolua_FsLibFaeris___Entity_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float tx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ty = ((float)  tolua_tonumber(tolua_S,3,0));
  float tz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'", NULL);
#endif
  {
   self->move(tx,ty,tz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_moveX00
static int tolua_FsLibFaeris___Entity_moveX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveX'", NULL);
#endif
  {
   self->moveX(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_moveY00
static int tolua_FsLibFaeris___Entity_moveY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveY'", NULL);
#endif
  {
   self->moveY(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_moveZ00
static int tolua_FsLibFaeris___Entity_moveZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveZ'", NULL);
#endif
  {
   self->moveZ(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotate of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setRotate00
static int tolua_FsLibFaeris___Entity_setRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotate'", NULL);
#endif
  {
   self->setRotate(rx,ry,rz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setRotateX00
static int tolua_FsLibFaeris___Entity_setRotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateX'", NULL);
#endif
  {
   self->setRotateX(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setRotateY00
static int tolua_FsLibFaeris___Entity_setRotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateY'", NULL);
#endif
  {
   self->setRotateY(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setRotateZ00
static int tolua_FsLibFaeris___Entity_setRotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateZ'", NULL);
#endif
  {
   self->setRotateZ(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setScale00
static int tolua_FsLibFaeris___Entity_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(sx,sy,sz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setScaleX00
static int tolua_FsLibFaeris___Entity_setScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleX'", NULL);
#endif
  {
   self->setScaleX(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setScaleY00
static int tolua_FsLibFaeris___Entity_setScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleY'", NULL);
#endif
  {
   self->setScaleY(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setScaleZ00
static int tolua_FsLibFaeris___Entity_setScaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleZ'", NULL);
#endif
  {
   self->setScaleZ(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setPosition00
static int tolua_FsLibFaeris___Entity_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float tx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ty = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(tx,ty,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setPositionX00
static int tolua_FsLibFaeris___Entity_setPositionX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionX'", NULL);
#endif
  {
   self->setPositionX(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setPositionY00
static int tolua_FsLibFaeris___Entity_setPositionY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionY'", NULL);
#endif
  {
   self->setPositionY(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setPositionZ00
static int tolua_FsLibFaeris___Entity_setPositionZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionZ'", NULL);
#endif
  {
   self->setPositionZ(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionInWorld of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getPositionInWorld00
static int tolua_FsLibFaeris___Entity_getPositionInWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionInWorld'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getPositionInWorld();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPositionInWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionInWorld of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getPositionInWorld01
static int tolua_FsLibFaeris___Entity_getPositionInWorld01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionInWorld'", NULL);
#endif
  {
   self->getPositionInWorld(&x,&y,&z);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
   tolua_pushnumber(tolua_S,(lua_Number)z);
  }
 }
 return 3;
tolua_lerror:
 return tolua_FsLibFaeris___Entity_getPositionInWorld00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getZorder of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getZorder00
static int tolua_FsLibFaeris___Entity_getZorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getZorder'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getZorder();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getZorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZorder of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setZorder00
static int tolua_FsLibFaeris___Entity_setZorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float z = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZorder'", NULL);
#endif
  {
   self->setZorder(z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setVisible00
static int tolua_FsLibFaeris___Entity_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setChildVisible of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setChildVisible00
static int tolua_FsLibFaeris___Entity_setChildVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool visiable = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool rec = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setChildVisible'", NULL);
#endif
  {
   self->setChildVisible(visiable,rec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setChildVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVisible of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_visible00
static int tolua_FsLibFaeris___Entity_visible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVisible of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getVisible00
static int tolua_FsLibFaeris___Entity_getVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisibles of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setVisibles00
static int tolua_FsLibFaeris___Entity_setVisibles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisibles'", NULL);
#endif
  {
   self->setVisibles(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisibles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVisibles of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getVisibles00
static int tolua_FsLibFaeris___Entity_getVisibles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVisibles'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getVisibles();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVisibles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDispatchTouchEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setDispatchTouchEnabled00
static int tolua_FsLibFaeris___Entity_setDispatchTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDispatchTouchEnabled'", NULL);
#endif
  {
   self->setDispatchTouchEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDispatchTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDispatchTouchEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getDispatchTouchEnabled00
static int tolua_FsLibFaeris___Entity_getDispatchTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDispatchTouchEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getDispatchTouchEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDispatchTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDispatchTouchesEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setDispatchTouchesEnabled00
static int tolua_FsLibFaeris___Entity_setDispatchTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDispatchTouchesEnabled'", NULL);
#endif
  {
   self->setDispatchTouchesEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDispatchTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDispatchTouchesEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getDispatchTouchesEnabled00
static int tolua_FsLibFaeris___Entity_getDispatchTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDispatchTouchesEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getDispatchTouchesEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDispatchTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hit2D of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_hit2D00
static int tolua_FsLibFaeris___Entity_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hit2D'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hit2D(x,y);
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

/* method: draw of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_draw00
static int tolua_FsLibFaeris___Entity_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
  bool update_matrix = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(render,update_matrix);
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

/* method: draws of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_draws00
static int tolua_FsLibFaeris___Entity_draws00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
  bool update_matrix = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draws'", NULL);
#endif
  {
   self->draws(render,update_matrix);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draws'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_update00
static int tolua_FsLibFaeris___Entity_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(dt);
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

/* method: updates of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_updates00
static int tolua_FsLibFaeris___Entity_updates00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updates'", NULL);
#endif
  {
   self->updates(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updates'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setTouchEnabled00
static int tolua_FsLibFaeris___Entity_setTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchEnabled'", NULL);
#endif
  {
   self->setTouchEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTouchEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getTouchEnabled00
static int tolua_FsLibFaeris___Entity_getTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTouchEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getTouchEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchBegin of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_touchBegin00
static int tolua_FsLibFaeris___Entity_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchBegin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchBegin(x,y);
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

/* method: touchMove of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_touchMove00
static int tolua_FsLibFaeris___Entity_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchMove'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchMove(x,y);
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

/* method: touchEnd of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_touchEnd00
static int tolua_FsLibFaeris___Entity_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchEnd'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchEnd(x,y);
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

/* method: setTouchesEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_setTouchesEnabled00
static int tolua_FsLibFaeris___Entity_setTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchesEnabled'", NULL);
#endif
  {
   self->setTouchesEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTouchesEnabled of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Entity_getTouchesEnabled00
static int tolua_FsLibFaeris___Entity_getTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTouchesEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getTouchesEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Entity_create00
static int tolua_FsLibFaeris_Entity_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaEntity* tolua_ret = (LuaEntity*)  LuaEntity::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaEntity");
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

/* method: onUpdate of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Entity_update00
static int tolua_FsLibFaeris_Entity_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onDraw of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Entity_draw00
static int tolua_FsLibFaeris_Entity_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Entity_touchBegin00
static int tolua_FsLibFaeris_Entity_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Entity_touchMove00
static int tolua_FsLibFaeris_Entity_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Entity_touchEnd00
static int tolua_FsLibFaeris_Entity_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Entity_hit2D00
static int tolua_FsLibFaeris_Entity_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setColor of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_setColor00
static int tolua_FsLibFaeris___ColorQuad2D_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
  int vertex = ((int)  tolua_tonumber(tolua_S,3,ColorQuad2D::VERTEX_ALL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(c,vertex);
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

/* method: setRect2D of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_setRect2D00
static int tolua_FsLibFaeris___ColorQuad2D_setRect2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* rect = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRect2D'", NULL);
#endif
  {
   self->setRect2D(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRect2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRect2D of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_getRect2D00
static int tolua_FsLibFaeris___ColorQuad2D_getRect2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRect2D'", NULL);
#endif
  {
   Rect2D tolua_ret = (Rect2D)  self->getRect2D();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Rect2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect2D));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRect2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_setOpacity00
static int tolua_FsLibFaeris___ColorQuad2D_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_getOpacity00
static int tolua_FsLibFaeris___ColorQuad2D_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAnchor of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_setAnchor00
static int tolua_FsLibFaeris___ColorQuad2D_setAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchor'", NULL);
#endif
  {
   self->setAnchor(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchor of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_getAnchor00
static int tolua_FsLibFaeris___ColorQuad2D_getAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchor'", NULL);
#endif
  {
   self->getAnchor(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_setSize00
static int tolua_FsLibFaeris___ColorQuad2D_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   self->setSize(w,h);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  ColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorQuad2D_getSize00
static int tolua_FsLibFaeris___ColorQuad2D_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorQuad2D* self = (ColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'", NULL);
#endif
  {
   self->getSize(&w,&h);
   tolua_pushnumber(tolua_S,(lua_Number)w);
   tolua_pushnumber(tolua_S,(lua_Number)h);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_create00
static int tolua_FsLibFaeris_ColorQuad2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaColorQuad2D* tolua_ret = (LuaColorQuad2D*)  LuaColorQuad2D::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorQuad2D");
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

/* method: create of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_create01
static int tolua_FsLibFaeris_ColorQuad2D_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Rect2D* rect = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
  Color c = *((Color*)  tolua_tousertype(tolua_S,3,0));
  {
   LuaColorQuad2D* tolua_ret = (LuaColorQuad2D*)  LuaColorQuad2D::create(*rect,c);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorQuad2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_ColorQuad2D_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_create02
static int tolua_FsLibFaeris_ColorQuad2D_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  Color c = *((Color*)  tolua_tousertype(tolua_S,4,0));
  {
   LuaColorQuad2D* tolua_ret = (LuaColorQuad2D*)  LuaColorQuad2D::create(width,height,c);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorQuad2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_ColorQuad2D_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_draw00
static int tolua_FsLibFaeris_ColorQuad2D_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_update00
static int tolua_FsLibFaeris_ColorQuad2D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_touchBegin00
static int tolua_FsLibFaeris_ColorQuad2D_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_touchMove00
static int tolua_FsLibFaeris_ColorQuad2D_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_touchEnd00
static int tolua_FsLibFaeris_ColorQuad2D_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorQuad2D_hit2D00
static int tolua_FsLibFaeris_ColorQuad2D_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setColor of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setColor00
static int tolua_FsLibFaeris___Quad2D_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getColor of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getColor00
static int tolua_FsLibFaeris___Quad2D_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
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

/* method: setOpacity of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setOpacity00
static int tolua_FsLibFaeris___Quad2D_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getOpacity00
static int tolua_FsLibFaeris___Quad2D_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setTexture of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setTexture00
static int tolua_FsLibFaeris___Quad2D_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  const char* tex = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setTexture01
static int tolua_FsLibFaeris___Quad2D_setTexture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  Texture2D* tex = ((Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___Quad2D_setTexture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getTexture00
static int tolua_FsLibFaeris___Quad2D_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   Texture2D* tolua_ret = (Texture2D*)  self->getTexture();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTextureCoord of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setTextureCoord00
static int tolua_FsLibFaeris___Quad2D_setTextureCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* coord = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTextureCoord'", NULL);
#endif
  {
   self->setTextureCoord(*coord);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTextureCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureCoord of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getTextureCoord00
static int tolua_FsLibFaeris___Quad2D_getTextureCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureCoord'", NULL);
#endif
  {
   Rect2D tolua_ret = (Rect2D)  self->getTextureCoord();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Rect2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect2D));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRect2D of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setRect2D00
static int tolua_FsLibFaeris___Quad2D_setRect2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* rect = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRect2D'", NULL);
#endif
  {
   self->setRect2D(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRect2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRect2D of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getRect2D00
static int tolua_FsLibFaeris___Quad2D_getRect2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRect2D'", NULL);
#endif
  {
   Rect2D tolua_ret = (Rect2D)  self->getRect2D();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Rect2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect2D));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRect2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWidth of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setWidth00
static int tolua_FsLibFaeris___Quad2D_setWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWidth'", NULL);
#endif
  {
   self->setWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHeight of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setHeight00
static int tolua_FsLibFaeris___Quad2D_setHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHeight'", NULL);
#endif
  {
   self->setHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setSize00
static int tolua_FsLibFaeris___Quad2D_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   self->setSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getWidth00
static int tolua_FsLibFaeris___Quad2D_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getHeight00
static int tolua_FsLibFaeris___Quad2D_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getSize00
static int tolua_FsLibFaeris___Quad2D_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'", NULL);
#endif
  {
   self->getSize(&width,&height);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnchorX of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setAnchorX00
static int tolua_FsLibFaeris___Quad2D_setAnchorX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchorX'", NULL);
#endif
  {
   self->setAnchorX(x);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchorX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnchorY of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setAnchorY00
static int tolua_FsLibFaeris___Quad2D_setAnchorY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchorY'", NULL);
#endif
  {
   self->setAnchorY(y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchorY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnchor of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_setAnchor00
static int tolua_FsLibFaeris___Quad2D_setAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchor'", NULL);
#endif
  {
   self->setAnchor(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchor of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getAnchor00
static int tolua_FsLibFaeris___Quad2D_getAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchor'", NULL);
#endif
  {
   self->getAnchor(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchorX of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getAnchorX00
static int tolua_FsLibFaeris___Quad2D_getAnchorX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchorX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAnchorX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchorX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchorY of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Quad2D_getAnchorY00
static int tolua_FsLibFaeris___Quad2D_getAnchorY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchorY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAnchorY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchorY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_create00
static int tolua_FsLibFaeris_Quad2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaQuad2D* tolua_ret = (LuaQuad2D*)  LuaQuad2D::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaQuad2D");
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

/* method: create of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_create01
static int tolua_FsLibFaeris_Quad2D_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* tex = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LuaQuad2D* tolua_ret = (LuaQuad2D*)  LuaQuad2D::create(tex);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaQuad2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Quad2D_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_create02
static int tolua_FsLibFaeris_Quad2D_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* tex = ((const char*)  tolua_tostring(tolua_S,2,0));
  Rect2D tolua_var_1 = *((Rect2D*)  tolua_tousertype(tolua_S,3,0));
  {
   LuaQuad2D* tolua_ret = (LuaQuad2D*)  LuaQuad2D::create(tex,tolua_var_1);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaQuad2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Quad2D_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_create03
static int tolua_FsLibFaeris_Quad2D_create03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  float width = ((float)  tolua_tonumber(tolua_S,3,0));
  float height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   LuaQuad2D* tolua_ret = (LuaQuad2D*)  LuaQuad2D::create(text,width,height);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaQuad2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Quad2D_create02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_draw00
static int tolua_FsLibFaeris_Quad2D_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaQuad2D* self = (LuaQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_update00
static int tolua_FsLibFaeris_Quad2D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaQuad2D* self = (LuaQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_touchBegin00
static int tolua_FsLibFaeris_Quad2D_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaQuad2D* self = (LuaQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_touchMove00
static int tolua_FsLibFaeris_Quad2D_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaQuad2D* self = (LuaQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_touchEnd00
static int tolua_FsLibFaeris_Quad2D_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaQuad2D* self = (LuaQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Quad2D_hit2D00
static int tolua_FsLibFaeris_Quad2D_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaQuad2D* self = (LuaQuad2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setString of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_setString00
static int tolua_FsLibFaeris___LabelTTF_setString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setString'", NULL);
#endif
  {
   self->setString(str);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_getString00
static int tolua_FsLibFaeris___LabelTTF_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFont of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_setFont00
static int tolua_FsLibFaeris___LabelTTF_setFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  FontTTF* font = ((FontTTF*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFont'", NULL);
#endif
  {
   self->setFont(font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFont of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_getFont00
static int tolua_FsLibFaeris___LabelTTF_getFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFont'", NULL);
#endif
  {
   FontTTF* tolua_ret = (FontTTF*)  self->getFont();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FontTTF");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlign of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_setAlign00
static int tolua_FsLibFaeris___LabelTTF_setAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  int h = ((int)  tolua_tonumber(tolua_S,2,0));
  int v = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlign'", NULL);
#endif
  {
   self->setAlign(h,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlign of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_getAlign00
static int tolua_FsLibFaeris___LabelTTF_getAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  int h = ((int)  tolua_tonumber(tolua_S,2,0));
  int v = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlign'", NULL);
#endif
  {
   self->getAlign(&h,&v);
   tolua_pushnumber(tolua_S,(lua_Number)h);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_setColor00
static int tolua_FsLibFaeris___LabelTTF_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getColor of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_getColor00
static int tolua_FsLibFaeris___LabelTTF_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
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

/* method: setOpacity of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_setOpacity00
static int tolua_FsLibFaeris___LabelTTF_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelTTF_getOpacity00
static int tolua_FsLibFaeris___LabelTTF_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_create00
static int tolua_FsLibFaeris_LabelTTF_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  FontTTF* font = ((FontTTF*)  tolua_tousertype(tolua_S,3,0));
  {
   LuaLabelTTF* tolua_ret = (LuaLabelTTF*)  LuaLabelTTF::create(text,font);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaLabelTTF");
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

/* method: create of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_create01
static int tolua_FsLibFaeris_LabelTTF_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FontTTF* font = ((FontTTF*)  tolua_tousertype(tolua_S,2,0));
  {
   LuaLabelTTF* tolua_ret = (LuaLabelTTF*)  LuaLabelTTF::create(font);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaLabelTTF");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_LabelTTF_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_draw00
static int tolua_FsLibFaeris_LabelTTF_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelTTF* self = (LuaLabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_update00
static int tolua_FsLibFaeris_LabelTTF_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelTTF* self = (LuaLabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_touchBegin00
static int tolua_FsLibFaeris_LabelTTF_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelTTF* self = (LuaLabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_touchMove00
static int tolua_FsLibFaeris_LabelTTF_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelTTF* self = (LuaLabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_touchEnd00
static int tolua_FsLibFaeris_LabelTTF_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelTTF* self = (LuaLabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaLabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelTTF_hit2D00
static int tolua_FsLibFaeris_LabelTTF_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelTTF* self = (LuaLabelTTF*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setColor of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_setColor00
static int tolua_FsLibFaeris___Sprite2D_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  Color color = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
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

/* method: getColor of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_getColor00
static int tolua_FsLibFaeris___Sprite2D_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
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

/* method: setOpacity of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_setOpacity00
static int tolua_FsLibFaeris___Sprite2D_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_getOpacity00
static int tolua_FsLibFaeris___Sprite2D_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setBlendMode of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_setBlendMode00
static int tolua_FsLibFaeris___Sprite2D_setBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  int blendsrc = ((int)  tolua_tonumber(tolua_S,2,0));
  int blenddst = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendMode'", NULL);
#endif
  {
   self->setBlendMode(blendsrc,blenddst);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_setAnimation00
static int tolua_FsLibFaeris___Sprite2D_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'", NULL);
#endif
  {
   self->setAnimation(name);
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

/* method: getAnimation of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_getAnimation00
static int tolua_FsLibFaeris___Sprite2D_getAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimation'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getAnimation();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasAnimation of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_hasAnimation00
static int tolua_FsLibFaeris___Sprite2D_hasAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasAnimation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasAnimation(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateAnimation of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_updateAnimation00
static int tolua_FsLibFaeris___Sprite2D_updateAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: playAnimation of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_playAnimation00
static int tolua_FsLibFaeris___Sprite2D_playAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,Sprite2D::ANIM_LOOP));
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

/* method: startAnimation of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_startAnimation00
static int tolua_FsLibFaeris___Sprite2D_startAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,Sprite2D::ANIM_LOOP));
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

/* method: stopAnimation of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_stopAnimation00
static int tolua_FsLibFaeris___Sprite2D_stopAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAnimationOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_setAnimationOffset00
static int tolua_FsLibFaeris___Sprite2D_setAnimationOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationOffset'", NULL);
#endif
  {
   self->setAnimationOffset(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_getAnimationOffset00
static int tolua_FsLibFaeris___Sprite2D_getAnimationOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationOffset'", NULL);
#endif
  {
   self->getAnimationOffset(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAnimationPlaying of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_isAnimationPlaying00
static int tolua_FsLibFaeris___Sprite2D_isAnimationPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setCurFrame of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_setCurFrame00
static int tolua_FsLibFaeris___Sprite2D_setCurFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  int frame = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCurFrame'", NULL);
#endif
  {
   self->setCurFrame(frame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCurFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurFrame of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_getCurFrame00
static int tolua_FsLibFaeris___Sprite2D_getCurFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurFrame'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurFrame();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTotalFrame of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_getTotalFrame00
static int tolua_FsLibFaeris___Sprite2D_getTotalFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTotalFrame'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTotalFrame();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTotalFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFps of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_getFps00
static int tolua_FsLibFaeris___Sprite2D_getFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFps'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFps();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFps of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Sprite2D_setFps00
static int tolua_FsLibFaeris___Sprite2D_setFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFps'", NULL);
#endif
  {
   self->setFps(fps);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaSprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sprite2D_create00
static int tolua_FsLibFaeris_Sprite2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSprite2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LuaSprite2D* tolua_ret = (LuaSprite2D*)  LuaSprite2D::create(name);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaSprite2D");
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

/* method: onDraw of class  LuaSprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sprite2D_draw00
static int tolua_FsLibFaeris_Sprite2D_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSprite2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSprite2D* self = (LuaSprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaSprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sprite2D_update00
static int tolua_FsLibFaeris_Sprite2D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSprite2D* self = (LuaSprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaSprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sprite2D_touchBegin00
static int tolua_FsLibFaeris_Sprite2D_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSprite2D* self = (LuaSprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaSprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sprite2D_touchMove00
static int tolua_FsLibFaeris_Sprite2D_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSprite2D* self = (LuaSprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaSprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sprite2D_touchEnd00
static int tolua_FsLibFaeris_Sprite2D_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSprite2D* self = (LuaSprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaSprite2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sprite2D_hit2D00
static int tolua_FsLibFaeris_Sprite2D_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSprite2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSprite2D* self = (LuaSprite2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setString of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setString00
static int tolua_FsLibFaeris___LabelBitmap_setString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  const char* utf8_str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setString'", NULL);
#endif
  {
   int tolua_ret = (int)  self->setString(utf8_str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setString of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setString01
static int tolua_FsLibFaeris___LabelBitmap_setString01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  const char* utf8_str = ((const char*)  tolua_tostring(tolua_S,2,0));
  int start = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setString'", NULL);
#endif
  {
   int tolua_ret = (int)  self->setString(utf8_str,start);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris___LabelBitmap_setString00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setString of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setString02
static int tolua_FsLibFaeris___LabelBitmap_setString02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  const char* utf8_str = ((const char*)  tolua_tostring(tolua_S,2,0));
  int start = ((int)  tolua_tonumber(tolua_S,3,0));
  int num = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setString'", NULL);
#endif
  {
   int tolua_ret = (int)  self->setString(utf8_str,start,num);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris___LabelBitmap_setString01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getString00
static int tolua_FsLibFaeris___LabelBitmap_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setColor00
static int tolua_FsLibFaeris___LabelBitmap_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getColor of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getColor00
static int tolua_FsLibFaeris___LabelBitmap_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
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

/* method: setOpacity of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setOpacity00
static int tolua_FsLibFaeris___LabelBitmap_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getOpacity00
static int tolua_FsLibFaeris___LabelBitmap_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAlign of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setAlign00
static int tolua_FsLibFaeris___LabelBitmap_setAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  int alignh = ((int)  tolua_tonumber(tolua_S,2,0));
  int alignv = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlign'", NULL);
#endif
  {
   self->setAlign(alignh,alignv);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignOffset of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setAlignOffset00
static int tolua_FsLibFaeris___LabelBitmap_setAlignOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignOffset'", NULL);
#endif
  {
   self->setAlignOffset(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlign of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getAlign00
static int tolua_FsLibFaeris___LabelBitmap_getAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  int alignh = ((int)  tolua_tonumber(tolua_S,2,0));
  int alignv = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlign'", NULL);
#endif
  {
   self->getAlign(&alignh,&alignv);
   tolua_pushnumber(tolua_S,(lua_Number)alignh);
   tolua_pushnumber(tolua_S,(lua_Number)alignv);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlignOffset of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getAlignOffset00
static int tolua_FsLibFaeris___LabelBitmap_getAlignOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlignOffset'", NULL);
#endif
  {
   self->getAlignOffset(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlignOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getWidth00
static int tolua_FsLibFaeris___LabelBitmap_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getHeight00
static int tolua_FsLibFaeris___LabelBitmap_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTextAlign of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setTextAlign00
static int tolua_FsLibFaeris___LabelBitmap_setTextAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTextAlign'", NULL);
#endif
  {
   self->setTextAlign(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTextAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBounds of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_setBounds00
static int tolua_FsLibFaeris___LabelBitmap_setBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBounds'", NULL);
#endif
  {
   self->setBounds(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextAlign of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getTextAlign00
static int tolua_FsLibFaeris___LabelBitmap_getTextAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextAlign'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTextAlign();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBounds of class  LabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___LabelBitmap_getBounds00
static int tolua_FsLibFaeris___LabelBitmap_getBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelBitmap* self = (LabelBitmap*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBounds'", NULL);
#endif
  {
   self->getBounds(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_create00
static int tolua_FsLibFaeris_LabelBitmap_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"FontBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  FontBitmap* font = ((FontBitmap*)  tolua_tousertype(tolua_S,3,0));
  {
   LuaLabelBitmap* tolua_ret = (LuaLabelBitmap*)  LuaLabelBitmap::create(text,font);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaLabelBitmap");
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

/* method: create of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_create01
static int tolua_FsLibFaeris_LabelBitmap_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FontBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FontBitmap* font = ((FontBitmap*)  tolua_tousertype(tolua_S,2,0));
  {
   LuaLabelBitmap* tolua_ret = (LuaLabelBitmap*)  LuaLabelBitmap::create(font);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaLabelBitmap");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_LabelBitmap_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_draw00
static int tolua_FsLibFaeris_LabelBitmap_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelBitmap* self = (LuaLabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_update00
static int tolua_FsLibFaeris_LabelBitmap_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelBitmap* self = (LuaLabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_touchBegin00
static int tolua_FsLibFaeris_LabelBitmap_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelBitmap* self = (LuaLabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_touchMove00
static int tolua_FsLibFaeris_LabelBitmap_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelBitmap* self = (LuaLabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_touchEnd00
static int tolua_FsLibFaeris_LabelBitmap_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelBitmap* self = (LuaLabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaLabelBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_LabelBitmap_hit2D00
static int tolua_FsLibFaeris_LabelBitmap_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLabelBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLabelBitmap* self = (LuaLabelBitmap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_create00
static int tolua_FsLibFaeris_Particle2DEmitter_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Particle2DEmitter* tolua_ret = (Particle2DEmitter*)  Particle2DEmitter::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Particle2DEmitter");
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

/* method: create of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_create01
static int tolua_FsLibFaeris_Particle2DEmitter_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Particle2DEmitter* tolua_ret = (Particle2DEmitter*)  Particle2DEmitter::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Particle2DEmitter");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Particle2DEmitter_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDurationTime of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setDurationTime00
static int tolua_FsLibFaeris_Particle2DEmitter_setDurationTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDurationTime'", NULL);
#endif
  {
   self->setDurationTime(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDurationTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDurationTime of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getDurationTime00
static int tolua_FsLibFaeris_Particle2DEmitter_getDurationTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setDurationTimeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setDurationTimeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setDurationTimeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDurationTimeVar'", NULL);
#endif
  {
   self->setDurationTimeVar(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDurationTimeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDurationTimeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getDurationTimeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getDurationTimeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDurationTimeVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDurationTimeVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDurationTimeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaxParticleNu of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setMaxParticleNu00
static int tolua_FsLibFaeris_Particle2DEmitter_setMaxParticleNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  int number = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaxParticleNu'", NULL);
#endif
  {
   self->setMaxParticleNu(number);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaxParticleNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxParticleNu of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getMaxParticleNu00
static int tolua_FsLibFaeris_Particle2DEmitter_getMaxParticleNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxParticleNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMaxParticleNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxParticleNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEmitSpeed of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEmitSpeed00
static int tolua_FsLibFaeris_Particle2DEmitter_setEmitSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  int speed = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEmitSpeed'", NULL);
#endif
  {
   self->setEmitSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEmitSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEmitSpeed of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEmitSpeed00
static int tolua_FsLibFaeris_Particle2DEmitter_getEmitSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEmitSpeed'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getEmitSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEmitSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLifeTime of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setLifeTime00
static int tolua_FsLibFaeris_Particle2DEmitter_setLifeTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLifeTime'", NULL);
#endif
  {
   self->setLifeTime(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLifeTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLifeTime of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getLifeTime00
static int tolua_FsLibFaeris_Particle2DEmitter_getLifeTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLifeTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLifeTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLifeTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLifeTimeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setLifeTimeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setLifeTimeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLifeTimeVar'", NULL);
#endif
  {
   self->setLifeTimeVar(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLifeTimeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLifeTimeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getLifeTimeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getLifeTimeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLifeTimeVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLifeTimeVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLifeTimeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartSize of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartSize00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartSize'", NULL);
#endif
  {
   self->setStartSize(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartSize of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartSize00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartSize'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartSizeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartSizeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartSizeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartSizeVar'", NULL);
#endif
  {
   self->setStartSizeVar(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartSizeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartSizeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartSizeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartSizeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartSizeVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartSizeVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartSizeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndSize of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndSize00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndSize'", NULL);
#endif
  {
   self->setEndSize(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndSize of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndSize00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndSize'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getEndSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndSizeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndSizeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndSizeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndSizeVar'", NULL);
#endif
  {
   self->setEndSizeVar(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndSizeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndSizeVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndSizeVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndSizeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndSizeVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getEndSizeVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndSizeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartColor of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartColor00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartColor'", NULL);
#endif
  {
   self->setStartColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartColor of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartColor00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getStartColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartColorVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartColorVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartColorVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartColorVar'", NULL);
#endif
  {
   self->setStartColorVar(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartColorVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartColorVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartColorVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartColorVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartColorVar'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getStartColorVar();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartColorVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndColor of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndColor00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndColor'", NULL);
#endif
  {
   self->setEndColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndColor of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndColor00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getEndColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndColorVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndColorVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndColorVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndColorVar'", NULL);
#endif
  {
   self->setEndColorVar(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndColorVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndColorVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndColorVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndColorVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndColorVar'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getEndColorVar();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndColorVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAngle of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setAngle00
static int tolua_FsLibFaeris_Particle2DEmitter_setAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAngle'", NULL);
#endif
  {
   self->setAngle(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngle of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getAngle00
static int tolua_FsLibFaeris_Particle2DEmitter_getAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAngle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAngleVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setAngleVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setAngleVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAngleVar'", NULL);
#endif
  {
   self->setAngleVar(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAngleVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngleVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getAngleVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getAngleVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngleVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAngleVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngleVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartRotation of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartRotation00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartRotation'", NULL);
#endif
  {
   self->setStartRotation(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartRotation of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartRotation00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartRotation'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartRotation();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartRotationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartRotationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartRotationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartRotationVar'", NULL);
#endif
  {
   self->setStartRotationVar(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartRotationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartRotationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartRotationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartRotationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartRotationVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartRotationVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartRotationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndRotation of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndRotation00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndRotation'", NULL);
#endif
  {
   self->setEndRotation(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndRotation of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndRotation00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndRotation'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getEndRotation();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndRotationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndRotationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndRotationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndRotationVar'", NULL);
#endif
  {
   self->setEndRotationVar(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndRotationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndRotationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndRotationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndRotationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndRotationVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getEndRotationVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndRotationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setPosition00
static int tolua_FsLibFaeris_Particle2DEmitter_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Vector2 pos = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getPosition00
static int tolua_FsLibFaeris_Particle2DEmitter_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setPositionVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setPositionVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Vector2 pos = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionVar'", NULL);
#endif
  {
   self->setPositionVar(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getPositionVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getPositionVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionVar'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getPositionVar();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPositionVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMoveMode of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setMoveMode00
static int tolua_FsLibFaeris_Particle2DEmitter_setMoveMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMoveMode'", NULL);
#endif
  {
   self->setMoveMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMoveMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMoveMode of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getMoveMode00
static int tolua_FsLibFaeris_Particle2DEmitter_getMoveMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMoveMode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMoveMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMoveMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlendSrc of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setBlendSrc00
static int tolua_FsLibFaeris_Particle2DEmitter_setBlendSrc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  int blend = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendSrc'", NULL);
#endif
  {
   self->setBlendSrc(blend);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendSrc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendSrc of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getBlendSrc00
static int tolua_FsLibFaeris_Particle2DEmitter_getBlendSrc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendSrc'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getBlendSrc();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendSrc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlendDst of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setBlendDst00
static int tolua_FsLibFaeris_Particle2DEmitter_setBlendDst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  int blend = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendDst'", NULL);
#endif
  {
   self->setBlendDst(blend);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendDst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendDst of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getBlendDst00
static int tolua_FsLibFaeris_Particle2DEmitter_getBlendDst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendDst'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getBlendDst();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendDst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setTexture00
static int tolua_FsLibFaeris_Particle2DEmitter_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Texture2D* texture = ((Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(texture);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getTexture00
static int tolua_FsLibFaeris_Particle2DEmitter_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   Texture2D* tolua_ret = (Texture2D*)  self->getTexture();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnvironmentMode of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEnvironmentMode00
static int tolua_FsLibFaeris_Particle2DEmitter_setEnvironmentMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnvironmentMode'", NULL);
#endif
  {
   self->setEnvironmentMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEnvironmentMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEnvironmentMode of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEnvironmentMode00
static int tolua_FsLibFaeris_Particle2DEmitter_getEnvironmentMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEnvironmentMode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getEnvironmentMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEnvironmentMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpeed of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setSpeed00
static int tolua_FsLibFaeris_Particle2DEmitter_setSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpeed'", NULL);
#endif
  {
   self->setSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpeed of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getSpeed00
static int tolua_FsLibFaeris_Particle2DEmitter_getSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpeedVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setSpeedVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setSpeedVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpeedVar'", NULL);
#endif
  {
   self->setSpeedVar(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpeedVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpeedVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getSpeedVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getSpeedVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpeedVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getSpeedVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpeedVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGravity of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setGravity00
static int tolua_FsLibFaeris_Particle2DEmitter_setGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  Vector2 g = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGravity'", NULL);
#endif
  {
   self->setGravity(g);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGravity of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getGravity00
static int tolua_FsLibFaeris_Particle2DEmitter_getGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGravity'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getGravity();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRadialAcceleration of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setRadialAcceleration00
static int tolua_FsLibFaeris_Particle2DEmitter_setRadialAcceleration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float accel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRadialAcceleration'", NULL);
#endif
  {
   self->setRadialAcceleration(accel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRadialAcceleration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRadialAcceleration of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getRadialAcceleration00
static int tolua_FsLibFaeris_Particle2DEmitter_getRadialAcceleration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRadialAcceleration'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRadialAcceleration();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRadialAcceleration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRadialAccelerationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setRadialAccelerationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setRadialAccelerationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float accel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRadialAccelerationVar'", NULL);
#endif
  {
   self->setRadialAccelerationVar(accel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRadialAccelerationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRadialAccelerationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getRadialAccelerationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getRadialAccelerationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRadialAccelerationVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRadialAccelerationVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRadialAccelerationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTangentialAcceleration of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setTangentialAcceleration00
static int tolua_FsLibFaeris_Particle2DEmitter_setTangentialAcceleration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float accel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTangentialAcceleration'", NULL);
#endif
  {
   self->setTangentialAcceleration(accel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTangentialAcceleration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTangentialAcceleration of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getTangentialAcceleration00
static int tolua_FsLibFaeris_Particle2DEmitter_getTangentialAcceleration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTangentialAcceleration'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTangentialAcceleration();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTangentialAcceleration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTangentialAccelerationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setTangentialAccelerationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setTangentialAccelerationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float accel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTangentialAccelerationVar'", NULL);
#endif
  {
   self->setTangentialAccelerationVar(accel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTangentialAccelerationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTangentialAccelerationVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getTangentialAccelerationVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getTangentialAccelerationVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTangentialAccelerationVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTangentialAccelerationVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTangentialAccelerationVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartRadius of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartRadius00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartRadius'", NULL);
#endif
  {
   self->setStartRadius(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartRadius of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartRadius00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartRadius'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartRadiusVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setStartRadiusVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setStartRadiusVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartRadiusVar'", NULL);
#endif
  {
   self->setStartRadiusVar(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartRadiusVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartRadiusVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getStartRadiusVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getStartRadiusVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartRadiusVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartRadiusVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartRadiusVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndRadius of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndRadius00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndRadius'", NULL);
#endif
  {
   self->setEndRadius(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndRadius of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndRadius00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndRadius'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getEndRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndRadiusVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setEndRadiusVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setEndRadiusVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndRadiusVar'", NULL);
#endif
  {
   self->setEndRadiusVar(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndRadiusVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEndRadiusVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getEndRadiusVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getEndRadiusVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndRadiusVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getEndRadiusVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndRadiusVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateSpeed of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setRotateSpeed00
static int tolua_FsLibFaeris_Particle2DEmitter_setRotateSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateSpeed'", NULL);
#endif
  {
   self->setRotateSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotateSpeed of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getRotateSpeed00
static int tolua_FsLibFaeris_Particle2DEmitter_getRotateSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotateSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRotateSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotateSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateSpeedVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_setRotateSpeedVar00
static int tolua_FsLibFaeris_Particle2DEmitter_setRotateSpeedVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateSpeedVar'", NULL);
#endif
  {
   self->setRotateSpeedVar(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateSpeedVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotateSpeedVar of class  Particle2DEmitter */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEmitter_getRotateSpeedVar00
static int tolua_FsLibFaeris_Particle2DEmitter_getRotateSpeedVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEmitter* self = (Particle2DEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotateSpeedVar'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRotateSpeedVar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotateSpeedVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_start00
static int tolua_FsLibFaeris___Particle2DEffect_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
  bool restart = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(restart);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: refresh of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_refresh00
static int tolua_FsLibFaeris___Particle2DEffect_refresh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'refresh'", NULL);
#endif
  {
   self->refresh();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'refresh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_stop00
static int tolua_FsLibFaeris___Particle2DEffect_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPause of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_setPause00
static int tolua_FsLibFaeris___Particle2DEffect_setPause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
  bool pause = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPause'", NULL);
#endif
  {
   self->setPause(pause);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPause of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_isPause00
static int tolua_FsLibFaeris___Particle2DEffect_isPause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPause'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPause();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isStop of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_isStop00
static int tolua_FsLibFaeris___Particle2DEffect_isStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isStop'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isStop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLifeTime of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_getLifeTime00
static int tolua_FsLibFaeris___Particle2DEffect_getLifeTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLifeTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLifeTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLifeTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getElapseTime of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_getElapseTime00
static int tolua_FsLibFaeris___Particle2DEffect_getElapseTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElapseTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getElapseTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElapseTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEmitter of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_setEmitter00
static int tolua_FsLibFaeris___Particle2DEffect_setEmitter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
  Particle2DEmitter* emit = ((Particle2DEmitter*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEmitter'", NULL);
#endif
  {
   self->setEmitter(emit);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEmitter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEmitter of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_getEmitter00
static int tolua_FsLibFaeris___Particle2DEffect_getEmitter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEmitter'", NULL);
#endif
  {
   Particle2DEmitter* tolua_ret = (Particle2DEmitter*)  self->getEmitter();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Particle2DEmitter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEmitter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoRemoveOnStop of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_setAutoRemoveOnStop00
static int tolua_FsLibFaeris___Particle2DEffect_setAutoRemoveOnStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
  bool remove = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoRemoveOnStop'", NULL);
#endif
  {
   self->setAutoRemoveOnStop(remove);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoRemoveOnStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParticleNu of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_getParticleNu00
static int tolua_FsLibFaeris___Particle2DEffect_getParticleNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParticleNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getParticleNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParticleNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxParticleNu of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_getMaxParticleNu00
static int tolua_FsLibFaeris___Particle2DEffect_getMaxParticleNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxParticleNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMaxParticleNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxParticleNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_setOpacity00
static int tolua_FsLibFaeris___Particle2DEffect_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
  float v = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(v);
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

/* method: getOpacity of class  Particle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Particle2DEffect_getOpacity00
static int tolua_FsLibFaeris___Particle2DEffect_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Particle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Particle2DEffect* self = (Particle2DEffect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_create00
static int tolua_FsLibFaeris_Particle2DEffect_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LuaParticle2DEffect* tolua_ret = (LuaParticle2DEffect*)  LuaParticle2DEffect::create(filename);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaParticle2DEffect");
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

/* method: create of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_create01
static int tolua_FsLibFaeris_Particle2DEffect_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FsFile* file = ((FsFile*)  tolua_tousertype(tolua_S,2,0));
  {
   LuaParticle2DEffect* tolua_ret = (LuaParticle2DEffect*)  LuaParticle2DEffect::create(file);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaParticle2DEffect");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Particle2DEffect_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_create02
static int tolua_FsLibFaeris_Particle2DEffect_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Particle2DEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Particle2DEmitter* emitter = ((Particle2DEmitter*)  tolua_tousertype(tolua_S,2,0));
  {
   LuaParticle2DEffect* tolua_ret = (LuaParticle2DEffect*)  LuaParticle2DEffect::create(emitter);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaParticle2DEffect");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Particle2DEffect_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_create03
static int tolua_FsLibFaeris_Particle2DEffect_create03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   LuaParticle2DEffect* tolua_ret = (LuaParticle2DEffect*)  LuaParticle2DEffect::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaParticle2DEffect");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Particle2DEffect_create02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_draw00
static int tolua_FsLibFaeris_Particle2DEffect_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaParticle2DEffect* self = (LuaParticle2DEffect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_update00
static int tolua_FsLibFaeris_Particle2DEffect_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaParticle2DEffect* self = (LuaParticle2DEffect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_touchBegin00
static int tolua_FsLibFaeris_Particle2DEffect_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaParticle2DEffect* self = (LuaParticle2DEffect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_touchMove00
static int tolua_FsLibFaeris_Particle2DEffect_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaParticle2DEffect* self = (LuaParticle2DEffect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_touchEnd00
static int tolua_FsLibFaeris_Particle2DEffect_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaParticle2DEffect* self = (LuaParticle2DEffect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaParticle2DEffect */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Particle2DEffect_hit2D00
static int tolua_FsLibFaeris_Particle2DEffect_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaParticle2DEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaParticle2DEffect* self = (LuaParticle2DEffect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setOpacity of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_setOpacity00
static int tolua_FsLibFaeris___VertexPolygon_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_getOpacity00
static int tolua_FsLibFaeris___VertexPolygon_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setColor of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_setColor00
static int tolua_FsLibFaeris___VertexPolygon_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  Color color = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
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

/* method: getColor of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_getColor00
static int tolua_FsLibFaeris___VertexPolygon_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
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

/* method: setVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_setVertex00
static int tolua_FsLibFaeris___VertexPolygon_setVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  Vector3 v = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVertex'", NULL);
#endif
  {
   self->setVertex(index,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_setVertex01
static int tolua_FsLibFaeris___VertexPolygon_setVertex01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  Vector2 v = *((Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVertex'", NULL);
#endif
  {
   self->setVertex(index,v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___VertexPolygon_setVertex00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_setVertex02
static int tolua_FsLibFaeris___VertexPolygon_setVertex02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVertex'", NULL);
#endif
  {
   self->setVertex(index,x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___VertexPolygon_setVertex01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_getVertex00
static int tolua_FsLibFaeris___VertexPolygon_getVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVertex'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getVertex(index);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: append of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_append00
static int tolua_FsLibFaeris___VertexPolygon_append00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  Vector3 v = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'append'", NULL);
#endif
  {
   self->append(v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'append'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: append of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_append01
static int tolua_FsLibFaeris___VertexPolygon_append01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  Vector2 v = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'append'", NULL);
#endif
  {
   self->append(v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___VertexPolygon_append00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: append of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_append02
static int tolua_FsLibFaeris___VertexPolygon_append02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'append'", NULL);
#endif
  {
   self->append(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___VertexPolygon_append01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_removeVertex00
static int tolua_FsLibFaeris___VertexPolygon_removeVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeVertex'", NULL);
#endif
  {
   self->removeVertex(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_insertVertex00
static int tolua_FsLibFaeris___VertexPolygon_insertVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  Vector3 v = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertVertex'", NULL);
#endif
  {
   self->insertVertex(index,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_insertVertex01
static int tolua_FsLibFaeris___VertexPolygon_insertVertex01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  Vector2 v = *((Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertVertex'", NULL);
#endif
  {
   self->insertVertex(index,v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___VertexPolygon_insertVertex00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertVertex of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_insertVertex02
static int tolua_FsLibFaeris___VertexPolygon_insertVertex02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertVertex'", NULL);
#endif
  {
   self->insertVertex(index,x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___VertexPolygon_insertVertex01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_resize00
static int tolua_FsLibFaeris___VertexPolygon_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  int nu = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'", NULL);
#endif
  {
   self->resize(nu);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVertexNu of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_getVertexNu00
static int tolua_FsLibFaeris___VertexPolygon_getVertexNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVertexNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getVertexNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVertexNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMode of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_setMode00
static int tolua_FsLibFaeris___VertexPolygon_setMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMode'", NULL);
#endif
  {
   self->setMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMode of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_getMode00
static int tolua_FsLibFaeris___VertexPolygon_getMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPointSize of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_setPointSize00
static int tolua_FsLibFaeris___VertexPolygon_setPointSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPointSize'", NULL);
#endif
  {
   self->setPointSize(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPointSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointSize of class  VertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___VertexPolygon_getPointSize00
static int tolua_FsLibFaeris___VertexPolygon_getPointSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VertexPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexPolygon* self = (VertexPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPointSize'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPointSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPointSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaVertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_VertexPolygon_create00
static int tolua_FsLibFaeris_VertexPolygon_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaVertexPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaVertexPolygon* tolua_ret = (LuaVertexPolygon*)  LuaVertexPolygon::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaVertexPolygon");
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

/* method: onDraw of class  LuaVertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_VertexPolygon_draw00
static int tolua_FsLibFaeris_VertexPolygon_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaVertexPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaVertexPolygon* self = (LuaVertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaVertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_VertexPolygon_update00
static int tolua_FsLibFaeris_VertexPolygon_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaVertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaVertexPolygon* self = (LuaVertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaVertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_VertexPolygon_touchBegin00
static int tolua_FsLibFaeris_VertexPolygon_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaVertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaVertexPolygon* self = (LuaVertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaVertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_VertexPolygon_touchMove00
static int tolua_FsLibFaeris_VertexPolygon_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaVertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaVertexPolygon* self = (LuaVertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaVertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_VertexPolygon_touchEnd00
static int tolua_FsLibFaeris_VertexPolygon_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaVertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaVertexPolygon* self = (LuaVertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaVertexPolygon */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_VertexPolygon_hit2D00
static int tolua_FsLibFaeris_VertexPolygon_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaVertexPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaVertexPolygon* self = (LuaVertexPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setSize of class  Panel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Panel_setSize00
static int tolua_FsLibFaeris___Panel_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   self->setSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  Panel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Panel_getSize00
static int tolua_FsLibFaeris___Panel_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'", NULL);
#endif
  {
   self->getSize(&width,&height);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnchor of class  Panel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Panel_setAnchor00
static int tolua_FsLibFaeris___Panel_setAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchor'", NULL);
#endif
  {
   self->setAnchor(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchor of class  Panel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Panel_getAnchor00
static int tolua_FsLibFaeris___Panel_getAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchor'", NULL);
#endif
  {
   self->getAnchor(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScissorEnabled of class  Panel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Panel_setScissorEnabled00
static int tolua_FsLibFaeris___Panel_setScissorEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScissorEnabled'", NULL);
#endif
  {
   self->setScissorEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScissorEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScissorEnabled of class  Panel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Panel_getScissorEnabled00
static int tolua_FsLibFaeris___Panel_getScissorEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScissorEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getScissorEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScissorEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_create00
static int tolua_FsLibFaeris_Panel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaPanel* tolua_ret = (LuaPanel*)  LuaPanel::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaPanel");
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

/* method: create of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_create01
static int tolua_FsLibFaeris_Panel_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   LuaPanel* tolua_ret = (LuaPanel*)  LuaPanel::create(width,height);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaPanel");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Panel_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_draw00
static int tolua_FsLibFaeris_Panel_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPanel* self = (LuaPanel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_update00
static int tolua_FsLibFaeris_Panel_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPanel* self = (LuaPanel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_touchBegin00
static int tolua_FsLibFaeris_Panel_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPanel* self = (LuaPanel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_touchMove00
static int tolua_FsLibFaeris_Panel_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPanel* self = (LuaPanel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_touchEnd00
static int tolua_FsLibFaeris_Panel_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPanel* self = (LuaPanel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaPanel */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Panel_hit2D00
static int tolua_FsLibFaeris_Panel_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaPanel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaPanel* self = (LuaPanel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setFlag of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setFlag00
static int tolua_FsLibFaeris_ButtonState_setFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  int flags = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlag'", NULL);
#endif
  {
   self->setFlag(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearFlag of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_clearFlag00
static int tolua_FsLibFaeris_ButtonState_clearFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  int flags = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearFlag'", NULL);
#endif
  {
   self->clearFlag(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearFlag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setColor00
static int tolua_FsLibFaeris_ButtonState_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getColor of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getColor00
static int tolua_FsLibFaeris_ButtonState_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
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

/* method: setOpacity of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setOpacity00
static int tolua_FsLibFaeris_ButtonState_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getOpacity00
static int tolua_FsLibFaeris_ButtonState_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setTexture of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setTexture00
static int tolua_FsLibFaeris_ButtonState_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(filename);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setTexture01
static int tolua_FsLibFaeris_ButtonState_setTexture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  Texture2D* tex = ((Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_ButtonState_setTexture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getTexture00
static int tolua_FsLibFaeris_ButtonState_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   Texture2D* tolua_ret = (Texture2D*)  self->getTexture();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setSize00
static int tolua_FsLibFaeris_ButtonState_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   self->setSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getSize00
static int tolua_FsLibFaeris_ButtonState_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'", NULL);
#endif
  {
   self->getSize(&width,&height);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnchor of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setAnchor00
static int tolua_FsLibFaeris_ButtonState_setAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchor'", NULL);
#endif
  {
   self->setAnchor(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchor of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getAnchor00
static int tolua_FsLibFaeris_ButtonState_getAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchor'", NULL);
#endif
  {
   self->getAnchor(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setPosition00
static int tolua_FsLibFaeris_ButtonState_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  Vector3 t = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getPosition00
static int tolua_FsLibFaeris_ButtonState_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotate of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setRotate00
static int tolua_FsLibFaeris_ButtonState_setRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  Vector3 r = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotate'", NULL);
#endif
  {
   self->setRotate(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotate of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getRotate00
static int tolua_FsLibFaeris_ButtonState_getRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotate'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getRotate();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setScale00
static int tolua_FsLibFaeris_ButtonState_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  Vector3 s = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getScale00
static int tolua_FsLibFaeris_ButtonState_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getScale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZorder of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setZorder00
static int tolua_FsLibFaeris_ButtonState_setZorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  float orlder = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZorder'", NULL);
#endif
  {
   self->setZorder(orlder);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getZorder of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getZorder00
static int tolua_FsLibFaeris_ButtonState_getZorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getZorder'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getZorder();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getZorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setChild of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_setChild00
static int tolua_FsLibFaeris_ButtonState_setChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
  FsArray* child = ((FsArray*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setChild'", NULL);
#endif
  {
   self->setChild(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChild of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ButtonState_getChild00
static int tolua_FsLibFaeris_ButtonState_getChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChild'", NULL);
#endif
  {
   FsArray* tolua_ret = (FsArray*)  self->getChild();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FsArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNormalState of class  Button */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Button_getNormalState00
static int tolua_FsLibFaeris___Button_getNormalState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNormalState'", NULL);
#endif
  {
   ButtonState* tolua_ret = (ButtonState*)  self->getNormalState();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ButtonState");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNormalState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPressState of class  Button */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Button_getPressState00
static int tolua_FsLibFaeris___Button_getPressState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPressState'", NULL);
#endif
  {
   ButtonState* tolua_ret = (ButtonState*)  self->getPressState();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ButtonState");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPressState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStateNormal of class  Button */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Button_setStateNormal00
static int tolua_FsLibFaeris___Button_setStateNormal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStateNormal'", NULL);
#endif
  {
   self->setStateNormal();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStateNormal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStatePress of class  Button */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Button_setStatePress00
static int tolua_FsLibFaeris___Button_setStatePress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStatePress'", NULL);
#endif
  {
   self->setStatePress();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStatePress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_create00
static int tolua_FsLibFaeris_Button_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaButton* tolua_ret = (LuaButton*)  LuaButton::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaButton");
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

/* method: create of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_create01
static int tolua_FsLibFaeris_Button_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* image = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LuaButton* tolua_ret = (LuaButton*)  LuaButton::create(image);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaButton");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Button_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_create02
static int tolua_FsLibFaeris_Button_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* image = ((const char*)  tolua_tostring(tolua_S,2,0));
  float width = ((float)  tolua_tonumber(tolua_S,3,0));
  float height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   LuaButton* tolua_ret = (LuaButton*)  LuaButton::create(image,width,height);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaButton");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Button_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_draw00
static int tolua_FsLibFaeris_Button_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onUpdate of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_update00
static int tolua_FsLibFaeris_Button_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchBegin of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_touchBegin00
static int tolua_FsLibFaeris_Button_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_touchMove00
static int tolua_FsLibFaeris_Button_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_touchEnd00
static int tolua_FsLibFaeris_Button_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onHit2D of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_hit2D00
static int tolua_FsLibFaeris_Button_hit2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onClick of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_click00
static int tolua_FsLibFaeris_Button_click00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onClick'", NULL);
#endif
  {
   self->onClick();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'click'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onPressDown of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_pressDown00
static int tolua_FsLibFaeris_Button_pressDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onPressDown'", NULL);
#endif
  {
   self->onPressDown(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pressDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onPressMoveIn of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_pressMoveIn00
static int tolua_FsLibFaeris_Button_pressMoveIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onPressMoveIn'", NULL);
#endif
  {
   self->onPressMoveIn(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pressMoveIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onPressMoveOut of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_pressMoveOut00
static int tolua_FsLibFaeris_Button_pressMoveOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onPressMoveOut'", NULL);
#endif
  {
   self->onPressMoveOut(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pressMoveOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onPressUp of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_pressUp00
static int tolua_FsLibFaeris_Button_pressUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onPressUp'", NULL);
#endif
  {
   self->onPressUp(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pressUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onPressCancel of class  LuaButton */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Button_pressCancel00
static int tolua_FsLibFaeris_Button_pressCancel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaButton* self = (LuaButton*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onPressCancel'", NULL);
#endif
  {
   self->onPressCancel(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pressCancel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: refCnt of class  Resource */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Resource_refCnt00
static int tolua_FsLibFaeris_Resource_refCnt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'refCnt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->refCnt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'refCnt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addRef of class  Resource */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Resource_addRef00
static int tolua_FsLibFaeris_Resource_addRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addRef'", NULL);
#endif
  {
   self->addRef();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decRef of class  Resource */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Resource_decRef00
static int tolua_FsLibFaeris_Resource_decRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'decRef'", NULL);
#endif
  {
   self->decRef();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRefDelete of class  Resource */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Resource_setRefDelete00
static int tolua_FsLibFaeris_Resource_setRefDelete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRefDelete'", NULL);
#endif
  {
   self->setRefDelete(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRefDelete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRefDelete of class  Resource */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Resource_getRefDelete00
static int tolua_FsLibFaeris_Resource_getRefDelete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRefDelete'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getRefDelete();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRefDelete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  Resource */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Resource_destroy00
static int tolua_FsLibFaeris_Resource_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'", NULL);
#endif
  {
   self->destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: autoDestroy of class  Resource */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Resource_autoDestroy00
static int tolua_FsLibFaeris_Resource_autoDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'autoDestroy'", NULL);
#endif
  {
   self->autoDestroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'autoDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSearchPath of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_addSearchPath00
static int tolua_FsLibFaeris_ResourceMgr_addSearchPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSearchPath'", NULL);
#endif
  {
   self->addSearchPath(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: existSearchPath of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_existSearchPath00
static int tolua_FsLibFaeris_ResourceMgr_existSearchPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'existSearchPath'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->existSearchPath(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'existSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeSearchPath of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_removeSearchPath00
static int tolua_FsLibFaeris_ResourceMgr_removeSearchPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeSearchPath'", NULL);
#endif
  {
   self->removeSearchPath(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: preloadResource of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_preloadResource00
static int tolua_FsLibFaeris_ResourceMgr_preloadResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'preloadResource'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->preloadResource(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'preloadResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_load00
static int tolua_FsLibFaeris_ResourceMgr_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'", NULL);
#endif
  {
   Resource* tolua_ret = (Resource*)  self->load(path);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Resource");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unload of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_unload00
static int tolua_FsLibFaeris_ResourceMgr_unload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool force = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unload'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->unload(path,force);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadAll of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_unloadAll00
static int tolua_FsLibFaeris_ResourceMgr_unloadAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  bool force = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadAll'", NULL);
#endif
  {
   self->unloadAll(force);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCacheResourceNu of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_getCacheResourceNu00
static int tolua_FsLibFaeris_ResourceMgr_getCacheResourceNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCacheResourceNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCacheResourceNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCacheResourceNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_remove00
static int tolua_FsLibFaeris_ResourceMgr_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  Resource* res = ((Resource*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(res);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_add00
static int tolua_FsLibFaeris_ResourceMgr_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  Resource* res = ((Resource*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(name,res);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dump of class  ResourceMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ResourceMgr_dump00
static int tolua_FsLibFaeris_ResourceMgr_dump00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceMgr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceMgr* self = (ResourceMgr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dump'", NULL);
#endif
  {
   self->dump();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dump'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: className of class  ObjectMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ObjectMgr_className00
static int tolua_FsLibFaeris_ObjectMgr_className00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectMgr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectMgr* self = (ObjectMgr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'className'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->className();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'className'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: manageObject of class  ObjectMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ObjectMgr_manageObject00
static int tolua_FsLibFaeris_ObjectMgr_manageObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectMgr",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectMgr* self = (ObjectMgr*)  tolua_tousertype(tolua_S,1,0);
  FsObject* ob = ((FsObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'manageObject'", NULL);
#endif
  {
   self->manageObject(ob);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'manageObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unManageObject of class  ObjectMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ObjectMgr_unManageObject00
static int tolua_FsLibFaeris_ObjectMgr_unManageObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectMgr",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectMgr* self = (ObjectMgr*)  tolua_tousertype(tolua_S,1,0);
  FsObject* ob = ((FsObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unManageObject'", NULL);
#endif
  {
   self->unManageObject(ob);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unManageObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dropObjectData of class  ObjectMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ObjectMgr_dropObjectData00
static int tolua_FsLibFaeris_ObjectMgr_dropObjectData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectMgr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectMgr* self = (ObjectMgr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dropObjectData'", NULL);
#endif
  {
   self->dropObjectData();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dropObjectData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unManageAllObject of class  ObjectMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ObjectMgr_unManageAllObject00
static int tolua_FsLibFaeris_ObjectMgr_unManageAllObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectMgr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectMgr* self = (ObjectMgr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unManageAllObject'", NULL);
#endif
  {
   self->unManageAllObject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unManageAllObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getManageObjectNu of class  ObjectMgr */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ObjectMgr_getManageObjectNu00
static int tolua_FsLibFaeris_ObjectMgr_getManageObjectNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectMgr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectMgr* self = (ObjectMgr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getManageObjectNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getManageObjectNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getManageObjectNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_create00
static int tolua_FsLibFaeris_Scheduler_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scheduler* tolua_ret = (Scheduler*)  Scheduler::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Scheduler");
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

/* method: className of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_className00
static int tolua_FsLibFaeris_Scheduler_className00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'className'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->className();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'className'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_start00
static int tolua_FsLibFaeris_Scheduler_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_stop00
static int tolua_FsLibFaeris_Scheduler_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFps of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_setFps00
static int tolua_FsLibFaeris_Scheduler_setFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFps'", NULL);
#endif
  {
   self->setFps(fps);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mainLoop of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_mainLoop00
static int tolua_FsLibFaeris_Scheduler_mainLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mainLoop'", NULL);
#endif
  {
   self->mainLoop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mainLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scheduleWithMiliSecond of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_scheduleWithMiliSecond00
static int tolua_FsLibFaeris_Scheduler_scheduleWithMiliSecond00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scheduleWithMiliSecond'", NULL);
#endif
  {
   self->scheduleWithMiliSecond(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scheduleWithMiliSecond'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_add00
static int tolua_FsLibFaeris_Scheduler_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SchedulerTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
  SchedulerTarget* s = ((SchedulerTarget*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(s,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scheduler_remove00
static int tolua_FsLibFaeris_Scheduler_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SchedulerTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
  SchedulerTarget* s = ((SchedulerTarget*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(s,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaSchedulerTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SchedulerTarget_create00
static int tolua_FsLibFaeris_SchedulerTarget_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSchedulerTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaSchedulerTarget* tolua_ret = (LuaSchedulerTarget*)  LuaSchedulerTarget::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaSchedulerTarget");
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

/* method: update of class  LuaSchedulerTarget */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SchedulerTarget_update00
static int tolua_FsLibFaeris_SchedulerTarget_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSchedulerTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSchedulerTarget* self = (LuaSchedulerTarget*)  tolua_tousertype(tolua_S,1,0);
  int priority = ((int)  tolua_tonumber(tolua_S,2,0));
  float dt = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(priority,dt);
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

/* method: push of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_push00
static int tolua_FsLibFaeris___Scene_push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'", NULL);
#endif
  {
   self->push(layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pop of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_pop00
static int tolua_FsLibFaeris___Scene_pop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pop'", NULL);
#endif
  {
   self->pop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insert of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_insert00
static int tolua_FsLibFaeris___Scene_insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insert'", NULL);
#endif
  {
   self->insert(pos,layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replace of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_replace00
static int tolua_FsLibFaeris___Scene_replace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'replace'", NULL);
#endif
  {
   self->replace(pos,layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_remove00
static int tolua_FsLibFaeris___Scene_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: layerNu of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_layerNu00
static int tolua_FsLibFaeris___Scene_layerNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'layerNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->layerNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'layerNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLayerIndex of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_getLayerIndex00
static int tolua_FsLibFaeris___Scene_getLayerIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayerIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLayerIndex(layer);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayerIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: top of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_top00
static int tolua_FsLibFaeris___Scene_top00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'top'", NULL);
#endif
  {
   Layer* tolua_ret = (Layer*)  self->top();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Layer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'top'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLayer of class  Scene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Scene_getLayer00
static int tolua_FsLibFaeris___Scene_getLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayer'", NULL);
#endif
  {
   Layer* tolua_ret = (Layer*)  self->getLayer(index);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Layer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_create00
static int tolua_FsLibFaeris_Scene_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaScene* tolua_ret = (LuaScene*)  LuaScene::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaScene");
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

/* method: onEnter of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_enter00
static int tolua_FsLibFaeris_Scene_enter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onEnter'", NULL);
#endif
  {
   self->onEnter();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onExit of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_exit00
static int tolua_FsLibFaeris_Scene_exit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onExit'", NULL);
#endif
  {
   self->onExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'exit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onUpdate of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_update00
static int tolua_FsLibFaeris_Scene_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onDraw of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_draw00
static int tolua_FsLibFaeris_Scene_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(render);
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

/* method: onTouchBegin of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchBegin00
static int tolua_FsLibFaeris_Scene_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchBegin'", NULL);
#endif
  {
   self->onTouchBegin(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchEnd of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchEnd00
static int tolua_FsLibFaeris_Scene_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchEnd'", NULL);
#endif
  {
   self->onTouchEnd(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchMove of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchMove00
static int tolua_FsLibFaeris_Scene_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchMove'", NULL);
#endif
  {
   self->onTouchMove(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesBegin of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchesBegin00
static int tolua_FsLibFaeris_Scene_touchesBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesBegin'", NULL);
#endif
  {
   self->onTouchesBegin(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesPointerDown of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchesPointerDown00
static int tolua_FsLibFaeris_Scene_touchesPointerDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesPointerDown'", NULL);
#endif
  {
   self->onTouchesPointerDown(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesPointerDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesMove of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchesMove00
static int tolua_FsLibFaeris_Scene_touchesMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesMove'", NULL);
#endif
  {
   self->onTouchesMove(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesPointerUp of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchesPointerUp00
static int tolua_FsLibFaeris_Scene_touchesPointerUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesPointerUp'", NULL);
#endif
  {
   self->onTouchesPointerUp(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesPointerUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesEnd of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_touchesEnd00
static int tolua_FsLibFaeris_Scene_touchesEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesEnd'", NULL);
#endif
  {
   self->onTouchesEnd(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onKeypadEvent of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Scene_keypadEvent00
static int tolua_FsLibFaeris_Scene_keypadEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
  int keycode = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onKeypadEvent'", NULL);
#endif
  {
   self->onKeypadEvent(type,keycode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keypadEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_push00
static int tolua_FsLibFaeris_Director_push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'", NULL);
#endif
  {
   self->push();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_push01
static int tolua_FsLibFaeris_Director_push01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'", NULL);
#endif
  {
   self->push(scene);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Director_push00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: pop of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_pop00
static int tolua_FsLibFaeris_Director_pop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pop'", NULL);
#endif
  {
   self->pop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_run00
static int tolua_FsLibFaeris_Director_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run(scene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: current of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_current00
static int tolua_FsLibFaeris_Director_current00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'current'", NULL);
#endif
  {
   Scene* tolua_ret = (Scene*)  self->current();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'current'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_pause00
static int tolua_FsLibFaeris_Director_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_start00
static int tolua_FsLibFaeris_Director_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isRunning of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_isRunning00
static int tolua_FsLibFaeris_Director_isRunning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRunning'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isRunning();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRunning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoSwapBuffers of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Director_setAutoSwapBuffers00
static int tolua_FsLibFaeris_Director_setAutoSwapBuffers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
  bool swap = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoSwapBuffers'", NULL);
#endif
  {
   self->setAutoSwapBuffers(swap);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoSwapBuffers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVisible of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getVisible00
static int tolua_FsLibFaeris___layer_getVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVisible of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_visible00
static int tolua_FsLibFaeris___layer_visible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_setVisible00
static int tolua_FsLibFaeris___layer_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_touchEnabled00
static int tolua_FsLibFaeris___layer_touchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_setTouchEnabled00
static int tolua_FsLibFaeris___layer_setTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchEnabled'", NULL);
#endif
  {
   self->setTouchEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchesEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_setTouchesEnabled00
static int tolua_FsLibFaeris___layer_setTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchesEnabled'", NULL);
#endif
  {
   self->setTouchesEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTouchesEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getTouchesEnabled00
static int tolua_FsLibFaeris___layer_getTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTouchesEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getTouchesEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDispatchTouchEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_setDispatchTouchEnabled00
static int tolua_FsLibFaeris___layer_setDispatchTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDispatchTouchEnabled'", NULL);
#endif
  {
   self->setDispatchTouchEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDispatchTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDispatchTouchEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getDispatchTouchEnabled00
static int tolua_FsLibFaeris___layer_getDispatchTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDispatchTouchEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getDispatchTouchEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDispatchTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDispatchTouchesEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_setDispatchTouchesEnabled00
static int tolua_FsLibFaeris___layer_setDispatchTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDispatchTouchesEnabled'", NULL);
#endif
  {
   self->setDispatchTouchesEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDispatchTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDispatchTouchesEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getDispatchTouchesEnabled00
static int tolua_FsLibFaeris___layer_getDispatchTouchesEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDispatchTouchesEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getDispatchTouchesEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDispatchTouchesEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScissorArea of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_setScissorArea00
static int tolua_FsLibFaeris___layer_setScissorArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScissorArea'", NULL);
#endif
  {
   self->setScissorArea(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScissorArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScissorArea of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getScissorArea00
static int tolua_FsLibFaeris___layer_getScissorArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScissorArea'", NULL);
#endif
  {
   self->getScissorArea(&x,&y,&width,&height);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScissorArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scissorEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_scissorEnabled00
static int tolua_FsLibFaeris___layer_scissorEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scissorEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->scissorEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scissorEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScissorEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_setScissorEnabled00
static int tolua_FsLibFaeris___layer_setScissorEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScissorEnabled'", NULL);
#endif
  {
   self->setScissorEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScissorEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProjectMatrix of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getProjectMatrix00
static int tolua_FsLibFaeris___layer_getProjectMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProjectMatrix'", NULL);
#endif
  {
   Matrix4 tolua_ret = (Matrix4)  self->getProjectMatrix();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProjectMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toLayerCoord of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_toLayerCoord00
static int tolua_FsLibFaeris___layer_toLayerCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toLayerCoord'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->toLayerCoord(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toLayerCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_add00
static int tolua_FsLibFaeris___layer_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(entity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_remove00
static int tolua_FsLibFaeris___layer_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(entity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearEntity of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_clearEntity00
static int tolua_FsLibFaeris___layer_clearEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearEntity'", NULL);
#endif
  {
   self->clearEntity();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEntityNu of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getEntityNu00
static int tolua_FsLibFaeris___layer_getEntityNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEntityNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getEntityNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEntityNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScene of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___layer_getScene00
static int tolua_FsLibFaeris___layer_getScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScene'", NULL);
#endif
  {
   Scene* tolua_ret = (Scene*)  self->getScene();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  ColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorLayer_setColor00
static int tolua_FsLibFaeris___ColorLayer_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorLayer* self = (ColorLayer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getColor of class  ColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___ColorLayer_getColor00
static int tolua_FsLibFaeris___ColorLayer_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorLayer* self = (ColorLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
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

/* method: create of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorLayer_create00
static int tolua_FsLibFaeris_ColorLayer_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaColorLayer* tolua_ret = (LuaColorLayer*)  LuaColorLayer::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorLayer");
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

/* method: create of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorLayer_create01
static int tolua_FsLibFaeris_ColorLayer_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
  {
   LuaColorLayer* tolua_ret = (LuaColorLayer*)  LuaColorLayer::create(c);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorLayer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_ColorLayer_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onUpdate of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorLayer_update00
static int tolua_FsLibFaeris_ColorLayer_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onDraw of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorLayer_draw00
static int tolua_FsLibFaeris_ColorLayer_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(render);
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

/* method: onTouchBegin of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorLayer_touchBegin00
static int tolua_FsLibFaeris_ColorLayer_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorLayer_touchEnd00
static int tolua_FsLibFaeris_ColorLayer_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ColorLayer_touchMove00
static int tolua_FsLibFaeris_ColorLayer_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getProjectMatrix of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_getProjectMatrix00
static int tolua_FsLibFaeris___Layer2D_getProjectMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProjectMatrix'", NULL);
#endif
  {
   Matrix4 tolua_ret = (Matrix4)  self->getProjectMatrix();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProjectMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toLayerCoord of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_toLayerCoord00
static int tolua_FsLibFaeris___Layer2D_toLayerCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toLayerCoord'", NULL);
#endif
  {
   self->toLayerCoord(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toLayerCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewArea of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_setViewArea00
static int tolua_FsLibFaeris___Layer2D_setViewArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewArea'", NULL);
#endif
  {
   self->setViewArea(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewArea of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_getViewArea00
static int tolua_FsLibFaeris___Layer2D_getViewArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewArea'", NULL);
#endif
  {
   self->getViewArea(&x,&y,&width,&height);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewArea of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_setViewArea01
static int tolua_FsLibFaeris___Layer2D_setViewArea01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* area = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewArea'", NULL);
#endif
  {
   self->setViewArea(*area);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris___Layer2D_setViewArea00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSortMode of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_setSortMode00
static int tolua_FsLibFaeris___Layer2D_setSortMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSortMode'", NULL);
#endif
  {
   self->setSortMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSortMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSortMode of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_getSortMode00
static int tolua_FsLibFaeris___Layer2D_getSortMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSortMode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getSortMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSortMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEliminate of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_setEliminate00
static int tolua_FsLibFaeris___Layer2D_setEliminate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  bool eliminate = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEliminate'", NULL);
#endif
  {
   self->setEliminate(eliminate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEliminate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEliminate of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris___Layer2D_getEliminate00
static int tolua_FsLibFaeris___Layer2D_getEliminate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEliminate'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getEliminate();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEliminate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_create00
static int tolua_FsLibFaeris_Layer2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaLayer2D* tolua_ret = (LuaLayer2D*)  LuaLayer2D::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaLayer2D");
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

/* method: onUpdate of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_update00
static int tolua_FsLibFaeris_Layer2D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onDraw of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_draw00
static int tolua_FsLibFaeris_Layer2D_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(render);
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

/* method: onTouchBegin of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchBegin00
static int tolua_FsLibFaeris_Layer2D_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchEnd of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchEnd00
static int tolua_FsLibFaeris_Layer2D_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchMove of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchMove00
static int tolua_FsLibFaeris_Layer2D_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onTouchesBegin of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchesBegin00
static int tolua_FsLibFaeris_Layer2D_touchesBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesBegin'", NULL);
#endif
  {
   self->onTouchesBegin(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesPointerDown of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchesPointerDown00
static int tolua_FsLibFaeris_Layer2D_touchesPointerDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesPointerDown'", NULL);
#endif
  {
   self->onTouchesPointerDown(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesPointerDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesMove of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchesMove00
static int tolua_FsLibFaeris_Layer2D_touchesMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesMove'", NULL);
#endif
  {
   self->onTouchesMove(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesPointerUp of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchesPointerUp00
static int tolua_FsLibFaeris_Layer2D_touchesPointerUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesPointerUp'", NULL);
#endif
  {
   self->onTouchesPointerUp(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesPointerUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchesEnd of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Layer2D_touchesEnd00
static int tolua_FsLibFaeris_Layer2D_touchesEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent* event = ((TouchEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchesEnd'", NULL);
#endif
  {
   self->onTouchesEnd(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScissorArea of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_setScissorArea00
static int tolua_FsLibFaeris_Render_setScissorArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScissorArea'", NULL);
#endif
  {
   self->setScissorArea(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScissorArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScissorEnabled of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_setScissorEnabled00
static int tolua_FsLibFaeris_Render_setScissorEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScissorEnabled'", NULL);
#endif
  {
   self->setScissorEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScissorEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewport of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_setViewport00
static int tolua_FsLibFaeris_Render_setViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewport'", NULL);
#endif
  {
   self->setViewport(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setClearColor of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_setClearColor00
static int tolua_FsLibFaeris_Render_setClearColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClearColor'", NULL);
#endif
  {
   self->setClearColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClearColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProjectionMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_setProjectionMatrix00
static int tolua_FsLibFaeris_Render_setProjectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* mat = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProjectionMatrix'", NULL);
#endif
  {
   self->setProjectionMatrix(mat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_pushMatrix00
static int tolua_FsLibFaeris_Render_pushMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushMatrix'", NULL);
#endif
  {
   self->pushMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: popMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_popMatrix00
static int tolua_FsLibFaeris_Render_popMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popMatrix'", NULL);
#endif
  {
   self->popMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadIdentity of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_loadIdentity00
static int tolua_FsLibFaeris_Render_loadIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadIdentity'", NULL);
#endif
  {
   self->loadIdentity();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_mulMatrix00
static int tolua_FsLibFaeris_Render_mulMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulMatrix'", NULL);
#endif
  {
   self->mulMatrix(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_setMatrix00
static int tolua_FsLibFaeris_Render_setMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMatrix'", NULL);
#endif
  {
   self->setMatrix(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_translate00
static int tolua_FsLibFaeris_Render_translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(*t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_scale00
static int tolua_FsLibFaeris_Render_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(*s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Render_rotate00
static int tolua_FsLibFaeris_Render_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(*v,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_COLOR of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_DEFAULT_COLOR
static int tolua_get_Color_DEFAULT_COLOR(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::DEFAULT_COLOR,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DEFAULT_COLOR of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_DEFAULT_COLOR
static int tolua_set_Color_DEFAULT_COLOR(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::DEFAULT_COLOR = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RED of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_RED
static int tolua_get_Color_RED(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::RED,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: RED of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_RED
static int tolua_set_Color_RED(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::RED = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BLUE of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_BLUE
static int tolua_get_Color_BLUE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::BLUE,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: BLUE of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_BLUE
static int tolua_set_Color_BLUE(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::BLUE = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GREEN of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_GREEN
static int tolua_get_Color_GREEN(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::GREEN,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GREEN of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_GREEN
static int tolua_set_Color_GREEN(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::GREEN = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WHITE of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_WHITE
static int tolua_get_Color_WHITE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::WHITE,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WHITE of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_WHITE
static int tolua_set_Color_WHITE(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::WHITE = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BLACK of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_BLACK
static int tolua_get_Color_BLACK(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::BLACK,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: BLACK of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_BLACK
static int tolua_set_Color_BLACK(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::BLACK = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_r
static int tolua_get_Color_unsigned_r(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_r
static int tolua_set_Color_unsigned_r(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_g
static int tolua_get_Color_unsigned_g(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_g
static int tolua_set_Color_unsigned_g(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_b
static int tolua_get_Color_unsigned_b(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_b
static int tolua_set_Color_unsigned_b(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_a
static int tolua_get_Color_unsigned_a(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_a
static int tolua_set_Color_unsigned_a(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color_new00
static int tolua_FsLibFaeris_Color_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  unsigned char alpha = ((unsigned char)  tolua_tonumber(tolua_S,5,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
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

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color_new00_local
static int tolua_FsLibFaeris_Color_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  unsigned char alpha = ((unsigned char)  tolua_tonumber(tolua_S,5,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
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

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color_new01
static int tolua_FsLibFaeris_Color_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Color_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color_new01_local
static int tolua_FsLibFaeris_Color_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Color_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color_new02
static int tolua_FsLibFaeris_Color_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Color_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color_new02_local
static int tolua_FsLibFaeris_Color_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Color_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color__add00
static int tolua_FsLibFaeris_Color__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  Color right = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->operator+(right);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color__sub00
static int tolua_FsLibFaeris_Color__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  Color right = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->operator-(right);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color__mul00
static int tolua_FsLibFaeris_Color__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->operator*(s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Color__eq00
static int tolua_FsLibFaeris_Color__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  Color right = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(right);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontTTF_create00
static int tolua_FsLibFaeris_FontTTF_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   FontTTF* tolua_ret = (FontTTF*)  FontTTF::create(name,size);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FontTTF");
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

/* method: getHeight of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontTTF_getHeight00
static int tolua_FsLibFaeris_FontTTF_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontTTF* self = (FontTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAscend of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontTTF_getAscend00
static int tolua_FsLibFaeris_FontTTF_getAscend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontTTF* self = (FontTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAscend'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAscend();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAscend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDescend of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontTTF_getDescend00
static int tolua_FsLibFaeris_FontTTF_getDescend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontTTF* self = (FontTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDescend'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDescend();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDescend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Texture2D_getWidth00
static int tolua_FsLibFaeris_Texture2D_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Texture2D_getHeight00
static int tolua_FsLibFaeris_Texture2D_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  FontBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontBitmap_create00
static int tolua_FsLibFaeris_FontBitmap_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FontBitmap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fnt = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   FontBitmap* tolua_ret = (FontBitmap*)  FontBitmap::create(fnt);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FontBitmap");
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

/* method: getHeight of class  FontBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontBitmap_getHeight00
static int tolua_FsLibFaeris_FontBitmap_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontBitmap* self = (FontBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAscent of class  FontBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontBitmap_getAscent00
static int tolua_FsLibFaeris_FontBitmap_getAscent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontBitmap* self = (FontBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAscent'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAscent();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAscent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDescent of class  FontBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontBitmap_getDescent00
static int tolua_FsLibFaeris_FontBitmap_getDescent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontBitmap* self = (FontBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDescent'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDescent();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDescent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureWidth of class  FontBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontBitmap_getTextureWidth00
static int tolua_FsLibFaeris_FontBitmap_getTextureWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontBitmap* self = (FontBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTextureWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureHeight of class  FontBitmap */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_FontBitmap_getTextureHeight00
static int tolua_FsLibFaeris_FontBitmap_getTextureHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontBitmap* self = (FontBitmap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTextureHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_x
static int tolua_get_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_x
static int tolua_set_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_y
static int tolua_get_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_y
static int tolua_set_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_new00
static int tolua_FsLibFaeris_Vector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(fx,fy));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
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

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_new00_local
static int tolua_FsLibFaeris_Vector2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(fx,fy));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
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

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_new01
static int tolua_FsLibFaeris_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_new01_local
static int tolua_FsLibFaeris_Vector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_add00
static int tolua_FsLibFaeris_Vector2_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->add(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_sub00
static int tolua_FsLibFaeris_Vector2_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->sub(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_scale00
static int tolua_FsLibFaeris_Vector2_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float k = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->scale(k);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_dot00
static int tolua_FsLibFaeris_Vector2_dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normal of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_normal00
static int tolua_FsLibFaeris_Vector2_normal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normal'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->normal();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_normalize00
static int tolua_FsLibFaeris_Vector2_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: proj of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_proj00
static int tolua_FsLibFaeris_Vector2_proj00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'proj'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->proj(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'proj'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_angle00
static int tolua_FsLibFaeris_Vector2_angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_length00
static int tolua_FsLibFaeris_Vector2_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length2 of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_length200
static int tolua_FsLibFaeris_Vector2_length200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length2'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length2();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equal of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector2_equal00
static int tolua_FsLibFaeris_Vector2_equal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equal(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_x
static int tolua_get_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_x
static int tolua_set_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_y
static int tolua_get_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_y
static int tolua_set_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_z
static int tolua_get_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_z
static int tolua_set_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_new00
static int tolua_FsLibFaeris_Vector3_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
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

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_new00_local
static int tolua_FsLibFaeris_Vector3_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
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

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_new01
static int tolua_FsLibFaeris_Vector3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_new01_local
static int tolua_FsLibFaeris_Vector3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_add00
static int tolua_FsLibFaeris_Vector3_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->add(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_sub00
static int tolua_FsLibFaeris_Vector3_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->sub(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_scale00
static int tolua_FsLibFaeris_Vector3_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float k = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->scale(k);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_dot00
static int tolua_FsLibFaeris_Vector3_dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_cross00
static int tolua_FsLibFaeris_Vector3_cross00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cross'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->cross(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normal of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_normal00
static int tolua_FsLibFaeris_Vector3_normal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normal'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->normal();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_normalize00
static int tolua_FsLibFaeris_Vector3_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: proj of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_proj00
static int tolua_FsLibFaeris_Vector3_proj00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'proj'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->proj(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'proj'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_angle00
static int tolua_FsLibFaeris_Vector3_angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_length00
static int tolua_FsLibFaeris_Vector3_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length2 of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_length200
static int tolua_FsLibFaeris_Vector3_length200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length2'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length2();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equal of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_equal00
static int tolua_FsLibFaeris_Vector3_equal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equal(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector3_set00
static int tolua_FsLibFaeris_Vector3_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_x
static int tolua_get_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_x
static int tolua_set_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_y
static int tolua_get_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_y
static int tolua_set_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_z
static int tolua_get_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_z
static int tolua_set_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_w
static int tolua_get_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_w
static int tolua_set_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_new00
static int tolua_FsLibFaeris_Vector4_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  float fw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz,fw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
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

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_new00_local
static int tolua_FsLibFaeris_Vector4_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  float fw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz,fw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
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

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_new01
static int tolua_FsLibFaeris_Vector4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_new01_local
static int tolua_FsLibFaeris_Vector4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_new02
static int tolua_FsLibFaeris_Vector4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_new02_local
static int tolua_FsLibFaeris_Vector4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Vector4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_add00
static int tolua_FsLibFaeris_Vector4_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->add(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_sub00
static int tolua_FsLibFaeris_Vector4_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->sub(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_scale00
static int tolua_FsLibFaeris_Vector4_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float k = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->scale(k);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_dot00
static int tolua_FsLibFaeris_Vector4_dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normal of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_normal00
static int tolua_FsLibFaeris_Vector4_normal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normal'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->normal();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_normalize00
static int tolua_FsLibFaeris_Vector4_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_length00
static int tolua_FsLibFaeris_Vector4_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length2 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_length200
static int tolua_FsLibFaeris_Vector4_length200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length2'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length2();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equal of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Vector4_equal00
static int tolua_FsLibFaeris_Vector4_equal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equal(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_new00
static int tolua_FsLibFaeris_Matrix4_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
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

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_new00_local
static int tolua_FsLibFaeris_Matrix4_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
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

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_new01
static int tolua_FsLibFaeris_Matrix4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v[16];
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,2,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_new01_local
static int tolua_FsLibFaeris_Matrix4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v[16];
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,2,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_new02
static int tolua_FsLibFaeris_Matrix4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
  float v30 = ((float)  tolua_tonumber(tolua_S,14,0));
  float v31 = ((float)  tolua_tonumber(tolua_S,15,0));
  float v32 = ((float)  tolua_tonumber(tolua_S,16,0));
  float v33 = ((float)  tolua_tonumber(tolua_S,17,0));
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23,v30,v31,v32,v33));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_new02_local
static int tolua_FsLibFaeris_Matrix4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
  float v30 = ((float)  tolua_tonumber(tolua_S,14,0));
  float v31 = ((float)  tolua_tonumber(tolua_S,15,0));
  float v32 = ((float)  tolua_tonumber(tolua_S,16,0));
  float v33 = ((float)  tolua_tonumber(tolua_S,17,0));
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23,v30,v31,v32,v33));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_add00
static int tolua_FsLibFaeris_Matrix4_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* n = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(*n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_mul00
static int tolua_FsLibFaeris_Matrix4_mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* n = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mul'", NULL);
#endif
  {
   self->mul(*n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScaler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_mulScaler00
static int tolua_FsLibFaeris_Matrix4_mulScaler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulScaler'", NULL);
#endif
  {
   self->mulScaler(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScaler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulVector3 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_mulVector300
static int tolua_FsLibFaeris_Matrix4_mulVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulVector3'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->mulVector3(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulVector4 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_mulVector400
static int tolua_FsLibFaeris_Matrix4_mulVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulVector4'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->mulVector4(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transpose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_transpose00
static int tolua_FsLibFaeris_Matrix4_transpose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'transpose'", NULL);
#endif
  {
   self->transpose();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transpose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTranspose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getTranspose00
static int tolua_FsLibFaeris_Matrix4_getTranspose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  Matrix4* m = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTranspose'", NULL);
#endif
  {
   self->getTranspose(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTranspose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_inverse00
static int tolua_FsLibFaeris_Matrix4_inverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'inverse'", NULL);
#endif
  {
   self->inverse();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInverse of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getInverse00
static int tolua_FsLibFaeris_Matrix4_getInverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  Matrix4* m = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInverse'", NULL);
#endif
  {
   self->getInverse(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDetermiant of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getDetermiant00
static int tolua_FsLibFaeris_Matrix4_getDetermiant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDetermiant'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDetermiant();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDetermiant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeTranslate00
static int tolua_FsLibFaeris_Matrix4_makeTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeTranslate'", NULL);
#endif
  {
   self->makeTranslate(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeTranslate01
static int tolua_FsLibFaeris_Matrix4_makeTranslate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeTranslate'", NULL);
#endif
  {
   self->makeTranslate(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_makeTranslate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateX of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeRotateX00
static int tolua_FsLibFaeris_Matrix4_makeRotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateX'", NULL);
#endif
  {
   self->makeRotateX(theta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeRotateY00
static int tolua_FsLibFaeris_Matrix4_makeRotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateY'", NULL);
#endif
  {
   self->makeRotateY(theta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateZ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeRotateZ00
static int tolua_FsLibFaeris_Matrix4_makeRotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateZ'", NULL);
#endif
  {
   self->makeRotateZ(theta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeRotateAxis00
static int tolua_FsLibFaeris_Matrix4_makeRotateAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateAxis'", NULL);
#endif
  {
   self->makeRotateAxis(*v,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeRotateAxis01
static int tolua_FsLibFaeris_Matrix4_makeRotateAxis01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float angle = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateAxis'", NULL);
#endif
  {
   self->makeRotateAxis(x,y,z,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_makeRotateAxis00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateFromEuler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeRotateFromEuler00
static int tolua_FsLibFaeris_Matrix4_makeRotateFromEuler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  int type = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateFromEuler'", NULL);
#endif
  {
   self->makeRotateFromEuler(x,y,z,type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateFromEuler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateFromEuler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeRotateFromEuler01
static int tolua_FsLibFaeris_Matrix4_makeRotateFromEuler01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  int type = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateFromEuler'", NULL);
#endif
  {
   self->makeRotateFromEuler(*v,type);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_makeRotateFromEuler00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeScale00
static int tolua_FsLibFaeris_Matrix4_makeScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeScale'", NULL);
#endif
  {
   self->makeScale(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeScale01
static int tolua_FsLibFaeris_Matrix4_makeScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeScale'", NULL);
#endif
  {
   self->makeScale(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_makeScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeIdentity of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeIdentity00
static int tolua_FsLibFaeris_Matrix4_makeIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeIdentity'", NULL);
#endif
  {
   self->makeIdentity();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeCompose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeCompose00
static int tolua_FsLibFaeris_Matrix4_makeCompose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* r = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  int r_type = ((int)  tolua_tonumber(tolua_S,4,0));
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeCompose'", NULL);
#endif
  {
   self->makeCompose(*t,*r,r_type,*s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeCompose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeLookAt of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeLookAt00
static int tolua_FsLibFaeris_Matrix4_makeLookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* eye = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* up = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeLookAt'", NULL);
#endif
  {
   self->makeLookAt(*eye,*target,*up);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeLookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFrustum of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeFrustum00
static int tolua_FsLibFaeris_Matrix4_makeFrustum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float right = ((float)  tolua_tonumber(tolua_S,3,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float n = ((float)  tolua_tonumber(tolua_S,6,0));
  float f = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeFrustum'", NULL);
#endif
  {
   self->makeFrustum(left,right,bottom,top,n,f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeFrustum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePerspective of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makePerspective00
static int tolua_FsLibFaeris_Matrix4_makePerspective00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspect = ((float)  tolua_tonumber(tolua_S,3,0));
  float n = ((float)  tolua_tonumber(tolua_S,4,0));
  float f = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makePerspective'", NULL);
#endif
  {
   self->makePerspective(fov,aspect,n,f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makePerspective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeOrthographic of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_makeOrthographic00
static int tolua_FsLibFaeris_Matrix4_makeOrthographic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float right = ((float)  tolua_tonumber(tolua_S,3,0));
  float top = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
  float n = ((float)  tolua_tonumber(tolua_S,6,0));
  float f = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeOrthographic'", NULL);
#endif
  {
   self->makeOrthographic(left,right,top,bottom,n,f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeOrthographic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_setTranslate00
static int tolua_FsLibFaeris_Matrix4_setTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTranslate'", NULL);
#endif
  {
   self->setTranslate(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_setTranslate01
static int tolua_FsLibFaeris_Matrix4_setTranslate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTranslate'", NULL);
#endif
  {
   self->setTranslate(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_setTranslate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationFromEuler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_setRotationFromEuler00
static int tolua_FsLibFaeris_Matrix4_setRotationFromEuler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  int type = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotationFromEuler'", NULL);
#endif
  {
   self->setRotationFromEuler(rx,ry,rz,type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationFromEuler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_setScale00
static int tolua_FsLibFaeris_Matrix4_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(sx,sy,sz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_setScale01
static int tolua_FsLibFaeris_Matrix4_setScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_setScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_translate00
static int tolua_FsLibFaeris_Matrix4_translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float vx = ((float)  tolua_tonumber(tolua_S,2,0));
  float vy = ((float)  tolua_tonumber(tolua_S,3,0));
  float vz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(vx,vy,vz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_translate01
static int tolua_FsLibFaeris_Matrix4_translate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_translate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateX of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_rotateX00
static int tolua_FsLibFaeris_Matrix4_rotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateX'", NULL);
#endif
  {
   self->rotateX(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_rotateY00
static int tolua_FsLibFaeris_Matrix4_rotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateY'", NULL);
#endif
  {
   self->rotateY(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateZ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_rotateZ00
static int tolua_FsLibFaeris_Matrix4_rotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateZ'", NULL);
#endif
  {
   self->rotateZ(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateByAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_rotateByAxis00
static int tolua_FsLibFaeris_Matrix4_rotateByAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float angle = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateByAxis'", NULL);
#endif
  {
   self->rotateByAxis(x,y,z,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateByAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateByAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_rotateByAxis01
static int tolua_FsLibFaeris_Matrix4_rotateByAxis01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateByAxis'", NULL);
#endif
  {
   self->rotateByAxis(*v,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_rotateByAxis00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_scale00
static int tolua_FsLibFaeris_Matrix4_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_scale01
static int tolua_FsLibFaeris_Matrix4_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsLibFaeris_Matrix4_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColumnX of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getColumnX00
static int tolua_FsLibFaeris_Matrix4_getColumnX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColumnX'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getColumnX();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColumnX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColumnY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getColumnY00
static int tolua_FsLibFaeris_Matrix4_getColumnY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColumnY'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getColumnY();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColumnY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColumnZ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getColumnZ00
static int tolua_FsLibFaeris_Matrix4_getColumnZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColumnZ'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getColumnZ();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColumnZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getTranslate00
static int tolua_FsLibFaeris_Matrix4_getTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTranslate'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getTranslate();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Matrix4_getScale00
static int tolua_FsLibFaeris_Matrix4_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getScale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Rect2D_new00
static int tolua_FsLibFaeris_Rect2D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  float _width = ((float)  tolua_tonumber(tolua_S,4,0));
  float _height = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(_x,_y,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
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

/* method: new_local of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Rect2D_new00_local
static int tolua_FsLibFaeris_Rect2D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  float _width = ((float)  tolua_tonumber(tolua_S,4,0));
  float _height = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(_x,_y,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
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

/* method: new of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Rect2D_new01
static int tolua_FsLibFaeris_Rect2D_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* _start = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float _width = ((float)  tolua_tonumber(tolua_S,3,0));
  float _height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(*_start,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Rect2D_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Rect2D_new01_local
static int tolua_FsLibFaeris_Rect2D_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* _start = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float _width = ((float)  tolua_tonumber(tolua_S,3,0));
  float _height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(*_start,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Rect2D_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Rect2D_new02
static int tolua_FsLibFaeris_Rect2D_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Rect2D_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Rect2D_new02_local
static int tolua_FsLibFaeris_Rect2D_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_Rect2D_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Rect2D_set00
static int tolua_FsLibFaeris_Rect2D_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  float _width = ((float)  tolua_tonumber(tolua_S,4,0));
  float _height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(_x,_y,_width,_height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_x
static int tolua_get_Rect2D_x(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_x
static int tolua_set_Rect2D_x(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_y
static int tolua_get_Rect2D_y(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_y
static int tolua_set_Rect2D_y(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_width
static int tolua_get_Rect2D_width(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_width
static int tolua_set_Rect2D_width(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_height
static int tolua_get_Rect2D_height(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_height
static int tolua_set_Rect2D_height(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCaption of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_setCaption00
static int tolua_FsLibFaeris_Window_setCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCaption'", NULL);
#endif
  {
   self->setCaption(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCaption of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_getCaption00
static int tolua_FsLibFaeris_Window_getCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCaption'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getCaption();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_setPosition00
static int tolua_FsLibFaeris_Window_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_setSize00
static int tolua_FsLibFaeris_Window_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  unsigned int width = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int height = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   self->setSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_show00
static int tolua_FsLibFaeris_Window_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_hide00
static int tolua_FsLibFaeris_Window_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   self->hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStyle of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_setStyle00
static int tolua_FsLibFaeris_Window_setStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  long flags = ((long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStyle'", NULL);
#endif
  {
   self->setStyle(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFullScreen of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_setFullScreen00
static int tolua_FsLibFaeris_Window_setFullScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool full = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFullScreen'", NULL);
#endif
  {
   self->setFullScreen(full);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFullScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_getWidth00
static int tolua_FsLibFaeris_Window_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_getHeight00
static int tolua_FsLibFaeris_Window_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosX of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_getPosX00
static int tolua_FsLibFaeris_Window_getPosX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPosX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosY of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Window_getPosY00
static int tolua_FsLibFaeris_Window_getPosY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPosY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openInputTextDialog of class  Sys */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sys_openInputTextDialog00
static int tolua_FsLibFaeris_Sys_openInputTextDialog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Sys",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* msg = ((const char*)  tolua_tostring(tolua_S,3,0));
  int input_mode = ((int)  tolua_tonumber(tolua_S,4,FS_INPUT_MODE_ANY));
  int input_flag = ((int)  tolua_tonumber(tolua_S,5,FS_INPUT_FLAG_SENSITIVE));
  int return_type = ((int)  tolua_tonumber(tolua_S,6,FS_KEYBOARD_RETURN_TYPE_DEFAULT));
  int max_length = ((int)  tolua_tonumber(tolua_S,7,-1));
  {
   Sys::openInputTextDialog(title,msg,input_mode,input_flag,return_type,max_length);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openInputTextDialog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openNetSettingInterface of class  Sys */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Sys_openNetSettingInterface00
static int tolua_FsLibFaeris_Sys_openNetSettingInterface00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Sys",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Sys::openNetSettingInterface();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openNetSettingInterface'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Timer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Timer_new00
static int tolua_FsLibFaeris_Timer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Timer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Timer* tolua_ret = (Timer*)  Mtolua_new((Timer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Timer");
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

/* method: new_local of class  Timer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Timer_new00_local
static int tolua_FsLibFaeris_Timer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Timer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Timer* tolua_ret = (Timer*)  Mtolua_new((Timer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Timer");
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

/* method: reset of class  Timer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Timer_reset00
static int tolua_FsLibFaeris_Timer_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Timer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Timer* self = (Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'", NULL);
#endif
  {
   self->reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: now of class  Timer */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Timer_now00
static int tolua_FsLibFaeris_Timer_now00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Timer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Timer* self = (Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'now'", NULL);
#endif
  {
   float tolua_ret = (float)  self->now();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'now'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaTouchEventListener */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_TouchEventListener_create00
static int tolua_FsLibFaeris_TouchEventListener_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaTouchEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaTouchEventListener* tolua_ret = (LuaTouchEventListener*)  LuaTouchEventListener::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaTouchEventListener");
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

/* method: create of class  LuaSysEventListener */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SysEventListener_create00
static int tolua_FsLibFaeris_SysEventListener_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSysEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaSysEventListener* tolua_ret = (LuaSysEventListener*)  LuaSysEventListener::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaSysEventListener");
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

/* get function: id of class  TouchPoint */
#ifndef TOLUA_DISABLE_tolua_get_TouchPoint_id
static int tolua_get_TouchPoint_id(lua_State* tolua_S)
{
  TouchPoint* self = (TouchPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: id of class  TouchPoint */
#ifndef TOLUA_DISABLE_tolua_set_TouchPoint_id
static int tolua_set_TouchPoint_id(lua_State* tolua_S)
{
  TouchPoint* self = (TouchPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->id = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  TouchPoint */
#ifndef TOLUA_DISABLE_tolua_get_TouchPoint_x
static int tolua_get_TouchPoint_x(lua_State* tolua_S)
{
  TouchPoint* self = (TouchPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  TouchPoint */
#ifndef TOLUA_DISABLE_tolua_set_TouchPoint_x
static int tolua_set_TouchPoint_x(lua_State* tolua_S)
{
  TouchPoint* self = (TouchPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  TouchPoint */
#ifndef TOLUA_DISABLE_tolua_get_TouchPoint_y
static int tolua_get_TouchPoint_y(lua_State* tolua_S)
{
  TouchPoint* self = (TouchPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  TouchPoint */
#ifndef TOLUA_DISABLE_tolua_set_TouchPoint_y
static int tolua_set_TouchPoint_y(lua_State* tolua_S)
{
  TouchPoint* self = (TouchPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoints of class  TouchEvent */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_TouchEvent_getPoints00
static int tolua_FsLibFaeris_TouchEvent_getPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchEvent* self = (TouchEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoints'", NULL);
#endif
  {
   const TouchPoint* tolua_ret = (const TouchPoint*)  self->getPoints();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const TouchPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  TouchEvent */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_TouchEvent_getPoint00
static int tolua_FsLibFaeris_TouchEvent_getPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchEvent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchEvent* self = (TouchEvent*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoint'", NULL);
#endif
  {
   const TouchPoint* tolua_ret = (const TouchPoint*)  self->getPoint(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const TouchPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  TouchEvent */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_TouchEvent__geti00
static int tolua_FsLibFaeris_TouchEvent__geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchEvent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchEvent* self = (TouchEvent*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   const TouchPoint* tolua_ret = (const TouchPoint*)  self->operator[](index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const TouchPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addListener of class  TouchDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_TouchDispatcher_addListener00
static int tolua_FsLibFaeris_TouchDispatcher_addListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchDispatcher* self = (TouchDispatcher*)  tolua_tousertype(tolua_S,1,0);
  TouchEventListener* l = ((TouchEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addListener'", NULL);
#endif
  {
   self->addListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeListener of class  TouchDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_TouchDispatcher_removeListener00
static int tolua_FsLibFaeris_TouchDispatcher_removeListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchDispatcher* self = (TouchDispatcher*)  tolua_tousertype(tolua_S,1,0);
  TouchEventListener* l = ((TouchEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeListener'", NULL);
#endif
  {
   self->removeListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addListener of class  SysDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SysDispatcher_addListener00
static int tolua_FsLibFaeris_SysDispatcher_addListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SysDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SysEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SysDispatcher* self = (SysDispatcher*)  tolua_tousertype(tolua_S,1,0);
  SysEventListener* l = ((SysEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addListener'", NULL);
#endif
  {
   self->addListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeListener of class  SysDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SysDispatcher_removeListener00
static int tolua_FsLibFaeris_SysDispatcher_removeListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SysDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SysEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SysDispatcher* self = (SysDispatcher*)  tolua_tousertype(tolua_S,1,0);
  SysEventListener* l = ((SysEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeListener'", NULL);
#endif
  {
   self->removeListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: keycode of class  KeypadEvent */
#ifndef TOLUA_DISABLE_tolua_get_KeypadEvent_keycode
static int tolua_get_KeypadEvent_keycode(lua_State* tolua_S)
{
  KeypadEvent* self = (KeypadEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'keycode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->keycode);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: keycode of class  KeypadEvent */
#ifndef TOLUA_DISABLE_tolua_set_KeypadEvent_keycode
static int tolua_set_KeypadEvent_keycode(lua_State* tolua_S)
{
  KeypadEvent* self = (KeypadEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'keycode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->keycode = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  KeypadEvent */
#ifndef TOLUA_DISABLE_tolua_get_KeypadEvent_type
static int tolua_get_KeypadEvent_type(lua_State* tolua_S)
{
  KeypadEvent* self = (KeypadEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type of class  KeypadEvent */
#ifndef TOLUA_DISABLE_tolua_set_KeypadEvent_type
static int tolua_set_KeypadEvent_type(lua_State* tolua_S)
{
  KeypadEvent* self = (KeypadEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_Action_create00
static int tolua_FsLibFaeris_Action_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaAction* tolua_ret = (LuaAction*)  LuaAction::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaAction");
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

/* method: create of class  MoveByAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_MoveByAction_create00
static int tolua_FsLibFaeris_MoveByAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoveByAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float time = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   MoveByAction* tolua_ret = (MoveByAction*)  MoveByAction::create(x,y,z,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"MoveByAction");
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

/* method: create of class  MoveByAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_MoveByAction_create01
static int tolua_FsLibFaeris_MoveByAction_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoveByAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float time = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   MoveByAction* tolua_ret = (MoveByAction*)  MoveByAction::create(x,y,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"MoveByAction");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_MoveByAction_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  MoveByAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_MoveByAction_create02
static int tolua_FsLibFaeris_MoveByAction_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoveByAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* pos = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float time = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   MoveByAction* tolua_ret = (MoveByAction*)  MoveByAction::create(*pos,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"MoveByAction");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_MoveByAction_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  MoveToAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_MoveToAction_create00
static int tolua_FsLibFaeris_MoveToAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoveToAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
  float time = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   MoveToAction* tolua_ret = (MoveToAction*)  MoveToAction::create(sx,sy,sz,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"MoveToAction");
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

/* method: create of class  MoveToAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_MoveToAction_create01
static int tolua_FsLibFaeris_MoveToAction_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoveToAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float time = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   MoveToAction* tolua_ret = (MoveToAction*)  MoveToAction::create(sx,sy,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"MoveToAction");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_MoveToAction_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  MoveToAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_MoveToAction_create02
static int tolua_FsLibFaeris_MoveToAction_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoveToAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* pos = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float time = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   MoveToAction* tolua_ret = (MoveToAction*)  MoveToAction::create(*pos,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"MoveToAction");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_MoveToAction_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  PauseAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_PauseAction_create00
static int tolua_FsLibFaeris_PauseAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PauseAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   PauseAction* tolua_ret = (PauseAction*)  PauseAction::create(time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"PauseAction");
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

/* method: create of class  RotateZByAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_RotateZByAction_create00
static int tolua_FsLibFaeris_RotateZByAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RotateZByAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  float time = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   RotateZByAction* tolua_ret = (RotateZByAction*)  RotateZByAction::create(angle,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"RotateZByAction");
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

/* method: create of class  RotateZToAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_RotateZToAction_create00
static int tolua_FsLibFaeris_RotateZToAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RotateZToAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  float time = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   RotateZToAction* tolua_ret = (RotateZToAction*)  RotateZToAction::create(angle,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"RotateZToAction");
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

/* method: create of class  ScaleByAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ScaleByAction_create00
static int tolua_FsLibFaeris_ScaleByAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScaleByAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
  float time = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   ScaleByAction* tolua_ret = (ScaleByAction*)  ScaleByAction::create(sx,sy,sz,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"ScaleByAction");
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

/* method: create of class  ScaleByAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ScaleByAction_create01
static int tolua_FsLibFaeris_ScaleByAction_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScaleByAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float time = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   ScaleByAction* tolua_ret = (ScaleByAction*)  ScaleByAction::create(sx,sy,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"ScaleByAction");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_ScaleByAction_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ScaleToAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ScaleToAction_create00
static int tolua_FsLibFaeris_ScaleToAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScaleToAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
  float time = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   ScaleToAction* tolua_ret = (ScaleToAction*)  ScaleToAction::create(sx,sy,sz,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"ScaleToAction");
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

/* method: create of class  ScaleToAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_ScaleToAction_create01
static int tolua_FsLibFaeris_ScaleToAction_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScaleToAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float time = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   ScaleToAction* tolua_ret = (ScaleToAction*)  ScaleToAction::create(sx,sy,time);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"ScaleToAction");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_ScaleToAction_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  SeqAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SeqAction_create00
static int tolua_FsLibFaeris_SeqAction_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SeqAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SeqAction* tolua_ret = (SeqAction*)  SeqAction::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"SeqAction");
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

/* method: addAction of class  SeqAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SeqAction_addAction00
static int tolua_FsLibFaeris_SeqAction_addAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SeqAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Action",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SeqAction* self = (SeqAction*)  tolua_tousertype(tolua_S,1,0);
  Action* action = ((Action*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAction'", NULL);
#endif
  {
   self->addAction(action);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAction of class  SeqAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SeqAction_removeAction00
static int tolua_FsLibFaeris_SeqAction_removeAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SeqAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Action",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SeqAction* self = (SeqAction*)  tolua_tousertype(tolua_S,1,0);
  Action* action = ((Action*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAction'", NULL);
#endif
  {
   self->removeAction(action);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearAction of class  SeqAction */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_SeqAction_clearAction00
static int tolua_FsLibFaeris_SeqAction_clearAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SeqAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SeqAction* self = (SeqAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearAction'", NULL);
#endif
  {
   self->clearAction();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_create00
static int tolua_FsLibFaeris_AudioEngine_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AudioEngine* tolua_ret = (AudioEngine*)  AudioEngine::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"AudioEngine");
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

/* method: create of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_create01
static int tolua_FsLibFaeris_AudioEngine_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int channel_nu = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   AudioEngine* tolua_ret = (AudioEngine*)  AudioEngine::create(channel_nu);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"AudioEngine");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibFaeris_AudioEngine_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: playBackgroundMusic of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_playBackgroundMusic00
static int tolua_FsLibFaeris_AudioEngine_playBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playBackgroundMusic'", NULL);
#endif
  {
   self->playBackgroundMusic(name,loop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopBackgroundMusic of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_stopBackgroundMusic00
static int tolua_FsLibFaeris_AudioEngine_stopBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopBackgroundMusic'", NULL);
#endif
  {
   self->stopBackgroundMusic();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pauseBackgroundMusic of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_pauseBackgroundMusic00
static int tolua_FsLibFaeris_AudioEngine_pauseBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pauseBackgroundMusic'", NULL);
#endif
  {
   self->pauseBackgroundMusic();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pauseBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resumeBackgroundMusic of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_resumeBackgroundMusic00
static int tolua_FsLibFaeris_AudioEngine_resumeBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resumeBackgroundMusic'", NULL);
#endif
  {
   self->resumeBackgroundMusic();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resumeBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rewindBackgroundMusic of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_rewindBackgroundMusic00
static int tolua_FsLibFaeris_AudioEngine_rewindBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rewindBackgroundMusic'", NULL);
#endif
  {
   self->rewindBackgroundMusic();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rewindBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSound of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_loadSound00
static int tolua_FsLibFaeris_AudioEngine_loadSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSound'", NULL);
#endif
  {
   int tolua_ret = (int)  self->loadSound(name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadSound of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_unloadSound00
static int tolua_FsLibFaeris_AudioEngine_unloadSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadSound'", NULL);
#endif
  {
   int tolua_ret = (int)  self->unloadSound(name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadSounds of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_unloadSounds00
static int tolua_FsLibFaeris_AudioEngine_unloadSounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadSounds'", NULL);
#endif
  {
   int tolua_ret = (int)  self->unloadSounds();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadSounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playSound of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_playSound00
static int tolua_FsLibFaeris_AudioEngine_playSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int loop = ((int)  tolua_tonumber(tolua_S,3,0));
  int priority = ((int)  tolua_tonumber(tolua_S,4,AudioEngine::PRIORITY_MIDDLE));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playSound'", NULL);
#endif
  {
   Channel* tolua_ret = (Channel*)  self->playSound(name,loop,priority);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Channel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pauseChannel of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_pauseChannel00
static int tolua_FsLibFaeris_AudioEngine_pauseChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pauseChannel'", NULL);
#endif
  {
   self->pauseChannel(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pauseChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resumeChannel of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_resumeChannel00
static int tolua_FsLibFaeris_AudioEngine_resumeChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resumeChannel'", NULL);
#endif
  {
   self->resumeChannel(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resumeChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopChannel of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_stopChannel00
static int tolua_FsLibFaeris_AudioEngine_stopChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopChannel'", NULL);
#endif
  {
   self->stopChannel(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setChannelVolume of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_setChannelVolume00
static int tolua_FsLibFaeris_AudioEngine_setChannelVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
  float value = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setChannelVolume'", NULL);
#endif
  {
   self->setChannelVolume(c,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setChannelVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChannelVolume of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_getChannelVolume00
static int tolua_FsLibFaeris_AudioEngine_getChannelVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChannelVolume'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getChannelVolume(c);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChannelVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pauseChannels of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_pauseChannels00
static int tolua_FsLibFaeris_AudioEngine_pauseChannels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pauseChannels'", NULL);
#endif
  {
   self->pauseChannels();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pauseChannels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resumeChannels of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_resumeChannels00
static int tolua_FsLibFaeris_AudioEngine_resumeChannels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resumeChannels'", NULL);
#endif
  {
   self->resumeChannels();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resumeChannels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopChannnels of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_stopChannnels00
static int tolua_FsLibFaeris_AudioEngine_stopChannnels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopChannnels'", NULL);
#endif
  {
   self->stopChannnels();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopChannnels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVolume of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_AudioEngine_setVolume00
static int tolua_FsLibFaeris_AudioEngine_setVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVolume'", NULL);
#endif
  {
   self->setVolume(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpEngine_create00
static int tolua_FsLibFaeris_HttpEngine_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HttpEngine* tolua_ret = (HttpEngine*)  HttpEngine::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"HttpEngine");
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

/* method: send of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpEngine_send00
static int tolua_FsLibFaeris_HttpEngine_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpEngine* self = (HttpEngine*)  tolua_tousertype(tolua_S,1,0);
  LuaHttpRequest* request = ((LuaHttpRequest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'", NULL);
#endif
  {
   self->send(request);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpEngine_clear00
static int tolua_FsLibFaeris_HttpEngine_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpEngine* self = (HttpEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpEngine_stop00
static int tolua_FsLibFaeris_HttpEngine_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpEngine* self = (HttpEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_create00
static int tolua_FsLibFaeris_HttpRequest_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaHttpRequest* tolua_ret = (LuaHttpRequest*)  LuaHttpRequest::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaHttpRequest");
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

/* method: setUrl of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_setUrl00
static int tolua_FsLibFaeris_HttpRequest_setUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUrl'", NULL);
#endif
  {
   self->setUrl(url);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUrl of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_getUrl00
static int tolua_FsLibFaeris_HttpRequest_getUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUrl'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getUrl();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMethod of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_setMethod00
static int tolua_FsLibFaeris_HttpRequest_setMethod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  int method = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMethod'", NULL);
#endif
  {
   self->setMethod(method);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMethod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMethod of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_getMethod00
static int tolua_FsLibFaeris_HttpRequest_getMethod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMethod'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMethod();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMethod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVersion of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_setVersion00
static int tolua_FsLibFaeris_HttpRequest_setVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  int version = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVersion'", NULL);
#endif
  {
   self->setVersion(version);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVersion of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_getVersion00
static int tolua_FsLibFaeris_HttpRequest_getVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersion'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addHeader of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_addHeader00
static int tolua_FsLibFaeris_HttpRequest_addHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* header = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addHeader'", NULL);
#endif
  {
   self->addHeader(header);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeHeader of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_removeHeader00
static int tolua_FsLibFaeris_HttpRequest_removeHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* header = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeHeader'", NULL);
#endif
  {
   self->removeHeader(header);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearHeader of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_clearHeader00
static int tolua_FsLibFaeris_HttpRequest_clearHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearHeader'", NULL);
#endif
  {
   self->clearHeader();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeaderNu of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_getHeaderNu00
static int tolua_FsLibFaeris_HttpRequest_getHeaderNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeaderNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeaderNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeaderNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setData of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibFaeris_HttpRequest_setData00
static int tolua_FsLibFaeris_HttpRequest_setData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setData'", NULL);
#endif
  {
   self->setData(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FsLibFaeris_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"share","Global","",NULL);
  tolua_beginmodule(tolua_S,"share");
   tolua_function(tolua_S,"scheduler",tolua_FsLibFaeris_share_scheduler00);
   tolua_function(tolua_S,"touchDispatcher",tolua_FsLibFaeris_share_touchDispatcher00);
   tolua_function(tolua_S,"director",tolua_FsLibFaeris_share_director00);
   tolua_function(tolua_S,"sysDispatcher",tolua_FsLibFaeris_share_sysDispatcher00);
   tolua_function(tolua_S,"window",tolua_FsLibFaeris_share_window00);
   tolua_function(tolua_S,"render",tolua_FsLibFaeris_share_render00);
   tolua_function(tolua_S,"textureMgr",tolua_FsLibFaeris_share_textureMgr00);
   tolua_function(tolua_S,"sprite2DDataMgr",tolua_FsLibFaeris_share_sprite2DDataMgr00);
   tolua_function(tolua_S,"objectMgr",tolua_FsLibFaeris_share_objectMgr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FsObject","FsObject","",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"FsObject");
   tolua_function(tolua_S,"getObjectNu",tolua_FsLibFaeris_FsObject_getObjectNu00);
   tolua_function(tolua_S,"refCnt",tolua_FsLibFaeris_FsObject_refCnt00);
   tolua_function(tolua_S,"addRef",tolua_FsLibFaeris_FsObject_addRef00);
   tolua_function(tolua_S,"decRef",tolua_FsLibFaeris_FsObject_decRef00);
   tolua_function(tolua_S,"setRefDelete",tolua_FsLibFaeris_FsObject_setRefDelete00);
   tolua_function(tolua_S,"getRefDelete",tolua_FsLibFaeris_FsObject_getRefDelete00);
   tolua_function(tolua_S,"destroy",tolua_FsLibFaeris_FsObject_destroy00);
   tolua_function(tolua_S,"autoDestroy",tolua_FsLibFaeris_FsObject_autoDestroy00);
   tolua_function(tolua_S,"className",tolua_FsLibFaeris_FsObject_className00);
   tolua_variable(tolua_S,"data",tolua_get_FsObject_data,tolua_set_FsObject_data);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"FS_PLATFORM_WIN32",FS_PLATFORM_WIN32);
  tolua_constant(tolua_S,"FS_PLATFORM_LINUX",FS_PLATFORM_LINUX);
  tolua_constant(tolua_S,"FS_PLATFORM_ANDROID",FS_PLATFORM_ANDROID);
  tolua_constant(tolua_S,"FS_PLATFORM_APPLE",FS_PLATFORM_APPLE);
  tolua_constant(tolua_S,"FS_CUR_PLATFORM",FS_CUR_PLATFORM);
  tolua_cclass(tolua_S,"ActionTarget","ActionTarget","FsObject",NULL);
  tolua_beginmodule(tolua_S,"ActionTarget");
   tolua_function(tolua_S,"doAction",tolua_FsLibFaeris_ActionTarget_doAction00);
   tolua_function(tolua_S,"removeAction",tolua_FsLibFaeris_ActionTarget_removeAction00);
   tolua_function(tolua_S,"clearAction",tolua_FsLibFaeris_ActionTarget_clearAction00);
   tolua_function(tolua_S,"stopAction",tolua_FsLibFaeris_ActionTarget_stopAction00);
   tolua_function(tolua_S,"isActionStop",tolua_FsLibFaeris_ActionTarget_isActionStop00);
   tolua_function(tolua_S,"resumeAction",tolua_FsLibFaeris_ActionTarget_resumeAction00);
   tolua_function(tolua_S,"updateAction",tolua_FsLibFaeris_ActionTarget_updateAction00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Entity","Entity","ActionTarget",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Entity");
   tolua_function(tolua_S,"localToWorld",tolua_FsLibFaeris___Entity_localToWorld00);
   tolua_function(tolua_S,"worldToLocal",tolua_FsLibFaeris___Entity_worldToLocal00);
   tolua_function(tolua_S,"addChild",tolua_FsLibFaeris___Entity_addChild00);
   tolua_function(tolua_S,"getParent",tolua_FsLibFaeris___Entity_getParent00);
   tolua_function(tolua_S,"remove",tolua_FsLibFaeris___Entity_remove00);
   tolua_function(tolua_S,"detach",tolua_FsLibFaeris___Entity_detach00);
   tolua_function(tolua_S,"clearChild",tolua_FsLibFaeris___Entity_clearChild00);
   tolua_function(tolua_S,"takeAllChild",tolua_FsLibFaeris___Entity_takeAllChild00);
   tolua_function(tolua_S,"childNu",tolua_FsLibFaeris___Entity_childNu00);
   tolua_function(tolua_S,"getLayer",tolua_FsLibFaeris___Entity_getLayer00);
   tolua_function(tolua_S,"getLocalMatrix",tolua_FsLibFaeris___Entity_getLocalMatrix00);
   tolua_function(tolua_S,"getWorldMatrix",tolua_FsLibFaeris___Entity_getWorldMatrix00);
   tolua_function(tolua_S,"updateLocalMatrix",tolua_FsLibFaeris___Entity_updateLocalMatrix00);
   tolua_function(tolua_S,"updateWorldMatrix",tolua_FsLibFaeris___Entity_updateWorldMatrix00);
   tolua_function(tolua_S,"updateAllWorldMatrix",tolua_FsLibFaeris___Entity_updateAllWorldMatrix00);
   tolua_function(tolua_S,"getPosition",tolua_FsLibFaeris___Entity_getPosition00);
   tolua_function(tolua_S,"getPosition",tolua_FsLibFaeris___Entity_getPosition01);
   tolua_function(tolua_S,"getPositionX",tolua_FsLibFaeris___Entity_getPositionX00);
   tolua_function(tolua_S,"getPositionY",tolua_FsLibFaeris___Entity_getPositionY00);
   tolua_function(tolua_S,"getPositionZ",tolua_FsLibFaeris___Entity_getPositionZ00);
   tolua_function(tolua_S,"getScale",tolua_FsLibFaeris___Entity_getScale00);
   tolua_function(tolua_S,"getScaleX",tolua_FsLibFaeris___Entity_getScaleX00);
   tolua_function(tolua_S,"getScaleY",tolua_FsLibFaeris___Entity_getScaleY00);
   tolua_function(tolua_S,"getScaleZ",tolua_FsLibFaeris___Entity_getScaleZ00);
   tolua_function(tolua_S,"getRotate",tolua_FsLibFaeris___Entity_getRotate00);
   tolua_function(tolua_S,"getRotateX",tolua_FsLibFaeris___Entity_getRotateX00);
   tolua_function(tolua_S,"getRotateY",tolua_FsLibFaeris___Entity_getRotateY00);
   tolua_function(tolua_S,"getRotateZ",tolua_FsLibFaeris___Entity_getRotateZ00);
   tolua_function(tolua_S,"rotate",tolua_FsLibFaeris___Entity_rotate00);
   tolua_function(tolua_S,"rotateX",tolua_FsLibFaeris___Entity_rotateX00);
   tolua_function(tolua_S,"rotateY",tolua_FsLibFaeris___Entity_rotateY00);
   tolua_function(tolua_S,"rotateZ",tolua_FsLibFaeris___Entity_rotateZ00);
   tolua_function(tolua_S,"scale",tolua_FsLibFaeris___Entity_scale00);
   tolua_function(tolua_S,"scaleX",tolua_FsLibFaeris___Entity_scaleX00);
   tolua_function(tolua_S,"scaleY",tolua_FsLibFaeris___Entity_scaleY00);
   tolua_function(tolua_S,"scaleZ",tolua_FsLibFaeris___Entity_scaleZ00);
   tolua_function(tolua_S,"move",tolua_FsLibFaeris___Entity_move00);
   tolua_function(tolua_S,"moveX",tolua_FsLibFaeris___Entity_moveX00);
   tolua_function(tolua_S,"moveY",tolua_FsLibFaeris___Entity_moveY00);
   tolua_function(tolua_S,"moveZ",tolua_FsLibFaeris___Entity_moveZ00);
   tolua_function(tolua_S,"setRotate",tolua_FsLibFaeris___Entity_setRotate00);
   tolua_function(tolua_S,"setRotateX",tolua_FsLibFaeris___Entity_setRotateX00);
   tolua_function(tolua_S,"setRotateY",tolua_FsLibFaeris___Entity_setRotateY00);
   tolua_function(tolua_S,"setRotateZ",tolua_FsLibFaeris___Entity_setRotateZ00);
   tolua_function(tolua_S,"setScale",tolua_FsLibFaeris___Entity_setScale00);
   tolua_function(tolua_S,"setScaleX",tolua_FsLibFaeris___Entity_setScaleX00);
   tolua_function(tolua_S,"setScaleY",tolua_FsLibFaeris___Entity_setScaleY00);
   tolua_function(tolua_S,"setScaleZ",tolua_FsLibFaeris___Entity_setScaleZ00);
   tolua_function(tolua_S,"setPosition",tolua_FsLibFaeris___Entity_setPosition00);
   tolua_function(tolua_S,"setPositionX",tolua_FsLibFaeris___Entity_setPositionX00);
   tolua_function(tolua_S,"setPositionY",tolua_FsLibFaeris___Entity_setPositionY00);
   tolua_function(tolua_S,"setPositionZ",tolua_FsLibFaeris___Entity_setPositionZ00);
   tolua_function(tolua_S,"getPositionInWorld",tolua_FsLibFaeris___Entity_getPositionInWorld00);
   tolua_function(tolua_S,"getPositionInWorld",tolua_FsLibFaeris___Entity_getPositionInWorld01);
   tolua_function(tolua_S,"getZorder",tolua_FsLibFaeris___Entity_getZorder00);
   tolua_function(tolua_S,"setZorder",tolua_FsLibFaeris___Entity_setZorder00);
   tolua_function(tolua_S,"setVisible",tolua_FsLibFaeris___Entity_setVisible00);
   tolua_function(tolua_S,"setChildVisible",tolua_FsLibFaeris___Entity_setChildVisible00);
   tolua_function(tolua_S,"visible",tolua_FsLibFaeris___Entity_visible00);
   tolua_function(tolua_S,"getVisible",tolua_FsLibFaeris___Entity_getVisible00);
   tolua_function(tolua_S,"setVisibles",tolua_FsLibFaeris___Entity_setVisibles00);
   tolua_function(tolua_S,"getVisibles",tolua_FsLibFaeris___Entity_getVisibles00);
   tolua_function(tolua_S,"setDispatchTouchEnabled",tolua_FsLibFaeris___Entity_setDispatchTouchEnabled00);
   tolua_function(tolua_S,"getDispatchTouchEnabled",tolua_FsLibFaeris___Entity_getDispatchTouchEnabled00);
   tolua_function(tolua_S,"setDispatchTouchesEnabled",tolua_FsLibFaeris___Entity_setDispatchTouchesEnabled00);
   tolua_function(tolua_S,"getDispatchTouchesEnabled",tolua_FsLibFaeris___Entity_getDispatchTouchesEnabled00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris___Entity_hit2D00);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris___Entity_draw00);
   tolua_function(tolua_S,"draws",tolua_FsLibFaeris___Entity_draws00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris___Entity_update00);
   tolua_function(tolua_S,"updates",tolua_FsLibFaeris___Entity_updates00);
   tolua_function(tolua_S,"setTouchEnabled",tolua_FsLibFaeris___Entity_setTouchEnabled00);
   tolua_function(tolua_S,"getTouchEnabled",tolua_FsLibFaeris___Entity_getTouchEnabled00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris___Entity_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris___Entity_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris___Entity_touchEnd00);
   tolua_function(tolua_S,"setTouchesEnabled",tolua_FsLibFaeris___Entity_setTouchesEnabled00);
   tolua_function(tolua_S,"getTouchesEnabled",tolua_FsLibFaeris___Entity_getTouchesEnabled00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Entity","LuaEntity","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Entity");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Entity_create00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Entity_update00);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Entity_draw00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Entity_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Entity_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Entity_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_Entity_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__ColorQuad2D","ColorQuad2D","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__ColorQuad2D");
   tolua_constant(tolua_S,"VERTEX_A",ColorQuad2D::VERTEX_A);
   tolua_constant(tolua_S,"VERTEX_B",ColorQuad2D::VERTEX_B);
   tolua_constant(tolua_S,"VERTEX_C",ColorQuad2D::VERTEX_C);
   tolua_constant(tolua_S,"VERTEX_D",ColorQuad2D::VERTEX_D);
   tolua_constant(tolua_S,"VERTEX_ALL",ColorQuad2D::VERTEX_ALL);
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris___ColorQuad2D_setColor00);
   tolua_function(tolua_S,"setRect2D",tolua_FsLibFaeris___ColorQuad2D_setRect2D00);
   tolua_function(tolua_S,"getRect2D",tolua_FsLibFaeris___ColorQuad2D_getRect2D00);
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris___ColorQuad2D_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris___ColorQuad2D_getOpacity00);
   tolua_function(tolua_S,"setAnchor",tolua_FsLibFaeris___ColorQuad2D_setAnchor00);
   tolua_function(tolua_S,"getAnchor",tolua_FsLibFaeris___ColorQuad2D_getAnchor00);
   tolua_function(tolua_S,"setSize",tolua_FsLibFaeris___ColorQuad2D_setSize00);
   tolua_function(tolua_S,"getSize",tolua_FsLibFaeris___ColorQuad2D_getSize00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ColorQuad2D","LuaColorQuad2D","ColorQuad2D",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"ColorQuad2D");
   tolua_constant(tolua_S,"VERTEX_A",LuaColorQuad2D::VERTEX_A);
   tolua_constant(tolua_S,"VERTEX_B",LuaColorQuad2D::VERTEX_B);
   tolua_constant(tolua_S,"VERTEX_C",LuaColorQuad2D::VERTEX_C);
   tolua_constant(tolua_S,"VERTEX_D",LuaColorQuad2D::VERTEX_D);
   tolua_constant(tolua_S,"VERTEX_ALL",LuaColorQuad2D::VERTEX_ALL);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ColorQuad2D_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ColorQuad2D_create01);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ColorQuad2D_create02);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_ColorQuad2D_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_ColorQuad2D_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_ColorQuad2D_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_ColorQuad2D_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_ColorQuad2D_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_ColorQuad2D_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Quad2D","Quad2D","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Quad2D");
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris___Quad2D_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsLibFaeris___Quad2D_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris___Quad2D_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris___Quad2D_getOpacity00);
   tolua_function(tolua_S,"setTexture",tolua_FsLibFaeris___Quad2D_setTexture00);
   tolua_function(tolua_S,"setTexture",tolua_FsLibFaeris___Quad2D_setTexture01);
   tolua_function(tolua_S,"getTexture",tolua_FsLibFaeris___Quad2D_getTexture00);
   tolua_function(tolua_S,"setTextureCoord",tolua_FsLibFaeris___Quad2D_setTextureCoord00);
   tolua_function(tolua_S,"getTextureCoord",tolua_FsLibFaeris___Quad2D_getTextureCoord00);
   tolua_function(tolua_S,"setRect2D",tolua_FsLibFaeris___Quad2D_setRect2D00);
   tolua_function(tolua_S,"getRect2D",tolua_FsLibFaeris___Quad2D_getRect2D00);
   tolua_function(tolua_S,"setWidth",tolua_FsLibFaeris___Quad2D_setWidth00);
   tolua_function(tolua_S,"setHeight",tolua_FsLibFaeris___Quad2D_setHeight00);
   tolua_function(tolua_S,"setSize",tolua_FsLibFaeris___Quad2D_setSize00);
   tolua_function(tolua_S,"getWidth",tolua_FsLibFaeris___Quad2D_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_FsLibFaeris___Quad2D_getHeight00);
   tolua_function(tolua_S,"getSize",tolua_FsLibFaeris___Quad2D_getSize00);
   tolua_function(tolua_S,"setAnchorX",tolua_FsLibFaeris___Quad2D_setAnchorX00);
   tolua_function(tolua_S,"setAnchorY",tolua_FsLibFaeris___Quad2D_setAnchorY00);
   tolua_function(tolua_S,"setAnchor",tolua_FsLibFaeris___Quad2D_setAnchor00);
   tolua_function(tolua_S,"getAnchor",tolua_FsLibFaeris___Quad2D_getAnchor00);
   tolua_function(tolua_S,"getAnchorX",tolua_FsLibFaeris___Quad2D_getAnchorX00);
   tolua_function(tolua_S,"getAnchorY",tolua_FsLibFaeris___Quad2D_getAnchorY00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Quad2D","LuaQuad2D","Quad2D",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Quad2D");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Quad2D_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Quad2D_create01);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Quad2D_create02);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Quad2D_create03);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Quad2D_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Quad2D_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Quad2D_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Quad2D_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Quad2D_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_Quad2D_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__LabelTTF","LabelTTF","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__LabelTTF");
   tolua_function(tolua_S,"setString",tolua_FsLibFaeris___LabelTTF_setString00);
   tolua_function(tolua_S,"getString",tolua_FsLibFaeris___LabelTTF_getString00);
   tolua_function(tolua_S,"setFont",tolua_FsLibFaeris___LabelTTF_setFont00);
   tolua_function(tolua_S,"getFont",tolua_FsLibFaeris___LabelTTF_getFont00);
   tolua_function(tolua_S,"setAlign",tolua_FsLibFaeris___LabelTTF_setAlign00);
   tolua_function(tolua_S,"getAlign",tolua_FsLibFaeris___LabelTTF_getAlign00);
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris___LabelTTF_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsLibFaeris___LabelTTF_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris___LabelTTF_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris___LabelTTF_getOpacity00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LabelTTF","LuaLabelTTF","LabelTTF",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"LabelTTF");
   tolua_constant(tolua_S,"ALIGN_V_CENTER",LuaLabelTTF::ALIGN_V_CENTER);
   tolua_constant(tolua_S,"ALIGN_V_TOP",LuaLabelTTF::ALIGN_V_TOP);
   tolua_constant(tolua_S,"ALIGN_V_BOTTOM",LuaLabelTTF::ALIGN_V_BOTTOM);
   tolua_constant(tolua_S,"ALIGN_H_LEFT",LuaLabelTTF::ALIGN_H_LEFT);
   tolua_constant(tolua_S,"ALIGN_H_RIGHT",LuaLabelTTF::ALIGN_H_RIGHT);
   tolua_constant(tolua_S,"ALIGN_H_CENTER",LuaLabelTTF::ALIGN_H_CENTER);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_LabelTTF_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_LabelTTF_create01);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_LabelTTF_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_LabelTTF_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_LabelTTF_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_LabelTTF_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_LabelTTF_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_LabelTTF_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Sprite2D","Sprite2D","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Sprite2D");
   tolua_constant(tolua_S,"ANIM_LOOP",Sprite2D::ANIM_LOOP);
   tolua_constant(tolua_S,"ANIM_START",Sprite2D::ANIM_START);
   tolua_constant(tolua_S,"ANIM_END",Sprite2D::ANIM_END);
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris___Sprite2D_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsLibFaeris___Sprite2D_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris___Sprite2D_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris___Sprite2D_getOpacity00);
   tolua_function(tolua_S,"setBlendMode",tolua_FsLibFaeris___Sprite2D_setBlendMode00);
   tolua_function(tolua_S,"setAnimation",tolua_FsLibFaeris___Sprite2D_setAnimation00);
   tolua_function(tolua_S,"getAnimation",tolua_FsLibFaeris___Sprite2D_getAnimation00);
   tolua_function(tolua_S,"hasAnimation",tolua_FsLibFaeris___Sprite2D_hasAnimation00);
   tolua_function(tolua_S,"updateAnimation",tolua_FsLibFaeris___Sprite2D_updateAnimation00);
   tolua_function(tolua_S,"playAnimation",tolua_FsLibFaeris___Sprite2D_playAnimation00);
   tolua_function(tolua_S,"startAnimation",tolua_FsLibFaeris___Sprite2D_startAnimation00);
   tolua_function(tolua_S,"stopAnimation",tolua_FsLibFaeris___Sprite2D_stopAnimation00);
   tolua_function(tolua_S,"setAnimationOffset",tolua_FsLibFaeris___Sprite2D_setAnimationOffset00);
   tolua_function(tolua_S,"getAnimationOffset",tolua_FsLibFaeris___Sprite2D_getAnimationOffset00);
   tolua_function(tolua_S,"isAnimationPlaying",tolua_FsLibFaeris___Sprite2D_isAnimationPlaying00);
   tolua_function(tolua_S,"setCurFrame",tolua_FsLibFaeris___Sprite2D_setCurFrame00);
   tolua_function(tolua_S,"getCurFrame",tolua_FsLibFaeris___Sprite2D_getCurFrame00);
   tolua_function(tolua_S,"getTotalFrame",tolua_FsLibFaeris___Sprite2D_getTotalFrame00);
   tolua_function(tolua_S,"getFps",tolua_FsLibFaeris___Sprite2D_getFps00);
   tolua_function(tolua_S,"setFps",tolua_FsLibFaeris___Sprite2D_setFps00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Sprite2D","LuaSprite2D","Sprite2D",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Sprite2D");
   tolua_constant(tolua_S,"ANIM_LOOP",LuaSprite2D::ANIM_LOOP);
   tolua_constant(tolua_S,"ANIM_START",LuaSprite2D::ANIM_START);
   tolua_constant(tolua_S,"ANIM_END",LuaSprite2D::ANIM_END);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Sprite2D_create00);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Sprite2D_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Sprite2D_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Sprite2D_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Sprite2D_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Sprite2D_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_Sprite2D_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__LabelBitmap","LabelBitmap","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__LabelBitmap");
   tolua_function(tolua_S,"setString",tolua_FsLibFaeris___LabelBitmap_setString00);
   tolua_function(tolua_S,"setString",tolua_FsLibFaeris___LabelBitmap_setString01);
   tolua_function(tolua_S,"setString",tolua_FsLibFaeris___LabelBitmap_setString02);
   tolua_function(tolua_S,"getString",tolua_FsLibFaeris___LabelBitmap_getString00);
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris___LabelBitmap_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsLibFaeris___LabelBitmap_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris___LabelBitmap_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris___LabelBitmap_getOpacity00);
   tolua_function(tolua_S,"setAlign",tolua_FsLibFaeris___LabelBitmap_setAlign00);
   tolua_function(tolua_S,"setAlignOffset",tolua_FsLibFaeris___LabelBitmap_setAlignOffset00);
   tolua_function(tolua_S,"getAlign",tolua_FsLibFaeris___LabelBitmap_getAlign00);
   tolua_function(tolua_S,"getAlignOffset",tolua_FsLibFaeris___LabelBitmap_getAlignOffset00);
   tolua_function(tolua_S,"getWidth",tolua_FsLibFaeris___LabelBitmap_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_FsLibFaeris___LabelBitmap_getHeight00);
   tolua_function(tolua_S,"setTextAlign",tolua_FsLibFaeris___LabelBitmap_setTextAlign00);
   tolua_function(tolua_S,"setBounds",tolua_FsLibFaeris___LabelBitmap_setBounds00);
   tolua_function(tolua_S,"getTextAlign",tolua_FsLibFaeris___LabelBitmap_getTextAlign00);
   tolua_function(tolua_S,"getBounds",tolua_FsLibFaeris___LabelBitmap_getBounds00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LabelBitmap","LuaLabelBitmap","LabelBitmap",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"LabelBitmap");
   tolua_constant(tolua_S,"ALIGN_V_TOP",LuaLabelBitmap::ALIGN_V_TOP);
   tolua_constant(tolua_S,"ALIGN_V_CENTER",LuaLabelBitmap::ALIGN_V_CENTER);
   tolua_constant(tolua_S,"ALIGN_V_BOTTOM",LuaLabelBitmap::ALIGN_V_BOTTOM);
   tolua_constant(tolua_S,"ALIGN_V_USER_DEFINE",LuaLabelBitmap::ALIGN_V_USER_DEFINE);
   tolua_constant(tolua_S,"ALIGN_H_LEFT",LuaLabelBitmap::ALIGN_H_LEFT);
   tolua_constant(tolua_S,"ALIGN_H_RIGHT",LuaLabelBitmap::ALIGN_H_RIGHT);
   tolua_constant(tolua_S,"ALIGN_H_CENTER",LuaLabelBitmap::ALIGN_H_CENTER);
   tolua_constant(tolua_S,"ALIGN_H_USER_DEFINE",LuaLabelBitmap::ALIGN_H_USER_DEFINE);
   tolua_constant(tolua_S,"TEXT_ALIGN_LEFT",LuaLabelBitmap::TEXT_ALIGN_LEFT);
   tolua_constant(tolua_S,"TEXT_ALIGN_CENTER",LuaLabelBitmap::TEXT_ALIGN_CENTER);
   tolua_constant(tolua_S,"TEXT_ALIGN_RIGHT",LuaLabelBitmap::TEXT_ALIGN_RIGHT);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_LabelBitmap_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_LabelBitmap_create01);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_LabelBitmap_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_LabelBitmap_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_LabelBitmap_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_LabelBitmap_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_LabelBitmap_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_LabelBitmap_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Particle2DEmitter","Particle2DEmitter","FsObject",NULL);
  tolua_beginmodule(tolua_S,"Particle2DEmitter");
   tolua_constant(tolua_S,"MOVE_FREE",Particle2DEmitter::MOVE_FREE);
   tolua_constant(tolua_S,"MOVE_GROUP",Particle2DEmitter::MOVE_GROUP);
   tolua_constant(tolua_S,"ENV_GRAVITY",Particle2DEmitter::ENV_GRAVITY);
   tolua_constant(tolua_S,"ENV_RADIAL",Particle2DEmitter::ENV_RADIAL);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Particle2DEmitter_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Particle2DEmitter_create01);
   tolua_function(tolua_S,"setDurationTime",tolua_FsLibFaeris_Particle2DEmitter_setDurationTime00);
   tolua_function(tolua_S,"getDurationTime",tolua_FsLibFaeris_Particle2DEmitter_getDurationTime00);
   tolua_function(tolua_S,"setDurationTimeVar",tolua_FsLibFaeris_Particle2DEmitter_setDurationTimeVar00);
   tolua_function(tolua_S,"getDurationTimeVar",tolua_FsLibFaeris_Particle2DEmitter_getDurationTimeVar00);
   tolua_function(tolua_S,"setMaxParticleNu",tolua_FsLibFaeris_Particle2DEmitter_setMaxParticleNu00);
   tolua_function(tolua_S,"getMaxParticleNu",tolua_FsLibFaeris_Particle2DEmitter_getMaxParticleNu00);
   tolua_function(tolua_S,"setEmitSpeed",tolua_FsLibFaeris_Particle2DEmitter_setEmitSpeed00);
   tolua_function(tolua_S,"getEmitSpeed",tolua_FsLibFaeris_Particle2DEmitter_getEmitSpeed00);
   tolua_function(tolua_S,"setLifeTime",tolua_FsLibFaeris_Particle2DEmitter_setLifeTime00);
   tolua_function(tolua_S,"getLifeTime",tolua_FsLibFaeris_Particle2DEmitter_getLifeTime00);
   tolua_function(tolua_S,"setLifeTimeVar",tolua_FsLibFaeris_Particle2DEmitter_setLifeTimeVar00);
   tolua_function(tolua_S,"getLifeTimeVar",tolua_FsLibFaeris_Particle2DEmitter_getLifeTimeVar00);
   tolua_function(tolua_S,"setStartSize",tolua_FsLibFaeris_Particle2DEmitter_setStartSize00);
   tolua_function(tolua_S,"getStartSize",tolua_FsLibFaeris_Particle2DEmitter_getStartSize00);
   tolua_function(tolua_S,"setStartSizeVar",tolua_FsLibFaeris_Particle2DEmitter_setStartSizeVar00);
   tolua_function(tolua_S,"getStartSizeVar",tolua_FsLibFaeris_Particle2DEmitter_getStartSizeVar00);
   tolua_function(tolua_S,"setEndSize",tolua_FsLibFaeris_Particle2DEmitter_setEndSize00);
   tolua_function(tolua_S,"getEndSize",tolua_FsLibFaeris_Particle2DEmitter_getEndSize00);
   tolua_function(tolua_S,"setEndSizeVar",tolua_FsLibFaeris_Particle2DEmitter_setEndSizeVar00);
   tolua_function(tolua_S,"getEndSizeVar",tolua_FsLibFaeris_Particle2DEmitter_getEndSizeVar00);
   tolua_function(tolua_S,"setStartColor",tolua_FsLibFaeris_Particle2DEmitter_setStartColor00);
   tolua_function(tolua_S,"getStartColor",tolua_FsLibFaeris_Particle2DEmitter_getStartColor00);
   tolua_function(tolua_S,"setStartColorVar",tolua_FsLibFaeris_Particle2DEmitter_setStartColorVar00);
   tolua_function(tolua_S,"getStartColorVar",tolua_FsLibFaeris_Particle2DEmitter_getStartColorVar00);
   tolua_function(tolua_S,"setEndColor",tolua_FsLibFaeris_Particle2DEmitter_setEndColor00);
   tolua_function(tolua_S,"getEndColor",tolua_FsLibFaeris_Particle2DEmitter_getEndColor00);
   tolua_function(tolua_S,"setEndColorVar",tolua_FsLibFaeris_Particle2DEmitter_setEndColorVar00);
   tolua_function(tolua_S,"getEndColorVar",tolua_FsLibFaeris_Particle2DEmitter_getEndColorVar00);
   tolua_function(tolua_S,"setAngle",tolua_FsLibFaeris_Particle2DEmitter_setAngle00);
   tolua_function(tolua_S,"getAngle",tolua_FsLibFaeris_Particle2DEmitter_getAngle00);
   tolua_function(tolua_S,"setAngleVar",tolua_FsLibFaeris_Particle2DEmitter_setAngleVar00);
   tolua_function(tolua_S,"getAngleVar",tolua_FsLibFaeris_Particle2DEmitter_getAngleVar00);
   tolua_function(tolua_S,"setStartRotation",tolua_FsLibFaeris_Particle2DEmitter_setStartRotation00);
   tolua_function(tolua_S,"getStartRotation",tolua_FsLibFaeris_Particle2DEmitter_getStartRotation00);
   tolua_function(tolua_S,"setStartRotationVar",tolua_FsLibFaeris_Particle2DEmitter_setStartRotationVar00);
   tolua_function(tolua_S,"getStartRotationVar",tolua_FsLibFaeris_Particle2DEmitter_getStartRotationVar00);
   tolua_function(tolua_S,"setEndRotation",tolua_FsLibFaeris_Particle2DEmitter_setEndRotation00);
   tolua_function(tolua_S,"getEndRotation",tolua_FsLibFaeris_Particle2DEmitter_getEndRotation00);
   tolua_function(tolua_S,"setEndRotationVar",tolua_FsLibFaeris_Particle2DEmitter_setEndRotationVar00);
   tolua_function(tolua_S,"getEndRotationVar",tolua_FsLibFaeris_Particle2DEmitter_getEndRotationVar00);
   tolua_function(tolua_S,"setPosition",tolua_FsLibFaeris_Particle2DEmitter_setPosition00);
   tolua_function(tolua_S,"getPosition",tolua_FsLibFaeris_Particle2DEmitter_getPosition00);
   tolua_function(tolua_S,"setPositionVar",tolua_FsLibFaeris_Particle2DEmitter_setPositionVar00);
   tolua_function(tolua_S,"getPositionVar",tolua_FsLibFaeris_Particle2DEmitter_getPositionVar00);
   tolua_function(tolua_S,"setMoveMode",tolua_FsLibFaeris_Particle2DEmitter_setMoveMode00);
   tolua_function(tolua_S,"getMoveMode",tolua_FsLibFaeris_Particle2DEmitter_getMoveMode00);
   tolua_function(tolua_S,"setBlendSrc",tolua_FsLibFaeris_Particle2DEmitter_setBlendSrc00);
   tolua_function(tolua_S,"getBlendSrc",tolua_FsLibFaeris_Particle2DEmitter_getBlendSrc00);
   tolua_function(tolua_S,"setBlendDst",tolua_FsLibFaeris_Particle2DEmitter_setBlendDst00);
   tolua_function(tolua_S,"getBlendDst",tolua_FsLibFaeris_Particle2DEmitter_getBlendDst00);
   tolua_function(tolua_S,"setTexture",tolua_FsLibFaeris_Particle2DEmitter_setTexture00);
   tolua_function(tolua_S,"getTexture",tolua_FsLibFaeris_Particle2DEmitter_getTexture00);
   tolua_function(tolua_S,"setEnvironmentMode",tolua_FsLibFaeris_Particle2DEmitter_setEnvironmentMode00);
   tolua_function(tolua_S,"getEnvironmentMode",tolua_FsLibFaeris_Particle2DEmitter_getEnvironmentMode00);
   tolua_function(tolua_S,"setSpeed",tolua_FsLibFaeris_Particle2DEmitter_setSpeed00);
   tolua_function(tolua_S,"getSpeed",tolua_FsLibFaeris_Particle2DEmitter_getSpeed00);
   tolua_function(tolua_S,"setSpeedVar",tolua_FsLibFaeris_Particle2DEmitter_setSpeedVar00);
   tolua_function(tolua_S,"getSpeedVar",tolua_FsLibFaeris_Particle2DEmitter_getSpeedVar00);
   tolua_function(tolua_S,"setGravity",tolua_FsLibFaeris_Particle2DEmitter_setGravity00);
   tolua_function(tolua_S,"getGravity",tolua_FsLibFaeris_Particle2DEmitter_getGravity00);
   tolua_function(tolua_S,"setRadialAcceleration",tolua_FsLibFaeris_Particle2DEmitter_setRadialAcceleration00);
   tolua_function(tolua_S,"getRadialAcceleration",tolua_FsLibFaeris_Particle2DEmitter_getRadialAcceleration00);
   tolua_function(tolua_S,"setRadialAccelerationVar",tolua_FsLibFaeris_Particle2DEmitter_setRadialAccelerationVar00);
   tolua_function(tolua_S,"getRadialAccelerationVar",tolua_FsLibFaeris_Particle2DEmitter_getRadialAccelerationVar00);
   tolua_function(tolua_S,"setTangentialAcceleration",tolua_FsLibFaeris_Particle2DEmitter_setTangentialAcceleration00);
   tolua_function(tolua_S,"getTangentialAcceleration",tolua_FsLibFaeris_Particle2DEmitter_getTangentialAcceleration00);
   tolua_function(tolua_S,"setTangentialAccelerationVar",tolua_FsLibFaeris_Particle2DEmitter_setTangentialAccelerationVar00);
   tolua_function(tolua_S,"getTangentialAccelerationVar",tolua_FsLibFaeris_Particle2DEmitter_getTangentialAccelerationVar00);
   tolua_function(tolua_S,"setStartRadius",tolua_FsLibFaeris_Particle2DEmitter_setStartRadius00);
   tolua_function(tolua_S,"getStartRadius",tolua_FsLibFaeris_Particle2DEmitter_getStartRadius00);
   tolua_function(tolua_S,"setStartRadiusVar",tolua_FsLibFaeris_Particle2DEmitter_setStartRadiusVar00);
   tolua_function(tolua_S,"getStartRadiusVar",tolua_FsLibFaeris_Particle2DEmitter_getStartRadiusVar00);
   tolua_function(tolua_S,"setEndRadius",tolua_FsLibFaeris_Particle2DEmitter_setEndRadius00);
   tolua_function(tolua_S,"getEndRadius",tolua_FsLibFaeris_Particle2DEmitter_getEndRadius00);
   tolua_function(tolua_S,"setEndRadiusVar",tolua_FsLibFaeris_Particle2DEmitter_setEndRadiusVar00);
   tolua_function(tolua_S,"getEndRadiusVar",tolua_FsLibFaeris_Particle2DEmitter_getEndRadiusVar00);
   tolua_function(tolua_S,"setRotateSpeed",tolua_FsLibFaeris_Particle2DEmitter_setRotateSpeed00);
   tolua_function(tolua_S,"getRotateSpeed",tolua_FsLibFaeris_Particle2DEmitter_getRotateSpeed00);
   tolua_function(tolua_S,"setRotateSpeedVar",tolua_FsLibFaeris_Particle2DEmitter_setRotateSpeedVar00);
   tolua_function(tolua_S,"getRotateSpeedVar",tolua_FsLibFaeris_Particle2DEmitter_getRotateSpeedVar00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Particle2DEffect","Particle2DEffect","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Particle2DEffect");
   tolua_function(tolua_S,"start",tolua_FsLibFaeris___Particle2DEffect_start00);
   tolua_function(tolua_S,"refresh",tolua_FsLibFaeris___Particle2DEffect_refresh00);
   tolua_function(tolua_S,"stop",tolua_FsLibFaeris___Particle2DEffect_stop00);
   tolua_function(tolua_S,"setPause",tolua_FsLibFaeris___Particle2DEffect_setPause00);
   tolua_function(tolua_S,"isPause",tolua_FsLibFaeris___Particle2DEffect_isPause00);
   tolua_function(tolua_S,"isStop",tolua_FsLibFaeris___Particle2DEffect_isStop00);
   tolua_function(tolua_S,"getLifeTime",tolua_FsLibFaeris___Particle2DEffect_getLifeTime00);
   tolua_function(tolua_S,"getElapseTime",tolua_FsLibFaeris___Particle2DEffect_getElapseTime00);
   tolua_function(tolua_S,"setEmitter",tolua_FsLibFaeris___Particle2DEffect_setEmitter00);
   tolua_function(tolua_S,"getEmitter",tolua_FsLibFaeris___Particle2DEffect_getEmitter00);
   tolua_function(tolua_S,"setAutoRemoveOnStop",tolua_FsLibFaeris___Particle2DEffect_setAutoRemoveOnStop00);
   tolua_function(tolua_S,"getParticleNu",tolua_FsLibFaeris___Particle2DEffect_getParticleNu00);
   tolua_function(tolua_S,"getMaxParticleNu",tolua_FsLibFaeris___Particle2DEffect_getMaxParticleNu00);
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris___Particle2DEffect_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris___Particle2DEffect_getOpacity00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Particle2DEffect","LuaParticle2DEffect","Particle2DEffect",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Particle2DEffect");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Particle2DEffect_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Particle2DEffect_create01);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Particle2DEffect_create02);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Particle2DEffect_create03);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Particle2DEffect_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Particle2DEffect_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Particle2DEffect_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Particle2DEffect_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Particle2DEffect_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_Particle2DEffect_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__VertexPolygon","VertexPolygon","Entity",NULL);
  tolua_beginmodule(tolua_S,"__VertexPolygon");
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris___VertexPolygon_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris___VertexPolygon_getOpacity00);
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris___VertexPolygon_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsLibFaeris___VertexPolygon_getColor00);
   tolua_function(tolua_S,"setVertex",tolua_FsLibFaeris___VertexPolygon_setVertex00);
   tolua_function(tolua_S,"setVertex",tolua_FsLibFaeris___VertexPolygon_setVertex01);
   tolua_function(tolua_S,"setVertex",tolua_FsLibFaeris___VertexPolygon_setVertex02);
   tolua_function(tolua_S,"getVertex",tolua_FsLibFaeris___VertexPolygon_getVertex00);
   tolua_function(tolua_S,"append",tolua_FsLibFaeris___VertexPolygon_append00);
   tolua_function(tolua_S,"append",tolua_FsLibFaeris___VertexPolygon_append01);
   tolua_function(tolua_S,"append",tolua_FsLibFaeris___VertexPolygon_append02);
   tolua_function(tolua_S,"removeVertex",tolua_FsLibFaeris___VertexPolygon_removeVertex00);
   tolua_function(tolua_S,"insertVertex",tolua_FsLibFaeris___VertexPolygon_insertVertex00);
   tolua_function(tolua_S,"insertVertex",tolua_FsLibFaeris___VertexPolygon_insertVertex01);
   tolua_function(tolua_S,"insertVertex",tolua_FsLibFaeris___VertexPolygon_insertVertex02);
   tolua_function(tolua_S,"resize",tolua_FsLibFaeris___VertexPolygon_resize00);
   tolua_function(tolua_S,"getVertexNu",tolua_FsLibFaeris___VertexPolygon_getVertexNu00);
   tolua_function(tolua_S,"setMode",tolua_FsLibFaeris___VertexPolygon_setMode00);
   tolua_function(tolua_S,"getMode",tolua_FsLibFaeris___VertexPolygon_getMode00);
   tolua_function(tolua_S,"setPointSize",tolua_FsLibFaeris___VertexPolygon_setPointSize00);
   tolua_function(tolua_S,"getPointSize",tolua_FsLibFaeris___VertexPolygon_getPointSize00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"VertexPolygon","LuaVertexPolygon","VertexPolygon",NULL);
  tolua_beginmodule(tolua_S,"VertexPolygon");
   tolua_constant(tolua_S,"POINTS",LuaVertexPolygon::POINTS);
   tolua_constant(tolua_S,"LINES",LuaVertexPolygon::LINES);
   tolua_constant(tolua_S,"LINE_STRIP",LuaVertexPolygon::LINE_STRIP);
   tolua_constant(tolua_S,"LINE_LOOP",LuaVertexPolygon::LINE_LOOP);
   tolua_constant(tolua_S,"TRIANGLES",LuaVertexPolygon::TRIANGLES);
   tolua_constant(tolua_S,"TRIANGLE_FAN",LuaVertexPolygon::TRIANGLE_FAN);
   tolua_constant(tolua_S,"TRIANGLE_STRIP",LuaVertexPolygon::TRIANGLE_STRIP);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_VertexPolygon_create00);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_VertexPolygon_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_VertexPolygon_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_VertexPolygon_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_VertexPolygon_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_VertexPolygon_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_VertexPolygon_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Panel","Panel","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Panel");
   tolua_function(tolua_S,"setSize",tolua_FsLibFaeris___Panel_setSize00);
   tolua_function(tolua_S,"getSize",tolua_FsLibFaeris___Panel_getSize00);
   tolua_function(tolua_S,"setAnchor",tolua_FsLibFaeris___Panel_setAnchor00);
   tolua_function(tolua_S,"getAnchor",tolua_FsLibFaeris___Panel_getAnchor00);
   tolua_function(tolua_S,"setScissorEnabled",tolua_FsLibFaeris___Panel_setScissorEnabled00);
   tolua_function(tolua_S,"getScissorEnabled",tolua_FsLibFaeris___Panel_getScissorEnabled00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Panel","LuaPanel","Panel",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Panel");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Panel_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Panel_create01);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Panel_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Panel_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Panel_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Panel_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Panel_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_Panel_hit2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ButtonState","ButtonState","",NULL);
  tolua_beginmodule(tolua_S,"ButtonState");
   tolua_function(tolua_S,"setFlag",tolua_FsLibFaeris_ButtonState_setFlag00);
   tolua_function(tolua_S,"clearFlag",tolua_FsLibFaeris_ButtonState_clearFlag00);
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris_ButtonState_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsLibFaeris_ButtonState_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsLibFaeris_ButtonState_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsLibFaeris_ButtonState_getOpacity00);
   tolua_function(tolua_S,"setTexture",tolua_FsLibFaeris_ButtonState_setTexture00);
   tolua_function(tolua_S,"setTexture",tolua_FsLibFaeris_ButtonState_setTexture01);
   tolua_function(tolua_S,"getTexture",tolua_FsLibFaeris_ButtonState_getTexture00);
   tolua_function(tolua_S,"setSize",tolua_FsLibFaeris_ButtonState_setSize00);
   tolua_function(tolua_S,"getSize",tolua_FsLibFaeris_ButtonState_getSize00);
   tolua_function(tolua_S,"setAnchor",tolua_FsLibFaeris_ButtonState_setAnchor00);
   tolua_function(tolua_S,"getAnchor",tolua_FsLibFaeris_ButtonState_getAnchor00);
   tolua_function(tolua_S,"setPosition",tolua_FsLibFaeris_ButtonState_setPosition00);
   tolua_function(tolua_S,"getPosition",tolua_FsLibFaeris_ButtonState_getPosition00);
   tolua_function(tolua_S,"setRotate",tolua_FsLibFaeris_ButtonState_setRotate00);
   tolua_function(tolua_S,"getRotate",tolua_FsLibFaeris_ButtonState_getRotate00);
   tolua_function(tolua_S,"setScale",tolua_FsLibFaeris_ButtonState_setScale00);
   tolua_function(tolua_S,"getScale",tolua_FsLibFaeris_ButtonState_getScale00);
   tolua_function(tolua_S,"setZorder",tolua_FsLibFaeris_ButtonState_setZorder00);
   tolua_function(tolua_S,"getZorder",tolua_FsLibFaeris_ButtonState_getZorder00);
   tolua_function(tolua_S,"setChild",tolua_FsLibFaeris_ButtonState_setChild00);
   tolua_function(tolua_S,"getChild",tolua_FsLibFaeris_ButtonState_getChild00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Button","Button","Quad2D",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Button");
   tolua_function(tolua_S,"getNormalState",tolua_FsLibFaeris___Button_getNormalState00);
   tolua_function(tolua_S,"getPressState",tolua_FsLibFaeris___Button_getPressState00);
   tolua_function(tolua_S,"setStateNormal",tolua_FsLibFaeris___Button_setStateNormal00);
   tolua_function(tolua_S,"setStatePress",tolua_FsLibFaeris___Button_setStatePress00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Button","LuaButton","Button",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Button");
   tolua_constant(tolua_S,"FLAG_COLOR",LuaButton::FLAG_COLOR);
   tolua_constant(tolua_S,"FLAG_OPACITY",LuaButton::FLAG_OPACITY);
   tolua_constant(tolua_S,"FLAG_TEXTURE",LuaButton::FLAG_TEXTURE);
   tolua_constant(tolua_S,"FLAG_SIZE",LuaButton::FLAG_SIZE);
   tolua_constant(tolua_S,"FLAG_ANCHOR",LuaButton::FLAG_ANCHOR);
   tolua_constant(tolua_S,"FLAG_TRANSLATE",LuaButton::FLAG_TRANSLATE);
   tolua_constant(tolua_S,"FLAG_ROTATE",LuaButton::FLAG_ROTATE);
   tolua_constant(tolua_S,"FLAG_SCALE",LuaButton::FLAG_SCALE);
   tolua_constant(tolua_S,"FLAG_ZORDER",LuaButton::FLAG_ZORDER);
   tolua_constant(tolua_S,"FLAG_CHILDREN",LuaButton::FLAG_CHILDREN);
   tolua_constant(tolua_S,"FLAG_ALL",LuaButton::FLAG_ALL);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Button_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Button_create01);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Button_create02);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Button_draw00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Button_update00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Button_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Button_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Button_touchEnd00);
   tolua_function(tolua_S,"hit2D",tolua_FsLibFaeris_Button_hit2D00);
   tolua_function(tolua_S,"click",tolua_FsLibFaeris_Button_click00);
   tolua_function(tolua_S,"pressDown",tolua_FsLibFaeris_Button_pressDown00);
   tolua_function(tolua_S,"pressMoveIn",tolua_FsLibFaeris_Button_pressMoveIn00);
   tolua_function(tolua_S,"pressMoveOut",tolua_FsLibFaeris_Button_pressMoveOut00);
   tolua_function(tolua_S,"pressUp",tolua_FsLibFaeris_Button_pressUp00);
   tolua_function(tolua_S,"pressCancel",tolua_FsLibFaeris_Button_pressCancel00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Resource","Resource","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Resource");
   tolua_function(tolua_S,"refCnt",tolua_FsLibFaeris_Resource_refCnt00);
   tolua_function(tolua_S,"addRef",tolua_FsLibFaeris_Resource_addRef00);
   tolua_function(tolua_S,"decRef",tolua_FsLibFaeris_Resource_decRef00);
   tolua_function(tolua_S,"setRefDelete",tolua_FsLibFaeris_Resource_setRefDelete00);
   tolua_function(tolua_S,"getRefDelete",tolua_FsLibFaeris_Resource_getRefDelete00);
   tolua_function(tolua_S,"destroy",tolua_FsLibFaeris_Resource_destroy00);
   tolua_function(tolua_S,"autoDestroy",tolua_FsLibFaeris_Resource_autoDestroy00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TextureMgr","TextureMgr","ResourceMgr",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"TextureMgr");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Sprite2DDataMgr","Sprite2DDataMgr","ResourceMgr",NULL);
  tolua_beginmodule(tolua_S,"Sprite2DDataMgr");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ResourceMgr","ResourceMgr","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"ResourceMgr");
   tolua_function(tolua_S,"addSearchPath",tolua_FsLibFaeris_ResourceMgr_addSearchPath00);
   tolua_function(tolua_S,"existSearchPath",tolua_FsLibFaeris_ResourceMgr_existSearchPath00);
   tolua_function(tolua_S,"removeSearchPath",tolua_FsLibFaeris_ResourceMgr_removeSearchPath00);
   tolua_function(tolua_S,"preloadResource",tolua_FsLibFaeris_ResourceMgr_preloadResource00);
   tolua_function(tolua_S,"load",tolua_FsLibFaeris_ResourceMgr_load00);
   tolua_function(tolua_S,"unload",tolua_FsLibFaeris_ResourceMgr_unload00);
   tolua_function(tolua_S,"unloadAll",tolua_FsLibFaeris_ResourceMgr_unloadAll00);
   tolua_function(tolua_S,"getCacheResourceNu",tolua_FsLibFaeris_ResourceMgr_getCacheResourceNu00);
   tolua_function(tolua_S,"remove",tolua_FsLibFaeris_ResourceMgr_remove00);
   tolua_function(tolua_S,"add",tolua_FsLibFaeris_ResourceMgr_add00);
   tolua_function(tolua_S,"dump",tolua_FsLibFaeris_ResourceMgr_dump00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ObjectMgr","ObjectMgr","FsObject",NULL);
  tolua_beginmodule(tolua_S,"ObjectMgr");
   tolua_function(tolua_S,"className",tolua_FsLibFaeris_ObjectMgr_className00);
   tolua_function(tolua_S,"manageObject",tolua_FsLibFaeris_ObjectMgr_manageObject00);
   tolua_function(tolua_S,"unManageObject",tolua_FsLibFaeris_ObjectMgr_unManageObject00);
   tolua_function(tolua_S,"dropObjectData",tolua_FsLibFaeris_ObjectMgr_dropObjectData00);
   tolua_function(tolua_S,"unManageAllObject",tolua_FsLibFaeris_ObjectMgr_unManageAllObject00);
   tolua_function(tolua_S,"getManageObjectNu",tolua_FsLibFaeris_ObjectMgr_getManageObjectNu00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Scheduler","Scheduler","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Scheduler");
   tolua_constant(tolua_S,"HIGHEST",Scheduler::HIGHEST);
   tolua_constant(tolua_S,"HIGH",Scheduler::HIGH);
   tolua_constant(tolua_S,"MIDDLE",Scheduler::MIDDLE);
   tolua_constant(tolua_S,"LOW",Scheduler::LOW);
   tolua_constant(tolua_S,"LOWEST",Scheduler::LOWEST);
   tolua_constant(tolua_S,"PRIORITY_NU",Scheduler::PRIORITY_NU);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Scheduler_create00);
   tolua_function(tolua_S,"className",tolua_FsLibFaeris_Scheduler_className00);
   tolua_function(tolua_S,"start",tolua_FsLibFaeris_Scheduler_start00);
   tolua_function(tolua_S,"stop",tolua_FsLibFaeris_Scheduler_stop00);
   tolua_function(tolua_S,"setFps",tolua_FsLibFaeris_Scheduler_setFps00);
   tolua_function(tolua_S,"mainLoop",tolua_FsLibFaeris_Scheduler_mainLoop00);
   tolua_function(tolua_S,"scheduleWithMiliSecond",tolua_FsLibFaeris_Scheduler_scheduleWithMiliSecond00);
   tolua_function(tolua_S,"add",tolua_FsLibFaeris_Scheduler_add00);
   tolua_function(tolua_S,"remove",tolua_FsLibFaeris_Scheduler_remove00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__SchedulerTarget","SchedulerTarget","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__SchedulerTarget");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SchedulerTarget","LuaSchedulerTarget","SchedulerTarget",NULL);
  tolua_beginmodule(tolua_S,"SchedulerTarget");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_SchedulerTarget_create00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_SchedulerTarget_update00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Scene","Scene","ActionTarget",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Scene");
   tolua_function(tolua_S,"push",tolua_FsLibFaeris___Scene_push00);
   tolua_function(tolua_S,"pop",tolua_FsLibFaeris___Scene_pop00);
   tolua_function(tolua_S,"insert",tolua_FsLibFaeris___Scene_insert00);
   tolua_function(tolua_S,"replace",tolua_FsLibFaeris___Scene_replace00);
   tolua_function(tolua_S,"remove",tolua_FsLibFaeris___Scene_remove00);
   tolua_function(tolua_S,"layerNu",tolua_FsLibFaeris___Scene_layerNu00);
   tolua_function(tolua_S,"getLayerIndex",tolua_FsLibFaeris___Scene_getLayerIndex00);
   tolua_function(tolua_S,"top",tolua_FsLibFaeris___Scene_top00);
   tolua_function(tolua_S,"getLayer",tolua_FsLibFaeris___Scene_getLayer00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Scene","LuaScene","Scene",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Scene");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Scene_create00);
   tolua_function(tolua_S,"enter",tolua_FsLibFaeris_Scene_enter00);
   tolua_function(tolua_S,"exit",tolua_FsLibFaeris_Scene_exit00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Scene_update00);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Scene_draw00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Scene_touchBegin00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Scene_touchEnd00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Scene_touchMove00);
   tolua_function(tolua_S,"touchesBegin",tolua_FsLibFaeris_Scene_touchesBegin00);
   tolua_function(tolua_S,"touchesPointerDown",tolua_FsLibFaeris_Scene_touchesPointerDown00);
   tolua_function(tolua_S,"touchesMove",tolua_FsLibFaeris_Scene_touchesMove00);
   tolua_function(tolua_S,"touchesPointerUp",tolua_FsLibFaeris_Scene_touchesPointerUp00);
   tolua_function(tolua_S,"touchesEnd",tolua_FsLibFaeris_Scene_touchesEnd00);
   tolua_function(tolua_S,"keypadEvent",tolua_FsLibFaeris_Scene_keypadEvent00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Director","Director","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Director");
   tolua_function(tolua_S,"push",tolua_FsLibFaeris_Director_push00);
   tolua_function(tolua_S,"push",tolua_FsLibFaeris_Director_push01);
   tolua_function(tolua_S,"pop",tolua_FsLibFaeris_Director_pop00);
   tolua_function(tolua_S,"run",tolua_FsLibFaeris_Director_run00);
   tolua_function(tolua_S,"current",tolua_FsLibFaeris_Director_current00);
   tolua_function(tolua_S,"pause",tolua_FsLibFaeris_Director_pause00);
   tolua_function(tolua_S,"start",tolua_FsLibFaeris_Director_start00);
   tolua_function(tolua_S,"isRunning",tolua_FsLibFaeris_Director_isRunning00);
   tolua_function(tolua_S,"setAutoSwapBuffers",tolua_FsLibFaeris_Director_setAutoSwapBuffers00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__layer","Layer","ActionTarget",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__layer");
   tolua_function(tolua_S,"getVisible",tolua_FsLibFaeris___layer_getVisible00);
   tolua_function(tolua_S,"visible",tolua_FsLibFaeris___layer_visible00);
   tolua_function(tolua_S,"setVisible",tolua_FsLibFaeris___layer_setVisible00);
   tolua_function(tolua_S,"touchEnabled",tolua_FsLibFaeris___layer_touchEnabled00);
   tolua_function(tolua_S,"setTouchEnabled",tolua_FsLibFaeris___layer_setTouchEnabled00);
   tolua_function(tolua_S,"setTouchesEnabled",tolua_FsLibFaeris___layer_setTouchesEnabled00);
   tolua_function(tolua_S,"getTouchesEnabled",tolua_FsLibFaeris___layer_getTouchesEnabled00);
   tolua_function(tolua_S,"setDispatchTouchEnabled",tolua_FsLibFaeris___layer_setDispatchTouchEnabled00);
   tolua_function(tolua_S,"getDispatchTouchEnabled",tolua_FsLibFaeris___layer_getDispatchTouchEnabled00);
   tolua_function(tolua_S,"setDispatchTouchesEnabled",tolua_FsLibFaeris___layer_setDispatchTouchesEnabled00);
   tolua_function(tolua_S,"getDispatchTouchesEnabled",tolua_FsLibFaeris___layer_getDispatchTouchesEnabled00);
   tolua_function(tolua_S,"setScissorArea",tolua_FsLibFaeris___layer_setScissorArea00);
   tolua_function(tolua_S,"getScissorArea",tolua_FsLibFaeris___layer_getScissorArea00);
   tolua_function(tolua_S,"scissorEnabled",tolua_FsLibFaeris___layer_scissorEnabled00);
   tolua_function(tolua_S,"setScissorEnabled",tolua_FsLibFaeris___layer_setScissorEnabled00);
   tolua_function(tolua_S,"getProjectMatrix",tolua_FsLibFaeris___layer_getProjectMatrix00);
   tolua_function(tolua_S,"toLayerCoord",tolua_FsLibFaeris___layer_toLayerCoord00);
   tolua_function(tolua_S,"add",tolua_FsLibFaeris___layer_add00);
   tolua_function(tolua_S,"remove",tolua_FsLibFaeris___layer_remove00);
   tolua_function(tolua_S,"clearEntity",tolua_FsLibFaeris___layer_clearEntity00);
   tolua_function(tolua_S,"getEntityNu",tolua_FsLibFaeris___layer_getEntityNu00);
   tolua_function(tolua_S,"getScene",tolua_FsLibFaeris___layer_getScene00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__ColorLayer","ColorLayer","Layer",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__ColorLayer");
   tolua_function(tolua_S,"setColor",tolua_FsLibFaeris___ColorLayer_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsLibFaeris___ColorLayer_getColor00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ColorLayer","LuaColorLayer","ColorLayer",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"ColorLayer");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ColorLayer_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ColorLayer_create01);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_ColorLayer_update00);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_ColorLayer_draw00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_ColorLayer_touchBegin00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_ColorLayer_touchEnd00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_ColorLayer_touchMove00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Layer2D","Layer2D","Layer",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Layer2D");
   tolua_function(tolua_S,"getProjectMatrix",tolua_FsLibFaeris___Layer2D_getProjectMatrix00);
   tolua_function(tolua_S,"toLayerCoord",tolua_FsLibFaeris___Layer2D_toLayerCoord00);
   tolua_function(tolua_S,"setViewArea",tolua_FsLibFaeris___Layer2D_setViewArea00);
   tolua_function(tolua_S,"getViewArea",tolua_FsLibFaeris___Layer2D_getViewArea00);
   tolua_function(tolua_S,"setViewArea",tolua_FsLibFaeris___Layer2D_setViewArea01);
   tolua_function(tolua_S,"setSortMode",tolua_FsLibFaeris___Layer2D_setSortMode00);
   tolua_function(tolua_S,"getSortMode",tolua_FsLibFaeris___Layer2D_getSortMode00);
   tolua_function(tolua_S,"setEliminate",tolua_FsLibFaeris___Layer2D_setEliminate00);
   tolua_function(tolua_S,"getEliminate",tolua_FsLibFaeris___Layer2D_getEliminate00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Layer2D","LuaLayer2D","Layer2D",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Layer2D");
   tolua_constant(tolua_S,"SORT_NONE",LuaLayer2D::SORT_NONE);
   tolua_constant(tolua_S,"SORT_ORDER_Z",LuaLayer2D::SORT_ORDER_Z);
   tolua_constant(tolua_S,"SORT_Y",LuaLayer2D::SORT_Y);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Layer2D_create00);
   tolua_function(tolua_S,"update",tolua_FsLibFaeris_Layer2D_update00);
   tolua_function(tolua_S,"draw",tolua_FsLibFaeris_Layer2D_draw00);
   tolua_function(tolua_S,"touchBegin",tolua_FsLibFaeris_Layer2D_touchBegin00);
   tolua_function(tolua_S,"touchEnd",tolua_FsLibFaeris_Layer2D_touchEnd00);
   tolua_function(tolua_S,"touchMove",tolua_FsLibFaeris_Layer2D_touchMove00);
   tolua_function(tolua_S,"touchesBegin",tolua_FsLibFaeris_Layer2D_touchesBegin00);
   tolua_function(tolua_S,"touchesPointerDown",tolua_FsLibFaeris_Layer2D_touchesPointerDown00);
   tolua_function(tolua_S,"touchesMove",tolua_FsLibFaeris_Layer2D_touchesMove00);
   tolua_function(tolua_S,"touchesPointerUp",tolua_FsLibFaeris_Layer2D_touchesPointerUp00);
   tolua_function(tolua_S,"touchesEnd",tolua_FsLibFaeris_Layer2D_touchesEnd00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Render","Render","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Render");
   tolua_constant(tolua_S,"FACTOR_ZERO",Render::FACTOR_ZERO);
   tolua_constant(tolua_S,"FACTOR_ONE",Render::FACTOR_ONE);
   tolua_constant(tolua_S,"FACTOR_SRC_COLOR",Render::FACTOR_SRC_COLOR);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_SRC_COLOR",Render::FACTOR_ONE_MINUS_SRC_COLOR);
   tolua_constant(tolua_S,"FACTOR_DST_COLOR",Render::FACTOR_DST_COLOR);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_DST_COLOR",Render::FACTOR_ONE_MINUS_DST_COLOR);
   tolua_constant(tolua_S,"FACTOR_SRC_ALPHA",Render::FACTOR_SRC_ALPHA);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_SRC_ALPHA",Render::FACTOR_ONE_MINUS_SRC_ALPHA);
   tolua_constant(tolua_S,"FACTOR_DST_ALPHA",Render::FACTOR_DST_ALPHA);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_DST_ALPHA",Render::FACTOR_ONE_MINUS_DST_ALPHA);
   tolua_constant(tolua_S,"FACTOR_SRC_ALPHA_SATURATE",Render::FACTOR_SRC_ALPHA_SATURATE);
   tolua_function(tolua_S,"setScissorArea",tolua_FsLibFaeris_Render_setScissorArea00);
   tolua_function(tolua_S,"setScissorEnabled",tolua_FsLibFaeris_Render_setScissorEnabled00);
   tolua_function(tolua_S,"setViewport",tolua_FsLibFaeris_Render_setViewport00);
   tolua_function(tolua_S,"setClearColor",tolua_FsLibFaeris_Render_setClearColor00);
   tolua_function(tolua_S,"setProjectionMatrix",tolua_FsLibFaeris_Render_setProjectionMatrix00);
   tolua_function(tolua_S,"pushMatrix",tolua_FsLibFaeris_Render_pushMatrix00);
   tolua_function(tolua_S,"popMatrix",tolua_FsLibFaeris_Render_popMatrix00);
   tolua_function(tolua_S,"loadIdentity",tolua_FsLibFaeris_Render_loadIdentity00);
   tolua_function(tolua_S,"mulMatrix",tolua_FsLibFaeris_Render_mulMatrix00);
   tolua_function(tolua_S,"setMatrix",tolua_FsLibFaeris_Render_setMatrix00);
   tolua_function(tolua_S,"translate",tolua_FsLibFaeris_Render_translate00);
   tolua_function(tolua_S,"scale",tolua_FsLibFaeris_Render_scale00);
   tolua_function(tolua_S,"rotate",tolua_FsLibFaeris_Render_rotate00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Color","Color","",tolua_collect_Color);
  #else
  tolua_cclass(tolua_S,"Color","Color","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Color");
   tolua_variable(tolua_S,"DEFAULT_COLOR",tolua_get_Color_DEFAULT_COLOR,tolua_set_Color_DEFAULT_COLOR);
   tolua_variable(tolua_S,"RED",tolua_get_Color_RED,tolua_set_Color_RED);
   tolua_variable(tolua_S,"BLUE",tolua_get_Color_BLUE,tolua_set_Color_BLUE);
   tolua_variable(tolua_S,"GREEN",tolua_get_Color_GREEN,tolua_set_Color_GREEN);
   tolua_variable(tolua_S,"WHITE",tolua_get_Color_WHITE,tolua_set_Color_WHITE);
   tolua_variable(tolua_S,"BLACK",tolua_get_Color_BLACK,tolua_set_Color_BLACK);
   tolua_variable(tolua_S,"r",tolua_get_Color_unsigned_r,tolua_set_Color_unsigned_r);
   tolua_variable(tolua_S,"g",tolua_get_Color_unsigned_g,tolua_set_Color_unsigned_g);
   tolua_variable(tolua_S,"b",tolua_get_Color_unsigned_b,tolua_set_Color_unsigned_b);
   tolua_variable(tolua_S,"a",tolua_get_Color_unsigned_a,tolua_set_Color_unsigned_a);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Color_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Color_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Color_new00_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Color_new01);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Color_new01_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Color_new01_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Color_new02);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Color_new02_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Color_new02_local);
   tolua_function(tolua_S,".add",tolua_FsLibFaeris_Color__add00);
   tolua_function(tolua_S,".sub",tolua_FsLibFaeris_Color__sub00);
   tolua_function(tolua_S,".mul",tolua_FsLibFaeris_Color__mul00);
   tolua_function(tolua_S,".eq",tolua_FsLibFaeris_Color__eq00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FontTTF","FontTTF","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"FontTTF");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_FontTTF_create00);
   tolua_function(tolua_S,"getHeight",tolua_FsLibFaeris_FontTTF_getHeight00);
   tolua_function(tolua_S,"getAscend",tolua_FsLibFaeris_FontTTF_getAscend00);
   tolua_function(tolua_S,"getDescend",tolua_FsLibFaeris_FontTTF_getDescend00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Texture2D","Texture2D","Resource",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Texture2D");
   tolua_function(tolua_S,"getWidth",tolua_FsLibFaeris_Texture2D_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_FsLibFaeris_Texture2D_getHeight00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FontBitmap","FontBitmap","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"FontBitmap");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_FontBitmap_create00);
   tolua_function(tolua_S,"getHeight",tolua_FsLibFaeris_FontBitmap_getHeight00);
   tolua_function(tolua_S,"getAscent",tolua_FsLibFaeris_FontBitmap_getAscent00);
   tolua_function(tolua_S,"getDescent",tolua_FsLibFaeris_FontBitmap_getDescent00);
   tolua_function(tolua_S,"getTextureWidth",tolua_FsLibFaeris_FontBitmap_getTextureWidth00);
   tolua_function(tolua_S,"getTextureHeight",tolua_FsLibFaeris_FontBitmap_getTextureHeight00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector2","Vector2","",tolua_collect_Vector2);
  #else
  tolua_cclass(tolua_S,"Vector2","Vector2","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector2");
   tolua_variable(tolua_S,"x",tolua_get_Vector2_x,tolua_set_Vector2_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector2_y,tolua_set_Vector2_y);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Vector2_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Vector2_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Vector2_new00_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Vector2_new01);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Vector2_new01_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Vector2_new01_local);
   tolua_function(tolua_S,"add",tolua_FsLibFaeris_Vector2_add00);
   tolua_function(tolua_S,"sub",tolua_FsLibFaeris_Vector2_sub00);
   tolua_function(tolua_S,"scale",tolua_FsLibFaeris_Vector2_scale00);
   tolua_function(tolua_S,"dot",tolua_FsLibFaeris_Vector2_dot00);
   tolua_function(tolua_S,"normal",tolua_FsLibFaeris_Vector2_normal00);
   tolua_function(tolua_S,"normalize",tolua_FsLibFaeris_Vector2_normalize00);
   tolua_function(tolua_S,"proj",tolua_FsLibFaeris_Vector2_proj00);
   tolua_function(tolua_S,"angle",tolua_FsLibFaeris_Vector2_angle00);
   tolua_function(tolua_S,"length",tolua_FsLibFaeris_Vector2_length00);
   tolua_function(tolua_S,"length2",tolua_FsLibFaeris_Vector2_length200);
   tolua_function(tolua_S,"equal",tolua_FsLibFaeris_Vector2_equal00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector3","Vector3","",tolua_collect_Vector3);
  #else
  tolua_cclass(tolua_S,"Vector3","Vector3","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector3");
   tolua_variable(tolua_S,"x",tolua_get_Vector3_x,tolua_set_Vector3_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector3_y,tolua_set_Vector3_y);
   tolua_variable(tolua_S,"z",tolua_get_Vector3_z,tolua_set_Vector3_z);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Vector3_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Vector3_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Vector3_new00_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Vector3_new01);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Vector3_new01_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Vector3_new01_local);
   tolua_function(tolua_S,"add",tolua_FsLibFaeris_Vector3_add00);
   tolua_function(tolua_S,"sub",tolua_FsLibFaeris_Vector3_sub00);
   tolua_function(tolua_S,"scale",tolua_FsLibFaeris_Vector3_scale00);
   tolua_function(tolua_S,"dot",tolua_FsLibFaeris_Vector3_dot00);
   tolua_function(tolua_S,"cross",tolua_FsLibFaeris_Vector3_cross00);
   tolua_function(tolua_S,"normal",tolua_FsLibFaeris_Vector3_normal00);
   tolua_function(tolua_S,"normalize",tolua_FsLibFaeris_Vector3_normalize00);
   tolua_function(tolua_S,"proj",tolua_FsLibFaeris_Vector3_proj00);
   tolua_function(tolua_S,"angle",tolua_FsLibFaeris_Vector3_angle00);
   tolua_function(tolua_S,"length",tolua_FsLibFaeris_Vector3_length00);
   tolua_function(tolua_S,"length2",tolua_FsLibFaeris_Vector3_length200);
   tolua_function(tolua_S,"equal",tolua_FsLibFaeris_Vector3_equal00);
   tolua_function(tolua_S,"set",tolua_FsLibFaeris_Vector3_set00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector4","Vector4","",tolua_collect_Vector4);
  #else
  tolua_cclass(tolua_S,"Vector4","Vector4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector4");
   tolua_variable(tolua_S,"x",tolua_get_Vector4_x,tolua_set_Vector4_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector4_y,tolua_set_Vector4_y);
   tolua_variable(tolua_S,"z",tolua_get_Vector4_z,tolua_set_Vector4_z);
   tolua_variable(tolua_S,"w",tolua_get_Vector4_w,tolua_set_Vector4_w);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Vector4_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Vector4_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Vector4_new00_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Vector4_new01);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Vector4_new01_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Vector4_new01_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Vector4_new02);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Vector4_new02_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Vector4_new02_local);
   tolua_function(tolua_S,"add",tolua_FsLibFaeris_Vector4_add00);
   tolua_function(tolua_S,"sub",tolua_FsLibFaeris_Vector4_sub00);
   tolua_function(tolua_S,"scale",tolua_FsLibFaeris_Vector4_scale00);
   tolua_function(tolua_S,"dot",tolua_FsLibFaeris_Vector4_dot00);
   tolua_function(tolua_S,"normal",tolua_FsLibFaeris_Vector4_normal00);
   tolua_function(tolua_S,"normalize",tolua_FsLibFaeris_Vector4_normalize00);
   tolua_function(tolua_S,"length",tolua_FsLibFaeris_Vector4_length00);
   tolua_function(tolua_S,"length2",tolua_FsLibFaeris_Vector4_length200);
   tolua_function(tolua_S,"equal",tolua_FsLibFaeris_Vector4_equal00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Matrix4","Matrix4","",tolua_collect_Matrix4);
  #else
  tolua_cclass(tolua_S,"Matrix4","Matrix4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Matrix4");
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Matrix4_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Matrix4_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Matrix4_new00_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Matrix4_new01);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Matrix4_new01_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Matrix4_new01_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Matrix4_new02);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Matrix4_new02_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Matrix4_new02_local);
   tolua_function(tolua_S,"add",tolua_FsLibFaeris_Matrix4_add00);
   tolua_function(tolua_S,"mul",tolua_FsLibFaeris_Matrix4_mul00);
   tolua_function(tolua_S,"mulScaler",tolua_FsLibFaeris_Matrix4_mulScaler00);
   tolua_function(tolua_S,"mulVector3",tolua_FsLibFaeris_Matrix4_mulVector300);
   tolua_function(tolua_S,"mulVector4",tolua_FsLibFaeris_Matrix4_mulVector400);
   tolua_function(tolua_S,"transpose",tolua_FsLibFaeris_Matrix4_transpose00);
   tolua_function(tolua_S,"getTranspose",tolua_FsLibFaeris_Matrix4_getTranspose00);
   tolua_function(tolua_S,"inverse",tolua_FsLibFaeris_Matrix4_inverse00);
   tolua_function(tolua_S,"getInverse",tolua_FsLibFaeris_Matrix4_getInverse00);
   tolua_function(tolua_S,"getDetermiant",tolua_FsLibFaeris_Matrix4_getDetermiant00);
   tolua_function(tolua_S,"makeTranslate",tolua_FsLibFaeris_Matrix4_makeTranslate00);
   tolua_function(tolua_S,"makeTranslate",tolua_FsLibFaeris_Matrix4_makeTranslate01);
   tolua_function(tolua_S,"makeRotateX",tolua_FsLibFaeris_Matrix4_makeRotateX00);
   tolua_function(tolua_S,"makeRotateY",tolua_FsLibFaeris_Matrix4_makeRotateY00);
   tolua_function(tolua_S,"makeRotateZ",tolua_FsLibFaeris_Matrix4_makeRotateZ00);
   tolua_function(tolua_S,"makeRotateAxis",tolua_FsLibFaeris_Matrix4_makeRotateAxis00);
   tolua_function(tolua_S,"makeRotateAxis",tolua_FsLibFaeris_Matrix4_makeRotateAxis01);
   tolua_function(tolua_S,"makeRotateFromEuler",tolua_FsLibFaeris_Matrix4_makeRotateFromEuler00);
   tolua_function(tolua_S,"makeRotateFromEuler",tolua_FsLibFaeris_Matrix4_makeRotateFromEuler01);
   tolua_function(tolua_S,"makeScale",tolua_FsLibFaeris_Matrix4_makeScale00);
   tolua_function(tolua_S,"makeScale",tolua_FsLibFaeris_Matrix4_makeScale01);
   tolua_function(tolua_S,"makeIdentity",tolua_FsLibFaeris_Matrix4_makeIdentity00);
   tolua_function(tolua_S,"makeCompose",tolua_FsLibFaeris_Matrix4_makeCompose00);
   tolua_function(tolua_S,"makeLookAt",tolua_FsLibFaeris_Matrix4_makeLookAt00);
   tolua_function(tolua_S,"makeFrustum",tolua_FsLibFaeris_Matrix4_makeFrustum00);
   tolua_function(tolua_S,"makePerspective",tolua_FsLibFaeris_Matrix4_makePerspective00);
   tolua_function(tolua_S,"makeOrthographic",tolua_FsLibFaeris_Matrix4_makeOrthographic00);
   tolua_function(tolua_S,"setTranslate",tolua_FsLibFaeris_Matrix4_setTranslate00);
   tolua_function(tolua_S,"setTranslate",tolua_FsLibFaeris_Matrix4_setTranslate01);
   tolua_function(tolua_S,"setRotationFromEuler",tolua_FsLibFaeris_Matrix4_setRotationFromEuler00);
   tolua_function(tolua_S,"setScale",tolua_FsLibFaeris_Matrix4_setScale00);
   tolua_function(tolua_S,"setScale",tolua_FsLibFaeris_Matrix4_setScale01);
   tolua_function(tolua_S,"translate",tolua_FsLibFaeris_Matrix4_translate00);
   tolua_function(tolua_S,"translate",tolua_FsLibFaeris_Matrix4_translate01);
   tolua_function(tolua_S,"rotateX",tolua_FsLibFaeris_Matrix4_rotateX00);
   tolua_function(tolua_S,"rotateY",tolua_FsLibFaeris_Matrix4_rotateY00);
   tolua_function(tolua_S,"rotateZ",tolua_FsLibFaeris_Matrix4_rotateZ00);
   tolua_function(tolua_S,"rotateByAxis",tolua_FsLibFaeris_Matrix4_rotateByAxis00);
   tolua_function(tolua_S,"rotateByAxis",tolua_FsLibFaeris_Matrix4_rotateByAxis01);
   tolua_function(tolua_S,"scale",tolua_FsLibFaeris_Matrix4_scale00);
   tolua_function(tolua_S,"scale",tolua_FsLibFaeris_Matrix4_scale01);
   tolua_function(tolua_S,"getColumnX",tolua_FsLibFaeris_Matrix4_getColumnX00);
   tolua_function(tolua_S,"getColumnY",tolua_FsLibFaeris_Matrix4_getColumnY00);
   tolua_function(tolua_S,"getColumnZ",tolua_FsLibFaeris_Matrix4_getColumnZ00);
   tolua_function(tolua_S,"getTranslate",tolua_FsLibFaeris_Matrix4_getTranslate00);
   tolua_function(tolua_S,"getScale",tolua_FsLibFaeris_Matrix4_getScale00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Rect2D","Rect2D","",tolua_collect_Rect2D);
  #else
  tolua_cclass(tolua_S,"Rect2D","Rect2D","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Rect2D");
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Rect2D_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Rect2D_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Rect2D_new00_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Rect2D_new01);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Rect2D_new01_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Rect2D_new01_local);
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Rect2D_new02);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Rect2D_new02_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Rect2D_new02_local);
   tolua_function(tolua_S,"set",tolua_FsLibFaeris_Rect2D_set00);
   tolua_variable(tolua_S,"x",tolua_get_Rect2D_x,tolua_set_Rect2D_x);
   tolua_variable(tolua_S,"y",tolua_get_Rect2D_y,tolua_set_Rect2D_y);
   tolua_variable(tolua_S,"width",tolua_get_Rect2D_width,tolua_set_Rect2D_width);
   tolua_variable(tolua_S,"height",tolua_get_Rect2D_height,tolua_set_Rect2D_height);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Window","Window","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Window");
   tolua_function(tolua_S,"setCaption",tolua_FsLibFaeris_Window_setCaption00);
   tolua_function(tolua_S,"getCaption",tolua_FsLibFaeris_Window_getCaption00);
   tolua_function(tolua_S,"setPosition",tolua_FsLibFaeris_Window_setPosition00);
   tolua_function(tolua_S,"setSize",tolua_FsLibFaeris_Window_setSize00);
   tolua_function(tolua_S,"show",tolua_FsLibFaeris_Window_show00);
   tolua_function(tolua_S,"hide",tolua_FsLibFaeris_Window_hide00);
   tolua_function(tolua_S,"setStyle",tolua_FsLibFaeris_Window_setStyle00);
   tolua_function(tolua_S,"setFullScreen",tolua_FsLibFaeris_Window_setFullScreen00);
   tolua_function(tolua_S,"getWidth",tolua_FsLibFaeris_Window_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_FsLibFaeris_Window_getHeight00);
   tolua_function(tolua_S,"getPosX",tolua_FsLibFaeris_Window_getPosX00);
   tolua_function(tolua_S,"getPosY",tolua_FsLibFaeris_Window_getPosY00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"KEY_BACKSPACE",KEY_BACKSPACE);
  tolua_constant(tolua_S,"KEY_TAB",KEY_TAB);
  tolua_constant(tolua_S,"KEY_RETURN",KEY_RETURN);
  tolua_constant(tolua_S,"KEY_SHIFT",KEY_SHIFT);
  tolua_constant(tolua_S,"KEY_CONTROL",KEY_CONTROL);
  tolua_constant(tolua_S,"KEY_MENU",KEY_MENU);
  tolua_constant(tolua_S,"KEY_BACK",KEY_BACK);
  tolua_constant(tolua_S,"KEY_ESCAPE",KEY_ESCAPE);
  tolua_constant(tolua_S,"KEY_SPACE",KEY_SPACE);
  tolua_constant(tolua_S,"KEY_LEFT",KEY_LEFT);
  tolua_constant(tolua_S,"KEY_UP",KEY_UP);
  tolua_constant(tolua_S,"KEY_RIGHT",KEY_RIGHT);
  tolua_constant(tolua_S,"KEY_DOWN",KEY_DOWN);
  tolua_constant(tolua_S,"KEY_DELETE",KEY_DELETE);
  tolua_constant(tolua_S,"KEY_0",KEY_0);
  tolua_constant(tolua_S,"KEY_1",KEY_1);
  tolua_constant(tolua_S,"KEY_2",KEY_2);
  tolua_constant(tolua_S,"KEY_3",KEY_3);
  tolua_constant(tolua_S,"KEY_4",KEY_4);
  tolua_constant(tolua_S,"KEY_5",KEY_5);
  tolua_constant(tolua_S,"KEY_6",KEY_6);
  tolua_constant(tolua_S,"KEY_7",KEY_7);
  tolua_constant(tolua_S,"KEY_8",KEY_8);
  tolua_constant(tolua_S,"KEY_9",KEY_9);
  tolua_constant(tolua_S,"KEY_A",KEY_A);
  tolua_constant(tolua_S,"KEY_B",KEY_B);
  tolua_constant(tolua_S,"KEY_C",KEY_C);
  tolua_constant(tolua_S,"KEY_D",KEY_D);
  tolua_constant(tolua_S,"KEY_E",KEY_E);
  tolua_constant(tolua_S,"KEY_F",KEY_F);
  tolua_constant(tolua_S,"KEY_G",KEY_G);
  tolua_constant(tolua_S,"KEY_H",KEY_H);
  tolua_constant(tolua_S,"KEY_I",KEY_I);
  tolua_constant(tolua_S,"KEY_J",KEY_J);
  tolua_constant(tolua_S,"KEY_K",KEY_K);
  tolua_constant(tolua_S,"KEY_L",KEY_L);
  tolua_constant(tolua_S,"KEY_M",KEY_M);
  tolua_constant(tolua_S,"KEY_N",KEY_N);
  tolua_constant(tolua_S,"KEY_O",KEY_O);
  tolua_constant(tolua_S,"KEY_P",KEY_P);
  tolua_constant(tolua_S,"KEY_Q",KEY_Q);
  tolua_constant(tolua_S,"KEY_R",KEY_R);
  tolua_constant(tolua_S,"KEY_S",KEY_S);
  tolua_constant(tolua_S,"KEY_T",KEY_T);
  tolua_constant(tolua_S,"KEY_U",KEY_U);
  tolua_constant(tolua_S,"KEY_V",KEY_V);
  tolua_constant(tolua_S,"KEY_W",KEY_W);
  tolua_constant(tolua_S,"KEY_X",KEY_X);
  tolua_constant(tolua_S,"KEY_Y",KEY_Y);
  tolua_constant(tolua_S,"KEY_Z",KEY_Z);
  tolua_constant(tolua_S,"FS_INPUT_MODE_ANY",FS_INPUT_MODE_ANY);
  tolua_constant(tolua_S,"FS_INPUT_MODE_EMAIL_ADDR",FS_INPUT_MODE_EMAIL_ADDR);
  tolua_constant(tolua_S,"FS_INPUT_MODE_NUMERIC",FS_INPUT_MODE_NUMERIC);
  tolua_constant(tolua_S,"FS_INPUT_MODE_PHONE_NUMBER",FS_INPUT_MODE_PHONE_NUMBER);
  tolua_constant(tolua_S,"FS_INPUT_MODE_URL",FS_INPUT_MODE_URL);
  tolua_constant(tolua_S,"FS_INPUT_MODE_DECIMAL",FS_INPUT_MODE_DECIMAL);
  tolua_constant(tolua_S,"FS_INPUT_MODE_SINGLE_LINE",FS_INPUT_MODE_SINGLE_LINE);
  tolua_constant(tolua_S,"FS_INPUT_FLAG_PASSWORD",FS_INPUT_FLAG_PASSWORD);
  tolua_constant(tolua_S,"FS_INPUT_FLAG_SENSITIVE",FS_INPUT_FLAG_SENSITIVE);
  tolua_constant(tolua_S,"FS_INPUT_FLAG_INITIAL_CAPS_WORD",FS_INPUT_FLAG_INITIAL_CAPS_WORD);
  tolua_constant(tolua_S,"FS_INPUT_FLAG_INITIAL_CAPS_SENTENCE",FS_INPUT_FLAG_INITIAL_CAPS_SENTENCE);
  tolua_constant(tolua_S,"FS_INPUT_FLAG_INITIAL_CAPS_ALL_CHARACTERS",FS_INPUT_FLAG_INITIAL_CAPS_ALL_CHARACTERS);
  tolua_constant(tolua_S,"FS_KEYBOARD_RETURN_TYPE_DEFAULT",FS_KEYBOARD_RETURN_TYPE_DEFAULT);
  tolua_constant(tolua_S,"FS_KEYBOARD_RETURN_TYPE_DONE",FS_KEYBOARD_RETURN_TYPE_DONE);
  tolua_constant(tolua_S,"FS_KEYBOARD_RETURN_TYPE_SEND",FS_KEYBOARD_RETURN_TYPE_SEND);
  tolua_constant(tolua_S,"FS_KEYBOARD_RETURN_TYPE_SEARCH",FS_KEYBOARD_RETURN_TYPE_SEARCH);
  tolua_constant(tolua_S,"FS_KEYBOARD_RETURN_TYPE_GO",FS_KEYBOARD_RETURN_TYPE_GO);
  tolua_cclass(tolua_S,"Sys","Sys","",NULL);
  tolua_beginmodule(tolua_S,"Sys");
   tolua_function(tolua_S,"openInputTextDialog",tolua_FsLibFaeris_Sys_openInputTextDialog00);
   tolua_function(tolua_S,"openNetSettingInterface",tolua_FsLibFaeris_Sys_openNetSettingInterface00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Timer","Timer","",tolua_collect_Timer);
  #else
  tolua_cclass(tolua_S,"Timer","Timer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Timer");
   tolua_function(tolua_S,"new",tolua_FsLibFaeris_Timer_new00);
   tolua_function(tolua_S,"new_local",tolua_FsLibFaeris_Timer_new00_local);
   tolua_function(tolua_S,".call",tolua_FsLibFaeris_Timer_new00_local);
   tolua_function(tolua_S,"reset",tolua_FsLibFaeris_Timer_reset00);
   tolua_function(tolua_S,"now",tolua_FsLibFaeris_Timer_now00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__TouchEventListener","TouchEventListener","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__TouchEventListener");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TouchEventListener","LuaTouchEventListener","TouchEventListener",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"TouchEventListener");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_TouchEventListener_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__SysEventListener","SysEventListener","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__SysEventListener");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SysEventListener","LuaSysEventListener","SysEventListener",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"SysEventListener");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_SysEventListener_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TouchPoint","TouchPoint","",NULL);
  tolua_beginmodule(tolua_S,"TouchPoint");
   tolua_variable(tolua_S,"id",tolua_get_TouchPoint_id,tolua_set_TouchPoint_id);
   tolua_variable(tolua_S,"x",tolua_get_TouchPoint_x,tolua_set_TouchPoint_x);
   tolua_variable(tolua_S,"y",tolua_get_TouchPoint_y,tolua_set_TouchPoint_y);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TouchEvent","TouchEvent","",NULL);
  tolua_beginmodule(tolua_S,"TouchEvent");
   tolua_function(tolua_S,"getPoints",tolua_FsLibFaeris_TouchEvent_getPoints00);
   tolua_function(tolua_S,"getPoint",tolua_FsLibFaeris_TouchEvent_getPoint00);
   tolua_function(tolua_S,".geti",tolua_FsLibFaeris_TouchEvent__geti00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TouchDispatcher","TouchDispatcher","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"TouchDispatcher");
   tolua_function(tolua_S,"addListener",tolua_FsLibFaeris_TouchDispatcher_addListener00);
   tolua_function(tolua_S,"removeListener",tolua_FsLibFaeris_TouchDispatcher_removeListener00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SysDispatcher","SysDispatcher","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"SysDispatcher");
   tolua_function(tolua_S,"addListener",tolua_FsLibFaeris_SysDispatcher_addListener00);
   tolua_function(tolua_S,"removeListener",tolua_FsLibFaeris_SysDispatcher_removeListener00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"KeypadEvent","KeypadEvent","",NULL);
  tolua_beginmodule(tolua_S,"KeypadEvent");
   tolua_constant(tolua_S,"KEYPAD_DOWN",KeypadEvent::KEYPAD_DOWN);
   tolua_constant(tolua_S,"KEYPAD_UP",KeypadEvent::KEYPAD_UP);
   tolua_variable(tolua_S,"keycode",tolua_get_KeypadEvent_keycode,tolua_set_KeypadEvent_keycode);
   tolua_variable(tolua_S,"type",tolua_get_KeypadEvent_type,tolua_set_KeypadEvent_type);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Action","Action","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Action");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Action","LuaAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Action");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_Action_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MoveByAction","MoveByAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"MoveByAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_MoveByAction_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_MoveByAction_create01);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_MoveByAction_create02);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MoveToAction","MoveToAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"MoveToAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_MoveToAction_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_MoveToAction_create01);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_MoveToAction_create02);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"PauseAction","PauseAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"PauseAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_PauseAction_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"RotateZByAction","RotateZByAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"RotateZByAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_RotateZByAction_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"RotateZToAction","RotateZToAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"RotateZToAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_RotateZToAction_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ScaleByAction","ScaleByAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"ScaleByAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ScaleByAction_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ScaleByAction_create01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ScaleToAction","ScaleToAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"ScaleToAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ScaleToAction_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_ScaleToAction_create01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SeqAction","SeqAction","Action",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"SeqAction");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_SeqAction_create00);
   tolua_function(tolua_S,"addAction",tolua_FsLibFaeris_SeqAction_addAction00);
   tolua_function(tolua_S,"removeAction",tolua_FsLibFaeris_SeqAction_removeAction00);
   tolua_function(tolua_S,"clearAction",tolua_FsLibFaeris_SeqAction_clearAction00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"AudioEngine","AudioEngine","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"AudioEngine");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_AudioEngine_create00);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_AudioEngine_create01);
   tolua_function(tolua_S,"playBackgroundMusic",tolua_FsLibFaeris_AudioEngine_playBackgroundMusic00);
   tolua_function(tolua_S,"stopBackgroundMusic",tolua_FsLibFaeris_AudioEngine_stopBackgroundMusic00);
   tolua_function(tolua_S,"pauseBackgroundMusic",tolua_FsLibFaeris_AudioEngine_pauseBackgroundMusic00);
   tolua_function(tolua_S,"resumeBackgroundMusic",tolua_FsLibFaeris_AudioEngine_resumeBackgroundMusic00);
   tolua_function(tolua_S,"rewindBackgroundMusic",tolua_FsLibFaeris_AudioEngine_rewindBackgroundMusic00);
   tolua_function(tolua_S,"loadSound",tolua_FsLibFaeris_AudioEngine_loadSound00);
   tolua_function(tolua_S,"unloadSound",tolua_FsLibFaeris_AudioEngine_unloadSound00);
   tolua_function(tolua_S,"unloadSounds",tolua_FsLibFaeris_AudioEngine_unloadSounds00);
   tolua_function(tolua_S,"playSound",tolua_FsLibFaeris_AudioEngine_playSound00);
   tolua_function(tolua_S,"pauseChannel",tolua_FsLibFaeris_AudioEngine_pauseChannel00);
   tolua_function(tolua_S,"resumeChannel",tolua_FsLibFaeris_AudioEngine_resumeChannel00);
   tolua_function(tolua_S,"stopChannel",tolua_FsLibFaeris_AudioEngine_stopChannel00);
   tolua_function(tolua_S,"setChannelVolume",tolua_FsLibFaeris_AudioEngine_setChannelVolume00);
   tolua_function(tolua_S,"getChannelVolume",tolua_FsLibFaeris_AudioEngine_getChannelVolume00);
   tolua_function(tolua_S,"pauseChannels",tolua_FsLibFaeris_AudioEngine_pauseChannels00);
   tolua_function(tolua_S,"resumeChannels",tolua_FsLibFaeris_AudioEngine_resumeChannels00);
   tolua_function(tolua_S,"stopChannnels",tolua_FsLibFaeris_AudioEngine_stopChannnels00);
   tolua_function(tolua_S,"setVolume",tolua_FsLibFaeris_AudioEngine_setVolume00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"HttpEngine","HttpEngine","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"HttpEngine");
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_HttpEngine_create00);
   tolua_function(tolua_S,"send",tolua_FsLibFaeris_HttpEngine_send00);
   tolua_function(tolua_S,"clear",tolua_FsLibFaeris_HttpEngine_clear00);
   tolua_function(tolua_S,"stop",tolua_FsLibFaeris_HttpEngine_stop00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"HttpRequest","LuaHttpRequest","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"HttpRequest");
   tolua_constant(tolua_S,"VERSION_1_0",LuaHttpRequest::VERSION_1_0);
   tolua_constant(tolua_S,"VERSION_1_1",LuaHttpRequest::VERSION_1_1);
   tolua_constant(tolua_S,"METHOD_GET",LuaHttpRequest::METHOD_GET);
   tolua_constant(tolua_S,"METHOD_POST",LuaHttpRequest::METHOD_POST);
   tolua_function(tolua_S,"create",tolua_FsLibFaeris_HttpRequest_create00);
   tolua_function(tolua_S,"setUrl",tolua_FsLibFaeris_HttpRequest_setUrl00);
   tolua_function(tolua_S,"getUrl",tolua_FsLibFaeris_HttpRequest_getUrl00);
   tolua_function(tolua_S,"setMethod",tolua_FsLibFaeris_HttpRequest_setMethod00);
   tolua_function(tolua_S,"getMethod",tolua_FsLibFaeris_HttpRequest_getMethod00);
   tolua_function(tolua_S,"setVersion",tolua_FsLibFaeris_HttpRequest_setVersion00);
   tolua_function(tolua_S,"getVersion",tolua_FsLibFaeris_HttpRequest_getVersion00);
   tolua_function(tolua_S,"addHeader",tolua_FsLibFaeris_HttpRequest_addHeader00);
   tolua_function(tolua_S,"removeHeader",tolua_FsLibFaeris_HttpRequest_removeHeader00);
   tolua_function(tolua_S,"clearHeader",tolua_FsLibFaeris_HttpRequest_clearHeader00);
   tolua_function(tolua_S,"getHeaderNu",tolua_FsLibFaeris_HttpRequest_getHeaderNu00);
   tolua_function(tolua_S,"setData",tolua_FsLibFaeris_HttpRequest_setData00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsLibFaeris (lua_State* tolua_S) {
 return tolua_FsLibFaeris_open(tolua_S);
};
#endif

