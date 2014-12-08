#include <math.h>
#include "FsEasingUtil.h"
#include "FsBezierEase.h"

NS_FS_BEGIN

const char* BezierEase::className()
{
	return FS_BEZIER_EASE_CLASS_NAME;
}


BezierEase* BezierEase::create(const Vector2& v1,const Vector2& v2)
{
	BezierEase* ret=new BezierEase(v1,v2);
	return ret;
}

BezierEase* BezierEase::create(float p1_x,float p1_y,float p2_x,float p2_y)
{
	BezierEase* ret=new BezierEase(p1_x,p1_y,p2_x,p2_y);
	return ret;
}

float BezierEase::getEaseIn(float t)
{
	return solve(t,m_epsion);
}

BezierEase::BezierEase(const Vector2& v1,const Vector2& v2)
{
	init(v1.x,v1.y,v2.x,v2.y);
}

BezierEase::BezierEase(float p1_x,float p1_y,float p2_x,float p2_y)
{
	init(p1_x,p1_y,p2_x,p2_y);

}





void BezierEase::init(float p1_x,float p1_y,float p2_x,float p2_y)
{
	m_cx=3.0f*p1_x;
	m_bx=3.0f*(p2_x-p1_x)-m_cx;
	m_ax=1.0f-m_cx-m_bx;

	m_cy=3.0f*p1_y;
	m_by=3.0f*(p2_y-p1_y)-m_cy;
	m_ay=1.0f-m_cy-m_by;
}

float BezierEase::sampleCurveX(float t)
{
	return ((m_ax*t+m_bx)*t+m_cx)*t;
}

float BezierEase::sampleCurveY(float t)
{
	return ((m_ay*t+m_by)*t+m_cy)*t;
}

float BezierEase::sampleCurveDerivativeX(float t)
{
	return (3.0f*m_ax*t+2.0f*m_bx)*t+m_cx;
}

float BezierEase::solveCurveX(float x,float epsilon)
{
	float t0,t1,t2,x2,d2;
	int i;

	// First try a few iterations of Newton's method -- normally very fast.
	for (t2 = x, i = 0; i < 8; i++) 
	{
		x2 = sampleCurveX(t2) - x;
		if (fabs (x2) < epsilon)
			return t2;
		d2 = sampleCurveDerivativeX(t2);
		if (fabs(d2) < 1e-6)
			break;
		t2 = t2 - x2 / d2;
	}

	// Fall back to the bisection method for reliability.
	t0 = 0.0f;
	t1 = 1.0f;
	t2 = x;

	if (t2 < t0)
		return t0;

	if (t2 > t1)
		return t1;

	while (t0 < t1) 
	{
		x2 = sampleCurveX(t2);
		if (fabs(x2 - x) < epsilon)
			return t2;
		if (x > x2)
			t0 = t2;
		else
			t1 = t2;
		t2 = (t1 - t0) * 0.5f + t0;
	}

	return t2;
}

float BezierEase::solve(float x,float epsion)
{
	return sampleCurveY(solveCurveX(x,epsion));
}
NS_FS_END 



