/*************************************************************************/
/*  FsPathUtil.cc                                                        */
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


#include <string.h>
#include "support/util/FsPathUtil.h"


NS_FS_BEGIN

bool PathUtil::absolutePath(const char* name)
{
	if(name[0]=='/')
	{
		return true;
	}

	if((strlen(name)>=2)&&name[1]==':')
	{
		return true;
	}

	return false;
}
bool PathUtil::hasExtend(const char* name)
{
	bool has=false;
	const char* p=name;
	while(*p)
	{
		if(*p=='.')
		{
			has=true;
			break;
		}
		p++;
	}
	if(has)
	{
		if(*(p+1)=='\0')
		{
			has=false;
		}
	}
	return has;
}


std::string PathUtil::getDirName(const char* name)
{
	int split=0;
	int name_len=(int)strlen(name);
	for(int i=name_len-1;i>=0;i--)
	{
		if(name[i]=='/')
		{
			split=i;
			break;
		}
	}
	return std::string(name,split);

}
std::string PathUtil::getFileName(const char* name)
{
	int split=-1;
	int name_len=(int)strlen(name);
	int i;
	for(i=name_len-1;i>=0;i--)
	{
		if(name[i]=='/')
		{
			split=i;
			break;
		}
	}

	return std::string(name+split+1);

}
std::string PathUtil::toStdPath(const char* name)
{
	std::string ret(name);

	int length=(int)ret.size();
	for(int i=0;i<length;i++)
	{
		if(ret[i]=='\\')
		{
			ret[i]='/';
		}
	}
	return ret;
}
NS_FS_END


