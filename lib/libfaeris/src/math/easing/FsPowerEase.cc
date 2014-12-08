#include <math.h>
#include "FsPowerEase.h"
#include "FsEasingUtil.h"


NS_FS_BEGIN

PowerEase* PowerEase::create(float p)
{
	PowerEase* ret=new PowerEase(p);
	return ret;
}


const char* PowerEase::className()
{
	return FS_POWER_EASE_CLASS_NAME;
}


float PowerEase::getEaseIn(float t)
{
	return pow(t,m_exponent);
}


PowerEase::PowerEase(float p)
{
	m_exponent=p;
}


NS_FS_END



