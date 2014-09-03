#include <assert.h>
#include "FsListView.h"

NS_FS_BEGIN

class ListViewContentPanel:public Entity()
{
	class ListItemInfo:public FsObject 
	{
		public:
			ListItemInfo* create(int alignh,int alignv,UiWidget* widget)
			{

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


	public:
		static ListViewContentPanel* create()
		{
			return new ListViewContentPanel();
		}


	protected:
		ListViewContentPanel()
		{
			m_mode=ListView::SCROLL_VERTICAL;
			m_listItem=FsArray::create();
			m_listGap=0;
			m_contentWidth=0;
			m_contentHeight=0;
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
			ListItemInfo* item=ListItemInfo::create(widget,alignh,alignv);
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

		int UiWidget* getListItem(int index)
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
								item->m_widget->setPositionX(width/2-(left+right)/2);
								break;

							case ListView::ITEM_ALIGN_RIGHT:
								item->m_widget->setPositionX(width-right);
								break;

							default:
								FS_TRACE_WARN("Unkown ALign For List Item");


						}
					}
					break;

				case ListView::SCROLL_HORIZONTAL:
					{
						switch(item->alignv)
						{

							case ListView::ITEM_ALIGN_TOP:
								item->m_widget->setPositionY(-top);
								break;
							case ListView::ITEM_ALIGN_CENTER:
								item->m_widget->setPositionY(-height/2-(top+bottom)/2);
								break;

							case ListView::ITEM_ALIGN_BOTTOM:
								item->m_widget->setPositionY(-height-bottom);
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
		{
			ListItemInfo* item=(ListItemInfo*)m_listItem->get(index);
			return item->m_alignV;

		}
		}

		void setListItemAlign(UiWidget* widget,int alignh,int alignv);
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

		void getContentWidth()
		{
			return m_contentWidth;
		}
		void getContentHeight()
		{
			return m_contentHeight;
		}

	public:
		virtual bool hit2D(float x,float y){return true;}
		void layout()
		{
			switch(m_mode)
			{
				case SCROLL_VERTICAL:
					layoutVertical();
					break;
				case SCROLL_HORIZONTAL:
					layoutHorizontal();
					break;
				default:
					FS_TRACE_WARN("Unkown Mode For ListView");
			}

		}
	protected:

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
				widget->getRSBoundSize2D(&left,&right,&top,&bottom);
				widget->setPositionY(start_y-top);
				if(i==0)
				{
					height=top-bottom;
				}
				else 
				{
					height+=top-bottom+m_listGap;
				}
				start_y+=top-bottom+m_listGap;

				if(width<right-left)
				{
					width=right-left;
				}
			}

			for(int i=0;i<size;i++)
			{

				ListItemInfo* item=(ListItemInfo*)m_listItem->get(i);
				float left,right,top,bottom;
				item->m_widget->getRSBoundSize2D(&left,&right,&top,&bottom);
				switch(item->m_alignH)
				{
					case ListView::ITEM_ALIGN_LEFT:
						item->m_widget->setPositionX(-left);
						break;

					case ListView::ITEM_ALIGN_CENTER:
						item->m_widget->setPositionX(width/2-(left+right)/2);
						break;

					case ListView::ITEM_ALIGN_RIGHT:
						item->m_widget->setPositionX(width-right);
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
				widget->getRSBoundSize2D(&left,&right,&top,&bottom);
				widget->setPositionX(start_x-left);
				if(i==0)
				{
					width=right-left;
				}
				else 
				{
					width+=right-left+m_listGap;
				}

				start_x=right-left+m_listGap;

				if(height<top-bottom)
				{
					height=top-bottom;
				}
			}

			for(int i=0;i<size;i++)
			{
				ListItemInfo* item=(ListItemInfo*) m_listItem->get(i);
				float left,right,top,bottom;
				item->m_widget->getRSBoundSize2D(&left,&right,&top,&bottom);
				switch(item->m_alignV)
				{
					case ListView::ITEM_ALIGN_TOP:
						item->m_widget->setPositionY(-top);
						break;
					case ListView::ITEM_ALIGN_CENTER:
						item->m_widget->setPositionY(-height/2-(top+bottom)/2);
						break;

					case ListView::ITEM_ALIGN_BOTTOM:
						item->m_widget->setPositionY(-height-bottom);
						break;
					default:
						FS_TRACE_WARN("Unkown Align For List Item");
				}
			}

		}
}


const char* ListView::className()
{
	return FS_LIST_VIEW_CLASS_NAME;
}



ListView* ListView::create(int mode,float width,float height)
{
	ListView* ret=new ListView(mode,width,height);
	return ret;
}

ListView::ListView(int mode,int w,int h)
{
	m_contentPanel=ListViewContentPanel::create();
	FS_NO_REF_DESTORY(m_contentPanel);
	addChild(m_contentPanel);

	m_contentPanel->setMode(mode);

	setSize(w,h);

}


ListView::~ListView()
{
	int size=m_contentPanel->getListItemNu();

	for(int i=0;i<size;i++)
	{
		UiWidget* widget=m_contentPanel->getListite(i);
		widget->setParentWidget(NULL);
	}
	remove(m_contentHeight);

	FS_SAFE_DESTORY(m_contentPanel);
}



void ListView::removeWidget(UiWidget* widget)
{
	removeListItem(widget);
}

void ListView::scrollChange(float x,float y)
{
}



void ListView::setMode(int mode)
{
	m_contentPanel->setMode(mode);

	float width=m_contentPanel->getContentWidth();
	float height=m_contentPanel->getContentHeight();
	setContentSize(width,height);
}

void ListView::setListGap(float value)
{
	m_contentPanel->setListGap(value);

	float width=m_contentPanel->getContentWidth();
	float height=m_contentPanel->getContentHeight();
	setContentSize(width,height);
}

float ListView::getListGap()
{
	return m_contentPanel->getListGap();
}


void ListView::addListItem(UiWidget* widget)
{
	int size=m_listItem->size();
	addListItem(size,widget);
}

void ListView::addListItem(int index,UiWidget* widget,int alignh,int alignv)
{
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

		float width=m_contentPanel->getContentWidth();
		float height=m_contentPanel->getContentHeight();
		setContentSize(width,height);
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

	float width=m_contentPanel->getContentWidth();
	float height=m_contentPanel->getContentHeight();
	setContentSize(width,height);
}


int ListView::getListItemNu()
{
	return m_contentPanel->getListItemNu();
}



UiWidget* ListView::getListItem(int index)
{
	return m_contentPanel->getListItem(index);
}



void ListView::layout()
{
	m_contentPanel->layout();
	float width=m_contentPanel->getContentWidth();
	float height=m_contentPanel->getContentHeight();
	setContentSize(width,height);
}




NS_FS_END



