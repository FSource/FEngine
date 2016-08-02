/*************************************************************************/
/*  FsUiWidget.h                                                         */
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
class Filter;

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

		void setBgTextureUrl(const char* filename);
		const char* getBgTextureUrl();

		void setBgEnabled(bool value);
		bool getBgEnabled();

		void setFilter(Filter* filter);
		Filter* getFilter();



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

		Material2D* m_bgMaterial;
		Filter* m_filter;

		std::string m_bgTextureUrl;

};


NS_FS_END 



#endif /*_FS_UI_WIDGET_H_*/



