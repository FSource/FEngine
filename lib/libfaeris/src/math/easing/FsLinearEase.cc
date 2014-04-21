#include "FsLinearEase.h"



NS_FS_BEGIN

LinearEase* LinearEase::create()
{
	return new LinearEase();
}

float LinearEase::getEaseIn(float t)
{
	return t;
}



NS_FS_END





