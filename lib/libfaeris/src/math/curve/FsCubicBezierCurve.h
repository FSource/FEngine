#ifndef _FS_CUBIC_BEZIER_CURVE_H_
#define _FS_CUBIC_BEZIER_CURVE_H_

#include "FsMacros.h"
#include "FsCurve.h"

NS_FS_BEGIN
/* Cubic Bezier:
 * 	Formula: 
 * 		B(t) = (1-t)^3*P0 + 3*(1-t)^2*t*P1 + 3(1-t)*t^2*P2 + t^3*P3
 */

template <typename T_Vector>
class CubicBezierCurve:public TCurve<T_Vector>
{

	public:
		void setPoints(const T_Vector& p0,
						const T_Vector& p1,
						const T_Vector& p2,
						const T_Vector& p3)
		{
			m_p0=p0;
			m_p1=p1;
			m_p2=p2;
			m_p3=p3;
		}

		T_Vector getPoint0() { return m_p0; }
		void setPoint0(const T_Vector& v){m_p0=v;}

		T_Vector getPoint1() {return m_p1;}
		void setPoint1(const T_Vector& v){m_p1=v;}

		T_Vector getPoint2() {return m_p2;}
		void setPoint2(const T_Vector& v){m_p2=v;}

		T_Vector getPoint3() {return m_p3;}
		void setPoint3(const T_Vector& v){m_p3=v;}


	public:
		virtual T_Vector getValue(float t)
		{
			float l_t=1-t;

			return  m_p0*l_t*l_t*l_t  +
					m_p1*3*l_t*l_t*t  +
					m_p2*3*l_t*t*t    +
					m_p3*t*t*t;
		}

	protected:
		 CubicBezierCurve(const T_Vector& p0,const T_Vector& p1,
				 		const T_Vector& p2,const T_Vector& p3)
		 {
			 m_p0=p0;
			 m_p1=p1;
			 m_p2=p2;
			 m_p3=p3;
		 }

	private:
		T_Vector m_p0;
		T_Vector m_p1;
		T_Vector m_p2;
		T_Vector m_p3;
};

class CubicBezierCurve2:public CubicBezierCurve<Vector2>
{
	public:
		static CubicBezierCurve2* create(const Vector2& p0,
										const Vector2& p1,
										const Vector2& p2,
										const Vector2& p3);
	public:
		virtual const char* className();

	protected:
		CubicBezierCurve2(const Vector2& p0,const Vector2& p1,
						const Vector2& p2,const Vector2& p3);


};

class CubicBezierCurve3:public CubicBezierCurve<Vector3> 
{

	public:
		static CubicBezierCurve3* create(const Vector3& p0,
										const Vector3& p1,
										const Vector3& p2,
										const Vector3& p3);

	public:
		virtual const char* className();

	protected:
		CubicBezierCurve3(const Vector3& p0,const Vector3& p1,
						const Vector3& p2,const Vector3& p3);

};

class CubicBezierCurve4:public CubicBezierCurve<Vector4>
{
	public:
		static CubicBezierCurve4* create(const Vector4& p0,
										const Vector4& p1,
										const Vector4& p2,
										const Vector4& p3);
	public:
		virtual const char* className();

	protected:
		CubicBezierCurve4(const Vector4& p0,const Vector4& p1,
						 const Vector4& p2,const Vector4& p3);
};



NS_FS_END





#endif /*_FS_CUBIC_BEZIER_CURVE_H_*/

