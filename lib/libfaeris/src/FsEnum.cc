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






NS_FS_END 




