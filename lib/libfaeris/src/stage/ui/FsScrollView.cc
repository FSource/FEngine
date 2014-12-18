
#include "FsScrollView.h"

NS_FS_BEGIN

const char* ScrollView::className()
{
	return "ScrollView";
}



ScrollView::ScrollView(float width,float height)
{
	m_contentWidget=NULL;

	setSize(Vector2f(width,height));
	setScissorEnabled(true);

}

ScrollView::~ScrollView()
{
	if(m_contentWidget)
	{
		m_contentWidget->setParentWidget(NULL);
	}
}


ScrollView* ScrollView::create(float width,float height)
{
	ScrollView* ret=new ScrollView(width,height);
	return ret; 
}


void ScrollView::setContentWidget(UiWidget* widget)
{
	if(widget->getParentWidget()==this)
	{
		FS_TRACE_WARN("Widget Already Add To ScrollView");
		return;
	}

	if(widget->getParentWidget())
	{
		FS_TRACE_WARN("Widget Already Add to Other Widget");
		return;
	}

	if(m_contentWidget)
	{
		m_contentWidget->setParentWidget(NULL);
		removeChild(m_contentWidget);
		m_contentWidget=NULL;
		m_contentHeight=0;
		m_contentWidth=0;
	}


	if(widget)
	{
		FS_SAFE_ADD_REF(widget);
		m_contentWidget=widget;
		addChild(widget);

		widget->setParentWidget(this);
		float minx,maxx,miny,maxy;
		widget->getRSBoundSize2D(&minx,&maxx,&miny,&maxy);

		m_contentWidth=maxx-minx;
		m_contentHeight=maxy-miny;
	}


	adjustScrollArea();

	setScrollPercent(0,0);
}

UiWidget* ScrollView::getContentWidget()
{
	return m_contentWidget;
}


void ScrollView::scrollChange(float x,float y)
{
	if(!m_contentWidget)
	{
		return ;
	}

	float minx,maxx,miny,maxy;

	m_contentWidget->getRSBoundSize2D(&minx,&maxx,&miny,&maxy);


	float middlex=(minx+maxx)/2;
	float middley=(miny+maxy)/2;


	switch(m_alignv)
	{
		case ALIGN_TOP:
			m_contentWidget->setPositionY(y-maxy);
			break;

		case ALIGN_CENTER:
			m_contentWidget->setPositionY(y-middley);
			break;

		case ALIGN_BOTTOM:
			m_contentWidget->setPositionY(y-miny);
			break;
		default:
			FS_TRACE_WARN("Unkown Align For Vetical");
	}

	switch(m_alignh)
	{
		case ALIGN_LEFT:
			m_contentWidget->setPositionX(x-minx);
			break;

		case ALIGN_CENTER:
			m_contentWidget->setPositionX(x-middlex);
			break;

		case ALIGN_RIGHT:
			m_contentWidget->setPositionX(x-maxx);
			break;

		default:
			FS_TRACE_WARN("Unkown Align For Horizontal");
	}

	//FS_TRACE_WARN("%f,%f",x,y);

}








NS_FS_END









