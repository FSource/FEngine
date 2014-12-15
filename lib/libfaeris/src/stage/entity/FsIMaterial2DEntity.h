#ifndef _FS_I_MATERIAL_2D_H_
#define _FS_I_MATERIAL_2D_H_

#include "FsMacros.h"
#include "FsEnums.h"
#include "graphics/material/FsMaterial2D.h"


NS_FS_BEGIN
class ProgramSource;
class Program;
class ProgramFeatureDesc;


class IMaterial2DEntity 
{
	public:
		void setMaterial(Material2D* mat);
		Material2D* getMaterial() ;

		/* material */
		void setColor(const Color4f& c);
		Color4f getColor();

		void setOpacity(float opacity);
		float getOpacity();

		void setBlend(E_BlendEquation eq,E_BlendFactor src,E_BlendFactor dst);
		void setBlend(E_BlendFactor src,E_BlendFactor dst);

		void setBlendSrc(E_BlendFactor src);
		E_BlendFactor getBlendSrc();

		void setBlendDst(E_BlendFactor dst);
		E_BlendFactor getBlendDst();

		void setBlendEquation(E_BlendEquation eq);
		E_BlendEquation getBlendEquation();



		void setProgramSource(ProgramSource* ps);
		void setProgramSource(const char* filename);
		ProgramSource* getProgramSource();

	public:
		Program* getProgram(ProgramFeatureDesc* desc);

	public:
		IMaterial2DEntity();

		virtual ~IMaterial2DEntity();
		


	protected:
		Material2D* m_material;
};



NS_FS_END





#endif /*_FS_I_MATERIAL_2D_H_*/



