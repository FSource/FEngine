/*************************************************************************/
/*  FsFontTTF.h                                                          */
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


#ifndef _FS_FONT_TTF_H_
#define _FS_FONT_TTF_H_
#include <set>
#include "FsMacros.h"
#include "mgr/FsResource.h"
#include "graphics/FsTypoPage.h"

#define FS_FONT_GLYPH_CACHE_NU 256

NS_FS_BEGIN

class Texture2D;
class Image2D;
class FsFile;
class FontTTF;

class FontMetrices 
{
	public:
		int m_ascend;
		int m_descend;
		int m_height;

	public:
		FontMetrices()
			:m_ascend(0),
			m_descend(0),
			m_height(0)
		{ }
};


class GlyphTTF:public TypoGlyph 
{
	public:
		static GlyphTTF* create(uint16_t c,uint16_t size);

	public:
		void getBound(int* minx,int* miny,int* maxx,int* maxy) FS_OVERRIDE;
		void setBound(int minx,int miny,int maxx,int maxy);

		void setAdvanceX(int advance);
		int getAdvanceX() FS_OVERRIDE;

		int getAscend() FS_OVERRIDE;
		int getDescend() FS_OVERRIDE;
		int getHeight() FS_OVERRIDE;


		uint16_t getChar() FS_OVERRIDE;
		uint16_t getSize() ;

		Image2D* getImage();
		void setImage(Image2D* image);

		Texture2D* getTexture();

		void setFont(FontTTF* data);
		FontTTF* getFont();

	protected:
		GlyphTTF(uint16_t c,uint16_t size);
		~GlyphTTF();

	private:
		/* size and char used for compare */
		uint16_t m_char;
		uint16_t m_size;

		/* glyph metrics */
		int m_minx;
		int m_miny;
		int m_maxx;
		int m_maxy;
		int m_advance;


		/* gray bit */
		Image2D* m_bitmap;
		Texture2D* m_texture;

		FS_FEATURE_WEAK_REF(FontTTF*) m_mgr;

		friend class FontTTF;
};


class PlatfromFontTTF;
class FontTTF:public Resource
{
	public:
		class GlyphTTFCompare
		{
			public:
				bool operator()(GlyphTTF* l,GlyphTTF* r)
				{
					if(l->getSize()<r->getSize())
					{
						return true;
					}
					else if (l->getSize()==r->getSize())
					{	
						if(l->getChar()<r->getChar())
						{
							return true;
						}
					}
					return false;
				}
		};
		typedef std::set<GlyphTTF*,GlyphTTFCompare> GlyphTTFSet;

	public:
		static FontTTF* create(FsFile* file);

	public:
		GlyphTTF* getGlyphTTF(uint16_t char_index,int size);
		bool getFontMetrices(int size,FontMetrices* metrics);
		void clearCache();


		/* WARN: Please Don't Call It, This Interface Used To Remove GlyphTTF,
		 * 		 When GlyphTTF Destory.
		 */
		void removeGlyphTTF(GlyphTTF* g);

	public:
		virtual const char* className();

	protected:
		FontTTF();
		~FontTTF();

		bool init(FsFile* file);
		void destruct();

		void addToMgr(GlyphTTF* g);
		void addToCache(GlyphTTF* g);

		GlyphTTF* findFromCache(uint16_t char_index,uint16_t size);
		GlyphTTF* findFromMgr(uint16_t char_index,uint16_t size);
		GlyphTTF* createGlyphTTF(uint16_t char_index,uint16_t size);

		uint32_t getGlyphTTFHashCode(GlyphTTF* g);
		uint32_t getGlyphTTFHashCode(uint16_t char_index,uint16_t size);

	private:
		PlatfromFontTTF* m_data;
		GlyphTTFSet m_glyphSet;
		GlyphTTF* m_caches[FS_FONT_GLYPH_CACHE_NU];
};


NS_FS_END

#endif /*_FS_FONT_TTF_H_*/











