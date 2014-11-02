#include "fb2Transform.h"

NS_FS_BEGIN
const char* fb2Transform::className()
{
	return "fb2Transform";
}
fb2Transform::fb2Transform(b2Body* b,b2World* w,float radio)
{
	m_body=b;
	m_world=w;
	m_radio=radio;
	m_scale.set(1,1,1);
	m_rotate.set(0,0,0);
}

fb2Transform::~fb2Transform()
{
	m_world->DestroyBody(m_body);
}



fb2Transform* fb2Transform::create(b2Body* b,b2World* world,float radio)
{
	return new fb2Transform(b,world,radio);
}


void fb2Transform::setPosition(const Vector3& v)
{
	m_body->SetPosition(b2Vec2(v.x/m_radio,v.y/m_radio));
}

Vector3 fb2Transform::getPosition()
{
	b2Vec2 pos =m_body->GetPosition();
	return Vector3(pos.x*m_radio,pos.y*m_radio,0);
}

void fb2Transform::setRotate(const Vector3& r)
{
	m_rotate=r;
}

Vector3 fb2Transform::getRotate()
{
	m_rotate.z=getAngle();
	return m_rotate;
}

void fb2Transform::setScale(const Vector3& v)
{
	m_scale=v;
}

Vector3  fb2Transform::getScale()
{
	return m_scale;
}

bool fb2Transform::updateTransformMatrix()
{
	return true;
}

Matrix4* fb2Transform::getTransformMatrix()
{
	b2Vec2 pos=m_body->GetPosition();
	m_rotate.z=getAngle();

	m_transformMatrix.makeCompose(Vector3(pos.x*m_radio,pos.y*m_radio,0),
		m_rotate,E_EulerOrientType::XYZ,m_scale);
	return &m_transformMatrix;
}


void fb2Transform::setPosition(float x,float y)
{
	m_body->SetPosition(b2Vec2(x/m_radio,y/m_radio));

}
void fb2Transform::getPosition(float* x,float* y)
{
	b2Vec2 v=m_body->GetPosition();
	*x=v.x*m_radio;
	*y=v.y*m_radio;
}


float fb2Transform::getAngle()
{
	float angle=m_body->GetAngle();
	return angle/FS_PI*180.0f;
}

void fb2Transform::setLinearVelocity(float x,float y)
{
	m_body->SetLinearVelocity(b2Vec2(x/m_radio,y/m_radio));
}

void fb2Transform::getLinearVelocity(float* x,float* y)
{
	b2Vec2 v=m_body->GetLinearVelocity();
	*x=v.x*m_radio;
	*y=v.y*m_radio;
}

void fb2Transform::setBody(b2Body* b,b2World* w)
{
	m_body=b;
	m_world=w;
}

b2Body* fb2Transform::getBody()
{
	return m_body;
}

void fb2Transform::setRadio(float radio)
{
	m_radio=radio;
}

float fb2Transform::getRadio()
{
	return m_radio;
}
















NS_FS_END
