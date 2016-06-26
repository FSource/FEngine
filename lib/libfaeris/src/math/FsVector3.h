/*************************************************************************/
/*  FsVector3.h                                                          */
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


#ifndef FY_MATH_VECTORE3_H_
#define FY_MATH_VECTORE3_H_

#include "FsMath.h"

NS_FS_BEGIN

template <typename T> 
class TVector3
{
	public:
		union
		{
			struct
			{
				T x;
				T y;
				T z;
			};
			T v[3];
		};
	public:
		TVector3(T _x,T _y,T _z);
		TVector3();

		TVector3<T> add(const TVector3<T>& v) const ;
		TVector3<T> sub(const TVector3<T>& v) const ;
		TVector3<T> scale(float k) const ;
		T dot(const TVector3<T>& v) const ;
		TVector3<T> cross(const TVector3<T>& v)const;
		TVector3<T> normal() const ;
		void normalize() ;
		TVector3<T> proj(const TVector3<T>& v) const;
		T angle(const TVector3<T>& v) const;
		T length() const;
		T length2() const;
		bool equal(const TVector3<T>& v) const;
		void set(T _x,T _y,T _z);
		TVector3<T> lerp(const TVector3<T>& v,T t);



		/* operator */

		TVector3<T> operator+(const TVector3<T>& v)const;
		TVector3<T> operator-(const TVector3<T>& v)const;
		TVector3<T> operator/ (T v)const;
		TVector3<T> operator* (T v)const;
		TVector3<T>& operator +=(const TVector3<T>& v);


};

#include "FsVector3.inl"

typedef TVector3<float> Vector3f;
typedef TVector3<float> Vector3;

typedef TVector3<uint32_t> Vector3ui;
typedef TVector3<int32_t> Vector3i;


NS_FS_END
#endif 

