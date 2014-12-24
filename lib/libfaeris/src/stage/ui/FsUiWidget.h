#ifndef _FS_UI_WIDGET_H_
#define _FS_UI_WIDGET_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
#include "graphics/FsColor.h"
#include "math/FsVector2.h"

#include "graphics/material/FsMaterial2D.h"

NS_FS_BEGIN
class RenderDevice;
class Texture2D;

class UiWidget:public Entity2D
{
	public:
		FS_CLASS_DECLARE(UiWidget);

	public:
		static UiWidget* create(float width,float height);
		static UiWidget* create();

	public:


		void draws(RenderDevice* r,bool updateMatrix) FS_OVERRIDE;
		void draw(RenderDevice* r,bool updateMatrix) FS_OVERRIDE;

		using Entity2D::setSize;
		void setSize(const Vector2& v) FS_OVERRIDE;

		using Entity2D::setAnchor;
		void setAnchor(const Vector2& v) FS_OVERRIDE;

		using Entity2D::setPosition;
		void setPosition(const Vector3f& v ) FS_OVERRIDE;

		using Entity2D::setRotate;
		void setRotate(const Vector3f& v) FS_OVERRIDE;

		using Entity2D::setScale;
		void setScale(const Vector3f& v) FS_OVERRIDE;

		void addChild(Entity* en) FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;
		void detach() FS_OVERRIDE;


	public:
		void getBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);
		void getRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);
		void getTRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);


		void setScissorEnabled(bool clip);
		bool getScissorEnabled();

		void setListenChildTSAEnabled(bool value) 
		{ 
			m_listenChildTSAEnabled =value;
		}

		bool getListenChildTSAEnabled()
		{
			return m_listenChildTSAEnabled;
		}

		void setSignalTSAEnabled(bool value)
		{
			m_signalParentTSAEnabled=value;
		}
		bool getSignalTSAEnabled()
		{
			return m_signalParentTSAEnabled;
		}

		void setBgColor(const Color4f& c);
		Color4f getBgColor();
		void setBgTexture(Texture2D* tex);
		void setBgTexture(const char* filename);
		void setBgEnabled(bool value);
		bool getBgEnabled();



	public:
		void setParentWidget(UiWidget* widget);
		UiWidget* getParentWidget();


	protected:
		UiWidget();
		virtual ~UiWidget();

		virtual void childTransformChanged(UiWidget* child);
		virtual void childSizeChanged(UiWidget* child);
		virtual void childAnchorChanged(UiWidget* child);

	protected:
		FS_FEATURE_WEAK_REF(UiWidget*) m_parentWidget;

		bool m_scissorEnabled;
		bool m_bgEnabled;
		bool m_listenChildTSAEnabled;
		bool m_signalParentTSAEnabled;
};


NS_FS_END 



#endif /*_FS_UI_WIDGET_H_*/



