#ifndef _FS_ANIMATION_H_
#define _FS_ANIMATION_H_

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class FsAnimation:public FsObject
{
	public:
		void setAnimType(E_AnimType type);
		E_AnimType getAnimTye();
	public:
		FS_VIRTUAL void update(Animator* at,float time,float dt);
		FS_VIRTUAL float getTimeLength();

	protected:
		E_AnimType m_animType;
		std::string m_animTypeName;
};

NS_FS_END

#endif /*_FS_ANIMATION_H_*/
