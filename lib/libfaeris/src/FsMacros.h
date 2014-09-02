#ifndef _FAERIS_MACROS_H_
#define _FAERIS_MACROS_H_
#include <assert.h>
#include "FsConfig.h"

#define FS_BEGIN_NAMESPACE(name) namespace name{
#define FS_END_NAMESPACE(name) }

#define NS_FS_BEGIN FS_BEGIN_NAMESPACE(Faeris)
#define NS_FS_END FS_END_NAMESPACE(Faeris)
#define NS_FS_USE using namespace Faeris;

enum 
{
	FS_PLATFORM_WIN32=1,
	FS_PLATFORM_LINUX=2,
	FS_PLATFORM_ANDROID=3,
	FS_PLATFORM_APPLE=4,
};


#if defined(WIN32)
	#define FS_OS_WIN32
	#define FS_CUR_PLATFORM  FS_PLATFORM_WIN32

#elif defined(LINUX)
	#define FS_OS_LINUX
	#define FS_CUR_PLATFORM FS_PLATFORM_LINUX

#elif defined(ANDROID)
	#define FS_OS_ANDROID
	#define FS_CUR_PLATFORM FS_PLATFORM_ANDROID

#else
	#error "UNKOWN PLATFORM OS"
#endif





#define FS_PLATFORM_OS defined


#ifndef NULL
	#define NULL 0
#endif 


#if defined(FS_OS_WIN32)
#define snprintf _snprintf
#endif 

namespace Faeris
{
	void FsUtil_TagLog(const char* tag,const char* msg,...);
	void FsUtil_Log(const char* fmt,...);
}

#define FS_LOG_TAG Faeris::FsUtil_TagLog
#define FS_LOG Faeris::FsUtil_Log




#define FS_CONDTION_ON(tag,cnd,fmt,...) \
	do{\
		if(cnd) \
		{ \
			FS_LOG_TAG(#tag,"%s:%s:%d:%s:"#fmt,__FILE__,__FUNCTION__,__LINE__,#cnd,##__VA_ARGS__); \
		}\
	} while(0)


#define FS_MESSAGE(tag,fmt,...) \
	do{\
		FS_LOG_TAG(#tag,"%s:%s:%d:"#fmt,__FILE__,__FUNCTION__,__LINE__,##__VA_ARGS__); \
    } while(0)

#define FS_TRACE_WARN_ON(cnd,fmt,...) \
	FS_CONDTION_ON(WARN_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_TRACE_ERROR_ON(cnd,fmt,...) \
	FS_CONDTION_ON(ERROR_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_TRACE_INFO_ON(cnd,fmt,...) \
	FS_CONDTION_ON(INFO_ON,cnd,fmt,##__VA_ARGS__) 


#define FS_TRACE_WARN(fmt,...) \
	FS_MESSAGE(WARN,fmt,##__VA_ARGS__)

#define FS_TRACE_ERROR(fmt,...) \
	FS_MESSAGE(ERROR,fmt,##__VA_ARGS__)

#define FS_TRACE_INFO(fmt,...) \
	FS_MESSAGE(INFO,fmt,##__VA_ARGS__)


#define FS_ASSERT(condtion) \
	assert(condtion)


#define FS_UNUSED_PARAM(x) (void)x


/* copy able */
#define FS_FEATURE public

#define FS_FEATURE_NEW_OBJECT(v) v 
#define FS_FEATURE_WEAK_REF(v) v


#define FS_MAKE_NO_COPYABLE(class_name) \
	private: \
    class_name& operator&(class_name& /*other*/){return *this;} \
    class_name& operator=(class_name& /*other*/){return *this;}




/* for safe add and dec object refrence */

#define FS_SAFE_ADD_REF(f) \
	do{ if(f) (f)->addRef(); }while(0)

#define FS_SAFE_DEC_REF(f) \
	do{ if(f) (f)->decRef();} while(0)

#define FS_DESTROY(f) \
	do{(f)->destroy();}while(0)

#define FS_SAFE_DESTROY(f) \
	do{ if(f) (f)->destroy();}while(0) 

#define FS_NO_REF_DESTROY(f) \
	do{ if(f) (f)->setRefDelete(false);}while(0)


#define FS_SAFE_ASSIGN(d,s) \
	do{ \
		FS_SAFE_ADD_REF(s); \
		FS_SAFE_DEC_REF(d); \
		d=s; \
	}while(0)

#define FS_SAFE_DELETE(v) \
	do{ if(v){ delete (v);} } while(0)

#define FS_DELETE(v) \
	do{ delete (v);}while(0)

#define FS_SAFE_DELETES(v) \
	do{if(v) {delete[] (v);}} while(0)

#define FS_DELETES(v) \
	do{delete[] v;}while(0)

/* global Macros For Faeris */

/* event part*/




#define FS_MASK_LSHIFT (0x1ul<<0)
#define FS_MASK_RSHIFT (0x1ul<<1)
#define FS_MASK_SHIFT (FS_MASK_LSHIFT|FS_MASK_RSHIFT)
#define FS_MASK_LALT (0x1ul<<2)
#define FS_MASK_RALT (0x1ul<<3)
#define FS_MASK_ALT (FS_MASK_LALT|FS_MASK_RALT)
#define FS_MASK_LCTRL (0x1ul<<4)
#define FS_MASK_RCTRL (0x1ul<<5)
#define FS_MASK_CTRL (FS_MASK_LCTRL|FS_MASK_RCTRL)
#define FS_MASK_LBUTTON (0x1ul<<6) 
#define FS_MASK_MBUTTON (0x1ul<<7)
#define FS_MASK_RBUTTON (0x1ul<<8)




#define FS_LBUTTON (0x1ul<<6)
#define FS_RBUTTON (0x1ul<<7)
#define FS_MBUTTON (0x1ul<<8)

#define FS_DOWN 0x1 
#define FS_UP 0x2 
#define FS_CLICK 0x3 
#define FS_DCLICK 0x4
#define FS_MOVE 0x5


/* Frame Buffer */
#define FS_BUFFER_LEFT
#define FS_BUFFER_RIGHT
#define FS_BUFFER_FRONT
#define FS_BUFFER_BACK
#define FS_BUFFER_SINGLE 
#define FS_BUFFER_DOUBLE 
#define FS_BUFFER_STENCIL
#define FS_BUFFER_SAMPLES 
#define FS_BUFFER_DEPTH
#define FS_BUFFER_RGB 
#define FS_BUFFER_RGBA



/* EULER  OLDER */
enum 
{
	FS_EULER_XYZ =0,
	FS_EULER_XZY ,
	FS_EULER_YXZ ,
	FS_EULER_YZX ,
	FS_EULER_ZXY ,
	FS_EULER_ZYX 
};


/* TEXT ALIGN */

enum 
{
	FS_ALIGN_V_CENTER,
	FS_ALIGN_V_TOP,
	FS_ALIGN_V_BUTTON,

	FS_ALIGN_H_LEFT,
	FS_ALIGN_H_RIGHT,
	FS_ALIGN_H_CENTER,
};

enum 
{
	FS_TEXT_ALIGN_LEFT,
	FS_TEXT_ALIGN_CENTER,
	FS_TEXT_ALIGN_RIGHT,
};



/* file type */
#define FS_FILE_UNKOWN (0x1)
#define FS_FILE_BINARY (0x2)
#define FS_FILE_SCRIPT (0x3)


enum 
{
	FS_FLOAT=0,
	FS_INT,

	FS_INT8,
	FS_INT16,
	FS_INT32,

	FS_UINT8,
	FS_UINT16,
	FS_UINT32,

	FS_MAX_TYPE_NU,
};


/* file type */
enum 
{
	FS_FTYPE_SCRIPT,
	FS_FTYPE_BINARY
};


/* bound type */
enum 
{
	FS_BOUND_BOX,
	FS_BOUND_SPHERE
};

/* window name */
#define FS_DEFAULT_WINDOW_NAME "FaerisEngine"


/* class name */


/* stage */
#define FS_ACTION_TARGET_CLASS_NAME "ActionTarget"


/* entity */
#define FS_ENTITY_CLASS_NAME "Entity"
#define FS_COLOR_QUAD2D_CLASS_NAME "ColorQuad2D"
#define FS_QUAD2D_CLASS_NAME   "Quad2D"
#define FS_LABEL_TTF_CLASS_NAME "LabelTTF"
#define FS_SPRITE2D_ANIMATION_CLASS_NAME "Sprite2DAnimation"
#define FS_SPRITE2D_DATA_CLASS_NAME "Sprite2DData"
#define FS_SPRITE2D_CLASS_NAME "Sprite2D"
#define FS_LABEL_BITMAP_CLASS_NAME "LabelBitmap"
#define FS_PARTICLE2D_EMITTER_CLASS_NAME "Particle2DEmitter"
#define FS_PARTICLE2D_EFFECT_CLASS_NAME   "Particle2DEffect"
#define FS_VERTEX_POLYGON_CLASS_NAME "VertexPolygon"
#define FS_PANEL_CLASS_NAME "Panel"

/* ui */
#define FS_PRESS_BUTTON_CLASS_NAME "PressButton"
#define FS_UI_WIDGET_CLASS_NAME  "UiWidget"
#define FS_SCROLL_WIDGET_CLASS_NAME "ScrollWidget"


/* scene */
#define FS_DIRECTOR_CLASS_NAME "Director"
#define FS_SCENE_CLASS_NAME "Scene"
#define FS_LAYER_CLASS_NAME "Layer"
#define FS_COLOR_LAYER_CLASS_NAME "ColorLayer"
#define FS_LAYER_2D_CLASS_NAME "Layer2D"


/* util */
#define FS_ARRAY_CLASS_NAME "FsArray"
#define FS_SLOW_ARRAY_CLASS_NAME "FsSlowArray"
#define FS_STRING_CLASS_NAME "FsString"
#define FS_INTEGER_CLASS_NAME "FsInteger"
#define FS_DICT_CLASS_NAME "FsDict"
#define FS_SLOW_DICT_CLASS_NAME "FsSlowDict"

/* material */
#define FS_MATERIAL_CLASS_NAME "Material"
#define FS_COLOR_MATERIAL_CLASS_NAME "ColorMaterial"
#define FS_TEXTURE_MATERIAL_CLASS_NAME "TextureMaterial"

/* math/easing */
#define FS_EASE_EXPR_CLASS_NAME   "EaseExpr"
#define FS_BACK_EASE_CLASS_NAME   "BackEase"
#define FS_BEZIER_EASE_CLASS_NAME "BezierEase"
#define FS_BOUNCE_EASE_CLASS_NAME "BounceEase"
#define FS_CIRCLE_EASE_CLASS_NAME "CircleEase"
#define FS_CUBIC_EASE_CLASS_NAME "CubicEase"
#define FS_ELASTIC_EASE_CLASS_NAME "ElasticEase"
#define FS_EXPONENTIAL_EASE_CLASS_NAME "ExponentialEase"
#define FS_LINEAR_EASE_CLASS_NAME "LinearEase"
#define FS_POWER_EASE_CLASS_NAME "PowerEase"
#define FS_QUAD_EASE_CLASS_NAME "QuadEase"
#define FS_QUART_EASE_CLASS_NAME "QuartEase"
#define FS_QUINT_EASE_CLASS_NAME "QuintEase"
#define FS_SINE_EASE_CLASS_NAME "SineEase"




/* math/curve */
#define FS_LINEAR_CURVE_2_CLASS_NAME "LinearCurve2"
#define FS_LINEAR_CURVE_3_CLASS_NAME "LinearCurve3"
#define FS_LINEAR_CURVE_4_CLASS_NAME "LinearCurve4"

#define FS_CUBIC_BEZIER_CURVE_2 "CubicBezierCurve2"
#define FS_CUBIC_BEZIER_CURVE_3 "CubicBezierCurve3"
#define FS_CUBIC_BEZIER_CURVE_4 "CubicBezierCurve4"

#define FS_CATMULL_ROM_CURVE_2 "CatmullRomCurve2"
#define FS_CATMULL_ROM_CURVE_3 "CatmullRomCurve3"
#define FS_CATMULL_ROM_CURVE_4 "CatmullRomCurve4"



/* sys */
#define FS_WINDOW_CLASS_NAME "Window"

/* event */
#define FS_TOUCH_EVENT_LISTENER_CLASS_NAME "TouchEventListener"
#define FS_TOUCH_DISPATCHER_CLASS_NAME "TouchDispatcher"
#define FS_SYS_DISPATCHER_CLASS_NAME "SysDispatcher"
#define FS_SYS_EVENT_LISTENER_CLASS_NAME "SysEventListener"
#define FS_KEYPAD_EVENT_LISTENER_CLASS_NAME "KeypadEventListener"
#define FS_KEYPAD_DISPATCHER_CLASS_NAME "KeypadDispatcher"
#define FS_INPUT_TEXT_DISPATCHER_CLASS_NAME "InputTextDispatcher"
#define FS_INPUT_TEXT_EVENT_LISTENER_CLASS_NAME "InputTextEventListener"

/* scheduler */
#define FS_SCHEDULER_CLASS_NAME "Scheduler"
#define FS_SCHEDULER_TARGET_CLASS_NAME "SchedulerTarget"
#define FS_TASK_CLASS_NAME "Task"


/* graphics */
#define FS_RENDER_CLASS_NAME "Render"
#define FS_TEXTURE2D_CLASS_NAME "Texture2D"
#define FS_GLYPH_CLASS_NAME  "Glyph"
#define FS_FONT_TTF_DATA_CLASS_NAME "FontTTFData"
#define FS_FONT_TTF_CLASS_NAME "FontTTF"
#define FS_IMAGE2D_CLASS_NAME "Image2D"
#define FS_PROGRAM_CLASS_NAME "Program"
#define FS_GLYPH_BITMAP_CLASS_NAME "GlyphBitmap"
#define FS_FONT_BITMAP_CLASS_NAME "FontBitmap"
#define FS_FRAME_BUFFER_CLASS_NAME "FrameBuffer"

/* mgr */
#define FS_TEXTURE_MGR_CLASS_NAME "TextureMgr"
#define FS_FONT_TTF_DATA_MGR_CLASS_NAME  "FontTTFDataMgr"
#define FS_SPRITE_2D_DATA_MGR_CLASS_NAME "Sprite2DDataMgr"
#define FS_OBJECT_MGR_CLASS_NAME "ObjectMgr"
#define FS_PROGRAM_MGR_CLASS_NAME "ProgramMgr"


/* action */
#define FS_ACTION_CLASS_NAME "Action"
#define FS_PAUSE_ACTION_CLASS_NAME "PauseAction"
#define FS_SEQ_ACTION_CLASS_NAME "SeqAction"
#define FS_CURVE3_ACTION_CLASS_NAME "Curve3Action"
#define FS_FIX_TIME_ACTION_CLASS_NAME "FixTimeAction"
#define FS_LOOP_ACTION_CLASS_NAME "LoopAction"
#define FS_MOVE_ACTION_CLASS_NAME "MoveAction"
#define FS_ROTATE_ACTION_CLASS_NAME "RotateAction"
#define FS_SCALE_ACTION_CLASS_NAME "ScaleAction"

/* io */
#define FS_FILE_CLASS_NAME "FsFile"
#define FS_MEM_FILE_CLASS_NAME "MemFile"
#define FS_SYS_FILE_CLASS_NAME "SysFile"
#define FS_PACKAGE_CLASS_NAME "Package"
#define FS_RES_PACKAGE_CLASS_NAME "ResPackage"
#define FS_ZIP_PACKAGE_CLASS_NAME "ZipPackage"
#define FS_FGZ_PACKAGE_CLASS_NAME "FgzPackage"
#define FS_VFS_NAME_FILTER_CLASS_NAME "NameFilter"
#define FS_VFS_PREFIX_NAME_FILTER_CLASS_NAME "PrefixNameFilter"
#define FS_VFS_MAP_PACKAGE_CLASS_NAME "MapPackage"
#define FS_SEG_FILE_CLASS_NAME  "SegFile"

/* support */
#define FS_ZIP_READER_CLASS_NAME "ZipReader"

/* networking */
#define FS_HTTP_ENGINE_CLASS_NAME "HttpEngine"






#include "FsTypes.h"



#endif /*_FAERIS_MACROS_H_*/



