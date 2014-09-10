#include <assert.h>
#include "FsListView.h"

NS_FS_BEGIN

class ListViewContentPanel:public Entity
{
	protected:
	class ListItemInfo:public FsObject 
	{
		public:
			static ListItemInfo* create(int alignh,int alignv,UiWidget* widget)
			{
				return new ListItemInfo(alignh,alignv,widget);
			}
		public:
			virtual const char* className()
			{
				return "ListItemInfo";
			}
		public:
			int m_alignH;
			int m_alignV;
			UiWidget* m_widget;

		protected:
			ListItemInfo(int alignh,int alignv,UiWidget* widget)
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
		int m_mode;

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
			m_mode=ListView::SCROLL_VERTICAL;
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
		void addListItem(UiWidget* widget,int alignh,int alignv)
		{
			int index=m_listItem->size();
			addListItem(index,widget,alignh,alignv);
		}

		void addListItem(int index,UiWidget* widget,int alignh,int alignv)
		{
			ListItemInfo* item=ListItemInfo::create(alignh,alignv,widget);
			if(index>(int)m_listItem->size())
			{
				index=m_listItem->size();
			}
			m_listItem->insert(index,item);
			layout();
		}


		void removeListItem(UiWidget* widget)
		{
			int index=getListItemIndex(widget);
			removeListItem(index);
		}

		void removeListItem(int index)
		{
			m_listItem->remove(index);
			layout();
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

		void setMode(int mode)
		{
			m_mode=mode;
			layout();
		}

		int getMode()
		{
			return m_mode;
		}

		void setSize(float width,float height)
		{
			m_width=width;
			m_height=height;

			layout();
		}


		void setListItemAlign(int index,int alignh,int alignv)
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);

			item->m_alignH=alignh;
			item->m_alignV=alignv;

			float left,right,top,bottom;

			item->m_widget->getRSBoundSize2D(&left,&right,&top,&bottom);
			switch(m_mode)
			{
				case ListView::SCROLL_VERTICAL:
					{
						switch(item->m_alignH)
						{
							case ListView::ITEM_ALIGN_LEFT:
								item->m_widget->setPositionX(-left);
								break;

							case ListView::ITEM_ALIGN_CENTER:
								item->m_widget->setPositionX(m_contentWidth/2-(left+right)/2);
								break;

							case ListView::ITEM_ALIGN_RIGHT:
								item->m_widget->setPositionX(m_contentWidth-right);
								break;

							default:
								FS_TRACE_WARN("Unkown ALign For List Item");


						}
					}
					break;

				case ListView::SCROLL_HORIZONTAL:
					{
						switch(item->m_alignV)
						{

							case ListView::ITEM_ALIGN_TOP:
								item->m_widget->setPositionY(-top);
								break;
							case ListView::ITEM_ALIGN_CENTER:
								item->m_widget->setPositionY(-m_contentHeight/2-(top+bottom)/2);
								break;

							case ListView::ITEM_ALIGN_BOTTOM:
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
		}

		int getListItemAlignH(int index)
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);
			return item->m_alignH;

		}
		int getListItemAlignV(int index)
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);
			return item->m_alignV;
		}


		void setListItemAlign(UiWidget* widget,int alignh,int alignv)
		{
			int index=getListItemIndex(widget);
			setListItemAlign(index,alignh,alignv);
		}

		int getListItemAlignH(UiWidget* widget)
		{
			int index=getListItemIndex(widget);
			return getListItemAlignH(index);
		}

		int getListItemAlignV(UiWidget* widget)
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
		virtual bool hit2D(float x,float y){return true;}
		void layout()
		{
			switch(m_mode)
			{
				case ListView::SCROLL_VERTICAL:
					layoutVertical();
					break;
				case ListView::SCROLL_HORIZONTAL:
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
			}

			for(int i=0;i<size;i++)
			{

				ListItemInfo* item=(ListItemInfo*)m_listItem->get(i);
				float left,right,top,bottom;
				item->m_widget->getRSBoundSize2D(&left,&right,&bottom,&top);
				switch(item->m_alignH)
				{
					case ListView::ITEM_ALIGN_LEFT:
						item->m_widget->setPositionX(-left);
						break;

					case ListView::ITEM_ALIGN_CENTER:
						item->m_widget->setPositionX(m_width/2-(left+right)/2);
						break;

					case ListView::ITEM_ALIGN_RIGHT:
						item->m_widget->setPositionX(m_width-right);
						break;

					default:
						FS_TRACE_WARN("Unkown ALign For List Item");
				}
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
			}

			for(int i=0;i<size;i++)
			{
				ListItemInfo* item=(ListItemInfo*) m_listItem->get(i);
				float left,right,top,bottom;
				item->m_widget->getRSBoundSize2D(&left,&right,&bottom,&top);
				switch(item->m_alignV)
				{
					case ListView::ITEM_ALIGN_TOP:
						item->m_widget->setPositionY(-top);
						break;
					case ListView::ITEM_ALIGN_CENTER:
						item->m_widget->setPositionY(-m_height/2-(top+bottom)/2);
						break;

					case ListView::ITEM_ALIGN_BOTTOM:
						item->m_widget->setPositionY(-m_height-bottom);
						break;
					default:
						FS_TRACE_WARN("Unkown Align For List Item");
				}
			}
			m_contentWidth=width;
			m_contentHeight=height;
		}
};


const char* ListView::className()
{
	return FS_LIST_VIEW_CLASS_NAME;
}

ListView* ListView::create(int mode,float width,float height)
{
	ListView* ret=new ListView(mode,width,height);
	return ret;
}


ListView* ListView::create(float width,float height)
{
	ListView* ret=new ListView(SCROLL_VERTICAL,width,height);
	return ret;
}


ListView::ListView(int mode,float w,float h)
{
	m_contentPanel=ListViewContentPanel::create(w,h);
	FS_NO_REF_DESTROY(m_contentPanel);

	addChild(m_contentPanel);

	setMode(mode);
	if(mode==SCROLL_VERTICAL)
	{
		setContentAlign(ScrollWidget::ALIGN_CENTER,ScrollWidget::ALIGN_TOP);
	}
	else 
	{
		setContentAlign(ScrollWidget::ALIGN_LEFT,ScrollWidget::ALIGN_CENTER);
	}

	setSize(w,h);
	setScissorEnabled(true);

}


ListView::~ListView()
{
	int size=m_contentPanel->getListItemNu();

	for(int i=0;i<size;i++)
	{
		UiWidget* widget=m_contentPanel->getListItem(i);
		widget->setParentWidget(NULL);
	}
	remove(m_contentPanel);

	FS_SAFE_DESTROY(m_contentPanel);
}



void ListView::removeWidget(UiWidget* widget)
{
	removeListItem(widget);
}




void ListView::setMode(int mode)
{
	setScrollMode(mode);
	m_contentPanel->setMode(mode);

	adjustContentSize();
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

	if(m_contentPanel->getMode()==SCROLL_VERTICAL)
	{
		w=m_size.x;
	}
	else if (m_contentPanel->getMode()==SCROLL_HORIZONTAL)
	{
		h=m_size.y;
	}

	return Vector2(w,h);
}


void ListView::addListItem(UiWidget* widget)
{
	addListItem(widget,ListView::ITEM_ALIGN_CENTER,ListView::ITEM_ALIGN_CENTER);
}

void ListView::addListItem(UiWidget* widget,int alignh,int alignv)
{
	int size=m_contentPanel->getListItemNu();
	addListItem(size,widget,alignh,alignv);
}


void ListView::addListItem(int index,UiWidget* widget)
{
	addListItem(index,widget,ListView::ITEM_ALIGN_CENTER,ListView::ITEM_ALIGN_CENTER);
}

void ListView::addListItem(int index,UiWidget* widget,int alignh,int alignv)
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
		m_contentPanel->addChild(widget);

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
	m_contentPanel->remove(widget);

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


void ListView::scrollChange(float x,float y)
{
	//FS_TRACE_WARN("x=%f,y=%f",x,y);

	float minx,maxx,miny,maxy;

	if(m_contentPanel->getMode()==SCROLL_VERTICAL)
	{
		minx=0;
		maxx=m_size.x;
		miny=m_contentPanel->getContentHeight();
		maxy=0;
	}
	else if(m_contentPanel->getMode()==SCROLL_HORIZONTAL)
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
		case ALIGN_TOP:
			m_contentPanel->setPositionY(y-maxy);
			break;

		case ALIGN_CENTER:
			m_contentPanel->setPositionY(y-middley);
			break;

		case ALIGN_BOTTOM:
			m_contentPanel->setPositionY(y-miny);
			break;
		default:
			FS_TRACE_WARN("Unkown Align For Vetical");
	}

	switch(m_alignh)
	{
		case ALIGN_LEFT:
			m_contentPanel->setPositionX(x-minx);
			break;

		case ALIGN_CENTER:
			m_contentPanel->setPositionX(x-middlex);
			break;

		case ALIGN_RIGHT:
			m_contentPanel->setPositionX(x-maxx);
			break;

		default:
			FS_TRACE_WARN("Unkown Align For Horizontal");
	}
}

void ListView::childSizeChanged(UiWidget* widget,float w,float h)
{
	layout();
}

void ListView::childAnchorChanged(UiWidget* widget,float x,float y)
{
	layout();
}
void ListView::adjustContentSize()
{
	Vector2 size=getListItemSize();

	setContentSize(size.x,size.y);

}

void ListView::sizeChanged(float w,float h)
{
	float x=getScrollPercentX();
	float y=getScrollPercentY();

	m_contentPanel->setSize(w,h);

	adjustContentSize();

	setScrollPercent(x,y);
}

void ListView::anchorChanged(float w,float h)
{
	float x=getScrollPercentX();
	float y=getScrollPercentY();

	ScrollWidget::sizeChanged(w,h);

	setScrollPercent(x,y);

}



NS_FS_END



