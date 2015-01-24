#include "DmTextureChooseWidget.h"

DmTextureChooseWidget* DmTextureChooseWidget::create(FsArray* textures)
{
	DmTextureChooseWidget* ret=new DmTextureChooseWidget();
	ret->init(textures);
	return ret;
}

Layer2D* DmTextureChooseWidget::create(FsArray* textures,float x,float y,std::function<void(const char*)> fn)
{
	Layer2D* ret=Layer2D::create();
	ret->setViewArea(0,0,DM_GAME_WIDTH,DM_GAME_HEIGHT);
	ret->setTouchEnabled(true);
	ret->setDispatchTouchEnabled(true);

	DmTextureChooseWidget* widget=create(textures);
	widget->onTextureChoosed=fn;

	if(y>DM_GAME_HEIGHT/2) 
	{
		y-=DM_GAME_HEIGHT/2;
	}
	widget->setPosition(x,y);

	ret->onTouchBegin=[](Layer* l ,float x,float y)->bool 
	{
		bool ret=l->touchBegin(x,y);
		if(!ret)
		{
			l->getScene()->remove(l);
		}
		return true;
	};

	ret->add(widget);

	return ret;

}



DmTextureChooseWidget::DmTextureChooseWidget()
{
	setSize(DM_GAME_WIDTH/2,DM_GAME_HEIGHT/2);
	setAnchor(0.5f,0);
	setBgColor(Color4f(0.5f,0.5f,0.5f,0.8f));
	setBgEnabled(true);

	m_textureList=NULL;
	m_textureNames=NULL;
	m_selectQuad=NULL;
	m_selectTexture=NULL;
}

void DmTextureChooseWidget::init(FsArray* textures)
{
	FS_SAFE_ASSIGN(m_textureNames,textures);

	initSeleteQuad();
	initListView();
	initTitle();
	initPressButton();
}



void DmTextureChooseWidget::initSeleteQuad()
{
	m_selectQuad=Quad2D::create(Color4f(0.176f,0.537f,0.937f,1.0f),130,100);
	m_selectQuad->addRef();
	m_selectQuad->setZorder(-1);
}


void DmTextureChooseWidget::initListView()
{
	if(!m_textureNames) 
	{
		return ;
	}

	ListView* list_view=ListView::create(DM_GAME_WIDTH/2,200);
	list_view->setPosition(0,150);
	//list_view->setBgEnabled(true);
	list_view->setListGap(5);
	list_view->setDispatchTouchEnabled(true);

	addChild(list_view);

	int texture_nu=m_textureNames->size();
	int list_nu=(int)Math::ceil((float)texture_nu/3.0f);

	float startx=-150;
	float endx=150;

	float width=120;
	float height=90;

	for(int i=0;i<list_nu;i++)
	{
		UiWidget* widget=UiWidget::create(550,100); 
		widget->setBgColor(Color4f(1.0,0.0,0.0));
		widget->setDispatchTouchEnabled(true);
		//widget->setBgEnabled(true);
		int start_index=i*3;

		for(int j=0;j<3&&start_index+j<texture_nu;j++)
		{

			FsString* tex_url=NULL;

			if(m_textureNames->getString(start_index+j))
			{
				tex_url = m_textureNames->getString(start_index+j);
			}
			else
			{
				tex_url=m_textureNames->getDict(start_index+j)->lookupString("url");
				Texture2D* tex=Global::textureMgr()->loadTexture(tex_url->cstr());
				tex->setWrap(E_TextureWrap::REPEAT,E_TextureWrap::REPEAT);
			}

			Quad2D* q=Quad2D::create(tex_url->cstr(),width,height);
			q->setTouchEnabled(true);
			if(j==0)
			{
				q->setPosition(-150,0);
			}
			else if(j==1)
			{
				q->setPosition(0,0);
			}
			else if (j==2)
			{
				q->setPosition(150,0);
			}

			widget->addChild(q);
			int text_index=start_index+j;
			q->onTouchBegin=[this,text_index,tex_url](Entity* e,float x,float y)->bool
			{
				//FS_TRACE_WARN("Select %d Texture",text_index);
				if(m_selectQuad->getParent())
				{
					m_selectQuad->detach();
				}
				e->addChild(m_selectQuad);
				m_selectTexture=tex_url;

				return false;
			};

		}
		list_view->addListItem(widget);
	}
}


void DmTextureChooseWidget::initTitle()
{
	/* title */
	LabelTTF* title=LabelTTF::create("font/arial.ttf",18,"Texture Choose");
	title->setPosition(0,277);
	title->setColor(Color4f("#ccccccff"));
	this->addChild(title);

	/* line */
	VertexPolygon* line=VertexPolygon::create();
	line->append(Vector2(-280,258));
	line->append(Vector2(280,258));
	line->setMode(E_DrawMode::LINES);
	line->setColor(Color4f("ccccccff"));
	this->addChild(line);

}

void DmTextureChooseWidget::initPressButton()
{
	PressButton* ok_button=PressButton::createWithColorStyle("images/button_bg.png",Color4f(0.176f,0.573f,0.937f),Color4f(0.2f,0.2f,0.2f));
	ok_button->setSize(84,30);
	ok_button->setPosition(200,26);
	ok_button->onClick=[this](PressButton* ob)
	{
		if(m_selectTexture)
		{
			if(onTextureChoosed)
			{
				onTextureChoosed(m_selectTexture->cstr());
			}
			else 
			{
				onTextureChoosed(NULL);
			}
		}
		ob->getScene()->remove(ob->getLayer());

	};

	addChild(ok_button);
	LabelTTF* ok_text=LabelTTF::create("font/arial.ttf",13,"Ok");
	ok_button->addChild(ok_text);




	PressButton* cancel_button=PressButton::createWithColorStyle("images/button_bg.png",Color4f(0.376f,0.235f,0.729f),Color4f(0.2f,0.2f,0.2f));
	cancel_button->setSize(84,30);
	cancel_button->setPosition(100,26);
	cancel_button->onClick=[](PressButton* ob)
	{
		ob->getScene()->remove(ob->getLayer());
	};

	addChild(cancel_button);
	LabelTTF* cancel_text=LabelTTF::create("font/arial.ttf",13,"Cancel");
	cancel_button->addChild(cancel_text);

}


bool DmTextureChooseWidget::touchBegin(float x,float y)
{
	UiWidget::touchBegin(x,y);
	return true;
}




