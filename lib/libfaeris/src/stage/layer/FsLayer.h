/*************************************************************************/
/*  FsLayer.h                                                            */
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


#ifndef _FS_LAYER_H_
#define _FS_LAYER_H_
#include <functional>
#include <vector>
#include "stage/animation/FsAnimator.h"
#include "math/FsRect2D.h"
#include "math/FsVector3.h"
#include "math/FsVector2.h"
#include "math/FsMatrix4.h"

NS_FS_BEGIN
class Scene;
class RenderDevice;
class FsDict;
class FsSlowDict;
class TouchEvent;
class Entity;

class Layer:public Animator 
{
	public:
		FS_CLASS_DECLARE(Layer);

	public:
		/* visible */
		bool getVisible(){return m_visible;}
		void setVisible(bool visible){m_visible=visible;}

		/* touch enable */
		bool touchEnabled(){return m_touchEnabled;}
		void setTouchEnabled(bool enable){m_touchEnabled=enable;}
		bool getTouchEnabled(){return m_touchEnabled;}
		void setTouchesEnabled(bool enable){m_touchesEnabled=enable;}
		bool getTouchesEnabled(){return m_touchesEnabled;}

		/* dispatch touch */
		void setDispatchTouchEnabled(bool enable){m_dispatchTouchEnabled=enable;}
		bool getDispatchTouchEnabled(){return m_dispatchTouchEnabled;}
		void setDispatchTouchesEnabled(bool enable){m_dispatchTouchesEnabled=enable;}
		bool getDispatchTouchesEnabled(){return m_dispatchTouchesEnabled;}

		/* scissor */
		void setScissorArea(float x,float y,float width,float height);
		void getScissorArea(float* x,float* y,float* width,float* height);
		bool scissorEnabled(){return m_scissorEnabled;}
		void setScissorEnabled(bool enable){m_scissorEnabled=enable;}


		/* scene */
		Scene* getScene();
		/* WARN: Please don't call this interface, it used for Scene 
		 *       When Layer add to Scene
		 */
		void setScene(Scene* scene);

	public:

		/* event hook */
		virtual void update(float dt);
		virtual void draw(RenderDevice* render)=0;

		/* touch event */
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);

		/* touches event */
		virtual bool touchesBegin(TouchEvent* event);
		virtual bool touchesPointerDown(TouchEvent* event);
		virtual bool touchesMove(TouchEvent* event);
		virtual bool touchesPointerUp(TouchEvent* event);
		virtual bool touchesEnd(TouchEvent* event);

		/* project matrix */
		virtual Matrix4 getProjectMatrix()=0;
		virtual Vector3 toLayerCoord(const Vector3& v);

		virtual void add(Entity* entity);
		virtual void remove(Entity* entity);
		virtual void clearEntity();

	public:
		std::function<void(Layer*,float)> onUpdate;
		std::function<void(Layer*,RenderDevice*)> onDraw;

		/* touch */
		std::function<bool(Layer*,float,float)> onTouchBegin;
		std::function<bool(Layer*,float,float)> onTouchMove;
		std::function<bool(Layer*,float,float)> onTouchEnd;

		/* touches */
		std::function<bool(Layer*,TouchEvent*)> onTouchesBegin;
		std::function<bool(Layer*,TouchEvent*)> onTouchesPointerDown;
		std::function<bool(Layer*,TouchEvent*)> onTouchesMove;
		std::function<bool(Layer*,TouchEvent*)> onTouchesPointerUp;
		std::function<bool(Layer*,TouchEvent*)> onTouchesEnd;

	public:
		void updateEntity(float dt);

	protected:
		Layer();
		virtual ~Layer();
		void init();
		void destruct();

	protected:
		bool m_visible;

		bool m_touchEnabled;
		bool m_touchesEnabled;

		bool m_dispatchTouchEnabled;
		bool m_dispatchTouchesEnabled;


		Rect2D m_scissorArea;
		bool m_scissorEnabled;
		Scene* m_scene;  /* weak ref */


		friend class Scene;

};
NS_FS_END

#endif /*_FS_LAYER_H_*/




