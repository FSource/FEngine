#ifndef _FS_ENUMS_H_
#define _FS_ENUMS_H_

#include "FsMacros.h"

NS_FS_BEGIN

/* EULER  OLDER */
enum class  E_EulerOrientType
{
	XYZ =0,
	XZY ,
	YXZ ,
	YZX ,
	ZXY ,
	ZYX 
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
	UT_REF_RD, 	   /* take from render device */
	UT_REF_MAT,    /* take from material */
	UT_REF_MAT_EXT, /* take from material extends */

	MAX_NU,
};


enum  class E_UniformRef
{
	/* world matrix */
	UNKOWN=0,
	R_WORLD_MAT=1,
	R_WORLD_TRANSPOSE_MAT=2,
	R_WORLD_INVERSE_MAT=3,
	R_WORLD_INVERSE_TRANSPOSE_MAT=4,

	/* view matrix */
	R_VIEW_MAT=5,
	R_VIEW_TRANSPOSE_MAT=6,
	R_VIEW_INVERSE_MAT=7,
	R_VIEW_INVERSE_TRANSPOSE_MAT=8,

	/* project matrix */
	R_PROJECTION_MAT=9,
	R_PROJECTION_TRANSPOSE_MAT=10,
	R_PROJECTION_INVERSE_MAT=11,
	R_PROJECTION_INVERSE_TRANSPOSE_MAT=12,

	/* world view matrix */
	R_WORLD_VIEW_MAT=13,
	R_WORLD_VIEW_TRANSPOSE_MAT=14,
	R_WORLD_VIEW_INVERSE_MAT=15,
	R_WORLD_VIEW_INVERSE_TRANSPOSE_MAT=16,


	/* view project matrix */
	R_VIEW_PROJECTION_MAT=17,
	R_VIEW_PROJECTION_TRANSPOSE_MAT=18,
	R_VIEW_PROJECTION_INVERSE_MAT=19,
	R_VIEW_PROJECTION_INVERSE_TRANSPOSE_MAT=20,

	/* world view projection matrix */
	R_WORLD_VIEW_PROJECTION_MAT=21,
	R_WORLD_VIEW_PROJECTION_TRANSPOSE_MAT=22,
	R_WORLD_VIEW_PROJECTION_INVERSE_MAT=23,
	R_WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE_MAT=24,

	R_MAX_MATRIX_NU=25,

	/* time */
	R_TIME=26,

	/* viewport */
	R_VIEWPORT_WIDTH=27,
	R_VIEWPORT_WIDTH_INVERSE=28,
	R_VIEWPORT_HEIGHT=29,
	R_VIEWPORT_HEIGHT_INVERSE=30,

	/* color */
	R_COLOR=31,
	R_OPACITY=32,

	/* material */
	M_POINT_SIZE,
	M_COLOR,
	M_OPACITY,
	M_COLOR_MAP,
	

	MAX_NU,
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

enum class E_AnimPlayMode 
{
	LOOP,
	START,
	END
};



enum class E_MeshType 
{
	STATIC,
	MORPH,
	SKELETON,
	MORPH_SKELETON
};


enum E_MorphAnimFlag 
{
	VERTICES=0x01ul,
	NORMALS=0x02ul,
	COLORS=0x04ul,
	UVS=0x08ul,
	UV2S=0x10ul,
	TANGENTS=0x20ul,
	SKIN_INDICS=0x40ul,
	SKIN_WEIGHTS=0x80ul
};


enum class E_FileSeek 
{
	SET,
	CUR,
	END,
};

enum class E_PixelFormat 
{
	UNKOWN=0,
	RGB888,
	RGBA8888,
	GRAY8,
	ALPHA,
	LUMINANCE,
	LUMINANCE_ALPHA,
	INTENSITY,

};

enum class E_ImageType 
{
	UNKOWN=0,
	PNG,
	JPEG,
	TGA,
	BMP
};

enum class E_TextureFilter 
{
	LINEAR,
	NEAREST,
};

enum class E_TextureWrap 
{
	CLAMP,
	REPEAT,
	CLAMP_TO_EDGE,
	CLAMP_TO_BORDER,
};


enum class E_FrontFace 
{
	CCW,
	CW
};

enum class E_BoneType 
{
	WORLD,
	LOCAL,
};



NS_FS_END 

#endif 


