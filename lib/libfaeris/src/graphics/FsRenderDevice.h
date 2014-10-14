#ifndef _FS_RENDER_H_
#define _FS_RENDER_H_

#include "FsMacros.h"
#include "FsConfig.h"


class Render;


class RenderState
{
	private:
		FsArray* m_ambientLights;
		FsArray* m_directionalLights;
		FsArray* m_pointLights;
		FsArray* m_spotLights;
		FsArray* m_hemiSphereLights;

		Fog* m_fog;

		/* render mode */
		bool m_wireFrame;

		/* face cull */
		bool m_doubleSize;

		/* depth */
		bool m_depthTest;
		bool m_depthWrite;

		/* blend */
		int m_blendEquation;
		int m_blendSrcFactor;
		int m_blendDstFactor;

		/* clear color */
		Color4f m_clearColor;

		/* viewport */
		int m_viewportX,m_viewportY,m_viewportWidth,m_viewportHeight;

		friend class Render;
};

class RenderConfig
{
	public:
		union
		{
			struct 
			{
				ulong m_supportShaodw:1;
				ulong m_supportAmbientLight:1;
				ulong m_supportDirectionalLight:1;
				ulong m_supportPointLight:1;
				ulong m_supportSpotLight:1;
				ulong m_supportHemiSphereLight:1;
				ulong m_supportFog:1;
			};
			ulong m_supportFlags;
		};


};


#if FS_CONFIG(FS_GLES_RENDER)
#include "platform/FsESRenderDevice.h"
#elif FS_CONFIG(FS_GL_RENDER)
#include "platform/FsGLRenderDevice.h"
#else 
#error "UnSupport Render"
#endif 

#endif 

