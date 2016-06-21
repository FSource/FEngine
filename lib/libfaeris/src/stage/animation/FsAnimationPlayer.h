#ifndef _FS_ANIMATION_PLAYER_H_
#define _FS_ANIMATION_PLAYER_H_

#include "FsMacros.h"
NS_FS_BEGIN

class FsAnimation;
class FsAnimator;

class FsAnimationPlayer :public FsObject
{
	public:
		void start(FsAnimation* animation,E_AnimPlayMode mode);
		void stop();

		void pause();
		void play();

		bool isPause();
		bool isStop();

	public:
		FS_VIRTUAL void update(FsAnimator* target,float dt);

	protected:
		E_AnimPlayMode m_mode;
		FsAnimation* m_animation;
		float m_time;
		bool m_isStop;
		bool m_isPause;
		FsAnimator* FS_FEATURE_WEAK_REF(m_animator);
};

NS_FS_END



#endif /*_FS_ANIMATION_PLAYER_H_ */
