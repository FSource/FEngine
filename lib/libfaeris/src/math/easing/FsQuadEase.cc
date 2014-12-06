#include "FsQuadEase.h"
#include "FsEasingUtil.h"

NS_FS_BEGIN 
const char* QuadEase::className()
{
	return FS_QUAD_EASE_CLASS_NAME;
}


QuadEase* QuadEase::create()
{
	QuadEase* ret=new QuadEase;
	return ret;
}

float QuadEase::getEaseIn(float t)
{
	return EasingUtil::easeInQuad(t);
}

float QuadEase::getEaseOut(float t)
{
	return EasingUtil::easeOutQuad(t);
}

float QuadEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutQuad(t);
}
float QuadEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInQuad(t);
}

NS_FS_END
