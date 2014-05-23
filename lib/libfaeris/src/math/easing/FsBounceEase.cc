#include "FsBounceEase.h"



NS_FS_BEGIN

const char* BounceEase::className()
{
	return FS_BOUNCE_EASE_CLASS_NAME;
}


BounceEase* BounceEase::create()
{
	BounceEase* ret=new BounceEase();
	return ret;
}


BounceEase* BounceEase::create(float amplitude)
{
	BounceEase* ret=new BounceEase(amplitude);
	return ret;

}



float BounceEase::getEaseIn(float t)
{
	return EasingUtil::easeInBounce(t,m_amplitude);
}

float BounceEase::getEaseOut(float t)
{
	return EaseUtil::easeOutBounce(t,m_amplitude);
}

float BounceEase::getEaseInOut(float t)
{
	return EaseUtil::easeInOutBounce(t,m_amplitude);
}

float BounceEase::getEaseOutIn(float t)
{
	return EaseUtil::easeOutInBounce(t,m_amplitude);
}


BounceEase::BounceEase(float amplitude)
{
	m_amplitude=amplitude;
}





