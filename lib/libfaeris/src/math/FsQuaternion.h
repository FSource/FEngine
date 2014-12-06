#ifndef _FS_QUATERNION_H_
#define _FS_QUATERNION_H_
#include "FsMacros.h"
#include "FsEnums.h"
#include "math/FsVector3.h"

NS_FS_BEGIN

class Matrix4;
class Quaternion 
{
	public:
		union
		{
			struct
			{
				float x,y,z,w;
			};
			float v[4];
		};
	public:
		Quaternion(float qx,float qy,float qz,float qw)
			:x(qx),y(qy),z(qz),w(qw){}
		Quaternion(float qx,float qy,float qz)
			:x(qx),y(qy),z(qz),w(1){}
		Quaternion():x(0),y(0),z(0),w(1){}

		/* set Quaternion from different way */
		void set(float qx,float qy,float qz,float qw) { x=qx;y=qy;z=qz;w=qw; }

		/* aux function for quick make Quaternion */
		void makeFromEuler(const Vector3& v,E_EulerOrientType order);
		void makeFromAxisAngle(const Vector3& v,float angle);
		void makeFromRotationMatrix(const Matrix4& m);

		/* normalize function */
		void calcuateW();
		float length()const;
		void normalize();
		void inverse();
		void getInverse(Quaternion* q)const;

		/* transform function */
		void multiply(const Quaternion& q);
		void multiply(const Quaternion& a,const Quaternion& b);
		Vector3 multiplyVector3(const Vector3& v) const;

		/* slerp */
		void slerp(const Quaternion& qa,const Quaternion& qb,float t);

};

NS_FS_END
#endif /*_FAERY_CORE_QUATERNION_H_*/



