#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "stage/FsScene.h"
#include "stage/layer/FsLayer2D.h"
#include "stage/entity/FsQuad2D.h"
#include "FsGlobal.h"
#include "FsFaerisModule.h"
#include "stage/action/FsAction.h"
#include "stage/action/FsRotateAction.h"
#include "stage/action/FsScaleAction.h"
#include "stage/action/FsMoveAction.h"
#include "stage/action/FsSeqAction.h"
#include "stage/action/FsPauseAction.h"



NS_FS_USE

class MyEntity:public Quad2D 
{
	public:
		MyEntity()
		{
			Quad2D::init("play.png");
			m_time=rand()%100+3;
			int x=rand()%960;
			int y=rand()%640;
			setPosition(x,y,0);

			Action* a1=MoveAction::createBy(Vector3(x,y,0),Vector3(20,20,0),2);
			Action* a2=ScaleAction::createFromTo(Vector3(1,1,1),Vector3(2,2,1),1);
			Action* a3=RotateAction::createFromTo(Vector3(0,0,0),Vector3(0,0,30),2);

			doAction(a1);
			doAction(a2);
			doAction(a3);

			SeqAction* sq=SeqAction::create();
			sq->addAction(PauseAction::create(5));
			sq->addAction(MoveAction::createBy(Vector3(20,20,0),Vector3(-20,-20,0),2));

			SeqAction* sq2=SeqAction::create();

			sq2->addAction(ScaleAction::createFromTo(Vector3(2,2,2),Vector3(1,1,1),2));
			sq2->addAction(RotateAction::createBy(Vector3(0,0,30),Vector3(0,0,-30),2));

			sq->addAction(sq2);

			doAction(sq);
		}


		void update(float dt)
		{
			Quad2D::update(dt);
			m_time-=dt;
			if(m_time<0)
			{
				detach();
			}
		}
	private:
		float m_time;
};

class MyLayer:public Layer2D 
{
	public:
		MyLayer()
		{

			for(int i=0;i<10;i++)
			{
				MyEntity* e1=new MyEntity();
				for(int j=0;j<10;j++)
				{
					MyEntity* e2=new MyEntity();
					for(int z=0;z<10;z++)
					{
						MyEntity* e3=new MyEntity();
						e2->addChild(e3);
					}
					e1->addChild(e2);
				}
				this->add(e1);
			}

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
		}

};

int main()
{
	srand(time(NULL));
	FsFaeris_ModuleInit();

	Window* win=Global::window();
	RenderDevice* render=Global::renderDevice();

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












