/*************************************************************************/
/*  FsEasingUtil.cc                                                      */
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
#include "FsEasingUtil.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif
#ifndef M_PI_2
#define M_PI_2 (M_PI / 2)
#endif

NS_FS_BEGIN


float EasingUtil::easeNone(float t)
{
	return t;
}

/* quadratic (t^2) */
float EasingUtil::easeInQuad(float t)
{
	return t*t;
}

float EasingUtil::easeOutQuad(float t)
{
	return -t*(t-2);
}
float EasingUtil::easeInOutQuad(float t)
{
    t*=2.0f;
    if (t < 1) {
        return t*t/2.0f;
    } else {
        --t;
        return -0.5f * (t*(t-2) - 1);
    }
}
float EasingUtil::easeOutInQuad(float t)
{
    if (t < 0.5f) return easeOutQuad (t*2)/2;
    return easeInQuad((2*t)-1)/2 + 0.5f;
}


/* cubic (t^3) */
float EasingUtil::easeInCubic(float t)
{
    return t*t*t;
}
float EasingUtil::easeOutCubic(float t)
{
    t-=1.0f;
    return t*t*t + 1;
}
float EasingUtil::easeInOutCubic(float t)
{
    t*=2.0f;
    if(t < 1) {
        return 0.5f*t*t*t;
    } else {
        t -= 2.0f;
        return 0.5f*(t*t*t + 2);
    }
}

float EasingUtil::easeOutInCubic(float t)
{
    if (t < 0.5f) return easeOutCubic (2*t)/2;
    return easeInCubic(2*t - 1)/2 + 0.5f;
}


/* quartic (t^4) */
float EasingUtil::easeInQuart(float t)
{
    return t*t*t*t;
}
float EasingUtil::easeOutQuart(float t)
{
    t-= 1.0f;
    return - (t*t*t*t- 1);
}

float EasingUtil::easeInOutQuart(float t)
{
    t*=2;
    if (t < 1) return 0.5f*t*t*t*t;
    else {
        t -= 2.0f;
        return -0.5f * (t*t*t*t- 2);
    }
}
float EasingUtil::easeOutInQuart(float t)
{
    if (t < 0.5f) return easeOutQuart (2*t)/2;
    return easeInQuart(2*t-1)/2 + 0.5f;
}


/* quintic (t^5) */ 
float EasingUtil::easeInQuint(float t)
{
    return t*t*t*t*t;
}

float EasingUtil::easeOutQuint(float t)
{
    t-=1.0f;
    return t*t*t*t*t + 1;
}
float EasingUtil::easeInOutQuint(float t)
{
    t*=2.0f;
    if (t < 1) return 0.5f*t*t*t*t*t;
    else {
        t -= 2.0f;
        return 0.5f*(t*t*t*t*t + 2);
    }
}

float EasingUtil::easeOutInQuint(float t)
{
    if (t < 0.5f) return easeOutQuint (2*t)/2;
    return easeInQuint(2*t - 1)/2 + 0.5f;
}


/* sine  (sin(t)) */
float EasingUtil::easeInSine(float t)
{
    return (t == 1.0f) ? 1.0f : -cosf(t * M_PI_2) + 1.0f;
}
float EasingUtil::easeOutSine(float t)
{
    return sin(t* M_PI_2);
}
float EasingUtil::easeInOutSine(float t)
{
    return -0.5f * (cos(M_PI*t) - 1);
}
float EasingUtil::easeOutInSine(float t)
{
    if (t < 0.5f) return easeOutSine (2*t)/2;
    return easeInSine(2*t - 1)/2 + 0.5f;
}

/* exponential (2^t) */
float EasingUtil::easeInExpo(float t)
{
    return (t==0 || t == 1.0f) ? t : pow(2.0f, 10 * (t - 1)) - 0.001f;
}
float EasingUtil::easeOutExpo(float t)
{
    return (t==1.0f) ? 1.0f : 1.001f * (-pow(2.0f, -10 * t) + 1);
}

float EasingUtil::easeInOutExpo(float t)
{
    if (t==0.0f) return 0.0f;
    if (t==1.0f) return 1.0f;
    t*=2.0f;
    if (t < 1) return 0.5f * pow(2.0f, 10 * (t - 1)) - 0.0005f;
    return 0.5f * 1.0005f * (-pow(2.0f, -10 * (t - 1)) + 2);
}
float EasingUtil::easeOutInExpo(float t)
{
    if (t < 0.5f) return easeOutExpo (2*t)/2;
    return easeInExpo(2*t - 1)/2 + 0.5f;
}



/* circular (sqrt(1-t^2)) */
float EasingUtil::easeInCirc(float t)
{
    return -(sqrt(1 - t*t) - 1);
}
float EasingUtil::easeOutCirc(float t)
{
    t-= 1.0f;
    return sqrt(1 - t* t);

}
float EasingUtil::easeInOutCirc(float t)
{
    t*=2.0f;
    if (t < 1) {
        return -0.5f * (sqrt(1 - t*t) - 1);
    } else {
        t -= 2.0f;
        return 0.5f * (sqrt(1 - t*t) + 1);
    }
}

float EasingUtil::easeOutInCirc(float t)
{
    if (t < 0.5f) return easeOutCirc (2*t)/2;
    return easeInCirc(2*t - 1)/2 + 0.5f;
}




/* elastic (exponentially decaying sine wave) */

static float S_EaseInElasitic_Helper(float t,float b,float c,float d,float a, float p)
{
    if (t==0) return b;
    float t_adj = (float)t / (float)d;
    if (t_adj==1) return b+c;

    float s;
    if(a < fabs(c)) {
        a = c;
        s = p / 4.0f;
    } else {
        s = p / (2 * M_PI) * asin(c / a);
    }

    t_adj -= 1.0f;
    return -(a*pow(2.0f,10*t_adj) * sin( (t_adj*d-s)*(2*M_PI)/p )) + b;
}

float EasingUtil::easeInElastic(float t,float a,float p)
{
    return S_EaseInElasitic_Helper(t, 0, 1, 1, a, p);
}

static float S_EaseOutElastic_Helper(float t,float b,float c,float d,float a,float p)
{
    if (t==0) return 0;
    if (t==1) return c;

    float s;
    if(a < c) {
        a = c;
        s = p / 4.0f;
    } else {
        s = p / (2 * M_PI) * asin(c / a);
    }

    return (a*pow(2.0f,-10*t) * sin( (t-s)*(2*M_PI)/p ) + c);
}



float EasingUtil::easeOutElastic(float t,float a,float p)
{
    return S_EaseOutElastic_Helper(t, 0, 1, 1, a, p);
}

float EasingUtil::easeInOutElastic(float t,float a,float p)
{
    if (t==0) return 0.0f;
    t*=2.0f;
    if (t==2) return 1.0f;

    float s;
    if(a < 1.0f) {
        a = 1.0f;
        s = p / 4.0f;
    } else {
        s = p / (2 * M_PI) * asin(1.0f / a);
    }

    if (t < 1) return -0.5f*(a*pow(2.0f,10*(t-1)) * sin( (t-1-s)*(2*M_PI)/p ));
    return a*pow(2.0f,-10*(t-1)) * sin( (t-1-s)*(2*M_PI)/p )*0.5f + 1.0f;
}

float EasingUtil::easeOutInElastic(float t,float a,float p)
{
    if (t < 0.5f) return S_EaseOutElastic_Helper(t*2, 0, 0.5f, 1.0f, a, p);
    return S_EaseInElasitic_Helper(2*t - 1.0f, 0.5f, 0.5f, 1.0f, a, p);
}


/* back */
float EasingUtil::easeInBack(float t,float s)
{
    return t*t*((s+1)*t - s);
}

float EasingUtil::easeOutBack(float t,float s)
{
    t-= float(1.0f);
    return t*t*((s+1)*t+ s) + 1;
}
float EasingUtil::easeInOutBack(float t,float s)
{
    t *= 2.0f;
    if (t < 1) {
        s *= 1.525f;
        return 0.5f*(t*t*((s+1)*t - s));
    } else {
        t -= 2;
        s *= 1.525f;
        return 0.5f*(t*t*((s+1)*t+ s) + 2);
    }

}
float EasingUtil::easeOutInBack(float t,float s)
{
    if (t < 0.5f) return easeOutBack (2*t, s)/2;
    return easeInBack(2*t - 1, s)/2 + 0.5f;
}


/* bounce (exponentially decaying parabolic bounce) */

float S_EaseOutBounce_Helper(float t,float c,float a)
{
    if (t == 1.0f) return c;
    if (t < (4/11.0f)) {
        return c*(7.5625f*t*t);
    } else if (t < (8/11.0f)) {
        t -= (6/11.0f);
        return -a * (1.0f - (7.5625f*t*t + 0.75f)) + c;
    } else if (t < (10/11.0f)) {
        t -= (9/11.0f);
        return -a * (1.0f - (7.5625f*t*t + 0.9375f)) + c;
    } else {
        t -= (21/22.0f);
        return -a * (1.0f - (7.5625f*t*t + 0.984375f)) + c;
    }
}

float EasingUtil::easeInBounce(float t,float a)
{
    return 1.0f - S_EaseOutBounce_Helper(1.0f-t, 1.0f, a);

}
float EasingUtil::easeOutBounce(float t,float a)
{
    return S_EaseOutBounce_Helper(t, 1, a);
}

float EasingUtil::easeInOutBounce(float t,float a)
{
    if (t < 0.5f) return easeInBounce (2*t, a)/2;
    else return (t == 1.0f) ? 1.0f : easeOutBounce (2*t - 1, a)/2 + 0.5f;
}
float EasingUtil::easeOutInBounce(float t,float a)
{
    if (t < 0.5f) return S_EaseOutBounce_Helper(t*2, 0.5f, a);
    return 1.0f - S_EaseOutBounce_Helper(2.0f-2*t, 0.5f, a);

}

NS_FS_END

