#include <stdio.h>
#include <math.h>


#include "stage/FsScene.h"
#include "stage/layer/FsLayer2D.h"
#include "stage/entity/FsSprite2D.h"
#include "FsGlobal.h"
#include "FsFaerisModule.h"


NS_FS_USE
class MyLayer:public Layer2D 
{
	public:
		MyLayer()
		{
			m_time=0;
			m_sprite1=Sprite2D::create("sprites/start.fst");
			m_sprite1->setPosition(400,100,0);
			m_sprite1->setScale(0.3,0.3,1);
			m_sprite1->setAnimation("default");
			m_sprite1->playAnimation();

			m_sprite2=Sprite2D::create("sprites/start.fst");
			m_sprite2->setPosition(200,200,0);
			m_sprite2->setScale(0.3,0.3,1);
			m_sprite2->setAnimation("default");
			m_sprite2->playAnimation();


			m_sprite3=Sprite2D::create("boy.fst");
			m_sprite3->setPosition(700,500,0);
			m_sprite3->setAnimation("walk");
			m_sprite3->playAnimation();

			m_state="walk";



			this->add(m_sprite1);
			this->add(m_sprite2);
			this->add(m_sprite3);
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
			Layer2D::update(dt);
			m_time=m_time+dt;

			if (m_time> 9)
			{
				m_time=0;
			}
			else if(m_time> 7)
			{
				if(m_state!="throw")
				{
					m_sprite3->setAnimation("throw");
					m_sprite3->playAnimation();
					m_state="throw";
				}
			}
			else if(m_time > 5) 
			{
				if(m_state!="run")
				{

					m_sprite3->setAnimation("run");
					m_sprite3->setFps(10);
					m_sprite3->playAnimation();
					m_state="run";
				}
			}
			else if(m_time> 3)
			{
				if(m_state!="strike")
				{
					m_sprite3->setAnimation("strike");
					m_sprite3->setAnimationOffset(-1,-1);
					m_sprite3->playAnimation();
					m_state="strike";
				}
			}

		}

	private:
		float m_time;
		Sprite2D* m_sprite1;
		Sprite2D* m_sprite2;
		Sprite2D* m_sprite3;
		std::string  m_state;
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












