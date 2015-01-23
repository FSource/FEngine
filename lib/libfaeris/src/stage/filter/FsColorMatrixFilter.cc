/*************************************************************************/
/*  FsColorMatrixFilter.cc                                               */
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


#include "FsColorMatrixFilter.h"
#include "graphics/material/FsMaterial2D.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"

NS_FS_BEGIN


ColorMatrixFilter* ColorMatrixFilter::create()
{
	ColorMatrixFilter* ret=new ColorMatrixFilter;
	return ret;
}


void ColorMatrixFilter::setColorMatrix(const Matrix4& mat)
{
	m_colorMatrix->set(mat);

}

const Matrix4& ColorMatrixFilter::getColorMatrix()
{
	return m_colorMatrix->get();
}

void ColorMatrixFilter::setColorOffset(const Vector4f& offset)
{
	m_colorOffset->set(offset);
}
const Vector4f& ColorMatrixFilter::getColorOffset()
{
	return m_colorOffset->get();
}




void ColorMatrixFilter::setSaturation(float s)
{
	float rwgt=0.3086f;
	float gwgt =0.6094f;
	float bwgt =0.0820f;

	float a = (1.0f-s)*rwgt + s;
    float b = (1.0f-s)*rwgt;
    float c = (1.0f-s)*rwgt;
    float d = (1.0f-s)*gwgt;
    float e = (1.0f-s)*gwgt + s;
    float f = (1.0f-s)*gwgt;
    float g = (1.0f-s)*bwgt;
    float h = (1.0f-s)*bwgt;
    float i = (1.0f-s)*bwgt + s;

	m_colorMatrix->set(Matrix4(
		a,      d,      g,      0.0f,
        b,      e,      h,      0.0f,
        c,      f,      i,      0.0f,
        0.0f,    0.0f,    0.0f,    1.0f));

}

void ColorMatrixFilter::setBrightness(float b)
{
	m_colorMatrix->set(Matrix4::IDENTITY);
	m_colorOffset->set(Vector4f(b,b,b,0));
}

void ColorMatrixFilter::setContrast(float c)
{
	float t= (1.0f - c) / 2.0f; 
	m_colorMatrix->set(Matrix4(
		c,0,0,0,
		0,c,0,0,
		0,0,c,0,
		0,0,0,1
	));
	m_colorOffset->set(Vector4f(t,t,t,0));

}

void ColorMatrixFilter::setInvert()
{
	m_colorMatrix->set(Matrix4(
		-1.0f,   0,    0,   0,
		0,    -1.0f,   0,   0,
		0,       0,  -1.0f, 0,
		0,       0,    0,    1.0f
	));

	m_colorOffset->set(Vector4f(1,1,1,0));
}

void ColorMatrixFilter::setSepia()
{
	m_colorMatrix->set(Matrix4(
		0.393f, 0.769f, 0.189f, 0,
		0.349f, 0.686f, 0.168f, 0,
		0.272f, 0.534f, 0.131f, 0,
		0, 0, 0,1));
		
	m_colorOffset->set(Vector4f(0,0,0,0));
}



ColorMatrixFilter::ColorMatrixFilter()
{
	m_colorMatrix=UniformMat4f::create("u_colorMat4",Matrix4::IDENTITY);
	m_colorOffset=UniformValue4f::create("u_colorOffset",Vector4f(0.0f,0.0f,0.0f,0.0f));

	FS_NO_REF_DESTROY(m_colorMatrix);
	FS_NO_REF_DESTROY(m_colorOffset);

	m_material->addUniformValue(m_colorMatrix);
	m_material->addUniformValue(m_colorOffset);

	static ProgramSource* ps=NULL;
	if(ps==NULL)
	{
		ps=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_FILTER_COLOR_MATRIX);
	}
	m_material->setProgramSource(ps);

}



ColorMatrixFilter::~ColorMatrixFilter()
{
	FS_SAFE_DESTROY(m_colorMatrix);
	FS_SAFE_DESTROY(m_colorOffset);
}


NS_FS_END 



