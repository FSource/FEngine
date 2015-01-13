#include "FsProcessBar.h"
#include "FsGlobal.h"
#include "graphics/FsTexture2D.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"




NS_FS_BEGIN


ProcessBar* ProcessBar::create()
{
	ProcessBar* ret=new ProcessBar();
	return ret;
}

ProcessBar* ProcessBar::create(const char* bg,const char* fg)
{
	ProcessBar* ret=new ProcessBar();
	ret->initWithTexture(bg,fg);
	return ret;
}

ProcessBar* ProcessBar::create(Texture2D* bg,Texture2D* fg)
{
	ProcessBar* ret=new ProcessBar();
	ret->initWithTexture(bg,fg);
	return ret;
}


void ProcessBar::setPercent(float value)
{
	m_percent=Math::clampf(value,0.0f,1.0f);
}

float ProcessBar::getPercent()
{
	return m_percent;
}


void ProcessBar::setDirection(E_AxisDirection dr)
{
	m_direction=dr;
}
E_AxisDirection ProcessBar::getDirection()
{
	return m_direction;
}

void ProcessBar::setReverseDirection(bool value)
{
	m_reverseDirection=value;
}

bool ProcessBar::getReverseDirection()
{
	return m_reverseDirection;
}



void ProcessBar::setBackgroundTexture(const char* filename)
{
	Texture2D* tex=NULL;
	if(filename)
	{
		tex=Global::textureMgr()->loadTexture(filename);
		FS_TRACE_WARN_ON(tex==NULL,"Load Background Texture(%s) For ProcessBar Failed",filename);
	}
	setBackgroundTexture(tex);

}

void ProcessBar::setBackgroundTexture(Texture2D* tex)
{
	FS_SAFE_ASSIGN(m_backgroundTexture,tex);
}

Texture2D* ProcessBar::getBackgroundTexture()
{
	return m_backgroundTexture;
}


void ProcessBar::setForegroundTexture(const char* filename)
{
	Texture2D* tex=NULL ;
	if(filename)
	{
		Global::textureMgr()->loadTexture(filename);
		FS_TRACE_WARN_ON(tex==NULL,"Load Foreground Texture(%s) For ProcessBar Faild",filename);
	}
	setForegroundTexture(tex);
}

void ProcessBar::setForegroundTexture(Texture2D* tex)
{
	FS_SAFE_ASSIGN(m_foregroundTexture,tex);
}

Texture2D* ProcessBar::getForegroundTexture()
{
	return m_foregroundTexture;
}


void ProcessBar::draw(RenderDevice* rd,bool update_matrix) 
{
	//UiWidget::draw(rd,update_matrix);

	Program*  prog=getProgram(NULL);
	if(!prog)
	{
		return;
	}
	if(!m_backgroundTexture&&!m_foregroundTexture)
	{
		return;
	}


	if(update_matrix)
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

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);

	if(m_backgroundTexture)
	{
		rd->bindTexture(m_backgroundTexture,0);

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

	if(m_foregroundTexture)
	{
		rd->bindTexture(m_foregroundTexture,0);

		Vector2f vertices[4];
		TexCoord2 tex_coord[4];

		switch(m_direction)
		{
			case E_AxisDirection::HORIZONTAL:
				{
					if(m_reverseDirection)
					{
						left=right+(left-right)*m_percent;

						vertices[0]=Vector2f(left,bottom);
						vertices[1]=Vector2f(right,bottom);
						vertices[2]=Vector2f(left,top);
						vertices[3]=Vector2f(right,top);

						tex_coord[0]=TexCoord2(1.0f-m_percent,1.0f);
						tex_coord[1]=TexCoord2(1.0f,1.0f);
						tex_coord[2]=TexCoord2(1.0f-m_percent,0.0f);
						tex_coord[3]=TexCoord2(1.0f,0.0f);
					}
					else 
					{
						right=left+(right-left)*m_percent;

						vertices[0]=Vector2f(left,bottom);
						vertices[1]=Vector2f(right,bottom);
						vertices[2]=Vector2f(left,top);
						vertices[3]=Vector2f(right,top);

						tex_coord[0]=TexCoord2(0.0,1.0);
						tex_coord[1]=TexCoord2(m_percent,1.0f);
						tex_coord[2]=TexCoord2(0.0f,0.0f);
						tex_coord[3]=TexCoord2(m_percent,0.0f);
					}
				}
				break;

			case E_AxisDirection::VERTICAL:
				{
					if(m_reverseDirection)
					{
						bottom=top+(bottom-top)*m_percent;

						vertices[0]=Vector2f(left,bottom);
						vertices[1]=Vector2f(right,bottom);
						vertices[2]=Vector2f(left,top);
						vertices[3]=Vector2f(right,top);

						tex_coord[0]=TexCoord2(0.0f,m_percent);
						tex_coord[1]=TexCoord2(1.0f,m_percent);
						tex_coord[2]=TexCoord2(0.0f,0.0f);
						tex_coord[3]=TexCoord2(1.0f,0.0f);
					}
					else 
					{
						top=bottom+(top-bottom)*m_percent;

						vertices[0]=Vector2f(left,bottom);
						vertices[1]=Vector2f(right,bottom);
						vertices[2]=Vector2f(left,top);
						vertices[3]=Vector2f(right,top);

						tex_coord[0]=TexCoord2(0.0f,1.0f);
						tex_coord[1]=TexCoord2(1.0f,1.0f);
						tex_coord[2]=TexCoord2(0.0f,1-m_percent);
						tex_coord[3]=TexCoord2(1.0f,1-m_percent);
					}
				}
				break;
		}


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
}


ProcessBar::ProcessBar()
{
	m_backgroundTexture=NULL;
	m_foregroundTexture=NULL;
	m_percent=1.0;
	m_direction=E_AxisDirection::HORIZONTAL;
	m_reverseDirection=false;


	static ProgramSource* S_texProgramSource=NULL;
	if(S_texProgramSource==NULL)
	{
		S_texProgramSource=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F_T2F);
	}
	setProgramSource(S_texProgramSource);

}

ProcessBar::~ProcessBar()
{
	FS_SAFE_DEC_REF(m_backgroundTexture);
	FS_SAFE_DEC_REF(m_foregroundTexture);
}

void ProcessBar::initWithTexture(const char* bg,const char* fg)
{
	Texture2D* tex_bg=NULL;
	if(bg)
	{
		tex_bg=Global::textureMgr()->loadTexture(bg);
	}

	Texture2D* tex_fg=NULL;
	if(fg)
	{
		tex_fg=Global::textureMgr()->loadTexture(fg);
	}
	initWithTexture(tex_bg,tex_fg);
}

void ProcessBar::initWithTexture(Texture2D* bg,Texture2D* fg)
{
	float width=0;
	float height=0;

	if(bg)
	{
		width=(float)bg->getWidth();
		height=(float)bg->getHeight();
	}

	if(fg)
	{
		if(width<(float)fg->getWidth())
		{
			width=(float)fg->getWidth();
		}

		if(height<(float)fg->getHeight())
		{
			height=(float)fg->getHeight();
		}

	}
	setSize(width,height);

	FS_SAFE_ASSIGN(m_backgroundTexture,bg);
	FS_SAFE_ASSIGN(m_foregroundTexture,fg);

}















NS_FS_END 



