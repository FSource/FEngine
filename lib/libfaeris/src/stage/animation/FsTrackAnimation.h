#ifndef _FS_TRACK_ANIMATION_H_ 
#define _FS_TRACK_ANIMATION_H_ 

#include "FsMacros.h"
#include "FsAnimation.h"

NS_FS_BEGIN 
class FsTrackAnimation:public FsAnimation
{
	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;
		float getTimeLength() FS_OVERRIDE;

};
NS_FS_END


#endif /*_FS_TRACK_ANIMATION_H_ */


