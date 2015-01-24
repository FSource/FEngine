/*************************************************************************/
/*  FsEasingUtil.h                                                       */
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


#ifndef _FS_EASE_UTIL_H_
#define _FS_EASE_UTIL_H_

#include "FsMacros.h"

NS_FS_BEGIN

class EasingUtil
{
	public:
		static float easeNone(float t);

		/* quadratic (t^2) */
		static float easeInQuad(float t);
		static float easeOutQuad(float t);
		static float easeInOutQuad(float t);
		static float easeOutInQuad(float t);


		/* cubic (t^3) */
		static float easeInCubic(float t);
		static float easeOutCubic(float t);
		static float easeInOutCubic(float t);
		static float easeOutInCubic(float t);


		/* quartic (t^4) */
		static float easeInQuart(float t);
		static float easeOutQuart(float t);
		static float easeInOutQuart(float t);
		static float easeOutInQuart(float t);


		/* quintic (t^5) */ 
		static float easeInQuint(float t);
		static float easeOutQuint(float t);
		static float easeInOutQuint(float t);
		static float easeOutInQuint(float t);


		/* sine  (sin(t)) */
		static float easeInSine(float t);
		static float easeOutSine(float t);
		static float easeInOutSine(float t);
		static float easeOutInSine(float t);

		/* exponential (2^t) */
		static float easeInExpo(float t);
		static float easeOutExpo(float t);
		static float easeInOutExpo(float t);
		static float easeOutInExpo(float t);

		/* circular (sqrt(1-t^2)) */
		static float easeInCirc(float t);
		static float easeOutCirc(float t);
		static float easeInOutCirc(float t);
		static float easeOutInCirc(float t);

		/* elastic (exponentially decaying sine wave) */
		static float easeInElastic(float t,float a,float p);
		static float easeOutElastic(float t,float a,float p);
		static float easeInOutElastic(float t,float a,float p);
		static float easeOutInElastic(float t,float a,float p);

		/* back */
		static float easeInBack(float t,float s);
		static float easeOutBack(float t,float s);
		static float easeInOutBack(float t,float s);
		static float easeOutInBack(float t,float s);


		/* bounce (exponentially decaying parabolic bounce) */
		static float easeInBounce(float t,float a);
		static float easeOutBounce(float t,float a);
		static float easeInOutBounce(float t,float a);
		static float easeOutInBounce(float t,float a);


};


NS_FS_END



#endif /*_FS_EASE_UTIL_H_*/




