#ifndef _FS_TEXTURE_2D_H_
#define _FS_TEXTURE_2D_H_ 

#include "FsMacros.h"
#include "FsConfig.h"
#include "mgr/FsResourceMgr.h"
#include "mgr/FsResource.h"
#include "sys/io/FsFile.h"
#include "graphics/FsImage2D.h"

#if FS_CONFIG(FS_GL_RENDER) ||FS_CONFIG(FS_GLES_RENDER)
	typedef uint PlatformTexture;
#else 
	#error "Unsupport PlatformTexture"
#endif 



NS_FS_BEGIN 
class Texture2D:public Resource
{
	public:
		static Texture2D* create(
				Image2D* image,
				E_TextureFilter filter_mag,
				E_TextureFilter filter_min,
				E_TextureWrap wraps,
				E_TextureWrap wrapt);
		
		static Texture2D* create(E_PixelFormat format,int width,int height,void* data,
								 E_TextureFilter filter_mag,E_TextureFilter filter_min,
								 E_TextureWrap wraps,E_TextureWrap wrapt);


		/* for quick create texture from image */
		static Texture2D* create(Image2D* image);
		static Texture2D* create(const char* filename);

	public:

		/* fileter */
		void setFilter(E_TextureFilter mag,E_TextureFilter min,E_TextureFilter mip=E_TextureFilter::LINEAR);
		E_TextureFilter getFilterMin(){return m_filterMin;}
		E_TextureFilter getFilterMag(){return m_filterMag;}
		E_TextureFilter getFilterMipmap(){return m_filterMipmap;}

		/* wrap */
		void setWrap(E_TextureWrap wraps,E_TextureWrap wrapt);
		E_TextureWrap getWrapS(){return m_wrapS;}
		E_TextureWrap getWrapT(){return m_wrapT;}

		/* format */
		E_PixelFormat getFormat(){return m_format;}

		/* height,and width */
		uint getWidth(){return m_width;}
		uint getHeight(){return m_height;}

		/* mipmap */
		bool enableMipmap();
		PlatformTexture getPlatformTexture(){return m_platformTexture;}

		void markInvaild();
		void setResourceUrl(const char* name);

	public:
		virtual const char* className();
	

	protected:
		Texture2D();
		virtual ~Texture2D();

		bool init(Image2D* image,E_TextureFilter filter_mag,E_TextureFilter filter_min,E_TextureWrap wraps,E_TextureWrap wrapt);
		bool init(E_PixelFormat format,int width,int height,void* data,
								 E_TextureFilter filter_mag,E_TextureFilter filter_min,
								 E_TextureWrap wraps,E_TextureWrap wrapt);

		bool init(Image2D* image);
		bool init(const char* filename);


	private:
		bool m_useMipmap;

		int m_width;
		int m_height;
		/* format */
		E_PixelFormat m_format;
		/* filter */
		E_TextureFilter m_filterMin;
		E_TextureFilter m_filterMag;
		E_TextureFilter m_filterMipmap;
		/* wrap */
		E_TextureWrap m_wrapS;
		E_TextureWrap m_wrapT;

		/* env */
		PlatformTexture m_platformTexture;

		std::string m_resourceUrl;

};

NS_FS_END 

#endif /*_FS_TEXTURE_2D_H_*/




