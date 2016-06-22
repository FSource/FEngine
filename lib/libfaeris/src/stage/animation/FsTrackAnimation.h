#ifndef _FS_TRACK_ANIMATION_H_ 
#define _FS_TRACK_ANIMATION_H_ 

#include "FsMacros.h"
#include "FsAnimation.h"

NS_FS_BEGIN 

class FsKeyFrame;

class FsTrackAnimation:public FsAnimation
{
	public:
		static FsTrackAnimation* createMoveFromTo(const Vector3& f,const Vector3& t,float time);
		static FsTrackAnimation* createMoveXFromTo(const float& f,const float& t,float time);
		static FsTrackAnimation* createMoveYFromTo(const float& f,const float& t,float time);
		static FsTrackAnimation* createMoveZFromTo(const float& f,const float& t,float time);

		static FsTrackAnimation* createRotateFromTo(const Vector3& f,const Vector3& t,float time);
		static FsTrackAnimation* createRotateXFromTo(const float& f,const float& t,float time);
		static FsTrackAnimation* createRotateYFromTo(const float& f,const float& t,float time);
		static FsTrackAnimation* createRotateZFromTo(const float& f,const float& t,float time);

		static FsTrackAnimation* createScaleFromTo(const Vector3& f,const Vector3& t,float time);
		static FsTrackAnimation* createScaleXFromTo(const float& f,const float& t,float time);
		static FsTrackAnimation* createScaleYFromTo(const float& f,const float& t,float time);
		static FsTrackAnimation* createScaleZFromTo(const float& f,const float& t,float time);


	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;
		float getTimeLength() FS_OVERRIDE;

	public:
		void setLerpMode(E_LerpMode mode);
		E_LerpMode getLerpMode();

		void setValueType(FsType type);
		FsType getValueType()

	public:
		void insert(FsKeyFrame* keyframe);
		void remove(FsKeyFrame* keyframe);

	private:
		FsType m_valueType;
		E_LerpMode m_lerpMode;

		float m_totalTime;
		std::set<FsKeyFrame*> m_keyFrame;
};

NS_FS_END

#endif /*_FS_TRACK_ANIMATION_H_ */

