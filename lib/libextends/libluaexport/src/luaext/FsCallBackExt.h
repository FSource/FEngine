#ifndef _FS_CALL_BACK_EXT_H_
#define _FS_CALL_BACK_EXT_H_


#include "FsMacros.h"

#include "stage/entity/FsEntity.h"
#include "stage/entity/FsEntity2D.h"
#include "stage/ui/FsPressButton.h"
#include "stage/ui/FsToggleButton.h"
#include "stage/ui/FsPageView.h"
#include "stage/ui/FsDynamicView.h"
#include "stage/layer/FsLayer.h"



#include "FsGlobal.h"
#include "FsLuaEngine.h"


NS_FS_BEGIN


void FsLFsObject_CallBackAssign(FsObject* ob);
void FsLEntity_CallBackAssign(Entity* en);
void FsLEntity2D_CallBackAssign(Entity2D* en);
void FsLPressButton_CallBackAssign(PressButton* en);
void FsLToggleButton_CallBackAssign(ToggleButton* tb);

void FsLPageView_CallBackAssign(PageView* pv);
void FsLDynamicView_CallBackAssign(DynamicView* dv);


void FsLLayer_CallBackAssign(Layer* ly);




NS_FS_END


#endif /*_FS_LAMBDA_CALL_BACK_H_*/

