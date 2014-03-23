#ifndef _FS_SPINE_SPRITE_H_
#define _FS_SPINE_SPRITE_H_
#include "spine/spine.h"
#include "FsMacros.h"
#include "FsObject.h"
#include "graphics/FsColor.h"
#include "stage/entity/FsEntity.h"
#include "FsSpineSpriteData.h"
#include "FsSpineSpriteDataMgr.h"

#include "graphics/material/FsTextureMaterial.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN
class Render;
class SpineSprite:public Entity 
{
	public:
		enum
		{
			ANIM_LOOP,
			ANIM_START,
			ANIM_END,
		};
	public:
		static SpineSprite* create(const char* filename);

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
		/* skin */
		bool setSkin(const char* skin);


		/* animation */
		void updateAnimation(float dt);
		void setAnimation(const char* anim);


		void playAnimation(int mode=ANIM_LOOP);
		void startAnimation(int mode=ANIM_LOOP);
		void stopAnimation();
		bool isAnimationPlaying();


		/* time */
		void setCurTime(float time);
		float getCurTime();
		float getDurationTime();


	public:
		virtual void update(float dt);
		virtual void draw(Render* render,bool update_matrix=true);

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

		int m_mode;
		int m_stop;

		Skeleton* m_skeleton;
		SpineSpriteData* m_data;


		Animation* m_curAnimation;


		TextureMaterial* m_material;
		Program* m_program;

};



NS_FS_END 

#endif /*_FS_SPINE_SPRITE_H_*/














