#ifndef  FY_MATH_VECTOR2_H_
#define  FY_MATH_VECTOR2_H_ 

#include "FsMacros.h"
#include "FsMathUtil.h"

NS_FS_BEGIN
class Vector2
{
	public:
		union
		{
			struct 
			{
				float x;
				float y;
			};
			float v[2];
		};
	public:
		Vector2(float fx,float fy);
		Vector2();
		Vector2 add(const Vector2& v)const;
		Vector2 sub(const Vector2& v)const;
		Vector2 scale(float k) const ;
		float dot(const Vector2& v)const;
		Vector2 normal()const;
		void normalize();
		Vector2 proj(const Vector2& v)const;
		float angle(const Vector2& v)const;
		float length() const;
		float length2() const;
		bool equal(const Vector2& v)const ;
		void set(float _x,float _y);

		Vector2 lerp(const Vector2& v,float t);

		/* operator */
		Vector2 operator + (const Vector2& v)const;
		Vector2 operator - (const Vector2& v)const;
		Vector2 operator / (float v) const ;
		Vector2 operator * (float v) const ;

		Vector2& operator +=(const Vector2& v);
};

#include "FsVector2.inl"
NS_FS_END
#endif 


