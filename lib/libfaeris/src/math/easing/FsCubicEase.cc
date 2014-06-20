#include "FsCubicEase.h"
#include "FsEasingUtil.h"

NS_FS_BEGIN 
const char* CubicEase::className()
{
	return FS_CUBIC_EASE_CLASS_NAME;
}


CubicEase* CubicEase::create()
{
	CubicEase* ret=new CubicEase;
	return ret;
}

float CubicEase::getEaseIn(float t)
{
	return EasingUtil::easeInCubic(t);
}

float CubicEase::getEaseOut(float t)
{
	return EasingUtil::easeOutCubic(t);
}

float CubicEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutCubic(t);
}
float CubicEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInCubic(t);
}

NS_FS_END
