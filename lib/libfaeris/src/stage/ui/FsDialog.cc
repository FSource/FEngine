/*************************************************************************/
/*  FsDialog.cc                                                          */
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


#include "FsDialog.h"

#include "graphics/shader/FsProgramSource.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"
#include "FsGlobal.h"
#include "FsClass.h"
#include "mgr/FsProgramSourceMgr.h"





NS_FS_BEGIN



Dialog* Dialog::create()
{
	Dialog* ret=new Dialog;
	return ret;
}

Dialog* Dialog::create(float width,float height)
{
	Dialog* ret=new Dialog;
	ret->setSize(width,height);
	return ret;
}

bool Dialog::hit2D(float x,float y)
{
	return true;
}

bool Dialog::touchBegin(float x,float y)
{
	UiWidget::touchBegin(x,y);
	return true;
}



bool Dialog::touchEnd(float x,float y)
{
	bool ret=UiWidget::touchEnd(x,y);
	if(ret)
	{
		return true;
	}

	if(!UiWidget::hit2D(x,y))
	{
		FS_OBJECT_LAMBDA_CALL(this,onTouchOutside,touchOutside,x,y);
	}
	return true;
}

void Dialog::draw(RenderDevice* rd,bool update_matrix) 
{
	if(m_darkOutsideEnabled)
	{
		drawOutside(rd,update_matrix);
	}

	UiWidget::draw(rd,update_matrix);
}

void Dialog::drawOutside(RenderDevice*rd,bool update_matrix)
{
	Program* prog=m_outsideMaterial->getProgram(NULL);
	if(!prog)
	{
		return;
	}

	static Vector3 vv[4]=
	{
		Vector3(0,0,0),
		Vector3(1,0,0),
		Vector3(1,1,0),
		Vector3(0,1,0),
	};

	static Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	Matrix4 old_proj_mat=*rd->getProjectionMatrix();

	Matrix4 mat;
	mat.makeOrthographic(0,1,0,1,-100,100);
	rd->setProjectionMatrix(&mat);
	rd->loadWorldMatrixIdentity();

	rd->setProgram(prog);
	m_outsideMaterial->configRenderDevice(rd);


	rd->disableAllAttrArray();

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);


	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,3,FS_FLOAT,4,0,vv);
	}


	rd->drawFace3(faces,2);

	rd->setProjectionMatrix(&old_proj_mat);

}



void Dialog::setDarkOutsideColor(const Color4f& c)
{
	m_outsideMaterial->setColor(c);
}

Color4f Dialog::getDarkOutsideColor()
{
	return m_outsideMaterial->getColor();
}

void Dialog::setDarkOutsideEnabled(bool enabled)
{
	m_darkOutsideEnabled=enabled;
}

bool Dialog::getDarkOutsideEnabled()
{
	return m_darkOutsideEnabled;
}

void Dialog::setDetachOnTouchOutside(bool value)
{
	m_detachOutside=value;
}

bool Dialog::getDetachOnTouchOutside()
{
	return m_detachOutside;
}


void Dialog::touchOutside(float x,float y)
{
	if(this->m_detachOutside)
	{
		this->detach();
	}
}



Dialog::Dialog()
{
	m_detachOutside=false;
	m_darkOutsideEnabled=false;

	onTouchOutside=nullptr;
	m_outsideMaterial=Material2D::create();
	FS_NO_REF_DESTROY(m_outsideMaterial);

	setBlockTouchEnabled(true);
	setBlockTouchesEnabled(true);

	static ProgramSource* S_programSourceColor=NULL;
	if(S_programSourceColor==NULL)
	{
		S_programSourceColor=(ProgramSource*) Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F);
	}

	m_outsideMaterial->setProgramSource(S_programSourceColor);
}


Dialog::~Dialog()
{
	FS_DESTROY(m_outsideMaterial);
}



/** Used For Dialog Attribute */

static Dialog* Dialog_NewInstance(FsDict* attr)
{
	Dialog* ret=Dialog::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}

FS_CLASS_ATTR_SET_GET_FUNCTION(Dialog,setDarkOutsideColor,getDarkOutsideColor,Color4f);
FS_CLASS_ATTR_SET_GET_FUNCTION(Dialog,setDarkOutsideEnabled,getDarkOutsideEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Dialog,setDetachOnTouchOutside,getDetachOnTouchOutside,bool);


static FsClass::FsAttributeDeclare S_Dialog_Main_Attr[]={

	FS_CLASS_ATTR_DECLARE("darkOutsideColor",FsType::FT_COLOR_4,NULL,Dialog_setDarkOutsideColor,Dialog_getDarkOutsideColor),

	FS_CLASS_ATTR_DECLARE("darkOutsideEnabled",FsType::FT_B_1,NULL,Dialog_setDarkOutsideEnabled,Dialog_getDarkOutsideEnabled),

	FS_CLASS_ATTR_DECLARE("detachOnTouchOutside",FsType::FT_B_1,NULL,Dialog_setDetachOnTouchOutside,Dialog_getDetachOnTouchOutside),

	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)

};

FS_CLASS_IMPLEMENT_WITH_BASE(Dialog,UiWidget,Dialog_NewInstance,S_Dialog_Main_Attr);




















NS_FS_END 


