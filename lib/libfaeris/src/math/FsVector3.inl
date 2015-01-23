/*************************************************************************/
/*  FsVector3.inl                                                        */
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


#ifndef FY_MATH_VECTORE3_INL_
#define FY_MATH_VECTORE3_INL_

template <typename T>
inline TVector3<T>::TVector3(T fx,T fy,T fz)
	:x(fx),y(fy),z(fz) {}


template <typename T>
inline TVector3<T>::TVector3()
	:x(0),y(0),z(0)
{}

template <typename T>
inline TVector3<T> TVector3<T>::add(const TVector3<T>& v) const
{
	return TVector3<T>(x+v.x,y+v.y,z+v.z);
}

template <typename T>
inline TVector3<T> TVector3<T>::sub(const TVector3<T>& v) const 
{
	return TVector3<T>(x-v.x,y-v.y,z-v.z);
}

template <typename T>
inline TVector3<T> TVector3<T>::scale(T k) const 
{
	return TVector3<T>(k*x,k*y,k*z);
}

/* u dot v 
 * =u.x*v.x+u.y*v.y+u.z*v.z
 */

template <typename T>
inline T  TVector3<T>::dot(const TVector3<T>& v) const
{
	return x*v.x+y*v.y+z*v.z;
}

/* u cross v 
 * | i   j   k  |
 * | vx  vy  vz |
 * | ux  uy  uz |
 *
 * =(vy*uz-vz*uy)i
 * +(vz*ux-vx*uz)j
 * +(vx*uy-ux*vy)k
 */

template <typename T>
inline TVector3<T> TVector3<T>::cross(const TVector3<T>& u) const 
{
	T rx=y*u.z-z*u.y;
	T ry=z*u.x-x*u.z;
	T rz=x*u.y-u.x*y;
	return  TVector3<T>(rx,ry,rz);
}

/* normal(v)= v/|v| */
template <typename T>
inline TVector3<T> TVector3<T>::normal() const
{
	T l=length();
	if( l==0)
	{
		return TVector3(0,0,0);
	}
	return TVector3<T>(x/l,y/l,z/l);
}



template <typename T>
inline void TVector3<T>::normalize()
{
	T l=length();
	x=x/l;
	y=y/l;
	z=z/l;
}

/* project(u,v)= (dot(u,v)*u)/(|u||u|) */
template <typename T>
inline TVector3<T> TVector3<T>::proj(const TVector3<T>& v) const 
{
	T l=v.x*v.x+v.y*v.y+v.z*v.z;
	T k=this->dot(v)/(l);
	return v.scale(k);
}

template <typename T>
inline T TVector3<T>::angle(const TVector3<T>& v) const 
{
	T m=dot(v)/(length()*v.length());
	return Math::acosr(m)/FS_PI*180.0f;
}

/* |u|=sqrt(x*x+y*y+z*z) */
template <typename T>
inline T TVector3<T>::length() const 
{
	T l=x*x+y*y+z*z;
	return Math::sqrt(l);
}

template <typename T>
inline T TVector3<T>::length2()const
{
	return x*x+y*y+z*z;
}

template <typename T>
inline bool TVector3<T>::equal(const TVector3<T>& v) const 
{
	return (Math::equal(x,v.x)&&
			Math::equal(y,v.y)&&
			Math::equal(z,v.z));
}

template <typename T>
inline void TVector3<T>::set(T _x,T _y,T _z)
{
	x=_x;
	y=_y;
	z=_z;
}



template <typename T>
inline TVector3<T> TVector3<T>::lerp(const TVector3<T>& v,T t)
{
	T rx=x+(v.x-x)*t;
	T ry=y+(v.y-y)*t;
	T rz=z+(v.z-z)*t;

	return TVector3<T>(rx,ry,rz);
}

template <typename T>
inline TVector3<T> TVector3<T>::operator+(const TVector3<T>& v)const
{
	return this->add(v);
}


template <typename T>
inline TVector3<T> TVector3<T>::operator-(const TVector3<T>& v)const
{
	return this->sub(v);
}


template <typename T>
inline TVector3<T> TVector3<T>::operator/(T v)const
{
	return this->scale(1/v);
}


template <typename T>
inline TVector3<T> TVector3<T>::operator*(T v)const
{
	return this->scale(v);
}

template <typename T>
inline TVector3<T>& TVector3<T>::operator +=(const TVector3<T>& v)
{
	this->x+=v.x;
	this->y+=v.y;
	this->z+=v.z;
	return *this;
}




#endif 







