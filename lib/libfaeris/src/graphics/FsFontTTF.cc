/*************************************************************************/
/*  FsFontTTF.cc                                                         */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include "ft2build.h"
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include "graphics/FsFontTTF.h"
#include "graphics/FsImage2D.h"
#include "graphics/FsTexture2D.h"
#include "FsGlobal.h"
#include "sys/io/FsFile.h"


#define FT_FLOOR(X)	((X & -64) / 64)
#define FT_CEIL(X)	(((X + 63) & -64) / 64)



NS_FS_BEGIN
static FT_Library S_mLibrary;

static int S_mFreetypeRefNu=0;

static int S_RefFreetype()
{
	if(S_mFreetypeRefNu==0)
	{
		FT_Error error = FT_Init_FreeType( &S_mLibrary);
		if(error)
		{
			FS_TRACE_WARN("init FT_Library Failed");
			return -1;
		}
	}
	S_mFreetypeRefNu++;
	return 0;
}

static int S_unRefFreeType()
{
	assert(S_mFreetypeRefNu>0);
	S_mFreetypeRefNu--;
	if(S_mFreetypeRefNu==0)
	{
		FT_Done_FreeType(S_mLibrary);
	}
	return 0;
}


static unsigned long  S_fileRead(FT_Stream stream,
		unsigned long offset,
		unsigned char* buffer,
		unsigned long count)
{
	int readbyte;
	FsFile* file=(FsFile*)stream->descriptor.pointer;
	file->seek(offset,E_FileSeek::SET);
	readbyte=file->read(buffer,count);
	return readbyte;
}




class PlatfromFontTTF
{
	public:
		PlatfromFontTTF();
		~PlatfromFontTTF();
	public:
		GlyphTTF* createGlyphTTF(uint16_t char_index,int size);
		bool getFontMetrices(int size,FontMetrices* metrics);

		bool init(FsFile* file);
		bool setFontSize(int size);
		void destruct();

	private:
		int m_curSize;
		bool m_refFreeType;
		FsFile* m_source;
		FT_Stream m_stream;
		FT_Face m_face;
		FT_Open_Args m_args;
};

GlyphTTF* PlatfromFontTTF::createGlyphTTF(uint16_t char_index,int size)
{
	if(!setFontSize(size))
	{
		return NULL;
	}
	int error=FT_Load_Char(m_face,char_index,FT_LOAD_RENDER);
	if(error)
	{
		FS_TRACE_WARN("Load GlyphTTF(%d) Failed",char_index);
		return NULL;
	}
	GlyphTTF* ret=GlyphTTF::create(char_index,size);

	/* get glyph metrics */
	FT_Glyph_Metrics* metrics=&m_face->glyph->metrics;


	int minx=FT_FLOOR(metrics->horiBearingX);
	int maxx=minx+FT_CEIL(metrics->width);
	int maxy=FT_FLOOR(metrics->horiBearingY);
	int miny=maxy-FT_CEIL(metrics->height);
	int advance=FT_CEIL(metrics->horiAdvance);

	ret->setBound(minx,miny,maxx,maxy);
	ret->setAdvanceX(advance);



	FT_Bitmap* bitmap_src=&m_face->glyph->bitmap;
	int rows=bitmap_src->rows;
	int width=bitmap_src->width;

	if(rows==0||width==0)
	{
		return ret;
	}

	if(bitmap_src->pixel_mode!=FT_PIXEL_MODE_GRAY)
	{
		FS_TRACE_WARN("bitmap is not 8 bit gray");
		return ret;
	}
	Image2D* image=Image2D::create(width,rows,E_PixelFormat::RGBA8888);

	Color* data_dst=(Color*)image->getPixelData();
	uint8_t* data_src=bitmap_src->buffer;
	int pixel_nu=rows*width;
	for(int i=0;i<pixel_nu;i++)
	{
		Color* dst=data_dst+i;
		dst->r=255;
		dst->g=255;
		dst->b=255;
		dst->a=data_src[i];
	}

	ret->setImage(image);

	return ret;
}

bool PlatfromFontTTF::getFontMetrices(int size,FontMetrices* metrics)
{
	if(!setFontSize(size))
	{
		return false;
	}

	FT_Fixed scale;
	scale=m_face->size->metrics.y_scale;

	metrics->m_ascend=FT_CEIL(FT_MulFix(m_face->ascender,scale));
	metrics->m_descend=FT_CEIL(FT_MulFix(m_face->descender,scale));
	metrics->m_height=metrics->m_ascend-metrics->m_descend+1;
	return true;
}

PlatfromFontTTF::PlatfromFontTTF()
{
	m_curSize=-1;
	m_source=NULL;
	m_stream=NULL;
	m_face=NULL;
	m_refFreeType=false;
}
PlatfromFontTTF::~PlatfromFontTTF()
{
	if(m_face)
	{
		FT_Done_Face(m_face);
	}

	FS_SAFE_DEC_REF(m_source);

	if(m_stream)
	{
		free(m_stream);
	}
	if(m_refFreeType)
	{
		S_unRefFreeType();
	}
}


bool PlatfromFontTTF::init(FsFile* file)
{
	if(S_RefFreetype()<0)
	{
		return false;
	}

	m_refFreeType=true;

	FT_CharMap found=NULL;
	FT_Error error;
	m_stream=(FT_Stream)malloc(sizeof(*m_stream));
	memset(m_stream,0,sizeof(*m_stream));
	m_stream->read=S_fileRead;
	m_stream->descriptor.pointer=file;
	m_stream->pos=0;
	m_stream->size=file->getLength();

	m_args.flags=FT_OPEN_STREAM;
	m_args.stream=m_stream;

	error=FT_Open_Face(S_mLibrary,&m_args,0,&m_face);
	if(error)
	{
		FS_TRACE_WARN("Open FT_Face Failed");
		free(m_stream);
		m_stream=NULL;
		return false;
	}

	for(int i=0;i<m_face->num_charmaps;i++)
	{
		FT_CharMap charmap=m_face->charmaps[i];

		if ((charmap->platform_id == 3 && charmap->encoding_id == 1) /* Windows Unicode */
				||(charmap->platform_id == 3 && charmap->encoding_id == 0) /* Windows Symbol */
				||(charmap->platform_id == 2 && charmap->encoding_id == 1) /* ISO Unicode */
				||(charmap->platform_id == 0)) /* Apple Unicode */
		{ 
			found = charmap;
			break;
		}
	}
	if(found) 
	{
		FT_Set_Charmap(m_face,found);
	}

	FS_SAFE_ASSIGN(m_source,file);
	m_curSize=-1;
	return true;
}



bool PlatfromFontTTF::setFontSize(int size)
{
	if(m_curSize==size)
	{
		return true;
	}
	FT_Error error=FT_Set_Char_Size(m_face,0,size*64,0,0);
	if(error)
	{
		FS_TRACE_WARN("Can't Set Font Size(%d)",size);
		return false;
	}
	m_curSize=size;
	return true;
}


GlyphTTF* GlyphTTF::create(uint16_t c_id,uint16_t size)
{
	GlyphTTF* ret=new GlyphTTF(c_id,size);
	return ret;
}


GlyphTTF::GlyphTTF(uint16_t c_id,uint16_t size)
{
	m_char=c_id;
	m_size=size;
	m_minx=0;
	m_miny=0;
	m_maxx=0;
	m_maxy=0;
	m_advance=0;
	m_bitmap=NULL;
	m_texture=NULL;
	m_mgr=NULL;
}
uint16_t GlyphTTF::getChar()
{
	return m_char;
}
uint16_t GlyphTTF::getSize()
{
	return m_size;
}

void GlyphTTF::setBound(int minx,int miny,int maxx,int maxy)
{
	m_minx=minx;
	m_miny=miny;
	m_maxx=maxx;
	m_maxy=maxy;
}

void GlyphTTF::getBound(int* minx,int* miny,int* maxx,int* maxy)
{
	*minx=m_minx;
	*miny=m_miny;
	*maxx=m_maxx;
	*maxy=m_maxy;
}

int GlyphTTF::getAscend()
{
	FontMetrices metrics;
	m_mgr->getFontMetrices(m_size,&metrics);
	return metrics.m_ascend;
}

int GlyphTTF::getDescend()
{
	FontMetrices metrics;
	m_mgr->getFontMetrices(m_size,&metrics);
	return metrics.m_descend;
}

int GlyphTTF::getHeight()
{
	FontMetrices metrics;
	m_mgr->getFontMetrices(m_size,&metrics);
	return metrics.m_height;
}

void GlyphTTF::setAdvanceX(int advance) 
{
	m_advance=advance;
}

int GlyphTTF::getAdvanceX()
{
	return m_advance;
}


void GlyphTTF::setFont(FontTTF* font)
{
	m_mgr=font;
}

FontTTF* GlyphTTF::getFont()
{
	return m_mgr;
}




Image2D* GlyphTTF::getImage()
{
	return m_bitmap;
}

void GlyphTTF::setImage(Image2D* image)
{
	FS_SAFE_ASSIGN(m_bitmap,image);
}


Texture2D* GlyphTTF::getTexture()
{
	if(!m_texture)
	{
		if(m_bitmap)
		{
			m_texture=Texture2D::create(m_bitmap);
			FS_NO_REF_DESTROY(m_texture);
		}
	}

	return m_texture;
}

GlyphTTF::~GlyphTTF()
{
	if(m_mgr)
	{
		m_mgr->removeGlyphTTF(this);
		m_mgr=NULL;
	}

	FS_SAFE_DEC_REF(m_bitmap);
	FS_SAFE_DESTROY(m_texture);
}



/* ----- FontTTF ------ */

FontTTF* FontTTF::create(FsFile* file)
{
	FontTTF* ret=new FontTTF();
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}


GlyphTTF* FontTTF::getGlyphTTF(uint16_t char_index,int size)
{
	GlyphTTF* g=NULL;

	g=findFromCache(char_index,size);
	if(g)
	{
		return g;
	}

	g=findFromMgr(char_index,size);
	if(!g)
	{
		g=m_data->createGlyphTTF(char_index,size);
		if(g)
		{
			addToMgr(g);
		}
	}

	if(g)
	{
		addToCache(g);
	}

	return g;

}


void FontTTF::removeGlyphTTF(GlyphTTF* g)
{
	assert(findFromCache(g->getChar(),g->getSize())==NULL);
	m_glyphSet.erase(g);
}




bool FontTTF::getFontMetrices(int size,FontMetrices* metrics)
{
	return m_data->getFontMetrices(size,metrics);
}


const char* FontTTF::className()
{
	return FS_FONT_TTF_DATA_CLASS_NAME;
}

bool FontTTF::init(FsFile* file)
{
	m_data=new PlatfromFontTTF();
	return m_data->init(file);
}

FontTTF::FontTTF()
{
	m_data=NULL;
	for(int i=0;i<FS_FONT_GLYPH_CACHE_NU;i++)
	{
		m_caches[i]=NULL;
	}
}

void FontTTF::clearCache()
{
	for(int i=0;i<FS_FONT_GLYPH_CACHE_NU;i++)
	{
		GlyphTTF* g=m_caches[i];
		FS_SAFE_DEC_REF(g);
		m_caches[i]=NULL;
	}
}


void FontTTF::destruct()
{
	GlyphTTFSet::iterator iter;
	for(iter=m_glyphSet.begin();iter!=m_glyphSet.end();++iter)
	{
		(*iter)->setFont(NULL);
	}
	m_glyphSet.clear();

	clearCache();
	FS_SAFE_DELETE(m_data);
}


FontTTF::~FontTTF()
{
	destruct();
}


void FontTTF::addToMgr(GlyphTTF* g)
{
	g->setFont(this);

	m_glyphSet.insert(g);
}


void FontTTF::addToCache(GlyphTTF* g)
{
	uint32_t hash_code=getGlyphTTFHashCode(g);

	int index=hash_code%(FS_FONT_GLYPH_CACHE_NU-1);

	GlyphTTF* old=m_caches[index];
	m_caches[index]=g;


	FS_SAFE_DEC_REF(old);

	FS_SAFE_ADD_REF(g);


}

GlyphTTF* FontTTF::findFromCache(uint16_t char_index,uint16_t size)
{

	uint32_t hash_code=getGlyphTTFHashCode(char_index,size);
	int index=hash_code%(FS_FONT_GLYPH_CACHE_NU-1);

	GlyphTTF* g=m_caches[index];
	if(g)
	{
		if(g->getChar()==char_index&& g->getSize()==size)
		{
			return g;
		}
	}
	return NULL;

}


GlyphTTF* FontTTF::findFromMgr(uint16_t char_index, uint16_t size)
{
	GlyphTTF g(char_index,size);

	GlyphTTFSet::iterator iter=m_glyphSet.find(&g);

	if(iter!=m_glyphSet.end())
	{
		return  *iter;
	}

	return NULL;
}



GlyphTTF* FontTTF::createGlyphTTF(uint16_t char_index,uint16_t size)
{
	GlyphTTF* g=m_data->createGlyphTTF(char_index,size);
	return g;
}


uint32_t FontTTF::getGlyphTTFHashCode(GlyphTTF* g)
{
	uint32_t c_id=g->getChar();
	uint32_t size=g->getSize();
	return size<<16|c_id;
}

uint32_t FontTTF::getGlyphTTFHashCode(uint16_t c,uint16_t s)
{
	uint32_t c32=c;
	uint32_t s32=s;

	return s32<<16|c32;
}



NS_FS_END








