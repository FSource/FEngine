/*************************************************************************/
/*  FsBounceEase.cc                                                      */
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


#include "FsBounceEase.h"
#include "FsEasingUtil.h"



NS_FS_BEGIN

const char* BounceEase::className()
{
	return FS_BOUNCE_EASE_CLASS_NAME;
}


BounceEase* BounceEase::create()
{
	BounceEase* ret=new BounceEase(1.0);
	return ret;
}


BounceEase* BounceEase::create(float amplitude)
{
	BounceEase* ret=new BounceEase(amplitude);
	return ret;

}



float BounceEase::getEaseIn(float t)
{
	return EasingUtil::easeInBounce(t,m_amplitude);
}

float BounceEase::getEaseOut(float t)
{
	return EasingUtil::easeOutBounce(t,m_amplitude);
}

float BounceEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutBounce(t,m_amplitude);
}

float BounceEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInBounce(t,m_amplitude);
}


BounceEase::BounceEase(float amplitude)
{
	m_amplitude=amplitude;
}





NS_FS_END