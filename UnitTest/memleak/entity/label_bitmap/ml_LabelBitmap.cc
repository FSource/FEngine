#include <stdio.h>
#include <math.h>

#include "stage/entity/FsLabelBitmap.h"
#include "stage/FsScene.h"
#include "stage/layer/FsLayer2D.h"
#include "FsGlobal.h"
#include "graphics/FsFontBitmap.h"
#include "FsFaerisModule.h"


NS_FS_USE
class MyLayer:public Layer2D 
{
	public:
		MyLayer()
		{
			FontBitmap* font=FontBitmap::create("font.fnt");
			LabelBitmap* label=LabelBitmap::create(font);

			label->setString("My Name Is ChenLin(陈林)");
			label->setPosition(200,300,0);

			m_label2=LabelBitmap::create(font);
			m_label2->setString("Hello world");
			m_label2->setPosition(200,400,0);


			m_time=0;
			add(label);
			add(m_label2);
			m_labe=label;

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
			m_labe->setString(buf);
		}

	private:
		float m_time;
		LabelBitmap* m_labe;
		LabelBitmap* m_label2;
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












