/*************************************************************************/
/*  FsLayer.cc                                                           */
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


#include <algorithm>

#include "FsClass.h"
#include "stage/layer/FsLayer.h"
#include "stage/entity/FsEntity.h"
#include "stage/FsScene.h"
#include "support/util/FsDict.h"
#include "support/util/FsSlowDict.h"

NS_FS_BEGIN


Layer::Layer()
{
	init();
}

Layer::~Layer()
{
	destruct();
}



Scene* Layer::getScene()
{
	return m_scene;
}

void Layer::setScene(Scene* scene)
{
	m_scene=scene;
}


/* scissor */ 
void Layer::setScissorArea(float x,float y,float width,float height)
{
	m_scissorArea.set(x,y,width,height);
}
void Layer::getScissorArea(float* x,float* y,float* width,float* height)
{
	*x=m_scissorArea.x;
	*y=m_scissorArea.y;
	*width=m_scissorArea.width;
	*height=m_scissorArea.height;
}

void Layer::add(Entity* e)
{
	e->setLayer(this);
}

void Layer::remove(Entity* e) 
{
	e->setLayer(NULL);
}

void Layer::clearEntity()
{

}


void Layer::update(float dt)
{
}


bool Layer::touchBegin(float x,float y) { return m_touchEnabled; }
bool Layer::touchMove(float x,float y) { return m_touchEnabled; }
bool Layer::touchEnd(float x,float y) { return m_touchEnabled; }


/* touches event */
bool Layer::touchesBegin(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesPointerDown(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesMove(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesPointerUp(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesEnd(TouchEvent* event) { return m_touchesEnabled; }




void Layer::init()
{
	m_visible=true;

	m_touchEnabled=false;
	m_touchesEnabled=false;

	m_dispatchTouchEnabled=false;
	m_dispatchTouchesEnabled=false;



	m_scissorEnabled=false;
	m_scissorArea.set(0,0,1,1);
	m_scene=NULL;


	onUpdate=nullptr;
	onDraw=nullptr;

	/* touch */
	onTouchBegin=nullptr;
	onTouchMove=nullptr;
	onTouchEnd=nullptr;

	/* touches */
	onTouchesBegin=nullptr;
	onTouchesPointerDown=nullptr;
	onTouchesMove=nullptr;
	onTouchesPointerUp=nullptr;
	onTouchesEnd=nullptr;
}

void Layer::destruct() { }

Vector3 Layer::toLayerCoord(const Vector3& v) { return v; }



/*** Used For Layer  FsClass Attribute */

FS_CLASS_ATTR_SET_GET_FUNCTION(Layer,setVisible,getVisible,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Layer,setTouchEnabled,getTouchEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Layer,setTouchesEnabled,getTouchesEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Layer,setDispatchTouchEnabled,getDispatchTouchEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Layer,setDispatchTouchesEnabled,getDispatchTouchesEnabled,bool);


static FsClass::FsAttributeDeclare S_Layer_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("visible",FsType::FT_B_1,NULL,Layer_setVisible,Layer_getVisible),
	FS_CLASS_ATTR_DECLARE("touchEnabled",FsType::FT_B_1,NULL,Layer_setTouchEnabled,Layer_getTouchEnabled),
	FS_CLASS_ATTR_DECLARE("touchesEnabled",FsType::FT_B_1,NULL,Layer_setTouchesEnabled,Layer_getTouchesEnabled),
	FS_CLASS_ATTR_DECLARE("dispatchTouchEnabled",FsType::FT_B_1,NULL,Layer_setDispatchTouchEnabled,Layer_getDispatchTouchEnabled),
	FS_CLASS_ATTR_DECLARE("dispatchTouchesEnabled",FsType::FT_B_1,NULL,Layer_setDispatchTouchesEnabled,Layer_getDispatchTouchesEnabled),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(Layer,FsObject,0,S_Layer_Main_Attr);



NS_FS_END

