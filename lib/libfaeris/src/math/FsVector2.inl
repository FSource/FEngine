/*************************************************************************/
/*  FsVector2.inl                                                        */
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


#ifndef FY_MATH_VECTOR2_INL_
#define FY_MATH_VECTOR2_INL_


template<typename T> 
inline TVector2<T>::TVector2(T fx,T fy) 
	:x(fx),y(fy) 
{}

template<typename T>
inline TVector2<T>::TVector2()
	:x(0),y(0)
{}

template<typename T>
inline TVector2<T> TVector2<T>::add(const TVector2<T>& v) const
{
	return TVector2(x+v.x,y+v.y);
}

template<typename T>
inline TVector2<T> TVector2<T>::sub(const TVector2<T>& v) const 
{
	return TVector2(x-v.x,y-v.y);
}

template<typename T>
inline TVector2<T> TVector2<T>::scale( float k)const 
{
	return TVector2((T)(x*k),(T)(y*k));
}

template<typename T>
inline T TVector2<T>::dot(const TVector2<T>& v)const 
{
	return x*v.x+y*v.y;
}

template<typename T>
inline TVector2<T> TVector2<T>::normal()const 
{
	T l=length();
	return TVector2<T>(x/l,y/l);
}

template<typename T>
inline void TVector2<T>::normalize()
{
	T l=length();
	x=x/l;
	y=y/l;
}

template<typename T>
inline TVector2<T> TVector2<T>::proj(const TVector2<T>& v) const
{
	T l=v.length2();
	T k=this->dot(v)/l;
	return v.scale(k);
}

template<typename T>
inline T TVector2<T>::angle(const TVector2<T>& v) const
{
	T theta=dot(v)/(length()*v.length());
	return Math::acosr(theta)/FS_PI*180.0f;
}

template<typename T>
inline T TVector2<T>::length() const 
{
	return Math::sqrt(length2());
}

template<typename T>
inline T TVector2<T>::length2()const 
{
	return x*x+y*y;
}

template<typename T>
inline bool TVector2<T>::equal(const TVector2<T>& v) const 
{
	return Math::equal(x,v.x)&&Math::equal(y,v.y);
}


template<typename T>
inline void TVector2<T>::set(T _x,T _y) 
{
	x=_x;
	y=_y;
}


template<typename T>
inline TVector2<T> TVector2<T>::lerp(const TVector2<T>& v,T t)
{
	T rx=x+(v.x-x)*t;
	T ry=y+(v.y-y)*t;

	return TVector2(rx,ry);
}


/* operator */

template<typename T>
inline TVector2<T> TVector2<T>::operator+(const TVector2<T>& v) const 
{
	return this->add(v);
}

template<typename T>
inline TVector2<T> TVector2<T>::operator-(const TVector2<T>& v) const 
{
	return this->sub(v);
}

template<typename T>
inline TVector2<T> TVector2<T>::operator/(T v) const 
{
	return this->scale(1.0f/v);
}

template<typename T>
inline TVector2<T> TVector2<T>::operator*(T v) const 
{
	return this->scale(v);
}

template<typename T>
inline TVector2<T>& TVector2<T>::operator +=(const TVector2<T>& v)
{
	this->x+=v.x;
	this->y+=v.y;
	return *this;
}

#endif

