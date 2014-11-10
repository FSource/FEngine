#include <stdio.h>
#include <math.h>

#include "stage/entity/FsLabelTTF.h"
#include "stage/entity/FsLabelTTF.h"
#include "graphics/FsFontTTF.h"

#include "stage/FsScene.h"
#include "stage/layer/FsLayer2D.h"
#include "FsGlobal.h"
#include "graphics/FsFontTTF.h"
#include "FsFaerisModule.h"


NS_FS_USE
class MyLayer:public Layer2D 
{
	public:
		MyLayer()
		{
			FontTTF* font=FontTTF::create("simsun.ttc",30);
			m_label1=LabelTTF::create(font);

			m_label1->setString("My Name Is ChenLin(陈林)");
			m_label1->setPosition(200,300,0);

			m_label2=LabelTTF::create(font);
			m_label2->setString("Hello world");
			m_label2->setPosition(200,400,0);


			m_time=0;
			add(m_label1);
			add(m_label2);


		}
	public:
		static MyLayer* create()
		{

			MyLayer* ret=new MyLayer();
			return ret;
		}

	public:
		virtual bool touchBegin(float x,float y)
		{
			Global::scheduler()->stop();
			return true;
		}
		virtual void update(float dt)
		{
			char buf[1000];
			m_time+=dt;
			sprintf(buf, "My Name Is ChenLin(陈林)%d",(int)floor(m_time));
			m_label1->setString(buf);
		}

	private:
		float m_time;
		LabelTTF* m_label1;
		LabelTTF* m_label2;
};

int main()
{
	FsFaeris_ModuleInit();

	Window* win=Global::window();
	Render* render=Global::render();

	win->setPosition(100,100);
	win->show();
	render->setRenderTarget(win);
	render->setClearColor(Color(0,0,0));



	Global::director()->setAutoSwapBuffers(true);

	Scene* scene=Scene::create();
	Layer2D* layer=MyLayer::create();

	layer->setTouchEnabled(true);


	scene->push(layer);

	layer->setViewArea(0,0,960,640);

	Global::director()->run(scene);

	Global::scheduler()->mainLoop();

	FsFaeris_ModuleExit();


	printf("FsFaeris_ModuleExit exit");

	return 0;
}












