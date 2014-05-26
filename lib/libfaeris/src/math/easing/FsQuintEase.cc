#include "FsQuintEase.h"
#include "FsEasingUtil.h"

NS_FS_BEGIN 
const char* QuintEase::className()
{
	return FS_QUINT_EASE_CLASS_NAME;
}


QuintEase* QuintEase::create()
{
	QuintEase* ret=new QuintEase;
	return ret;
}

float QuintEase::getEaseIn(float t)
{
	return EasingUtil::easeInQuint(t);
}

float QuintEase::getEaseOut(float t)
{
	return EasingUtil::easeOutQuint(t);
}

float QuintEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutQuint(t);
}
float QuintEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInQuint(t);
}

NS_FS_END
