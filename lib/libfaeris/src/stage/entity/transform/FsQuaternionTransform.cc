#include "FsQuaternionTransform.h"


NS_FS_BEGIN

const char* QuaternionTransform::className()
{
	return "QuaternionTransform";
}

QuaternionTransform* QuaternionTransform::create()
{
	return new QuaternionTransform();
}

QuaternionTransform::QuaternionTransform()
{
	m_translate.set(0,0,0);
	m_rotate.makeFromEuler(Vector3f(0,0,0),E_EulerOrientType::XYZ);
	m_scale.set(0,0,0);

	m_transformMatrixDirty=true;
}


void QuaternionTransform::setPosition(const Vector3f& v)
{
	m_translate=v;
	m_transformMatrixDirty=true;
}


Vector3f QuaternionTransform::getPosition()
{
	return m_translate;
}



void QuaternionTransform::setRotate(const Vector3f& v)
{
	m_rotate.makeFromEuler(v,E_EulerOrientType::XYZ);
	m_transformMatrixDirty=true;
}

Vector3f QuaternionTransform::getRotate()
{
	FS_TRACE_WARN("Can't Convert QuaternionTransform To Euler Rotation");
	return Vector3f(0,0,0);
}


void QuaternionTransform::setScale(const Vector3f& v)
{
	m_scale=v;
	m_transformMatrixDirty=true;
}


Vector3f QuaternionTransform::getScale()
{
	return m_scale;
}

void QuaternionTransform::setQuaternion(const Quaternion& q)
{
	m_rotate=q;
	m_transformMatrixDirty=true;
}

Quaternion QuaternionTransform::getQuaternion()
{
	return m_rotate;
}


bool QuaternionTransform::updateTransformMatrix()
{
	if(m_transformMatrixDirty)
	{
		m_transformMatrix.makeCompose(m_translate,m_rotate,m_scale);
		m_transformMatrixDirty=false;
		return true;
	}

	return false;
}

Matrix4* QuaternionTransform::getTransformMatrix()
{
	updateTransformMatrix();
	return &m_transformMatrix;
}














NS_FS_END 


