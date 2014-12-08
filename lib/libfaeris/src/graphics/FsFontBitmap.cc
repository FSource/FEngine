#include <string.h>
#include <stdlib.h>

#include "graphics/FsFontBitmap.h"
#include "graphics/FsTexture2D.h"
#include "support/util/FsDict.h"
#include "support/util/FsInteger.h"
#include "support/util/FsArray.h"
#include "sys/io/FsFile.h"
#include "sys/io/FsVFS.h"
#include "FsGlobal.h"

NS_FS_BEGIN
#define FS_CHAR_TOKEN_NUM 9
static const char* s_char_token[FS_CHAR_TOKEN_NUM]=
{
	"id=", "x=", "y=", "width=", "height=", "xoffset=", "yoffset=", "xadvance=","page="
};
static int s_char_token_len[FS_CHAR_TOKEN_NUM]=
{
	 3,2,2,6,7,8,8,9,5,
};

GlyphBitmap* GlyphBitmap::create()
{
	return new GlyphBitmap;
}

GlyphBitmap::GlyphBitmap()
	:m_char(0),m_x(0),m_y(0),m_width(0),m_height(0),m_xoffset(0),m_yoffset(0),m_xadvance(0),m_page(0)
{
	m_minx=0;
	m_miny=0;
	m_maxx=0;
	m_maxy=0;

	m_ulb=0;
	m_vlb=0;
	m_urb=0;
	m_vrb=0;
	m_urt=0;
	m_vrt=0;
	m_ult=0;
	m_vlt=0;
}
const char* GlyphBitmap::className()
{
	return FS_GLYPH_BITMAP_CLASS_NAME;
}



const char* FontBitmap::className()
{
	return FS_FONT_BITMAP_CLASS_NAME;
}

FontBitmap::GlyphSet::GlyphSet()
{
}
FontBitmap::GlyphSet::~GlyphSet()
{
	std::map<int,GlyphBitmap*>::iterator iter;

	for(iter=m_values.begin();iter!=m_values.end();++iter)
	{
		iter->second->decRef();
	}
	m_values.clear();
}

void FontBitmap::GlyphSet::insert(int key,GlyphBitmap* g)
{
	g->addRef();

	std::map<int,GlyphBitmap*>::iterator iter=m_values.find(key);
	if(iter!=m_values.end())
	{
		iter->second->decRef();  /* key has insert, so just remove it */
	}
	m_values[key]=g;
}

GlyphBitmap* FontBitmap::GlyphSet::find(int key)
{
	std::map<int,GlyphBitmap*>::iterator iter=m_values.find(key);
	if(iter!=m_values.end())
	{
		return iter->second;
	}
	else 
	{
		return NULL;
	}
}


FontBitmap* FontBitmap::create(const char* fnt)
{
	FsFile* file=VFS::createFile(fnt);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't open File(%s) For FontBitmap",fnt);
		return NULL;
	}
	FontBitmap* ret=create(file);
	file->decRef();
	return ret;
}

FontBitmap* FontBitmap::create(FsFile* file)
{
	FontBitmap* ret=new FontBitmap();
	if(!ret->init(file))
	{
		ret->decRef();
		ret=NULL;
	}
	return ret;
}



FontBitmap::FontBitmap()
{
	m_glyphs=NULL;
	m_textureWidth=0;
	m_textureHeight=0;
	m_descent=0;
	m_ascent=0;
	m_height=0;
	m_textures=NULL;
}

FontBitmap::~FontBitmap()
{
	destruct();
}

void FontBitmap::destruct()
{
	FS_SAFE_DELETE(m_glyphs);
	m_glyphs=NULL;

	FS_DESTROY(m_textures);
	m_textures=NULL;
}


GlyphBitmap* FontBitmap::getGlyph(uint16_t index)
{
	GlyphBitmap* g= m_glyphs->find(index);
	return g;

}

Texture2D* FontBitmap::getTexture(int index)
{
	if((unsigned int)index>=m_textures->size())
	{
		return NULL;
	}

	return (Texture2D*) m_textures->get(index);
}


bool FontBitmap::init(FsFile* file)
{
	int file_len=file->getLength();

	char* buf=new char[file_len+1];
	buf[file_len]='\0';

	file->read(buf,file_len);

	std::string file_data(buf);

	delete[] buf;

	std::string::size_type cur_pos=0;
	std::string::size_type  prev_pos=0;

	int line_height=0;
	int base_line=0;
	int scale_w=0;
	int scale_h=0;

	int max_y=0;
	int min_y=0;
	int max_xadvance=0;

	std::string texture_file;
	GlyphSet* glyphs=new GlyphSet;

	Texture2D* texture=NULL;
	GlyphBitmap* g=NULL;

	int line_num=1;


	bool next=true;
	while(next)
	{
		cur_pos=file_data.find('\n',prev_pos);

		std::string line;
		if(cur_pos==std::string::npos)
		{
			line=file_data.substr(prev_pos,std::string::npos);
			next=false;
		}
		else 
		{
			std::string::size_type length=cur_pos-prev_pos;
			line=file_data.substr(prev_pos,length);
		}

		if(strncmp(line.c_str(),"info",4)==0)
		{
			/* do nothing */
		}
		else if(strncmp(line.c_str(),"common",6)==0)
		{
			unsigned long long height_pos,base_pos,scale_w_pos,scale_h_pos;

			/* lineHeight */
			height_pos=line.find("lineHeight=");
			if(height_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"lineHeight\" In Font Bitmap");
				goto error;
			}
			line_height=atoi(line.c_str()+height_pos+11);  /* strlen("lineHeight=") is 11 */


			/* baseline */
			base_pos=line.find("base=");
			if(base_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"lineHeight\" In Font Bitmap");
				goto error;
			}
			base_line=atoi(line.c_str()+base_pos+5);  /* strlen("base=") is 5 */



			/* scaleW */
			scale_w_pos=line.find("scaleW=");
			if(scale_w_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"scaleW\" in FontBitmap");
				goto error;
			}
			scale_w=atoi(line.c_str()+scale_w_pos+7); /* strlen("scaleW") is 7 */

			/* scaleH */
			scale_h_pos=line.find("scaleH=");
			if(scale_w_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"scaleH\" in FontBitmap");
				goto error;
			}

			scale_h=atoi(line.c_str()+scale_h_pos+7);  /* strlen("scaleH") is 7 */
		}
		else if (strncmp(line.c_str(),"page",4)==0)
		{
			std::string::size_type file_name_begin_pos,file_name_end_pos;


			/* begin pos */
			file_name_begin_pos=line.find("file=\"");
			if(file_name_begin_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find file name in FontBitmap");
				goto error;
			}

			/* end pos */
			file_name_end_pos=  line.find("\"",file_name_begin_pos+6);
			if(file_name_end_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find file name in FontBitmap");
				goto error;
			}

			texture_file=line.substr(file_name_begin_pos+6,file_name_end_pos-file_name_begin_pos-6);
		}

		else if (strncmp(line.c_str(),"char ",5)==0)
		{
			int v_id,v_x,v_y,v_width,v_height,v_xoffset,v_yoffset,v_xadvance,v_page;
			int* values[FS_CHAR_TOKEN_NUM]={&v_id,&v_x,&v_y,&v_width,&v_height,
										&v_xoffset,&v_yoffset,&v_xadvance,&v_page};

			for(int i=0;i<FS_CHAR_TOKEN_NUM;i++)
			{
				unsigned long long token_pos=line.find(s_char_token[i]);
				if(token_pos==std::string::npos)
				{
					FS_TRACE_WARN("Ignore:Can't Find Token(%s) In Bitmap At Line(%d)",s_char_token[i],line_num);
					goto next_line;
				}
				*values[i]=atoi(line.c_str()+s_char_token_len[i]+token_pos);
			}

			GlyphBitmap* glyph=GlyphBitmap::create();
			glyph->m_char=v_id;
			glyph->m_x=v_x;
			glyph->m_y=v_y;
			glyph->m_width=v_width;
			glyph->m_height=v_height;
			glyph->m_xoffset=v_xoffset;
			glyph->m_yoffset=v_yoffset;
			glyph->m_xadvance=v_xadvance;
			glyph->m_page=v_page;

			/* cache info for typography */
			glyph->m_minx=v_xoffset;
			glyph->m_maxx=v_xoffset+v_width;
			glyph->m_miny=v_yoffset;
			glyph->m_maxy=v_yoffset+v_height;

			glyph->m_ulb=(float)v_x/(float)scale_w;
			glyph->m_vlb=(float)(v_y+v_height)/(float)scale_h;

			glyph->m_urb=(float)(v_x+v_width)/(float)scale_w;
			glyph->m_vrb=glyph->m_vlb;

			glyph->m_urt=glyph->m_urb;
			glyph->m_vrt=(float)v_y/(float)scale_h;

			glyph->m_ult=glyph->m_ulb;
			glyph->m_vlt=glyph->m_vrt;





			if(glyph->m_maxy>max_y)
			{
				max_y=glyph->m_maxy;
			}
			if(v_yoffset<min_y)
			{
				min_y=v_yoffset;
			}
			if(max_xadvance<v_xadvance)
			{
				max_xadvance=v_xadvance;
			}
			glyphs->insert(v_id,glyph);
		}
		else
		{
			//FS_TRACE_INFO("Ignore Unused Of UnSupport Line(%d)",line_num);
		}

next_line:
		line_num++;
		cur_pos++;
		prev_pos=cur_pos;
	}


	texture=Global::textureMgr()->loadTexture(texture_file.c_str());

	if(texture==NULL)
	{
		FS_TRACE_WARN("Can't Load Texture(%s) For Bitmap",texture_file.c_str());
		goto error;
	}
	//texture->setFilter(Texture2D::FILTER_NEAREST,Texture2D::FILTER_NEAREST);


	/* find space */
	g=glyphs->find(' '); 
	if(g==NULL)
	{
		g=new GlyphBitmap();
		g->m_char=' ';
		g->m_xadvance=max_xadvance;
		g->m_maxx=max_xadvance;
		glyphs->insert(' ',g);
	}

	/* find tab */
	g=glyphs->find('\t');
	if(g==NULL)
	{
		g=new GlyphBitmap();
		g->m_char='\t';
		g->m_xadvance=max_xadvance;
		g->m_maxx=max_xadvance;
		glyphs->insert('\t',g);
	}


	/* find line */
	g=glyphs->find('\n');
	if(g==NULL)
	{
		g=new GlyphBitmap();
		g->m_char='\n';
		glyphs->insert('\n',g);
	}



	m_glyphs=glyphs;
	m_textureWidth=scale_w;
	m_textureHeight=scale_h;


	m_ascent=line_height-base_line;
	m_descent=m_ascent-line_height;

	m_height=line_height;

	m_textures=FsArray::create();
	FS_NO_REF_DESTROY(m_textures);
	m_textures->push(texture);

	return true;

error:
	delete glyphs;
	return false;

};







NS_FS_END;
































