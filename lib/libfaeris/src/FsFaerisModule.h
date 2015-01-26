/*************************************************************************/
/*  FsFaerisModule.h                                                     */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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


/*
#if FS_PLATFORM_OS(FS_OS_WIN32)
    void FsWin32_Main_Start()
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
    void FsAndroid_Main_Start()
#elif FS_PLATFORM_OS(FS_OS_IOS)
    void FsIos_Main_Start()
#elif FS_PLATFORM_OS(FS_OS_LINUX)
    void FsLinux_Main_Start()
#else
    #error "Unkow Platform"
#endif
 */




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
	} 

#elif FS_PLATFORM_OS(FS_OS_ANDROID) 

#define FS_USE_MAIN_ENTRY  \
    NS_FS_BEGIN     \
	void FsAndroid_Main_Start() \
	{ \
		FsFaeris_ModuleInit(); \
		FsMain_Entry(0,NULL); \
	} \
    NS_FS_END


#elif FS_PLATFORM_OS(FS_OS_IOS)


#define FS_USE_MAIN_ENTRY \
    NS_FS_BEGIN \
    void FsIos_Main_Start() \
    {   \
        FsFaeris_ModuleInit(); \
        FsMain_Entry(0,NULL); \
    } \
    NS_FS_END

#else 


#endif 


NS_FS_END

#endif /*_FS_FAERIS_MODULE_H_*/

