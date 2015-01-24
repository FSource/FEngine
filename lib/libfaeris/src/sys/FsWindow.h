/*************************************************************************/
/*  FsWindow.h                                                           */
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


#ifndef _FAERIS_WINDOW_H_
#define _FAERIS_WINDOW_H_ 
#include <vector>
#include <string>

#include "FsMacros.h"
#include "graphics/FsRenderTarget.h"
#include "FsConfig.h"



NS_FS_BEGIN
class PlatformWindow;
class Window:public RenderTarget
{
	public:
		enum
		{
			STYLE_MAXBOX=0x1,
			STYLE_MINBOX=0x2,
			STYLE_CLOSEBOX=0x4,
		};

	public:
		static Window* create();
	public:
		/* inherit RenderTarget */
		virtual void makeCurrent(RenderDevice* r);
		virtual void loseCurrent(RenderDevice* r);
		virtual void swapBuffers();
		virtual void sizeChanged(uint width,uint height);
	public:
		void setCaption(const char* name);
		std::string getCaption(){return m_caption;}
		void setPosition(int x,int y);
		void setSize(uint width,uint height);
		void show();
		void hide();
		void setStyle(long flags);

		void setFullScreen(bool full);

		int getWidth();
		int getHeight();
		int getPosX();
		int getPosY();
		void setCenter();

	public:
		void openTextInputPad();

	public:
		virtual const char* className();

	protected:
		Window();
		virtual ~Window();
		bool init();

	public:
		PlatformWindow* getPlatformWindow(){return m_window;}

	private:
		RenderDevice* m_renderDevice;
		std::string m_caption;
		PlatformWindow* m_window;
};

NS_FS_END
#endif /*_FAERIS_WINDOW_H_*/















