#include "FsAnimation.h"
#include "FsClass.h"

NS_FS_BEGIN



/** User For Animation Attribute **/

static FsClass::FsAttributeDeclare S_Animation_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(Animation,FsObject,0,S_Animation_Main_Attr);


NS_FS_END

