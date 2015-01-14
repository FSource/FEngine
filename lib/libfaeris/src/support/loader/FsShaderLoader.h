#ifndef _FS_SHADER_LOADER_H_
#define _FS_SHADER_LOADER_H_

#include "FsMacros.h"
#include "FsEnums.h"

NS_FS_BEGIN 

Program* FsShader_Load(FsFile* file);
Program* FsShader_Load(const char* filename);

NS_FS_END 


#endif /*_FS_SHADER_LOADER_H_*/


