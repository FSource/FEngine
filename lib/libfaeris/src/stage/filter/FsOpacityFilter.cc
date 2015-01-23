/*************************************************************************/
/*  FsOpacityFilter.cc                                                   */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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


