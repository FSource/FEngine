#ifndef _FS_JSON_H_
#define _FS_JSON_H_

#include <string>
#include "cJSON.h" 
#include "FsMacros.h"

NS_FS_BEGIN
class FsDict;

FsDict* FsJson_Decode(const char* json);
std::string FsJson_Encode(FsDict* dict);

NS_FS_END

#endif /*_FS_JSON_H_*/


