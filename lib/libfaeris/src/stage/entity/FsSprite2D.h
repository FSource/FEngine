#ifndef _FS_SPRITE_2D_H_
#define _FS_SPRITE_2D_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "graphics/material/FsTextureMaterial.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN

class Sprite2DData;
class Texture2D;
class FsArray;
class FsDict;
class Sprite2DAnimation;
class AnimationCacheData;
class TextureMaterial;
class Program;

class Sprite2D :public Entity 
{
	public:
		enum
		{
			ANIM_LOOP,
			ANIM_START,
			ANIM_END,
		};
	public:

		static Sprite2D* create();
		static Sprite2D* create(const char* name);

	public:

		/* material */
		void setColor(Color4f c){m_material->setColor(c);}
		Color4f getColor(){return m_material->getColor();}

		void setOpacity(float opacity){m_material->setOpacity(opacity);}
		float getOpacity(){return m_material->getOpacity();}

		void setBlend(int eq,int src,int dst){m_material->setBlend(eq,src,dst);}
		void setBlend(int src,int dst){m_material->setBlend(src,dst);}

		TextureMaterial* getMaterial(){return m_material;}
		void setMaterial(TextureMaterial* mat){FS_SAFE_ASSIGN(m_material,mat);}

		Program* getShader(){return m_program;}
		void setShader(Program* shader){FS_SAFE_ASSIGN(m_program,shader);}


	public:


		void setResourceUrl(const char* name);

		/* animation */
		void setAnimation(const char* name);
		const char* getAnimation();
		void updateAnimation(float dt);

		bool hasAnimation(const char* name);

		void playAnimation(int mode=ANIM_LOOP);
		void startAnimation(int mode=ANIM_LOOP);
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
		virtual void draw(Render* render,bool update_matrix=true);

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


		int m_mode;
		int m_stop;

		int m_curFps;

		Sprite2DData* m_data;

		Sprite2DAnimation* m_curAnimation;
		AnimationCacheData* m_curAnimationCacheData; /* weak reference */
		FsArray* m_textures;
		FsDict* m_animationCacheData;

		/* material */
		TextureMaterial* m_material;
		Program* m_program;
};



NS_FS_END


#endif /*_FS_SPRITE_2D_H_*/




