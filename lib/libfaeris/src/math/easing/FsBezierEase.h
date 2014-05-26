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

