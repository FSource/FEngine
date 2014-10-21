#include "FsColorMaterial.h"

NS_FS_BEGIN

const char* ColorMaterial::className()
{
	return "ColorMaterial";
}


ColorMaterial::ColorMaterial()
{
	m_color=new UniformValueC3f("u_color",E_UniformType::UT_F_3,Color3f::WHITE);
	addUniform(m_color);
}


static const char* FS_PRE_SHADER_

Program* ColorMaterial::getProgram(ProgramFeatureDesc* desc)
{
	ProgramFeatureDesc* cm_desc=desc->clone();
	cm_desc->m_name="__FsColorShader";

	cm_desc->m_supportLight=0;
	cm_desc->m_supportAlphaTest=0;


	Program* prog=Program::create(cm_desc,

}



NS_FS_END 
