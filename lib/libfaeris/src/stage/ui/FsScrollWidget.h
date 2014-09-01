#ifndef _FS_SCROLL_WIDGET_H_
#define _FS_SCROLL_WIDGET_H_

#include "FsMacros.h"
#include "stage/entity/FsUiWidget.h"

NS_FS_BEGIN

class VelocityTracker;

class ScrollWidget:public UiWidget
{
	enum 
	{
		SCROLL_HORIZONTAL,
		SCROLL_VERTICAL,
		SCROLL_ALL,
	};

	enum
	{
		ALIGN_TOP,
		ALIGN_CENTER,
		ALIGN_BOTTOM,
		ALIGN_LEFT,
		ALIGN_RIGHT,
	};

	public:
		/* inherit Entity */
		virtual  bool touchBegin(float x,float y);
		virtual  bool touchMove(float x,float y);
		virtual  bool touchEnd(float x,float y);

		virtual void update(float dt);



		/* inherit UiWidget */
		virtual void childSizeChanged(float w,float h);
		virtual void childAnchorChanged(float w,float h);

		virtual void setSize(float width,float height);
		virtual void setAnchor(float x,float y);


		/* inherit FsObject */
		const char* className();



		virtual void beginDrag();
		virtual void endDrag();


	public:
		virtual void pressDown(x,y);
		virtual void pressMove(x,y);
		virtual bool PressUp();


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

	public:
		void setContentAlign(int w,int h);
		void setContentSize(float width,float height);


	public: /* scroll support */
		void scrollBy(float x,float y);
		void scrollTo(float x,float y);

		void setScrollPercent(float x,float y);
		void setScrollPercentX(float x);
		void setScrollPercentY(float y);

		void getScrollPercent(float* x,float* y);
		float getScrollPercentX();
		float getScrollPercentY();


	public:
		void scrollChange(float x,float y);

	protected:
		void adjustScrollArea();

		void startScrollX(float cur,float min,float max,float delta);
		void startScrollY(float cur,float min,float max,float delta);

		void updateScroll(float dt);


	private:
		float m_scrollX,m_scrollY;

		float m_touchTap;

		float m_contentWidth,m_contentHeight;

		float m_marginLeft,m_marginRight,m_marginTop,m_marginBottom;

		float m_scrollMinX,m_scrollMaxX;
		float m_scrollMinY,m_scrollMaxY;


		/* attr cache */
		float m_edgeLeft,m_edgeRight,m_edgeTop,m_edgeBottom;
		float m_edgeBLeft,m_edgeBRight,m_edgeBTop,m_edgeBBottom;




		bool m_press;
		int m_scrollState;

		Scroller* m_scrollerX;
		Scroller* m_scrollerY;

		int m_scrollMode;

		int m_alignh,m_alignv;

		VelocityTracker* m_tracker;

};

NS_FS_END

#endif /*_FS_SCROLL_WIDGET_H_*/


