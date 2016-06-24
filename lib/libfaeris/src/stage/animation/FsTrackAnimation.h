#ifndef _FS_TRACK_ANIMATION_H_ 
#define _FS_TRACK_ANIMATION_H_ 

#include "FsMacros.h"
#include "FsAnimation.h"

NS_FS_BEGIN 

class KeyFrame;

class TrackAnimation:public Animation
{
	public:
		FS_CLASS_DECLARE(TrackAnimation);

	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;
		float getTimeLength() FS_OVERRIDE;

	public:
		void setLerpMode(E_LerpMode mode);
		E_LerpMode getLerpMode();

	public:
		void insertKeyFrame(KeyFrame* frame);
		void removeTime(float time);
		void removeRange(float begin,float end);
		int getKeyFrameNu();
		void clearKeyFrame();

		KeyFrame* getKeyFrame(int index);

	protected:
		TrackAnimation();
		~TrackAnimation();

	protected:
		int getNearBeforeIndex(float time);
		int getNearAfterIndex(float time);
		void calTotoalTime();


	private:
		E_LerpMode m_lerpMode;

		float m_totalTime;
		std::vector<KeyFrame*> m_keyFrames;
};

NS_FS_END

#endif /*_FS_TRACK_ANIMATION_H_ */

