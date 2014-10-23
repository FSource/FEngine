#ifndef _FS_LABLE_TTF_H_
#define _FS_LABLE_TTF_H_

#include <string>

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "graphics/FsTypoPage.h"
#include "graphics/FsFontTTF.h"
#include "stage/entity/FsIMaterial2DEntity.h"
#include "graphics/shader/FsProgram.h"

NS_FS_BEGIN
class Image2D;
class Texture2D;

class Material2D;
class Program;

class FontTTF;

class LabelTTF:public Entity,public IMaterial2DEntity
{
	public:
		static LabelTTF* create();
		static LabelTTF* create(const char* font,int size);
		static LabelTTF* create(const char* font,int size,const char* text);

	public:
		void setString(const char* string);
		const char* getString();

		void setFontName(const char* font);
		const char* getFontName();

		void setFontSize(int size);
		int getFontSize();


		void setTextAlign(int align);
		int getTextAlign();

		void setBoundSize(float width,float height);
		void getBoundSize(float* width,float* height);

		float getTextWidth();
		float getTextHeight();
		void getTextSize(float* width,float* height);

		void setLineGap(float line_gap);
		float getLineGap();

		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);


	public:
		/* inherit Entity */
		virtual void draw(RenderDevice* render,bool updateMatrix);
		virtual bool hit2D(float x,float y);


		/* inherit FsObject */
		virtual const char* className();
	protected:
		bool init();
		bool init(const char* font,int size);
		bool init(const char* font,int size,const char* text);

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

		int m_textAlign;
		
		float m_boundWidth,m_boundHeight;

		float m_anchorX,m_anchorY;

		float m_lineGap;


		FontTTF* m_font;

		/* compute result */
		float m_textWidth,m_textHeight;
		TypoPage<TypoText> m_typoPage;


};

NS_FS_END

#endif /*_FS_LABLE_TTF_H_*/















