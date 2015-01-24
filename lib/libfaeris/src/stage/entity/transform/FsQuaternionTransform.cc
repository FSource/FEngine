/*************************************************************************/
/*  FsQuaternionTransform.cc                                             */
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
	m_scale.set(1.0f,1.0f,1.0f);

	m_transformMatrixDirty=true;
}

QuaternionTransform::~QuaternionTransform()
{
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


