#ifndef _FB2_TRANSFORM_H_
#define _FB2_TRANSFORM_H_

#include "FsMacros.h"
#include "stage/entity/FsITransform.h"
#include "Box2D/Box2D.h"



NS_FS_BEGIN

class fb2Transform:public ITransform 
{
	public:
		static fb2Transform* create(b2Body* b,b2World* world,float radio);

	public:
		virtual void setPosition(const Vector3& v);
		virtual Vector3 getPosition();

		virtual void setRotate(const Vector3& r);
		virtual Vector3 getRotate();

		virtual void setScale(const Vector3& v);
		virtual Vector3 getScale();

		virtual bool updateTransformMatrix();
		virtual  Matrix4* getTransformMatrix();

	public:
		virtual const char* className();

	public:
		void setPosition(float x,float y);
		void getPosition(float* x,float* y);

		float getAngle();

		void setLinearVelocity(float x,float y);
		void getLinearVelocity(float* x,float* y);


		void setBody(b2Body* b,b2World* world);
		b2Body* getBody();
		
		void setRadio(float radio);
		float getRadio();



	protected:
		fb2Transform(b2Body* b,b2World* w,float radio);
		~fb2Transform();

	protected:
		Matrix4 m_transformMatrix;
		b2Body* m_body;
		b2World* m_world;

		Vector3 m_scale;
		Vector3 m_rotate;

		float m_radio;

};



NS_FS_END 



#endif /*_FB2_TRANSFORM_H_*/

