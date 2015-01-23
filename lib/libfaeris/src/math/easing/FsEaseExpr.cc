/*************************************************************************/
/*  FsEaseExpr.cc                                                        */
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


#include "FsEaseExpr.h"
#include "FsEasingUtil.h"


NS_FS_BEGIN

const char* EaseExpr::className()
{
	return FS_EASE_EXPR_CLASS_NAME;
}

EaseExpr::EaseExpr(int mode)
{
	m_easeMode=mode;
}

EaseExpr::EaseExpr()
{
	m_easeMode=FS_EASE_IN;
}


EaseExpr::~EaseExpr()
{
}


float EaseExpr::getValue(float t)
{
	switch(m_easeMode)
	{
		case FS_EASE_IN: return getEaseIn(t);
		case FS_EASE_OUT: return getEaseOut(t);
		case FS_EASE_INOUT:return getEaseInOut(t);
		case FS_EASE_OUTIN: return getEaseOutIn(t);
	}

	FS_TRACE_WARN("Unkown Ease Mode(%d)",m_easeMode);

	return getEaseIn(t);
}
float EaseExpr::getValue(float t, int mode)
{
	switch(mode)
	{
		case FS_EASE_IN: return getEaseIn(t);
		case FS_EASE_OUT: return getEaseOut(t);
		case FS_EASE_INOUT:return getEaseInOut(t);
		case FS_EASE_OUTIN: return getEaseOutIn(t);
	}

	FS_TRACE_WARN("Unkown Ease Mode(%d)",m_easeMode);

	return getEaseIn(t);
}

void EaseExpr::setMode(int mode)
{
	m_easeMode=mode;
}

int EaseExpr::getMode()
{
	return m_easeMode;
}


float EaseExpr::getEaseOut(float t)
{
	return 1.0f-getEaseIn(1.0f-t);
}

float EaseExpr::getEaseInOut(float t)
{
	if (t<=0.5f )
	{
		return 0.5f*getEaseIn(2*t);
	}

	return 0.5f+0.5f*getEaseOut(2*t-1);
}

float EaseExpr::getEaseOutIn(float t)
{
	if (t<=0.5f)
	{
		return 0.5f*getEaseOut(2*t);
	}

	return 0.5f+0.5f*getEaseIn(2*t-1);
}




NS_FS_END








