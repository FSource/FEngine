#ifndef _FS_LABEL_RTF_H_
#define _FS_LABEL_RTF_H_

#include "FsMacros.h"
#include "FsEntity.h"
#include "FsIMaterial2DEntity.h"

NS_FS_BEGIN 
class LabelRTF:public Entity,public FsIMaterial2DEntity 
{
	public:
		static LabelRTF* create(const char* font_name,int size=24,const Color4f& c=Color4f::WHITE);

	public:


};



NS_FS_END 

#endif /*_FS_LABEL_RTF_H_*/


