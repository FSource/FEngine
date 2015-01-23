/*************************************************************************/
/*  FsBackEase.cc                                                        */
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


#include <assert.h>
#include "FsEasingUtil.h"
#include "FsBackEase.h"


NS_FS_BEGIN

const char* BackEase::className()
{
	return FS_BACK_EASE_CLASS_NAME;

}

BackEase* BackEase::create()
{
	return new BackEase(1.70158f);
}


BackEase* BackEase::create(float overshoot)
{
	return new BackEase(overshoot);
}


float BackEase::getEaseIn(float t)
{
	return EasingUtil::easeInBack(t,m_overshoot);
}

float BackEase::getEaseOut(float t)
{
	return EasingUtil::easeOutBack(t,m_overshoot);
}

float BackEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutBack(t,m_overshoot);
}

float BackEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInBack(t,m_overshoot);
}


BackEase::BackEase(float overshoot)
{
	m_overshoot=overshoot;
}


NS_FS_END
