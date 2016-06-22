#ifndef _FS_KEY_FRAME_H_
#define _FS_KEY_FRAME_H_ 

#include "FsMacros.h"
#include "FsObject.h"
#include "FsAnimation.h"

NS_FS_BEGIN
class FsKeyFrame:public FsObject
{
	public:
		FsKeyFrame* create(float time,const FsVariant& value,FsEaseExpr* ease_expr);

	public:
		float getTime();
		void setEaseExpr(FsEaseExpr* ease);
		FsEaseExpr* getEaseExpr();
		const FsVariant& getVariant();

	protected:
		FsKeyFrame(float time,const FsVariant& value,FsEaseExpr* ease_expr);

	protected:
		float m_time;
		FsEaseExpr* m_easeExpr;
		FsVariant m_value;
};

NS_FS_END 
#endif 
