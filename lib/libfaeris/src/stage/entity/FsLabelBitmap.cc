#include "FsLabelBitmap.h"
#include "support/data/FsIconv.h"
#include "support/data/FsUnicode.h"
#include "FsGlobal.h"
#include "graphics/FsFontBitmap.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"
#include "FsClass.h"


NS_FS_BEGIN

LabelBitmap* LabelBitmap::create()
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init())
	{
		delete ret;
		ret=NULL;
	}

	return ret;
}

LabelBitmap* LabelBitmap::create(const char* font)
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init(font,1.0f))
	{
		delete ret;
		ret=NULL;
	}

	return ret;
}

LabelBitmap* LabelBitmap::create(const char* font,const char* text)
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init(font,1.0f,text))
	{
		delete ret;
		ret=NULL;
	}
	return ret;
}

LabelBitmap* LabelBitmap::create(const char* font,float size,const char* text)
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init(font,1.0f,text))
	{
		delete ret;
		ret=NULL;
	}

	return ret;
}


void LabelBitmap::setString(const char* str)
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
	m_drawDirty=true;
}

const char* LabelBitmap::getString()
{
	return m_text.c_str();
}

void LabelBitmap::setFontName(const char* font_name)
{
	if(m_fontName==font_name)
	{
		return;
	}

	m_fontName=font_name;

	FontBitmap*  font=(FontBitmap*)Global::fontBitmapMgr()->load(font_name);

	FS_TRACE_WARN_ON(font==NULL,"Load FontName %s Failed",font_name);

	FS_SAFE_ASSIGN(m_font,font);
	m_dirty=true;
	m_drawDirty=true;
}


const char* LabelBitmap::getFontName()
{
	return m_fontName.c_str();
}

void LabelBitmap::setFontSize(float size)
{
	if(m_fontSize==size)
	{
		return;
	}

	m_fontSize=size;
	m_dirty=true;
	m_drawDirty=true;
}

float LabelBitmap::getFontSize()
{
	return m_fontSize;
}

void LabelBitmap::setTextAlign(E_TextAlign align)
{
	if(m_textAlign == align)
	{
		return ;
	}
	m_textAlign=align;

	if(!m_dirty)
	{
		m_typoPage.setTextAlign(align);
		m_drawDirty=true;
	}
}

E_TextAlign LabelBitmap::getTextAlign()
{
	return m_textAlign;
}

void LabelBitmap::setBoundSize(const Vector2& v)
{
	setBoundSize(v.x,v.y);
}

void LabelBitmap::setBoundWidth(float width)
{
	if(m_boundWidth==width)
	{
		return;
	}
	m_boundWidth=width;
	m_dirty=true;
	m_drawDirty=true;
}


void LabelBitmap::setBoundHeight(float height)
{
	if(m_boundHeight==height)
	{
		return;
	}
	m_boundHeight=height;
	m_dirty=true;
	m_drawDirty=true;
}

void LabelBitmap::setBoundSize(float width,float height)
{
	if(m_boundWidth==width&&m_boundHeight==height)
	{
		return;
	}

	m_boundWidth=width;
	m_boundHeight=height;
	m_dirty=true;
	m_drawDirty=true;
}

Vector2 LabelBitmap::getBoundSize()
{
	Vector2 ret(m_boundWidth,m_boundHeight);
	return ret;
}


float LabelBitmap::getBoundWidth()
{
	return m_boundWidth;
}

float LabelBitmap::getBoundHeight()
{
	return m_boundHeight;
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

void LabelBitmap::setLineGap(float gap)
{
	m_lineGap=gap;
	m_dirty=true;
}

float LabelBitmap::getLineGap()
{
	return m_lineGap;
}

void LabelBitmap::setAnchor(const Vector2& v)
{
	Entity2D::setAnchor(v);
	if(!m_dirty)
	{
		m_typoPage.setAnchor(v.x,v.y);
		m_drawDirty=true;
	}
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

void LabelBitmap::draw(RenderDevice* rd,bool update_matrix) 
{
	Program* prog=m_material->getProgram(NULL);
	if(!m_font||!prog)
	{
		return;
	}

	Texture2D* texture=m_font->getTexture(0);
	if(!texture)
	{
		return;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}

	if(m_dirty)
	{
		typoText();
		m_dirty=false;
	}

	if(m_drawDirty)
	{
		m_finishVertices.clear();
		m_faces.clear();
		int face_index=0;

		int typo_lines=m_typoPage.getTypoLineNu();
		for(int i=0;i<typo_lines;i++)
		{
			TypoLine<TypoText>* line=m_typoPage.getTypoLine(i);
			int text_nu=line->getTextNu();

			for(int j=0;j<text_nu;j++)
			{
				TypoText* t=line->getText(j);
				GlyphBitmap* g=(GlyphBitmap*)t->m_glyph;
				if(g->getChar()==' '||g->getChar()=='\t'||g->getChar()=='\n')
				{
					continue;
				}

				m_finishVertices.push_back(Fs_V2F_T2F(t->m_vertices[0],TexCoord2(g->m_ulb,g->m_vlb)));
				m_finishVertices.push_back(Fs_V2F_T2F(t->m_vertices[1],TexCoord2(g->m_urb,g->m_vrb)));
				m_finishVertices.push_back(Fs_V2F_T2F(t->m_vertices[2],TexCoord2(g->m_ult,g->m_vlt)));
				m_finishVertices.push_back(Fs_V2F_T2F(t->m_vertices[3],TexCoord2(g->m_urt,g->m_vrt)));

				int vertex_index=face_index*4;

				m_faces.push_back(Face3(vertex_index+0,vertex_index+1,vertex_index+2));
				m_faces.push_back(Face3(vertex_index+3,vertex_index+2,vertex_index+1));

				face_index++;
			}
		}
		m_drawDirty=false;
	}
	int size=m_finishVertices.size();
	if(size==0)
	{
		return;
	}




	rd->setWorldMatrix(&m_worldMatrix);
	rd->setProgram(prog);
	m_material->configRenderDevice(rd);

	rd->bindTexture(texture,0);

	rd->disableAllAttrArray();


	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);

	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,size,
							sizeof(Fs_V2F_T2F),
							&m_finishVertices[0].v2);
	}
	if(map_u)
	{
		rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,size,
				sizeof(Fs_V2F_T2F),
				&m_finishVertices[0].t2);

	}

	rd->drawFace3(&m_faces[0],m_faces.size());

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

	while(!m_typoPage.done()&&(*p_text))
	{
		GlyphBitmap* g=m_font->getGlyph(*p_text);
		if(!g)
		{
			FS_TRACE_INFO("Can't Find Index(%d) At FontBitmap,Use Space Instead",*p_text);
			g=m_font->getGlyph(' ');
			assert(g);
		}

		m_typoPage.pushText(g,m_fontSize);
		p_text++;
	}
	m_typoPage.typoEnd();


	m_typoPage.setTextAlign(m_textAlign);
	m_typoPage.setAnchor(m_anchor.x,m_anchor.y);
	m_textWidth=m_typoPage.getTextWidth();
	m_textHeight=m_typoPage.getTextHeight();
}

LabelBitmap::LabelBitmap()
{
	m_dirty=false;
	m_drawDirty=false;

	m_text="";
	m_utf16text=NULL;
	m_fontName="";
	m_fontSize=1.0f;
	m_textAlign=E_TextAlign::LEFT;
	m_boundWidth=0;
	m_boundHeight=0;
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

LabelBitmap::~LabelBitmap()
{
	destruct();
}




bool LabelBitmap::init()
{
	return true;
}

bool LabelBitmap::init(const char* font,float size)
{
	setFontName(font);
	setFontSize(size);
	return true;
}

bool LabelBitmap::init(const char* font,float size,const char* text)
{
	setFontName(font);
	setFontSize(size);
	setString(text);
	return true;
}

void LabelBitmap::destruct()
{
	FS_SAFE_DELETES(m_utf16text);
	FS_SAFE_DEC_REF(m_font);
}



/** Used For FsLabelBitmap Attribute */

static LabelBitmap* LabelBitmap_NewInstance(FsDict* attr)
{
	LabelBitmap* ret=LabelBitmap::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}

	return ret;
}


FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(LabelBitmap,setString,getString);
FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(LabelBitmap,setFontName,getFontName);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelBitmap,setFontSize,getFontSize,float);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(LabelBitmap,setTextAlign,getTextAlign,TextAlign);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelBitmap,setBoundSize,getBoundSize,Vector2);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelBitmap,setBoundWidth,getBoundWidth,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelBitmap,setBoundHeight,getBoundHeight,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(LabelBitmap,setLineGap,getLineGap,float);


static FsClass::FsAttributeDeclare S_LabelBitmap_BoundSize_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("w",FsType::FT_F_1,NULL,LabelBitmap_setBoundWidth,LabelBitmap_getBoundWidth),
	FS_CLASS_ATTR_DECLARE("h",FsType::FT_F_1,NULL,LabelBitmap_setBoundHeight,LabelBitmap_getBoundHeight),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

static FsClass::FsAttributeDeclare S_labelBitmap_Main_Attr[]={

	FS_CLASS_ATTR_DECLARE("string",FsType::FT_CHARS,NULL,LabelBitmap_setString,LabelBitmap_getString),
	FS_CLASS_ATTR_DECLARE("fontName",FsType::FT_CHARS,NULL,LabelBitmap_setFontName,LabelBitmap_getFontName),
	FS_CLASS_ATTR_DECLARE("fontSize",FsType::FT_F_1,NULL,LabelBitmap_setFontSize,LabelBitmap_getFontSize),
	FS_CLASS_ATTR_DECLARE("textAlign",FsType::FT_CHARS,NULL,LabelBitmap_setTextAlign,LabelBitmap_getTextAlign),
	FS_CLASS_ATTR_DECLARE("boundSize",FsType::FT_F_2,S_LabelBitmap_BoundSize_SubAttr,LabelBitmap_setBoundSize,LabelBitmap_getBoundSize),
	FS_CLASS_ATTR_DECLARE("lineGap",FsType::FT_F_2,NULL,LabelBitmap_setLineGap,LabelBitmap_getLineGap),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)

};
FS_CLASS_IMPLEMENT_WITH_BASE(LabelBitmap,Entity2D,LabelBitmap_NewInstance,S_labelBitmap_Main_Attr);
















NS_FS_END



