#ifndef _FS_FILTER_H_
#define _FS_FILTER_H_

#include "FsMacros.h"
#include "FsObject.h"
#include "math/FsMatrix4.h"




NS_FS_BEGIN 

class RenderDevice;
class FrameBuffer;
class RenderTarget;
class Material2D;

#define FS_FILTER_MVP_CACHE_INDEX 0
#define FS_FILTER_TEXTURE0_CACHE_INDEX 1


class Filter:public FsObject 
{
	public:
		void begin(RenderDevice* rd,float left,float right,float bottom,float top);
		void end(RenderDevice* rd);

	public:
		virtual void apply(RenderDevice* rd,float left,float right,float bottom,float top);
		virtual void configRender(RenderDevice* rd);


	protected:
		Filter();
		~Filter();

	protected:
		FrameBuffer* m_frameBuffer;
		int m_width;
		int m_height;
		float m_precision;
		Material2D* m_material;

		/* render state cache */
		RenderTarget* m_oldRenderTarget;
		Matrix4 m_oldProjMat;

};

NS_FS_END 


#endif /*_FS_FILTER_H_*/

