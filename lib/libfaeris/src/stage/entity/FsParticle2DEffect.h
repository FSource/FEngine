#ifndef _FS_PARTICLE_EFFECT_H_
#define _FS_PARTICLE_EFFECT_H_

#include <vector>
#include "FsMacros.h"
#include "FsObject.h"
#include "stage/entity/FsEntity.h"
#include "graphics/material/FsTextureMaterial.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN

class Particle2DEmitter;
class Mat_V4F_T2F;
class FsFile;


class Particle 
{
	public:
		float m_timeElapse;
		float m_lifeTime;
		float m_size;
		float m_sizeDt;
		float m_colorRed,m_colorGreen,m_colorBlue,m_colorAlpha;
		float m_colorRedDt,m_colorGreenDt,m_colorBlueDt,m_colorAlphaDt;


		float m_rotation;
		float m_rotationDt;

		Vector2 m_position;
		Vector2 m_startPos;
		

		int m_envMode;
		int m_moveMode;

		/* gravity mode */
		struct 
		{
			Vector2 m_gravity;
			float m_radialAcceleration;
			float m_tangentialAcceleration;
			Vector2 m_direction;

		}m_gravityMode;

		/* radial mode */
		struct 
		{
			float m_radius;
			float m_radiusDt;
			float m_angleDt;
			float m_angle;

		}m_radialMode;
};


class Particle2DEffect:public Entity 
{
	public:

		static Particle2DEffect* create(const char* filename);
		static Particle2DEffect* create(FsFile* file);
		static Particle2DEffect* create(Particle2DEmitter* emitter);
		static Particle2DEffect* create();

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
		void start(bool restart=true);
		void refresh();
		void stop();
		void setPause(bool pause);
		bool isPause();
		bool isStop();

		float getLifeTime();
		float getElapseTime();


		void setEmitter(Particle2DEmitter* emit);
		Particle2DEmitter* getEmitter();

		void setAutoRemoveOnStop(bool remove);

		int getParticleNu(){return m_particles.size(); }
		int getMaxParticleNu();

	public:
		/* override entity */
		virtual void update(float dt);
		virtual void draw(RenderDevice* r,bool update_world_matrix);
		virtual const char* className();


	protected:
		virtual void updateParticle(Particle* p,float dt);
		virtual void generateParticle(float dt);
		Particle2DEffect();
		~Particle2DEffect();
		bool init(Particle2DEmitter* emitter);
		void destruct();

	private:
		std::vector<Particle> m_particles;

		int m_maxParticles;
		int m_emitSpeed;
		float m_lifeTime;
		float m_elapseTime;
		float m_opacity;

		Particle2DEmitter* m_emitter;

		bool m_stop;
		bool m_pause;
		bool m_autoRemove;
		float m_generateParticle;

		TextureMaterial* m_material;
		Program* m_program;

};


NS_FS_END


#endif /*_FS_PARTICLE_EFFECT_H_*/


