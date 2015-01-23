/*************************************************************************/
/*  FsSeekBar.cc                                                         */
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


#include "FsSeekBar.h"

NS_FS_BEGIN


SeekBar* SeekBar::create(const char* bg,const char* fg,const char* seek)
{
	SeekBar* ret=new SeekBar;
	ret->initWithTexture(bg,fg,seek);
	return ret;
}

SeekBar* SeekBar::create(Texture2D* tex_bg,Texture2D* tex_fg,Texture2D* tex_seek)
{
	SeekBar* ret=new SeekBar;
	ret->initWithTexture(tex_bg,tex_fg,tex_seek);
	return ret;
}


void SeekBar::setSeekTexture(const char* filename)
{
	Texture2D* tex=NULL;
	if(filename)
	{
		tex=Global::textureMgr()->loadTexture(filename);
		FS_TRACE_WARN_ON(tex==NULL,"Can't Seek Texture(%s) For SeekBar",filename);
	}
	setSeekTexture(tex);
}

void SeekBar::setSeekTexture(Texture2D* tex)
{
	FS_TRACE_WARN_ON(m_seekTexture,tex);
}

Texture2D* SeekBar::getSeekTexture()
{
	return m_seekTexture;
}

void SeekBar::setSeekMargin(float ml,float mb)
{
	m_seekMargin.set(ml,mb);
}

void SeekBar::setSeekMargin(const Vector2f& v)
{
	m_seekMargin=v;
}

Vector2f SeekBar::getSeekMargin()
{
	return m_seekMargin;
}


void SeekBar::setSeekSize(float w,float h)
{
	m_seekSize.set(w,h);
}

void SeekBar::setSeekSize(const Vector2f& v)
{
	m_seekSize=v;
}

Vector2f SeekBar::getSeekSize()
{
	return m_seekSize;
}










NS_FS_END 

