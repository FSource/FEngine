#include <stdlib.h>
#include <string.h>
#include "support/data/FsIconv.h"
#include "support/data/FsUnicode.h"
#include "stage/entity/FsLabelTTF.h"
#include "graphics/FsImage2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsFontTTF.h"
#include "graphics/FsRenderDevice.h"
#include "support/util/FsArray.h"
#include "graphics/shader/FsStreamMap.h"


#include "FsClass.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"


NS_FS_BEGIN


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

	m_anchor.set(0.5f,0.5f);

	m_lineGap=0;


	m_font=NULL;

	m_textWidth=0;
	m_textHeight=0;

	static ProgramSource* S_programSource=NULL;
	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource* )Global::programSourceMgr()->load("__V4F_T2F__.fshader");
	}
	setProgramSource(S_programSource);
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


void LabelTTF::setTextAlign(E_TextAlign align)
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


E_TextAlign LabelTTF::getTextAlign()
{
	return m_textAlign;
}

void LabelTTF::setBoundSize(const Vector2& v)
{
	setBoundSize(v.x,v.y);
}

void LabelTTF::setBoundWidth(float width) 
{
	if(m_boundWidth==width)
	{
		return ;
	}
	m_boundWidth=width;
	m_dirty=true;
}

void LabelTTF::setBoundHeight(float height)
{
	if(m_boundHeight==height)
	{
		return;
	}
	m_boundHeight=height;
	m_dirty=true;
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


Vector2 LabelTTF::getBoundSize()
{
	Vector2 ret;
	getBoundSize(&ret.x,&ret.y);
	return ret;
}

void LabelTTF::getBoundSize(float* width,float* height)
{
	*width=m_boundWidth;
	*height=m_boundHeight;
}

float LabelTTF::getBoundWidth()
{
	return m_boundWidth;
}

float LabelTTF::getBoundHeight()
{
	return m_boundHeight;
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



void LabelTTF::setAnchor(const Vector2& v)
{
	Entity2D::setAnchor(v);
	if(!m_dirty)
	{
		m_typoPage.setAnchor(v.x,v.y);
	}
}





void LabelTTF::draw(RenderDevice* rd,bool updateMatrix)
{
	Program* prog=m_material->getProgram(NULL);

	if(!m_font||!m_utf16text||!prog)
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

	rd->setWorldMatrix(&m_worldMatrix);
	rd->setProgram(prog);

	m_material->configRenderDevice(rd);



	rd->disableAllAttrArray();


	StreamMap* map_v =prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u= prog->getStreamMap(E_StreamType::UVS);


	static float t[8]={
		0.0f,1.0f,
		1.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,
	};


	if(map_u)
	{
		rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,4,0,t);
	}

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
				rd->bindTexture(t2d,0);
				if(map_v)
				{
					rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,4,0,&t->m_vertices[0]);
				}

				rd->drawArray(E_DrawMode::TRIANGLE_STRIP,0,4);
			}
		}
	}

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

	float diffx=v.x+m_anchor.x*m_textWidth;
	float diffy=v.y+m_anchor.y*m_textHeight;

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
	m_typoPage.setAnchor(m_anchor.x,m_anchor.y);

	m_textWidth=m_typoPage.getTextWidth();
	m_textHeight=m_typoPage.getTextHeight();
}



/** Used For FsLabelTTF Attribute */

static LabelTTF* LabelTTF_NewInstance(FsDict* attr)
{
	LabelTTF* ret=LabelTTF::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}






FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(LabelTTF,setString,getString);
FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(LabelTTF,setFontName,getFontName);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelTTF,setFontSize,getFontSize,int);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(LabelTTF,setTextAlign,getTextAlign,TextAlign);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelTTF,setBoundSize,getBoundSize,Vector2);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelTTF,setBoundWidth,getBoundWidth,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelTTF,setBoundHeight,getBoundHeight,float);

FS_CLASS_ATTR_SET_GET_FUNCTION(LabelTTF,setLineGap,getLineGap,float);


static FsClass::FsAttributeDeclare S_LabelTTF_BoundSize_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("w",FsType::FT_F_1,NULL,LabelTTF_setBoundWidth,LabelTTF_getBoundWidth),
	FS_CLASS_ATTR_DECLARE("h",FsType::FT_F_1,NULL,LabelTTF_setBoundHeight,LabelTTF_getBoundHeight),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};


static FsClass::FsAttributeDeclare S_LabelTTF_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("string",FsType::FT_CHARS,NULL,LabelTTF_setString,LabelTTF_getString),
	FS_CLASS_ATTR_DECLARE("fontName",FsType::FT_CHARS,NULL,LabelTTF_setFontName,LabelTTF_getFontName),
	FS_CLASS_ATTR_DECLARE("fontSize",FsType::FT_I_1,NULL,LabelTTF_setFontSize,LabelTTF_getFontSize),
	FS_CLASS_ATTR_DECLARE("textAlign",FsType::FT_CHARS,NULL,LabelTTF_setTextAlign,LabelTTF_getTextAlign),
	FS_CLASS_ATTR_DECLARE("boundSize",FsType::FT_F_2,S_LabelTTF_BoundSize_SubAttr,LabelTTF_setBoundSize,LabelTTF_getBoundSize),
	FS_CLASS_ATTR_DECLARE("lineGap",FsType::FT_F_2,NULL,LabelTTF_setLineGap,LabelTTF_getLineGap),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(LabelTTF,Entity,LabelTTF_NewInstance,S_LabelTTF_Main_Attr);









NS_FS_END

















