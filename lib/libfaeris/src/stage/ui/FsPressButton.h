/*************************************************************************/
/*  FsPressButton.h                                                      */
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


#ifndef _FS_PRESS_BUTTON_H_
#define _FS_PRESS_BUTTON_H_

#include <functional>
#include "FsMacros.h"


#include "stage/ui/FsStateButton.h"



NS_FS_BEGIN

class Program;
class Material2D;
class Texture2D;

class PressButton:public StateButton
{
	public:
		FS_CLASS_DECLARE(PressButton);

	public:
		enum{
			STATE_ALL=-1,
			STATE_NORMAL=0,
			STATE_PRESS=1,
			STATE_DISABLE=2,
			STATE_NU=3,
			STATE_UNKOWN=4,
		};


	public:
		static PressButton* create();
		static PressButton* createWithDarkStyle(const char* filename,const Color4f& dark);
		static PressButton* createWithDarkStyle(Texture2D* tex,const Color4f& dark);

		static PressButton* createWithColorStyle(const char* filename,const Color4f& normal,const Color4f& press);
		static PressButton* createWithColorStyle(Texture2D* tex,const Color4f& normal,const Color4f& press);

		static PressButton* createWithScaleStyle(const char* filename,const Vector3& scale);
		static PressButton* createWithScaleStyle(Texture2D* tex,const Vector3& scale);


	public:
		/* inherit Entity*/
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;
		bool hit2D(float x,float y) FS_OVERRIDE;



	public:
		virtual void pressDown(float x,float y);
		virtual void pressMoveIn(float x,float y);
		virtual void pressMoveOut(float x,float y);
		virtual void pressUp(float x,float y);

		virtual void cancel();
		virtual void click();


	public:

		std::function<void(PressButton*,float,float)> onPressDown;
		std::function<void(PressButton*,float,float)> onPressMoveIn;
		std::function<void(PressButton*,float,float)> onPressMoveOut;
		std::function<void (PressButton*,float,float)> onPressUp;
		std::function<void(PressButton*)> onCancel;
		std::function<void(PressButton*)> onClick;

	public:  
		void setDisabled(bool value);
		bool getDisabled() const;

	protected:
		PressButton();
		virtual ~PressButton();


		void initWithDarkStyle(const char* filename,const Color4f& dark);
		void initWithDarkStyle(Texture2D* texture,const Color4f& dark);

		void initWithColorStyle(const char* filename,const Color4f& normal,const Color4f& press);
		void initWithColorStyle(Texture2D* texture,const Color4f& normal,const Color4f& press);

		void initWithScaleStyle(const char* filename,const Vector3& scale);
		void initWithScaleStyle(Texture2D* texture,const Vector3& scale);


	protected:
		/* bool focus */
		bool m_moveIn;
		bool m_disabled;

};


NS_FS_END

#endif /*_FS_PRESS_BUTTON_H_*/

















