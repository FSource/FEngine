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

const char* LinearEase::className()
{
	return FS_LINEAR_EASE_CLASS_NAME;

}



NS_FS_END





