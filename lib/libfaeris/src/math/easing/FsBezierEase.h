/*************************************************************************/
/*  FsBezierEase.h                                                       */
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


#ifndef _FS_BEZIER_EASE_H_
#define _FS_BEZIER_EASE_H_

#include "FsMacros.h"
#include "math/FsVector2.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN

class BezierEase:public EaseExpr 
{
	public:
		static BezierEase* create(const Vector2& v1,const Vector2& v2);
		static BezierEase* create(float p1_x,float p1_y,float p2_x,float p2_y);

	public:
		virtual float getEaseIn(float t);
		virtual const char* className();

	protected:
		BezierEase(const Vector2& v1,const Vector2& v2);
		BezierEase(float p1_x,float p1_y,float p2_x,float p2_y);

		float sampleCurveX(float t);
		float sampleCurveY(float t);
		float sampleCurveDerivativeX(float t);
		float solveCurveX(float x,float epsion);
		float solve(float x,float epsion);

		void init(float p1_x,float p1_y,float p2_x,float p2_y);

	private:
		float m_ax,m_bx,m_cx;
		float m_ay,m_by,m_cy;

		float m_epsion;
};



NS_FS_END 


#endif /*_FS_BEZIER_EASE_H_*/

