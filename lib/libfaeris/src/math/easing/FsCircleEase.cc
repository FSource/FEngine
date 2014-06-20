#include "FsCircleEase.h"
#include "FsEasingUtil.h"

NS_FS_BEGIN 
const char* CircleEase::className()
{
	return FS_CIRCLE_EASE_CLASS_NAME;
}


CircleEase* CircleEase::create()
{
	CircleEase* ret=new CircleEase;
	return ret;
}

float CircleEase::getEaseIn(float t)
{
	return EasingUtil::easeInCirc(t);
}

float CircleEase::getEaseOut(float t)
{
	return EasingUtil::easeOutCirc(t);
}

float CircleEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutCirc(t);
}
float CircleEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInCirc(t);
}

NS_FS_END
