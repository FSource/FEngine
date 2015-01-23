/*************************************************************************/
/*  FsInputTextDispatcher.cc                                             */
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


#include "sys/event/FsInputTextDispatcher.h"

NS_FS_BEGIN

InputTextEventListener* InputTextEventListener::create()
{
	InputTextEventListener* ret=new InputTextEventListener();
	return ret;
}

InputTextEventListener::InputTextEventListener()
{
}

InputTextEventListener::~InputTextEventListener()
{
}


void InputTextEventListener::textInput(const char* text,int length)
{
}

const char* InputTextEventListener::className()
{
	return FS_INPUT_TEXT_EVENT_LISTENER_CLASS_NAME;
}


InputTextDispatcher* InputTextDispatcher::create()
{
	InputTextDispatcher* ret=new InputTextDispatcher();
	return ret;
}

const char* InputTextDispatcher::className()
{
	return FS_INPUT_TEXT_DISPATCHER_CLASS_NAME;
}


NS_FS_END

