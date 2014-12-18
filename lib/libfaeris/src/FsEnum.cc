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
	EnumStrPair<E_TextureWrap>(E_TextureWrap::CLAMP_TO_BORDER,"clampToBorder")
};
FS_ENUM_TO_STR_MAP_IMPLEMENT(TextureWrap,S_E_TextureWrap);





NS_FS_END 




