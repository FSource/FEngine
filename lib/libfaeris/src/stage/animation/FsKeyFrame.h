#ifndef _FS_KEY_FRAME_H_
#define _FS_KEY_FRAME_H_ 

#include "FsMacros.h"
#include "FsObject.h"
#include "FsAnimation.h"

NS_FS_BEGIN
class EaseExpr;
class KeyFrame:public FsObject
{
	public:
		KeyFrame(float time,EaseExpr* ease_expr);
		virtual  ~KeyFrame();

	public:
		float getTime();
		void setEaseExpr(EaseExpr* ease);
		EaseExpr* getEaseExpr();

	protected:
		float m_time;
		EaseExpr* m_easeExpr;
};

class VariantKeyFrame:public KeyFrame  
{
	public:
		static VariantKeyFrame* create(float time,const FsVariant& value, EaseExpr* ease_expr);

	public:
		void setValue(const FsVariant& value);
		const FsVariant& getValue() const ;

	protected:
		VariantKeyFrame(float time,const FsVariant& value,EaseExpr* ease_expr);

	protected:
		FsVariant m_value;
};

class PoseKeyFrame:public KeyFrame 
{
	public:
		static PoseKeyFrame* create(float time,int anim_index,float anim_time,EaseExpr* ease_expr);
	public:
		void setValue(int anim_index,float anim_time);
		int getAnimIndex();
		float getAnimTime();

	protected:
		PoseKeyFrame(float time,int anim_index,float anim_time,EaseExpr* ease_expr);

	protected:
		int m_animIndex;
		float m_animTime;
};

NS_FS_END 
#endif 
