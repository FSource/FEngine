#include "FsBrightnessFilter.h"
#include "graphics/material/FsMaterial2D.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"

NS_FS_BEGIN

BrightnessFilter* BrightnessFilter::create()
{
	BrightnessFilter* ret=new BrightnessFilter();
	return ret;
}

BrightnessFilter* BrightnessFilter::create(float value)
{
	BrightnessFilter* ret=new BrightnessFilter();
	ret->setBrightness(value);
	return ret;
}


void BrightnessFilter::setBrightness(float value)
{
	m_material->setOpacity(value);
}

float BrightnessFilter::getBrightness()
{
	return m_material->getOpacity();
}

BrightnessFilter::BrightnessFilter()
{
	static ProgramSource* ps=NULL;
	if(ps==NULL)
	{
		ps=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_FILTER_BRIGHTNESS);
	}

	m_material->setProgramSource(ps);
	m_material->setOpacity(0.0f);
}







NS_FS_END 


