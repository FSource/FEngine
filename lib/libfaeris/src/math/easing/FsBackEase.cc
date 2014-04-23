#include "FsBackEase.h"

#define FS_BACK_EASE_AMPLITUDE 1.70158f 
#define FS_BACK_EASE_VALUE 1.525f

NS_FS_BEGIN

BackEase* BackEase::create()
{
	return new BackEase();
	
}


BackEase* BackEase::create(int mode)
{
	return new BackEase(mode);
	
}

float BackEase::getEaseIn(float t)
{
	float s = FS_BACK_EASE_AMPLITUDE;
	return t * t *((s + 1) * t - s);
}

float BackEase::getEaseOut(float t)
{
	float s = FS_BACK_EASE_AMPLITUDE;
	t = t - 1;
	return t * t * ((s + 1)* t + s) + 1;
}

float BackEase::getEaseInOut(float t)
{
	float s = FS_BACK_EASE_AMPLITUDE;
	t = t / 0.5f;
	if(t < 1)
		return 0.5f*(t*t*(((s*=FS_BACK_EASE_VALUE) + 1)*t - s));
	else
		t-=2;
		return 0.5f*(t*t*(((s*=FS_BACK_EASE_VALUE) + 1)*t + s) + 2);
}

float BackEase::getEaseOutIn(float t)
{
	return t;
}

const char* BackEase::className()
{
	return FS_BACK_EASE_CLASS_NAME;

}

BackEase::BackEase():EaseExpr(FS_EASE_IN)
{
	
}

BackEase::BackEase(int mode):EaseExpr(mode)
{
	
}

BackEase::~BackEase()
{
	
}

NS_FS_END
