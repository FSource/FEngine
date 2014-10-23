#include "FsIMaterial2DEntity.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/shader/FsProgramSource.h"



NS_FS_BEGIN

IMaterial2DEntity::IMaterial2DEntity()
{
	m_material=Material2D::create();
	FS_SAFE_ADD_REF(m_material);
}

IMaterial2DEntity::~IMaterial2DEntity()
{
	FS_SAFE_DEC_REF(m_material);
}


void IMaterial2DEntity::setMaterial(Material2D* mat)
{
	FS_SAFE_ASSIGN(m_material,mat);
}

Material2D* IMaterial2DEntity::getMaterial()
{
	return m_material;
}

void IMaterial2DEntity::setColor(const Color4f& c)
{
	if(m_material) m_material->setColor(c);
}

Color4f IMaterial2DEntity::getColor()
{
	if(m_material) return m_material->getColor();
	return Color4f();
}


void IMaterial2DEntity::setOpacity(float opacity)
{
	if(m_material) m_material->setOpacity(opacity);
}


float IMaterial2DEntity::getOpacity()
{
	if(m_material) return m_material->getOpacity();
	return 1.0f;
}

void IMaterial2DEntity::setBlend(E_BlendEquation eq,E_BlendFactor src,E_BlendFactor dst)
{
	if(m_material)  m_material->setBlend(eq,src,dst); 
}

void IMaterial2DEntity::setBlend(E_BlendFactor src,E_BlendFactor dst)
{
	if(m_material)
	{
		m_material->setBlend(src,dst);
	}
}

void IMaterial2DEntity::setProgramSource(ProgramSource* ps)
{
	if(m_material) m_material->setProgramSource(ps);
}

void IMaterial2DEntity::setProgramSource(const char* filename)
{
	ProgramSource* ps=NULL;

	if(filename!=NULL)
	{
		ps=(ProgramSource*)Global::programSourceMgr()->load(filename);
	}

	if(m_material)
	{
		m_material->setProgramSource(ps);
	}
}




ProgramSource* IMaterial2DEntity::getProgramSource()
{
	if(m_material) return m_material->getProgramSource();

	return NULL;
}





Program* IMaterial2DEntity::getProgram(ProgramFeatureDesc* desc)
{
	if(m_material) return m_material->getProgram(desc);

	return NULL;
}











NS_FS_END




