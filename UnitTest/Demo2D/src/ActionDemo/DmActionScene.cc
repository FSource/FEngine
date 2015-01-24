#include "DmActionScene.h"

NS_FS_BEGIN

class MyEntity:public Quad2D 
{
	public:
		MyEntity()
		{
			bool ret=Quad2D::init("images/play.png");
			assert(ret);
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
			sq->addAction(MoveAction::createBy(Vector3(x+20,y+20,0),Vector3(-20,-20,0),2));

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
			setViewArea(0,0,DM_GAME_WIDTH,DM_GAME_HEIGHT);
			int nu=10;

			for(int i=0;i<nu;i++)
			{
				MyEntity* e1=new MyEntity();
				for(int j=0;j<nu;j++)
				{
					MyEntity* e2=new MyEntity();
					for(int z=0;z<nu;z++)
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

};

ActionScene* ActionScene::create()
{
	ActionScene* ret=new ActionScene();
	ret->push(MyLayer::create());
	return ret;
}



NS_FS_END 

