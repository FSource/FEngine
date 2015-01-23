/*************************************************************************/
/*  DmMaterialScene.cc                                                   */
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
#include "DmMaterialScene.h"
#include "DmColorSlider.h"
#include "DmMaterialListItem.h"

NS_FS_BEGIN

DmMaterialScene* DmMaterialScene::create()
{
	DmMaterialScene* ret=new DmMaterialScene();
	ret->init();
	return ret;
}

DmMaterialScene::DmMaterialScene()
{
	m_focusMaterialItem=NULL;
}



DmMaterialScene::~DmMaterialScene()
{
}

void DmMaterialScene::init() 
{
	initLayer3D();
	initLayer2D();

	initCamera();
	initObjects();

	initLight();
	initColorSlider();
	initMaterials();
}


void DmMaterialScene::initLayer2D()
{
	m_layer2D =Layer2D::create();
	m_layer2D->setViewArea(0,0,GAME_WIDTH,GAME_HEIGHT);
	m_layer2D->setTouchEnabled(true);
	m_layer2D->setDispatchTouchEnabled(true);
	m_layer2D->setSortMode(Layer2D::SORT_ORDER_Z);
	this->push(m_layer2D);
}

void DmMaterialScene::initLayer3D()
{
	m_layer3D=Layer3D::create();
	this->push(m_layer3D);

}

void DmMaterialScene::initCamera()
{
#if 1 
	///<create a  camera
	OrthographicsCamera* camera = OrthographicsCamera::create();
	/*
	float width= (float)Global::window()->getWidth(); 
	float height= (float)Global::window()->getHeight();
	*/
	float width= 1000;
	float height= 600;

	camera->set(-width/2,width/2,-height/2,height/2,0,10000);
	camera->setPosition(0, 0.0f, 200.0f);
	camera->lookAt(Vector3(-0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
#else 
	PerspectiveCamera* camera=PerspectiveCamera::create();
	float width= (float)Global::window()->getWidth(); 
	float height= (float)Global::window()->getHeight();
	camera->set(45,width/height,10,1000);
	camera->setPosition(0, 0.0f, 200.0f);
	camera->lookAt(Vector3(-0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
#endif



	m_layer3D->setCamera(camera);
}

void DmMaterialScene::initObjects()
{
	float scale=60;
	m_monkey=Sprite3D::create("model/obj/monkey.obj");
	m_monkey->setScale(100,100,100);

	m_layer3D->add(m_monkey);


	//mtl->setEmissive(Color::WHITE);

	m_monkey->setRotateY(180);
	//m_monkey->setPositionZ(-300);

	m_monkey->onUpdate=[](Entity* entity,float dt)
	{
		Sprite3D* sp=(Sprite3D*)entity;
		entity->rotate(0,dt*20.0f,0);
	};
}

void DmMaterialScene::initLight()
{
	DirectionalLight* dirLight=DirectionalLight::create();
	dirLight->setDirection(Vector3(0,-1,-1));

	dirLight->setColor(Color3f::WHITE);
	dirLight->setIntensity(1.0);
	
	m_layer3D->add(dirLight);


	AmbientLight* ambient_light=AmbientLight::create();
	ambient_light->setColor(Color3f::WHITE);
	ambient_light->setIntensity(0.3f);
	m_layer3D->add(ambient_light);


}

void DmMaterialScene::initColorSlider()
{
	Color4f dark_color("#ccccccff");
	LabelTTF* material_name= LabelTTF::create("font/simsun.ttc",18,"Name: Golden");
	material_name->setPosition(686,485);
	material_name->setAnchor(0,0.5);
	material_name->setColor(Color4f("#ccccccff"));
	m_layer2D->add(material_name);
	m_materialName=material_name;



	VertexPolygon* line=VertexPolygon::create();
	line->append(Vector2(687,470));
	line->append(Vector2(943,470));
	m_layer2D->add(line);
	line->setMode(E_DrawMode::LINES);
	line->setColor(Color4f("ccccccff"));


	m_ambientSlider=DmColorSlider::create("Ambient",Color3f());
	m_ambientSlider->setPosition(691,346);
	m_layer2D->add(m_ambientSlider);
	
	m_ambientSlider->onColorChange=[this](DmColorSlider*,Color3f c)
	{
		m_material->setAmbient(c);
	};



	m_diffuseSlider=DmColorSlider::create("Diffuse",Color());
	m_diffuseSlider->setPosition(691,224);
	m_layer2D->add(m_diffuseSlider);
	m_diffuseSlider->onColorChange=[this](DmColorSlider*,Color3f c)
	{
		m_material->setDiffuse(c);
	};



	m_specularSlider=DmColorSlider::create("Specular",Color());
	m_specularSlider->setPosition(691,105);
	m_layer2D->add(m_specularSlider);
	m_specularSlider->onColorChange=[this](DmColorSlider*,Color3f c)
	{
		m_material->setSpecular(c);
	};

	UiWidget* shiness_panel=UiWidget::create(300,50);
	shiness_panel->setBgColor(Color4f(1.0f,1.0f,1.0f,0.20f));
	shiness_panel->setBgEnabled(true);
	shiness_panel->setAnchor(0,0);
	shiness_panel->setPosition(691,46);
	m_layer2D->add(shiness_panel);

	LabelTTF* shiniss_text=LabelTTF::create("font/arial.ttf",18,"Shiness");
	shiniss_text->setPosition(7,41);
	shiniss_text->setAnchor(0,0.5);
	shiniss_text->setColor(dark_color);
	shiness_panel->addChild(shiniss_text);

	LabelTTF* shiniss_value=LabelTTF::create("font/arial.ttf",13,"1.0");
	shiniss_value->setPosition(255,15);
	shiniss_value->setAnchor(0,0.5);
	shiniss_value->setColor(dark_color);
	shiness_panel->addChild(shiniss_value);
	m_shininessValue=shiniss_value;

	LabelTTF* shiness_value_text=LabelTTF::create("font/arial.ttf",13,"value:");
	shiness_value_text->setPosition(15,15);
	shiness_value_text->setAnchor(0,0.5);
	shiness_value_text->setColor(dark_color);
	shiness_panel->addChild(shiness_value_text);


	m_shininessSilder=DmSlideBar::create(Vector2(174,7),Color4f::BLUE,
															Vector2(10,13),Color4f::WHITE);

	m_shininessSilder->onPercentChange=[this](DmSlideBar* ,float value)
	{
		m_material->setShininess(value*200);
		setShininessValue(value*200);
	};

	m_shininessSilder->setPosition(150,15);
	shiness_panel->addChild(m_shininessSilder);




}

void DmMaterialScene::initMaterials()
{
	LabelTTF* title=LabelTTF::create("font/arial.ttf",18,"Material List");
	title->setPosition(125,488);
	m_layer2D->add(title);
	title->setColor(Color4f("#ccccccff"));

	VertexPolygon* line=VertexPolygon::create();
	line->append(Vector2(16,470));
	line->append(Vector2(241,470));
	m_layer2D->add(line);
	line->setMode(E_DrawMode::LINES);
	line->setColor(Color4f("ccccccff"));


	ListView* list_view=ListView::create(223,423);

	float martin=10;
	list_view->setMargin(martin,martin,martin,martin);

	list_view->setBgColor(Color4f(1.0f,1.0f,1.0f,0.2f));
	list_view->setBgEnabled(true);
	list_view->setPosition(20,29);
	list_view->setAnchor(0,0);
	list_view->setListGap(4);
	list_view->setDispatchTouchEnabled(true);

	m_layer2D->add(list_view);


	FsDict* dict=Global::felisScriptMgr()->loadDict("MaterialDemo/material_list.flis");

	FsArray* array=ScriptUtil::getArray(dict,"materials");
	FsString* path=ScriptUtil::getString(dict,"path");

	int material_nu=array->size();

	for(int i=0;i<material_nu;i++)
	{
		FsDict* entry=ScriptUtil::getDict(array,i);
		FsString* name=ScriptUtil::getString(entry,"name");
		FsString* url=ScriptUtil::getString(entry,"url");

		FsString* cname=ScriptUtil::getString(entry,"cname");
		

		if(name==NULL||url==NULL)
		{
			continue;
		}

		std::string material_path=std::string(path->cstr())+std::string(url->cstr());

		Material3D* mtl=(Material3D*)Global::material3DMgr()->load(material_path.c_str());
		if(mtl==NULL)
		{
			FS_TRACE_WARN("Can't Load Material(%s)",material_path.c_str());
			continue;
		}

		mtl->setProgramSourceUrl("shader/phong.fshader");

		DmMaterialListItem* item=DmMaterialListItem::create(name->cstr(),cname? cname->cstr():"",material_path.c_str());
		if(i==0)
		{
			setMaterial(name->cstr(),cname?cname->cstr():"",mtl);
			item->setFocus(true);
			m_focusMaterialItem=item;
		}
		list_view->addListItem(item);

		item->onClick=[this](DmMaterialListItem* e)
		{
			if(m_focusMaterialItem==e)
			{
				e->setFocus(true);
				return ;
			}

			if(m_focusMaterialItem)
			{
				m_focusMaterialItem->setFocus(false);
			}

			m_focusMaterialItem=e;
			e->setFocus(true);
			Material3D* mtl=Material3D::create(e->getMaterial());
			mtl->setProgramSourceUrl("shader/phong.fshader");

			setMaterial(e->getName(),e->getCName(),mtl);

		};
	}
}

void DmMaterialScene::setMaterial(const char* name,const char* cname,Material3D* mtl)
{
	char buf[1280];
	if (*cname)
	{
		sprintf(buf,"Name: %s(%s)",name,cname);
	}
	else 
	{
		sprintf(buf,"Name: %s",name);
	}

	m_materialName->setString(buf);

	m_ambientSlider->setColor(mtl->getAmbient());
	m_diffuseSlider->setColor(mtl->getDiffuse());
	m_specularSlider->setColor(mtl->getSpecular());
	m_material=mtl;
	m_monkey->getSprite3DChunk(0)->setMaterial(mtl);

	m_shininessSilder->setPercent(mtl->getShininess()/200);
	setShininessValue(mtl->getShininess());

}
void DmMaterialScene::setShininessValue(float value)
{
	char buf[128];
	sprintf(buf,"%.1f",value);
	m_shininessValue->setString(buf);
}








NS_FS_END


