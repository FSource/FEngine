#ifndef _FS_SPRITE_2D_H_
#define _FS_SPRITE_2D_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "stage/Entity/FsIMaterial2DEntity.h"
#include "graphics/FsColor.h"
#include "graphics/material/FsMaterial2D.h"

NS_FS_BEGIN

class Sprite2DData;
class Texture2D;
class FsArray;
class FsDict;
class Sprite2DAnimation;
class AnimationCacheData;
class Material2D;
class Program;

class Sprite2D :public Entity ,public IMaterial2DEntity
{
	public:

		static Sprite2D* create();
		static Sprite2D* create(const char* name);

	public:


		void setResourceUrl(const char* name);

		/* animation */
		void setAnimation(const char* name);
		const char* getAnimation();
		void updateAnimation(float dt);

		bool hasAnimation(const char* name);

		void playAnimation(E_AnimPlayMode mode=E_AnimPlayMode::LOOP);
		void startAnimation(E_AnimPlayMode mode=E_AnimPlayMode::LOOP);
		void stopAnimation();

		bool isAnimationPlaying();

		void setAnimationOffset(float x,float y);
		void getAnimationOffset(float* x,float* y);


		/* frame */
		void setCurFrame(int frame);
		int getCurFrame();
		int getTotalFrame();

		/* fps */
		int getFps();
		void setFps(int fps);

	public:

		/* inherit Entity */
		virtual void update(float dt);
		virtual void draw(RenderDevice* rd,bool update_matrix=true);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		bool init();
		bool init(const char* name);
		void setAnimation(Sprite2DAnimation* anim);
		Sprite2D();
		~Sprite2D();

	private:

		int m_curFrame;
		float m_elapseTime;


		E_AnimPlayMode m_mode;
		int m_stop;

		int m_curFps;

		Sprite2DData* m_data;

		Sprite2DAnimation* m_curAnimation;
		AnimationCacheData* m_curAnimationCacheData; /* weak reference */
		FsArray* m_textures;
		FsDict* m_animationCacheData;

};



NS_FS_END


#endif /*_FS_SPRITE_2D_H_*/




