/*************************************************************************/
/*  FsInputTextDispatcher.h                                              */
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


#ifndef _FS_INPUT_TEXT_DISPATCHER_H_
#define _FS_INPUT_TEXT_DISPATCHER_H_

#include <string>

#include "FsMacros.h"
#include "sys/event/FsTEventDispatcher.h"

NS_FS_BEGIN

class InputTextEvent 
{
	public:
		InputTextEvent(const char* text)
		{
			m_text=std::string(text);
		}

		~InputTextEvent(){}

	public:
		const char* getText(){return m_text.c_str();}
		int getTextLength(){return m_text.length();}

	private:
		std::string m_text;
};

class InputTextEventListener:public FsObject 
{
	public:
		static InputTextEventListener*  create();

	protected:
		InputTextEventListener();
		virtual ~InputTextEventListener();
		

	public:
		void handleEvent(InputTextEvent* event)
		{
			textInput(event->getText(),event->getTextLength());
		}
	public:
		virtual void textInput(const char* text,int length);

	public:
		virtual const char* className();
};



class InputTextDispatcher:public TEventDispatcher<InputTextEvent,InputTextEventListener> 
{
	public:
		static InputTextDispatcher* create();

	public:
		/* override FsObject */
		const char* className();
};

NS_FS_END

#endif /*_FS_INPUT_TEXT_DISPATCHER_H_*/

