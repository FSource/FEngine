#ifndef _FS_TRACK_H_
#define _FS_TRACK_H_


NS_FS_BEGIN

class FsTrack
{
	public:
		float getTotalTime();

		void setMode(E_TrackMode);
		E_TrackMode getMode();

		void setType(E_TrackType);
		E_TrackType getType();


		void setLoop(int loop);
		int isLoop();

		FsTrackKeyFrame lerpKeyFrame(float time);

		int insertKeyFrame(const FsTrackKeyFrame&  kf);
		int getKeyFrameNu();
		FsTrackKeyFrame getKeyFrame(int index);
		void removeKeyFrame(int index);


	protected:
		E_TrackMode m_trackMode;
		E_TrackType m_traceType;
		std::vector<FsTrackKeyFrame> m_keyframes;
		int m_isLoop;
		float m_trackTime;
};

NS_FS_END

#endif /*_FS_TRACK_H_*/

