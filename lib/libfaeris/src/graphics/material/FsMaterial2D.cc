#include "FsMaterial2D.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsProgramSource.h"
#include "graphics/shader/FsUniformMap.h"
#include "FsGlobal.h"

NS_FS_BEGIN

Material2D* Material2D::create()
{
	Material2D* ret=new Material2D();
	return ret;

}

Material2D* Material2D::create(ProgramSource* ps)
{

	Material2D* ret=new Material2D();
	ret->setProgramSource(ps);
	return ret;
}




const char* Material2D::className()
{
	return "Material2D";
}

Material2D::Material2D()
{
	m_color=Color4f::RED;
	m_opacity=1.0f;
	m_colorMap=NULL;
	m_extends=NULL;
}

Material2D::~Material2D()
{
	FS_SAFE_DEC_REF(m_colorMap);
}


Program* Material2D::getProgram(ProgramFeatureDesc* desc)
{
	if(m_programSource)
	{
		return m_programSource->getProgram(desc);
	}

	return NULL;

}



void Material2D::configRenderDevice(RenderDevice* rd)
{
	Material::configRenderDevice(rd);

	Program* prog=rd->getProgram();
	if(!prog)
	{
		return;
	}

	int uniform_nu=prog->getUniformMapNu();
	for(int i=0;i<uniform_nu;i++)
	{
		UniformMap* u=prog->getUniformMap(i);
		switch(u->m_type)
		{
			case E_UniformType::UT_REF_RD:
				rd->setUniform(u->m_location,u);
				break;
			case E_UniformType::UT_REF_MAT:
				{
					switch(u->m_refValue)
					{
						case E_UniformRef::M_COLOR:
							rd->setUniform(u->m_location,E_UniformType::UT_F_4,1,&m_color);
							break;

						case E_UniformRef::M_OPACITY:
							rd->setUniform(u->m_location,E_UniformType::UT_F_1,1,&m_opacity);
							break;

						case E_UniformRef::M_COLOR_MAP:
							{
								int tex_slot=0;
								if(m_colorMap)
								{
									rd->bindTexture(m_colorMap,tex_slot);
								}
								rd->setUniform(u->m_location,E_UniformType::UT_S_2D,1,&tex_slot);
							}
							break;

						default:
							FS_TRACE_WARN("UnSupport Material Ref Map(%d)",static_cast<int>(u->m_refValue));
							break;
					}
				}
				break;
			default:
				FS_TRACE_WARN("UnSupport Uniform Type(%d)",static_cast<int>(u->m_type));
		}
	}
}


void Material2D::setColorMap(Texture2D* t)
{
	FS_SAFE_ASSIGN(m_colorMap,t);
}


void Material2D::setProgramSource(ProgramSource* ps)
{
	FS_SAFE_ASSIGN(m_programSource,ps);
}






NS_FS_END 



