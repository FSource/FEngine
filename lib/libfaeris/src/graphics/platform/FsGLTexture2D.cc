#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
#elif FS_PLATFORM_OS(FS_OS_OSX)
	#include "GL/glew.h"
#elif FS_PLATFORM_OS(FS_OS_IOS)
    #include "GL_IOS/gl_ios_es.h"
#else
	#include "GL/glew.h"
#endif 

#include "graphics/FsTexture2D.h"
#include "support/image/FsImageDecoder.h"


NS_FS_BEGIN
static void s_bindTexture2D(GLuint texture)
{
	glBindTexture(GL_TEXTURE_2D,texture);
}



static inline GLint FsFilter_ToGLEnum(E_TextureFilter filter)
{
	switch(filter)
	{
		case E_TextureFilter::LINEAR:
			return GL_LINEAR;
		case E_TextureFilter::NEAREST:
			return GL_NEAREST;
		default:
			return GL_LINEAR;
	}
}
static inline GLint  FsFilter_ToGLEnum(E_TextureFilter filter_min,E_TextureFilter filter_mipmap)
{
	if(filter_min==E_TextureFilter::LINEAR)
	{
		if(filter_mipmap==E_TextureFilter::LINEAR)
		{
			return GL_LINEAR_MIPMAP_LINEAR;
		}
		else if(filter_mipmap==E_TextureFilter::NEAREST)
		{
			return GL_LINEAR_MIPMAP_NEAREST;
		}
		else 
		{
			return GL_LINEAR_MIPMAP_NEAREST;
		}
	}
	else  if(filter_min==E_TextureFilter::NEAREST)
	{
		if(filter_mipmap==E_TextureFilter::LINEAR)
		{
			return GL_NEAREST_MIPMAP_LINEAR;
		}
		else if(filter_mipmap==E_TextureFilter::NEAREST)
		{
			return GL_NEAREST_MIPMAP_NEAREST;
		}
	}
	
	return GL_LINEAR_MIPMAP_LINEAR;
}

static inline GLint FsWrap_ToGLEnum(E_TextureWrap wrap)
{
	switch(wrap)
	{
		/* opengl es not support 
		case E_TextureWrap::CLAMP:
			return GL_CLAMP;
		*/
		case E_TextureWrap::REPEAT:
			return GL_REPEAT;
		case E_TextureWrap::CLAMP_TO_EDGE:
			return GL_CLAMP_TO_EDGE;

		/* opengl es not support 
		case E_TextureWrap::CLAMP_TO_BORDER:
			return GL_CLAMP_TO_BORDER;
		*/
		default:
			return GL_CLAMP_TO_EDGE;
	}
}

static inline GLint  FsPixelFomat_ToGLEnum(E_PixelFormat format)
{
	switch(format)
	{
		case E_PixelFormat::RGBA8888:
			return GL_RGBA;

		case E_PixelFormat::ALPHA:
			return GL_ALPHA;

		case E_PixelFormat::LUMINANCE:
			return GL_LUMINANCE;

		case E_PixelFormat::LUMINANCE_ALPHA:
			return GL_LUMINANCE_ALPHA;

		/*  opengl es not support 
		case Texture2D::FORMAT_INTENSITY:
			return GL_INTENSITY;
		*/

		case E_PixelFormat::RGB888:
			return GL_RGB;

		default:
			return GL_RGBA;
	}
}



Texture2D* Texture2D::create(Image2D* image,
							E_TextureFilter filter_mag,E_TextureFilter filter_min,
							E_TextureWrap wraps,E_TextureWrap wrapt)
{
	Texture2D* ret=new Texture2D();
	if(!ret->init(image,filter_mag,filter_min,wraps,wrapt))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Texture2D* Texture2D::create(E_PixelFormat format,int width,int height,void* data,
							E_TextureFilter filter_mag,E_TextureFilter filter_min,
							E_TextureWrap wraps,E_TextureWrap wrapt)
{
	Texture2D* ret=new Texture2D();
	if(!ret->init(format,width,height,data,filter_mag,filter_min,wraps,wrapt))
	{
		delete ret;
		return NULL;
	}
	return ret;
}


Texture2D* Texture2D::create(Image2D* image)
{
	Texture2D* ret=new Texture2D();
	if(!ret->init(image))
	{
		delete ret;
		return NULL;
	}
	return ret;

}

Texture2D* Texture2D::create(const char* filename)
{
	Texture2D* ret=new Texture2D();
	if(!ret->init(filename))
	{
		delete ret;
		return NULL;
	}
	return ret;
}




bool Texture2D::init(const char* filename)
{
	Image2D* image=FsUtil_ImageReader(filename,E_ImageType::UNKOWN);
	if(image==NULL)
	{
		return false;
	}

	bool ret=init(image);
	image->decRef();
	return ret;
}


bool Texture2D::init(Image2D* image)
{
	bool ret=init( image, E_TextureFilter::LINEAR, E_TextureFilter::LINEAR, 
						  E_TextureWrap::CLAMP_TO_EDGE, 
						  E_TextureWrap::CLAMP_TO_EDGE);
	return ret;
}

bool Texture2D::init(Image2D* image,E_TextureFilter filter_mag,E_TextureFilter filter_min,
		 							E_TextureWrap wraps,E_TextureWrap wrapt)
{
	if(image==NULL)
	{
		FS_TRACE_WARN("Image Is NULL");
		return false;
	}

	return Texture2D::init(image->getPixelFormat(),image->getWidth(),image->getHeight(),image->getPixelData(),filter_mag,filter_min,wraps,wrapt);


}

bool Texture2D::init(E_PixelFormat format, int width,int height,void* pixels,
						E_TextureFilter filter_mag,E_TextureFilter filter_min,
						E_TextureWrap wraps,E_TextureWrap wrapt)
{

	GLint format_gl;
	GLint filter_mag_gl,filter_min_gl;
	GLint wraps_gl,wrapt_gl;
	/* pixel format */
	format_gl =FsPixelFomat_ToGLEnum(format);

	/* env mode */

	/* gen texture */
	GLuint texture;
	glGenTextures(1,&texture);


	/* bind texture */
	s_bindTexture2D(texture);

	/* filter */
	filter_mag_gl=FsFilter_ToGLEnum(filter_mag);
	filter_min_gl=FsFilter_ToGLEnum(filter_min);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,filter_mag_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,filter_min_gl);

	/* wrap */
	wraps_gl=FsWrap_ToGLEnum(wraps);
	wrapt_gl=FsWrap_ToGLEnum(wrapt);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,wraps_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,wrapt_gl);

	/* env mode */

	glPixelStorei(GL_UNPACK_ALIGNMENT,1);



	glTexImage2D(
			GL_TEXTURE_2D,
			0,
			format_gl,
			width,
			height,
			0,
			format_gl,
			GL_UNSIGNED_BYTE,
			pixels
			);

	m_width=width;
	m_height=height;

	m_format=format;
	m_filterMin=filter_min;
	m_filterMag=filter_mag;

	m_filterMipmap=E_TextureFilter::LINEAR;

	m_useMipmap=false;
	m_hasMipmap=false;
	m_wrapS=wraps;
	m_wrapT=wrapt;
	m_platformTexture=texture;

	return true;
}



void Texture2D::setFilter(E_TextureFilter mag,E_TextureFilter min,E_TextureFilter mipmap)
{
	if(m_filterMin==min&&m_filterMag==mag&&m_filterMipmap==mipmap)
	{
		return;
	}

	s_bindTexture2D(m_platformTexture);
	GLint filter_min_gl,filter_mag_gl;
	filter_mag_gl=FsFilter_ToGLEnum(mag);
	if(m_useMipmap)
	{
		filter_min_gl=FsFilter_ToGLEnum(min,mipmap);
	}
	else 
	{
		filter_min_gl=FsFilter_ToGLEnum(min);
	}

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,filter_mag_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,filter_min_gl);

	m_filterMin=min;
	m_filterMag=mag;
	m_filterMipmap=mipmap;

}

void Texture2D::setWrap(E_TextureWrap wraps,E_TextureWrap wrapt)
{
	if(m_wrapS==wraps&&m_wrapT==wrapt)
	{
		return;
	}

	s_bindTexture2D(m_platformTexture);
	GLint gl_wraps=FsWrap_ToGLEnum(wraps);
	GLint gl_wrapt=FsWrap_ToGLEnum(wrapt);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,gl_wraps);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,gl_wrapt);
	m_wrapS=wraps;
	m_wrapT=wrapt;

}


void Texture2D::setMipmapEnabled(bool enabled)
{
	if(m_useMipmap==enabled)
	{
		return;
	}

	s_bindTexture2D(m_platformTexture);
	GLint filter_min_gl;
	if(enabled)
	{
		filter_min_gl=FsFilter_ToGLEnum(m_filterMin,m_filterMipmap);
	}
	else 
	{
		filter_min_gl=FsFilter_ToGLEnum(m_filterMin);
	}

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,filter_min_gl);

	m_useMipmap=enabled;
	if(!m_hasMipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
		m_hasMipmap=true;
	}
}

bool Texture2D::getMipmapEnalbed()
{
	return m_useMipmap;
}

	



void Texture2D::markInvaild()
{
	m_platformTexture=0;
}

void Texture2D::setResourceUrl(const char* name)
{
	m_resourceUrl=std::string(name);
}

Texture2D::~Texture2D()
{
	if(m_platformTexture)
	{
		glDeleteTextures(1,&m_platformTexture);
	}
}


Texture2D::Texture2D()
{
	m_useMipmap=false;
	m_width=0;
	m_height=0;
	m_format=E_PixelFormat::UNKOWN;
	m_filterMin=E_TextureFilter::NEAREST;
	m_filterMag=E_TextureFilter::NEAREST;
	m_filterMipmap=E_TextureFilter::NEAREST;
	m_wrapS=E_TextureWrap::CLAMP_TO_EDGE;
	m_wrapT=E_TextureWrap::CLAMP_TO_EDGE;
	m_platformTexture=0;

}


const char* Texture2D::className()
{
	return FS_TEXTURE2D_CLASS_NAME;
}




NS_FS_END

