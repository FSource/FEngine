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

