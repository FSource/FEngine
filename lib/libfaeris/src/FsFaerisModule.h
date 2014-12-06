#ifndef _FS_FAERIS_MODULE_H_
#define _FS_FAERIS_MODULE_H_

#include "FsMacros.h"

NS_FS_BEGIN

class FsDict;

int FsFaeris_ModuleInit();
int FsFaeris_ModuleExit();


int FsFaeris_LoadConfig(FsDict* dict);



int FsFaeris_ConfigManager(FsDict* dict);
int FsFaeris_ConfigVFS(FsDict* dict);
int FsFaeris_ConfigWin(FsDict* dict);

int FsFaeris_ConfigENV(FsDict* dict);



NS_FS_END



#endif /*_FS_FAERIS_MODULE_H_*/

