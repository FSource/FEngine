#ifndef _FS_LIST_VIEW_H_
#define _FS_LIST_VIEW_H_

#include "FsMacros.h"
#include "FsUiWidget.h"
#include "FsScrollView.h"

NS_FS_BEGIN

class ListViewContentPanel;
class ListView:public ScrollWidget
{
	public:
		enum 
		{
			SCROLL_VERTICAL=ScrollWidget::SCROLL_VERTICAL,
			SCROLL_HORIZONTAL=ScrollWidget::SCROLL_HORIZONTAL,
		};

		enum 
		{
			ITEM_ALIGN_LEFT,
			ITEM_ALIGN_CENTER,
			ITEM_ALIGN_RIGHT,
			ITEM_ALIGN_TOP,
			ITEM_ALIGN_BOTTOM,
		};

	public:
		static ListView* create(int mode,float width,float height);
		static ListView* create(float width,float height);

	public:
		/* inherit FsObject */
		virtual const char* className();


		/* inherit UiWidget */
		virtual void removeWidget(UiWidget* widget);
		virtual void layout();

		/* inherit ScrollWidget */
		virtual void scrollChange(float x,float y);
		
	public:
		void setMode(int mode);

		void setListGap(float value);
		float getListGap();

		Vector2 getListItemSize();


	public:
		void addListItem(UiWidget* widget);
		void addListItem(UiWidget* widget,int alignh,int alignv);

		void addListItem(int index,UiWidget* widget);
		void addListItem(int index,UiWidget* widget,int alignh,int alignv);

		void removeListItem(int index);
		void removeListItem(UiWidget* widget);
	
		int getListItemNu();
		UiWidget* getListItem(int index);

		int getListItemIndex(UiWidget* widget);

	protected:

		ListView(int mode,float width,float height);
		virtual ~ListView();

		virtual void childSizeChanged(UiWidget* widget,float w,float h);
		virtual void childAnchorChanged(UiWidget* widget,float w,float h);

		virtual void sizeChanged(float w,float h);
		virtual void anchorChanged(float x,float y);

		void adjustContentSize();


	protected:
		ListViewContentPanel* m_contentPanel;
};

NS_FS_END 
#endif /*_FS_LIST_VIEW_H_*/

