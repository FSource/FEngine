#ifndef _FS_SCROLLER_H_
#define _FS_SCROLLER_H_

#include "FsMacros.h"
#include "FsObject.h"


NS_FS_BEGIN

class Scroll 
{
	public:
		void touchBegin(float x,float y);
		void touchMove(float x,float y);
		void touchEnd(float x,float y);

	public:

		/* executed as soon as user touches the screen 
		 * but before the scrolling has initiated.
		 */
		virtual void beforeScrollStart();

		/* called when scroll initiated but didn't happen*/
		virtual void scrollCancel();

		/* called when the scroll started.*/
		virtual bool scrollStart();


		/* called when the content is scrolling */
		virtual void scroll(float x,float y);


		/* called content stopped scrolling */
		virtual void scrollEnd();

		/* user flicked left/right */
		virtual void flick();

	public:
		void update(float dt);
		void stopAnimation(bool force);

	protected:
		/* configure attr */
		bool m_scrollXEnabled;
		bool m_scrollYEnabled;

		bool m_directionLockedEnabled;
		float m_directionLockThreshold;

		/* bounce */
		bool m_bounceEnabled;
		bool m_bounceTime;
		EaseExpr* m_bounceEasing;

		/* translate */
		EaseExpr* m_transitionExpr;




		float m_minScrollX;
		float m_maxScrollX;
		float m_minScrollY;
		float m_maxScrollY;




		bool m_isInTransition;

		float m_positionX;
		float m_positionY;

};




NS_FS_END





#endif /*_FS_SCROLLER_H_*/

