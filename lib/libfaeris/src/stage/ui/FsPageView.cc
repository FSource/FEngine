/*************************************************************************/
/*  FsPageView.cc                                                        */
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


#include "FsPageView.h"
#include "math/easing/FsBounceEase.h"
#include "math/easing/FsCubicEase.h"
#include "FsVelocityTracker.h"
#include "FsClass.h"

NS_FS_BEGIN

class PageViewContentPanel: public Entity2D
{
	public:
		class PageViewItemInfo:public FsObject 
	{

		public:
			static PageViewItemInfo* create(E_AlignH alignh,E_AlignV alignv,UiWidget* widget)
			{
				return new PageViewItemInfo(alignh,alignv,widget);
			}


		public:
			E_AlignH m_alignH;
			E_AlignV m_alignV;
			UiWidget* m_widget;


		protected:
			PageViewItemInfo(E_AlignH alignh,E_AlignV alignv,UiWidget* widget)
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
		E_ScrollDirection m_mode;
		float m_width;
		float m_height;

	public:
		static PageViewContentPanel* create(E_ScrollDirection mode,float width,float height)
		{
			PageViewContentPanel* ret=new PageViewContentPanel(mode,width,height);
			return ret;
		}


	protected:
		PageViewContentPanel(E_ScrollDirection mode,float width,float height)
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
		void addPageItem(UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
		{
			int index=m_pageItem->size();
			addPageItem(index,widget,alignh,alignv);
		}

		void addPageItem(int index,UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
		{
			PageViewItemInfo* item=PageViewItemInfo::create(alignh,alignv,widget);

			if(index>(int)m_pageItem->size())
			{
				index=m_pageItem->size();
			}
			m_pageItem->insert(index,item);
			addChild(widget);
			layout();

		}

		void removePageItem(UiWidget* widget)
		{
			int index=getPageItemIndex(widget);
			removePageItem(index);
		}

		void removePageItem(int index)
		{
			PageViewItemInfo* item_info=(PageViewItemInfo*)m_pageItem->get(index);
			removeChild(item_info->m_widget);
			m_pageItem->remove(index);
			layout();
		}

		void clearPageItem()
		{
			clearChild();
			m_pageItem->clear();
			layout();
		}

		int getPageItemNu()
		{
			return m_pageItem->size();
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


		void adjustPageItemAlign(UiWidget* widget)
		{
			int index=getPageItemIndex(widget);
			if(index==-1)
			{
				return;
			}

			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			adjustPageItemAlign(index,item->m_alignH,item->m_alignV);
		}

		void adjustPageItemAlign(UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
		{
			int index=getPageItemIndex(widget);
			if(index==-1)
			{
				return;
			}

			adjustPageItemAlign(index,alignh,alignv);
		}

		void adjustPageItemAlign(int index,E_AlignH alignh,E_AlignV alignv)
		{
			adjustPageItemAlign(m_mode,index,alignh,alignv);
		}


		void adjustPageItemAlign(E_ScrollDirection mode,int index,E_AlignH alignh,E_AlignV alignv)
		{
			if(index<0|| index>=(int)m_pageItem->size())
			{
				return;
			}

			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			item->m_widget->setSignalTSAEnabled(false);
			float start_x,start_y;
			if(mode==E_ScrollDirection::HORIZONTAL)
			{
				start_x=m_width*index;
				start_y=0;
			}
			else 
			{
				start_x=getPositionX();
				start_y=-m_height*index;
			
			}

			float sminx,smaxx,sminy,smaxy;
			item->m_widget->getRSBoundSize2D(&sminx,&smaxx,&sminy,&smaxy);
			switch(alignh)
			{
			
				case E_AlignH::LEFT:
					item->m_widget->setPositionX(start_x-sminx);
					break;
				
				case E_AlignH::CENTER:
					//FS_TRACE_WARN("page pos(%f,%f)",start_x+m_width/2-(sminx+smaxx)/2,-smaxy);
					item->m_widget->setPositionX(start_x+m_width/2-(sminx+smaxx)/2);
					break;

				case E_AlignH::RIGHT:
					item->m_widget->setPositionX(start_y+m_width-smaxx);
					break;
			}

			switch(alignv)
			{
				case E_AlignV::TOP:
					item->m_widget->setPositionY(start_y-smaxy);
					break;

				case E_AlignV::CENTER:
					item->m_widget->setPositionY(start_y-m_height/2-(smaxy+sminy)/2);
					break;

				case E_AlignV::BOTTOM:
					item->m_widget->setPositionY(start_y-m_height-sminy);
					break;
			}
			item->m_widget->setSignalTSAEnabled(true);
		}



		UiWidget* getPageItem(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_widget;
		}

		PageViewContentPanel::PageViewItemInfo* getPageItemInfo(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item;
		}


		void setPageItemAlign(int index,E_AlignH h,E_AlignV v)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			item->m_alignH=h;
			item->m_alignV=v;
			adjustPageItemAlign(item->m_widget);
		}


		void setPageItemAlignH(int index,E_AlignH h)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			item->m_alignH=h;
			adjustPageItemAlign(item->m_widget);
		}

		E_AlignH getPageItemAlignH(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_alignH;
		}

		E_AlignV getPageItemAlignV(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_alignV;
		}

		void setPageItemAlignV(int index,E_AlignV v)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			item->m_alignV=v;
			adjustPageItemAlign(item->m_widget);
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
		bool hit2D(float x,float y) FS_OVERRIDE 
		{
			return true;
		}

		void layout()
		{
			int size=m_pageItem->size();
			for(int i=0;i<size;i++)
			{
				PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(i);
				adjustPageItemAlign(i,item->m_alignH,item->m_alignV);
			}
		}
};



/* PageView */
PageView* PageView::create()
{
	PageView* ret=new PageView(E_ScrollDirection::HORIZONTAL,0,0);
	return ret;
}


PageView* PageView::create(E_ScrollDirection mode,float width,float height)
{
	PageView* ret=new PageView(mode,width,height);
	return ret;
}


PageView* PageView::create(float width,float height)
{
	PageView* ret=new PageView(E_ScrollDirection::HORIZONTAL,width,height);
	return ret;
}

PageView::PageView()
{
	init(E_ScrollDirection::ALL,0,0);
}


PageView::PageView(E_ScrollDirection mode,float w,float h)
{
	init(mode,w,h);


}



void PageView::init(E_ScrollDirection mode ,float w,float h)
{
	m_contentPanel=PageViewContentPanel::create(mode,w,h);
	FS_NO_REF_DESTROY(m_contentPanel);
	Entity2D::addChild(m_contentPanel);
	onPageIndexChanged=nullptr;

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

	setSize(Vector2f(w,h));
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

	UiWidget::removeChild(m_contentPanel);
	FS_SAFE_DESTROY(m_contentPanel);
	FS_SAFE_DEC_REF(m_scrollEasing);
}





void PageView::setMode(E_ScrollDirection mode)
{
	m_contentPanel->setMode(mode);
}

E_ScrollDirection PageView::getMode()
{
	return m_contentPanel->getMode();
}

void PageView::addPage(UiWidget* widget)
{
	addPage(widget,E_AlignH::CENTER,E_AlignV::CENTER);
}


void PageView::addPage(UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
{
	int size=m_contentPanel->getPageItemNu();

	addPage(size,widget,alignh,alignv);
}

void PageView::addPage(int index,UiWidget* widget)
{
	addPage(index,widget,E_AlignH::CENTER,E_AlignV::CENTER);
}


void PageView::addPage(int index,UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
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
		widget->setParentWidget(this);
		adjustContentPanel();
	}
}

void PageView::setPageAlign(int index,E_AlignH alignh,E_AlignV alignv)
{
	if(index<0 || index>=m_contentPanel->getPageItemNu())
	{
		return;
	}

	m_contentPanel->setPageItemAlign(index,alignh,alignv);
}

E_AlignH PageView::getPageAlignH(int index)
{	
	if(index<0 || index>=m_contentPanel->getPageItemNu())
	{
		return E_AlignH::CENTER;
	}

	PageViewContentPanel::PageViewItemInfo* info=m_contentPanel->getPageItemInfo( index);

	return info->m_alignH;
}


E_AlignV PageView::getPageAlignV(int index)
{
	if(index<0 || index>=m_contentPanel->getPageItemNu())
	{
		return E_AlignV::CENTER;
	}

	PageViewContentPanel::PageViewItemInfo* info=m_contentPanel->getPageItemInfo( index);

	return info->m_alignV;

}


void PageView::setPageAlign(UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
{
	int index=m_contentPanel->getPageItemIndex(widget);

	setPageAlign(index,alignh,alignv);

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
	adjustContentPanel();
}


void PageView::clearPage()
{
	int size=m_contentPanel->getPageItemNu();
	for(int i=0;i<size;i++)
	{
		UiWidget* widget=m_contentPanel->getPageItem(i);
		widget->setParentWidget(NULL);
	}

	m_contentPanel->clearPageItem();
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
	if(index>=getPageNu())
	{
		index=getPageNu()-1;
	}

	if(index<0)
	{
		index=0;
	}



	if(!m_scrollFinished)
	{
		m_scrollFinished=true;
	}

	if(m_contentPanel->getMode()==E_ScrollDirection::HORIZONTAL)
	{
		m_xoffset=-index*m_size.x;
		m_contentPanel->setPosition(m_xoffset,m_yoffset,0);
		if(index!=m_currentPageIndex)
		{
			int old_index=m_currentPageIndex;
			m_currentPageIndex=index;
			FS_OBJECT_LAMBDA_CALL(this,onPageIndexChanged,pageIndexChanged,old_index,m_currentPageIndex);
		}
	}
	adjustContentPanel();
}


void PageView::setCurrentPageAlignH(E_AlignH h)
{
	if(m_currentPageIndex>=m_contentPanel->getPageItemNu())
	{
		return;
	}
	m_contentPanel->setPageItemAlignH(m_currentPageIndex,h);

}

E_AlignH PageView::getCurrentPageAlignH()
{
	if(m_currentPageIndex>=m_contentPanel->getPageItemNu())
	{
		return E_AlignH::CENTER;
	}
	return m_contentPanel->getPageItemAlignH(m_currentPageIndex);
}

void PageView::setCurrentPageAlignV(E_AlignV v)
{
	if(m_currentPageIndex>=m_contentPanel->getPageItemNu())
	{
		return;
	}
	m_contentPanel->setPageItemAlignV(m_currentPageIndex,v);
}


E_AlignV PageView::getCurrentPageAlignV()
{
	if(m_currentPageIndex>=m_contentPanel->getPageItemNu())
	{
		return E_AlignV::CENTER;
	}
	return m_contentPanel->getPageItemAlignV(m_currentPageIndex);
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
	if(m_currentPageIndex>=getPageNu())
	{
		return NULL;
	}
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
	E_ScrollDirection mode=m_contentPanel->getMode();

	if(!m_isDraged)
	{
		if(mode==E_ScrollDirection::HORIZONTAL)
		{
			if(Math::abs(diffx)>=m_touchTap)
			{
				m_isDraged=true;
				diffx=diffx>0? diffx-m_touchTap:diffx+m_touchTap;
			}
		}
		else if(mode==E_ScrollDirection::VERTICAL)
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
		if(mode==E_ScrollDirection::HORIZONTAL)
		{
			scrollXBy(diffx);
		}
		else if(mode==E_ScrollDirection::VERTICAL)
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
	E_ScrollDirection mode =m_contentPanel->getMode();
	if(mode==E_ScrollDirection::HORIZONTAL)
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


void PageView::childSizeChanged(UiWidget* widget)
{
	m_contentPanel->adjustPageItemAlign(widget);
}

void PageView::childAnchorChanged(UiWidget* widget)
{
	m_contentPanel->adjustPageItemAlign(widget);
}

void PageView::childTransformChanged(UiWidget* widget)
{
	m_contentPanel->adjustPageItemAlign(widget);
}





void PageView::setSize(const Vector2f& v)
{
	UiWidget::setSize(v);
	m_contentPanel->setSize(v.x,v.y);

	adjustContentPanel();
}

void PageView::setAnchor(const Vector2f& v)
{
	UiWidget::setAnchor(v);
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

	E_ScrollDirection mode=m_contentPanel->getMode();
	float left,right,bottom,top;

	getBoundSize2D(&left,&right,&bottom,&top);

	float x=0,y=0;

	if(mode==E_ScrollDirection::HORIZONTAL)
	{
		x=left+m_xoffset;
		y=top;
	}
	else if(mode==E_ScrollDirection::VERTICAL)
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
	E_ScrollDirection mode=m_contentPanel->getMode();

	if(mode==E_ScrollDirection::HORIZONTAL)
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

	E_ScrollDirection mode=m_contentPanel->getMode();


	if(mode==E_ScrollDirection::HORIZONTAL)
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


	E_ScrollDirection mode =m_contentPanel->getMode();

	if(mode == E_ScrollDirection::HORIZONTAL)
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
		if(mode==E_ScrollDirection::HORIZONTAL)
		{
			int index=(int)Math::floor(Math::abs(m_xoffset)/m_size.x+0.5f);
			if(m_currentPageIndex!=index)
			{
				int old_index=m_currentPageIndex;
				m_currentPageIndex=index;
				FS_OBJECT_LAMBDA_CALL(this,onPageIndexChanged,pageIndexChanged,old_index,m_currentPageIndex);
			}

		}
		else 
		{
			int index=(int)Math::floor(Math::abs(m_yoffset)/m_size.y+0.5f);
			if(m_currentPageIndex!=index)
			{
				int old_index=m_currentPageIndex;
				m_currentPageIndex=index;
				FS_OBJECT_LAMBDA_CALL(this,onPageIndexChanged,pageIndexChanged,old_index,m_currentPageIndex);
			}
		}
	}
}


void PageView::addChild(Entity* en) 
{
	FS_TRACE_WARN("Can't Add Child  To PageView,Use addPage");
}


void PageView::clearChild()
{
	clearPage();
}

void PageView::removeChild(Entity* en) 
{
	UiWidget* ui_widget=dynamic_cast<UiWidget*>(en);
	if(ui_widget)
	{
		removePage(ui_widget);
	}
	else 
	{
		FS_TRACE_WARN("Entity Is Not Manager By PageView");
	}
}





void PageView::pageIndexChanged(int old_index,int new_index)
{
}



/** Used For PageView FsClass */

static PageView* S_PageView_NewInstance(FsDict* attr)
{
	PageView* ret=PageView::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}




FS_CLASS_ATTR_SET_GET_FUNCTION(PageView,setCurrentPageIndex,getCurrentPageIndex,int);

FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(PageView,setMode,getMode,ScrollDirection);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(PageView,setCurrentPageAlignH,getCurrentPageAlignH,AlignH);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(PageView,setCurrentPageAlignV,getCurrentPageAlignV,AlignV);


static FsClass::FsAttributeDeclare S_PageView_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("mode",E_FsType::FT_CHARS,NULL,PageView_setMode,PageView_getMode),
	FS_CLASS_ATTR_DECLARE("currentPageIndex",E_FsType::FT_I_1,NULL,PageView_setCurrentPageIndex,PageView_getCurrentPageIndex),
	FS_CLASS_ATTR_DECLARE("currentPageAlignH",E_FsType::FT_CHARS,NULL,PageView_setCurrentPageAlignH,PageView_getCurrentPageAlignH),
	FS_CLASS_ATTR_DECLARE("currentPageAlignV",E_FsType::FT_CHARS,NULL,PageView_setCurrentPageAlignV,PageView_getCurrentPageAlignV),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0),

};

FS_CLASS_IMPLEMENT_WITH_BASE(PageView,UiWidget,S_PageView_NewInstance,S_PageView_Main_Attr);



NS_FS_END 



