#ifndef _FS_LINEAR_CURVE_H_
#define _FS_LINEAR_CURVE_H_

#include "FsMacros.h"
#include "FsCurve.h"

NS_FS_BEGIN
template<typename T_Vector>
class TLinearCurve:public TCurve<T_Vector>
{
	public:

		void setBegin(const T_Vector& v)
		{
			m_begin=v;
		}

		void setEnd(const T_Vector& v)
		{
			m_end=v;
		}

	public:
		/* inherit TCurve */
		virtual T_Vector getValue(float t)
		{
			return m_begin+(m_end-m_begin)*t;
		}

	protected:
		TLinearCurve(const T_Vector& b,const T_Vector& e)
		{
			m_begin=b;
			m_end=e;
		}

		virtual ~TLinearCurve()
		{

		}

	private:
		T_Vector m_begin;
		T_Vector m_end;
};

class LinearCurve2:public TLinearCurve<Vector2> 
{
	public:
		static LinearCurve2* create(const Vector2& b,const Vector2& e);

	public:
		virtual const char* className();

	protected:
		LinearCurve2(const Vector2& b,const Vector2& a);
};

class LinearCurve3:public TLinearCurve<Vector3>
{
	public:
		static LinearCurve3* create(const Vector3& b,const Vector3& e);

	public:
		virtual const char* className();

	protected:
		LinearCurve3(const Vector3& b,const Vector3& a);

};

class LinearCurve4:public TLinearCurve<Vector4>
{
	public:
		static LinearCurve4* create(const Vector4& b,const Vector4& e);

	public:
		virtual const char* className();

	protected:
		LinearCurve4(const Vector4& b,const Vector4& a);
};






NS_FS_END


#endif /*_FS_LINEAR_CURVE_H_*/


