#include "support/util/FsInteger.h"

static const char* s_FsIntegerName=FS_INTEGER_CLASS_NAME;

NS_FS_BEGIN

FsInteger* FsInteger::create(int value)
{
	return new FsInteger(value);

}

bool FsInteger::checkType(FsObject* ob)
{
	return ob->className()==s_FsIntegerName;
}

const char* FsInteger::className()
{
	return s_FsIntegerName;
}

bool FsInteger::equal(FsObject* ob)
{
	if(!FsInteger::checkType(ob))
	{
		return false;
	}
	return ((FsInteger*)ob)->m_value==m_value;
}
long FsInteger::getHashCode()
{
	if(m_value==FS_INVALID_HASH_CODE)
	{
		return m_value+1;
	}
	return m_value;
}

FsInteger::FsInteger()
	:m_value(0)
{}

FsInteger::FsInteger(int value)
	:m_value(value)
{}



NS_FS_END










