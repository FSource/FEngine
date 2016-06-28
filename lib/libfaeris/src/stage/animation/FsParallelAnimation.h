#ifndef _FS_GROUP_ANIMATION_H_
#define _FS_GROUP_ANIMATION_H_ 

#include "FsMacros.h"
#include "FsAnimation.h"

NS_FS_BEGIN
class FsParallelAnimation:public Animation 
{
	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;
		float getTimeLength() FS_OVERRIDE;

	public:
		void addAnimation(Animation* anim);
		void removeAnimation(Animation* anim);
		int getAnimationNu();
		Animation* getAnimation(int index);

	public:
		FsArray* m_animaitons;
		float m_totalTime;
};

NS_FS_END

#endif /*_FS_GROUP_ANIMATION_H_*/
