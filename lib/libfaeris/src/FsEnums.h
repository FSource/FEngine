#ifndef _FS_ENUMS_H_
#define _FS_ENUMS_H_

#include "FsMacros.h"

NS_FS_BEGIN

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


enum class E_UniformType
{
	UT_UNKOWN=0,

	/* float vec2 ,vec3 ,vec4 */

	UT_F_1,
	UT_F_2,
	UT_F_3,
	UT_F_4,


	/* int ,ivec2, ivec3, ivec4 */
	UT_I_1,
	UT_I_2,
	UT_I_3,
	UT_I_4,

	/* uint ,uvec2, uvec3, uvec4 */
	UT_UI_1,
	UT_UI_2,
	UT_UI_3,
	UT_UI_4,

	/* mat2 mat3 mat4 */
	UT_M_2,
	UT_M_3,
	UT_M_4,

	/* sampler */
	UT_S_1D,         /* sampler1D,sampler2D,sampler3D */
	UT_S_2D,
	UT_S_3D,
	UT_S_CUBE,       /* samplerCube */
	UT_S_1D_SHADOW,  /* sampler1DShadow, sampler2DShadow */
	UT_S_2D_SHADOW,

	/* ref */
	UT_REF,

	MAX_NU,
};




enum class E_UniformRef 
{
	/* world matrix */
	UNKOWN=0,
	WORLD=1,
	WORLD_TRANSPOSE=2,
	WORLD_INVERSE=3,
	WORLD_INVERSE_TRANSPOSE=4,

	/* view matrix */
	VIEW=5,
	VIEW_TRANSPOSE=6,
	VIEW_INVERSE=7,
	VIEW_INVERSE_TRANSPOSE=8,

	/* project matrix */
	PROJECTION=9,
	PROJECTION_TRANSPOSE=10,
	PROJECTION_INVERSE=11,
	PROJECTION_INVERSE_TRANSPOSE=12,

	/* world view matrix */
	WORLD_VIEW=13,
	WORLD_VIEW_TRANSPOSE=14,
	WORLD_VIEW_INVERSE=15,
	WORLD_VIEW_INVERSE_TRANSPOSE=16,


	/* view project matrix */
	VIEW_PROJECTION=17,
	VIEW_PROJECTION_TRANSPOSE=18,
	VIEW_PROJECTION_INVERSE=19,
	VIEW_PROJECTION_INVERSE_TRANSPOSE=20,

	/* world view projection matrix */
	WORLD_VIEW_PROJECTION=21,
	WORLD_VIEW_PROJECTION_TRANSPOSE=22,
	WORLD_VIEW_PROJECTION_INVERSE=23,
	WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE=24,

	MAX_MATRIX_NU=25,

	/* time */
	TIME=26,

	/* viewport */
	VIEWPORT_WIDTH=27,
	VIEWPORT_WIDTH_INVERSE=28,
	VIEWPORT_HEIGHT=29,
	VIEWPORT_HEIGHT_INVERSE=30,

	/* color */
	COLOR=31,
	OPACITY=32,

	MAX_NU=33,
};


enum class E_StreamType 
{
	UNKOWN=0,
	VERTICES=1,
	NORMALS=2,
	COLORS=3,
	UVS=4,
	UV2S=5,
	TANGENTS=6,
	SKIN_INDICS=7,
	SKIN_WEIGHTS=8,
	USER_DEFINE1=9,
	USER_DEFINE2=10,
	USER_DEFINE3=11,
	USER_DEFINE4=12,
	MAX_NU=13,
};


enum class E_ProgramFeatureSupport
{
	AMBIENT_LIGHT=0x01L<<1,
	DIRECTIONAL_LIGHT=0x01L<<2,
	SPOT_LIGHT=0x01<<3,
	POINT_LIGHT=0x01<<4,
	HEMI_SPHERE_LIGHT=0x1<<5,
	LIGHT=(0x01L<<1)|(0x01<<2)|(0x01<<3)|(0x01<<4)|(0x01<<5),

	SHADOW=(0x01<<6),

	ALPHA_TEST=0x01<<8,

	FOG=0x01<<9,

	SKELETON=0x01<<10,
};


enum class E_FogType 
{
	LINEAR,
	EXP2,
};



enum class E_ShadowType 
{
	SOFT,
	HARD,
};


/* blend */
enum class E_BlendEquation
{
	NONE,
	ADD,
	SUBTRACT,
	REVERSE_SUBTRACT,
};



enum class E_BlendFactor
{
	ZERO,
	ONE,
	SRC_COLOR,
	ONE_MINUS_SRC_COLOR,
	DST_COLOR,
	ONE_MINUS_DST_COLOR,
	SRC_ALPHA,
	ONE_MINUS_SRC_ALPHA,
	DST_ALPHA,
	ONE_MINUS_DST_ALPHA,
	SRC_ALPHA_SATURATE,
};


enum class E_DrawMode
{
	POINTS,
	LINES,
	LINE_STRIP,
	LINE_LOOP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN,
	TRIANGLE_INDEX,
};

NS_FS_END 

#endif 


