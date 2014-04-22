#include "FsBackEase.h"

#define FS_BACK_EASE_AMPLITUDE 1.70158f 

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
	return t*t*((s+1)*t-s);
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