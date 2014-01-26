#ifndef _FS_LABLE_TTF_H_
#define _FS_LABLE_TTF_H_

#include <string>

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "graphics/FsTypoPage.h"

NS_FS_BEGIN
class Image2D;
class Texture2D;
class Mat_V4F_T2F;
class FontTTF;

class LabelTTF:public Entity
{
	public:
		static LabelTTF* creat();
		static LabelTTF* create(const char* font,int size);
		static LabelTTF* create(const char* font,int size,const char* text);

	public:
		void setString(const char* string);
		const char* getString();

		void setFontName(const char* font);
		const char* getFontName();

		void setFontSize(int size);
		int getFontSize();


		void setTextAlign(int h,int v);
		void getTextAlign(int* h,int *v);

		void setSize(float width,float height);
		void getSize(float* width;float* height);
		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);


		void setColor(Color c);
		Color getColor();

		void setOpacity(float opacity);
		float getOpacity();


	public:
		/* inherit Entity */
		virtual void draw(Render* render,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className();
	protected:
		bool init();
		bool init(const char* font,int size);
		bool init(const char* font,int size,char* text);

		void destruct();

		LabelTTF();
		virtual ~LabelTTF();

		void typoText();
		void realignText();
		void clearTextLine();


	private:
		bool m_dirty;
		std::string m_text;
		uint16_t* m_utf16text;

		std::string m_fontName;
		int m_fontSize;

		int m_alignv,m_alignh;
		
		float m_width,m_height;
		float m_anchorX,m_anchorY;

		Color m_color;
		float m_opacity;

		FontTTF* m_font;
		Mat_V4F_T2F* m_material;

		/* compute result */
		float m_textWidth,m_textHeight;
		FsTypoPage<void> m_typoPage;
};

NS_FS_END

#endif /*_FS_LABLE_TTF_H_*/















