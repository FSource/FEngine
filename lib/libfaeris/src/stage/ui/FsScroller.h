#ifndef _FS_SCROLLER_H_
#define _FS_SCROLLER_H_

#include "FsMacros.h"
#include "FsObject.h"


#define FS_SCROLL_DEFAULT_DURATION 0.25f

NS_FS_BEGIN


class EaseExpr;
class Scroller:public FsObject 
{
	public:
		enum
		{
			SCROLL,
			FLING,
			BOUNCE_BACK,
		};

	public:
		static Scroller* create();

	public:

		void startScroll(float start,float min,float max,float delta,float duration=FS_SCROLL_DEFAULT_DURATION);
		void fling(float start,float min,float max,float velocity,float accel,float range);
		void bounceBack(float start,float min,float max,float range);

		bool isFinished();
		void abortAnimation();
		void finishAnimation();

		float getCurPos();

		int getScrollMode();


	public:
		virtual const char* className();
		virtual bool update(float dt);


	protected:
		Scroller();
		virtual ~Scroller();


		void updateFling(float dt);
		void updateScroll(float dt);
		void updateBounceBack(float dt);




	private:
		int m_mode;

		bool m_finish;


		/* common */
		float m_duration;
		float m_timePassed;

		float m_curPos;
		float m_maxPos;
		float m_minPos;

		/* scroll mode*/
		float m_delta,m_start,m_final;
		EaseExpr* m_scrollEasing;


		/* fling mode */
		float m_startVelocity;
		float m_curVelocity;

		float m_accel;

		bool m_flingDecrease;
		float m_flingEdgeRange;



		EaseExpr* m_flingEasing;

		/* bounceBack mode */
		EaseExpr* m_bounceExpr;

};



NS_FS_END





#endif /*_FS_SCROLLER_H_*/

