/*************************************************************************/
/*  FsParticle2DEffect.h                                                 */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#ifndef _FS_PARTICLE_EFFECT_H_
#define _FS_PARTICLE_EFFECT_H_

#include <vector>
#include "FsMacros.h"
#include "FsObject.h"
#include "stage/entity/FsEntity2D.h"
#include "math/FsVertices.h"

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


class Particle2DEffect:public Entity2D
{
	public:

		static Particle2DEffect* create(const char* filename);
		static Particle2DEffect* create(FsFile* file);
		static Particle2DEffect* create(Particle2DEmitter* emitter);
		static Particle2DEffect* create();


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

		/* when particle, this will called  */
		virtual void finish();


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

		std::vector<Fs_V2F_T2F_C4F> m_vertics;
		std::vector<Face3> m_faces;
};


NS_FS_END


#endif /*_FS_PARTICLE_EFFECT_H_*/


