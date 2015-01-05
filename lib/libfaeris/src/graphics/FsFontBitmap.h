#ifndef _FS_FONT_BITMAP_H_
#define _FS_FONT_BITMAP_H_

#include <map>
#include "FsMacros.h"
#include "mgr/FsResource.h"

#include "graphics/FsTypoPage.h"


NS_FS_BEGIN

class FsDict;
class FsArray;
class FsFile;
class Texture2D;
class FontBitmap;

class GlyphBitmap:public TypoGlyph
{
	public:
		static GlyphBitmap* create();


	public:
		void getBound(int* minx,int* miny,int* maxx,int* maxy) FS_OVERRIDE;
		int getAdvanceX() FS_OVERRIDE;
		int getAscend() FS_OVERRIDE;
		int getDescend() FS_OVERRIDE;
		int getHeight() FS_OVERRIDE;
		uint16_t getChar() FS_OVERRIDE;

	public:
		void setFont(FontBitmap* font);
		FontBitmap* getFont();


	protected:
		GlyphBitmap();

	public:
		uint16_t m_char;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		int m_xoffset;
		int m_yoffset;
		int m_xadvance;
		int m_page;

		/* info cache */
		int m_minx;
		int m_miny;
		int m_maxx;
		int m_maxy;

		float m_ulb,m_vlb;
		float m_urb,m_vrb;
		float m_urt,m_vrt;
		float m_ult,m_vlt;

		FS_FEATURE_WEAK_REF(FontBitmap*) m_font;

		friend class FontBitmap;
};

class FontBitmap:public Resource
{
	public:
		class GlyphSet 
		{
			public:
				GlyphSet();
				~GlyphSet();
			public:
				void insert(int key,GlyphBitmap* g);
				GlyphBitmap* find(int key);

			private:
				std::map<int,GlyphBitmap*> m_values;
		};

	public:
		static FontBitmap* create(FsFile* file);

	public:
		GlyphBitmap* getGlyph(uint16_t char_index);


		Texture2D* getTexture(int index);

		int getHeight(){return m_height;}
		int getAscent(){return m_ascent;}
		int getDescent(){return m_descent;}

		int getTextureWidth(){return m_textureWidth;}
		int getTextureHeight(){return m_textureHeight;}

	public:
		/* override FsObject */
		virtual const char* className();

	protected:
		FontBitmap();
		virtual ~FontBitmap();

		bool init(FsFile* file);
		void destruct();

	private:
		GlyphSet* m_glyphs;

		int m_textureWidth;
		int m_textureHeight;

		int m_descent;
		int m_ascent;
		int m_height;

		FsArray* m_textures;
};



NS_FS_END 
#endif 



