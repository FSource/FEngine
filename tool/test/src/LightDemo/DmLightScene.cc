/*************************************************************************/
/*  DmLightScene.cc                                                      */
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
#include "demo3D.h"
#include "DmLightScene.h"

NS_FS_BEGIN

DmLightScene::DmLightScene()
{
	init();
}

DmLightScene* DmLightScene::create()
{
	DmLightScene* scene = new DmLightScene();
	return scene;
}

bool DmLightScene::init()
{
	initLayer3D();
	initLayer2D();
	init3DObject();
	initAmbientLight();
	initPointLight();
	initDirectionLight();
	initHemiSphereLight();
	initSpotLight();
	initCamera();

	return true;
}



void DmLightScene::initLayer2D()
{
	m_layer2D = Layer2D::create();	
	push(m_layer2D);

	m_layer2D->setViewArea(0, 0, GAME_WIDTH, GAME_HEIGHT);
	m_layer2D->setTouchEnabled(true);
	m_layer2D->setDispatchTouchEnabled(true);
	m_layer2D->setSortMode(Layer2D::SORT_ORDER_Z);

	initButtons();

}

void DmLightScene::initButtons()
{


	/*  ambeint button */
	ToggleButton* ambient_button =ToggleButton::createWithColorStyle("images/button_bg.png",Color(27,161,226),Color(100,100,100));
	ambient_button->setPosition(120,GAME_HEIGHT-120);
	ambient_button->setSize(120,40);

	LabelTTF* am_text=LabelTTF::create("font/arial.ttf",20,"Ambient:on");
	ambient_button->addChild(am_text);

	ambient_button->onToggleChanged = [this,am_text](ToggleButton* tb,bool t) 
	{
		if(t)
		{
			am_text->setString("Ambient:on");
			m_ambientLight->setToggleOn(true);
		}
		else 
		{
			am_text->setString("ambient:off");
			m_ambientLight->setToggleOn(false);
		}
	};
	m_layer2D->add(ambient_button);

	/*  point button */
	ToggleButton* point_button =ToggleButton::createWithColorStyle("images/button_bg.png",Color(27,161,226),Color(100,100,100));
	point_button->setPosition(120,GAME_HEIGHT-180);
	point_button->setSize(120,40);

	LabelTTF* po_text=LabelTTF::create("font/arial.ttf",20,"Point:on");
	point_button->addChild(po_text);

	point_button->onToggleChanged = [this,po_text](ToggleButton* tb,bool t) 
	{
		if(t)
		{
			po_text->setString("Point:on");
			for(PointLight* l:m_pointLight)
			{
				l->setToggleOn(true);
			}
		}
		else 
		{
			po_text->setString("Point:off");
			for(PointLight* l:m_pointLight)
			{
				l->setToggleOn(false);
			}
		}
	};
	m_layer2D->add(point_button);



	/* dir light */

	ToggleButton* dir_button =ToggleButton::createWithColorStyle("images/button_bg.png",Color(27,161,226),Color(100,100,100));
	dir_button->setPosition(120,GAME_HEIGHT-240);
	dir_button->setSize(120,40);

	LabelTTF* dr_text=LabelTTF::create("font/arial.ttf",20,"Direction:on");
	dir_button->addChild(dr_text);

	dir_button->onToggleChanged = [this,dr_text](ToggleButton* tb,bool t) 
	{
		if(t)
		{
			dr_text->setString("Direction:on");
			m_dirLight->setToggleOn(true);
		}
		else 
		{
			dr_text->setString("Direction:off");
			m_dirLight->setToggleOn(false);
		}
	};
	m_layer2D->add(dir_button);


	/*hemi sphere light */

	ToggleButton* hp_button =ToggleButton::createWithColorStyle("images/button_bg.png",Color(27,161,226),Color(100,100,100));
	hp_button->setPosition(120,GAME_HEIGHT-300);
	hp_button->setSize(120,40);

	LabelTTF* hp_text=LabelTTF::create("font/arial.ttf",20,"Hemi:on");
	hp_button->addChild(hp_text);

	hp_button->onToggleChanged = [this,hp_text](ToggleButton* tb,bool t) 
	{
		if(t)
		{
			hp_text->setString("Hemi:on");
			m_hemiSphereLight->setToggleOn(true);
		}
		else 
		{
			hp_text->setString("Hemi:off");
			m_hemiSphereLight->setToggleOn(false);
		}
	};
	m_layer2D->add(hp_button);


	/* spot light button */
	ToggleButton* sp_button =ToggleButton::createWithColorStyle("images/button_bg.png",Color(27,161,226),Color(100,100,100));
	sp_button->setPosition(120,GAME_HEIGHT-360);
	sp_button->setSize(120,40);

	LabelTTF* sp_text=LabelTTF::create("font/arial.ttf",20,"Spot:on");
	sp_button->addChild(sp_text);

	sp_button->onToggleChanged = [this,sp_text](ToggleButton* tb,bool t) 
	{
		if(t)
		{
			sp_text->setString("Spot:on");
			m_spotLight->setToggleOn(true);
		}
		else 
		{
			sp_text->setString("Spot:off");
			m_spotLight->setToggleOn(false);
		}
	};
	m_layer2D->add(sp_button);



}

void DmLightScene::goBack()
{
	Global::director()->pop();
}

void DmLightScene::initLayer3D()
{
	m_layer3D = Layer3D::create();
	this->push(m_layer3D);

}

void DmLightScene::init3DObject()
{

	///<create a 3d sprite by format obj
	Texture2D* tex = Global::textureMgr()->loadTexture("images/Coin.png");
	tex->setMipmapEnabled(true);
	tex->setWrap(E_TextureWrap::REPEAT, E_TextureWrap::REPEAT);
	tex->setFilter(E_TextureFilter::LINEAR, E_TextureFilter::LINEAR);
	



	Sprite3D* torus3d = Sprite3D::create("model/obj/torus3d.obj");
	float scale = 100.0f;
	torus3d->setPosition(-60.0f, 0.0f, 0.0f);
	torus3d->setScale(scale, scale, scale);
	auto fn= [](Entity* entity, float dt)
	{
		Sprite3D* sp = (Sprite3D*)entity;
		sp->rotate(0, dt*20.0f, 0);
	};
	torus3d->onUpdate = fn;
	m_layer3D->add(torus3d);



	Material3D* mtl = Material3D::createLambertMaterial();
	mtl->setProgramSourceUrl("shader/phong.fshader");
	mtl->setEmissive(Color3f(0.0, 0.0, 0.0));
	mtl->setAmbient(Color3f(1.0, 1.0, 1.0));
	mtl->setShininess(60);


	mtl->setColorMap(tex);

	torus3d->getSprite3DChunk(0)->setMaterial(mtl);

	/* torus3d 2 */

	torus3d = Sprite3D::create("model/obj/torus3d.obj");
	torus3d->setPosition(60.0f, 0.0f, 0.0f);
	torus3d->setScale(scale, scale, scale);

	torus3d->onUpdate= [](Entity* entity, float dt)
	{
		Sprite3D* sp = (Sprite3D*)entity;
		sp->rotate(dt*10, dt*25.0f, 0);
	};
	m_layer3D->add(torus3d);

	mtl = Material3D::createLambertMaterial();
	mtl->setProgramSourceUrl("shader/lambert.fshader");
	mtl->setEmissive(Color3f(0.0, 0.0, 0.0));
	mtl->setAmbient(Color3f(1.0, 1.0, 1.0));
	mtl->setShininess(60);
	mtl->setColorMap(tex);
	torus3d->getSprite3DChunk(0)->setMaterial(mtl);


	Sprite3D* pl=Sprite3D::create("model/obj/cube5.obj");
	pl->setScale(scale*1.5,scale,scale);
	m_layer3D->add(pl);

	Material3D* pl_mtl=Material3D::createLambertMaterial();
	pl_mtl->setProgramSourceUrl("shader/phong.fshader");
	pl_mtl->setShininess(50);
	pl->getSprite3DChunk(0)->setMaterial(pl_mtl);

}



void DmLightScene::initAmbientLight()
{

	AmbientLight* light = AmbientLight::create();
	light->setColor(Color3f(1.0, 1.0, 1.0));
	light->setIntensity(0.08f);
	m_layer3D->addLight(light);

	m_ambientLight=light;
}

void DmLightScene::initCamera()
{

	///<create a  camera
	PerspectiveCamera* camera = PerspectiveCamera::create();
	camera->set(30.0f, (float)Global::window()->getWidth()/(float)Global::window()->getHeight(), 1.0f, 1000.0f);
	camera->setPosition(-0.0f, 200.0f, 250.0f);
	camera->lookAt(Vector3(-0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
	m_layer3D->setCamera(camera);

	m_camera=camera;

}
void DmLightScene::initPointLight()
{
	struct PointLightInfo
	{
		Color3f color;
		Vector3 pos;
		float distance;
		float angle;
	};

	PointLightInfo point_lights[]={
		{
			Color3f(1.0f,0.0f,0.0f),
			Vector3(0,0,0),
			100,
			0,
		},
		{
			Color3f(0.0f,1.0f,0.0f),
			Vector3(-90,90,0),
			250,
			0,
		},
		{
			Color3f(0.0f,0.0f,1.0f),
			Vector3(90,90,0),
			250,
			180,
		},
	};

	int size=sizeof(point_lights)/sizeof(PointLightInfo);


	for( int i=0;i<size;i++)
	{
		PointLight* l=PointLight::create();
		l->setColor(point_lights[i].color);
		l->setPosition(point_lights[i].pos);
		l->setDistance(point_lights[i].distance);

		Sprite3D* l_mark=Sprite3D::create("model/obj/cube.obj");
		Material3D* l_mtl=Material3D::createColorMaterial();
		l_mtl->setColor(point_lights[i].color);
		l_mark->getSprite3DChunk(0)->setMaterial(l_mtl);

		m_layer3D->addLight(l);

		l->addChild(l_mark);

		float angle=point_lights[i].angle;

		l->setUserData(new float(angle));
		l->onUpdate=[i](Entity* en ,float dt)
		{
			float* angle=(float*)en->getUserData();

			if(i==0)
			{
				*angle+=dt*40;
				float dis=Math::cosa(*angle);
				//((PointLight*)en)->setIntensity(Math::abs(dis));
			}
			else if(i==1)
			{
				*angle+=dt*40;
				float x=Math::cosa(*angle)*140;
				float y=Math::sina(*angle)*90;
				en->setPosition(x,y,0);
			}
			else if(i==2)
			{
				*angle+=dt*50;
				float x=Math::cosa(*angle)*90;
				float y=Math::sina(*angle)*90;
				en->setPosition(0,x,y);
			}
		};

		l->onFinalize=[](FsObject* ob)
		{
			delete (float*)ob->getUserData();
		};

		m_pointLight.push_back(l);
	}


}

void DmLightScene::initDirectionLight()
{
	Color c= Color(162,0,255);
	m_dirLight=DirectionalLight::create();
	m_dirLight->setPosition(0.0f,130.0f,0.0f);
	m_dirLight->setColor(c);
	m_dirLight->setIntensity(0.15f);

	m_layer3D->addLight(m_dirLight);

	m_dirLight->setScale(5,0.5,0.5);
	m_dirLight->setUserData(new float(0.0));

	m_dirLight->onUpdate=[this](Entity* en,float dt)
	{
		float* value=(float*)en->getUserData();
		*value=*value+dt*30;

		float dx=Math::cosa(*value);
		float dy=Math::sina(*value);

		m_dirLight->setDirection(Vector3(dx,dy,0));
		m_dirLight->setRotateZ(*value);
	};

	m_dirLight->onFinalize=[](FsObject* ob)
	{
		delete (float*)ob->getUserData();
	};


	Sprite3D* l_mark=Sprite3D::create("model/obj/cube.obj");


	Sprite3D* l_mark_l=Sprite3D::create("model/obj/cube.obj");
	Sprite3D* l_mark_r=Sprite3D::create("model/obj/cube.obj");

	l_mark_l->setPosition(-0.5,5,0);
	l_mark_r->setPosition(-0.5,-5,0);
	l_mark->addChild(l_mark_l);
	l_mark->addChild(l_mark_r);



	Material3D* l_mtl=Material3D::createColorMaterial();
	l_mtl->setColor(c);
	l_mark->getSprite3DChunk(0)->setMaterial(l_mtl);
	l_mark_l->getSprite3DChunk(0)->setMaterial(l_mtl);
	l_mark_r->getSprite3DChunk(0)->setMaterial(l_mtl);

	m_dirLight->addChild(l_mark);
}

void DmLightScene::initHemiSphereLight()
{
	m_hemiSphereLight=HemiSphereLight::create();
	m_hemiSphereLight->setDirection(Vector3(0,-1,0));
	m_hemiSphereLight->setIntensity(0.08f);

	m_hemiSphereLight->setSkyColor(Color3f::WHITE);
	m_hemiSphereLight->setGroundColor(Color3f::BLUE);

	m_layer3D->addLight(m_hemiSphereLight);

}

void DmLightScene::initSpotLight()
{
	m_spotLight=SpotLight::create();
	m_spotLight->setPosition(0,90,0);
	m_spotLight->setAngle(45);
	m_spotLight->setExponent(60);
	m_spotLight->setDistance(1500);
	m_spotLight->setTargetPosition(Vector3(0,0,0));
	m_spotLight->setIntensity(0.9);

	m_spotLight->setUserData(new float(0));

	m_spotLight->onUpdate=[this](Entity* en,float dt)
	{
		float* value=(float*)m_spotLight->getUserData();
		*value=*value+dt;
		float x=Math::sinr(*value)*90;
		m_spotLight->setTargetPosition(Vector3(x,0,0));
	};
	m_spotLight->onFinalize=[this](FsObject*)
	{
		delete (float*)m_spotLight->getUserData();
	};

	m_layer3D->addLight(m_spotLight);

}






NS_FS_END
