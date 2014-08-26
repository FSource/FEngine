#ifndef FY_MATH_VECTOR4_INL_
#define FY_MATH_VECTOR4_INL_

inline Vector4::Vector4(float fx,float fy,float fz,float fw)
	:x(fx),y(fy),z(fz),w(fw)
{}

inline Vector4::Vector4(float fx,float fy,float fz)
	:x(fx),y(fy),z(fz),w(1)
{}
inline Vector4::Vector4()
	:x(0),y(0),z(0),w(1)
{}

inline Vector4 Vector4::add(const Vector4& v) const 
{
	return Vector4(x+v.x,y+v.y,z+v.z,w+v.w);
}

inline Vector4 Vector4::sub(const Vector4& v) const 
{
	return Vector4(x-v.x,y-v.y,z-v.z,w-v.w);
}

inline Vector4 Vector4::scale(float k) const 
{
	return Vector4(x*k,y*k,z*k,w*k);
}

inline float Vector4::dot(const Vector4& v)const 
{
	return x*v.x+y*v.y+z*v.z+w*v.w;
}

inline Vector4 Vector4::normal() const 
{
	float l=length();

	return Vector4(x/l,y/l,z/l,w/l);
}

inline void Vector4::normalize() 
{
	float l=length();
	x=x/l;
	y=y/l;
	z=z/l;
	w=w/l;
}


inline float Vector4::length() const 
{
	return Math::sqrt(length2());
}

inline float Vector4::length2() const 
{
	return x*x+y*y+z*z+w*w;
}

inline bool Vector4::equal(const Vector4&  v) const 
{
	return Math::floatEqual(x,v.x)&&
		   Math::floatEqual(y,v.y)&&
		   Math::floatEqual(z,v.z)&&
		   Math::floatEqual(w,v.w);
}

inline Vector4 Vector4::lerp(const Vector4& v,float t)
{

	float rx=x+(v.x-x)*t;
	float ry=y+(v.y-y)*t;
	float rz=z+(v.z-z)*t;
	float rw=w+(v.w-w)*t;

	return Vector4(rx,ry,rz,rw);
}

inline Vector4 Vector4::operator + (const Vector4& v)const
{
	return this->add(v);
}

inline Vector4 Vector4::operator - (const Vector4& v)const
{
	return this->sub(v);
}

inline Vector4 Vector4::operator / (float v) const 
{
	return this->scale(1/v);
}

inline Vector4 Vector4::operator* (float v) const 
{
	return this->scale(v);
}

inline Vector4& Vector4::operator +=(const Vector4& v)
{
	this->x+=v.x;
	this->y+=v.y;
	this->z+=v.z;
	this->w+=v.w;
	return *this;
}

#endif 
















