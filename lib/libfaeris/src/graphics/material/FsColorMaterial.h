#ifndef _FS_COLOR_MATERIAL_H_
#define _FS_COLOR_MATERIAL_H_

#include "FsMacros.h"
#include "FsMaterial.h"

#include "graphics/FsColor.h"

NS_FS_BEGIN

class ColorMaterial:public Material 
{
	public:
		static ColorMaterial* create();

	public:
		void setColor(const Color3f& c){m_color->m_data=c;}
		const Color3f& getColor(){return m_color->m_data;}

	public:
		virtual Program* getProgram(ProgramFeatureDesc* desc);
		virtual const char* className();


	protected:
		ColorMaterial();

	protected:
		UniformValueC3f* m_color;
};

NS_FS_END

#endif /*_FS_COLOR_MATERIAL_H_*/



