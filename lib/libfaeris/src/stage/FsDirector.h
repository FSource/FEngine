/*************************************************************************/
/*  FsDirector.h                                                         */
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


#ifndef _FS_DIRECTOR_H_
#define _FS_DIRECTOR_H_
#include "FsMacros.h"
#include "scheduler/FsSchedulerTarget.h"

NS_FS_BEGIN
class Scene;
class DirectorTouchEventListener;
class DirectorKeypadEventListener;
class DirectorInputTextEventListener;

class FsArray;
class RenderDevice;
class TouchEvent;

class Director :public SchedulerTarget
{
	public:
		static Director* create();

	public:
		/* inherit FsObject */
		virtual const char* className();

		/* inherit SchedulerTarget */
		virtual void update(int priority,float dt);

	public:
		void push();
		void push(Scene* scene);

		void pop();

		void run(Scene*  scene);

		Scene* current();

		void pause();
		void start();

		bool isRunning();
		void setAutoSwapBuffers(bool swap);

	public: 

	protected:
		Director();
		~Director();
		void init();
		void destruct();
		void repace(Scene* scene);

		void updateScene(float dt);
		void drawScene();
		void swapBuffers();


		void touchBegin(float x,float y);
		void touchMove(float x,float y);
		void touchEnd(float x,float y);
		void touchesBegin(TouchEvent* event);
		void touchesPointerDown(TouchEvent* event);
		void touchesMove(TouchEvent* event);
		void touchesPointerUp(TouchEvent* event);
		void touchesEnd(TouchEvent* event);

		void keypadEvent(int type,int keycode);

		void inputTextEvent(const char* text,int length);

	private:
		Scene* m_current;

		Scene* m_next;

		bool m_sceneChange;

		FsArray* m_secenQueue;

		bool m_stop;
		bool m_autoSwapBuffers;

		DirectorTouchEventListener* m_touchEventListener;
		DirectorKeypadEventListener* m_keypadEventListener;
		DirectorInputTextEventListener* m_inputTextEventListener;

		friend class DirectorTouchEventListener;
		friend class DirectorKeypadEventListener;
		friend class DirectorInputTextEventListener;

};


NS_FS_END 

#endif /*_FS_DIRECTOR_H_*/

