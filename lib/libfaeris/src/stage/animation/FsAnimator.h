#ifndef _FS_ANIMATOR_H_
#define _FS_ANIMATOR_H_

#include "FsMacros.h"
#include "FsEnums.h"
#include "FsObject.h"
NS_FS_BEGIN

class AnimationEvent;
class Animation;
class AnimationPlayer;
class KeyFrame;
class FsDict;
class FsArray;
class AnimationEvent;

class Animator:public FsObject
{
	public:
		void addAnimation(const char* name,Animation* anim);
		void removeAnimation(const char* name);
		Animation* getAnimation(const char* name);
		FsDict* getAnimations();


		/* control default player*/
		void startAnimation(const char* name,E_AnimPlayMode mode);
		void startAnimation(Animation* animation,E_AnimPlayMode mode);

		void stopAniamtion();
		void pauseAniamtion();
		void playAnimation();
		bool isAnimationStop();
		bool isAnimationPause();

		/* default player */
		void setDefaultPlayer(AnimationPlayer* player);
		AnimationPlayer* getDefaultPlayer();

		int getPlayerNu();
		AnimationPlayer* getPlayer(int index);

		void addPlayer(AnimationPlayer* player);
		void removePlayer(AnimationPlayer* player);
		void removePlayer(int index);



	public:
		FS_VIRTUAL bool animationEvent(AnimationEvent* event);
		FS_VIRTUAL void updateAnimation(float dt);

	public:
		std::function<bool(Animator* at,AnimationEvent* event)> onAnimationEvent;


	protected:
		Animator();
		virtual ~Animator();

	protected:
		FsDict* m_animations;
		FsArray* m_players;
		AnimationPlayer* m_defaultPlayer;
};
NS_FS_END 

#endif /*_FS_ANIMATOR_H_*/
