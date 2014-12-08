#include <assert.h>
#include "FsEasingUtil.h"
#include "FsBackEase.h"


NS_FS_BEGIN

const char* BackEase::className()
{
	return FS_BACK_EASE_CLASS_NAME;

}

BackEase* BackEase::create()
{
	return new BackEase(1.70158f);
}


BackEase* BackEase::create(float overshoot)
{
	return new BackEase(overshoot);
}


float BackEase::getEaseIn(float t)
{
	return EasingUtil::easeInBack(t,m_overshoot);
}

float BackEase::getEaseOut(float t)
{
	return EasingUtil::easeOutBack(t,m_overshoot);
}

float BackEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutBack(t,m_overshoot);
}

float BackEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInBack(t,m_overshoot);
}


BackEase::BackEase(float overshoot)
{
	m_overshoot=overshoot;
}


NS_FS_END
