#ifndef _FS_ANIMATOR_H_
#define _FS_ANIMATOR_H_

#include "FsMacros.h"

NS_FS_BEGIN

class FsAnimation;
class FsAnimationPlayer;

class FsAnimator 
{
	public:
		void addAnimation(const char* name,FsAnimation* anim);
		void removeAnimation(const char* name);

		/* control default player*/
		void startAnimation(const char* name,E_AnimPlayMode mode);
		void startAnimation(FsAnimation* animation,E_AnimPlayMode mode);

		void stopAniamtion();
		void pauseAniamtion();
		void playAnimation();
		bool isAnimationStop();
		bool isAnimationPause();

		/* default player */
		void setDefaultPlayer(FsAnimationPlayer* player);
		void getDefaultPlayer(FsAnimationPlayer* player);

		FsAnimationPlayer* createPlayer();
		void removePlayer(FsAnimationPlayer* player);

	public:
		FS_VIRTUAL bool animationEvent(E_AnimType anim_type,const char* anim_tname,const FsVariant& value);


	protected:
		FsDict* m_animations;
		FsArray* m_players;
		
};
NS_FS_END 

#endif /*_FS_ANIMATOR_H_*/
