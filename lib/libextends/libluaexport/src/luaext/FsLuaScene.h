#ifndef _FS_LUA_SCENE_H_
#define _FS_LUA_SCENE_H_ 

#include <string.h>
#include "stage/FsScene.h"
#include "FsLuaMacros.h"
NS_FS_BEGIN
class LuaScene:public Scene 
{
	public:
		static LuaScene* create();
	public:
		/* inherit Scene */
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
		virtual void inputTextEvent(const char* value,int length);



	public:
		void onEnter() { Scene::enter(); }

		void onExit(){Scene::exit();}
		void onUpdate(float dt){Scene::update(dt);}
		void onDraw(RenderDevice* render){Scene::draw(render);}

		void onTouchBegin(float x,float y){Scene::touchBegin(x,y);}
		void onTouchEnd(float x,float y){Scene::touchEnd(x,y);}
		void onTouchMove(float x,float y){Scene::touchMove(x,y);}
		void onTouchesBegin(TouchEvent* event){Scene::touchesBegin(event);}

		void onTouchesPointerDown(TouchEvent* event)
		{
			Scene::touchesPointerDown(event);
		}
		void onTouchesMove(TouchEvent* event)
		{
			Scene::touchesMove(event);
		}
		void onTouchesPointerUp(TouchEvent* event)
		{
			Scene::touchesPointerUp( event);
		}
		void onTouchesEnd(TouchEvent* event)
		{
			Scene::touchesEnd(event);
		}
		void onKeypadEvent(int type,int keycode)
		{
			Scene::keypadEvent(type,keycode);
		}

		void onInputTextEvent(const char* value)
		{
			Scene::inputTextEvent(value,strlen(value));
		}


		/* inherit FsObject */
		virtual const char* className();

	protected:
		LuaScene();
		~LuaScene();
};
NS_FS_END
#endif /*_LUA_SCENE_H_*/

