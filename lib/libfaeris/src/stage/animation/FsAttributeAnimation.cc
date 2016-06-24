#include "FsAttributeAnimation.h"

AttributeAnimation* AttributeAnimation::create()
{
	AttributeAnimation* ret=new AttributeAnimation();
	return ret;
}


AttributeAnimation* AttributeAnimation::create(const char* attr_name,FsType type)
{

	AttributeAnimation* ret=new AttributeAnimation();
	ret->setAttributeName(attr_name);
	ret->setValueType(type);
	return ret;
}















