#include "FsColorMatrixFilter.h"
#include "graphics/material/FsMaterial2D.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"

NS_FS_BEGIN


ColorMatrixFilter* ColorMatrixFilter::create()
{
	ColorMatrixFilter* ret=new ColorMatrixFilter;
	return ret;
}


void ColorMatrixFilter::setColorMatrix(const Matrix4& mat)
{
	m_colorMatrix->set(mat);

}

const Matrix4& ColorMatrixFilter::getColorMatrix()
{
	return m_colorMatrix->get();
}


ColorMatrixFilter::ColorMatrixFilter()
{
	m_colorMatrix=UniformMat4f::create("u_colorMat4",Matrix4::IDENTITY);
	FS_NO_REF_DESTROY(m_colorMatrix);
	m_material->addUniformValue(m_colorMatrix);

	static ProgramSource* ps=NULL;
	if(ps==NULL)
	{
		ps=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_FILTER_COLOR_MATRIX);
	}
	m_material->setProgramSource(ps);

}



ColorMatrixFilter::~ColorMatrixFilter()
{
	FS_SAFE_DESTROY(m_colorMatrix);
}


NS_FS_END 



