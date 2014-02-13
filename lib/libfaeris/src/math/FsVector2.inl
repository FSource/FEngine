#ifndef FY_MATH_VECTOR2_INL_
#define FY_MATH_VECTOR2_INL_
inline Vector2::Vector2(float fx,float fy)
	:x(fx),y(fy)
{}
inline Vector2::Vector2()
	:x(0),y(0)
{}

inline Vector2 Vector2::add(const Vector2& v) const
{
	return Vector2(x+v.x,y+v.y);
}

inline Vector2 Vector2::sub(const Vector2& v) const 
{
	return Vector2(x-v.x,y-v.y);
}

inline Vector2 Vector2::scale(const float k)const 
{
	return Vector2(x*k,y*k);
}
inline float Vector2::dot(const Vector2& v)const 
{
	return x*v.x+y*v.y;
}

inline Vector2 Vector2::normal()const 
{
	float l=length();
	return Vector2(x/l,y/l);
}

inline void Vector2::normalize()
{
	float l=length();
	x=x/l;
	y=y/l;
}
inline Vector2 Vector2::proj(const Vector2& v) const
{
	float l=v.length2();
	float k=this->dot(v)/l;
	return v.scale(k);
}
inline float Vector2::angle(const Vector2& v) const
{
	float theta=dot(v)/(length()*v.length());
	return Math::acosr(theta)/FS_PI*180.0f;
}
inline float Vector2::length() const 
{
	return Math::sqrt(length2());
}
inline float Vector2::length2()const 
{
	return x*x+y*y;
}

inline bool Vector2::equal(const Vector2& v) const 
{
	return Math::floatEqual(x,v.x)&&Math::floatEqual(y,v.y);
}


inline void Vector2::set(float _x,float _y) 
{
	x=_x;
	y=_y;
}
/* operator */

inline Vector2 Vector2::operator+(const Vector2& v) const 
{
	return this->add(v);
}

inline Vector2 Vector2::operator-(const Vector2& v) const 
{
	return this->sub(v);
}

inline Vector2 Vector2::operator/(float v) const 
{
	return this->scale(1.0f/v);
}

inline Vector2 Vector2::operator*(float v) const 
{
	return this->scale(v);
}

inline Vector2& Vector2::operator +=(const Vector2& v)
{
	this->x+=v.x;
	this->y+=v.y;
	return *this;
}

#endif

