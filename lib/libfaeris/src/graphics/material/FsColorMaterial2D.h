#ifndef _FS_COLOR_MATERAL_2D_H_
#define _FS_COLOR_MATERAL_2D_H_ 

#include "FsMacros.h"
#include "graphics/material/FsMaterial.h"


/* uniform:
 * 		u_pointSize 
 */

NS_FS_BEGIN

class ColorMaterial:public Material 
{
	public:
		static ColorMaterial* create();


	public:
		void setPointSize(float size){m_pointSize=size;}
		float getPointSize(){return m_pointSize;}
		void setColor(const Color3f&  c){m_color=c;}


	public:
		virtual void configRenderDevice(RenderDevice* r,bool force);
		virtual Program* getProgram(ProgramFeatureDesc* desc);

		const char* className();

	protected:
		ColorMaterial();
		virtual ~ColorMaterial();

	private:
		float m_pointSize;
		Color3f m_color;
};

NS_FS_END

#endif /*_FS_COLOR_MATERAL_H_*/


