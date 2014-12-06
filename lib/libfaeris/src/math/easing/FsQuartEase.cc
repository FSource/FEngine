#include "FsQuartEase.h"
#include "FsEasingUtil.h"

NS_FS_BEGIN 
const char* QuartEase::className()
{
	return FS_QUART_EASE_CLASS_NAME;
}


QuartEase* QuartEase::create()
{
	QuartEase* ret=new QuartEase;
	return ret;
}

float QuartEase::getEaseIn(float t)
{
	return EasingUtil::easeInQuart(t);
}

float QuartEase::getEaseOut(float t)
{
	return EasingUtil::easeOutQuart(t);
}

float QuartEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutQuart(t);
}
float QuartEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInQuart(t);
}

NS_FS_END
