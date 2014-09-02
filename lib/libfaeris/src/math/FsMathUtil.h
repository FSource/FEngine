#ifndef _FS_MATH_UTIL_H_
#define _FS_MATH_UTIL_H_

#include <math.h>
#include "FsMacros.h"

NS_FS_BEGIN

class Vector2;
class Rect2D;
class Matrix4;
FS_BEGIN_NAMESPACE(Math)

#ifndef FS_PI 
#define FS_PI 3.14159265358979323846f
#endif 

inline float radianToAngle(float radian)
{
	return radian/FS_PI*180.0f;
}
inline float angleToRadian(float  angle)
{
	return angle/180.0f*FS_PI;
}

static inline float sqrt(float v)
{
	return ::sqrt(v);
}
inline float cosr(float radian)
{
	return ::cosf(radian);
}
inline float sinr(float radian)
{
	return ::sinf(radian);
}
inline float tanr(float radian)
{
	return ::tanf(radian);
}
inline float acosr(float radian)
{
	return ::acosf(radian);
}

inline float cosa(float angle)
{
	return ::cosf(angleToRadian(angle));
}
inline float sina(float angle)
{
	return ::sinf(angleToRadian(angle));
}
inline float tana(float angle)
{
	return ::tanf(angleToRadian(angle));
}
inline float acosa(float angle)
{
	return ::acosf(angleToRadian(angle));
}

inline float clampf(float value,float min,float max)
{
	if(value<min)
	{
		return min;
	}
	if(value>max)
	{
		return max;
	}
	return value;
}





template<typename T> T abs(T f){return f<0?-f:f;}

template<typename T> T sign(T f) 
{
	if(f<0)
	{
		return -1;
	}
	else if(f==0)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

void srand(ulong s);
int random();
int random(int begin,int end);
float random(float begin,float end);

inline int floatEqual(float a,float b)
{
	return abs(a-b)<0.0001?1:0;
}






bool pointInTriangle2D(const Vector2& point,const Vector2& a,const Vector2& b,const Vector2& c);

bool pointInRect2D(const Vector2& point,const Matrix4& mat,const Rect2D& rect);





FS_END_NAMESPACE(Math)



NS_FS_END

#endif 

