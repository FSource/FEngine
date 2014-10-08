#ifndef _FS_MATH_MATRIX4_H_
#define _FS_MATH_MATRIX4_H_ 

#include "FsMacros.h"

#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsQuaternion.h"


NS_FS_BEGIN
class  Matrix4
{
	public:
		union{
			struct 
			{
				float m00,m10,m20,m30;
				float m01,m11,m21,m31;
				float m02,m12,m22,m32;
				float m03,m13,m23,m33;
			};
			float v[16];
			float m[4][4];
		};
	public:

		Matrix4(){}
		Matrix4(const float* v)
		{
			set(v[0],  v[1],  v[2],  v[3],
				v[4],  v[5],  v[6],  v[7],
				v[8],  v[9],  v[10], v[11],
				v[12], v[13], v[14], v[15]);
		}

		Matrix4(float v00,float v01,float v02,float v03,
				float v10,float v11,float v12,float v13,
				float v20,float v21,float v22,float v23,
				float v30,float v31,float v32,float v33)
		{
			set(v00,v01,v02,v03,
				v10,v11,v12,v13,
				v20,v21,v22,v23,
				v30,v31,v32,v33
			   );
		}


		/* normal operating for Matrix4 */
		void add(const Matrix4& n); 
		void mul(const Matrix4& n);

		void mulScaler(float s);
		Vector2 mulVector2(const Vector2& v) const ;
		Vector3 mulVector3(const Vector3& v) const ;
		Vector4 mulVector4(const Vector4& v) const ;



		void transpose();
		void getTranspose(Matrix4* m);
		void inverse();
		void getInverse(Matrix4* m);
		float getDetermiant();


		/* aux function to quick change Matrix4  */
		void makeTranslate(float x,float y,float z);
		void makeTranslate(const Vector3& v){makeTranslate(v.x,v.y,v.z);}

		void makeRotateX(float theta);
		void makeRotateY(float theta);
		void makeRotateZ(float theta);
		void makeRotateAxis(const Vector3& v,float angle){makeRotateAxis(v.x,v.y,v.z,angle);}
		void makeRotateAxis(float x,float y,float z,float angle);

		void makeRotateFromEuler(float x,float y,float z,int type);
		void makeRotateFromEuler(const Vector3& v,int type){makeRotateFromEuler(v.x,v.y,v.z,type);}

		void makeScale(float x,float y,float z);
		void makeScale(const Vector3& v){makeScale(v.x,v.y,v.z);}
		void makeIdentity();

		void makeLookAt(const Vector3& eye,const Vector3& target,const Vector3& up);
		void makeFrustum(float left,float right,float bottom,float top,float near,float far);
		void makePerspective(float fov,float aspect,float near,float far);
		void makeOrthographic(float left,float right,float bottom,float top,float near,float far);
		void makeCompose(const Vector3& t,const Vector3& r,int r_type,const Vector3& s);
		void makeCompose(const Vector3& t,const Quaternion& q,const Vector3& s);


		/* set rotate,scale and translate part in Matrix4 */
		void setTranslate(float x,float y,float z);
		void setTranslate(const Vector3& v){setTranslate(v.x,v.y,v.z);}
		void setRotationFromEuler(float rx,float ry,float rz,int type);
		void setRotationFromQuaternion(const Quaternion& q); 
		void setScale(float sx,float sy,float sz);
		void setScale(const Vector3& v){setScale(v.x,v.y,v.z);}

		/* transform rotate,scale,translate part in Matrix4 */
		void translate(float vx,float vy,float vz);
		void translate(const Vector3& v){translate(v.x,v.y,v.z);}

		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		void rotateByAxis(float x,float y,float z,float angle);
		void rotateByAxis(const Vector3& v,float angle){rotateByAxis(v.x,v.y,v.z,angle);}
	
		void scale(float x,float y,float z);
		void scale(const Vector3& v){scale(v.x,v.y,v.z);}

		/* decompose and compose matrix */

		void decompose(Vector3* t,Quaternion* q,Vector3* s);
		
		/* get rotate,scale,and translate information from Matrix4 */
		Vector3 getColumnX();
		Vector3 getColumnY();
		Vector3 getColumnZ();


		Vector3 getTranslate();
		Vector3 getScale();
		Quaternion getRotate();

		void set(float v00,float v01,float v02,float v03,
				float v10,float v11,float v12,float v13,
				float v20,float v21,float v22,float v23,
				float v30,float v31,float v32,float v33)
		{
			m00=v00;m01=v01;m02=v02;m03=v03;
			m10=v10;m11=v11;m12=v12;m13=v13;
			m20=v20;m21=v21;m22=v22;m23=v23;
			m30=v30;m31=v31;m32=v32;m33=v33;
		}
	protected:
		void rawSetRotateFromEuler(float rx,float ry,float rz,int type);

};
NS_FS_END
#endif  /*_FS_MATH_MATRIX4_H_*/






