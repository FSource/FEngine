#include "FsOpacityFilter.h"
#include "graphics/FsRenderDevice.h"
#include "graphics/FsFrameBuffer.h"
#include "graphics/shader/FsProgramSource.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/material/FsMaterial2D.h"





NS_FS_BEGIN

OpacityFilter* OpacityFilter::create()
{
	OpacityFilter* ret=new OpacityFilter();
	return ret;
}

OpacityFilter* OpacityFilter::create(float opacity)
{
	OpacityFilter* ret=new OpacityFilter();
	ret->setOpacity(opacity);
	return ret;
}

OpacityFilter::OpacityFilter()
{
	static ProgramSource* ps=NULL;
	if(ps==NULL)
	{
		ps=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_FILTER_OPACITY);
	}
	m_material->setProgramSource(ps);

	m_material->setOpacity(1.0f);

}

void OpacityFilter::setOpacity(float value)
{
	m_material->setOpacity(value);
}

float OpacityFilter::getOpacity()
{
	return m_material->getOpacity();
}



NS_FS_END 


