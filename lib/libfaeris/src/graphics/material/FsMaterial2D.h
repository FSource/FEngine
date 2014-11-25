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


