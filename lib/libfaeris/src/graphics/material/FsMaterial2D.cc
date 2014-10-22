#include "FsMaterial2D.h"
#include "graphics/shader/FsProgram.h"

NS_FS_BEGIN

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


void Material2D::configRenderDevice(RenderDevice* rd)
{
	Material::configRenderDevice(rd);

	Program* prog=rd->getProgram();
	if(!proj)
	{
		return;
	}

	int uniform_nu=proj->getUinformMapNu();
	for(int i=0;i<uniform_nu;i++)
	{
		UniformMap* u=prog->getUinformMap(i);
		switch(u->m_type)
		{
			case 
		
		}
	}


}




NS_FS_END 



