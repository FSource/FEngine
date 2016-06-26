/*************************************************************************/
/*  FsEnums.cc                                                           */
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


#include <string.h>
#include "FsEnums.h"

NS_FS_BEGIN

#define FS_ENUM_TO_STR_MAP_IMPLEMENT(t,map) \
	const char* FsEnum_##t##ToStr(const E_##t& v)   \
	{ \
		EnumStrPair<E_##t>* p=map; \
		while(p->m_name!=NULL) \
		{  \
			if(p->m_enum==v) \
			{ \
				return p->m_name; \
			} \
			p++; \
		} \
		assert(0); \
		return NULL; \
	} \
	E_##t FsEnum_StrTo##t(const char* name) \
	{ \
		EnumStrPair<E_##t>* p=map ;  \
		while(p->m_name!=NULL) \
		{ \
			if(strcmp(p->m_name,name)==0) \
			{ \
				return p->m_enum; \
			} \
			p++; \
		} \
		return  map[0].m_enum; \
	}




/* E_FsType */

static EnumStrPair<E_FsType> S_E_FsTypeStrMap[]={
	EnumStrPair<E_FsType>(E_FsType::FT_IN_VALID,"invalid"),
	EnumStrPair<E_FsType>(E_FsType::FT_B_1,"boolean"),
	EnumStrPair<E_FsType>(E_FsType::FT_F_1,"float"),
	EnumStrPair<E_FsType>(E_FsType::FT_F_2,"vector2f"),
	EnumStrPair<E_FsType>(E_FsType::FT_F_3,"vector3f"),
	EnumStrPair<E_FsType>(E_FsType::FT_F_4,"vector4f"),
	EnumStrPair<E_FsType>(E_FsType::FT_I_1,"integer"),
	EnumStrPair<E_FsType>(E_FsType::FT_I_2,"vector2i"),
	EnumStrPair<E_FsType>(E_FsType::FT_I_3,"vector3i"),
	EnumStrPair<E_FsType>(E_FsType::FT_I_4,"vector4i"),
	EnumStrPair<E_FsType>(E_FsType::FT_COLOR_3,"color3f"),
	EnumStrPair<E_FsType>(E_FsType::FT_COLOR_4,"color4f"),
	EnumStrPair<E_FsType>(E_FsType::FT_MAT4,"mat4"),
	EnumStrPair<E_FsType>(E_FsType::FT_CHARS,"string"),
	EnumStrPair<E_FsType>(E_FsType::FT_OBJECT,"fobject"),
	EnumStrPair<E_FsType>(E_FsType::FT_STRING,"fstring"),
	EnumStrPair<E_FsType>(E_FsType::FT_DICT,"fdict"),
	EnumStrPair<E_FsType>(E_FsType::FT_ARRAY,"farray"),
	EnumStrPair<E_FsType>(E_FsType::FT_IN_VALID,NULL),
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(FsType,S_E_FsTypeStrMap) 



/* E_MaterialType */
static EnumStrPair<E_MaterialType>  S_E_MaterialTypeStrMap[] = 
{
	EnumStrPair<E_MaterialType>(E_MaterialType::UNKOWN,"unkown"),
	EnumStrPair<E_MaterialType>(E_MaterialType::COLOR,"color"),
	EnumStrPair<E_MaterialType>(E_MaterialType::TEXTURE,"texture"),
	EnumStrPair<E_MaterialType>(E_MaterialType::CONSTANT,"constant"),
	EnumStrPair<E_MaterialType>(E_MaterialType::LAMBERT,"lambert"),
	EnumStrPair<E_MaterialType>(E_MaterialType::PHONG,"phong"),
	EnumStrPair<E_MaterialType>(E_MaterialType::SHADER,"shader"),
	EnumStrPair<E_MaterialType>(E_MaterialType::UNKOWN,NULL)

};

FS_ENUM_TO_STR_MAP_IMPLEMENT(MaterialType,S_E_MaterialTypeStrMap) 

/* E_TextAlign */
static EnumStrPair<E_TextAlign> S_E_TextAlignStrMap[]=
{
	EnumStrPair<E_TextAlign>(E_TextAlign::LEFT,"left"),
	EnumStrPair<E_TextAlign>(E_TextAlign::CENTER,"center"),
	EnumStrPair<E_TextAlign>(E_TextAlign::RIGHT,"right"),
	EnumStrPair<E_TextAlign>(E_TextAlign::RIGHT,NULL)
};

FS_ENUM_TO_STR_MAP_IMPLEMENT(TextAlign,S_E_TextAlignStrMap)

/* E_BlendEquation */
static EnumStrPair<E_BlendEquation> S_E_BlendEquation[]=
{
	EnumStrPair<E_BlendEquation>(E_BlendEquation::NONE,"none"),
	EnumStrPair<E_BlendEquation>(E_BlendEquation::ADD,"add"),
	EnumStrPair<E_BlendEquation>(E_BlendEquation::SUBTRACT,"subtract"),
	EnumStrPair<E_BlendEquation>(E_BlendEquation::REVERSE_SUBTRACT,"reverseSubtract"),
	EnumStrPair<E_BlendEquation>(E_BlendEquation::REVERSE_SUBTRACT,NULL),
};

FS_ENUM_TO_STR_MAP_IMPLEMENT(BlendEquation,S_E_BlendEquation);



/* E_BlendFactor */
static EnumStrPair<E_BlendFactor> S_E_BlendFactor[] =
{
	EnumStrPair<E_BlendFactor>(E_BlendFactor::ZERO,"zero"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::ONE,"one"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::SRC_COLOR,"srcColor"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::ONE_MINUS_SRC_COLOR,"oneMinusSrcColor"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::DST_COLOR,"dstColor"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::ONE_MINUS_DST_COLOR,"oneMinusDstColor"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::SRC_ALPHA,"srcAlpha"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::ONE_MINUS_SRC_ALPHA,"oneMinusSrcAlpha"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::DST_ALPHA,"dstAlpha"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::ONE_MINUS_DST_ALPHA,"oneMinusDstAlpha"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::SRC_ALPHA_SATURATE,"srcAlphaSaturate"),
	EnumStrPair<E_BlendFactor>(E_BlendFactor::SRC_ALPHA_SATURATE,NULL)
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(BlendFactor,S_E_BlendFactor);


/* E_TextureFilter */
static EnumStrPair<E_TextureFilter> S_E_TextureFilter[]=
{
	EnumStrPair<E_TextureFilter>(E_TextureFilter::LINEAR,"linear"),
	EnumStrPair<E_TextureFilter>(E_TextureFilter::NEAREST,"nearest"),
	EnumStrPair<E_TextureFilter>(E_TextureFilter::NEAREST,NULL)
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(TextureFilter,S_E_TextureFilter);


/* E_TextureWrap */
static EnumStrPair<E_TextureWrap> S_E_TextureWrap[]=
{
	EnumStrPair<E_TextureWrap>(E_TextureWrap::CLAMP,"clamp"),
	EnumStrPair<E_TextureWrap>(E_TextureWrap::REPEAT,"repeat"),
	EnumStrPair<E_TextureWrap>(E_TextureWrap::CLAMP_TO_EDGE,"clampToEdge"),
	EnumStrPair<E_TextureWrap>(E_TextureWrap::CLAMP_TO_BORDER,"clampToBorder"),
	EnumStrPair<E_TextureWrap>(E_TextureWrap::CLAMP_TO_BORDER,NULL)
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(TextureWrap,S_E_TextureWrap);


/* E_DrawMode */
static EnumStrPair<E_DrawMode> S_E_DrawMode[]=
{
	EnumStrPair<E_DrawMode>(E_DrawMode::POINTS,"points"),
	EnumStrPair<E_DrawMode>(E_DrawMode::LINES,"lines"),
	EnumStrPair<E_DrawMode>(E_DrawMode::LINE_STRIP,"lineStrip"),
	EnumStrPair<E_DrawMode>(E_DrawMode::LINE_LOOP,"lineLoop"),
	EnumStrPair<E_DrawMode>(E_DrawMode::TRIANGLES,"triangles"),
	EnumStrPair<E_DrawMode>(E_DrawMode::TRIANGLE_STRIP,"triangleStrip"),
	EnumStrPair<E_DrawMode>(E_DrawMode::TRIANGLE_FAN,"triangleFan"),
	EnumStrPair<E_DrawMode>(E_DrawMode::TRIANGLE_INDEX,"triangleIndex"),
	EnumStrPair<E_DrawMode>(E_DrawMode::TRIANGLE_INDEX,NULL)
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(DrawMode,S_E_DrawMode);



static EnumStrPair<E_ButtonTweenFlag> S_E_ButtonTweenFlag[]={
	EnumStrPair<E_ButtonTweenFlag>(E_ButtonTweenFlag::ANCHOR,"anchor"),
	EnumStrPair<E_ButtonTweenFlag>(E_ButtonTweenFlag::ANCHOR,NULL)
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(ButtonTweenFlag,S_E_ButtonTweenFlag);




static EnumStrPair<E_LerpMode> S_E_LerpMode[]={
	EnumStrPair<E_LerpMode>(E_LerpMode::FLAT,"flat"),
	EnumStrPair<E_LerpMode>(E_LerpMode::SMOOTH,"smooth"),
	EnumStrPair<E_LerpMode>(E_LerpMode::FLAT,NULL)
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(LerpMode,S_E_LerpMode);



NS_FS_END 




