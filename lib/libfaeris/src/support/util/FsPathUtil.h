#ifndef _FS_PATH_UTIL_H_
#define _FS_PATH_UTIL_H_

#include <string>
#include "FsMacros.h"

NS_FS_BEGIN
class  PathUtil 
{
	public:
		static bool absolutePath(const char* name);
		static bool hasExtend(const char* name);
		static std::string getDirName(const char* name);
		static std::string getFileName(const char* name);
		static std::string toStdPath(const char* name);
};

NS_FS_END 

#endif /*_FS_PATH_UTIL_H_*/

