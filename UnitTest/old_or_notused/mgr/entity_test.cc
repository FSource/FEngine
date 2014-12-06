#include "mgr/FsTextureMgr.h"
#include "graphics/FsTexture2D.h"
#include "common/FsGlobal.h"
#include "scene/FsLayer2D.h"
#include "scene/FsScene.h"
#include "entity/FsColorQuad2D.h"
#include "entity/FsQuad2D.h"
#include "graphics/FsFontTTF.h"
#include "entity/FsLabelTTF.h"

NS_FS_USE
int main()
{
	Global::moduleInit();

	Scene* scene=Scene::create();

	FontTTF* font=FontTTF::create("UbuntuMono-RI.ttf",10);
	FontTTF* font2=FontTTF::create("UbuntuMono-RI.ttf",20);

	LabelTTF* t6=LabelTTF::create("sfssfsfsa2r32r9vlknfas;fjagh;wiorje;lgnbf",font);

	Layer2D* layer=Layer2D::create();
	Entity* t1=Quad2D::create("tree1.png");
	Entity* t2=Quad2D::create("tree2.png");
	Entity* t3=Quad2D::create("tree3.png");
	Entity* t4=Quad2D::create("tree1.png");

	Entity* t5=ColorQuad2D::create(Rect2D(20,20,20,20),Color::WHITE);

	t1->addChild(t2);
	t2->addChild(t3);

	t3->addChild(t4);

	layer->add(t1);
	layer->add(t5);
	layer->add(t6);

	t3->remove(t4);

	scene->push(layer);
	scene->push(layer);

	layer->decRef();
	t1->decRef();
	t2->decRef();
	t3->decRef();
	t4->decRef();
	t5->decRef();
	t6->decRef();

	scene->decRef();
	font->decRef();
	font2->decRef();

	

	Global::moduleExit();
	return 0;

}

