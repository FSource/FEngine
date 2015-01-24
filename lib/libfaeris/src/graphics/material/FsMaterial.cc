/*************************************************************************/
/*  FsMaterial.cc                                                        */
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


#include "FsClass.h"
#include "graphics/material/FsMaterial.h"
#include "graphics/FsRenderDevice.h"


NS_FS_BEGIN



Material::Material()
	:m_wireframe(false),
	m_blendEquation(E_BlendEquation::ADD),
	m_blendSrc(E_BlendFactor::SRC_ALPHA),
	m_blendDst(E_BlendFactor::ONE_MINUS_SRC_ALPHA),
	m_frontSide(E_FrontFace::CCW),
	m_doubleSideEnabled(true),
	m_depthTestEnabled(false),
	m_depthWriteEnabled(false)
{}


void Material::configRenderDevice(RenderDevice* rd)
{
	rd->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
	rd->setDepthTestEnabled(m_depthTestEnabled);
	rd->setDepthWriteEnabled(m_depthWriteEnabled);
	rd->setDoubleSideEnabled(m_doubleSideEnabled);
	rd->setFrontSide(m_frontSide);
}



Material::~Material() 
{
}


/*  Use For  Material  FsClass  Attribute */

//static Material* Material_NewInstance



FS_CLASS_IMPLEMENT_WITH_BASE(Material,FsObject,0,NULL);




NS_FS_END











