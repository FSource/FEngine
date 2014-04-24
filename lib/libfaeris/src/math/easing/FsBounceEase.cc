#include "FsBounceEase.h"



NS_FS_BEGIN

BounceEase* BounceEase::create()
{
	return new BounceEase();
}


BounceEase* BounceEase::create(int mode)
{
	return new BounceEase(mode);
}

float BounceEase::getEaseIn(float t)
{
	
}
