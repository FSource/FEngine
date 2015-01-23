/*************************************************************************/
/*  FsColorMatrixFilter.h                                                */
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


#ifndef _FS_COLOR_MATRIX_FILTER_H_
#define _FS_COLOR_MATRIX_FILTER_H_

#include "FsFilter.h"
#include "math/FsMatrix4.h"
#include "graphics/shader/FsUniformValue.h"

NS_FS_BEGIN

class UniformValue;

class ColorMatrixFilter:public Filter 
{
	public:
		static ColorMatrixFilter* create();

	public:
		void setColorMatrix(const Matrix4& mat);
		const Matrix4& getColorMatrix();
		void setColorOffset(const Vector4f& offset);
		const Vector4f& getColorOffset();

		void setSaturation(float value);
		void setBrightness(float b);
		void setContrast(float c);
		void setInvert();
		

		void setSepia();




	protected:
		ColorMatrixFilter();
		~ColorMatrixFilter();

	protected:
		UniformMat4f* m_colorMatrix;
		UniformValue4f* m_colorOffset;
};


NS_FS_END 


#endif /*_FS_COLOR_MATRIX_FILTER_H_*/

