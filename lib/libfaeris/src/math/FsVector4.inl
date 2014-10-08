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
inline TVector4<T> TVector4<T>::scale(T k) const 
{
	return TVector4<T>(x*k,y*k,z*k,w*k);
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
















