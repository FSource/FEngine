/*************************************************************************/
/*  FsCurve3Action.cc                                                    */
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


#include "FsCurve3Action.h"

NS_FS_BEGIN

const char* Curve3Action::className()
{
	return FS_CURVE3_ACTION_CLASS_NAME;
}

Curve3Action::Curve3Action()
{
	m_curve=NULL;
	m_markBit=CurveUsedMarkBit::USED_XYZ;
}

void Curve3Action::init(Curve3* curve,float time)
{
	FixTimeAction::setTotalTime(time);
	FS_SAFE_ASSIGN(m_curve,curve);
}


Curve3Action::~Curve3Action()
{
	FS_SAFE_DEC_REF(m_curve);
}

Vector3 Curve3Action::getCurveValue(float t)
{
	return m_curve->getValue(t);
}
















NS_FS_END 

