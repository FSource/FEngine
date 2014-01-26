#include <stdlib.h>
#include <string.h>
#include "support/data/FsIconv.h"
#include "stage/entity/FsLabelTTF.h"
#include "graphics/material/FsMat_V4F_T2F.h"
#include "graphics/FsImage2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsFontTTF.h"
#include "graphics/FsRender.h"
#include "support/util/FsArray.h"


NS_FS_BEGIN


const char*  LabelTTF::className()
{
	return FS_LABEL_TTF_CLASS_NAME;
}

LabelTTF* LabelTTF::create(const char* font)
{
	LabelTTF* ret=new LabelTTF;
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
	m_utf16Str=NULL;
	m_utf16StrLength=0;
	m_fontName="";
	m_alignv=FS_ALIGN_V_CENTER;
	m_alginv=FS_ALIGN_H_LEFT;

	m_width=0;
	m_height=0;
	m_anchorX=0.5;
	m_anchorY=0.5;


	m_color=Color::WHITE;
	m_opacity=1.0f;


	m_font=NULL;
	m_material=Mat_V4F_T2F::shareMaterial();
	FS_SAFE_ADD_REF(m_material);

	m_textWidth=0;
	m_textHeight=0;

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
bool LabelTTF::init(const char* font,int size,char* text)
{
	setFontName(font);
	setFontSize(size);
	setString(text);
	return true;
}



void LabelTTF::destruct()
{
	FS_SAFE_DELETES(m_utf16Str);
	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_font);

}


void LabelTTF::setString(const char* str)
{
	FS_TRACE_WARN_ON(string==NULL,"NULL String");
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

	FontTTF* font=(FontTTF*)Global::FontTTFMgr()->load(font_name);
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


void LabelTTF::setTextAlign(int h,int v)
{
	if(m_alignh==h&&m_alignv==v)
	{
		return;
	}

	m_alignh=h;
	m_alignv=v;
	if(!m_dirty)
	{
		realignText();
	}
}

void LabelTTF::getTextAlign(int* h,int* v)
{
	*h=m_alignh;
	*v=m_alignv;
}

void LabelTTF::setSize(float width,float height)
{
	if(m_width==width&&m_height==height)
	{
		return;
	}
	m_width=width;
	m_height=height;
	m_dirty=true;
}

void LabelTTF::setAnchor(float x,float y)
{
	m_anchorX=x;
	m_anchorY=y;
}

void LabelTTF::getAnchor(float* x,float* y)
{
	*x=m_anchorX;
	*y=m_anchorY;
}

void LabelTTF::setColor(Color c)
{
	m_color=c;
}

Color LabelTTF::getColor()
{
	return m_color;
}

void LabelTTF::setOpacity(float opacity)
{
	m_opacity=opacity;
}


float LabelTTF::getOpacity()
{
	return m_opacity;
}






FS_FEATURE_NEW_OBJECT(Image2D*) LineTypography::typo(const char* text,FontTTF* font)
{
	uint16_t* unicode=FsIconv_UTF8_to_UNICODE(text);
	if(!unicode)
	{
		return NULL;
	}
	uint16_t* cur=unicode;
	uint16_t ch;
	
	FsArray* glyphs=FsArray::create();

	while((ch=(*cur++)))
	{
		if(ch=='\n') /* just ignore  new line */
		{
			continue;
		}

		Glyph* g=font->getGlyph(ch);
		if(font)
		{
			glyphs->push(g);
		}
		else 
		{
			FS_TRACE_WARN("Can't Load Glyph %d,just ignore it",ch);
		}
	}


	int maxx=0,minx=0,maxy=0, miny=0;
	int glyphs_nu=glyphs->size();

	int penx=0;
	for(int i=0;i<glyphs_nu;i++)
	{
		Glyph* g=(Glyph*)glyphs->get(i);
		if(i==0)
		{
			maxx=g->m_maxx;
			minx=g->m_minx;
			maxy=g->m_maxy;
			miny=g->m_miny;
			penx=minx+g->m_advance;
		}
		else 
		{
			if(maxy<g->m_maxy)
			{
				maxy=g->m_maxy;
			}
			if(miny>g->m_miny)
			{
				miny=g->m_miny;
			}
			if(minx>penx+g->m_minx)
			{
				minx=penx+g->m_minx;
			}
			if(maxx<penx+g->m_maxx)
			{
				maxx=penx+g->m_maxx;
			}
			penx+=g->m_advance;
		}
	}

	int width=maxx-minx+1;
	int height=maxy-miny;
	int font_height=font->getHeight();

	assert(height<=font_height);
	height=font_height;


	if(width==0)
	{
		glyphs->decRef();
		delete unicode;
		return NULL;
	}
	Image2D* dst_image=Image2D::create(width,height,
										Image2D::PIXEL_RGBA8888);
	uint8_t* dst_buffer=(uint8_t*)dst_image->getPixelData();
	memset(dst_buffer,0,width*height*4);

	int startx=-minx;

	for(int i=0;i<glyphs_nu;i++)
	{
		Glyph* g=(Glyph*)glyphs->get(i);
		if(g->m_bitmap==NULL)
		{
			startx+=g->m_advance;
			continue;
		}

		uint8_t* src_buffer=(uint8_t*)g->m_bitmap->getPixelData();
		int glyph_width=g->m_bitmap->getWidth();
		int glyph_height=g->m_bitmap->getHeight();

		assert(font->getAscend()>=g->m_maxy);
		int y_offset=font->getAscend()-g->m_maxy;


		for(int j=0;j<glyph_height;j++)
		{
			for(int z=0;z<glyph_width;z++)
			{
				assert(z+startx+g->m_minx<width);
				uint8_t gray=src_buffer[j*glyph_width+z];
				uint8_t* cur_dst_buffer=dst_buffer+((j+y_offset)*width+z+startx+g->m_minx)*4;
				*cur_dst_buffer=255;
				*(cur_dst_buffer+1)=255;
				*(cur_dst_buffer+2)=255;
				*(cur_dst_buffer+3)=gray;
			}
		}
		startx+=g->m_advance;
	}
	glyphs->decRef();
	delete[] unicode;
	return dst_image;
}





void LabelTTF::draw(Render* render,bool updateMatrix)
{

}

bool LabelTTF::hit2D(float x,float y)
{
	if(m_width==0||m_height==0)
	{
		if(m_dirty) /* check dirty */
		{
			typoText();
			m_dirty=false;
		}
	}


	float width=m_width,height=m_height;
	if(width==0) width=m_textWidth;
	if(height==0) height=m_textHeight;


	Rect2D rect=getRect2D();

	updateWorldMatrix();
	Vector3 v=worldToLocal(Vector3(x,y,0));
	float diffx=x+m_anchorX*width;
	float diffy=x+m_anchorY*height;

	if(diffx>=0 && diffx <width)
	{
		if(diffy>=0 && diffy <height)
		{
			return true;
		}

	}
	return false;

}

void LabelTTF::typoText()
{
	if(m_utf16text==NULL||m_fontName==NULL)
	{
		m_textWidth=0;
		m_textHeight=0;
		return;
	}
	uint16_t* ptext=m_utf16text;

	m_typoPage.typoBegin(m_width,m_height,0,m_lineGap);

	while((!m_typoPage.done())&&(*p_text))
	{
		GlyphTTF* g=m_font->getGlyphTTF(*p_text,size);
		m_typoPage.pushText(g);
		p_text++;
	}
	m_typoPage.typoEnd();
	m_typoPage.setAlign(m_alignh,m_alignv);
	m_textWidth=m_typoPage.getTextWidth();
	m_textHeight=m_typoPage.getTextHeight();
}


void LabelTTF::realignText()
{
	m_typoPage.setAlign(m_alignh,m_alginv);
}



NS_FS_END

















