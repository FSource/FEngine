/*************************************************************************/
/*  FsVector4.inl                                                        */
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


#ifndef FY_MATH_VECTOR4_INL_
#define FY_MATH_VECTOR4_INL_

template<typename T>
inline TVector4<T>::TVector4(T fx,T fy,T fz,T fw)
	:x(fx),y(fy),z(fz),w(fw)
{}

template<typename T>
inline TVector4<T>::TVector4(T fx,T fy,T fz)
	:x(fx),y(fy),z(fz),w(1)
{}

template<typename T>
inline TVector4<T>::TVector4()
	:x(0),y(0),z(0),w(1)
{}

template<typename T>
inline TVector4<T> TVector4<T>::add(const TVector4<T>& v) const 
{
	return TVector4<T>(x+v.x,y+v.y,z+v.z,w+v.w);
}

template<typename T>
inline TVector4<T> TVector4<T>::sub(const TVector4<T>& v) const 
{
	return TVector4<T>(x-v.x,y-v.y,z-v.z,w-v.w);
}

template<typename T>
inline TVector4<T> TVector4<T>::scale(float k) const 
{
	return TVector4<T>((T)(x*k),(T)(y*k),(T)(z*k),(T)(w*k));
}

template<typename T>
inline T TVector4<T>::dot(const TVector4<T>& v)const 
{
	return x*v.x+y*v.y+z*v.z+w*v.w;
}

template<typename T>
inline TVector4<T> TVector4<T>::normal() const 
{
	T l=length();

	return TVector4<T>(x/l,y/l,z/l,w/l);
}

template<typename T>
inline void TVector4<T>::normalize() 
{
	T l=length();
	x=x/l;
	y=y/l;
	z=z/l;
	w=w/l;
}


template<typename T>
inline T TVector4<T>::length() const 
{
	return Math::sqrt(length2());
}

template<typename T>
inline T TVector4<T>::length2() const 
{
	return x*x+y*y+z*z+w*w;
}

template<typename T>
inline bool TVector4<T>::equal(const TVector4<T>&  v) const 
{
	return Math::equal(x,v.x)&&
		   Math::equal(y,v.y)&&
		   Math::equal(z,v.z)&&
		   Math::equal(w,v.w);
}

template<typename T>
inline TVector4<T> TVector4<T>::lerp(const TVector4<T>& v,T t)
{

	T rx=x+(v.x-x)*t;
	T ry=y+(v.y-y)*t;
	T rz=z+(v.z-z)*t;
	T rw=w+(v.w-w)*t;

	return TVector4<T>(rx,ry,rz,rw);
}

template<typename T>
inline TVector4<T> TVector4<T>::operator + (const TVector4<T>& v)const
{
	return this->add(v);
}

template<typename T>
inline TVector4<T> TVector4<T>::operator - (const TVector4<T>& v)const
{
	return this->sub(v);
}

template<typename T>
inline TVector4<T> TVector4<T>::operator / (T v) const 
{
	return this->scale(1/v);
}

template<typename T>
inline TVector4<T> TVector4<T>::operator* (T v) const 
{
	return this->scale(v);
}

template<typename T>
inline TVector4<T>& TVector4<T>::operator +=(const TVector4<T>& v)
{
	this->x+=v.x;
	this->y+=v.y;
	this->z+=v.z;
	this->w+=v.w;
	return *this;
}

#endif 
















