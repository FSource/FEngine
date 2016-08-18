#ifndef _FS_POSE_ANIMATION_H_
#define _FS_POSE_ANIMATION_H_ 

#include "FsMacros.h"
#include "FsAnimation.h"

NS_FS_BEGIN 

class FsPoseAnimation:public FsAnimation 
{
	public:
		static FsPoseAnimation* create(int anim_index,float anim_type);

	public:
		void insert(float time,int anim_index,float anim_time);

};



NS_FS_END 


#endif /*_FS_POSE_ANIMATION_H_*/
