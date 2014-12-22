#include "FsUiWidget.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRenderDevice.h"
#include "stage/layer/FsLayer.h"
#include "FsGlobal.h"
#include "math/FsTexCoord2.h"
#include "graphics/shader/FsProgramSource.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"
#include "FsClass.h"

NS_FS_BEGIN

UiWidget* UiWidget::create(float width,float height)
{
	UiWidget* ret=new UiWidget();
	ret->setSize(Vector2(width,height));
	return ret;
}

UiWidget* UiWidget::create()
{
	UiWidget* ret=new UiWidget();
	return ret;
}



UiWidget::UiWidget()
{
	setTouchEnabled(true);
	setDispatchTouchEnabled(true);

	m_scissorEnabled=true;
	m_parentWidget=NULL;

	setBgTexture((Texture2D*)NULL);
	m_bgEnabled=false;
	m_listenChildTSAEnabled=true;
	m_signalParentTSAEnabled=true;
}


UiWidget::~UiWidget()
{
	assert(m_parentWidget==NULL);
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		UiWidget* ch=dynamic_cast<UiWidget*>( m_chirdren->get(i));
		if(ch)
		{
			assert(ch->getParentWidget()==this);
			ch->setParentWidget(NULL);
		}
	}
}



void UiWidget::setSize(const Vector2& v)
{
	Entity2D::setSize(v);

	if(m_signalParentTSAEnabled&&m_parentWidget&&m_parentWidget->m_listenChildTSAEnabled)
	{
		m_parentWidget->childSizeChanged(this);
	}
}
void UiWidget::setAnchor(const Vector2& v)
{
	Entity2D::setAnchor(v);
	if(m_signalParentTSAEnabled&&m_parentWidget&&m_parentWidget->m_listenChildTSAEnabled)
	{
		m_parentWidget->childAnchorChanged(this);
	}
}

void UiWidget::setPosition(const Vector3f&  v)
{
	Entity2D::setPosition(v);
	if(m_signalParentTSAEnabled&&m_parentWidget&&m_parentWidget->m_listenChildTSAEnabled)
	{
		m_parentWidget->childTransformChanged(this);
	}
}

void UiWidget::setScale(const Vector3f& v) 
{
	Entity2D::setScale(v);
	if(m_signalParentTSAEnabled&&m_parentWidget&&m_parentWidget->m_listenChildTSAEnabled)
	{
		m_parentWidget->childTransformChanged(this);
	}
}

void UiWidget::setRotate(const Vector3f& v)
{
	Entity2D::setScale(v);
	if(m_signalParentTSAEnabled&&m_parentWidget&&m_parentWidget->m_listenChildTSAEnabled)
	{
		m_parentWidget->childTransformChanged(this);
	}
}



void UiWidget::setScissorEnabled(bool enabled)
{
	m_scissorEnabled=enabled;
}

bool UiWidget::getScissorEnabled()
{
	return m_scissorEnabled;
}


void UiWidget::setBgColor(const Color4f& c)
{
	setColor(c);
}

Color4f UiWidget::getBgColor()
{
	return getColor();
}


void UiWidget::setBgTexture(Texture2D* tex)
{
	m_material->setColorMap(tex);
	if(tex)
	{
		static ProgramSource* S_texProgramSource=NULL;
		if(S_texProgramSource==NULL)
		{
			S_texProgramSource=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F_T2F);
		}
		m_material->setProgramSource(S_texProgramSource);
	}
	else 
	{
		static ProgramSource* S_colorProgramSource=NULL;
		if(S_colorProgramSource==NULL)
		{
			S_colorProgramSource=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F);
		}
		m_material->setProgramSource(S_colorProgramSource);
	}
}

void UiWidget::setBgTexture(const char* filename)
{
	if(!filename)
	{
		setBgTexture((Texture2D*)NULL);
		return;
	}

	Texture2D* tex=(Texture2D*)Global::textureMgr()->load(filename);
	setBgTexture(tex);
}

void UiWidget::setBgEnabled(bool value)
{
	m_bgEnabled=true;
}






void UiWidget::childSizeChanged(UiWidget* widget)
{

}

void UiWidget::childAnchorChanged(UiWidget* widget)
{

}

void UiWidget::childTransformChanged(UiWidget* widget)
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


void UiWidget::draws(RenderDevice* r,bool updateMatrix)
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

	Vector3 t=getPosition();
	*minx=left+t.x;
	*maxx=right+t.x;

	*miny=bottom+t.y;
	*maxy=top+t.y;
}


void UiWidget::getRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy)
{
	float top=(1.0f-m_anchor.y)*m_size.y;
	float  bottom=-m_anchor.y*m_size.y;

	float left=-m_anchor.x*m_size.x;
	float right=(1.0f-m_anchor.x)*m_size.x;
	Vector3 s=getScale();
	Vector3 r=getRotate();


	if(Math::floatEqual(s.x,1.0f) 
			&&Math::floatEqual(s.y,1.0f)
			&&Math::floatEqual(r.x,0.0f)
			&&Math::floatEqual(r.y,0.0f)
			&&Math::floatEqual(r.z,0.0f))
	{
		*minx=left;
		*maxx=right;
		*miny=bottom;
		*maxy=top;
		return;
	}


	Matrix4 mat;
	mat.makeCompose(Vector3(0,0,0),r,E_EulerOrientType::XYZ,s);

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



void UiWidget::draw(RenderDevice* rd,bool updateMatrix)
{
	if(!m_bgEnabled) 
	{
		return;
	}

	Program* prog=m_material->getProgram(NULL);
	if(!prog)
	{
		return;
	}

	if(updateMatrix)
	{
		updateWorldMatrix();
	}


	rd->setWorldMatrix(&m_worldMatrix);
	rd->setProgram(prog);
	m_material->configRenderDevice(rd);

	rd->disableAllAttrArray();

	float top=(1.0f-m_anchor.y)*m_size.y;
	float  bottom=-m_anchor.y*m_size.y;

	float left=-m_anchor.x*m_size.x;
	float right=(1.0f-m_anchor.x)*m_size.x;
	

	Vector2f vertices[4]={
		Vector2f(left,bottom),
		Vector2f(right,bottom),
		Vector2f(left,top),
		Vector2f(right,top),
	};

	static TexCoord2 tex_coord[4]={
		TexCoord2(0.0f,1.0f),
		TexCoord2(1.0f,1.0f),
		TexCoord2(0.0f,0.0f),
		TexCoord2(1.0f,0.0f),
	};

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);
	
	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,4,0,&vertices[0]);
	}
	if(map_u)
	{
		rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,4,0,&tex_coord[0]);
	}

	rd->drawArray(E_DrawMode::TRIANGLE_STRIP,0,4);

}



void UiWidget::addChild(Entity* en)
{
	Entity2D::addChild(en);
	UiWidget* ui_child=dynamic_cast<UiWidget*>(en);
	if(ui_child)
	{
		ui_child->setParentWidget(this);
	}
}

void UiWidget::removeChild(Entity* en)
{
	Entity2D::removeChild(en);

	UiWidget* ui_child=dynamic_cast<UiWidget*>(en);
	if(ui_child)
	{
		if(ui_child->m_parentWidget==this)
		{
			ui_child->setParentWidget(NULL);
		}
	}
}

void UiWidget::detach()
{
	if(m_parentWidget)
	{
		m_parentWidget->removeChild(this);
	}
	else 
	{
		Entity2D::detach();
	}
}




/*** User For UiWidget FsClass Attr */
static UiWidget* UiWidget_NewInstace(FsDict* attr)
{
	UiWidget* ret=UiWidget::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}


FS_CLASS_ATTR_SET_GET_FUNCTION(UiWidget,setBgColor,getBgColor,Color4f);
FS_CLASS_ATTR_SET_CHARS_FUNCTION(UiWidget,setBgTexture);
FS_CLASS_ATTR_SET_GET_FUNCTION(UiWidget,setScissorEnabled,getScissorEnabled,bool);


static FsClass::FsAttributeDeclare S_UiWidget_Main_Attr[]=
{
	FS_CLASS_ATTR_DECLARE("bgColor",FsType::FT_COLOR_4,NULL,UiWidget_setBgColor,UiWidget_getBgColor),
	FS_CLASS_ATTR_DECLARE("bgTextureUrl",FsType::FT_CHARS,NULL,UiWidget_setBgTexture,0),
	FS_CLASS_ATTR_DECLARE("scissorEnabled",FsType::FT_B_1,NULL,UiWidget_setScissorEnabled,UiWidget_getScissorEnabled),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(UiWidget,Entity2D,UiWidget_NewInstace,S_UiWidget_Main_Attr);





NS_FS_END



