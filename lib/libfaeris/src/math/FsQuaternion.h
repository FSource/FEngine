/*************************************************************************/
/*  FsQuaternion.h                                                       */
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


#ifndef _FS_QUATERNION_H_
#define _FS_QUATERNION_H_
#include "FsMacros.h"
#include "FsEnums.h"
#include "math/FsVector3.h"

NS_FS_BEGIN

class Matrix4;
class Quaternion 
{
	public:
		union
		{
			struct
			{
				float x,y,z,w;
			};
			float v[4];
		};
	public:
		Quaternion(float qx,float qy,float qz,float qw)
			:x(qx),y(qy),z(qz),w(qw){}
		Quaternion(float qx,float qy,float qz)
			:x(qx),y(qy),z(qz),w(1){}
		Quaternion():x(0),y(0),z(0),w(1){}

		/* set Quaternion from different way */
		void set(float qx,float qy,float qz,float qw) { x=qx;y=qy;z=qz;w=qw; }

		/* aux function for quick make Quaternion */
		void makeFromEuler(const Vector3& v,E_EulerOrientType order);
		void makeFromAxisAngle(const Vector3& v,float angle);
		void makeFromRotationMatrix(const Matrix4& m);

		/* normalize function */
		void calcuateW();
		float length()const;
		void normalize();
		void inverse();
		void getInverse(Quaternion* q)const;

		/* transform function */
		void multiply(const Quaternion& q);
		void multiply(const Quaternion& a,const Quaternion& b);
		Vector3 multiplyVector3(const Vector3& v) const;

		/* slerp */
		void slerp(const Quaternion& qa,const Quaternion& qb,float t);

};

NS_FS_END
#endif /*_FAERY_CORE_QUATERNION_H_*/



