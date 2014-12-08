#include <math.h>
#include "FsEasingUtil.h"
#include "FsExponentialEase.h"

NS_FS_BEGIN

const char* ExponentialEase::className()
{
	return FS_EXPONENTIAL_EASE_CLASS_NAME;
}

ExponentialEase* ExponentialEase::create()
{
	ExponentialEase* ret=new ExponentialEase();
	return ret;
}



float ExponentialEase::getEaseIn(float t)
{
	return EasingUtil::easeInExpo(t);
}

float ExponentialEase::getEaseOut(float t)
{
	return EasingUtil::easeOutExpo(t);
}

float ExponentialEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutExpo(t);
}

float ExponentialEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInExpo(t);
}


NS_FS_END


