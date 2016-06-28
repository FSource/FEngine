#ifndef _FS_SCROLLER_H_
#define _FS_SCROLLER_H_
#include <functional>

#include "FsMacros.h"
#include "FsObject.h"

#include "FsUiWidget.h"
#include "sys/FsTimer.h"

NS_FS_BEGIN

class EaseExpr;

class ScrollWidget:public UiWidget
{
	public:
		FS_CLASS_DECLARE(ScrollWidget);

	public:
		enum class E_DirectionMoveMode
		{
			VERTICAL,
			HORIZONTAL,
			BOTH,
		};

	public:
		/* inherit UiWidget*/
		void update(float dt) FS_OVERRIDE;

		bool touchBegin(float x,float y) FS_OVERRIDE; 
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;
		//bool touchCancel(float x,float y) FS_OVERRIDE;


		void childSizeChanged(UiWidget* widget) FS_OVERRIDE;
		void childAnchorChanged(UiWidget* widge) FS_OVERRIDE;
		void childTransformChanged(UiWidget* widget) FS_OVERRIDE;


		using UiWidget::setSize;
		void setSize(const Vector2& size) FS_OVERRIDE;

		using UiWidget::setAnchor;
		void setAnchor(const Vector2& size) FS_OVERRIDE;


	public:

		/* executed as soon as user touches the screen 
		 * but before the scrolling has initiated.
		 */
		virtual void beforeScrollStart();

		/* called when scroll initiated but didn't happen*/
		virtual void scrollCancel();

		/* called when the scroll started.*/
		virtual void scrollStart();


		/* called when the content is scrolling */
		virtual void scroll();


		/* called content stopped scrolling */
		virtual void scrollEnd();

		/* user flicked left/right */
		virtual void flick();

	public:
		std::function<void(ScrollWidget*)> onBeforeScrollStart;
		std::function<void(ScrollWidget*)> onScrollCancel;
		std::function<void(ScrollWidget*)> onScrollStart;
		std::function<void(ScrollWidget*)> onScroll;
		std::function<void(ScrollWidget*)> onScrollEnd;
		std::function<void(ScrollWidget*)> onFlick;


	public:
		void setMargin(float l,float r,float t,float b);
		void getMargin(float* l,float* r,float* t,float* b);

		void setMarginLeft(float v);
		float getMarginLeft() const;

		void setMarginRight(float v);
		float getMarginRight() const;

		void setMarginTop(float v);
		float getMarginTop() const ;

		void setMarginBottom(float v);
		float getMarginBottom() const;

		void setContentAlign(E_AlignH h,E_AlignV v);

		void setScrollPercent(float x,float y);
		void setScrollPercentX(float x);
		void setScrollPercentY(float y);
		float getScrollPercentX();
		float getScrollPercentY();

		void setScrollXEnabled(bool value);
		void setScrollYEnabled(bool value);
		bool getScrollXEnabled();
		bool getScrollYEnabled();
		




	public:

		void stopScroll();
		void finishScroll();


	protected:
		ScrollWidget();
		~ScrollWidget();


	protected:
		void updateScroll(float dt);
		bool doEdgeOut(float time);
		void scrollSet(float x,float y);

		void scrollBy(float x,float y,float duration,EaseExpr* easing);
		void scrollTo(float x,float y,float duration,EaseExpr* easing); 

		void setContentSize(float width,float height);
		void adjustContentLayout(float x,float y);

		void calMomentum(float cur_pos,float start, float duration, float min, float max,
						 float wrap_size, float deceleration, float* des, float *time );
		void adjustScrollArea();


		/* call back */
		virtual void layoutContentWidget(float x,float y);

		

	protected:
		/* configure attr */
		bool m_scrollXEnabled;
		bool m_scrollYEnabled;

		bool m_directionLockedEnabled;
		float m_directionLockThreshold;


		float m_tapDistanceToScroll;
		float m_tapTimeToScroll;

		bool m_blockEventOnScroll;

		/* momentum */
		float m_momentumEnabled;
		float m_deceleration;



		/* content size */
		float m_contentWidth;
		float m_contentHeight;

		E_AlignH m_alignh;
		E_AlignV m_alignv;

		/* margin */
		float m_marginLeft;
		float m_marginRight;
		float m_marginTop;
		float m_marginBottom;


		/* bounce */
		bool m_bounceEnabled;
		float m_bounceTime;
		EaseExpr* m_bounceEasing;

		/* translate */
		EaseExpr* m_animatingEasing;
		EaseExpr* m_animatingOutEdgeEasing;



		/* scroll range */
		float m_minScrollX;
		float m_maxScrollX;
		float m_minScrollY;
		float m_maxScrollY;

		/* scroll position */
		float m_positionX;
		float m_positionY;


		Timer m_timer;


		/* for touch event */
		float m_startX;
		float m_startY;
		float m_startTime;


		float m_distX;
		float m_distY;

		int m_directionX;
		int m_directionY;

		float m_lastPosX;
		float m_lastPosY;

		E_DirectionMoveMode m_directionMoveMode;


		/* edge */
		float m_edgeLeft;
		float m_edgeRight;
		float m_edgeTop;
		float m_edgeBottom;

		float m_edgeBLeft;
		float m_edgeBRight;
		float m_edgeBTop;
		float m_edgeBBottom;




		/* animating */
		bool m_isAnimating;
		bool m_isDrag;

		float m_animatingFromX;
		float m_animatingToX;

		float m_animatingFromY;
		float m_animatingToY;

		float m_animatingTotalTime;
		float m_animatingElapseTime;

		EaseExpr* m_animatingEasingUse;

};




NS_FS_END





#endif /*_FS_SCROLLER_H_*/

