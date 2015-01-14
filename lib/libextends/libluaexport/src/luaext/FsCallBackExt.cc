#include "FsCallBackExt.h"

NS_FS_BEGIN


/* --------------------  FsObject -----------------------*/
static void FsLFsObject_onFinalize(FsObject* ob)
{
	LuaEngine* engine=(LuaEngine*)Global::scriptEngine();
	if(engine)
	{
		engine->callFunctionInTable(ob->m_scriptData,"onFinalize",1,0,"u<FsObject>",ob);
	}
}

void FsLFsObject_CallBackAssign(FsObject* ob)
{
	ob->onFinalize=FsLFsObject_onFinalize;
}


/*   -------------------- Entity  ------------------------*/
static void FsLEntity_onUpdate(Entity* en,float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onUpdate",2,0,"fn",en,dt))
	{
		en->update(dt);
	}
}

static void FsLEntity_onDraw(Entity* en,RenderDevice* r,bool updateMatrix)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onDraw",2,0,"ff",en,r))
	{
		en->draw(r,updateMatrix);
	}
}

void FsLEntity_CallBackAssign(Entity* en)
{
	FsLFsObject_CallBackAssign(en);
	en->onUpdate=FsLEntity_onUpdate;
	en->onDraw=FsLEntity_onDraw;
}




/* ------------------------ Entity2D -------------------------------*/

static bool FsLEntity2D_onTouchBegin(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onTouchBegin",3,1,"fnn",en,x,y))
	{
		return en->touchBegin(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}
static bool FsLEntity2D_onTouchMove(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onTouchMove",3,1,"fnn",en,x,y))
	{
		return en->touchMove(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLEntity2D_onTouchEnd(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onTouchEnd",3,1,"fnn",en,x,y))
	{
		return  en->touchEnd(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLEntity2D_onHit2D(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onHit2D",3,1,"fnn",en,x,y))
	{
		return  en->hit2D(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

void FsLEntity2D_CallBackAssign(Entity2D* en)
{
	FsLEntity_CallBackAssign(en);
	en->onTouchBegin=FsLEntity2D_onTouchBegin;
	en->onTouchMove=FsLEntity2D_onTouchMove;
	en->onTouchEnd=FsLEntity2D_onTouchEnd;
	en->onHit2D=FsLEntity2D_onHit2D;
}


/* ---------------------- PressButton ----------------*/

static void FsLPressButton_onClick(PressButton* pb)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(pb->m_scriptData,"onClick",1,0,"f",pb))
	{
		pb->click();
	}
}

static void FsLPressbutton_onCancel(PressButton* pb)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(pb->m_scriptData,"onCancel",1,0,"f",pb))
	{
		pb->cancel();
	}
}


static void FsLPressButton_onPressDown(PressButton* pb,float x,float y)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(pb->m_scriptData,"onPressDown",3,0,"fnn",pb,x,y))
	{
		pb->pressDown(x,y);
	}
}


static void FsLPressButton_onPressMoveIn(PressButton* pb,float x,float y)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(pb->m_scriptData,"onPressMoveIn",3,0,"fnn",pb,x,y))
	{
		pb->pressMoveIn(x,y);
	}
}



static void FsLPressButton_onPressMoveOut(PressButton* pb,float x,float y)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(pb->m_scriptData,"onPressMoveOut",3,0,"fnn",pb,x,y))
	{
		pb->pressMoveOut(x,y);
	}
}


static void FsLPressButton_onPressUp(PressButton* pb,float x,float y)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(pb->m_scriptData,"onPressUp",3,0,"fnn",pb,x,y))
	{
		pb->pressUp(x,y);
	}
}

void FsLPressButton_CallBackAssign(PressButton* pb)
{
	FsLEntity2D_CallBackAssign(pb);
	pb->onClick=FsLPressButton_onClick;
	pb->onCancel=FsLPressbutton_onCancel;
	pb->onPressDown=FsLPressButton_onPressDown;
	pb->onPressMoveIn=FsLPressButton_onPressMoveIn;
	pb->onPressMoveOut=FsLPressButton_onPressMoveOut;
	pb->onPressUp=FsLPressButton_onPressUp;
}


/* ------------------------- ToggleButton ---------------------*/
static void FsLToggleButton_onToggleChanged(ToggleButton* tb,bool value)
{

	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(tb->m_scriptData,"onToggleChanged",2,0,"fb",tb,value))
	{
		tb->toggleChanged(value);
	}
}
void FsLToggleButton_CallBackAssign(ToggleButton* tb)
{
	FsLEntity2D_CallBackAssign(tb);
	tb->onToggleChanged=FsLToggleButton_onToggleChanged;
}




/* --------------------------- PageView -------------------------*/
static void FsLPageView_onPageIndexChanged(PageView* pv,int old_index,int new_index)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(pv->m_scriptData,"onPageIndexChanged",3,0,"fii",pv,old_index,new_index))
	{
		pv->pageIndexChanged(old_index,new_index);
	}

}
void FsLPageView_CallBackAssign(PageView* pv)
{
	FsLEntity2D_CallBackAssign(pv);
	pv->onPageIndexChanged=FsLPageView_onPageIndexChanged;
}


/* --------------------------- DynamicView ----------------------*/

static void FsLDynamicView_onCurrentViewChanged(DynamicView* dv,UiWidget* old_view,UiWidget* new_view)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	if(!se->callFunctionInTable(dv->m_scriptData,"onCurrentViewChanged",3,0,"fff",dv,old_view,new_view))
	{
		dv->currentViewChanged(old_view,new_view);
	}
}

void FsLDynamicView_CallBackAssign(DynamicView* dv)
{
	FsLEntity2D_CallBackAssign(dv);
	dv->onCurrentViewChanged=FsLDynamicView_onCurrentViewChanged;
}











/* ---------------------------- Layer --------------------*/



static void FsLLayer_onUpdate(Layer* ly,float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onUpdate",2,0,"fn",ly,dt))
	{
		ly->update(dt);
	}
}



static void FsLLayer_onDraw(Layer* ly,RenderDevice* render)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();

	if(!se->callFunctionInTable(ly->m_scriptData,"onDraw",2,0,"ff",ly,render))
	{
		ly->draw(render);
	}
}

static bool FsLLayer_onTouchBegin(Layer* ly,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchBegin",3,1,"fnn",ly,x,y))
	{
		return ly->touchBegin(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}


static bool FsLLayer_onTouchMove(Layer* ly,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchMove",3,1,"fnn",ly,x,y))
	{
		return ly->touchMove(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchEnd(Layer* ly,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchEnd",3,1,"fnn",ly,x,y))
	{
		return  ly->touchEnd(x,y);
	}

	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchesBegin(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesBegin",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesBegin(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchesPointerDown(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesPointerDown",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesPointerDown(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}
static bool FsLLayer_onTouchesMove(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesMove",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesMove(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}
static bool FsLLayer_onTouchesPointerUp(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesPointerUp",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesPointerUp(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLLayer_onTouchesEnd(Layer* ly,TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(ly->m_scriptData,"onTouchesEnd",3,1,"fiu<TouchEvent>",ly,event->getPointsNu(),event))
	{
		return  ly->touchesEnd(event);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}


void FsLLayer_CallBackAssign(Layer* ly)
{
	ly->onUpdate=FsLLayer_onUpdate;
	ly->onDraw=FsLLayer_onDraw;
	ly->onTouchBegin=FsLLayer_onTouchBegin;
	ly->onTouchMove=FsLLayer_onTouchMove;
	ly->onTouchEnd=FsLLayer_onTouchEnd;

	ly->onTouchesBegin=FsLLayer_onTouchesBegin;
	ly->onTouchesPointerDown=FsLLayer_onTouchesPointerDown;
	ly->onTouchesMove=FsLLayer_onTouchesMove;
	ly->onTouchesPointerUp=FsLLayer_onTouchesPointerUp;
	ly->onTouchesEnd=FsLLayer_onTouchesEnd;

}







NS_FS_END 

