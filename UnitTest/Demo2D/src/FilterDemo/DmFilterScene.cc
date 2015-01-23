#include "DmFilterScene.h"
#include "Common/DmTextureChooseWidget.h"

#include "Common/DmListView.h"
#include "Common/DmListItem.h"

#include "stage/filter/FsOpacityFilter.h"
#include "stage/filter/FsGrayFilter.h"
#include "stage/filter/FsBrightnessFilter.h"
#include "stage/filter/FsColorMatrixFilter.h"



static Filter* Create_Filter(FsDict* dict)
{
	FsString* filter=dict->lookupString("filter");

	if(filter->equal("Gray"))
	{
		return GrayFilter::create();
	}
	else if(filter->equal("Opacity"))
	{
		OpacityFilter* ret=OpacityFilter::create();
		ret->setOpacity(dict->lookupString("opacity")->toFloatValue());
		return ret;
	}
	else if(filter->equal("Brightness"))
	{
		BrightnessFilter* ret=BrightnessFilter::create();
		ret->setBrightness(dict->lookupString("brightness")->toFloatValue());
		return ret;
	}
	else if (filter->equal("ColorMatrix"))
	{
		ColorMatrixFilter* ret=ColorMatrixFilter::create();
		if(dict->lookupArray("colorMatrix"))
		{
			FsArray* mat=dict->lookupArray("colorMatrix");
			float value[16];

			int mat_nu=mat->size();
			for(int i=0;i<16;i++)
			{
				if(i<mat_nu)
				{
					value[i]=mat->getString(i)->toFloatValue();
				}
				else 
				{
					value[i]=0.0f;
				}
			}
			FsArray* col=dict->lookupArray("colorOffset");
			if(col)
			{
				int col_nu=col->size();
				float cv[4];
				for(int i=0;i<4;i++)
				{
					if(i<col_nu)
					{
						cv[i]=col->getString(i)->toFloatValue();
					}
					else 
					{
						cv[i]=0;
					}
				}
				ret->setColorOffset(Vector4f(cv[0],cv[1],cv[2],cv[3]));
			}

			ret->setColorMatrix(Matrix4(value));
		}
		else if (dict->lookupString("saturation"))
		{
			ret->setSaturation(dict->lookupString("saturation")->toFloatValue());
		}
		else if (dict->lookupString("brightness"))
		{
			ret->setBrightness(dict->lookupString("brightness")->toFloatValue());
		}
		else if (dict->lookupString("constrast"))
		{
			ret->setContrast(dict->lookupString("constrast")->toFloatValue());
		}
		else if(dict->lookupString("invert"))
		{
			ret->setInvert();
		}
		else if(dict->lookupString("sepia"))
		{
			ret->setSepia();
		}

		return ret;
	}


	return NULL;
}



DmFilterScene* DmFilterScene::create()
{
	DmFilterScene* ret=new DmFilterScene();
	return ret;
}



DmFilterScene::DmFilterScene()
{
	init();
}



void DmFilterScene::init()
{

	initCfg();
	initLayer2D();
	initCenterWidget();
	initShaderWidget();
	initFilterWidget();

	m_shaderListView->setSelected(0,true);
	m_filterListView->setSelected(0,true);
}


void DmFilterScene::initCfg()
{
	FsDict* cfg=Global::felisScriptMgr()->loadDict("FilterDemo/FilterDemoCfg.fls");

	m_shaderList=cfg->lookupArray("shaderList");
	m_filterList=cfg->lookupArray("filterList");

}




void DmFilterScene::initLayer2D()
{
	m_layer2D=Layer2D::create();
	m_layer2D->setViewArea(0,0,DM_GAME_WIDTH,DM_GAME_HEIGHT);
	m_layer2D->setTouchEnabled(true);
	m_layer2D->setDispatchTouchEnabled(true);
	m_layer2D->setSortMode(Layer2D::SORT_ORDER_Z);
	this->push(m_layer2D);

	Quad2D* bg=Quad2D::create("FilterDemo/7.jpg",DM_GAME_WIDTH,DM_GAME_HEIGHT);
	bg->setAnchor(0,0);
	m_layer2D->add(bg);


	FS_NO_REF_DESTROY(m_layer2D);
}


#define NORMAL_COLOR Color4f("#ccccccff")


void DmFilterScene::initShaderWidget()
{
	/* title */
	LabelTTF* title=LabelTTF::create("font/arial.ttf",18,"Object List");
	title->setPosition(116,484);
	title->setColor(NORMAL_COLOR);
	m_layer2D->add(title);

	/* line */
	VertexPolygon* line=VertexPolygon::create();
	line->append(Vector2(20,464));
	line->append(Vector2(200,464));
	line->setMode(E_DrawMode::LINES);
	line->setColor(NORMAL_COLOR);
	m_layer2D->add(line);


	/* list view */
	DmListView* list_view=DmListView::create(180,423);


	float martin=10;
	list_view->setMargin(martin,martin,martin,martin);

	list_view->setBgColor(Color4f(0.5f,0.5f,0.5f,0.5f));
	list_view->setBgEnabled(true);

	list_view->setPosition(20,28);
	list_view->setAnchor(0,0);
	list_view->setListGap(4);

	list_view->setDispatchTouchEnabled(true);
	m_layer2D->add(list_view);

	int object_nu=m_shaderList->size();

	for(int i=0;i<object_nu;i++)
	{
		FsDict* ob=m_shaderList->getDict(i);
		DmListItem* item=DmListItem::create(ob->lookupString("name")->cstr(),162,40);
		//item->setBgColor(Color4f("#1c11119f"));
		list_view->addListItem(item);
	}

	list_view->onSelected=[this](int index)
	{
		setShaderListIndex(index);
	};
	m_shaderListView=list_view;
}


void DmFilterScene::initFilterWidget()
{
	/* title */
	LabelTTF* title=LabelTTF::create("font/arial.ttf",18,"Shader List");
	title->setPosition(880,484);
	title->setColor(Color4f("#ccccccff"));
	m_layer2D->add(title);


	/* line */
	VertexPolygon* line=VertexPolygon::create();
	line->append(Vector2(788,464));
	line->append(Vector2(970,464));
	line->setMode(E_DrawMode::LINES);
	line->setColor(Color4f("ccccccff"));

	m_layer2D->add(line);

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
	m_layer2D->add(list_view);

	m_filterListView=list_view;
	m_filterListView->onSelected=[this](int index)
	{
		setCurrentFilter(index);
	};

	int size=m_filterList->size();

	for(int i=0;i<size;i++)
	{
		FsDict* flist=m_filterList->getDict(i);
		DmListItem* item=DmListItem::create(flist->lookupString("name")->cstr(),162,40);
		m_filterListView->addListItem(item);
	}
}

void DmFilterScene::setShaderListIndex(int index)
{
	FsDict* cfg=m_shaderList->getDict(index);
	m_quad->setTexture(cfg->lookupString("url")->cstr());
	m_quad->setSize(480,280);
}

void DmFilterScene::setCurrentFilter(int index)
{
	FsDict* cfg=m_filterList->getDict(index);
	m_centerWidget->setFilter(Create_Filter(cfg));
}



void DmFilterScene::initCenterWidget()
{
	m_centerWidget=UiWidget::create(540,320);
	m_centerWidget->setPosition(DM_GAME_WIDTH/2,DM_GAME_HEIGHT/2);
	m_centerWidget->setBgColor(Color4f(0.5f,0.5f,0.5f,1.0f));
	m_centerWidget->setBgEnabled(true);
	m_layer2D->add(m_centerWidget);

	m_quad=Quad2D::create();
	m_centerWidget->addChild(m_quad);
}














