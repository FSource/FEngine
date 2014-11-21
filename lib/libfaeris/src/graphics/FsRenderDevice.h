#ifndef _FS_RENDER_DEVICE_H_
#define _FS_RENDER_DEVICE_H_

#include "FsMacros.h"
#include "FsConfig.h"
#include "graphics/FsColor.h"


#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE)
#include "platform/FsESRenderDevice.h"
#else 
#error "UnSupport Render"
#endif 

#endif 

