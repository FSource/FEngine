#ifndef _DM_PROCESS_BAR_H_
#define _DM_PROCESS_BAR_H_



NS_FS_USE;



class DmProcessBarDemo:public Scene 
{
	public:
		static DmProcessBarDemo* create()
		{
			DmProcessBarDemo* ret=new DmProcessBarDemo();
			return ret;
		}

	protected:
		DmProcessBarDemo()
		{
			initUiLayer();
			initProcessBar();

		}

		void initUiLayer()
		{
			m_layerUi=Layer2D::create();
			m_layerUi->setViewArea(0,0,DM_GAME_WIDTH,DM_GAME_HEIGHT);

			push(m_layerUi);

		}

		void initProcessBar()
		{
			float time=0.0f;
			auto fn=[time](Entity* en,float dt) mutable
			{
				ProcessBar* pb=(ProcessBar*) en;

				time+=dt*10;
				float percent=Math::abs(Math::sina(time));
				//FS_TRACE_WARN("percent=%f",percent);

				pb->setPercent(percent);
			};

			ProcessBar* p1=ProcessBar::create("processBarDemo/p1_bg.png",
											 "processBarDemo/p1_fg.png");
			p1->setPosition(500,500);
			p1->onUpdate=fn;

			m_layerUi->add(p1);

			/*  P2 */
			ProcessBar* p2=ProcessBar::create("processBarDemo/p1_bg.png",
											 "processBarDemo/p1_fg.png");
			p2->setPosition(500,400);
			p2->setReverseDirection(true);
			p2->onUpdate=fn;
			m_layerUi->add(p2);



			/* P3 */
			ProcessBar* p3=ProcessBar::create("processBarDemo/p1_bg.png",
											 "processBarDemo/p1_fg.png");
			p3->setPosition(500,300);
			p3->setSize(400,20);

			p3->onUpdate=fn;
			m_layerUi->add(p3);

			/* p4 */
			ProcessBar* p4=ProcessBar::create("processBarDemo/p3_bg.png",
											 "processBarDemo/p3_fg.png");
			p4->setPosition(200,200);
			p4->setDirection(E_AxisDirection::VERTICAL);
			p4->setReverseDirection(true);

			p4->onUpdate=fn;
			m_layerUi->add(p4);

			/* p5 */
			ProcessBar* p5=ProcessBar::create("processBarDemo/p3_bg.png",
											 "processBarDemo/p3_fg.png");
			p5->setPosition(800,200);

			p5->setDirection(E_AxisDirection::VERTICAL);
			p5->onUpdate=fn;
			m_layerUi->add(p5);

			/* p6 */
			ProcessBar* p6=ProcessBar::create(NULL,
											 "processBarDemo/p3_fg.png");
			p6->setPosition(500,100);
			p6->setDirection(E_AxisDirection::VERTICAL);
			p6->onUpdate=fn;
			m_layerUi->add(p6);

		}




	private:
		Layer2D* m_layerUi;

};






#endif /*_DM_PROCESS_BAR_H_*/


