#include "FsClassMgr.h"
#include "FsClass.h"
#include "support/util/FsDict.h"
#include "support/util/FsString.h"





NS_FS_BEGIN

ClassMgr::ClassMgr()
{
	m_cls=FsDict::create();
	FS_NO_REF_DESTROY(m_cls);
}


ClassMgr::~ClassMgr()
{
	FS_SAFE_DESTROY(m_cls);
	m_cls=NULL;
}


ClassMgr* ClassMgr::create()
{
	ClassMgr* ret=new ClassMgr();
	return ret;
}


FsObject* ClassMgr::newInstance(FsDict* dict)
{
	FsString* name=dict->lookupString("class");
	if(name)
	{
		FsClass* cls=getClass(name);
		if(cls)
		{
			return cls->newInstance(dict);
		}
		else 
		{
			FS_TRACE_WARN("Can't Find Class(%s) In ClassMgr",name->cstr()); 
		}
	}
	else 
	{
		FS_TRACE_WARN("Can't Find Key Class Type Info");
		return NULL;
	}
	return NULL;
}


FsClass* ClassMgr::getClass(FsString* name)
{
	return (FsClass*) m_cls->lookup(name);
}

FsClass* ClassMgr::getClass(const char* name)
{
	return (FsClass*) m_cls->lookup(name);
}


void ClassMgr::registerClass(FsString* name,FsClass* cls)
{
	m_cls->insert(name,cls);
}

void ClassMgr::registerClass(const char* name,FsClass* cls)
{
	FsString* fs_name=FsString::create(name);
	m_cls->insert(fs_name,cls);
	fs_name->autoDestroy();
}

void ClassMgr::unRegisterClass(const char* name)
{
	FsString* fs_name=FsString::create(name);
	m_cls->remove(fs_name);
	fs_name->autoDestroy();
}

void ClassMgr::unRegisterClass(FsString* name)
{
	m_cls->remove(name);
}


void ClassMgr::unRegisterAll()
{
	m_cls->clear();
}






NS_FS_END 




/* PreLoad FsClass */

#include "stage/entity/FsEntity.h"
#include "stage/entity/FsQuad2D.h"
#include "stage/entity/FsLabelTTF.h"
#include "stage/entity/FsLabelBitmap.h"
#include "stage/entity/FsVertexPolygon.h"

#include "stage/ui/FsUiWidget.h"
#include "stage/ui/FsListView.h"
#include "stage/ui/FsPageView.h"
#include "stage/ui/FsDynamicView.h"


#include "stage/ui/FsStateButton.h"
#include "stage/ui/FsToggleButton.h"
#include "stage/ui/FsPressButton.h"


#include "stage/FsScene.h"
#include "stage/layer/FsLayer.h"
#include "stage/layer/FsLayer2D.h"


NS_FS_BEGIN

#define FS_REGISTER_CLASS(cls) \
	registerClass(#cls,cls::getClass())

void ClassMgr::preRegisterClass()
{
	FS_REGISTER_CLASS(Entity);
	FS_REGISTER_CLASS(Quad2D);
	FS_REGISTER_CLASS(LabelTTF);
	FS_REGISTER_CLASS(LabelBitmap);
	FS_REGISTER_CLASS(VertexPolygon);

	FS_REGISTER_CLASS(UiWidget);
	FS_REGISTER_CLASS(ListView);
	FS_REGISTER_CLASS(PageView);
	FS_REGISTER_CLASS(DynamicView);
	FS_REGISTER_CLASS(StateButton);
	FS_REGISTER_CLASS(ToggleButton);
	FS_REGISTER_CLASS(PressButton);
	FS_REGISTER_CLASS(Scene);
	FS_REGISTER_CLASS(Layer);
	FS_REGISTER_CLASS(Layer2D);

}

NS_FS_END












