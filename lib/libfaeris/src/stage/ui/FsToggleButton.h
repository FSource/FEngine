/*************************************************************************/
/*  FsToggleButton.h                                                     */
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


#ifndef _FS_TOGGLE_BUTTON_H_
#define _FS_TOGGLE_BUTTON_H_

#include <functional>
#include "FsMacros.h"
#include "FsStateButton.h"

NS_FS_BEGIN 

class ToggleButton:public StateButton 
{
	public:
		FS_CLASS_DECLARE(ToggleButton);

	public:
		enum 
		{
			STATE_ALL=-1,
			STATE_ON=0,
			STATE_OFF=1,
			STATE_DISABLE=2,
			STATE_NU=3,
		};

	public:
		static ToggleButton* create();
		static ToggleButton* createWithColorStyle(const char* filename,
											const Color4f& on,
											const Color4f& off);

		static ToggleButton* createWithColorStyle(Texture2D* tex,
												const Color4f& on,
												const Color4f& off);

		static ToggleButton* createWithTextureStyle(const char* fileon,const char* fileoff);
		static ToggleButton* createWithTextureStyle(Texture2D* on,Texture2D* off);

	public:
		/* inherit Entity*/
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;
		bool hit2D(float x,float y) FS_OVERRIDE;


	public:
		virtual void toggleChanged(bool value);

	public:
		std::function<void(ToggleButton*,bool)> onToggleChanged;


	public:
		void setDisabled(bool value);
		bool getDisabled() const;

		void setToggle(bool value,bool callback=false);
		bool getToggle() const;


	protected:
		ToggleButton();
		~ToggleButton();

		void initWithDarkStyle(const char* filename,const Color4f& dark);
		void initWithDarkStyle(Texture2D* tex,const Color4f& dark);


		void initWithColorStyle(const char* filename,const Color4f& on,const Color4f& off);
		void initWithColorStyle(Texture2D* tex,const Color4f& on,const Color4f& off);


		void initWithTextureStyle(const char* fileon,const char* fileoff);
		void initWithTextureStyle(Texture2D* on,Texture2D* off);

	protected:
		bool m_toggleState;
		bool m_disabled;

};



NS_FS_END 

#endif /*_FS_TOGGLE_BUTTON_H_*/


