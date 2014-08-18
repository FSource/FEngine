#include "FsCatmullRomCurve.h"

NS_FS_BEGIN

/* CatmullRomCurve2 */
CatmullRomCurve2* CatmullRomCurve2::create()
{
	return new CatmullRomCurve2();
}

const char* CatmullRomCurve2::className()
{
	return FS_CATMULL_ROM_CURVE_2;
}


/* CatmullRomCurve3 */
CatmullRomCurve3* CatmullRomCurve3::create()
{
	return new CatmullRomCurve3();
}

const char* CatmullRomCurve3::className()
{
	return FS_CATMULL_ROM_CURVE_3;
}

/* CatmullRomCurve4 */
CatmullRomCurve4* CatmullRomCurve4::create()
{
	return new CatmullRomCurve4();
}

const char* CatmullRomCurve4::className()
{
	return FS_CATMULL_ROM_CURVE_4;
}



NS_FS_END 




