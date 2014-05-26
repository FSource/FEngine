#include "FsSineEase.h"
#include "FsEasingUtil.h"

NS_FS_BEGIN

SineEase* SineEase::create()
{
	return new SineEase();
}

const char* SineEase::className()
{
	return FS_SINE_EASE_CLASS_NAME;
}

float SineEase::getEaseIn(float t)
{
	return EasingUtil::easeInSine(t);

}
float SineEase::getEaseOut(float t)
{
	return EasingUtil::easeOutSine(t);
}

float SineEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutSine(t);

}

float SineEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInSine(t);
}

NS_FS_END 



