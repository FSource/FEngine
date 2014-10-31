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
	int name_len=strlen(name);
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
	int name_len=strlen(name);
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

	int length=ret.size();
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


