#include "FsGrayFilter.h"

#include "graphics/FsRenderDevice.h"
#include "graphics/FsFrameBuffer.h"
#include "graphics/shader/FsProgramSource.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/material/FsMaterial2D.h"


NS_FS_BEGIN

GrayFilter* GrayFilter::create()
{
	GrayFilter* ret=new GrayFilter;
	return ret;
}


GrayFilter::GrayFilter()
{
	static ProgramSource* ps=NULL;
	if(ps==NULL)
	{
		ps=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_FILTER_GRAY);
	}
	m_material->setProgramSource(ps);
}


NS_FS_END 


