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


LabelBitmap* LabelBitmap::create(const char* text,FontBitmap* font)
{
	LabelBitmap* ret=create(font);
	if(ret)
	{
		ret->setString(text);
	}
	return ret;
}

LabelBitmap* LabelBitmap::create(FontBitmap* font)
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init(font))
	{
		ret->decRef();
		ret=NULL;
	}

	return ret;
}

int LabelBitmap::setString(const char* utf8_str)
{
	return setString(utf8_str,0);
}

int LabelBitmap::setString(const char* utf8_str,int start)
{
	return setString(utf8_str,start,-1);
}

int LabelBitmap::setString(const char* utf8_str,int start,int num)
{
	uint16_t* utf16_str=FsUtf8_ToUtf16(utf8_str);
	//uint16_t* utf16_str=FsIconv_UTF8_to_UNICODE(utf8_str);
	int len=FsUtf16_StrLen(utf16_str);
	if(num==-1) { num=len; }
	if(start+num>len) { num=len-start; }
	if(num<=0) 
	{
		delete[] utf16_str;
		return 0;
	}
	else 
	{
		num=setString(utf16_str+start,num);
	}
	delete[] utf16_str;
	return num;
}

const char* LabelBitmap::getString()
{
	if(m_utf8str==NULL)
	{
		return "";
	}

	return (char*)m_utf8str;
}


void LabelBitmap::setAlign(int alignh,int alignv)
{
	m_alignh=alignh;
	m_alignv=alignv;
}
void LabelBitmap::setAlignOffset(float x,float y)
{
	m_offsetx=x;
	m_offsety=y;
}


void LabelBitmap::getAlign(int* alignh,int* alignv)
{
	*alignh=m_alignh;
	*alignv=m_alignv;
}

void LabelBitmap::getAlignOffset(float* x,float* y)
{
	*x=m_offsetx;
	*y=m_offsety;
}

void LabelBitmap::setTextAlign(int mode)
{
	m_textAlign=mode;
}

void LabelBitmap::setBounds(float x,float y)
{
	m_boundx=x;
	m_boundy=y;
}

int LabelBitmap::getTextAlign()
{
	return m_textAlign;
}

void LabelBitmap::getBounds(float* x,float* y)
{
	*x=m_boundx;
	*y=m_boundy;
}

float LabelBitmap::getWidth()
{
	return m_width;
}
float LabelBitmap::getHeight()
{
	return m_height;
}


void LabelBitmap::draw(Render* r,bool updateMatrix)
{
	if(!m_font||(m_vertices.size()==0)||!m_material||!m_program)
	{
		return;
	}
	if(!m_texture)
	{
		return;
	}

	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	r->pushMatrix();
	r->mulMatrix(&m_worldMatrix);
	r->translate(Vector3(m_relOffsetx,m_relOffsety,0));


	r->setProgram(m_program);
	m_material->configRender(r);

	r->disableAllAttrArray();
	r->bindTexture(m_texture,0);


	int pos_loc=r->getCacheAttrLocation(FS_ATTR_V4F_LOC,FS_ATTR_V4F_NAME);

	int tex_loc=r->getCacheAttrLocation(FS_ATTR_T2F_LOC,FS_ATTR_T2F_NAME);

	int vertex_nu=m_vertices.size();

	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertex_nu,sizeof(Fs_V2F_T2F),&m_vertices[0]);
	r->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,vertex_nu,sizeof(Fs_V2F_T2F),&(m_vertices[0].t2));

	r->drawFace3(&m_indics[0],m_indics.size());

	r->popMatrix();
}

bool LabelBitmap::hit2D(float x,float y)
{

	Rect2D rect(m_relOffsetx,-m_height+m_relOffsety,m_width,m_height);

	Vector2 point(x,y);
	updateWorldMatrix();
	return Math::pointInRect2D(point,m_worldMatrix,rect);
}


LabelBitmap::LabelBitmap()
{
	m_alignh=ALIGN_H_RIGHT;
	m_alignv=ALIGN_V_BOTTOM;
	m_offsetx=0;
	m_offsety=0;
	m_textAlign=TEXT_ALIGN_LEFT;

	m_boundx=0;
	m_boundy=0;

	m_utf8str=NULL;
	m_font=NULL;
	m_texture=NULL;

	m_width=0;
	m_height=0;
	m_relOffsetx=0;
	m_relOffsety=0;

	m_material=TextureMaterial:create();
	m_material->addRef();

	m_program=Global::programMgr()->load(FS_PRE_SHADER_V4F_T2F);
	FS_SAFE_ADD_REF(m_program);
}

LabelBitmap::~LabelBitmap()
{
	destruct();
}

bool LabelBitmap::init(FontBitmap* font)
{
	if(!font) return false;

	Texture2D* tex=font->getTexture(0);

	FS_SAFE_ASSIGN(m_texture,tex);
	FS_SAFE_ASSIGN(m_font,font);

	return true;
}

void LabelBitmap::destruct()
{

	clear();

	FS_SAFE_DEC_REF(m_font);
	FS_SAFE_DEC_REF(m_texture);
	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_program);

}

void LabelBitmap::clear()
{
	m_width=0;
	m_height=0;
	m_relOffsetx=0;
	m_relOffsety=0;

	m_vertices.clear();
	m_indics.clear();


	if(m_utf8str)
	{
		delete[] m_utf8str;
		m_utf8str=NULL;
	}


}


int LabelBitmap::setString(uint16_t* utf16_str,int len)
{
	clear();
	std::vector<GlyphBitmap*> glyphs;


	/* Get All Glyphs */
	for(int i=0;i<len;i++)
	{
		int index=utf16_str[i];
		GlyphBitmap* g=m_font->getGlyph(index);
		if(g==NULL)
		{
			FS_TRACE_INFO("Can't Find Index(%d) At FontBitmap,Use Space Instead",index);
			g=m_font->getGlyph(' ');
			assert(g);
		}
		glyphs.push_back(g);
	}




	int cap_glphs=0;

	/* Now Typo String */




	int font_height=m_font->getHeight();
	int pen_x=0;
	int pen_y=0;


	int max_x=0;
	int min_y=0;


	std::vector<std::vector<Fs_V2F_T2F>*> mul_line_vertices;
	std::vector<Fs_V2F_T2F>* curline=NULL;



	std::vector<GlyphBitmap*>::iterator iter=glyphs.begin();
	while(iter!=glyphs.end())
	{
		GlyphBitmap* g=*iter;
		if(g->m_char=='\n')
		{
			if(curline)
			{
				mul_line_vertices.push_back(curline);
				curline=NULL;
			}
			++iter;
			++cap_glphs;
			pen_x=0;
			pen_y-=font_height;
			continue;
		}


		int now_max_x= pen_x+g->m_maxx;

		if(m_boundx>0&&(m_boundx<now_max_x))  /* we must limit string to m_boundx */
		{
			if(curline==NULL)
			{
				break;
			}
			else
			{
				mul_line_vertices.push_back(curline);
				curline=NULL;
			}
			pen_x=0;
			pen_y-=font_height;
			continue;
		}
		int now_min_y=pen_y-g->m_maxy;

		if(m_boundy>0 && (m_boundy<-now_min_y))
		{
			break;
		}

		if(max_x<now_max_x) max_x=now_max_x;
		if(min_y>now_min_y) min_y=now_min_y;


		/* white space */
		if(g->m_char==' '||g->m_char=='\t')
		{
			pen_x+=g->m_xadvance;
			++cap_glphs;
			++iter;
			continue;
		}

		/* now generate vertics */
		if(curline==NULL)
		{
			curline=new std::vector<Fs_V2F_T2F>;
		}

		/* a------d
		 * |      |
		 * |      |
		 * b------c
		 */

		Vector2 v_a(pen_x+(float)g->m_minx,pen_y-(float)(g->m_miny));
		Vector2 v_b(pen_x+(float)g->m_minx,pen_y-(float)(g->m_maxy));
		Vector2 v_c(pen_x+(float)g->m_maxx,pen_y-(float)(g->m_maxy));
		Vector2 v_d(pen_x+(float)g->m_maxx,pen_y-(float)(g->m_miny));

		TexCoord2 t_a(g->m_ult,g->m_vlt);
		TexCoord2 t_b(g->m_ulb,g->m_vlb);
		TexCoord2 t_c(g->m_urb,g->m_vrb);
		TexCoord2 t_d(g->m_urt,g->m_vrt);  /* the max x allway at the end, used for align text */

		/* triangle dab 
		 * triangle dbc 
		 */

		curline->push_back(Fs_V2F_T2F(v_a,t_a));
		curline->push_back(Fs_V2F_T2F(v_b,t_b));
		curline->push_back(Fs_V2F_T2F(v_c,t_c));
		curline->push_back(Fs_V2F_T2F(v_d,t_d));

		pen_x+=g->m_xadvance;
		++cap_glphs;
		++iter;
	}
	if(curline!=NULL)
	{
		mul_line_vertices.push_back(curline);
		curline=NULL;
	}

	float rel_width=m_boundx<=0?max_x:m_boundx;
	float rel_height=m_boundy<=0?-min_y:m_boundy;

	/* align text */
	switch(m_textAlign)
	{
		case  TEXT_ALIGN_LEFT:
			break;
		case TEXT_ALIGN_CENTER:
			{
				std::vector<std::vector<Fs_V2F_T2F>*>::iterator iter;
				for(iter=mul_line_vertices.begin();iter!=mul_line_vertices.end();++iter)  /* for every line */
				{
					if((*iter)->size()==0)
					{
						continue;
					}
					float line_max_x=(*iter)->back().v2.x;
					assert(rel_width>=line_max_x);
					float x_shift=(rel_width-line_max_x)/2.0f;

					for(unsigned int i=0;i<(*iter)->size();i++)
					{
						(*iter)->at(i).v2.x+=x_shift;
					}

				}
			}

			break;
		case TEXT_ALIGN_RIGHT:
			{
				std::vector<std::vector<Fs_V2F_T2F>*>::iterator iter;
				for(iter=mul_line_vertices.begin();iter!=mul_line_vertices.end();++iter)  /* for every line */
				{
					if((*iter)->size()==0)
					{
						continue;
					}
					float line_max_x=(*iter)->back().v2.x;
					assert(rel_width>=line_max_x);
					float x_shift=(rel_width-line_max_x);

					for(unsigned int i=0;i<(*iter)->size();i++)
					{
						(*iter)->at(i).v2.x+=x_shift;
					}

				}
			}
			break;
	}

	/* translate all line to one vertics array */
	std::vector<std::vector<Fs_V2F_T2F>*>::iterator l_iter;
	for(l_iter=mul_line_vertices.begin();l_iter!=mul_line_vertices.end();++l_iter)  /* for every line */
	{
		for(unsigned int i=0;i<(*l_iter)->size();i++)
		{
			m_vertices.push_back((*l_iter)->at(i));
		}
	}
	
	/* release memory */
	for(l_iter=mul_line_vertices.begin();l_iter!=mul_line_vertices.end();++l_iter)  /* for every line */
	{
		delete *l_iter;
	}


	/* set attribute */
	m_width=rel_width;
	m_height=rel_height;

	generateIndices();  /* generate vertics indices */
	calRelOffset();
	m_utf8str=(uint8_t*)FsUtf16_ToUtf8(utf16_str,cap_glphs);

	return cap_glphs;
}


void LabelBitmap::generateIndices()
{
	int vertex_nu=m_vertices.size();
	assert(vertex_nu%4==0);

	int glyph_nu=vertex_nu/4;

	for(int i=0;i<glyph_nu;i++)
	{
		int index=i*4;
		Face3 a(index+0,index+1,index+2);
		Face3 b(index+2,index+3,index+0);
		m_indics.push_back(a);
		m_indics.push_back(b);
	}
}


void LabelBitmap::calRelOffset()
{
	switch(m_alignh)
	{
		case ALIGN_H_RIGHT:
			m_relOffsetx=0;
			break;
		case ALIGN_H_LEFT:
			m_relOffsetx=-m_width;
			break;
		case ALIGN_H_CENTER:
			m_relOffsetx=-m_width/2;
			break;
		case ALIGN_H_USER_DEFINE:
			m_relOffsetx=m_offsetx;
			break;
		default:
			m_relOffsetx=0;
	}

	switch(m_alignv)
	{
		case ALIGN_V_BOTTOM:
			m_relOffsety=0;
			break;
		case ALIGN_V_TOP:
			m_relOffsety=m_height;
			break;
		case ALIGN_V_CENTER:
			m_relOffsety=m_height/2;
			break;
		case ALIGN_V_USER_DEFINE:
			m_relOffsety=m_offsety;
			break;
		default:
			m_relOffsety=0;
	}
}

NS_FS_END 



























