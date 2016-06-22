/*************************************************************************/
/*  FsLinearCurve.h                                                      */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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


class LinearCurve1:public TLinearCurve<float>
{
	public:
		static LinearCurve1* create(const float& b,const float& e);

	public:
		virtual const char* className();

	protected:
		LinearCurve1(const float& b,const float& a);
}


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


