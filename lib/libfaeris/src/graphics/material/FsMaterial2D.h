/*************************************************************************/
/*  FsMaterial2D.h                                                       */
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


#ifndef _FS_MATERIAL_2D_H_
#define _FS_MATERIAL_2D_H_

#include "FsMacros.h"
#include "FsMaterial.h"
//#include "graphics/FsTexture2D.h"

NS_FS_BEGIN

class ProgramSource;
class ProgramFeatureDesc;
class Texture2D;
class FsArray;


class Material2D:public Material 
{

	public:
		static Material2D* create();
		static Material2D* create(ProgramSource* ps);

	public:
		/* inherit FsObject */
		const char* className();

		virtual Program* getProgram(ProgramFeatureDesc* desc);
		virtual void configRenderDevice(RenderDevice* rd);

	public:
		void setColor(const Color4f& color){m_color=color;}
		Color4f getColor(){return m_color;}

		void setOpacity(float opacity) {m_opacity=opacity;}
		float getOpacity(){return m_opacity;}


		void setColorMapUrl(const char* filename);
		void setColorMap(Texture2D* t);

		Texture2D* getColorMap()
		{
			return m_colorMap;
		}

		void setProgramSource(ProgramSource* ps);
		ProgramSource* getProgramSource(){return m_programSource;}

		void setPointSize(float size){m_pointSize=size;}
		float getPointSize(){return m_pointSize;}

		int getUniformValueNu();
		UniformValue* getUniformValue(int i);
		void addUniformValue(UniformValue* v);
		void removeUniformValue(UniformValue* v);

	protected:
		Material2D();
		virtual ~Material2D();


	protected:
		Color4f m_color;
		float m_opacity;
		float m_pointSize;

		Texture2D* m_colorMap;
		FsArray* m_extends;

		ProgramSource* m_programSource;
};

NS_FS_END

#endif /*_FS_MATERIAL_2D_H_*/


