#ifndef _FS_TRACK_ANIMATION_H_ 
#define _FS_TRACK_ANIMATION_H_ 

#include "FsMacros.h"
#include "FsAnimation.h"

NS_FS_BEGIN 

class FsKeyFrame;

class FsTrackAnimation:public FsAnimation
{
	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;
		float getTimeLength() FS_OVERRIDE;

	public:
		void setLerpMode(E_LerpMode mode);
		E_LerpMode getLerpMode();

	public:
		void insertKeyFrame(FsKeyFrame* frame);
		void removeTime(float time);
		void removeRange(float begin,float end);
		void removeKeyFrame(FsKeyFrame* frame);

		int getKeyFrameNu();
		FsKeyFrame* getKeyFrame(int index);


	private:
		E_LerpMode m_lerpMode;

		float m_totalTime;
		std::set<FsKeyFrame*> m_keyFrame;
};

NS_FS_END

#endif /*_FS_TRACK_ANIMATION_H_ */

