#ifndef _FS_ANIMATION_PLAYER_H_
#define _FS_ANIMATION_PLAYER_H_

#include "FsMacros.h"
#include "FsObject.h"
NS_FS_BEGIN

class Animation;
class Animator;

class AnimationPlayer :public FsObject
{
	public:
		static AnimationPlayer* create();  

	public:
		void start(Animation* animation,E_AnimPlayMode mode);
		void stop();

		void pause();
		void play();

		bool isPause();
		bool isStop();

	public:
		FS_VIRTUAL void update(Animator* target,float dt);
	protected:
		AnimationPlayer();
		~AnimationPlayer();

	protected:
		E_AnimPlayMode m_mode;
		Animation* m_animation;
		float m_animTotalTime;

		float m_time;
		bool m_isStop;
		bool m_isPause;
		//Animator* FS_FEATURE_WEAK_REF(m_animator);
};

NS_FS_END



#endif /*_FS_ANIMATION_PLAYER_H_ */
