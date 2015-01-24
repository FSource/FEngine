/*************************************************************************/
/*  FsLinearCurve.cc                                                     */
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


#include "FsLinearCurve.h"


NS_FS_BEGIN

/* LinearCurve2 */
LinearCurve2* LinearCurve2::create(const Vector2& b,const Vector2& e)
{
	return new LinearCurve2(b,e);
}

const char* LinearCurve2::className()
{
	return FS_LINEAR_CURVE_2_CLASS_NAME;
}

LinearCurve2::LinearCurve2(const Vector2& b,const Vector2& e)
	:TLinearCurve<Vector2>(b,e)
{
}



/* LinearCurve3 */
LinearCurve3* LinearCurve3::create(const Vector3& b,const Vector3& e)
{
	return new LinearCurve3(b,e);
}

const char* LinearCurve3::className()
{
	return FS_LINEAR_CURVE_3_CLASS_NAME;
}

LinearCurve3::LinearCurve3(const Vector3& b,const Vector3& e)
	:TLinearCurve<Vector3>(b,e)
{
}


/* LinearCurve4 */
LinearCurve4* LinearCurve4::create(const Vector4& b,const Vector4& e)
{
	return new LinearCurve4(b,e);
}	

const char* LinearCurve4::className()
{
	return FS_LINEAR_CURVE_4_CLASS_NAME;
}

LinearCurve4::LinearCurve4(const Vector4& b,const Vector4& e)
	:TLinearCurve<Vector4>(b,e)
{
}














NS_FS_END

