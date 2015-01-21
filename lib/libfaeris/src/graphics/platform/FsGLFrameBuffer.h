#ifndef _FS_GL_FRAME_BUFFER_H_
#define _FS_GL_FRAME_BUFFER_H_

#include "graphics/FsTexture2D.h"

NS_FS_BEGIN



class FrameBuffer:public RenderTarget 
{
	public:
		static FrameBuffer* create(int width,int height);

	public:
		/* inherit RenderTarget */
		virtual void swapBuffers();
		virtual void makeCurrent(RenderDevice* render);
		virtual void loseCurrent(RenderDevice* render);

		/* inherit FsObject */
		virtual const char*  className();

	public:
		Texture2D* getColorTexture();

		int getWidth(){return m_width;}
		int getHeight(){return m_height;}

		void setSize(int width,int height);

	protected:
		FrameBuffer();
		virtual ~FrameBuffer();

		bool init(int width,int height);
		void destruct();


	private:
		Texture2D* m_colorTexture;
		uint32_t m_fboId;

		uint32_t m_depthBuffer;
		uint32_t m_stencilBuffer;

		int m_width;
		int m_height;
};

NS_FS_END


#endif /*_FS_GL_FRAME_BUFFER_H_*/

