/*************************************************************************/
/*  FsMathUtil.cc                                                        */
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


#include <math.h>
#include <stdlib.h>

#include "FsMathUtil.h"

NS_FS_BEGIN


static float s_cross2d(const Vector2& u,const Vector2& v)
{
	return u.y*v.x-u.x*v.y;
}

bool Math::pointInTriangle2D(const Vector2& point,const Vector2& a,const Vector2& b,const Vector2& c)
{
	Vector2 pa=point.sub(a);
	Vector2 ba=b.sub(a);
	if(s_cross2d(pa,ba)<0.0f) return 0;

	Vector2 pb=point.sub(b);
	Vector2 cb=c.sub(b);
	if(s_cross2d(pb,cb)<0.0f) return 0;


	Vector2 pc=point.sub(c);
	Vector2 ac=a.sub(c);
	if(s_cross2d(pc,ac)<0.0f) return 0;

	return 1;
}

bool Math::pointInRect2D(const Vector2& point,const Matrix4& mat,const Rect2D& rect)
{
	Vector2 a=mat.mulVector2(Vector2(rect.x,rect.y));
	Vector2 b=mat.mulVector2(Vector2(rect.x+rect.width,rect.y));
	Vector2 c=mat.mulVector2(Vector2(rect.x+rect.width,rect.y+rect.height));
	Vector2 d=mat.mulVector2(Vector2(rect.x,rect.y+rect.height));

	if(Math::pointInTriangle2D(point,a,b,c))
	{
		return true;
	}

	if(Math::pointInTriangle2D(point,c,d,a))
	{
		return true;
	}
	return false;

}

NS_FS_END


