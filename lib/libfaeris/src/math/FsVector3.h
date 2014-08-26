#ifndef FY_MATH_VECTORE3_H_
#define FY_MATH_VECTORE3_H_
#include "FsMathUtil.h"
NS_FS_BEGIN
class Vector3
{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float v[3];
		};
	public:
		Vector3(float _x,float _y,float _z);
		Vector3();
		Vector3 add(const Vector3& v) const ;
		Vector3 sub(const Vector3& v) const ;
		Vector3 scale(float k) const ;
		float dot(const Vector3& v) const ;
		Vector3 cross(const Vector3& v)const;
		Vector3 normal() const ;
		void normalize() ;
		Vector3 proj(const Vector3& v) const;
		float angle(const Vector3& v) const;
		float length() const;
		float length2() const;
		bool equal(const Vector3& v) const;
		void set(float _x,float _y,float _z);
		Vector3 lerp(const Vector3& v,float t);



		/* operator */

		Vector3 operator+(const Vector3& v)const;
		Vector3 operator-(const Vector3& v)const;
		Vector3 operator/ (float v)const;
		Vector3 operator* (float v)const;
		Vector3& operator +=(const Vector3& v);


};
#include "FsVector3.inl"
NS_FS_END
#endif 

