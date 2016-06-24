#ifndef _FS_KEY_FRAME_H_
#define _FS_KEY_FRAME_H_ 

#include "FsMacros.h"
#include "FsObject.h"
#include "FsAnimation.h"

NS_FS_BEGIN
class FsKeyFrame:public FsObject
{
	public:
		FsKeyFrame(float time,FsEaseExpr* ease_expr);
		virtual  ~FsKeyFrame();

	public:
		float getTime();
		void setEaseExpr(FsEaseExpr* ease);
		FsEaseExpr* getEaseExpr();

	protected:
		float m_time;
		FsEaseExpr* m_easeExpr;
};

class FsVariantKeyFrame:public FsKeyFrame  
{
	public:
		static FsVariantKeyFrame* create(float time,const FsVariant& value, FsEaseExpr* ease_expr);

	public:
		void setValue(const FsVariant& value);
		const FsVariant& getValue();

	protected:
		FsVariantKeyFrame(float time,const FsVariant& value,FsEaseExpr* ease_expr);

	protected:
		FsVariant m_value;
};

class FsPoseKeyFrame:public FsKeyFrame 
{
	public:
		static FsPoseKeyFrame* create(float time,int anim_index,float anim_time,FsEaseExpr* ease_expr);
	public:
		void setValue(int anim_index,float anim_time);
		int getAnimIndex();
		float getAnimTime();

	protected:
		FsPoseKeyFrame(float time,int anim_index,float anim_time,FsEaseExpr* ease_expr);

	protected:
		int m_animIndex;
		float m_animTime;
};

NS_FS_END 
#endif 
