#ifndef _FS_SCENE_H_
#define _FS_SCENE_H_

#include "FsMacros.h"
#include "stage/FsActionTarget.h"
#include "graphics/FsColor.h"



NS_FS_BEGIN
class Render;
class Layer;
class FsSlowArray;
class Vector2;
class TouchEvent;
class ObjectMgr;


class Scene:public ActionTarget
{
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
		void setEnabledFade(bool fade);
		void setFadeColor(Color c);

	public:

		/* event hook */
		virtual void enter();
		virtual void exit();
		virtual void update(float dt);
		virtual void draw(Render* render);

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

		/*  inherit FsObject */
		virtual const char* className();

	public:
		void updateLayers(float dt);


	protected:
		Scene();
		~Scene();
		void init();
		void destruct();

	private:
		FsSlowArray* m_layers;

		Color m_fadeColor;
		bool m_fadeEnabled;

		FS_FEATURE_WEAK_REF(Layer*) m_touchFocusLayer;
};

NS_FS_END
#endif /*_FS_SCENE_H_ */











