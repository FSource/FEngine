#ifndef _FS_ENTITY_CALL_BACK_EXT_H_
#define _FS_ENTITY_CALL_BACK_EXT_H_

#include "FsMacros.h"



NS_FS_BEGIN

class FsObject;
class Entity;
class Entity2D;
class PressButton;
class ToggleButton;
class PageView;
class DynamicView;


void FsLEntity_CallBackAssign(Entity* en);
void FsLEntity2D_CallBackAssign(Entity2D* en);
void FsLPressButton_CallBackAssign(PressButton* en);
void FsLToggleButton_CallBackAssign(ToggleButton* tb);

void FsLPageView_CallBackAssign(PageView* pv);
void FsLDynamicView_CallBackAssign(DynamicView* dv);

NS_FS_END



#endif /*_FS_ENTITY_CALL_BACK_EXT_H_*/


