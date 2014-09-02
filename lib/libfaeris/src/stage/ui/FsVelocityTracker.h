#ifndef _FS_VELOCITY_TRACKER_H_
#define _FS_VELOCITY_TRACKER_H_

#include "FsMacros.h"
#include "FsObject.h"
#include "sys/FsTimer.h"

#define FS_VELOCITY_TRACE_MAX_POINT_SUPPORT 10
NS_FS_BEGIN

class VelocityTracker:public FsObject 
{
	protected:
		class TrackInfo
		{
			public:
				TrackInfo()
					:m_time(0.0f),
					m_x(0.0f),m_y(0.0f)
				{}

			public:
				float m_time;
				float m_x;
				float m_y;
		};

	public:
		static VelocityTracker* create();

	public:
		virtual const char* className();


	public:
		void beginTrack(float x,float y);
		void addTrack(float x,float y);
		void endTrack(float x,float y);

		float getVelocityX();
		float getVelocityY();

	protected:
		VelocityTracker();

		void computeVelocity();


	private:
		Timer m_time;
		TrackInfo m_trackInfo[FS_VELOCITY_TRACE_MAX_POINT_SUPPORT];
		int m_curTrackIndex;

		float m_velocityX;
		float m_velocityY;



};

NS_FS_END


#endif /*_FS_VELOCITY_TRACKER_H_*/

