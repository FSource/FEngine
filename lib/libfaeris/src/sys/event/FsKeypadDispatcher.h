/*************************************************************************/
/*  FsKeypadDispatcher.h                                                 */
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


#ifndef _FS_KEYPAD_DISPATCHER_H_
#define _FS_KEYPAD_DISPATCHER_H_ 

#include "FsMacros.h"
#include "sys/event/FsTEventDispatcher.h"
#include "sys/FsKeyCode.h"

NS_FS_BEGIN
class KeypadEvent 
{
	public:
		enum 
		{
			KEYPAD_DOWN,
			KEYPAD_UP,
			KEYPAD_REPEAT

		};
	public:
		KeypadEvent(int _keycode,int _type)
		{
			keycode=_keycode;
			type=_type;
		}
	public:
		int keycode;
		int type;
};

class KeypadEventListener:public FsObject
{
	public:
		KeypadEventListener* create();

	protected:
		KeypadEventListener();
		virtual ~KeypadEventListener();
	public:
		void handleEvent(KeypadEvent* event)
		{
			onKeypadEvent(event->type,event->keycode);
		}

	public:
		virtual void onKeypadEvent(int type,int keycode);
		
		/* Override FsObject*/
		virtual const char* className();
};



class KeypadDispatcher:public TEventDispatcher<KeypadEvent,KeypadEventListener>
{
	public:

	public:
		static KeypadDispatcher* create();
		const char* className();

};




NS_FS_END 


#endif /*_FS_KEYPAD_DISPATCHER_H_*/

