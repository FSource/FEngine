/*************************************************************************/
/*  FsListView.cc                                                        */
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


#include <assert.h>
#include "FsListView.h"
#include "FsClass.h"
#include "FsGlobal.h"

NS_FS_BEGIN

class ListViewContentPanel:public Entity2D
{
	protected:
	class ListItemInfo:public FsObject 
	{
		public:
			static ListItemInfo* create(E_AlignH alignh,E_AlignV alignv,UiWidget* widget)
			{
				return new ListItemInfo(alignh,alignv,widget);
			}
		public:
			E_AlignH m_alignH;
			E_AlignV m_alignV;
			UiWidget* m_widget;

		protected:
			ListItemInfo(E_AlignH alignh,E_AlignV alignv,UiWidget* widget)
			{
				m_alignH=alignh;
				m_alignV=alignv;
				m_widget=widget;
				FS_SAFE_ADD_REF(widget);
			}

			~ListItemInfo()
			{
				if(m_widget)
				{
					FS_SAFE_DEC_REF(m_widget);
					m_widget=NULL;
				}
			}
	};


	protected:
		FsArray* m_listItem;
		E_ScrollDirection m_mode;

		float m_listGap;
		float m_contentWidth;
		float m_contentHeight;

		float m_width;
		float m_height;


	public:
		static ListViewContentPanel* create(float width,float height)
		{
			return new ListViewContentPanel(width,height);
		}

	protected:
		ListViewContentPanel(float width,float height)
		{
			m_mode=E_ScrollDirection::VERTICAL;
			m_listItem=FsArray::create();
			m_listGap=0;
			m_contentWidth=0;
			m_contentHeight=0;
			setTouchEnabled(true);
			setDispatchTouchEnabled(true);
			m_width=width;
			m_height=height;
		}


		~ListViewContentPanel()
		{
			FS_SAFE_DEC_REF(m_listItem);
		}


	public:
		void addListItem(UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
		{
			int index=m_listItem->size();
			addListItem(index,widget,alignh,alignv);
		}

		void addListItem(int index,UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
		{
			ListItemInfo* item=ListItemInfo::create(alignh,alignv,widget);
			if(index>(int)m_listItem->size())
			{
				index=m_listItem->size();
			}
			m_listItem->insert(index,item);
			addChild(widget);
			layout();
		}


		void removeListItem(UiWidget* widget)
		{
			int index=getListItemIndex(widget);
			m_listItem->remove(index);
			removeChild(widget);
			layout();
		}

		void removeListItem(int index)
		{
			ListItemInfo* item_info=(ListItemInfo*)m_listItem->get(index);
			removeChild(item_info->m_widget);
			m_listItem->remove(index);
			layout();
		}

		void clearListItem()
		{
			clearChild();
			m_listItem->clear();
		}

		int getListItemNu()
		{
			return m_listItem->size();
		}

		UiWidget* getListItem(int index)
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);
			return item->m_widget;
		}

		void setMode(E_ScrollDirection mode)
		{
			m_mode=mode;
			layout();
		}

		E_ScrollDirection getMode()
		{
			return m_mode;
		}

		void setSize(float width,float height)
		{
			m_width=width;
			m_height=height;

			layout();
		}


		void setListItemAlign(int index,E_AlignH alignh,E_AlignV alignv)
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);

			item->m_alignH=alignh;
			item->m_alignV=alignv;

			float left,right,top,bottom;
			item->m_widget->setSignalTSAEnabled(false);
			item->m_widget->getRSBoundSize2D(&left,&right,&top,&bottom);
			switch(m_mode)
			{
				case E_ScrollDirection::VERTICAL:
					{
						switch(item->m_alignH)
						{
							case E_AlignH::LEFT:
								item->m_widget->setPositionX(-left);
								break;

							case E_AlignH::CENTER:
								item->m_widget->setPositionX(m_contentWidth/2-(left+right)/2);
								break;

							case E_AlignH::RIGHT:
								item->m_widget->setPositionX(m_contentWidth-right);
								break;

							default:
								FS_TRACE_WARN("Unkown ALign For List Item");


						}
					}
					break;

				case E_ScrollDirection::HORIZONTAL:
					{
						switch(item->m_alignV)
						{

							case E_AlignV::TOP:
								item->m_widget->setPositionY(-top);
								break;
							case E_AlignV::CENTER:
								item->m_widget->setPositionY(-m_contentHeight/2-(top+bottom)/2);
								break;

							case E_AlignV::BOTTOM:
								item->m_widget->setPositionY(-m_contentHeight-bottom);
								break;
							default:
								FS_TRACE_WARN("Unkown Align For List Item");

						}
					}
					break;
				default:
					FS_TRACE_WARN("Unkown Mode For ListView");
			}

			item->m_widget->setSignalTSAEnabled(true);
		}

		E_AlignH getListItemAlignH(int index)
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);
			return item->m_alignH;

		}
		E_AlignV getListItemAlignV(int index)
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);
			return item->m_alignV;
		}


		void setListItemAlign(UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
		{
			int index=getListItemIndex(widget);
			setListItemAlign(index,alignh,alignv);
		}

		E_AlignH getListItemAlignH(UiWidget* widget)
		{
			int index=getListItemIndex(widget);
			return getListItemAlignH(index);
		}

		E_AlignV getListItemAlignV(UiWidget* widget)
		{
			int index=getListItemIndex(widget);
			return getListItemAlignV(index);
		}

		float getContentWidth()
		{
			return m_contentWidth;
		}
		float getContentHeight()
		{
			return m_contentHeight;
		}

		void setListGap(float value)
		{
			m_listGap=value;
			layout();
		}

		float getListGap()
		{
			return m_listGap;
		}


		int getListItemIndex(UiWidget* widget)
		{
			int size=m_listItem->size();
			for(int i=0;i<size;i++)
			{
				ListItemInfo* item=(ListItemInfo*)m_listItem->get(i);
				if(item->m_widget==widget)
				{
					return i;

				}
			}
			return -1;
		}

	public:
		bool hit2D(float x,float y) FS_OVERRIDE 
		{
			return true;
		}

		void layout()
		{
			switch(m_mode)
			{
				case E_ScrollDirection::VERTICAL:
					layoutVertical();
					break;
				case E_ScrollDirection::HORIZONTAL:
					layoutHorizontal();
					break;
				default:
					FS_TRACE_WARN("Unkown Mode For ListView");
			}
		}


	protected:

		void layoutVertical()
		{
			int size=m_listItem->size();

			float start_y=0;
			float height=0;
			float width=0;

			for(int i=0;i<size;i++)
			{
				UiWidget* widget=((ListItemInfo*)m_listItem->get(i))->m_widget;
				widget->setSignalTSAEnabled(false);
				float left,right,top,bottom;
				widget->getRSBoundSize2D(&left,&right,&bottom,&top);
				widget->setPositionY(start_y-top);
				if(i==0)
				{
					height=top-bottom;
				}
				else 
				{
					height+=top-bottom+m_listGap;
				}
				start_y-=top-bottom+m_listGap;

				if(width<right-left)
				{
					width=right-left;
				}
				widget->setSignalTSAEnabled(true);
			}

			for(int i=0;i<size;i++)
			{

				ListItemInfo* item=(ListItemInfo*)m_listItem->get(i);
				float left,right,top,bottom;
				item->m_widget->getRSBoundSize2D(&left,&right,&bottom,&top);
				item->m_widget->setSignalTSAEnabled(false);
				switch(item->m_alignH)
				{
					case E_AlignH::LEFT:
						item->m_widget->setPositionX(-left);
						break;

					case E_AlignH::CENTER:
						item->m_widget->setPositionX(m_width/2-(left+right)/2);
						break;

					case E_AlignH::RIGHT:
						item->m_widget->setPositionX(m_width-right);
						break;

					default:
						FS_TRACE_WARN("Unkown ALign For List Item");
				}
				item->m_widget->setSignalTSAEnabled(true);
			}
			m_contentWidth=width;
			m_contentHeight=height;
		}

		void layoutHorizontal()
		{
			int size=m_listItem->size();
			float start_x=0;
			float height=0;
			float width=0;

			for(int i=0;i<size;i++)
			{
				UiWidget* widget=((ListItemInfo*)m_listItem->get(i))->m_widget;
				widget->setSignalTSAEnabled(false);
				float left,right,top,bottom;
				widget->getRSBoundSize2D(&left,&right,&bottom,&top);
				widget->setPositionX(start_x-left);
				if(i==0)
				{
					width=right-left;
				}
				else 
				{
					width+=right-left+m_listGap;
				}

				start_x+=right-left+m_listGap;

				if(height<top-bottom)
				{
					height=top-bottom;
				}
				widget->setSignalTSAEnabled(true);
			}

			for(int i=0;i<size;i++)
			{
				ListItemInfo* item=(ListItemInfo*) m_listItem->get(i);
				float left,right,top,bottom;
				item->m_widget->getRSBoundSize2D(&left,&right,&bottom,&top);
				item->m_widget->setSignalTSAEnabled(false);
				switch(item->m_alignV)
				{
					case E_AlignV::TOP:
						item->m_widget->setPositionY(-top);
						break;
					case E_AlignV::CENTER:
						item->m_widget->setPositionY(-m_height/2-(top+bottom)/2);
						break;

					case E_AlignV::BOTTOM:
						item->m_widget->setPositionY(-m_height-bottom);
						break;
					default:
						FS_TRACE_WARN("Unkown Align For List Item");
				}
				item->m_widget->setSignalTSAEnabled(true);
			}
			m_contentWidth=width;
			m_contentHeight=height;
		}
};



ListView* ListView::create(E_ScrollDirection mode,float width,float height)
{
	ListView* ret=new ListView(mode,width,height);
	return ret;
}


ListView* ListView::create(float width,float height)
{
	ListView* ret=new ListView(E_ScrollDirection::VERTICAL,width,height);
	return ret;
}

ListView* ListView::create()
{
	ListView* ret= new ListView(E_ScrollDirection::VERTICAL,0,0);
	return ret;
}

ListView::ListView()
{
	init(E_ScrollDirection::VERTICAL,0,0);
}

ListView::ListView(float width,float height)
{
	init(E_ScrollDirection::VERTICAL,width,height);
}

ListView::ListView(E_ScrollDirection mode,float w,float h)
{
	init(mode,w,h);
	
}


ListView::~ListView()
{
	clearListItem();
	ScrollWidget::removeChild(m_contentPanel);
	FS_SAFE_DESTROY(m_contentPanel);
}

void ListView::init(E_ScrollDirection mode,float w,float h)
{
	m_contentPanel=ListViewContentPanel::create(w,h);
	FS_NO_REF_DESTROY(m_contentPanel);

	ScrollWidget::addChild(m_contentPanel);
	setMode(mode);

	if(mode==E_ScrollDirection::VERTICAL)
	{
		setScrollXEnabled(false);
		setScrollYEnabled(true);
		setContentAlign(E_AlignH::CENTER,E_AlignV::TOP);
	}
	else 
	{
		setScrollXEnabled(true);
		setScrollYEnabled(false);
		setContentAlign(E_AlignH::LEFT,E_AlignV::CENTER);
	}
	setSize(w,h);
	setScissorEnabled(true);
}





void ListView::setMode(E_ScrollDirection mode)
{
	//setScrollMode(mode);
	m_contentPanel->setMode(mode);

	adjustContentSize();

	float x=getScrollPercentX();
	float y=getScrollPercentY();
	setScrollPercent(x,y);
}

E_ScrollDirection ListView::getMode()
{
	return m_contentPanel->getMode();
}

void ListView::setListGap(float value)
{
	m_contentPanel->setListGap(value);

	adjustContentSize();
}

float ListView::getListGap()
{
	return m_contentPanel->getListGap();
}

Vector2 ListView::getListItemSize()
{
	float w=m_contentPanel->getContentWidth();
	float h=m_contentPanel->getContentHeight();

	if(m_contentPanel->getMode()==E_ScrollDirection::VERTICAL)
	{
		w=m_size.x;
	}
	else if (m_contentPanel->getMode()==E_ScrollDirection::HORIZONTAL)
	{
		h=m_size.y;
	}

	return Vector2(w,h);
}


void ListView::addListItem(UiWidget* widget)
{
	addListItem(widget,E_AlignH::CENTER,E_AlignV::CENTER);
}

void ListView::addListItem(UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
{
	int size=m_contentPanel->getListItemNu();
	addListItem(size,widget,alignh,alignv);
}


void ListView::addListItem(int index,UiWidget* widget)
{
	addListItem(index,widget,E_AlignH::CENTER,E_AlignV::CENTER);
}

void ListView::addListItem(int index,UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
{
	float x=getScrollPercentX();
	float y=getScrollPercentY();

	if(widget->getParentWidget()==this)
	{
		FS_TRACE_WARN("widget Alread Add to ListView");
		return;
	}

	if(widget->getParentWidget())
	{
		FS_TRACE_WARN("Widget Already Add to Other Widget");
		return;
	}

	if(widget)
	{
		m_contentPanel->addListItem(index,widget,alignh,alignv);

		widget->setParentWidget(this);

		adjustContentSize();
		setScrollPercent(x,y);
	}
}


void ListView::removeListItem(int index)
{
	UiWidget* widget=m_contentPanel->getListItem(index);
	removeListItem(widget);

}

void ListView::removeListItem(UiWidget* widget)
{
	if(widget->getParentWidget()!=this)
	{
		FS_TRACE_WARN("Widget Is Not Add to ListView");
		return;
	}

	widget->setParentWidget(NULL);
	m_contentPanel->removeListItem(widget);

	adjustContentSize();
}


void ListView::clearListItem()
{
	int list_item_nu=m_contentPanel->getListItemNu();

	for(int i=0;i<list_item_nu;i++)
	{
		UiWidget* widget=m_contentPanel->getListItem(i);
		widget->setParentWidget(NULL);
	}

	m_contentPanel->clearListItem();
	adjustContentSize();
}

int ListView::getListItemNu()
{
	return m_contentPanel->getListItemNu();
}


UiWidget* ListView::getListItem(int index)
{
	return m_contentPanel->getListItem(index);
}

int ListView::getListItemIndex(UiWidget* widget)
{
	return m_contentPanel->getListItemIndex(widget);
}


void ListView::layout()
{
	m_contentPanel->layout();
	adjustContentSize();
}


void ListView::layoutContentWidget(float x,float y)
{
	//FS_TRACE_WARN("x=%f,y=%f",x,y);

	float minx=0.0f,maxx=0.0f,miny=0.0f,maxy=0.0f;

	if(m_contentPanel->getMode()==E_ScrollDirection::VERTICAL)
	{
		minx=0;
		maxx=m_size.x;
		miny=m_contentPanel->getContentHeight();
		maxy=0;
	}
	else if(m_contentPanel->getMode()==E_ScrollDirection::HORIZONTAL)
	{
		minx=0;
		maxx=m_contentPanel->getContentWidth();
		miny=-m_size.y;
		maxy=0;

	}

	float middlex=(minx+maxx)/2;
	float middley=(miny+maxy)/2;

	switch(m_alignv)
	{
		case E_AlignV::TOP:
			m_contentPanel->setPositionY(y-maxy);
			break;

		case E_AlignV::CENTER:
			m_contentPanel->setPositionY(y-middley);
			break;

		case E_AlignV::BOTTOM:
			m_contentPanel->setPositionY(y-miny);
			break;
		default:
			FS_TRACE_WARN("Unkown Align For Vetical");
	}

	switch(m_alignh)
	{
		case E_AlignH::LEFT:
			m_contentPanel->setPositionX(x-minx);
			break;

		case E_AlignH::CENTER:
			m_contentPanel->setPositionX(x-middlex);
			break;

		case E_AlignH::RIGHT:
			m_contentPanel->setPositionX(x-maxx);
			break;

		default:
			FS_TRACE_WARN("Unkown Align For Horizontal");
	}
}

void ListView::childSizeChanged(UiWidget* widget)
{
	layout();
}

void ListView::childAnchorChanged(UiWidget* widget)
{
	layout();
}

void ListView::childTransformChanged(UiWidget* widget)
{
	layout();
}


void ListView::adjustContentSize()
{
	Vector2 size=getListItemSize();
	setContentSize(size.x,size.y);
}

void ListView::setSize(const Vector2& v)
{
	float x=getScrollPercentX();
	float y=getScrollPercentY();

	ScrollWidget::setSize(v);

	m_contentPanel->setSize(v.x,v.y);

	adjustContentSize();

	setScrollPercent(x,y);
}

void ListView::setAnchor(const Vector2& v)
{
	float x=getScrollPercentX();
	float y=getScrollPercentY();

	ScrollWidget::setAnchor(v);

	setScrollPercent(x,y);
}

void ListView::addChild(Entity* en)
{
	FS_TRACE_WARN("Can't Add Child To ListView,Use addListItem");
}

void ListView::clearChild()
{
	clearListItem();
}

void ListView::removeChild(Entity* en)
{
	UiWidget* ui_widget=dynamic_cast<UiWidget*>(en);
	if(ui_widget)
	{
		removeListItem(ui_widget);
	}
	else 
	{
		FS_TRACE_WARN("Entity2D Is Not Manager by ListView");
	}
}


/** Used For ListView FsClass */

static ListView* S_ListView_NewInstance(FsDict* attr)
{
	ListView* ret=ListView::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}

	return ret;

}

static void S_ListView_setListItem(ListView* view,FsArray* attr)
{
	view->clearListItem();
	int list_nu=attr->size();

	for(int i=0;i<list_nu;i++)
	{
		FsDict* dict=attr->getDict(i);
		if(dict)
		{
			FsObject* ob=Global::classMgr()->newInstance(dict);
			if(ob)
			{
				UiWidget* child=dynamic_cast<UiWidget*>(ob);
				if(child)
				{
					view->addListItem(child);
				}
				else 
				{
					FS_TRACE_WARN("Not SubClass Of Entity,Ingore Item(%d)",i);
					ob->destroy();
				}
			}
		}
		else 
		{
			FS_TRACE_WARN("Not Dict,Ingore Item(%d)",i);
		}
	}

}


FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(ListView,setMode,getMode,ScrollDirection);
FS_CLASS_ATTR_SET_GET_FUNCTION(ListView,setListGap,getListGap,float);


static FsClass::FsAttributeDeclare S_ListView_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("mode",E_FsType::FT_CHARS,0,ListView_setMode,ListView_getMode),
	FS_CLASS_ATTR_DECLARE("listGap",E_FsType::FT_F_1,0,ListView_setListGap,ListView_getListGap),
	FS_CLASS_ATTR_DECLARE("listItems",E_FsType::FT_ARRAY,0,S_ListView_setListItem,0),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(ListView,ScrollWidget,S_ListView_NewInstance,S_ListView_Main_Attr);


NS_FS_END



