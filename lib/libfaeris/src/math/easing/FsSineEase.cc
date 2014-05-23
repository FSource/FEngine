#include "FsSineEase.h"

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
	return 1.0f-sin((1.0f-t)*M_PI_2);
}

NS_FS_END 



