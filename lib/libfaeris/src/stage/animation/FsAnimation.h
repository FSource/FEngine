#ifndef _FS_ANIMATION_H_
#define _FS_ANIMATION_H_

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class FsAnimation 
{
	public:
		void addAnimation(const char* name,FsTrackSet* tracks);
		FsTrackSet* getAnimaiton(const char* name);

		void setAnimation(const char* name);

		void start();
		void stop();

		int isRunning();

		void update(float dt);

	public:
		virtual int keyFrameEvent(E_TrackType type, FsTrackKeyFrame& kf);


	public:
		std::function<int(E_TrackType type,FsTrackKeyFrame)> onKeyFrameEvent;


};


NS_FS_END





#endif /*_FS_ANIMATION_H_*/
