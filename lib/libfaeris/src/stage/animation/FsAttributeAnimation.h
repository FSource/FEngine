#ifndef _FS_PROPERTY_ANIMATION_H_
#define _FS_PROPERTY_ANIMATION_H_

#include "FsMacros.h"
#include "FsTrackAnimation.h"

NS_FS_BEGIN

class AttributeAnimation:public TrackAnimation 
{
	public:
		static AttributeAnimation* create();
		static AttributeAnimation* create(const char* attr_name,FsType type);

	public:
		void insert(float time,const FsVariant& value);

		FsType getValueType() const;
		void setValueType(FsType type);

		void setAttributeName(const char* name);
		const char* getAttributeName() const;

	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;

	protected:
		AttributeAnimation();
		~AttributeAnimation();


	protected:
		FsType m_valueType;
		std::string m_attrName;
};


NS_FS_END

#endif /*_FS_PROPERTY_ANIMATION_H_*/
