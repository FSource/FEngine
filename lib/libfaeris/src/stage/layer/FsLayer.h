#ifndef _FS_LAYER_H_
#define _FS_LAYER_H_
#include <vector>
#include "stage/FsActionTarget.h"
#include "math/FsRect2D.h"
#include "math/FsVector3.h"
#include "math/FsVector2.h"
#include "math/FsMatrix4.h"

NS_FS_BEGIN
class Entity;
class Scene;
class Render;
class FsDict;
class FsSlowDict;
class TouchEvent;
class Scene;

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


		/* project matrix */
		virtual Matrix4 getProjectMatrix()=0;
		virtual Vector3 toLayerCoord(const Vector3& v);


		/* entity */
		void add(Entity* entity);
		void remove(Entity* entity);
		void clearEntity();
		int getEntityNu();
		



		/* scene */
		Scene* getScene();

		/* WARN: Please don't call this interface, it used for Scene 
		 *       When Layer add to Scene
		 */
		void setScene(Scene* scene);
	public:
		/* event hook */
		virtual void update(float dt);
		virtual void draw(Render* render);

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



		/* inherit FsObject */
		virtual const char* className();

	public:
		void updateEntity(float dt);

	protected:
		Layer();
		virtual ~Layer();
		void init();
		void destruct();
		void updateAllWorldMatrix();

		void getTouchEnabledEntity(std::vector<Entity*>* e);
		void sortEntity(std::vector<Entity*>* e);


	protected:
		FsSlowDict* m_entity;  /* direct add to layer */
		bool m_visible;

		bool m_touchEnabled;
		bool m_touchesEnabled;

		bool m_dispatchTouchEnabled;
		bool m_dispatchTouchesEnabled;


		Entity* m_touchFocus;



		Rect2D m_scissorArea;
		bool m_scissorEnabled;

		Scene* m_scene;  /* weak ref */

		uint32_t m_addOlder;

		friend class Scene;

};
NS_FS_END

#endif /*_FS_LAYER_H_*/
