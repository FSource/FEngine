/*************************************************************************/
/*  FsScriptUtil.h                                                       */
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

		static bool parseColor3f(const char* str,float* r,float* g,float* b);
		static bool parseColor3f(FsString* str, float* r,float* g,float* b)
		{
			return parseColor3f(str->cstr(),r,g,b);
		}
		static bool parseColor4f(const char* str,float* r,float* g,float* b,float* a);
		static bool parseColor4f(FsString* str,float* r,float* g,float* b,float* a)
		{
			return parseColor4f(str->cstr(),r,g,b,a);
		}

	
};

NS_FS_END 



#endif /*_FS_SCRIPT_UTIL_H_*/

