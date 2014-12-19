#ifndef _FS_LIST_VIEW_H_
#define _FS_LIST_VIEW_H_

#include "FsMacros.h"
#include "FsEnums.h"
#include "FsUiWidget.h"
#include "FsScrollView.h"



NS_FS_BEGIN

class ListViewContentPanel;
class ListView:public ScrollWidget
{
	public:
		static ListView* create();
		static ListView* create(E_ScrollDirection mode,float width,float height);
		static ListView* create(float width,float height);

	public:

		/* inherit ScrollWidget */
		virtual void scrollChange(float x,float y);
		
	public:
		void setMode(E_ScrollDirection mode);

		void setListGap(float value);
		float getListGap();

		Vector2 getListItemSize();


	public:
		void addListItem(UiWidget* widget);
		void addListItem(UiWidget* widget,E_AlignH alignh,E_AlignV alignv);

		void addListItem(int index,UiWidget* widget);
		void addListItem(int index,UiWidget* widget,E_AlignH alignh,E_AlignV alignv);

		void removeListItem(int index);
		void removeListItem(UiWidget* widget);

		void clearListItem();
	
		int getListItemNu();
		UiWidget* getListItem(int index);

		int getListItemIndex(UiWidget* widget);
		void layout();

	public:
		using ScrollWidget::setSize;
		void setSize(const Vector2& v) FS_OVERRIDE;

		using ScrollWidget::setAnchor;
		void setAnchor(const Vector2& v) FS_OVERRIDE;

		void addChild(Entity* en) FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;
		void clearChild() FS_OVERRIDE;


	protected:

		ListView(E_ScrollDirection mode,float width,float height);
		virtual ~ListView();

		void childSizeChanged(UiWidget* widget) FS_OVERRIDE;
		void childAnchorChanged(UiWidget* widget) FS_OVERRIDE;
		void childTransformChanged(UiWidget* widget) FS_OVERRIDE;

		void adjustContentSize();


	protected:
		ListViewContentPanel* m_contentPanel;
};

NS_FS_END 
#endif /*_FS_LIST_VIEW_H_*/

