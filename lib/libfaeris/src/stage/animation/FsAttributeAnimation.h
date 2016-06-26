#ifndef _FS_POPERTY_ANIMATION_H_
#define _FS_POPERTY_ANIMATION_H_

#include "FsMacros.h"
#include "FsTrackAnimation.h"


NS_FS_BEGIN

class AttributeAnimation:public TrackAnimation 
{
	public:
		FS_CLASS_DECLARE(AttributeAnimation);
	public:
		static AttributeAnimation* create();
		static AttributeAnimation* create(const char* attr_name,E_FsType type);

	public:
		void insert(float time,const FsVariant& value);

		E_FsType getValueType() const;
		void setValueType(E_FsType type);

		void setAttributeName(const char* name);
		const char* getAttributeName() const;

	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;

	protected:
		AttributeAnimation();
		~AttributeAnimation();


	protected:
		E_FsType m_valueType;
		std::string m_attrName;
};


NS_FS_END

#endif /*_FS_POPERTY_ANIMATION_H_*/
