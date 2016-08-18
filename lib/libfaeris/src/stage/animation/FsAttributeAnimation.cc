#include "FsAttributeAnimation.h"
#include "FsKeyFrame.h"
#include "FsClass.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsScriptUtil.h"
#include "FsAnimationEvent.h"
#include "FsAnimator.h"
#include "math/easing/FsEaseExpr.h"


NS_FS_BEGIN

AttributeAnimation* AttributeAnimation::create()
{
	AttributeAnimation* ret=new AttributeAnimation();
	return ret;
}


AttributeAnimation* AttributeAnimation::create(const char* attr_name,E_FsType type)
{

	AttributeAnimation* ret=new AttributeAnimation();
	ret->setAttributeName(attr_name);
	ret->setValueType(type);
	return ret;
}

void AttributeAnimation::insert(float time,const FsVariant& value)
{
	FsVariant fvalue=value.getCast(m_valueType);

	if(fvalue.getType()==E_FsType::FT_IN_VALID)
	{
		FS_TRACE_WARN("can't add case value to animation type");
		return;
	}

	VariantKeyFrame* kf=VariantKeyFrame::create(time,fvalue,NULL);

	insertKeyFrame(kf);
}

E_FsType AttributeAnimation::getValueType() const
{
	return m_valueType;
}

void AttributeAnimation::setValueType(E_FsType type)
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
	float now=time+dt;

	if(time<m_totalTime&&now>m_totalTime)
	{
		now=m_totalTime;
	}


	VariantKeyFrame* prev=NULL;
	VariantKeyFrame* next=NULL;

	if(m_lerpMode==E_LerpMode::SMOOTH)
	{
		getNearKeyFrame(now,(KeyFrame**)&prev,(KeyFrame**)&next);


		if(prev==NULL||next==NULL)
		{
			return;
		}

		if(prev==next)
		{
			AttributeAnimationEvent* event=new AttributeAnimationEvent(m_attrName.c_str(),prev->getValue().getCast(m_valueType));
			FS_OBJECT_LAMBDA_CALL(at,onAnimationEvent,animationEvent,event);
			delete event;
		}
		else  /* lerp between frame */
		{
			const FsVariant value_prev=prev->getValue().getCast(m_valueType);
			const FsVariant value_next=next->getValue().getCast(m_valueType);

			float time_length=next->getTime()-prev->getTime();
			float percent=(now-prev->getTime())/time_length;
			EaseExpr* expr=prev->getEaseExpr();
			if(expr)
			{
				percent=expr->getValue(percent);
			}

			FsVariant ret=value_prev*(1-percent)+value_next*percent;
			if(!ret.isValid())
			{
				FS_TRACE_WARN("FsKeyFrame Lerp Error Get inValid value");
				return;
			}

			AttributeAnimationEvent* event=new AttributeAnimationEvent(m_attrName.c_str(),ret);
			FS_OBJECT_LAMBDA_CALL(at,onAnimationEvent,animationEvent,event);
			delete event;
		}

	}
	else /* flat */
	{
		std::vector<KeyFrame*> kfs=getKeyFrame(time,now);
		int size=kfs.size();
		for(int i=0;i<size;i++)
		{
			VariantKeyFrame* k=(VariantKeyFrame*)kfs[i];
			FsVariant value=k->getValue().getCast(m_valueType);
			AttributeAnimationEvent* event=new AttributeAnimationEvent(m_attrName.c_str(),value);
			FS_OBJECT_LAMBDA_CALL(at,onAnimationEvent,animationEvent,event);
			delete event;
		}
	}
}


AttributeAnimation::AttributeAnimation()
{
	m_valueType=E_FsType::FT_IN_VALID;
	m_attrName="";
}

AttributeAnimation::~AttributeAnimation()
{

}

/** Used For AttributeAnimation Attribute */


static AttributeAnimation* S_AttributeAnimation_NewInstance(FsDict* attr)
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
			if(!ScriptUtil::getFloat(dict,"time",&time))
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

/** Used For AttributeAnimation Attribute */

FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(AttributeAnimation,setValueType,getValueType,FsType);
FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(AttributeAnimation,setAttributeName,getAttributeName);


static FsClass::FsAttributeDeclare S_AttributeAnimation_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("attributeName",E_FsType::FT_CHARS,NULL,AttributeAnimation_setAttributeName,AttributeAnimation_getAttributeName),
	FS_CLASS_ATTR_DECLARE("valueType",E_FsType::FT_CHARS,NULL,AttributeAnimation_setValueType,AttributeAnimation_getValueType),
	FS_CLASS_ATTR_DECLARE("keyframes",E_FsType::FT_ARRAY,NULL,AttributeAnimation_setKeyFrames,0),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(AttributeAnimation,TrackAnimation,S_AttributeAnimation_NewInstance,S_AttributeAnimation_Main_Attr);




NS_FS_END
