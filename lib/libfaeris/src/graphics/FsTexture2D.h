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
		enum 
		{
			/* filter */
			FILTER_LINEAR=0,
			FILTER_NEAREST,

			/* wrap */
			WRAP_CLAMP,
			WRAP_REPEAT,
			WRAP_CLAMP_TO_EDGE,
			WRAP_CLAMP_TO_BORDER,

			/* format */
			FORMAT_RGBA,
			FORMAT_ALPHA,
			FORMAT_LUMINANCE,
			FORMAT_LUMINANCE_ALPHA,
			FORMAT_INTENSITY,
			FORMAT_RGB,

		};

	public:
		static Texture2D* create(
				Image2D* image,
				int filter_mag,
				int filter_min,
				int wraps,
				int wrapt);


		/* for quick create texture from image */
		static Texture2D* create(Image2D* image);
		static Texture2D* create(const char* filename);

	public:

		/* fileter */
		void setFilter(int mag,int min,int mip=FILTER_LINEAR);
		int getFilterMin(){return m_filterMin;}
		int getFilterMag(){return m_filterMag;}
		int getFilterMipmap(){return m_filterMipmap;}

		/* wrap */
		void setWrap(int wraps,int wrapt);
		int getWrapS(){return m_wrapS;}
		int getWrapT(){return m_wrapT;}

		/* format */
		int getFormat(){return m_format;}

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

		bool init(Image2D* image,int filter_mag,int filter_min,int wraps,int wrapt);
		bool init(Image2D* image);
		bool init(const char* filename);


	private:
		bool m_useMipmap;

		int m_width;
		int m_height;
		/* format */
		int m_format;
		/* filter */
		int m_filterMin;
		int m_filterMag;
		int m_filterMipmap;
		/* wrap */
		int m_wrapS;
		int m_wrapT;

		/* env */
		PlatformTexture m_platformTexture;

		std::string m_resourceUrl;

};

NS_FS_END 

#endif /*_FS_TEXTURE_2D_H_*/




