#include "FsAttributeAnimation.h"
#include "FsKeyFrame.h"

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

void AttributeAnimation::insert(float time,const FsVariant& value)
{
	FsVariant fvalue=value.getCast(m_valueType);

	if(fvalue.getType()==FsType::FT_IN_VALID)
	{
		FS_TRACE_WARN("can't add case value to animation type");
		return;
	}

	FsVariantKeyFrame* kf=FsAttributeAnimation::create(time,fvalue,NULL);

	insert(kf);
}

FsType AttributeAnimation::getValueType() const
{
	return m_valueType;
}

void AttributeAnimation::setValueType(FsType type)
{
	m_valueType=type;
}

void AttributeAnimation::setAttributeName(const char* name)
{
	FS_ASSERT(name!=NULL);
	m_attrName=name;
}


const char* AttributeAnimation::getAttributeName()  const 
{
	return m_attrName.c_str();
}

void AttributeAnimation::update(Animator* at,float time,float dt) 
{

}


AttributeAnimation::AttributeAnimation()
{
	m_valueType=FsType::FT_IN_VALID;
	m_attrName="";
}

AttributeAnimation::~AttributeAnimation()
{

}

/** Used For AttributeAnimation Attribute */


static AttributeAnimation* AttributeAnimation_NewInstance(FsDict* attr)
{
	AttributeAnimation* ret=AttributeAnimation::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}

	return ret;
}

static void AttributeAnimation_setKeyFrames(AttributeAnimation* am,FsArray* attr)
{
	int size=attr->size();

	for(int i=0;i<size;i++)
	{
		FsDict* dict=attr->getDict(i);
		if(dict)
		{
			float time=0;
			if(ScriptUtil::getFloat(dict,"time",&time))
			{
				FS_TRACE_WARN("time not find in keyframe(%d) ignore",i);
				continue;
			}

			FsObject* value=dict->lookup("value");
			if(!value)
			{
				FS_TRACE_WARN("value not find int keyframe(%d) ignore",i);
				continue;
			}
			am->insert(time,value);
		}
	}
}

FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(AttributeAnimation,setValueType,getValueType,FsType);
FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(AttributeAnimation,setAttributeName,getAttributeName);


static FsClass::FsAttributeDeclare S_AttributeAnimation_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("attributeName",FsType::FT_CHARS,NULL,AttributeAnimation_setAttributeName,AttributeAnimation_getAttributeName),
	FS_CLASS_ATTR_DECLARE("valueType",FsType::FT_CHARS,NULL,AttributeAnimation_setValueType,AttributeAnimation_getValueType),
	FS_CLASS_ATTR_DECLARE("keyframes",FsType::FT_ARRAY,NULL,AttributeAnimation_setKeyFrames,0),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(AttributeAnimation,TrackAnimation,S_AttributeAnimation_NewInstance,S_AttributeAnimation_Main_Attr);




