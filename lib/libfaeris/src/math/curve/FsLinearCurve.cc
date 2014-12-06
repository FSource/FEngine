#include "FsLinearCurve.h"


NS_FS_BEGIN

/* LinearCurve2 */
LinearCurve2* LinearCurve2::create(const Vector2& b,const Vector2& e)
{
	return new LinearCurve2(b,e);
}

const char* LinearCurve2::className()
{
	return FS_LINEAR_CURVE_2_CLASS_NAME;
}

LinearCurve2::LinearCurve2(const Vector2& b,const Vector2& e)
	:TLinearCurve<Vector2>(b,e)
{
}



/* LinearCurve3 */
LinearCurve3* LinearCurve3::create(const Vector3& b,const Vector3& e)
{
	return new LinearCurve3(b,e);
}

const char* LinearCurve3::className()
{
	return FS_LINEAR_CURVE_3_CLASS_NAME;
}

LinearCurve3::LinearCurve3(const Vector3& b,const Vector3& e)
	:TLinearCurve<Vector3>(b,e)
{
}


/* LinearCurve4 */
LinearCurve4* LinearCurve4::create(const Vector4& b,const Vector4& e)
{
	return new LinearCurve4(b,e);
}	

const char* LinearCurve4::className()
{
	return FS_LINEAR_CURVE_4_CLASS_NAME;
}

LinearCurve4::LinearCurve4(const Vector4& b,const Vector4& e)
	:TLinearCurve<Vector4>(b,e)
{
}














NS_FS_END

