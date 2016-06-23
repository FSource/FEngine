#ifndef _FS_PROPERTY_ANIMATION_H_
#define _FS_PROPERTY_ANIMATION_H_

#include "FsMacros.h"
#include "FsTrackAnimation.h"

NS_FS_BEGIN

class FsAttributeAnimation:public FsTrackAnimation 
{
	public:
		static FsAttributeAnimation* create(E_AnimType anim_type,FsType type);


	public:
		void insert(float time,const FsVariant& value);

		E_AnimType getAnimType();
		FsType getValueType();


	protected:
		E_AnimType m_animType;
		FsType m_valueType;
};


NS_FS_END

#endif /*_FS_PROPERTY_ANIMATION_H_*/
