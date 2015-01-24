/*************************************************************************/
/*  FsTexture2D.h                                                        */
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


#ifndef _FS_TEXTURE_2D_H_
#define _FS_TEXTURE_2D_H_ 

#include "FsMacros.h"
#include "FsConfig.h"
#include "mgr/FsResourceMgr.h"
#include "mgr/FsResource.h"
#include "sys/io/FsFile.h"
#include "graphics/FsImage2D.h"

#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE) 
	typedef uint PlatformTexture;
#else 
	#error "Unsupport PlatformTexture"
#endif 



NS_FS_BEGIN 
class Texture2D:public Resource
{

	public:
		FS_CLASS_DECLARE(Texture2D);

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

		void setMipmapEnabled(bool enabled);
		bool getMipmapEnalbed();

		PlatformTexture getPlatformTexture(){return m_platformTexture;}

		void markInvaild();
		void setResourceUrl(const char* name);

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
		bool m_hasMipmap;

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




