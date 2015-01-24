/*************************************************************************/
/*  FsMaterial.h                                                         */
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


#ifndef _FS_BASE_MATERIAL_H_
#define _FS_BASE_MATERIAL_H_


#include <vector>

#include "FsMacros.h"
#include "FsEnums.h"
#include "mgr/FsResource.h"
#include "FsObject.h"
#include "graphics/FsRenderDevice.h"



NS_FS_BEGIN

class Program;
class ProgramFeatureDesc;


class Material:public Resource
{

	public:
		FS_CLASS_DECLARE(Material);

	public:
		Material();
		virtual ~Material();

	public:
		/* blend */
		void setBlend(E_BlendEquation equation,E_BlendFactor src,E_BlendFactor dst)
		{
			m_blendEquation=equation;
			m_blendSrc=src;
			m_blendDst=dst;
		}

		void setBlend(E_BlendFactor src,E_BlendFactor dst)
		{
			m_blendEquation=E_BlendEquation::ADD;
			m_blendSrc=src;
			m_blendDst=dst;
		}


		void setBlendEquation(E_BlendEquation eq)
		{
			m_blendEquation=eq;
		}
		E_BlendEquation getBlendEquation() { return m_blendEquation; }

		void setBlendSrc(E_BlendFactor f)
		{
			m_blendSrc=f;
		}
		E_BlendFactor getBlendSrc() { return m_blendSrc; }

		void setBlendDst(E_BlendFactor f)
		{
			m_blendDst=f;
		}
		E_BlendFactor getBlendDst() { return m_blendDst; }


		void setDoubleSideEnabled(bool value) {m_doubleSideEnabled=value;}
		bool getDoubleSideEnabled(){return m_doubleSideEnabled;}

		void setFrontSide(E_FrontFace front){m_frontSide=front;}
		E_FrontFace getFrontSide(){return m_frontSide;}

		/* depth test */
		void setDepthTestEnabled(bool enable) { m_depthTestEnabled=enable; }
		bool getDepthTestEnabled() { return m_depthTestEnabled; }

		void setDepthWriteEnabled(bool enable) {m_depthWriteEnabled=enable;}
		bool getDepthWriteEnabled(){return m_depthWriteEnabled;}



	public:
		virtual Program* getProgram(ProgramFeatureDesc* desc)=0;
		virtual void configRenderDevice(RenderDevice* rd);

	protected:
		/* render state */
		bool m_wireframe;

		E_BlendEquation m_blendEquation;
		E_BlendFactor m_blendSrc;
		E_BlendFactor m_blendDst;

		E_FrontFace m_frontSide;
		bool m_doubleSideEnabled;

		bool m_depthTestEnabled;
		bool m_depthWriteEnabled;

};

NS_FS_END 

#endif /*_FS_MATTERIAL_H_*/


