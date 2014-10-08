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
inline TVector2<T> TVector2<T>::scale(const T k)const 
{
	return TVector2(x*k,y*k);
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

