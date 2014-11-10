#include <stdio.h>
#include <math.h>


#include "stage/FsScene.h"
#include "stage/layer/FsLayer2D.h"
#include "stage/entity/FsQuad2D.h"
#include "FsGlobal.h"
#include "FsFaerisModule.h"


NS_FS_USE
class MyLayer:public Layer2D 
{
	public:
		MyLayer()
		{
			m_time=0;
			m_quad1=Quad2D::create("play.png");
			m_quad1->setPosition(100,100,0);
			m_quad2=Quad2D::create("play.png");
			m_quad2->setPosition(200,200,0);
			m_quad3=Quad2D::create("settings.png");
			m_quad3->setPosition(300,300,0);


			this->add(m_quad1);
			this->add(m_quad2);
			this->add(m_quad3);
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
			m_time=m_time+dt;
			m_quad1->setRotateZ(m_time*10);
			m_quad2->setRotateZ(m_time*2*10);
			m_quad3->setRotateZ(m_time*3*10);
		}

	private:
		float m_time;
		Quad2D* m_quad1;
		Quad2D* m_quad2;
		Quad2D* m_quad3;
};

int main()
{
	FsFaeris_ModuleInit();

	Window* win=Global::window();
	Render* render=Global::render();

	win->setPosition(100,100);
	win->setSize(960,640);
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












