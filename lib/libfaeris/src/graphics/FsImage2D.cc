/*************************************************************************/
/*  FsImage2D.cc                                                         */
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


#include <string.h>
#include "graphics/FsImage2D.h"
#include "support/image/FsImageDecoder.h"

NS_FS_BEGIN
uint Image2D::PixelFormatSize(E_PixelFormat f)
{
	uint pixel_bytes;
	switch(f)
	{
		case E_PixelFormat::UNKOWN:
			pixel_bytes=0;
			break;
		case E_PixelFormat::RGB888:
			pixel_bytes=3;
			break;
		case E_PixelFormat::RGBA8888:
			pixel_bytes=4;
			break;
		case E_PixelFormat::GRAY8:
			pixel_bytes=1;
			break;
		default:
			pixel_bytes=0;
			break;
	}
	FS_TRACE_WARN_ON(pixel_bytes==0,"UnKown PixelFormat");
	return pixel_bytes;
}

Image2D* Image2D::create(const char* filename,E_ImageType format)
{
	return FsUtil_ImageReader(filename,format);
}
Image2D* Image2D::create(uint width,uint height,E_PixelFormat format)
{
	FS_TRACE_ERROR_ON(format==E_PixelFormat::UNKOWN,"Unkown PixelFormat");
	Image2D* ret=new Image2D();
	ret->init(width,height,format);
	return ret;
}
Image2D* Image2D::create(uint width,uint height,void* data,E_PixelFormat format)
{
	FS_TRACE_ERROR_ON(format==E_PixelFormat::UNKOWN,"Unkown PixelFormat");
	Image2D* ret=new Image2D();
	ret->init(width,height,data,format);
	return ret;
}




Image2D::Image2D()
{
	m_pixel_bytes=0;
	m_width=0;
	m_height=0;
	m_format=E_PixelFormat::UNKOWN;
	m_buffer=NULL;
}
void Image2D::init(uint width,uint height,E_PixelFormat format)
{
	uint pixel_bytes=PixelFormatSize(format);
	if(pixel_bytes==0)
	{
		FS_TRACE_WARN("Unkown PixelFormat");
		m_width=0;
		m_height=0;
		m_format=E_PixelFormat::UNKOWN;
		m_pixel_bytes=0;
		m_buffer=0;
		return;
	}

	uint size=width*height*pixel_bytes;
	m_buffer=new uint8_t[size];
	memset(m_buffer,0,size);
	m_width=width;
	m_height=height;
	m_format=format;
	m_pixel_bytes=pixel_bytes;
} 

void Image2D::init(uint width,uint height,void* data,E_PixelFormat format)
{
	uint pixel_bytes=PixelFormatSize(format);
	if(pixel_bytes==0)
	{
		FS_TRACE_WARN("Unkown PixelFormat");
		m_width=0;
		m_height=0;
		m_format=E_PixelFormat::UNKOWN;
		m_pixel_bytes=0;
		m_buffer=0;
		return;
	}

	uint size=width*height*pixel_bytes;
	m_buffer=new uint8_t[size];
	memcpy(m_buffer,data,size);
	m_width=width;
	m_height=height;
	m_format=format;
	m_pixel_bytes=pixel_bytes;
}



Color Image2D::getColor(uint w,uint h)const 
{
	if(w>=m_width||h>=m_height)
	{
		FS_TRACE_WARN("Invalid Index");
		return Color::DEFAULT_COLOR;
	}
	Color ret;
	uint8_t* p=m_buffer+(h*m_width+w)*m_pixel_bytes;
	switch(m_format)
	{
		case E_PixelFormat::RGB888:
			ret.r=*p++;
			ret.g=*p++;
			ret.b=*p++;
			ret.a=255;
			break;
		case E_PixelFormat::RGBA8888:
			ret.r=*p++;
			ret.g=*p++;
			ret.b=*p++;
			ret.a=*p++;
			break;
		default:
			FS_TRACE_WARN("UnKown Format Type");
	}
	return ret;
}

void Image2D::setColor(uint w,uint h,Color c)
{
	if(w>=m_width||h>m_height)
	{
		FS_TRACE_WARN("Invalid Index");
		return ;
	}
	uint8_t* p=m_buffer+(h*m_width+w)*m_pixel_bytes;

	switch(m_format)
	{
		case E_PixelFormat::RGB888:
			*p++=c.r;
			*p++=c.g;
			*p++=c.b;
			break;
		case E_PixelFormat::RGBA8888:
			*p++=c.r;
			*p++=c.g;
			*p++=c.b;
			*p++=c.a;
			break;
		default:
			FS_TRACE_WARN("UnKown Format Type");
	}
}
Image2D::~Image2D()
{
	destruct();
}

void Image2D::destruct()
{
	if(m_buffer)
	{
		delete[] m_buffer;
		m_buffer=NULL;
	}
}

const char* Image2D::className()
{
	return FS_IMAGE2D_CLASS_NAME;
}






NS_FS_END 

