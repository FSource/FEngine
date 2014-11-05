#include "math/FsMatrix4.h"
#include "math/FsMathUtil.h"
#include "math/FsVector2.h"

NS_FS_BEGIN

Matrix4 Matrix4::ZERO=Matrix4( 0,0,0,0,
							   0,0,0,0,
							   0,0,0,0,
							   0,0,0,0);

Matrix4 Matrix4::IDENTITY(   1,0,0,0,
							 0,1,0,0,
							 0,0,1,0,
							 0,0,0,1
							);

void Matrix4::add(const Matrix4& n)
{
	m00+=n.m00; m01+=n.m01; m02+=n.m02; m03+=n.m03;
	m10+=n.m10; m11+=n.m11; m12+=n.m12; m13+=n.m13;
	m20+=n.m20; m21+=n.m21; m22+=n.m22; m23+=n.m23;
	m30+=n.m30; m31+=n.m31; m32+=n.m32; m33+=n.m33;
}

void Matrix4::mul(const Matrix4& n)
{
	float t00,t01,t02,t03;
	float t10,t11,t12,t13;
	float t20,t21,t22,t23;
	float t30,t31,t32,t33;

	t00=m00*n.m00+m01*n.m10+m02*n.m20+m03*n.m30;
	t01=m00*n.m01+m01*n.m11+m02*n.m21+m03*n.m31;
	t02=m00*n.m02+m01*n.m12+m02*n.m22+m03*n.m32;
	t03=m00*n.m03+m01*n.m13+m02*n.m23+m03*n.m33;

	t10=m10*n.m00+m11*n.m10+m12*n.m20+m13*n.m30;
	t11=m10*n.m01+m11*n.m11+m12*n.m21+m13*n.m31;
	t12=m10*n.m02+m11*n.m12+m12*n.m22+m13*n.m32;
	t13=m10*n.m03+m11*n.m13+m12*n.m23+m13*n.m33;

	t20=m20*n.m00+m21*n.m10+m22*n.m20+m23*n.m30;
	t21=m20*n.m01+m21*n.m11+m22*n.m21+m23*n.m31;
	t22=m20*n.m02+m21*n.m12+m22*n.m22+m23*n.m32;
	t23=m20*n.m03+m21*n.m13+m22*n.m23+m23*n.m33;

	t30=m30*n.m00+m31*n.m10+m32*n.m20+m33*n.m30;
	t31=m30*n.m01+m31*n.m11+m32*n.m21+m33*n.m31;
	t32=m30*n.m02+m31*n.m12+m32*n.m22+m33*n.m32;
	t33=m30*n.m03+m31*n.m13+m32*n.m23+m33*n.m33;

	set(t00,t01,t02,t03,
			t10,t11,t12,t13,
			t20,t21,t22,t23,
			t30,t31,t32,t33);
}

void Matrix4::mulScaler(float s)
{
	m00*=s; m01*=s; m02*=s; m03*=s;
	m10*=s; m11*=s; m12*=s; m13*=s;
	m20*=s; m21*=s; m22*=s; m23*=s;
	m30*=s; m31*=s; m32*=s; m33*=s;
}

Vector2 Matrix4::mulVector2(const Vector2& v) const
{
	float vx=v.x,vy=v.y;
	float d=1/(m30 * vx + m31 * vy +  m33);
	float rx,ry;
	rx = ( m00 * vx + m01 * vy  + m03 ) * d;
	ry = ( m10 * vx + m11 * vy  + m13 ) * d;
	return Vector2(rx,ry);
}

Vector3 Matrix4::mulVector3(const Vector3& v) const
{
	float vx = v.x, vy = v.y, vz = v.z;
	float d = 1 / ( m30 * vx + m31 * vy + m32 * vz + m33 );
	float rx,ry,rz;
	rx = ( m00 * vx + m01 * vy + m02 * vz + m03 ) * d;
	ry = ( m10 * vx + m11 * vy + m12 * vz + m13 ) * d;
	rz = ( m20 * vx + m21 * vy + m22 * vz + m23 ) * d;
	return Vector3(rx,ry,rz);
}

Vector4 Matrix4::mulVector4(const Vector4& v) const
{
	float vx=v.x, vy=v.y, vz=v.z, vw=v.w;
	float rx,ry,rz,rw;

	rx=m00*vx+m01*vy+m02*vz+m03*vw;
	ry=m10*vx+m11*vy+m12*vz+m13*vw;
	rz=m20*vx+m21*vy+m22*vz+m23*vw;
	rw=m30*vx+m31*vy+m32*vz+m33*vw;

	return Vector4(rx,ry,rz,rw);
}

void Matrix4::transpose()
{
	float tp;
	tp=m10; m10=m01; m01=tp;
	tp=m20; m20=m02; m02=tp;
	tp=m21; m21=m12; m12=tp;
	tp=m30; m30=m03; m03=tp;
	tp=m31; m31=m13; m13=tp;
	tp=m32; m32=m23; m23=tp;
}

void Matrix4::getTranspose(Matrix4* m)
{
	*m=*this;
	m->transpose();
}

void Matrix4::inverse()
{
	float t00,t01,t02,t03;
	float t10,t11,t12,t13;
	float t20,t21,t22,t23;
	float t30,t31,t32,t33;

	float det=getDetermiant();

	FS_TRACE_ERROR_ON(det==0,"Matrix Determiant Is Zero");
	det=1.0f/det;

	t00=m12*m23*m31 - m13*m22*m31 + m13*m21*m32 - m11*m23*m32 - m12*m21*m33 + m11*m22*m33;
	t01=m03*m22*m31 - m02*m23*m31 - m03*m21*m32 + m01*m23*m32 + m02*m21*m33 - m01*m22*m33;
	t02=m02*m13*m31 - m03*m12*m31 + m03*m11*m32 - m01*m13*m32 - m02*m11*m33 + m01*m12*m33;
	t03=m03*m12*m21 - m02*m13*m21 - m03*m11*m22 + m01*m13*m22 + m02*m11*m23 - m01*m12*m23;

	t10=m13*m22*m30 - m12*m23*m30 - m13*m20*m32 + m10*m23*m32 + m12*m20*m33 - m10*m22*m33;
	t11=m02*m23*m30 - m03*m22*m30 + m03*m20*m32 - m00*m23*m32 - m02*m20*m33 + m00*m22*m33;
	t12=m03*m12*m30 - m02*m13*m30 - m03*m10*m32 + m00*m13*m32 + m02*m10*m33 - m00*m12*m33;
	t13=m02*m13*m20 - m03*m12*m20 + m03*m10*m22 - m00*m13*m22 - m02*m10*m23 + m00*m12*m23;

	t20=m11*m23*m30 - m13*m21*m30 + m13*m20*m31 - m10*m23*m31 - m11*m20*m33 + m10*m21*m33;
	t21=m03*m21*m30 - m01*m23*m30 - m03*m20*m31 + m00*m23*m31 + m01*m20*m33 - m00*m21*m33;
	t22=m01*m13*m30 - m03*m11*m30 + m03*m10*m31 - m00*m13*m31 - m01*m10*m33 + m00*m11*m33;
	t23=m03*m11*m20 - m01*m13*m20 - m03*m10*m21 + m00*m13*m21 + m01*m10*m23 - m00*m11*m23;

	t30=m12*m21*m30 - m11*m22*m30 - m12*m20*m31 + m10*m22*m31 + m11*m20*m32 - m10*m21*m32;
	t31=m01*m22*m30 - m02*m21*m30 + m02*m20*m31 - m00*m22*m31 - m01*m20*m32 + m00*m21*m32;
	t32=m02*m11*m30 - m01*m12*m30 - m02*m10*m31 + m00*m12*m31 + m01*m10*m32 - m00*m11*m32;
	t33=m01*m12*m20 - m02*m11*m20 + m02*m10*m21 - m00*m12*m21 - m01*m10*m22 + m00*m11*m22;


	set(t00*det,t01*det,t02*det,t03*det,
			t10*det,t11*det,t12*det,t13*det,
			t20*det,t21*det,t22*det,t23*det,
			t30*det,t31*det,t32*det,t33*det);
}


void Matrix4::getInverse(Matrix4* m)
{
	*m=*this;
	m->inverse();
}

float Matrix4::getDetermiant()
{
	float r=m03 * m12 * m21 * m30-
		m02 * m13 * m21 * m30-
		m03 * m11 * m22 * m30+
		m01 * m13 * m22 * m30+

		m02 * m11 * m23 * m30-
		m01 * m12 * m23 * m30-
		m03 * m12 * m20 * m31+
		m02 * m13 * m20 * m31+

		m03 * m10 * m22 * m31-
		m00 * m13 * m22 * m31-
		m02 * m10 * m23 * m31+
		m00 * m12 * m23 * m31+

		m03 * m11 * m20 * m32-
		m01 * m13 * m20 * m32-
		m03 * m10 * m21 * m32+
		m00 * m13 * m21 * m32+

		m01 * m10 * m23 * m32-
		m00 * m11 * m23 * m32-
		m02 * m11 * m20 * m33+
		m01 * m12 * m20 * m33+

		m02 * m10 * m21 * m33-
		m00 * m12 * m21 * m33-
		m01 * m10 * m22 * m33+
		m00 * m11 * m22 * m33;
	return r;
}

/* aux function to quick change Matrix4 */
void Matrix4::makeTranslate(float x,float y,float z)
{
	set(1,0,0,x,
		0,1,0,y,
		0,0,1,z,
		0,0,0,1);
}
void Matrix4::makeRotateX(float theta)
{
	float c=Math::cosa(theta);
	float s=Math::sina(theta);
	set(    1,0,0,0,
			0,c,-s,0,
			0,s,c,0,
			0,0,0,1);
}

void Matrix4::makeRotateY(float theta)
{
	float c=Math::cosa(theta);
	float s=Math::sina(theta);
	set(    c,0,s,0,
			0,1,0,0,
			-s,0,c,0,
			0,0,0,1);
}

void Matrix4::makeRotateZ(float theta)
{
	float c=Math::cosa(theta);
	float s=Math::sina(theta);
	set(    c,-s,0,0,
			s,c,0,0,
			0,0,1,0,
			0,0,0,1);
}

void Matrix4::makeRotateAxis(float x,float y,float z,float theta)
{

	float n=Math::sqrt(x*x+y*y+z*z);
	x=x/n;y=y/n;z=z/n;

	float s=Math::sina(theta);
	float c=Math::cosa(theta);
	float k=1-c; 
	float xk=x*k; float yk=y*k;

	set(    x*xk+c,		x*yk-s*z,	xk*z+y*s,	0,
			xk*y+z*s,	y*yk+c,		yk*z-x*s,	0,
			xk*z-y*s,	yk*z+x*s,	k*z*z+c,	0,
			0,			0,			0,			1);
}

void Matrix4::makeRotateFromEuler(float x,float y,float z,E_EulerOrientType type)
{
	rawSetRotateFromEuler(x,y,z,type);
	m03=0;m13=0;m23=0;
	m30=0;m31=0;m32=0;m33=1;
}

void Matrix4::makeRotateFromQuaternion(const Quaternion& q)
{
	float x = q.x, y = q.y, z = q.z, w = q.w;
	float x2 = x + x, y2 = y + y, z2 = z + z;
	float xx = x * x2, xy = x * y2, xz = x * z2;
	float yy = y * y2, yz = y * z2, zz = z * z2;
	float wx = w * x2, wy = w * y2, wz = w * z2;

	m00 = 1 - ( yy + zz );
	m01 = xy - wz;
	m02 = xz + wy;

	m10 = xy + wz;
	m11 = 1 - ( xx + zz );
	m12 = yz - wx;

	m20 = xz - wy;
	m21 = yz + wx;
	m22 = 1 - ( xx + yy );

	m30=0;
	m31=0;
	m32=0;

	m03=0;
	m13=0;
	m23=0;
	m33=1;
} 

void Matrix4::makeScale(float x,float y,float z)
{
	set(    x,0,0,0,
			0,y,0,0,
			0,0,z,0,
			0,0,0,1);
}
void Matrix4::makeIdentity()
{
	set(    1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			0,0,0,1
	   );
}
void Matrix4::makeLookAt(const Vector3& eye,const Vector3& target,const Vector3& up)
{
	Vector3 forward=target.sub(eye);
	forward.normalize();   

	Vector3 side=forward.cross(up);
	side.normalize();

	Vector3 real_up=side.cross(forward);

	m00=side.x; m01=real_up.x; m02=-forward.x;  m03=0;
	m10=side.y; m11=real_up.y; m12=-forward.y;  m13=0;
	m20=side.z; m21=real_up.z; m22=-forward.z;  m23=0;
	m30=0;		m31=0;	  m32=0;		   m33=0;

	translate(-eye.x,-eye.y,-eye.z);
}

void Matrix4::makeFrustum(float left,float right,float bottom,float top,float near,float far)
{
	float x = 2 * near / ( right - left );
	float y = 2 * near / ( top - bottom );

	float a = ( right + left ) / ( right - left );
	float b = ( top + bottom ) / ( top - bottom );
	float c = - ( far + near ) / ( far - near );
	float d = - 2 * far * near / ( far - near );

	m00 = x;  m01 = 0;  m02 = a;   m03 = 0;
	m10 = 0;  m11 = y;  m12 = b;   m13 = 0;
	m20 = 0;  m21 = 0;  m22 = c;   m23 = d;
	m30 = 0;  m31 = 0;  m32 = - 1; m33 = 0;
}
void Matrix4::makePerspective(float fov,float aspect,float near,float far)
{
	float ymax = near * Math::tana( fov );
	float ymin = - ymax;
	float xmin = ymin * aspect;
	float xmax = ymax * aspect;

	makeFrustum( xmin, xmax, ymin, ymax, near, far );
}
void Matrix4::makeOrthographic(float left,float right,float bottom,float top,float near,float far)
{
	float w = right - left;
	float h = top - bottom;
	float p = far - near;

	float x = ( right + left ) / w;
	float y = ( top + bottom ) / h;
	float z = ( far + near ) / p;

	m00 = 2 / w; m01 = 0;     m02 = 0;      m03 = -x;
	m10 = 0;     m11 = 2 / h; m12 = 0;      m13 = -y;
	m20 = 0;     m21 = 0;     m22 = -2 / p; m23 = -z;
	m30 = 0;     m31 = 0;     m32 = 0;      m33 = 1;

}

void Matrix4::setTranslate(float x,float y,float z)
{
	m03=x;
	m13=y;
	m23=z;
}

void Matrix4::setRotationFromEuler(float rx,float ry,float rz,E_EulerOrientType type)
{
	/* get scale information */
	Vector3 scale=getScale();


	/* set rotation */
	rawSetRotateFromEuler(rx,ry,rz,type);

	/* apply scale info */
	m00*=scale.x; m01*=scale.y; m02*=scale.z;
	m10*=scale.x; m11*=scale.y; m12*=scale.z;
	m20*=scale.x; m21*=scale.y; m22*=scale.z;
}






void Matrix4::setScale(float sx,float sy,float sz)
{
	/* FIXME:need format m30,m32,m32 here? */

	float rsx=sx/Math::sqrt(m00*m00+m10*m10+m20*m20);
	float rsy=sy/Math::sqrt(m01*m01+m11*m11+m21*m21);
	float rsz=sz/Math::sqrt(m02*m02+m12*m12+m22*m22);

	m00*=rsx; m01*=rsy; m02*=rsz;
	m10*=rsx; m11*=rsy; m12*=rsz;
	m20*=rsx; m21*=rsy; m22*=rsz;
}


void Matrix4::translate(float x,float y,float z)
{
	m03=m00*x+m01*y+m02*z+m03;
	m13=m10*x+m11*y+m12*z+m13;
	m23=m20*x+m21*y+m22*z+m23;
	m33=m30*x+m31*y+m32*z+m33;
}

void Matrix4::rotateX(float angle)
{
	float c=Math::cosa(angle);
	float s=Math::sina(angle);

	float n01,n02;
	float n11,n12;
	float n21,n22;
	float n31,n32;

	n01=m01*c+m02*s; n02=-m01*s+m02*c;
	n11=m11*c+m12*s; n12=-m11*s+m12*c;
	n21=m21*c+m22*s; n22=-m21*s+m22*c;
	n31=m31*c+m32*s; n32=-m31*s+m32*c;

	m01=n01;m02=n02;
	m11=n11;m12=n12;
	m21=n21;m22=n22;
	m31=n31;m32=n32;

}

void Matrix4::rotateY(float angle)
{
	float c=Math::cosa(angle);
	float s=Math::sina(angle);

	float n00,n02;
	float n10,n12;
	float n20,n22;
	float n30,n32;

	n00=m00*c-m02*s; n02=m00*s+m02*c;
	n10=m10*c-m12*s; n12=m10*s+m12*c;
	n20=m20*c-m22*s; n22=m20*s+m22*c;
	n30=m30*c-m32*s; n32=m30*s+m32*c;


	m00=n00; m02=n02;
	m10=n10; m12=n12;
	m20=n20; m22=n22;
	m30=n30; m32=n32;
}


void Matrix4::rotateZ(float angle)
{
	float c=Math::cosa(angle);
	float s=Math::sina(angle);

	float n00,n01;
	float n10,n11;
	float n20,n21;
	float n30,n31;


	n00=m00*c+m01*s; n01=-m00*s+m01*c;
	n10=m10*c+m11*s; n11=-m10*s+m11*c;
	n20=m20*c+m21*s; n21=-m20*s+m21*c;
	n30=m30*c+m31*s; n31=-m30*s+m31*c;

	m00=n00; m01=n01;
	m10=n10; m11=n11;
	m20=n20; m21=n21;
	m30=n30; m31=n31;
}


void Matrix4::rotateByAxis(float vx,float vy,float vz,float angle)
{
	if(vx!=0&&vy==0&&vz==0)
	{
		rotateX(angle);
		return;
	}
	else if(vx==0&&vy!=0&&vz==0)
	{
		rotateY(angle);
		return;
	}
	else if(vx==0&&vy==0&&vz!=0)
	{
		rotateZ(angle);
		return;
	}
	else if(vx==0&&vy==0&&vz==0)
	{
		FS_TRACE_WARN("Rotate Is Zero");
		return;
	}

	Matrix4 ro_mat;
	ro_mat.makeRotateAxis(vx,vy,vz,angle);
	this->mul(ro_mat);
}

void Matrix4::scale(float x,float y,float z)
{
	m00*=x; m01*=y; m02*=z;
	m10*=x; m11*=y; m12*=z;
	m20*=x; m21*=y; m22*=z;
	m30*=x; m31*=y; m32*=z;
}


void Matrix4::makeCompose(const Vector3& translate,const Quaternion& q,const Vector3& s)
{
	this->makeRotateFromQuaternion(q);
	this->scale(s);
	this->setTranslate(translate);
}


void Matrix4::makeCompose(const Vector3& t,const Vector3& r,E_EulerOrientType r_type,const Vector3& s)
{
	rawSetRotateFromEuler(r.x,r.y,r.z,r_type);

	m00*=s.x;  m01*=s.y;  m02*=s.z;  m03=t.x;
	m10*=s.x;  m11*=s.y;  m12*=s.z;  m13=t.y;
	m20*=s.x;  m21*=s.y;  m22*=s.z;  m23=t.z;
	m30=0;     m31=0;     m32=0;     m33=1;
}

/*
void Matrix4::decompose(Vector3* translate,Quaternion* q,Vector3* s)
{
	Vector3 v_x(m00,m10,m20);
	Vector3 v_y(m01,m11,m21);
	Vector3 v_z(m02,m12,m22);

	s->x=v_x.length();
	s->y=v_y.length();
	s->z=v_z.length();

	translation->x=m03;
	translation->y=m13;
	translation->z=m23;

	Matrix4 tc=*this;

	tc.m00/=s->x;
	tc.m10/=s->x;
	tc.m20/=s->x;


	tc.m01/=s->y;
	tc.m11/=s->y;
	tc.m21/=s->y;

	tc.m02/=s->z;
	tc.m12/=s->z;
	tc.m22/=s->z;

	q->setFromRotationMatrix(tc);
}
*/

Vector3 Matrix4::getColumnX()
{
	return Vector3(m00,m10,m20);
}
Vector3 Matrix4::getColumnY()
{
	return Vector3(m01,m11,m21);
}
Vector3 Matrix4::getColumnZ()
{
	return Vector3(m02,m12,m22);
}

Vector3 Matrix4::getTranslate()
{
	return Vector3(m03,m13,m23);
}

Vector3 Matrix4::getScale()
{
	float sx=Math::sqrt(m00*m00+m10*m10+m20*m20);
	float sy=Math::sqrt(m01*m01+m11*m11+m21*m21);
	float sz=Math::sqrt(m02*m02+m12*m12+m22*m22);
	return Vector3(sx,sy,sz);
}


/*
Quaternion Matrix4::getRotate()
{

	float sx=sqrt(m00*m00+m10*m10+m20*m20);
	float sy=sqrt(m01*m01+m11*m11+m21*m21);
	float sz=sqrt(m02*m02+m12*m12+m22*m22);

	Matrix4 tc=*this;

	tc.m00/=sx;
	tc.m10/=sx;
	tc.m20/=sx;


	tc.m01/=sy;
	tc.m11/=sy;
	tc.m21/=sy;

	tc.m02/=sz;
	tc.m12/=sz;
	tc.m22/=sz;

	return Quaternion(tc);
}

*/



void Matrix4::rawSetRotateFromEuler(float rx,float ry,float rz,E_EulerOrientType type)
{
	float cx = Math::cosa( rx );  //a
	float sx = Math::sina( rx );  //b

	float cy = Math::cosa( ry );  //c 
	float sy = Math::sina( ry );  //d

	float cz = Math::cosa( rz );  //e
	float sz = Math::sina( rz );  //f

	switch(type)
	{
		case E_EulerOrientType::XYZ:
			m00=cy*cz;	
			m01=-cy*sz;  
			m02=sy;

			m10=sx*sy*cz+cx*sz;
			m11=-sx*sy*sz+cx*cz;
			m12=-sx*cy;

			m20=-cx*sy*cz+sx*sz;
			m21=cx*sy*sz+sx*cz;
			m22=cx*cy;
			break;
		case E_EulerOrientType::XZY:
			m00=cz*cy;
			m01=-sz;
			m02=cz*sy;

			m10=cx*sz*cy+sx*sy;
			m11=cx*cz;
			m12=cx*sz*sy-sx*cy;

			m20=sx*sz*cy-cx*sy;
			m21=sx*cz;
			m22=sx*sz*sy+cx*cy;
			break;

		case E_EulerOrientType::YXZ:
			m00=cy*cz+sy*sx*sz;
			m01=-cy*sz+sy*sx*cz;
			m02=sy*cx;

			m10=cx*sz;
			m11=cx*cz;
			m12=-sx;

			m20=-sy*cz+cy*sx*sz;
			m21=sy*sz+cy*sx*cz;
			m22=cy*cx;
			break;

		case E_EulerOrientType::YZX:
			m00=cy*cz;
			m01=-cy*sz*cx+sy*sx;
			m02=cy*sz*sx+sy*cx;

			m10=sz;
			m11=cz*cx;
			m12=-cz*sx;

			m20=-sy*cz;
			m21=sy*sz*cx+cy*sx;
			m22=-sy*sz*sx+cy*cx;
			break;
		case E_EulerOrientType::ZXY:
			m00=cz*cy-sz*sx*sy;
			m01=-sz*cx;
			m02=cz*sy+sz*sx*cy;

			m10=sz*cy+cz*sx*sy;
			m11=cz*cx;
			m12=sz*sy-cz*sx*cy;

			m20=-cx*sy;
			m21=sx;
			m22=cx*cy;
			break;

		case E_EulerOrientType::ZYX:
			m00=cz*cy;
			m01=-sz*cx+cz*sy*sx;
			m02=sz*sx+cz*sy*cx;

			m10=sz*cy;
			m11=cz*cx+sz*sy*sx;
			m12=-cz*sx+sz*sy*cx;

			m20=-sy;
			m21=cy*sx;
			m22=cy*cx;
			break;
		default:
			FS_TRACE_ERROR("Unkown EULER Type");
	}

}


NS_FS_END











