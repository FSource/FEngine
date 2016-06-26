#include "FsAnimationEvent.h"


NS_FS_BEGIN 


AnimationEvent::~AnimationEvent()
{

}



E_AnimEventType AttributeAnimationEvent::getEventType()
{
	return E_AnimEventType::ATTRIBUTE;
}


const FsVariant& AttributeAnimationEvent::getValue()
{
	return m_value;
}

const char* AttributeAnimationEvent::getAttributeName()
{
	return m_attrName.c_str();
}


AttributeAnimationEvent::AttributeAnimationEvent(const char* attr_name,const FsVariant& value)
	:m_value(value)
{
	m_attrName=attr_name;
}

AttributeAnimationEvent::~AttributeAnimationEvent()
{

}



NS_FS_END 


