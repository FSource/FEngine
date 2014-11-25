#include "FsEulerTransform.h"

NS_FS_BEGIN

const char* EulerTransform::className()
{
	return "EulerTransform";
}
EulerTransform* EulerTransform::create()
{
	return new EulerTransform();
}

EulerTransform::~EulerTransform()
{
}

EulerTransform::EulerTransform()
{
	m_translate.set(0,0,0);
	m_rotate.set(0,0,0);
	m_scale.set(1,1,1);

	m_transformMatrixDirty=true;
}

void EulerTransform::setPosition(const Vector3& v)
{
	m_translate=v;
	m_transformMatrixDirty=true;
}

Vector3 EulerTransform::getPosition()
{
	return m_translate;
}


void EulerTransform::setRotate(const Vector3& v)
{
	m_rotate=v;
	m_transformMatrixDirty=true;
}

Vector3 EulerTransform::getRotate()
{
	return m_rotate;
}

void EulerTransform::setScale(const Vector3& v)
{
	m_scale=v;
	m_transformMatrixDirty=true;
}

Vector3 EulerTransform::getScale()
{
	return m_scale;
}


bool EulerTransform::updateTransformMatrix()
{
	if(m_transformMatrixDirty)
	{
		m_transformMatrix.makeCompose(m_translate,m_rotate,E_EulerOrientType::XYZ,m_scale);
		m_transformMatrixDirty=false;
		return true;
	}
	return false;
}


Matrix4* EulerTransform::getTransformMatrix()
{
	updateTransformMatrix();
	return &m_transformMatrix;
}


NS_FS_END 

