#include "DmAnimationScene.h"
#include "Common/DmListView.h"
#include "Common/DmListItem.h"


DmAnimationScene* DmAnimationScene::create()
{
	DmAnimationScene* ret=new DmAnimationScene();
	return ret;
}



DmAnimationScene::DmAnimationScene()
{
	m_layoutList=NULL;
	m_uiLayer=NULL;
	m_layoutLayer=NULL;
	m_layoutListView=NULL;
	m_animationView=NULL;
	m_animList=NULL;

	initUiLayer();
	initLayoutList();
	initAnimationWidget();
}


DmAnimationScene::~DmAnimationScene()
{

}

void DmAnimationScene::initUiLayer()
{
	m_uiLayer=Layer2D::create();
	m_uiLayer->setViewArea(0,0,DM_GAME_WIDTH,DM_GAME_HEIGHT);
	m_uiLayer->setTouchEnabled(true);
	m_uiLayer->setDispatchTouchEnabled(true);

	this->push(m_uiLayer);
}


void DmAnimationScene::initLayoutList()
{
	FsDict* cfg=Global::felisScriptMgr()->loadDict("animationDemo/animationDemoCfg.fls");
	m_layoutList=cfg->lookupArray("layoutList");


	/* title */
	LabelTTF* title=LabelTTF::create("font/arial.ttf",18,"Layout List");
	title->setPosition(116,484);
	title->setColor(Color4f("#ccccccff"));
	m_uiLayer->add(title);


	/* line */
	VertexPolygon* line=VertexPolygon::create();
	line->append(Vector2(20,464));
	line->append(Vector2(200,464));
	line->setMode(E_DrawMode::LINES);
	line->setColor(Color4f("ccccccff"));

	m_uiLayer->add(line);

	/* List View  */
	DmListView* list_view=DmListView::create(180,423);

	list_view->setBgColor(Color4f(1.0f,1.0f,1.0f,0.2f));
	list_view->setBgEnabled(true);

	float martin=10;
	list_view->setMargin(martin,martin,martin,martin);

	list_view->setPosition(20,28);
	list_view->setAnchor(0,0);
	list_view->setListGap(4);


	m_uiLayer->add(list_view);

	int layout_nu=m_layoutList->size();
	for(int i=0;i<layout_nu;i++)
	{
		FsString* layout_str=m_layoutList->getDict(i)->lookupString("name");
		DmListItem* item=DmListItem::create(layout_str->cstr(),162,40);
		list_view->addListItem(item);
	}

	list_view->onSelected=[this](int index)
	{
		setCurrentSelect(index);
	};




}

void DmAnimationScene::initAnimationWidget()
{
	/* title */
	LabelTTF* title=LabelTTF::create("font/arial.ttf",18,"Animation List");
	title->setPosition(880,484);
	title->setColor(Color4f("#ccccccff"));
	m_uiLayer->add(title);


	/* line */
	VertexPolygon* line=VertexPolygon::create();
	line->append(Vector2(788,464));
	line->append(Vector2(970,464));
	line->setMode(E_DrawMode::LINES);
	line->setColor(Color4f("ccccccff"));

	m_uiLayer->add(line);

	/* List View  */
	DmListView* list_view=DmListView::create(180,423);

	list_view->setBgColor(Color4f(1.0f,1.0f,1.0f,0.2f));
	//list_view->setBgTexture("ShaderDemo/images/blur/2.jpg");
	list_view->setBgEnabled(true);


	float martin=10;
	list_view->setMargin(martin,martin,martin,martin);

	list_view->setPosition(790,28);
	list_view->setAnchor(0,0);
	list_view->setListGap(4);

	list_view->setDispatchTouchEnabled(true);
	m_uiLayer->add(list_view);

	m_animationView=list_view;
	m_animationView->onSelected=[this](int index)
	{
		setCurrentAnimaiton(index);
	};


}

void DmAnimationScene::resetAnimatiionView()
{
	m_animationView->clearChild();

	if(!m_animList)
	{
		return;
	}

	int size=m_animList->size();

	for(int i=0;i<size;i++)
	{
		FsString* flist=m_animList->getString(i);
		DmListItem* item=DmListItem::create(flist->cstr(),162,40);
		m_animationView->addListItem(item);
	}

}



void DmAnimationScene::setCurrentAnimaiton(int index)
{
	FsString* flist=m_animList->getString(index);
	printf("current animation is %s\n",flist->cstr());
	m_layoutLayer->traverseEntity([flist](Entity2D* en){
		en->startAnimation(flist->cstr(),E_AnimPlayMode::LOOP);
			});

}


void DmAnimationScene::setCurrentSelect(int index)
{
	FsDict* cfg=m_layoutList->getDict(index);

	if(m_layoutLayer)
	{
		remove(m_layoutLayer);
		m_layoutLayer=NULL;
	}
	
	FsString* url=cfg->lookupString("url");
	FsDict* dict=Global::felisScriptMgr()->loadDict(url->cstr());
	Layer2D* l=(Layer2D*)Global::classMgr()->newInstance(dict);

	m_layoutLayer=l;
	insert(0,l);
	FsArray* anim_list=dict->lookupArray("animationsList");
	m_animList=anim_list;
	resetAnimatiionView();

}











