#include "FsElasticEase.h"

NS_FS_BEGIN

const char* ElasticEase::className()
{
	return FS_ELASTIC_EASE_CLASS_NAME;
}

ElasticEase* ElasticEase::create()
{
	ElasticEase* ret=new ElasticEase(0.3,1.0);
	return ret;
}


ElasticEase* ElasticEase::create(float amplitude,float period)
{
	ElasticEase* ret=new ElasticEase(amplitude,period);
	return ret;
}


float ElasticEase::getEaseIn(float t)
{
	return EasingUtil::easeInElastic(t,m_amplitude,m_period);
}

float ElasticEase::getEaseOut(float t)
{
	return EasingUtil::easeOutElastic(t,m_amplitude,m_period);
}

float ElasticEase::getEaseInOut(float t)
{
	return EasingUtil::easeInOutElastic(t,m_amplitude,m_period);
}

float ElasticEase::getEaseOutIn(float t)
{
	return EasingUtil::easeOutInElastic(t,m_amplitude,m_period);
}

ElasticEase::ElasticEase(float amplitude,float period)
{
	m_amplitude=amplitude;
	m_period=period;
}


NS_FS_END 

