#include "FsCubicBezierCurve.h"


NS_FS_BEGIN

/* CubicBezierCurve2 */

CubicBezierCurve2* CubicBezierCurve2::create(const Vector2& p0,const Vector2& p1,
		 										const Vector2& p2,const Vector2& p3)
{
	return new CubicBezierCurve2(p0,p1,p2,p3);
}


const char* CubicBezierCurve2::className()
{
	return FS_CUBIC_BEZIER_CURVE_2;
}


CubicBezierCurve2::CubicBezierCurve2(const Vector2& p0,const Vector2& p1,
									const Vector2& p2,const Vector2& p3)
	:CubicBezierCurve<Vector2>(p0,p1,p2,p3)
{
}





/* CubicBezierCurve3 */
CubicBezierCurve3* CubicBezierCurve3::create(const Vector3& p0,const Vector3& p1,
		 										const Vector3& p2,const Vector3& p3)
{
	return new CubicBezierCurve3(p0,p1,p2,p3);
}


const char* CubicBezierCurve3::className()
{
	return FS_CUBIC_BEZIER_CURVE_3;
}


CubicBezierCurve3::CubicBezierCurve3(const Vector3& p0,const Vector3& p1,
									const Vector3& p2,const Vector3& p3)
	:CubicBezierCurve<Vector3>(p0,p1,p2,p3)
{
}


/* CubicBezierCurve4 */
CubicBezierCurve4* CubicBezierCurve4::create(const Vector4& p0,const Vector4& p1,
		 										const Vector4& p2,const Vector4& p3)
{
	return new CubicBezierCurve4(p0,p1,p2,p3);
}


const char* CubicBezierCurve4::className()
{
	return FS_CUBIC_BEZIER_CURVE_4;
}


CubicBezierCurve4::CubicBezierCurve4(const Vector4& p0,const Vector4& p1,
									const Vector4& p2,const Vector4& p3)
	:CubicBezierCurve<Vector4>(p0,p1,p2,p3)
{
}



NS_FS_END