/*************************************************************************/
/*  FsVector4.h                                                          */
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


#ifndef FY_MATH_VECTOR4_H_
#define FY_MATH_VECTOR4_H_
#include "FsMacros.h"
#include "FsMath.h"

NS_FS_BEGIN
template<typename T>
class TVector4
{
	public:
		union
		{
			struct 
			{
				T x;
				T y;
				T z;
				T w;
			};
			T v[4];
		};
	public:
		TVector4(T fx,T fy,T fz,T fw);
		TVector4(T fx,T fy,T fz);
		TVector4<T>();
		TVector4<T> add(const TVector4<T>& v)const ;
		TVector4<T> sub(const TVector4<T>& v)const;
		TVector4<T> scale(float k)const ;
		T dot(const TVector4<T>& v)const;

		TVector4<T> normal() const ;
		void normalize() ;
		T length() const;
		T length2() const;

		bool equal(const TVector4<T>& v) const;

		TVector4<T> lerp(const TVector4<T>& v,T t);


		TVector4<T> operator + (const TVector4<T>& v)const;
		TVector4<T> operator - (const TVector4<T>& v)const;
		TVector4<T> operator / (T v) const ;
		TVector4<T> operator * (T v) const ;

		TVector4<T>& operator +=(const TVector4<T>& v);
};

#include"FsVector4.inl"

typedef TVector4<float> Vector4f;
typedef TVector4<float> Vector4;

typedef TVector4<uint32_t> Vector4ui;
typedef TVector4<int32_t> Vector4i;

NS_FS_END
#endif



