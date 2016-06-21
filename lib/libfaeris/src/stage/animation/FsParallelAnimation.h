#ifndef _FS_GROUP_ANIMATION_H_
#define _FS_GROUP_ANIMATION_H_ 

#include "FsMacros.h"
#include "FsAnimation.h"

class FsParallelAnimation:public FsAnimation 
{
	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;
		float getTimeLength() FS_OVERRIDE;
	public:
		void addAnimation(FsAnimation* anim);
		void removeAnimation(FsAnimation* anim);
		int getAnimationNu();
		FsAnimation* getAnimation(int index);

	public:
		FsArray* m_animaitons;
		float m_totalTime;
};

#endif /*_FS_GROUP_ANIMATION_H_*/
