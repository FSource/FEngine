#include "FsDynamicView.h"
#include "support/util/FsDict.h"


NS_FS_BEGIN

DynamicView* DynamicView::create(float width,float height)
{
	DynamicView* ret=new DynamicView(width,height);
	return ret;
}

const char* DynamicView::className()
{
	return FS_DYNAMIC_VIEW_CLASS_NAME;
}

DynamicView::DynamicView(float width,float height)
{
	m_views=FsDict::create();
	FS_NO_REF_DESTROY(m_views);

	m_currentView=NULL;

	m_marginLeft=0;
	m_marginRight=0;
	m_marginTop=0;
	m_marginBottom=0;

	setSize(width,height);

}


DynamicView::~DynamicView()
{

	FsDict::Iterator* iter=m_views->takeIterator();
	while(!iter->done())
	{
		ViewInfo* info=(ViewInfo*)iter->getValue();
		info->m_widget->setParentWidget(NULL);
		iter->next();
	}
	delete iter;

	FS_SAFE_DESTROY(m_views);
}

void DynamicView::setMargin(float l,float r,float t,float b)
{
	m_marginLeft=l;
	m_marginRight=r;
	m_marginTop=t;
	m_marginBottom=b;

	adjustCurrentView();	
}

void DynamicView::getMargin(float* l,float* r,float* t,float* b) const
{
	*l=m_marginLeft;
	*r=m_marginRight;
	*t=m_marginTop;
	*b=m_marginBottom;
}



void DynamicView::setMarginLeft(float l)
{
	m_marginLeft=l;
	adjustCurrentView();
}

float DynamicView::getMarginLeft() const
{
	return m_marginLeft;
}


void DynamicView::setMarginRight(float r)
{
	m_marginRight=r;
	adjustCurrentView();
}

float DynamicView::getMarginRight() const
{
	return m_marginRight;
}



void DynamicView::setMarginTop(float t)
{
	m_marginTop=t;
	adjustCurrentView();
}

float DynamicView::getMarginTop() const 
{
	return m_marginTop;
}



void DynamicView::setMarginBottom(float b)
{
	m_marginBottom=b;
	adjustCurrentView();
}

float DynamicView::getMarginBottom() const
{
	return m_marginBottom;
}


void DynamicView::addView(const char* name,UiWidget* view)
{
	addView(name,view,ALIGN_CENTER,ALIGN_CENTER);
}

void DynamicView::addView(const char* name,UiWidget* view,int alignh,int alignv)
{
	ViewInfo* info=ViewInfo::create(name,view,alignh,alignv);

	if(m_currentView)
	{
		if(info->m_name->equal(m_currentView->m_name))
		{
			removeViewInfo(m_currentView);
			addViewInfo(info);
			setCurrentViewInfo(info);
		}
	}
	else 
	{
		addViewInfo(info);
	}

}

void DynamicView::removeView(const char* name)
{
	ViewInfo* info=getViewInfo(name);
	assert(info);
	removeViewInfo(info);
}

void DynamicView::removeView(UiWidget* view)
{
	ViewInfo* info=getViewInfo(view);
	assert(info);
	removeViewInfo(info);
}

UiWidget* DynamicView::getCurrentView()
{
	if(m_currentView)
	{
		return m_currentView->m_widget;
	}

	return NULL;
}

const char* DynamicView::getCurrentViewName()
{
	if(m_currentView)
	{
		return m_currentView->m_name->cstr();
	}
	return NULL;
}

void DynamicView::setCurrentView(const char* name)
{
	ViewInfo* info=getViewInfo(name);
	setCurrentViewInfo(info);


}

void DynamicView::setCurrentView(UiWidget* view)
{
	ViewInfo* info=getViewInfo(view);
	setCurrentViewInfo(info);
}

void DynamicView::setViewAlign(UiWidget* view,int alignh,int alignv)
{
	ViewInfo* info=getViewInfo(view);
	assert(info);

	info->m_alignh=alignh;
	info->m_alignv=alignv;

	if(info==m_currentView)
	{
		adjustCurrentView();
	}

}

void DynamicView::setCurrentViewAlign(int alignh,int alignv)
{
	if(!m_currentView)
	{
		return;
	}
	m_currentView->m_alignh=alignh;
	m_currentView->m_alignv=alignv;
	adjustCurrentView();
}


void DynamicView::sizeChanged(float w,float h)
{
	adjustCurrentView();
}

void DynamicView::anchorChanged(float x,float y)
{
	adjustCurrentView();
}

void DynamicView::childSizeChanged(UiWidget* child,float w,float h)
{

	adjustCurrentView();
}
void DynamicView::childAnchorChanged(UiWidget* child,float w,float h)
{
	adjustCurrentView();
}



void DynamicView::currentViewChanged(UiWidget* old_view,UiWidget* new_view)
{
}

void DynamicView::layout()
{
	adjustCurrentView();
}

void DynamicView::removeWidget(UiWidget* widget)
{
	removeView(widget);
}


DynamicView::ViewInfo* DynamicView::getViewInfo(const char* name)
{
	if(name==NULL)
	{
		return NULL;
	}

	ViewInfo* info=(ViewInfo*)m_views->lookup(name);

	return info;
}

DynamicView::ViewInfo* DynamicView::getViewInfo(UiWidget* view)
{
	if(view==NULL)
	{
		return NULL;
	}
	ViewInfo* ret=NULL;


	FsDict::Iterator* iter=m_views->takeIterator();

	while(!iter->done())
	{
		ViewInfo* info=(ViewInfo*)iter->getValue();
		if(info->m_widget==view)
		{
			ret=info;
			break;
		}
		iter->next();
	}
	delete iter;


	return ret;
}

void DynamicView::removeViewInfo(ViewInfo* info)
{
	if(m_currentView==info)
	{
		setCurrentViewInfo(NULL);
	}

	info->m_widget->setParentWidget(NULL);
	removeChild(info->m_widget);

	m_views->remove(info->m_name);
	
}

void DynamicView::addViewInfo(ViewInfo* info)
{
	info->m_widget->setParentWidget(this);
	addChild(info->m_widget);

	info->m_widget->setVisibles(false);
	m_views->insert(info->m_name,info);

}


void DynamicView::setCurrentViewInfo(ViewInfo* info)
{
	UiWidget* old_view=NULL;
	UiWidget* new_view=NULL;

	if(m_currentView==info)
	{
		return;
	}

	if(m_currentView)
	{
		m_currentView->m_widget->setVisibles(false);
		old_view=m_currentView->m_widget;

	}

	if(info)
	{
		info->m_widget->setVisibles(true);
		new_view=info->m_widget;
	}

	m_currentView=info;
	adjustCurrentView();
	currentViewChanged(old_view,new_view);
}


void DynamicView::adjustCurrentView()
{
	if(!m_currentView)
	{
		return;
	}

	float sminx,smaxx,sminy,smaxy;
	float cminx,cmaxx,cminy,cmaxy;


	getBoundSize2D(&sminx,&smaxx,&sminy,&smaxy);
	m_currentView->m_widget->getBoundSize2D(&cminx,&cmaxx,&cminy,&cmaxy);


	switch(m_currentView->m_alignh)
	{
		case ALIGN_LEFT:
			m_currentView->m_widget->setPositionX(sminx+m_marginLeft-cminx);
			break;

		case ALIGN_RIGHT:
			m_currentView->m_widget->setPositionX(smaxx-m_marginRight-cmaxx);
			break;

		case ALIGN_CENTER:
			float smiddle=(sminx+m_marginLeft+smaxx-m_marginRight)/2.0f;
			float cmiddle=(cminx+cmaxx)/2.0f;
			m_currentView->m_widget->setPositionX(smiddle-cmiddle);
			break;
	}

	switch(m_currentView->m_alignv)
	{
		case ALIGN_TOP:
			m_currentView->m_widget->setPositionY(smaxy-m_marginTop-cmaxy);
			break;

		case ALIGN_BOTTOM:
			m_currentView->m_widget->setPositionY(sminy+m_marginBottom-cminy);
			break;

		case ALIGN_CENTER:
			float smiddle=(sminy+m_marginBottom+smaxy-m_marginTop)/2.0f;
			float cmiddle=(cminy+cmaxy)/2.0f;
			m_currentView->m_widget->setPositionY(smiddle-cmiddle);
			break;
	}

}






NS_FS_END




