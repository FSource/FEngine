/*************************************************************************/
/*  FsLuaMacros.h                                                        */
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


#ifndef _FS_LUA_MACROS_H_
#define _FS_LUA_MACROS_H_

#include "FsMacros.h"


#define FS_LUA_TOUCH_EVENT_LISTENER_CLASS_NAME  "LuaTouchEventListener"
#define FS_LUA_SYS_EVENT_LISTENER_CLASS_NAME    "LuaSysEventListener"
#define FS_LUA_SCHEDULER_TARGET_CLASS_NAME		"LuaSchedulerTarget"
#define FS_LUA_SCENE_CLASS_NAME                 "LuaScene"
#define FS_LUA_COLOR_LAYER_CLASS_NAME 			"LuaColorLayer"
#define FS_LUA_LAYER2D_CLASS_NAME 				"LuaLayer2D"


/* entity */
#define FS_LUA_ENTITY_CLASS_NAME				"LuaEntity"
#define FS_LUA_COLOR_LAYER_CLASS_NAME			"LuaColorLayer"
#define FS_LUA_COLOR_QUAD2D_CLASS_NAME			"LuaColorQuad2D"
#define FS_LUA_QUAD2D_CLASS_NAME				"LuaQuad2D"
#define FS_LUA_LABEL_TTF_CLASS_NAME 			"LuaLabelTTF"
#define FS_LUA_LABEL_BITMAP_CLASS_NAME  		"LuaLabelBitmap"
#define FS_LUA_SPRITE2D_CLASS_NAME				"LuaSprite2D"
#define FS_LUA_VERTEX_POLYGON_CLASS_NAME		"LuaVertexPolygon"
#define FS_LUA_SPINE_SPRITE_CLASS_NAME			"LuaSpineSprite"
#define FS_LUA_PAYMENT_CLASS_NAME				"LuaPayment"


/* action */
#define FS_LUA_ACTION_CLASS_NAME    		    "LuaAction"
#define FS_LUA_LOOP_ACTION_CLASS_NAME			"LuaLoopAction"
#define FS_LUA_PAUSE_ACTION_CLASS_NAME			"LuaPauseAction"
#define FS_LUA_MOVE_ACTION_CLASS_NAME			"LuaMoveAction"
#define FS_LUA_ROTATE_ACTION_CLASS_NAME				"LuaRotateAction"
#define FS_LUA_SCALE_ACTION_CLASS_NAME				"LuaScaleAction"
#define FS_LUA_SEQ_ACTION_CLASS_NAME				"LuaSeqAction"





#define FS_LUA_HTTP_REQUEST_CLASS_NAME  		"LuaHttpRequest"



#define FS_LUA_PARTICLE2D_EFFECT_CLASS_NAME     "LuaParticle2DEffect"

#define FS_LUA_PANEL_CLASS_NAME					"LuaPanel"

#define FS_LUA_PRESS_BUTTON_CLASS_NAME 			"LuaPressButton"
#define FS_LUA_TOGGLE_BUTTON_CLASS_NAME			"LuaToggleButton"





/* Export Define */

#define FS_EXPORT_LIB_FAERIS

#define FS_EXPORT_LIB_LUA_FUNC 

#define FS_EXPORT_LIB_SPINE_SPRITE

#define FS_EXPORT_LIB_BOX2D

#define FS_EXPORT_LIB_FAERIS_EXT

#endif /*_FS_LUA_MACROS_H_*/




