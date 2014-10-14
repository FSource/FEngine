#include <stdlib.h>
#include <string.h>
#include "support/data/FsIconv.h"
#include "support/data/FsUnicode.h"
#include "stage/entity/FsLabelTTF.h"
#include "graphics/FsImage2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsFontTTF.h"
#include "graphics/FsRender.h"
#include "support/util/FsArray.h"


#include "FsGlobal.h"
#include "mgr/FsProgramMgr.h"


NS_FS_BEGIN


const char*  LabelTTF::className()
{
	return FS_LABEL_TTF_CLASS_NAME;
}

LabelTTF* LabelTTF::create()
{
	LabelTTF* ret= new LabelTTF;
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}



LabelTTF* LabelTTF::create(const char* font,int size)
{
	LabelTTF* ret=new LabelTTF;
	if(!ret->init(font,size))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

LabelTTF* LabelTTF::create(const char* font,int size,const char* text)
{
	LabelTTF* ret=new LabelTTF;
	if(!ret->init(font,size,text))
	{
		delete ret;
		return NULL;
	}
	return ret;
}




LabelTTF::LabelTTF()
{
	m_dirty=true;
	m_text="";
	m_utf16text=NULL;
	m_fontName="";
	m_fontSize=20;

	m_textAlign=FS_TEXT_ALIGN_LEFT;

	m_boundWidth=0;
	m_boundHeight=0;

	m_anchorX=0.5;
	m_anchorY=0.5;

	m_lineGap=0;


	m_font=NULL;

	m_textWidth=0;
	m_textHeight=0;


	m_material=TextureMaterial::create();
	m_material->addRef();

	m_program=(Program*)Global::programMgr()->load(FS_PRE_SHADER_V4F_T2F);
	FS_SAFE_ADD_REF(m_program);

}


LabelTTF::~LabelTTF()
{
	destruct();
}

bool LabelTTF::init()
{
	return true;
}

bool LabelTTF::init(const char* font,int size)
{
	setFontName(font);
	setFontSize(size);
	return true;
}
bool LabelTTF::init(const char* font,int size,const char* text)
{
	setFontName(font);
	setFontSize(size);
	setString(text);
	return true;
}



void LabelTTF::destruct()
{
	FS_SAFE_DELETES(m_utf16text);
	FS_SAFE_DEC_REF(m_font);

	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_program);
}


void LabelTTF::setString(const char* str)
{
	FS_TRACE_WARN_ON(str==NULL,"NULL String");
	if(m_text==str)
	{
		return;
	}
	m_text=std::string(str);

	FS_SAFE_DELETES(m_utf16text);
	m_utf16text=FsIconv_UTF8_to_UNICODE(str);
	m_dirty=true;
}

const char* LabelTTF::getString()
{
	return m_text.c_str();
}

void LabelTTF::setFontName(const char* font_name)
{
	if(m_fontName==font_name)
	{
		return;
	}


	FontTTF* font=(FontTTF*)Global::fontTTFMgr()->load(font_name);
	FS_TRACE_WARN_ON(font==NULL,"Load FontName %s Failed",font_name);

	FS_SAFE_ASSIGN(m_font,font);
	m_dirty=true;
}

const char* LabelTTF::getFontName()
{
	return m_fontName.c_str();
}

void LabelTTF::setFontSize(int size)
{
	if(m_fontSize==size)
	{
		return;
	}
	m_fontSize=size;
	m_dirty=true;
}


int LabelTTF::getFontSize()
{
	return m_fontSize;
}


void LabelTTF::setTextAlign(int align)
{
	if( m_textAlign==align)
	{
		return;
	}

	m_textAlign=align;

	if(!m_dirty)
	{
		m_typoPage.setTextAlign(align);
	}
}


int LabelTTF::getTextAlign()
{
	return m_textAlign;
}

void LabelTTF::setBoundSize(float width,float height)
{
	if(m_boundWidth==width&&m_boundHeight==height)
	{
		return;
	}
	m_boundWidth=width;
	m_boundHeight=height;
	m_dirty=true;
}


void LabelTTF::getBoundSize(float* width,float* height)
{
	*width=m_boundWidth;
	*height=m_boundHeight;
}

float LabelTTF::getTextWidth()
{
	if(m_dirty)
	{
		typoText();
		m_dirty=false;
	}
	return m_textWidth;
}

float LabelTTF::getTextHeight()
{
	if(m_dirty)
	{
		typoText();
		m_dirty=false;
	}
	return m_textHeight;
}

void LabelTTF::getTextSize(float* width,float* height)
{
	if(m_dirty)
	{
		typoText();
		m_dirty=false;
	}

	*width=m_textWidth;
	*height=m_textHeight;
}


void LabelTTF::setLineGap(float gap)
{
	m_lineGap=gap;
}
float LabelTTF::getLineGap()
{
	return m_lineGap;
}


void LabelTTF::setAnchor(float x,float y)
{
	m_anchorX=x;
	m_anchorY=y;
	if(!m_dirty)
	{
		m_typoPage.setAnchor(x,y);
	}
}

void LabelTTF::getAnchor(float* x,float* y)
{
	*x=m_anchorX;
	*y=m_anchorY;
}



void LabelTTF::draw(RenderDevice* render,bool updateMatrix)
{
	if(!m_font||!m_utf16text||!m_material||!m_program)
	{
		return; 
	}

	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	if(m_dirty)
	{
		typoText();
		m_dirty=false;
	}

	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);

	render->setProgram(m_program);
	m_material->configRenderDevice(render);

	render->disableAllAttrArray();

	int pos_loc=render->getCacheAttrLocation(FS_ATTR_V4F_LOC,FS_ATTR_V4F_NAME);
	int tex_loc=render->getCacheAttrLocation(FS_ATTR_T2F_LOC,FS_ATTR_T2F_NAME);


	static float t[8]={
		0.0f,1.0f,
		1.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,
	};
	render->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,4,0,t);

	int typo_lines=m_typoPage.getTypoLineNu();
	for(int i=0;i<typo_lines;i++)
	{
		TypoLine<TypoText>* line=m_typoPage.getTypoLine(i);
		int text_nu=line->getTextNu();
		for(int j=0;j<text_nu;j++)
		{
			TypoText*  t=line->getText(j);
			Texture2D* t2d=((GlyphTTF*)(t->m_glyph))->getTexture();
			if(t2d)
			{
				render->bindTexture(t2d,0);
				render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,&t->m_vertices[0]);
				render->drawArray(RenderDevice::TRIANGLE_STRIP,0,4);
			}
		}
	}
	render->popMatrix();
}


bool LabelTTF::hit2D(float x,float y)
{
	if(m_dirty) /* check dirty */
	{
		typoText();
		m_dirty=false;
	}

	updateWorldMatrix();
	Vector3 v=worldToLocal(Vector3(x,y,0));

	float diffx=v.x+m_anchorX*m_textWidth;
	float diffy=v.y+m_anchorY*m_textHeight;

	if(diffx>=0 && diffx <m_textWidth)
	{
		if(diffy>=0 && diffy <m_textHeight)
		{
			return true;
		}
	}
	return false;
}

void LabelTTF::typoText()
{

	if(!m_font)
	{
		m_textWidth=0;
		m_textHeight=0;
		return;
	}

	if(m_utf16text)
	{
		delete[] m_utf16text;
		m_utf16text=NULL;
	}

	m_utf16text=FsUtf8_ToUtf16(m_text.c_str());

	uint16_t* p_text=m_utf16text;

	m_typoPage.typoBegin(m_boundWidth,m_boundHeight,0,m_lineGap);

	while((!m_typoPage.done())&&(*p_text))
	{
		GlyphTTF* g=m_font->getGlyphTTF(*p_text,m_fontSize);
		m_typoPage.pushText(g);

		p_text++;
	}

	m_typoPage.typoEnd();

	m_typoPage.setTextAlign(m_textAlign);
	m_typoPage.setAnchor(m_anchorX,m_anchorY);

	m_textWidth=m_typoPage.getTextWidth();
	m_textHeight=m_typoPage.getTextHeight();
}

NS_FS_END

















