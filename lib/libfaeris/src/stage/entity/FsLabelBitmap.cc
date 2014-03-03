#include "stage/entity/FsLabelBitmap.h"
#include "graphics/FsFontBitmap.h"
#include "graphics/FsTexture2D.h"
#include "graphics/material/FsMat_V4F_T2F.h"
#include "support/data/FsUnicode.h"
#include "support/data/FsIconv.h"
NS_FS_BEGIN

class BitmapTypoText:public TypoText 
{
	public:
		BitmapTypoText(TypoGlyph* g,const Vector2& pen)
			:TypoText(g,pen)
		{

		}

	public:
		Vector2 m_texcoord[4];
};




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
		return ;
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

	if(m_dirty) 
	{
		typoText();
		m_dirty=false;
	}

	*width=m_textWidth;
	*height=m_textHeight;
}
float LabelBitmap::getTextWidth()
{
	if(m_dirty) 
	{
		typoText();
		m_dirty=false;
	}
	return m_textWidth;
}

float LabelBitmap::getTextHeight()
{
	if(m_dirty) 
	{
		typoText();
		m_dirty=false;
	}

	return m_textHeight;
}


void LabelBitmap::setTextAlign(int align)
{
	if(m_textAlign == align)
	{
		return;
	}
	m_textAlign=align;

	if(!m_dirty) 
	{
		m_typoPage.setTextAlign(align)
	}


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
	if(!m_font||!m_utf16text)
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

	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);

	render->setMaterial(m_material);
	render->setActiveTexture(1);
	render->disableAllAttrArray();

	Texture2D* t2d=m_textures->get(0);
	render->bindTexture(t2d,0);

	int pos_loc=m_material->getV4FLocation();
	int tex_loc=m_material->getT2FLocation();

	int typo_lines=m_typoPage.getTypoLineNu();

	for(int i=0;i<typo_lines;i++)
	{
		TypoLine<typoText>* line=m_typoPage.getTypoLine(i);

		int text_nu=line->getTextNu();

		for(int j=0;j<text_nu;j++)
		{
			TypoText* t=line->getText(j);

			render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,&t->m_vertices[0]);
			render->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,4,0,&t->m_texcoord[0]);

			render->drawArray(Render::TRIANGLE_STRIP,0,4);
		}
	}

	render->popMatrix();

}


bool LabelBitmap::hit2D(float x,float y)
{

	if(m_dirty)
	{
		typoText();
		m_dirty=false;
	}
	updateWorldMatrix();
	Vector3 v=worldToLocal(Vector3(x,y,0));

	float diffx=v.x+m_anchorX*m_textWidth;
	float diffy=v.y+m_anchorY*m_textHeight;

	if (diffx>=0 && diffx <m_textWidth) 
	{
		if( diffy>=0 && diffy <m_textHeight) 
		{
			return true;
		}
	}

	return false;
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

void LabelBitmap::typoText()
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
		GlyphBitmap* g=m_font->getGlyph(*p_text);
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



























