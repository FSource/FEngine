/*************************************************************************/
/*  FsParticle2DEmitter.h                                                */
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


#ifndef _FS_PARTICLE_2D_EMITTER_H_
#define _FS_PARTICLE_2D_EMITTER_H_

#include "FsMacros.h"
#include "FsEnums.h"
#include "FsObject.h"

#include "graphics/FsColor.h"
#include "graphics/FsTexture2D.h"
#include "math/FsVector2.h"


NS_FS_BEGIN

class FsFile;
class Texture2D;
class Particle;
class FsDict;


class Particle2DEmitter:public FsObject 
{
	public:
		enum{
			MOVE_FREE,
			MOVE_GROUP,
		};

		enum
		{
			ENV_GRAVITY,
			ENV_RADIAL,
		};

	public:
		static Particle2DEmitter* create();
		static Particle2DEmitter* create(const char* filename);
		static Particle2DEmitter* create(FsFile* file);
		static Particle2DEmitter* create(FsDict* dict);

	public:

		/* about emitter */

		/* particle life time */
		void setDurationTime(float time)
		{
			m_durationTime=time;
		}

		float getDurationTime()
		{
			return m_durationTime;
		}

		void setDurationTimeVar(float time)
		{
			m_durationTimeVar=time;
		}

		float getDurationTimeVar()
		{
			return m_durationTimeVar;
		}


		/* max particle num */
		void setMaxParticleNu(int number)
		{
			m_maxParticleNu=number;
		}

		int getMaxParticleNu()
		{
			return m_maxParticleNu;
		}

		/* emit speed */
		void setEmitSpeed(int speed)
		{
			m_emitSpeed=speed;
		}

		int getEmitSpeed()
		{
			return m_emitSpeed;
		}

		/* about particle */

		/* life time */
		void setLifeTime(float time)
		{
			m_lifeTime=time;
		}

		float getLifeTime()
		{
			return m_lifeTime;
		}

		void setLifeTimeVar(float time)
		{
			m_lifeTimeVar=time;
		}

		float getLifeTimeVar()
		{
			return m_lifeTimeVar;
		}

		/* size */
		void setStartSize(float size)
		{
			m_startSize=size;
		}
		float getStartSize()
		{
			return m_startSize;
		}

		void setStartSizeVar(float size)
		{
			m_startSizeVar=size;
		}
		
		float getStartSizeVar()
		{
			return m_startSizeVar;
		}

		void setEndSize(float size)
		{
			m_endSize=size;
		}
		float getEndSize()
		{
			return m_endSize;
		}

		void setEndSizeVar(float size)
		{
			m_endSizeVar=size;
		}

		float getEndSizeVar()
		{
			return m_endSizeVar;
		}


		/* color */
		void setStartColor(Color c)
		{
			m_startColor=c;
		}

		Color getStartColor()
		{
			return m_startColor;
		}

		void setStartColorVar(Color c)
		{
			m_startColorVar=c;
		}

		Color getStartColorVar()
		{
			return m_startColorVar;
		}

		void setEndColor(Color c)
		{
			m_endColor=c;
		}

		Color getEndColor()
		{
			return m_endColor;
		}

		void setEndColorVar(Color c)
		{
			m_endColorVar=c;
		}
		Color getEndColorVar()
		{
			return m_endColorVar;
		}

		/* angle */
		void setAngle(float angle)
		{
			m_angle=angle;
		}
		float getAngle()
		{
			return m_angle;
		}
		void setAngleVar(float angle)
		{
			m_angleVar=angle;
		}
		float getAngleVar()
		{
			return m_angleVar;
		}
		

		/* rotation */
		void setStartRotation(float angle)
		{
			m_startRotation=angle;
		}
		float getStartRotation()
		{
			return m_startRotation;
		}
		void setStartRotationVar(float angle)
		{
			m_startRotationVar=angle;
		}

		float getStartRotationVar()
		{
			return m_startRotationVar;
		}
		void setEndRotation(float angle)
		{
			m_endRotation=angle;
		}

		float getEndRotation()
		{
			return m_endRotation;
		}

		void setEndRotationVar(float angle)
		{
			m_endRotationVar=angle;
		}
		float getEndRotationVar()
		{
			return m_endRotationVar;
		}

		/* position */
		void setPosition(const Vector2& pos)
		{
			m_position=pos;
		}

		Vector2 getPosition()
		{
			return m_position;
		}


		void setPositionVar(const Vector2& pos)
		{
			m_positionVar=pos;
		}

		Vector2 getPositionVar()
		{
			return m_positionVar;
		}

		/* move mode */
		void setMoveMode(int mode)
		{
			m_moveMode=mode;
		}
		int getMoveMode()
		{
			return m_moveMode;
		}


		/* texture */
		void setBlendSrc(E_BlendFactor blend)
		{
			m_blendSrc=blend;
		}
		E_BlendFactor getBlendSrc()
		{
			return m_blendSrc;
		}

		void setBlendDst(E_BlendFactor blend)
		{
			m_blendDst=blend;
		}

		E_BlendFactor getBlendDst()
		{
			return m_blendDst;
		}

		void setTexture(Texture2D* texture)
		{
			FS_SAFE_ASSIGN(m_texture,texture);
		}

		Texture2D* getTexture()
		{
			FS_SAFE_ADD_REF(m_texture);
			return m_texture;
		}


		/* environment */
		void setEnvironmentMode(int mode)
		{
			m_enviromentMode=mode;
		}
		int getEnvironmentMode()
		{
			return m_enviromentMode;
		}

		/* gravity mode */
		void setSpeed(float speed)
		{
			m_speed=speed;
		}
		float getSpeed()
		{
			return m_speed;
		}

		void setSpeedVar(float speed)
		{
			m_speedVar=speed;
		}
		float getSpeedVar()
		{
			return m_speedVar;
		}

		void setGravity(const Vector2& g)
		{
			m_gravity=g;
		}

		Vector2 getGravity()
		{
			return m_gravity;
		}

		void setRadialAcceleration(float accel)
		{
			m_radialAcceleration=accel;
		}
		float getRadialAcceleration()
		{
			return m_radialAcceleration;
		}
		void setRadialAccelerationVar(float accel)
		{
			m_radialAccelerationVar=accel;
		}
		float getRadialAccelerationVar()
		{
			return m_radialAccelerationVar;
		}

		void setTangentialAcceleration(float accel)
		{
			m_tangentialAcceleration=accel;
		}
		float getTangentialAcceleration()
		{
			return m_tangentialAcceleration;
		}
		void setTangentialAccelerationVar(float accel)
		{
			m_tangentialAccelerationVar=accel;
		}
		float getTangentialAccelerationVar()
		{
			return m_tangentialAccelerationVar;
		}

		/* radial mode */
		void setStartRadius(float radius)
		{
			m_startRadius=radius;
		}

		float getStartRadius()
		{
			return m_startRadius;
		}
		
		void setStartRadiusVar(float radius)
		{
			m_startRadiusVar=radius;
		}

		float getStartRadiusVar()
		{
			return m_startRadiusVar;
		}

		void setEndRadius(float radius)
		{
			m_endRadius=radius;
		}

		float getEndRadius()
		{
			return m_endRadius;
		}

		void setEndRadiusVar(float radius)
		{
			m_endRadiusVar=radius;
		}

		float getEndRadiusVar()
		{
			return m_endRadiusVar;
		}

		void setRotateSpeed(float speed)
		{
			m_rotateSpeed=speed;
		}

		float getRotateSpeed()
		{
			return m_rotateSpeed;
		}

		void setRotateSpeedVar(float speed)
		{
			m_rotateSpeedVar=speed;
		}

		float getRotateSpeedVar()
		{
			return m_rotateSpeedVar;
		}



		/* Generate Particle */
		void generateParticle(Particle* p);


	protected:
		Particle2DEmitter();
		virtual ~Particle2DEmitter();
		virtual const char* className();

		bool init();
		bool init(const char* filename);
		bool init(FsFile* file);
		bool init(FsDict* dict);

	private:

		float m_durationTime;
		float m_durationTimeVar;
		int m_maxParticleNu;
		int m_emitSpeed;

		float m_lifeTime;
		float m_lifeTimeVar;
		float m_startSize;
		float m_startSizeVar;
		float m_endSize;
		float m_endSizeVar;
		Color m_startColor;
		Color m_startColorVar;
		Color m_endColor;
		Color m_endColorVar;

		float m_angle;
		float m_angleVar;

		float m_startRotation;
		float m_startRotationVar;
		float m_endRotation;
		float m_endRotationVar;

		Vector2 m_position;
		Vector2 m_positionVar;

		int m_moveMode;

		/* texture */
		E_BlendFactor m_blendSrc;
		E_BlendFactor m_blendDst;
		Texture2D* m_texture;

		/* environment */
		int m_enviromentMode;

		/* gravity mode */
		float m_speed;
		float m_speedVar;
		Vector2 m_gravity;

		float m_radialAcceleration;
		float m_radialAccelerationVar;
		float m_tangentialAcceleration;
		float m_tangentialAccelerationVar;

		/* radial mode */
		float m_startRadius;
		float m_startRadiusVar;
		float m_endRadius;
		float m_endRadiusVar;
		float m_rotateSpeed;
		float m_rotateSpeedVar;
};

NS_FS_END 
#endif /*_FS_PARTICLE_EMITTER_H_*/


