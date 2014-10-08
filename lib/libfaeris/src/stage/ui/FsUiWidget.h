#ifndef _FS_UI_WIDGET_H_
#define _FS_UI_WIDGET_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "math/FsVector2.h"

NS_FS_BEGIN
class Render;
class Texture2D;

class UiWidget:public Entity 
{
	public:
		static UiWidget* create(float width,float height);

	public:
		virtual const char* className();

		virtual bool hit2D(float x,float y);

		virtual void draws(Render* r,bool updateMatrix);
		virtual void draw(Render* r,bool updateMatrix);


	public:

		void setSize(float width,float height);
		Vector2 getSize();

		void getBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);
		void getRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);
		void getTRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);



		float getWidth();
		float getHeight();

		void setScissorEnabled(bool clip);
		bool getScissorEnabled();


		void setAnchor(float x,float y);
		float getAnchorX();
		float getAnchorY();
		Vector2 getAnchor();


		void setBgColor(const Color4f& c);
		void setBgTexture(Texture2D* tex);
		void setBgTexture(const char* filename);

		void setBgEnabled(bool value);

	public:
		virtual void removeWidget(UiWidget* widget);
		virtual void detach();
		virtual void layout();


	public:
		void setParentWidget(UiWidget* widget);
		UiWidget* getParentWidget();


	protected:
		UiWidget();
		virtual ~UiWidget();

		virtual void sizeChanged(float w,float h);
		virtual void anchorChanged(float x,float y);

		virtual void childSizeChanged(UiWidget* child,float w,float h);
		virtual void childAnchorChanged(UiWidget* child,float x,float y);


	protected:
		FS_FEATURE_WEAK_REF(UiWidget*) m_parentWidget;

		bool m_scissorEnabled;

		Vector2 m_size;
		Vector2 m_anchor;

		Color4f m_bgColor;
		Texture2D* m_bgTexture;
		bool m_bgEnabled;

};


NS_FS_END 



#endif /*_FS_UI_WIDGET_H_*/



