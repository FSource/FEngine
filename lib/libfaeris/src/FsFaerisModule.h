#ifndef _FS_FAERIS_MODULE_H_
#define _FS_FAERIS_MODULE_H_

#include "FsMacros.h"

NS_FS_BEGIN

class FsDict;


int FsFaeris_ModuleInit();
int FsFaeris_ModuleExit();


int FsFaeris_LoadConfig(const char* file);
int FsFaeris_LoadConfig(FsDict* dict);


int FsFaeris_ConfigManager(FsDict* dict);
int FsFaeris_ConfigVFS(FsDict* dict);
int FsFaeris_ConfigWin(FsDict* dict);
int FsFaeris_ConfigENV(FsDict* dict);


void FsMain_Entry(int argc,char** argv);

#if FS_PLATFORM_OS(FS_OS_WIN32) 
#define  FS_USE_MAIN_ENTRY  \
	NS_FS_USE			\
	int main(int argc,char** argv) \
	{  \
		FsFaeris_ModuleInit(); \
		FsMain_Entry(argc,argv); \
		Global::scheduler()->mainLoop();\
		/* exit */ \
		Global::sysDispatcher()->clearPending(); \
		Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::EXIT)); \
		Global::sysDispatcher()->flush(); \
		FsFaeris_ModuleExit(); \
		return 0; \
	} \


#elif FS_PLATFORM_OS(FS_OS_ANDROID) 
#define FS_USE_MAIN_ENTRY  \
	NS_FS_USE			\
	void FsAndroid_Main_Start() \
	{ \
		FsFaeris_ModuleInit(); \
		FsMain_Entry(0,NULL); \
	}


#elif FS_PLATFORM_OS(FS_OS_IOS)

#endif 


NS_FS_END

#endif /*_FS_FAERIS_MODULE_H_*/

