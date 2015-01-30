/*************************************************************************/
/*  FsListView.h                                                         */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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
		FS_CLASS_DECLARE(ListView);

	public:
		static ListView* create();
		static ListView* create(E_ScrollDirection mode,float width,float height);
		static ListView* create(float width,float height);

		
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
		ListView(float width,float height);

		void init(E_ScrollDirection mode,float width,float height);


		virtual ~ListView();

		void childSizeChanged(UiWidget* widget) FS_OVERRIDE;
		void childAnchorChanged(UiWidget* widget) FS_OVERRIDE;
		void childTransformChanged(UiWidget* widget) FS_OVERRIDE;

		void adjustContentSize();

		void layoutContentWidget(float x,float y) FS_OVERRIDE;


	protected:
		ListViewContentPanel* m_contentPanel;
};

NS_FS_END 
#endif /*_FS_LIST_VIEW_H_*/

