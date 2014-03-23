#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
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



static inline GLint FsFilter_ToGLEnum(int filter)
{
	switch(filter)
	{
		case Texture2D::FILTER_LINEAR:
			return GL_LINEAR;
		case Texture2D::FILTER_NEAREST:
			return GL_NEAREST;
		default:
			return GL_LINEAR;
	}
}
static inline GLint  FsFilter_ToGLEnum(int filter_min,int filter_mipmap)
{
	if(filter_min==Texture2D::FILTER_LINEAR)
	{
		if(filter_mipmap==Texture2D::FILTER_LINEAR)
		{
			return GL_LINEAR_MIPMAP_LINEAR;
		}
		else if(filter_mipmap==Texture2D::FILTER_NEAREST)
		{
			return GL_LINEAR_MIPMAP_NEAREST;
		}
		else 
		{
			return GL_LINEAR_MIPMAP_NEAREST;
		}
	}
	else  if(filter_min==Texture2D::FILTER_NEAREST)
	{
		if(filter_mipmap==Texture2D::FILTER_LINEAR)
		{
			return GL_NEAREST_MIPMAP_LINEAR;
		}
		else if(filter_mipmap==Texture2D::FILTER_NEAREST)
		{
			return GL_NEAREST_MIPMAP_NEAREST;
		}
	}
	
	return GL_LINEAR_MIPMAP_LINEAR;
}

static inline GLint FsWrap_ToGLEnum(int wrap)
{
	switch(wrap)
	{
		/* opengl es not support 
		case Texture2D::WRAP_CLAMP:
			return GL_CLAMP;
		*/
		case Texture2D::WRAP_REPEAT:
			return GL_REPEAT;
		case Texture2D::WRAP_CLAMP_TO_EDGE:
			return GL_CLAMP_TO_EDGE;

		/* opengl es not support 
		case Texture2D::WRAP_CLAMP_TO_BORDER:
			return GL_CLAMP_TO_BORDER;
		*/
		default:
			return GL_CLAMP_TO_EDGE;
	}
}

static inline GLint  FsTextureFomat_ToGLEnum(int format)
{
	switch(format)
	{
		case Texture2D::FORMAT_RGBA:
			return GL_RGBA;

		case Texture2D::FORMAT_ALPHA:
			return GL_ALPHA;

		case Texture2D::FORMAT_LUMINANCE:
			return GL_LUMINANCE;

		case Texture2D::FORMAT_LUMINANCE_ALPHA:
			return GL_LUMINANCE_ALPHA;

		/*  opengl es not support 
		case Texture2D::FORMAT_INTENSITY:
			return GL_INTENSITY;
		*/

		case Texture2D::FORMAT_RGB:
			return GL_RGB;

		default:
			return GL_RGBA;
	}
}

static inline GLint FsImageFormat_ToGLEnum(int format)
{
	switch(format)
	{
		case Image2D::PIXEL_RGBA8888: return GL_RGBA;
		case Image2D::PIXEL_RGB888:   return GL_RGB;
		default:
			FS_TRACE_WARN("Unsupport Pixel Format To Texture2D");
			return 0;
	}
}


Texture2D* Texture2D::create(Image2D* image,int filter_mag,int filter_min,int wraps,int wrapt)
{
	Texture2D* ret=new Texture2D();
	if(!ret->init(image,filter_mag,filter_min,wraps,wrapt))
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



bool Texture2D::init(Image2D* image,int filter_mag,int filter_min,int wraps,int wrapt)
{
	if(image==NULL)
	{
		FS_TRACE_WARN("Image Is NULL");
		return false;

	}

	GLint format_gl;
	GLint filter_mag_gl,filter_min_gl;
	GLint wraps_gl,wrapt_gl;
	GLint width,height;
	GLvoid* pixels;

	/* pixel format */
	format_gl =FsImageFormat_ToGLEnum(image->getPixelFormat());

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



	/* set texture data */
	height=image->getHeight();
	width=image->getWidth();
	pixels=image->getPixelData();

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
	m_format=format_gl;
	m_filterMin=filter_min;
	m_filterMag=filter_mag;
	m_filterMipmap=FILTER_LINEAR;
	m_useMipmap=false;
	m_wrapS=wraps;
	m_wrapT=wrapt;
	m_platformTexture=texture;

	return true;
}


bool Texture2D::init(Image2D* image)
{
	bool ret=init( image, FILTER_LINEAR, FILTER_LINEAR, WRAP_CLAMP_TO_EDGE, WRAP_CLAMP_TO_EDGE);
	return ret;
}

bool Texture2D::init(const char* filename)
{
	Image2D* image=FsUtil_ImageReader(filename,Image2D::IMAGE_UNKWON);
	if(image==NULL)
	{
		return false;
	}

	bool ret=init(image);
	image->decRef();
	return ret;
}



void Texture2D::setFilter(int mag,int min,int mipmap)
{
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
}

void Texture2D::setWrap(int wraps,int wrapt)
{
	s_bindTexture2D(m_platformTexture);
	GLint gl_wraps=FsWrap_ToGLEnum(wraps);
	GLint gl_wrapt=FsWrap_ToGLEnum(wrapt);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,gl_wraps);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,gl_wrapt);
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
	m_format=0;
	m_filterMin=0;
	m_filterMag=0;
	m_filterMipmap=0;
	m_wrapS=0;
	m_wrapT=0;
	m_platformTexture=0;
}


const char* Texture2D::className()
{
	return FS_TEXTURE2D_CLASS_NAME;
}




NS_FS_END

