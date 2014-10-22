#ifndef _FS_MATERIAL_2D_H_
#define _FS_MATERIAL_2D_H_

#include "FsMacros.h"
#include "FsMaterial.h"
#include "graphics/FsTexture2D.h"


NS_FS_BEGIN

class Material2D:public Material 
{
	public:
		/* inherit FsObject */
		const char* className();

		virtual Program* getProgram(ProgramFeatureDesc* desc)=0;
		virtual void configRenderDevice(RenderDevice* rd);

	public:
		void setColor(const Color4f& color){m_color=color;}
		Color4f getColor(){return m_color;}

		void setOpacity(float opacity) {m_opacity=opacity;}
		float getOpacity(){return m_opacity;}

		void setColorMap(Texture2D* t)
		{
			FS_SAFE_ASSIGN(m_colorMap,t);
		}

		Texture2D* getColorMap()
		{
			return m_colorMap;
		}

	protected:
		Material2D();
		virtual ~Material2D();


	protected:
		Color4f m_color;
		float m_opacity;
		Texture2D* m_colorMap;
		std::vector<UniformValue*>* m_extends;
};

NS_FS_END

#endif /*_FS_MATERIAL_2D_H_*/


