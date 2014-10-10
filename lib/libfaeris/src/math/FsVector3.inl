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







