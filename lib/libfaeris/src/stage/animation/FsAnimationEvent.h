#ifndef _FS_ANIMATION_EVENT_H_

#include <string>
#include "FsMacros.h"
#include "FsEnums.h"
#include "FsVariant.h"

NS_FS_BEGIN 

class AnimationEvent 
{
	public:
		FS_VIRTUAL E_AnimEventType getEventType()=0;

	public:
		FS_VIRTUAL ~AnimationEvent();

};

class AttributeAnimationEvent:public AnimationEvent 
{
	public:
		E_AnimEventType getEventType() FS_OVERRIDE;

		const FsVariant& getValue();
		const char* getAttributeName();

	public:
		AttributeAnimationEvent(const char* attr_name,const FsVariant& value);
		~AttributeAnimationEvent();

	protected:
		FsVariant m_value;
		std::string m_attrName;
};




NS_FS_END 


#endif /*_FS_ANIMATION_EVENT_H_*/


