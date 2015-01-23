/*************************************************************************/
/*  FsVector2.h                                                          */
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


#ifndef  FY_MATH_VECTOR2_H_
#define  FY_MATH_VECTOR2_H_ 

#include "FsMacros.h"
#include "FsMath.h"

NS_FS_BEGIN
template<typename T>
class TVector2
{
	public:
		union
		{
			struct 
			{
				T x;
				T y;
			};
			T v[2];
		};
	public:
		TVector2(T fx,T fy);
		TVector2();

		TVector2<T> add(const TVector2<T>& v)const;
		TVector2<T> sub(const TVector2<T>& v)const;
		TVector2<T> scale(T k) const ;

		T dot(const TVector2<T>& v)const;

		TVector2<T> normal()const;
		void normalize();

		TVector2<T> proj(const TVector2<T>& v)const;

		T angle(const TVector2<T>& v)const;

		T length() const;
		T length2() const;

		bool equal(const TVector2<T>& v)const ;
		void set(T _x,T _y);

		TVector2<T> lerp(const TVector2<T>& v,T t);

		/* operator */
		TVector2<T> operator + (const TVector2<T>& v)const;
		TVector2<T> operator - (const TVector2<T>& v)const;
		TVector2<T> operator / (T v) const ;
		TVector2<T> operator * (T v) const ;

		TVector2<T>& operator +=(const TVector2<T>& v);
};

#include "FsVector2.inl"

typedef TVector2<float> Vector2f;
typedef TVector2<float> Vector2;

typedef TVector2<uint32_t> Vector2ui;
typedef TVector2<int32_t> Vector2i;



NS_FS_END
#endif 







