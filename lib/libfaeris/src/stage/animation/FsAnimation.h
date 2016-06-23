#ifndef _FS_ANIMATION_H_
#define _FS_ANIMATION_H_

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class FsAnimation:public FsObject
{
	public:
		FS_VIRTUAL void update(Animator* at,float time,float dt)=0;
		FS_VIRTUAL float getTimeLength()=0;
};

NS_FS_END

#endif /*_FS_ANIMATION_H_*/
