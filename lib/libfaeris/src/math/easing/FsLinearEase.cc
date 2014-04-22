#include "FsLinearEase.h"



NS_FS_BEGIN

LinearEase* LinearEase::create()
{
	return new LinearEase();
}

LinearEase* LinearEase::create(int mode)
{
	return new LinearEase(mode);
}

float LinearEase::getEaseIn(float t)
{
	return t;
}

const char* LinearEase::className()
{
	return FS_LINEAR_EASE_CLASS_NAME;

}

LinearEase::LinearEase()
	:EaseExpr(FS_EASE_IN)

{
}
LinearEase::LinearEase(int mode)
	:EaseExpr(mode)
{
}


LinearEase::~LinearEase()
{
}



NS_FS_END





