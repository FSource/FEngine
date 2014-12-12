#include <stdio.h>
#include <string.h>

#include "support/util/FsString.h"

#include "support/util/FsScriptUtil.h"

static const char* s_FsStringName=FS_STRING_CLASS_NAME;

NS_FS_BEGIN

FsString* FsString::create()
{
	return new FsString;
}
FsString* FsString::create(const char* str)
{
	return new FsString(str);
}

FsString::FsString(int value)
{
	char buf[128];
	sprintf(buf,"%d",value);
	m_string=std::string(buf);
	mCalHashCode();
}
long FsString::getHashCode()
{
	return m_hash_code;
}

const char* FsString::className()
{
	return s_FsStringName;
}

bool FsString::checkType(FsObject* ob)
{
	return ob->className()==s_FsStringName;
}
bool FsString::equal(FsObject* ob)
{
	if(!FsString::checkType(ob))
	{
		return false;
	}
	if(ob==this)
	{
		return true;
	}

	FsString* sob=(FsString*)ob;
	if(sob->getHashCode()!=getHashCode())
	{
		return false;
	}
	if(strcmp(m_string.c_str(),sob->m_string.c_str())==0)
	{
		return true;
	}
	else 
	{
		return false;
	}

}
bool FsString::equal(const char* str)
{
	return strcmp(m_string.c_str(),str)==0;
}

int FsString::toIntValue()
{
	return ScriptUtil::parseInteger(this);
}

float FsString::toFloatValue()
{
	return ScriptUtil::parseFloat(this);
}



NS_FS_END

