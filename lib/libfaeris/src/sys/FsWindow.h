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















