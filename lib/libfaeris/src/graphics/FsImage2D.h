/*************************************************************************/
/*  FsImage2D.h                                                          */
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


#ifndef _FAERIS_IMAGE2D_H_
#define _FAERIS_IMAGE2D_H_
#include "FsMacros.h"
#include "FsEnums.h"
#include "FsObject.h"
#include "graphics/FsColor.h"
NS_FS_BEGIN
class Image2D:public FsObject
{
	public:
		static Image2D* create(const char* filename,E_ImageType format=E_ImageType::UNKOWN);
		static Image2D* create(uint width,uint height,E_PixelFormat format);
		static Image2D* create(uint width,uint height,void* data,E_PixelFormat format);
		static uint PixelFormatSize(E_PixelFormat f);


	public:
		uint getWidth()const{return m_width;} 
        uint getHeight()const{return m_height;}
		void* getPixelData()const{return m_buffer;}
		E_PixelFormat getPixelFormat()const{return m_format;}
		Color getColor(uint x,uint y)const;
		void setColor(uint x,uint y,Color c);

		/* overide FsObject */
		virtual const char* className();

	protected:
		Image2D();
		virtual ~Image2D();
		void init(uint width,uint height,E_PixelFormat format);
		void init(uint width,uint height,void* data,E_PixelFormat format);
		void destruct();

	private:
		uint m_pixel_bytes;
		uint m_width;
		uint m_height;
		E_PixelFormat m_format;
		uint8_t* m_buffer;
};
NS_FS_END
#endif /* _FAERIS_IMAGE2D_H_*/





