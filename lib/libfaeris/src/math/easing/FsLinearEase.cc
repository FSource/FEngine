#include "FsLinearEase.h"



NS_FS_BEGIN

const char* LinearEase::className()
{
	return FS_LINEAR_EASE_CLASS_NAME;

}

LinearEase* LinearEase::create()
{
	return new LinearEase();
}


float LinearEase::getEaseIn(float t)
{
	return EasingUtil::easeNone(t);
}

float LinearEase::getEaseOut(float t)
{
	return EasingUtil::easeNone(t);
}

float LinearEase::getEaseInOut(float t)
{
	return EasingUtil::easeNone(t);
}

float LinearEase::getEaseOutIn(float t)
{
	return EasingUtil::easeNone(t);
}






NS_FS_END





