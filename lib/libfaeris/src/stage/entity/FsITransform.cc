#include "FsITransform.h"

NS_FS_BEGIN

Transform::Transform()
{
	m_translate.set(0,0,0);
	m_rotate.set(0,0,0);
	m_scale.set(1,1,1);

	m_transformMatrixDirty=true;
}

void Transform::setPosition(const Vector3& v)
{
	m_translate=v;
	m_transformMatrixDirty=true;
}

Vector3 Transform::getPosition()
{
	return m_translate;
}


void Transform::setRotate(const Vector3& v)
{
	m_rotate=v;
	m_transformMatrixDirty=true;
}

Vector3 Transform::getRotate()
{
	return m_rotate;
}

void Transform::setScale(const Vector3& v)
{
	m_scale=v;
	m_transformMatrixDirty=true;
}

Vector3 Transform::getScale()
{
	return m_scale;
}

bool Transform::updateTransformMatrix()
{
	if(m_transformMatrixDirty)
	{
		m_transformMatrix.makeCompose(m_translate,m_rotate,E_EulerOrientType::XYZ,m_scale);
		m_transformMatrixDirty=false;
		return true;
	}
	return false;
}


Matrix4* Transform::getTransformMatrix()
{
	updateTransformMatrix();
	return &m_transformMatrix;
}























NS_FS_END 

