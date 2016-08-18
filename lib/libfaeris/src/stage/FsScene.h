/*************************************************************************/
/*  FsScene.h                                                            */
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


#ifndef _FS_SCENE_H_
#define _FS_SCENE_H_

#include <functional>

#include "FsMacros.h"
#include "stage/animation/FsAnimator.h"
#include "graphics/FsColor.h"




NS_FS_BEGIN
class RenderDevice;
class Layer;
class FsSlowArray;
class TouchEvent;
class ObjectMgr;
class ColorLayer;


class Scene:public Animator 
{
	public:
		FS_CLASS_DECLARE(Scene);

	public:
		static Scene* create();

	public:
		/* layer operation */
		void push(Layer* layer);
		void pop();
		void insert(int pos,Layer*  layer);
		void replace(int pos,Layer* layer);
		void remove(Layer* layer);
		int layerNu();
		Layer* top();
		Layer* getLayer(int index);
		int getLayerIndex(Layer* layer);
		void clear();

		/* fade */
		void setFadeEnabled(bool fade);
		bool getFadeEnabled();
		void setFadeColor(Color c);

		void setTouchEnabled(bool enabled);
		bool getTouchEnabled();

		void setTouchesEnabled(bool enabled);
		bool getTouchesEnabled();
		

	public:

		/* event hook */
		virtual void enter();
		virtual void exit();
		virtual void update(float dt);
		virtual void draw(RenderDevice* render);

		virtual void touchBegin(float x,float y);
		virtual void touchMove(float x,float y);
		virtual void touchEnd(float x,float y);

		virtual void touchesBegin(TouchEvent* event);
		virtual void touchesPointerDown(TouchEvent* event);
		virtual void touchesMove(TouchEvent* event);
		virtual void touchesPointerUp(TouchEvent* event);
		virtual void touchesEnd(TouchEvent* event);

		virtual void keypadEvent(int type,int keycode);

		virtual void inputTextEvent(const char* text,int length);


	public:
		std::function<void(Scene*)> onEnter;
		std::function<void(Scene*)> onExit;
		std::function<void(Scene*,float)> onUpdate;
		std::function<void(Scene*,RenderDevice*)> onDraw;

		std::function<void(Scene*,float,float)> onTouchBegin;
		std::function<void(Scene*,float,float)> onTouchMove;
		std::function<void(Scene*,float,float)> onTouchEnd;

		std::function<void(Scene*,TouchEvent*)> onTouchesBegin;
		std::function<void(Scene*,TouchEvent*)> onTouchesPointerDown;
		std::function<void(Scene*,TouchEvent*)> onTouchesMove;
		std::function<void(Scene*,TouchEvent*)> onTouchesPointerUp;
		std::function<void(Scene*,TouchEvent*)> onTouchesEnd;
		std::function<void(Scene*,int ,int)> 	onKeypadEvent;
		std::function<void(Scene*,const char* text,int length)> onInputTextEvent;



	public:
		void updateLayers(float dt);

	protected:
		Scene();
		~Scene();
		void init();
		void destruct();

	private:
		FsSlowArray* m_layers;

		Color4f m_fadeColor;
		bool m_fadeEnabled;
		ColorLayer* m_fadeLayer;

		bool m_touchEnabled;
		bool m_touchesEnabled;

		FS_FEATURE_WEAK_REF(Layer*) m_touchFocusLayer;
};

NS_FS_END
#endif /*_FS_SCENE_H_ */











