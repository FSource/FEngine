#ifndef _FAERIS_BUTTON_H_
#define _FAERIS_BUTTON_H_ 

#include "FsMacros.h"
#include "stage/entity/FsQuad2D.h"
#include "support/util/FsArray.h"
#include "graphics/FsTexture2D.h"
#include "FsGlobal.h"







NS_FS_BEGIN 

class Button;
class ButtonState 
{


	public:
		ButtonState()
		{
			m_color=Color::WHITE;
			m_opacity=1.0;
			m_texture=NULL;
			m_width=0;
			m_height=0;
			m_anchorX=0.5;
			m_anchorY=0.5;
			m_translate.set(0,0,0);
			m_rotate.set(0,0,0);
			m_scale.set(1,1,1);
			m_children=NULL;
			m_flags=0;
		}
		~ButtonState()
		{
			FS_SAFE_DEC_REF(m_texture);
			FS_SAFE_DEC_REF(m_children);
		}



	public:
		void setFlag(uint32_t flags) { m_flags=m_flags|flags; }
		void clearFlag(uint32_t flags) {m_flags=m_flags&(~flags);}

		void setColor(Color c) {m_color=c;}
		Color getColor(){return m_color;}

		void setOpacity(float opacity){m_opacity=opacity;}
		float getOpacity(){return m_opacity;}

		void setTexture(const char* filename)
		{
			Texture2D* tex=Global::textureMgr()->loadTexture(filename);
			FS_SAFE_ASSIGN(m_texture,tex);
		}
		void setTexture(Texture2D* tex) { FS_SAFE_ASSIGN(m_texture,tex); }
		Texture2D* getTexture() { return m_texture;} 

		void setSize(float width,float height){m_width=width;m_height=height;}
		void getSize(float* width,float* height){*width=m_width;*height=m_height;}

		void setAnchor(float x,float y){m_anchorX=x;m_anchorY=y;}
		void getAnchor(float* x,float* y){*x=m_anchorY;*y=m_anchorY;}

		void setPosition(Vector3 t){m_translate=t;}
		Vector3 getPosition(){return m_translate;}

		void setRotate(Vector3 r){m_rotate=r;}
		Vector3 getRotate(){return m_rotate;}

		void setScale(Vector3 s){m_scale=s;}
		Vector3 getScale(){return m_scale;}

		void setZorder(float orlder){m_zorder=orlder;}
		float getZorder(){return m_zorder;}

		void setChild(FsArray* child){FS_SAFE_ASSIGN(m_children,child);}
		FsArray* getChild(){return m_children;}


	private:
		uint32_t m_flags;
		Color m_color;
		float m_opacity;
		Texture2D* m_texture;
		float m_width,m_height;
		float m_anchorX,m_anchorY;
		Vector3 m_translate;
		Vector3 m_rotate;
		Vector3 m_scale;
		float m_zorder;
		FsArray* m_children;

		friend class Button;
};

class Button:public Quad2D
{
	public:
		enum 
		{
			FLAG_COLOR= 0x1UL,
			FLAG_OPACITY= 0x2UL,
			FLAG_TEXTURE= 0x4UL,
			FLAG_SIZE=0x8UL,
			FLAG_ANCHOR =0x10UL,
			FLAG_TRANSLATE=0x20UL,
			FLAG_ROTATE=0x40UL,
			FLAG_SCALE=0x80UL,
			FLAG_ZORDER=0x100UL,
			FLAG_CHILDREN=0x200UL,
			FLAG_ALL= 0x3FFUL,
		};

	public:
		static Button* create();
		static Button* create(const char* filename);
		static Button* create(const char* filename,float width,float height);

	public:
		ButtonState* getNormalState();
		ButtonState* getPressState();

	public:
		virtual void click();

		virtual void pressDown(float x,float y);
		virtual void pressMoveIn(float x,float y);
		virtual void pressMoveOut(float x,float y);
		virtual void pressUp(float x,float y);
		virtual void pressCancel(float x,float y);


		void setStateNormal();
		void setStatePress();


	public:
		/* inherit Entity*/
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		Button();
		~Button();
		void setState(ButtonState* state);

	protected:
		ButtonState* m_normalState;
		ButtonState* m_pressState;
		bool m_moveIn;

		
};


NS_FS_END

#endif /*_FAERIS_BUTTON_H_ */














