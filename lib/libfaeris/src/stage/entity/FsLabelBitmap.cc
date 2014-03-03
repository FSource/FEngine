#include "stage/entity/FsLabelBitmap.h"
#include "graphics/FsFontBitmap.h"
#include "graphics/FsTexture2D.h"
#include "graphics/material/FsMat_V4F_T2F.h"
#include "support/data/FsUnicode.h"
#include "support/data/FsIconv.h"
NS_FS_BEGIN

const char* LabelBitmap::className()
{
	return FS_LABEL_BITMAP_CLASS_NAME;
}


LabelBitmap* LabelBitmap::create()
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

LabelBitmap* LabelBitmap::create(const char* font)
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	ret->setFontName(font);
	return ret;
}

LabelBitmap* LabelBitmap::create(const char* font,const char* text)
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	ret->setFontName(font);
	ret->setString(text);
	return ret;
}

void LabelBitmap::setFontName(const char* name)
{
	FontBitmap* font=(FontBitmap*)Global::FontBitmapMgr()->load(name);
	FS_TRACE_WARN_ON(font==NULL,"Can't Load FontBitmap(%s)",name);
	m_dirty=true;

	m_fontName=name;
	FS_SAFE_ASSIGN(m_font,font);
}

const char* LabelBitmap::getFontName()
{
	return m_fontName.c_str();
}


void LabelBitmap::setFontSize(float size)
{
	if(m_fontSize==size)
	{
		return 
	}

	m_fontSize=size;
	m_dirty=true;
}

float LabelBitmap::getFontSize()
{
	return m_fontSize;
}

void LabelBitmap::setColor(Color c)
{
	m_color=c;
}
Color LabelBitmap::getColor()
{
	return m_color;
}

void LabelBitmap::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float LabelBitmap::getOpacity()
{
	return m_opacity;
}


void LabelBitmap::setAnchor(float x,float y)
{
	m_anchorX=x;
	m_anchorY=y;
}

void LabelBitmap::getAnchor(float* x,float* y)
{
	*x=m_anchorX;
	*y=m_anchorY;
}

void LabelBitmap::getTextSize(float* width,float* height)
{
	*width=m_textWidth;
	*height=m_textHeight;
}
float LabelBitmap::getTextWidth()
{
	return m_textWidth;
}

float LabelBitmap::getTextHeight()
{
	return m_textHeight;
}


void LabelBitmap::setTextAlign(int align)
{
	m_textAlign=align;
}

int LabelBitmap::getTextAlign()
{
	return m_textAlign;
}


void LabelBitmap::setBoundSize(float w,float h)
{
	m_boundWidth=w;
	m_boundHeight=h;
}

void LabelBitmap::getBoundSize(float* w,float* h)
{
	*w=m_boundWidth;
	*h=m_boundHeight;
}




void LabelBitmap::draw(Render* r,bool updateMatrix)
{
}


bool LabelBitmap::hit2D(float x,float y)
{

}


LabelBitmap::LabelBitmap()
{
	m_dirty=false;
	m_text="";
	m_utf16text=NULL;

	m_fontName="";
	m_fontSize=1.0f;
	m_textAlign=FS_TEXT_ALIGN_LEFT;

	m_boundWidth=0.0f;
	m_boundHeight=0.0f;

	m_anchorX=0.5f;
	m_anchorY=0.5f;

	m_lineGap=0.0f;

	m_color=Color::WHITE;
	m_opacity=1.0f;

	m_font=NULL;
	m_texture=NULL;
	m_material=Mat_V4F_T2F::shareMaterial();
}

LabelBitmap::~LabelBitmap()
{
	destruct();
}

bool LabelBitmap::init()
{
	return true;
}

void LabelBitmap::destruct()
{
	FS_SAFE_DEC_REF(m_font);
	FS_SAFE_DEC_REF(m_texture);
	FS_SAFE_DEC_REF(m_material);
}


NS_FS_END 



























