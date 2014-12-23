#ifndef _FS_SPINE_SPRITE_H_
#define _FS_SPINE_SPRITE_H_

#include "spine/spine.h"
#include "FsMacros.h"
#include "FsEnums.h"
#include "stage/entity/FsEntity2D.h"
#include "FsSpineSpriteData.h"
#include "FsSpineSpriteDataMgr.h"


NS_FS_BEGIN

class RenderDevice;
class SpineSprite:public Entity2D
{
	public:
		static SpineSprite* create(const char* filename);


	public:
		/* skin */
		bool setSkin(const char* skin);


		/* animation */
		void updateAnimation(float dt);
		void setAnimation(const char* anim);


		void playAnimation(E_AnimPlayMode mode=E_AnimPlayMode::LOOP);
		void startAnimation(E_AnimPlayMode mode=E_AnimPlayMode::LOOP);
		void stopAnimation();
		bool isAnimationPlaying();


		/* time */
		void setCurTime(float time);
		float getCurTime();
		float getDurationTime();


	public:
		virtual void update(float dt);
		virtual void draw(RenderDevice* render,bool update_matrix=true);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		bool init(const char* name);
		void destruct();
		SpineSprite();
		virtual ~SpineSprite();

	private:
		float m_elapseTime;
		float m_duration;

		E_AnimPlayMode m_mode;
		int m_stop;

		Skeleton* m_skeleton;
		SpineSpriteData* m_data;


		Animation* m_curAnimation;


};



NS_FS_END 

#endif /*_FS_SPINE_SPRITE_H_*/














