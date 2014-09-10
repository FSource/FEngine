#include "FsUiWidget.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRender.h"
#include "stage/layer/FsLayer.h"
NS_FS_BEGIN
const char* UiWidget::className()
{
	return FS_UI_WIDGET_CLASS_NAME;
}


UiWidget* UiWidget::create(float width,float height)
{
	UiWidget* ret=new UiWidget();
	ret->setSize(width,height);
	return ret;
}



UiWidget::UiWidget()
{
	setTouchEnabled(true);
	setDispatchTouchEnabled(true);

	m_scissorEnabled=true;
	m_size.set(0.0f,0.0f);
	m_anchor.set(0.5f,0.5f);
	m_parentWidget=NULL;
}

UiWidget::~UiWidget()
{
	assert(m_parentWidget==NULL);
}

bool UiWidget::hit2D(float x,float y)
{
	Vector3 t=worldToLocal(Vector3(x,y,0));

	float diffx=t.x+m_anchor.x*m_size.x;
	float diffy=t.y+m_anchor.y*m_size.y;


	if ((diffx>=0) && (diffx<m_size.x))
	{
		if((diffy>=0)&&(diffy<m_size.y))
		{
			return true;
		}
	}

	return false;
}

void UiWidget::setSize(float width,float height)
{
	m_size.x=width;
	m_size.y=height;

	sizeChanged(width,height);

	if(m_parentWidget)
	{
		m_parentWidget->childSizeChanged(this,width,height);
	}
}

Vector2 UiWidget::getSize()
{
	return m_size;
}

float UiWidget::getWidth()
{
	return m_size.x;
}

float UiWidget::getHeight()
{
	return m_size.y;
}


void UiWidget::setScissorEnabled(bool enabled)
{
	m_scissorEnabled=enabled;
}

bool UiWidget::getScissorEnabled()
{
	return m_scissorEnabled;
}

void UiWidget::setAnchor(float x,float y)
{
	m_anchor.x=x;
	m_anchor.y=y;

	anchorChanged(x,y);
	if(m_parentWidget)
	{
		m_parentWidget->childAnchorChanged(this,x,y);
	}
}

Vector2 UiWidget::getAnchor()
{
	return m_anchor;
}


float UiWidget::getAnchorX()
{
	return m_anchor.x;
}

float UiWidget::getAnchorY()
{
	return m_anchor.y;
}


void UiWidget::setBgColor(const Color4f& c)
{
}

void UiWidget::setBgTexture(Texture2D* tex)
{
}

void UiWidget::setBgTexture(const char* filename)
{
}

void UiWidget::setBgEnabled(bool value)
{
}


void UiWidget::sizeChanged(float x,float y)
{
}

void UiWidget::anchorChanged(float x,float y)
{
}




void UiWidget::childSizeChanged(UiWidget* widget,float w,float h)
{

}

void UiWidget::childAnchorChanged(UiWidget* widget,float x,float y)
{

}

void UiWidget::setParentWidget(UiWidget* widget)
{
	m_parentWidget=widget;
}


UiWidget* UiWidget::getParentWidget()
{
	return m_parentWidget;
}

void UiWidget::draws(Render* r,bool updateMatrix)
{
	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	if(m_scissorEnabled&&m_layer!=NULL)
	{
		bool old_scissor_enabled=r->getScissorEnabled();
		Rect2D old_scissor_area=r->getScissorArea();
		
		float minx=-m_anchor.x*m_size.x;
		float maxx=minx+m_size.x;
		float miny=-m_anchor.y*m_size.y;
		float maxy=miny+m_size.y;

		Vector3 a(minx,miny,0);
		Vector3 b(maxx,miny,0);
		Vector3 c(maxx,maxy,0);
		Vector3 d(minx,maxy,0);

		Vector3 t[4];

		t[0]=m_worldMatrix.mulVector3(a);
		t[1]=m_worldMatrix.mulVector3(b);
		t[2]=m_worldMatrix.mulVector3(c);
		t[3]=m_worldMatrix.mulVector3(d);


		float tminx=t[0].x;
		float tmaxx=t[0].x;
		float tminy=t[0].y;
		float tmaxy=t[0].y;


		for (int i=1;i<4;i++)
		{
			if (tminx>t[i].x) { tminx=t[i].x ;}
			if(tmaxx<t[i].x) { tmaxx=t[i].x; }
		   	if(tminy>t[i].y) { tminy=t[i].y; }
			if(tmaxy<t[i].y) { tmaxy=t[i].y ;}
		}
		Matrix4 proj=m_layer->getProjectMatrix();
		Vector3 sminv=proj.mulVector3(Vector3(tminx,tminy,0));
		Vector3 smaxv=proj.mulVector3(Vector3(tmaxx,tmaxy,0));

		float sminx=(sminv.x+1.0f)/2;
		float sminy=(sminv.y+1.0f)/2;

		float smaxx=(smaxv.x+1.0f)/2;
		float smaxy=(smaxv.y+1.0f)/2;

		if(old_scissor_enabled)
		{
			if(sminx<old_scissor_area.x)
			{
				sminx=old_scissor_area.x;
			}
			if(sminy<old_scissor_area.y)
			{
				sminy=old_scissor_area.y;
			}

			if(smaxx>old_scissor_area.x+old_scissor_area.width)
			{
				smaxx=old_scissor_area.x+old_scissor_area.width;
			}

			if(smaxy>old_scissor_area.y+old_scissor_area.height)
			{
				smaxy=old_scissor_area.y+old_scissor_area.height;
			}
		}





		float w=smaxx-sminx;
		float h=smaxy-sminy;

		if(w<=0||h<=0||smaxx<=0||smaxy<=0||sminx>=1.0f||sminy>=1.0f)
		{
			//FS_TRACE_WARN("Not Draw %d",(int)this);
			return;
		}

		r->setScissorEnabled(true);

		r->setScissorArea(sminx,sminy,w<0?0:w,h<0?0:h);

		Entity::draws(r,updateMatrix);

		r->setScissorEnabled(old_scissor_enabled);
		r->setScissorArea(old_scissor_area);
	}
	else 
	{
		Entity::draws(r,updateMatrix);
	}

}

void UiWidget::getBoundSize2D(float* minx,float* maxx,float* miny,float* maxy)
{
	float top=(1.0f-m_anchor.y)*m_size.y;
	float  bottom=-m_anchor.y*m_size.y;

	float left=-m_anchor.x*m_size.x;
	float right=(1.0f-m_anchor.x)*m_size.x;

	*minx=left;
	*maxx=right;
	*miny=bottom;
	*maxy=top;
}




void UiWidget::getTRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy)
{
	float top,bottom,left,right;
	getRSBoundSize2D(&left,&right,&bottom,&top);

	*minx=left+m_translate.x;
	*maxx=right+m_translate.x;

	*miny=bottom+m_translate.y;
	*maxy=top+m_translate.y;
}


void UiWidget::getRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy)
{
	float top=(1.0f-m_anchor.y)*m_size.y;
	float  bottom=-m_anchor.y*m_size.y;

	float left=-m_anchor.x*m_size.x;
	float right=(1.0f-m_anchor.x)*m_size.x;

	if(Math::floatEqual(m_scale.x,1.0f) 
			&&Math::floatEqual(m_scale.y,1.0f)
			&&Math::floatEqual(m_rotate.x,0.0f)
			&&Math::floatEqual(m_rotate.y,0.0f)
			&&Math::floatEqual(m_rotate.z,0.0f))
	{
		*minx=left;
		*maxx=right;
		*miny=bottom;
		*maxy=top;
		return;
	}


	Matrix4 mat;
	mat.makeCompose(Vector3(0,0,0),m_rotate,FS_EULER_XYZ,m_scale);

	/* D-----C 
	 * |     |
	 * A-----B
	 */

	Vector3 vv[4]={
		Vector3(left,bottom,0),
		Vector3(right,bottom,0),
		Vector3(right,top,0),
		Vector3(left,top,0),
	};

	for(int i=0;i<4;i++)
	{
		vv[i]=mat.mulVector3(vv[i]);
	}

	float t_minx=vv[0].x;
	float t_maxx=vv[0].x;

	float t_miny=vv[0].y;
	float t_maxy=vv[0].y;

	for(int i=1;i<4;i++)
	{
		if(t_minx>vv[i].x) t_minx=vv[i].x;
		if(t_maxx<vv[i].x) t_maxx=vv[i].x;

		if(t_miny>vv[i].y) t_miny=vv[i].y;
		if(t_maxy<vv[i].y) t_maxy=vv[i].y;
	}

	*minx=t_minx;
	*maxx=t_maxx;
	*miny=t_miny;
	*maxy=t_maxy;
}



void UiWidget::draw(Render* r,bool updateMatrix)
{

}

void UiWidget::removeWidget(UiWidget* widget)
{
	FS_TRACE_WARN("Can't Call UiWidget::removeWidget");
}


void UiWidget::layout()
{
}



void UiWidget::detach()
{
	if(m_parentWidget)
	{
		m_parentWidget->removeWidget(this);
	}
	else
	{
		Entity::detach();
	}
}


NS_FS_END


