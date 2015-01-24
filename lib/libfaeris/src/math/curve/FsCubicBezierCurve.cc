/*************************************************************************/
/*  FsCubicBezierCurve.cc                                                */
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


#include "FsCubicBezierCurve.h"


NS_FS_BEGIN

/* CubicBezierCurve2 */

CubicBezierCurve2* CubicBezierCurve2::create(const Vector2& p0,const Vector2& p1,
		 										const Vector2& p2,const Vector2& p3)
{
	return new CubicBezierCurve2(p0,p1,p2,p3);
}


const char* CubicBezierCurve2::className()
{
	return FS_CUBIC_BEZIER_CURVE_2;
}


CubicBezierCurve2::CubicBezierCurve2(const Vector2& p0,const Vector2& p1,
									const Vector2& p2,const Vector2& p3)
	:CubicBezierCurve<Vector2>(p0,p1,p2,p3)
{
}





/* CubicBezierCurve3 */
CubicBezierCurve3* CubicBezierCurve3::create(const Vector3& p0,const Vector3& p1,
		 										const Vector3& p2,const Vector3& p3)
{
	return new CubicBezierCurve3(p0,p1,p2,p3);
}


const char* CubicBezierCurve3::className()
{
	return FS_CUBIC_BEZIER_CURVE_3;
}


CubicBezierCurve3::CubicBezierCurve3(const Vector3& p0,const Vector3& p1,
									const Vector3& p2,const Vector3& p3)
	:CubicBezierCurve<Vector3>(p0,p1,p2,p3)
{
}


/* CubicBezierCurve4 */
CubicBezierCurve4* CubicBezierCurve4::create(const Vector4& p0,const Vector4& p1,
		 										const Vector4& p2,const Vector4& p3)
{
	return new CubicBezierCurve4(p0,p1,p2,p3);
}


const char* CubicBezierCurve4::className()
{
	return FS_CUBIC_BEZIER_CURVE_4;
}


CubicBezierCurve4::CubicBezierCurve4(const Vector4& p0,const Vector4& p1,
									const Vector4& p2,const Vector4& p3)
	:CubicBezierCurve<Vector4>(p0,p1,p2,p3)
{
}



NS_FS_END