/*************************************************************************/
/*  FsQuaternionTransform.h                                              */
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


#ifndef _FS_QUATERNION_TRANSFORM_H_
#define _FS_QUATERNION_TRANSFORM_H_

#include "FsITransform.h"

NS_FS_BEGIN

class QuaternionTransform : public ITransform 
{
	public: 
		static QuaternionTransform* create();

	public:
		void setPosition(const Vector3& v) FS_OVERRIDE; 
		Vector3 getPosition() FS_OVERRIDE;


		void setRotate(const Vector3& r) FS_OVERRIDE;
		Vector3 getRotate() FS_OVERRIDE;

		void setScale(const Vector3& v) FS_OVERRIDE;
		Vector3 getScale() FS_OVERRIDE;

		bool updateTransformMatrix() FS_OVERRIDE;
		Matrix4* getTransformMatrix() FS_OVERRIDE;

		void setQuaternion(const Quaternion& q);
		Quaternion getQuaternion();
		



	public:
		const char* className() FS_OVERRIDE;


	protected:
		QuaternionTransform();
		virtual ~QuaternionTransform();

	protected:
		Vector3 m_translate;
		Quaternion m_rotate;
		Vector3 m_scale;

		bool m_transformMatrixDirty;
		Matrix4 m_transformMatrix;
};


NS_FS_END

#endif /*_FS_QUATERNION_TRANSFORM_H_*/



