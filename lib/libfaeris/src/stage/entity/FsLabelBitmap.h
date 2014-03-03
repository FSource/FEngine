#ifndef _FS_LABEL_BITMAP_H_
#define _FS_LABEL_BITMAP_H_


#include <string>
#include <set>
#include <vector>

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "math/FsVertices.h"
#include "math/FsFace3.h"
#include "graphics/material/FsMat_V4F_T2F.h"


NS_FS_BEGIN
class FontBitmap;
class Texture2D;

class LabelBitmap:public Entity 
{

	public:
		static LabelBitmap* create();
		static LabelBitmap* create(const char* font);
		static LabelBitmap* create(const char* font,const char* text);
	public:

		void setFontName(const char* font);
		const char* getFontName();

		void setFontSize(float size);
		float getFontSize();


		void setString(const char* str);
		const char* getString();

		void setColor(Color c);
		Color getColor();

		void setOpacity(float opacity);
		float getOpacity();

		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);

		void getTextSize(float* width,float* height);
		float getTextWidth();
		float getTextHeight();


		void setTextAlign(int align);
		int getTextAlign();

		void setBoundSize(float width,float height);
		void getBoundSize(float* width,float* height);

	public:
		/* override Entity */
		virtual void draw(Render* r,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* override FsObject */
		virtual const char* className();



	protected:
		LabelBitmap();
		virtual ~LabelBitmap();
		bool init();
		void destruct();

	private:
		bool m_dirty;
		std::string m_text;
		uint16_t* m_utf16text;

		std::string m_fontName;
		float m_fontSize;

		int m_textAlign;

		float m_boundWidth,m_boundHeight;

		float m_anchorX,m_anchorY;
		float m_lineGap;

		Color m_color;
		float m_opacity;

		float m_textWidth,m_textHeight;

		FontBitmap* m_font;
		Texture2D* m_texture;

		Mat_V4F_T2F* m_material;
};


NS_FS_END 


#endif /*_FS_LABEL_BITMAP_H_*/




























