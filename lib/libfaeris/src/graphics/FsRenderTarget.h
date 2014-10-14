#ifndef _FAERIS_RENDER_TARGET_H_
#define _FAERIS_RENDER_TARGET_H_
#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class RenderDevice;
class RenderTarget:public FsObject
{
	public:
		virtual void swapBuffers()=0;
		virtual void makeCurrent(RenderDevice*)=0;
		virtual void loseCurrent(RenderDevice*)=0;
};
NS_FS_END
#endif /*_FAERIS_RENDER_TARGET_H_*/

