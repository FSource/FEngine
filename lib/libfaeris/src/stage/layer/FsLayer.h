#ifndef _FS_LAYER_H_
#define _FS_LAYER_H_
#include <vector>
#include "stage/FsActionTarget.h"
#include "math/FsRect2D.h"
#include "math/FsVector3.h"



NS_FS_BEGIN
class Scene;
class Render;
class FsDict;
class FsSlowDict;
class Vector2;
class TouchEvent;
class Entity;

class Layer:public ActionTarget
{
	public:
		/* visible */
		bool getVisible(){return m_visible;}
		void setVisible(bool visible){m_visible=visible;}

		/* touch enable */
		bool touchEnabled(){return m_touchEnabled;}
		void setTouchEnabled(bool enable){m_touchEnabled=enable;}
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
		virtual void draw(Render* render)=0;

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


		/* inherit FsObject */
		virtual const char* className();

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




