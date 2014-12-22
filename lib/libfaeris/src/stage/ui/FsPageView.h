#ifndef _FS_PAGE_VIEW_H_
#define _FS_PAGE_VIEW_H_

#include "FsMacros.h"
#include "FsUiWidget.h"


NS_FS_BEGIN

class EaseExpr;
class PageViewContentPanel;
class VelocityTracker;
class PageView:public UiWidget 
{

	public:
		static PageView* create();
		static PageView* create(float width,float height);
		static PageView* create(E_ScrollDirection mode,float width,float height);

	public:
		void setMode(E_ScrollDirection mode);
		E_ScrollDirection getMode();

		void addPage(UiWidget* widget);
		void addPage(UiWidget* widget,E_AlignH alignh,E_AlignV alignv);

		void addPage(int index,UiWidget* widget);
		void addPage(int index,UiWidget* widget,E_AlignH alignh,E_AlignV alignv);

		void setPageAlign(int index,E_AlignH alignh,E_AlignV alignv);
		void setPageAlign(UiWidget* widget,E_AlignH alignh,E_AlignV alignv);

		void removePage(UiWidget* widget);
		void removePage(int index);

		void clearPage();

		int getPageNu();
		UiWidget* getPage(int index);
		int getPageIndex(UiWidget* widget);

		void prevPage();
		void nextPage();
		void setCurrentPageIndex(int index);
		int getCurrentPageIndex();

		void setCurrentPage(UiWidget* widget);
		UiWidget* getCurrentPage();

		void slideToPage(UiWidget* widget);
		void slideToPageIndex(int index);
		void slideToNextPage();
		void slideToPrevPage();



	public:
		/* inherit Entity */
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;

		void update(float dt) FS_OVERRIDE;


		/* inherit UiWidget */

		void childSizeChanged(UiWidget* widget) FS_OVERRIDE;
		void childAnchorChanged(UiWidget* widget) FS_OVERRIDE;
		void childTransformChanged(UiWidget* widget) FS_OVERRIDE;

		using UiWidget::setSize;
		void setSize(const Vector2& v) FS_OVERRIDE;

		using UiWidget::setAnchor;
		void setAnchor(const Vector2& v) FS_OVERRIDE;

		void addChild(Entity* en) FS_OVERRIDE;
		void clearChild() FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;


	public:
		/* Page View */
		virtual void pageIndexChanged(int old_index,int new_index);
	public:
		std::function<void(PageView*,int old_index,int new_index)> onPageIndexChanged;


	protected:
		PageView(E_ScrollDirection mode,float width,float height);
		virtual ~PageView();

		void adjustContentPanel();

		void scrollXBy(float value);
		void scrollYBy(float value);
		void scrollXTo(float value);
		void scrollYTo(float value);
		void checkPageAlign();
		void checkPageAlign(float v);
		void updateScroll(float dt);
		void scrollFromTo(float start,float end);
		void scrollFromTo(float start,float end,float duration);




	protected:
		PageViewContentPanel* m_contentPanel;

		float m_xoffset,m_yoffset;
		float m_lastPosX,m_lastPosY;
		bool m_isDraged;

		float m_touchTap;

		int m_currentPageIndex;

		bool m_scrollFinished;
		float m_scrollBeginPos,m_scrollEndPos;
		float m_scrollDuration;
		float m_scrollTimeEscape;

		EaseExpr* m_scrollEasing;

		VelocityTracker* m_velocityTracker;
};

NS_FS_END 
#endif /*_FS_PAGE_VIEW_H_*/

