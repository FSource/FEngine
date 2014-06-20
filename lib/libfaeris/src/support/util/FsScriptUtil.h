#ifndef _FS_SCRIPT_UTIL_H_
#define _FS_SCRIPT_UTIL_H_

#include "FsMacros.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsString.h"
#include "sys/io/FsFile.h"

NS_FS_BEGIN
class ScriptUtil
{
	public:
		static FS_FEATURE_NEW_OBJECT(FsDict*) parseJson(const char* json);

		static FS_FEATURE_NEW_OBJECT(FsDict*) parseScript(FsFile* file);
		static bool saveScript(FsFile* file,FsDict* dict,int indent=0);

		/* if NULL return mean this no need to escape src */
		static char* escapeStringToOrign(const char* src);

		/* aux for quick get object in dict */
		static FsArray* getArray(FsDict* dict,const char* key);
		static FsDict* getDict(FsDict* dict,const char* key);
		static FsString* getString(FsDict* dict,const char* key);
		static bool getInteger(FsDict* dict,const char* key,int* value);
		static bool getFloat(FsDict* dict,const char* key,float* value);
		static bool getBoolean(FsDict* dict,const char* key,bool* value);

		/* aux for quick get object in array */
		static FsArray* getArray(FsArray* array,uint index);
		static FsDict* getDict(FsArray* array,uint index);
		static FsString* getString(FsArray* array,uint index);
		static bool getInteger(FsArray* array,uint index,int* v);
		static bool getFloat(FsArray* array,uint index,float* v);
		static bool getBoolean(FsArray* dict,uint index,bool* value);

		/* aux for translate string to float,integer*/
		static float parseFloat(const char* str);
		static float parseFloat(FsString* str)
		{
			return parseFloat(str->cstr());
		}

		static int parseInteger(const char* str);
		static int parseInteger(FsString* str)
		{
			return parseInteger(str->cstr());
		}

		static bool parseBoolean(const char* str);
		static bool parseBoolean(FsString* str)
		{
			return parseBoolean(str->cstr());
		}
	
};

NS_FS_END 



#endif /*_FS_SCRIPT_UTIL_H_*/

