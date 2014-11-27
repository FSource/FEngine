#include "FsPageView.h"
#include "math/easing/FsBounceEase.h"
#include "math/easing/FsCubicEase.h"
#include "FsVelocityTracker.h"

NS_FS_BEGIN

class PageViewContentPanel: public Entity
{
	protected:
		class PageViewItemInfo:public FsObject 
	{

		public:
			static PageViewItemInfo* create(int alignh,int alignv,UiWidget* widget)
			{
				return new PageViewItemInfo(alignh,alignv,widget);
			}

		public:
			virtual const char* className()
			{
				return "PageViewItemInfo";
			}


		public:
			int m_alignH;
			int m_alignV;
			UiWidget* m_widget;


		protected:
			PageViewItemInfo(int alignh,int alignv,UiWidget* widget)
			{
				m_alignH=alignh;
				m_alignV=alignv;
				m_widget=widget;
				FS_SAFE_ADD_REF(widget);
			}
			~PageViewItemInfo()
			{
				FS_SAFE_DEC_REF(m_widget);
			}
	};



	protected:
		FsArray* m_pageItem;
		int m_mode;
		float m_width;
		float m_height;

	public:
		static PageViewContentPanel* create(int mode,float width,float height)
		{
			PageViewContentPanel* ret=new PageViewContentPanel(mode,width,height);
			return ret;
		}


	protected:
		PageViewContentPanel(int mode,float width,float height)
		{
			m_mode=mode;
			m_width=width;
			m_height=height;
			setTouchEnabled(true);
			setDispatchTouchEnabled(true);
			m_pageItem=FsArray::create();
		}

		~PageViewContentPanel()
		{
			FS_SAFE_DEC_REF(m_pageItem);
		}


	public:
		void addPageItem(UiWidget* widget,int alignh,int alignv)
		{
			int index=m_pageItem->size();
			addPageItem(index,widget,alignh,alignv);
		}

		void addPageItem(int index,UiWidget* widget,int alignh,int alignv)
		{
			PageViewItemInfo* item=PageViewItemInfo::create(alignh,alignv,widget);

			if(index>(int)m_pageItem->size())
			{
				index=m_pageItem->size();
			}

			m_pageItem->insert(index,item);
			layout();
		}

		void removePageItem(UiWidget* widget)
		{
			int index=getPageItemIndex(widget);
			removePageItem(index);
		}

		void removePageItem(int index)
		{
			m_pageItem->remove(index);
			layout();
		}

		void clearPageItem()
		{
			m_pageItem->clear();
		}

		int getPageItemNu()
		{
			return m_pageItem->size();
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



		void setPageItemAlign(UiWidget* widget)
		{
			int index=getPageItemIndex(widget);
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			setPageItemAlign(index,item->m_alignH,item->m_alignV);
		}

		void setPageItemAlign(UiWidget* widget,int alignh,int alignv)
		{
			int index=getPageItemIndex(widget);
			setPageItemAlign(index,alignh,alignv);
		}

		void setPageItemAlign(int index,int alignh,int alignv)
		{
			setPageItemAlign(m_mode,index,alignh,alignv);
		}

		void setPageItemAlign(int mode,int index,int alignh,int alignv)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			float start_x,start_y;
			if(mode==PageView::SCROLL_HORIZONTAL)
			{
				start_x=m_width*index;
				start_y=0;
			}
			else 
			{
				start_x=0;
				start_y=-m_height*index;
			
			}

			float sminx,smaxx,sminy,smaxy;
			item->m_widget->getRSBoundSize2D(&sminx,&smaxx,&sminy,&smaxy);
			switch(alignh)
			{
			
				case PageView::ALIGN_LEFT:
					item->m_widget->setPositionX(start_x-sminx);
					break;
				
				case PageView::ALIGN_CENTER:
					item->m_widget->setPositionX(start_x+m_width/2-(sminx+smaxx)/2);
					break;

				case PageView::ALIGN_RIGHT:
					item->m_widget->setPositionX(start_y+m_width-smaxx);
					break;
				default:
					FS_TRACE_WARN("Unkown ALign For Page Item");
			}

			switch(alignv)
			{
				case PageView::ALIGN_TOP:
					item->m_widget->setPositionY(start_y-smaxy);
					break;

				case PageView::ALIGN_CENTER:
					item->m_widget->setPositionY(start_y-m_height/2-(smaxy+sminy)/2);
					break;

				case PageView::ALIGN_BOTTOM:
					item->m_widget->setPositionY(start_y-m_height-sminy);
					break;

				default:
					FS_TRACE_WARN("Unkown ALign For Page Item");
			}
		}


		UiWidget* getPageItem(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_widget;
		
		}


		int getPageItemAlignH(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_alignH;
		}

		int getPageItemAlignV(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_alignV;
		}


		int getPageItemIndex(UiWidget* widget)
		{
			int size=m_pageItem->size();
			for(int i=0;i<size;i++)
			{
				PageViewItemInfo* item=(PageViewItemInfo*)m_pageItem->get(i);
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
			int size=m_pageItem->size();
			for(int i=0;i<size;i++)
			{
				PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(i);
				setPageItemAlign(i,item->m_alignH,item->m_alignV);
			}
		}
};


const char* PageView::className()
{
	return FS_PAGE_VIEW_CLASS_NAME;
}

PageView* PageView::create(int mode,float width,float height)
{
	PageView* ret=new PageView(mode,width,height);
	return ret;
}


PageView* PageView::create(float width,float height)
{
	PageView* ret=new PageView(SCROLL_HORIZONTAL,width,height);
	return ret;
}

PageView::PageView(int mode,float w,float h)
{
	m_contentPanel=PageViewContentPanel::create(mode,w,h);
	FS_NO_REF_DESTROY(m_contentPanel);
	addChild(m_contentPanel);


	m_xoffset=0;
	m_yoffset=0;
	m_currentPageIndex=0;

	m_isDraged=false;
	m_lastPosX=0;
	m_lastPosY=0;
	m_touchTap=10;


	m_scrollFinished=true;
	m_scrollBeginPos=0;
	m_scrollEndPos=0;
	m_scrollDuration=0;
	m_scrollTimeEscape=0;


	m_scrollEasing=CubicEase::create();
	m_scrollEasing->setMode(FS_EASE_OUT);
	

	m_velocityTracker=VelocityTracker::create();



	setMode(mode);

	setSize(w,h);
	setScissorEnabled(true);



}

PageView::~PageView()
{
	int size=m_contentPanel->getPageItemNu();

	for(int i=0;i<size;i++)
	{
		UiWidget* widget=m_contentPanel->getPageItem(i);
		widget->setParentWidget(NULL);
	}

	remove(m_contentPanel);
	FS_SAFE_DESTROY(m_contentPanel);
	FS_SAFE_DEC_REF(m_scrollEasing);
}





void PageView::setMode(int mode)
{
	m_contentPanel->setMode(mode);
}

int PageView::getMode()
{
	return m_contentPanel->getMode();
}

void PageView::addPage(UiWidget* widget)
{
	addPage(widget,ALIGN_CENTER,ALIGN_CENTER);
}

void PageView::addPage(UiWidget* widget,int alignh,int alignv)
{
	int size=m_contentPanel->getPageItemNu();

	addPage(size,widget,alignh,alignv);
}

void PageView::addPage(int index,UiWidget* widget)
{
	addPage(index,widget,ALIGN_CENTER,ALIGN_CENTER);
}

void PageView::addPage(int index,UiWidget* widget,int alignh,int alignv)
{
	if(widget->getParentWidget()==this)
	{
		FS_TRACE_WARN("widget Alread Add to ListView");
		return;
	}
	if(widget->getParentWidget())
	{
		FS_TRACE_WARN("widget Alread Add to Other Widget");
		return;
	}

	if(widget)
	{
		m_contentPanel->addPageItem(index,widget,alignh,alignv);
		m_contentPanel->addChild(widget);
		widget->setParentWidget(this);
		adjustContentPanel();
	}

}

void PageView::setPageAlign(int index,int alignh,int alignv)
{
	m_contentPanel->setPageItemAlign(index,alignh,alignv);
}

void PageView::setPageAlign(UiWidget* widget,int alignh,int alignv)
{
	m_contentPanel->setPageItemAlign(widget,alignh,alignv);
}

void PageView::removePage(int index)
{
	UiWidget* widget=m_contentPanel->getPageItem(index);
	removePage(widget);

}

void PageView::removePage(UiWidget* widget)
{
	if(widget->getParentWidget()!=this)
	{
		FS_TRACE_WARN("Widget Is Not Add to PageView");
		return;
	}
	widget->setParentWidget(NULL);
	m_contentPanel->removePageItem(widget);
	m_contentPanel->remove(widget);
	adjustContentPanel();
}


void PageView::clearPage()
{

}

int PageView::getPageNu()
{
	return m_contentPanel->getPageItemNu();
}

UiWidget* PageView::getPage(int index)
{
	return m_contentPanel->getPageItem(index);
}

int PageView::getPageIndex(UiWidget* widget)
{
	return m_contentPanel->getPageItemIndex(widget);
}



void PageView::prevPage()
{
	int page_index=m_currentPageIndex-1;
	if(page_index<0)
	{
		page_index=0;
	}
	setCurrentPageIndex(page_index);
}

void PageView::nextPage()
{
	int page_index=m_currentPageIndex+1;
	if(page_index>=getPageNu())
	{
		page_index=getPageNu()-1;
	}

	setCurrentPageIndex(page_index);
}


void PageView::setCurrentPageIndex(int index)
{
	if(index<0)
	{
		index=0;
	}

	if(index>=getPageNu())
	{
		index=getPageNu()-1;
	}


	if(!m_scrollFinished)
	{
		m_scrollFinished=true;
	}

	if(m_contentPanel->getMode()==SCROLL_HORIZONTAL)
	{
		m_xoffset=-index*m_size.x;
		m_contentPanel->setPosition(m_xoffset,m_yoffset,0);
		if(index!=m_currentPageIndex)
		{
			int old_index=m_currentPageIndex;
			m_currentPageIndex=index;
			pageIndexChanged(old_index,m_currentPageIndex);
		}
	}
	adjustContentPanel();
}




int PageView::getCurrentPageIndex()
{
	return m_currentPageIndex;
}

void PageView::setCurrentPage(UiWidget* widget)
{
	int index=getPageIndex(widget);
	setCurrentPageIndex(index);
}


UiWidget* PageView::getCurrentPage()
{
	return m_contentPanel->getPageItem(m_currentPageIndex);
}


void PageView::slideToPageIndex(int index)
{
	if(index<0)
	{
		index=0;
	}

	if(index>=getPageNu())
	{
		index=getPageNu()-1;
	}

	scrollFromTo(m_xoffset,-index*m_size.x);
}



void PageView::slideToPage(UiWidget* widget)
{
	int index=getPageIndex(widget);
	slideToPageIndex(index);
}

void PageView::slideToNextPage()
{
	slideToPageIndex(m_currentPageIndex+1);
}

void PageView::slideToPrevPage()
{
	slideToPageIndex(m_currentPageIndex-1);
}




bool  PageView::touchBegin(float x,float y)
{

	UiWidget::touchBegin(x,y);

	if( !m_scrollFinished)
	{
		m_isDraged=true;
		m_scrollFinished=true;
	}


	m_lastPosX=x;
	m_lastPosY=y;
	m_velocityTracker->beginTrack(x,y);

	return true;

}



bool  PageView::touchMove(float x,float y)
{
	//FS_TRACE_WARN("OnTouchMove(%f,%f)",x,y);
	
	UiWidget::touchMove(x,y);

	float diffx=x-m_lastPosX;
	float diffy=y-m_lastPosY;
	int mode=m_contentPanel->getMode();

	if(!m_isDraged)
	{
		if(mode==SCROLL_HORIZONTAL)
		{
			if(Math::abs(diffx)>=m_touchTap)
			{
				m_isDraged=true;
				diffx=diffx>0? diffx-m_touchTap:diffx+m_touchTap;
			}
		}
		else if(mode==SCROLL_VERTICAL)
		{
			if(Math::abs(diffy)>m_touchTap)
			{
				m_isDraged=true;
				diffy=diffy>0?diffy-m_touchTap:diffy+m_touchTap;
			}
		}
		else 
		{
			FS_TRACE_WARN("Unkown Mode For PageView");
		}

	}

	if(m_isDraged)
	{
		if(mode==SCROLL_HORIZONTAL)
		{
			scrollXBy(diffx);
		}
		else if(mode==SCROLL_VERTICAL)
		{
			scrollYBy(diffy);
		}
		m_lastPosX=x;
		m_lastPosY=y;
	}
	m_velocityTracker->addTrack(x,y);


	return true;
}

bool PageView::touchEnd(float x,float y)
{
	UiWidget::touchEnd(x,y);
	m_velocityTracker->endTrack(x,y);

	float v=0;
	int mode =m_contentPanel->getMode();
	if(mode)
	{
		v=m_velocityTracker->getVelocityX();
	}
	else 
	{
		v=m_velocityTracker->getVelocityY();
	}

	if(m_isDraged)
	{
		checkPageAlign(v);
	}
	m_isDraged=false;

	return true;
}






void PageView::update(float dt)
{
	updateScroll(dt);
}

void PageView::childSizeChanged(UiWidget* widget,float w,float h)
{
	m_contentPanel->setPageItemAlign(widget);
}

void PageView::childAnchorChanged(UiWidget* widget,float w,float h)
{
	m_contentPanel->setPageItemAlign(widget);
}


void PageView::sizeChanged(float width,float height)
{
	m_contentPanel->setSize(width,height);

	adjustContentPanel();
}

void PageView::anchorChanged(float x,float y)
{
	adjustContentPanel();
}

void PageView::removeWidget(UiWidget* widget)
{
	removePage(widget);
}


void PageView::layout()
{
	adjustContentPanel();

}



void PageView::scrollXBy(float value)
{
	scrollXTo(m_xoffset+value);
}

void PageView::scrollYBy(float value)
{
	scrollYTo(m_yoffset+value);
}


void PageView::scrollXTo(float value)
{
	m_xoffset=value;
	adjustContentPanel();
}

void PageView::scrollYTo(float value)
{
	m_yoffset=value;
	adjustContentPanel();
}


void PageView::adjustContentPanel()
{

	int mode=m_contentPanel->getMode();
	float left,right,bottom,top;

	getBoundSize2D(&left,&right,&bottom,&top);

	float x=0,y=0;

	if(mode==SCROLL_HORIZONTAL)
	{
		x=left+m_xoffset;
		y=top;
	}
	else if(mode==SCROLL_VERTICAL)
	{
		x=left;
		y=top+m_yoffset;
	}
	else 
	{
		FS_TRACE_WARN("Unkown Mode For PageView");
	}

	m_contentPanel->setPosition(x,y,0);
	
	//FS_TRACE_WARN("Pos(%f,%f)",x,y);
}



void PageView::checkPageAlign()
{
	int mode=m_contentPanel->getMode();

	if(mode==SCROLL_HORIZONTAL)
	{
		float next_index=Math::floor(m_xoffset/m_size.x+0.5f);

		next_index=Math::clampf(next_index,0,-float(m_contentPanel->getPageItemNu()-1));

		float next_offset=next_index*m_size.x;

		if(Math::floatEqual(m_xoffset,next_offset))
		{
			return;
		}
		scrollFromTo(m_xoffset,next_offset);
	}

} 

void PageView::checkPageAlign(float v)
{
	//FS_TRACE_WARN("V=%f",v);

	float supper_v=500;

	int mode=m_contentPanel->getMode();


	if(mode==SCROLL_HORIZONTAL)
	{
		float cur_index=Math::floor(-m_xoffset/m_size.x);
		float cur_ret=(-m_xoffset-cur_index*m_size.x)/m_size.x;

		if(v<0)
		{
			if(cur_ret<0.5)
			{
				if(-v>supper_v)
				{
					cur_index=cur_index+1;
				}
			}
			else 
			{
				cur_index=cur_index+1;
			}
		}
		else 
		{
			if(cur_ret>0.5)
			{
				if(v<supper_v)
				{
					cur_index=cur_index+1;
				}
			}
		}



		cur_index=Math::clampf(-cur_index,-float(m_contentPanel->getPageItemNu()-1),0);

		//FS_TRACE_WARN("CurIndex=%f",cur_index);

		scrollFromTo(m_xoffset,cur_index*m_size.x);

	}

}


void PageView::scrollFromTo(float start,float end)
{
	float time=Math::abs(start-end)/m_size.x*1.0f;
	if(time<0.25)
	{
		time=0.25;
	}

	scrollFromTo(start,end,time);
}

void PageView::scrollFromTo(float start,float end,float time)
{
	m_scrollFinished=false;
	m_scrollBeginPos=start;
	m_scrollEndPos=end;
	m_scrollTimeEscape=0;
	m_scrollDuration=time;

}

void PageView::updateScroll(float dt)
{
	if(m_scrollFinished)
	{
		return ;
	}

	m_scrollTimeEscape+=dt;

	if(m_scrollTimeEscape>m_scrollDuration)
	{
		m_scrollTimeEscape=m_scrollDuration;
		m_scrollFinished=true;
	}



	float percent=m_scrollEasing->getValue(m_scrollTimeEscape/m_scrollDuration);


	int mode =m_contentPanel->getMode();

	if(mode == SCROLL_HORIZONTAL)
	{
		float offset= m_scrollBeginPos+(m_scrollEndPos-m_scrollBeginPos)*percent;
		if(Math::floatEqual(offset,m_scrollEndPos))
		{
			m_xoffset=m_scrollEndPos;
			m_scrollFinished=true;
		}
		else 
		{
			m_xoffset=offset;
		}
	}
	else 
	{
		float offset= m_scrollBeginPos+(m_scrollEndPos-m_scrollBeginPos)*percent;
		if(Math::floatEqual(offset,m_scrollEndPos))
		{
			m_yoffset=m_scrollEndPos;
			m_scrollFinished=true;
		}
		else 
		{
			m_yoffset= offset;
		}

	}

	adjustContentPanel();

	if(m_scrollFinished)
	{
		if(mode==SCROLL_HORIZONTAL)
		{
			int index=(int)Math::floor(Math::abs(m_xoffset)/m_size.x+0.5f);
			if(m_currentPageIndex!=index)
			{
				int old_index=m_currentPageIndex;
				m_currentPageIndex=index;
				pageIndexChanged(old_index,m_currentPageIndex);
			}

		}
		else 
		{
			int index=(int)Math::floor(Math::abs(m_yoffset)/m_size.y+0.5f);
			if(m_currentPageIndex!=index)
			{
				int old_index=m_currentPageIndex;
				m_currentPageIndex=index;
				pageIndexChanged(old_index,m_currentPageIndex);
			}
		}
	}
}




void PageView::pageIndexChanged(int old_index,int new_index)
{
}



NS_FS_END 



