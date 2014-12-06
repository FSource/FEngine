#include "sys/io/FsFgzPackage.h"
#include "support/data/FsFgzReader.h"


NS_FS_BEGIN

const char* FgzPackage::className()
{
	return FS_FGZ_PACKAGE_CLASS_NAME;
}

FgzPackage* FgzPackage::create(FsFile* file)
{
	FgzPackage* ret=new FgzPackage;
	if(!ret->init(file))
	{
		delete ret;
		ret=NULL;
	}
	return ret;
}

FsFile* FgzPackage::takeBlock(const char* filename)
{
	return m_reader->takeFile(filename);
}


bool FgzPackage::init(FsFile* file)
{
	FgzReader* reader=FgzReader::create(file);
	if(reader==NULL)
	{
		return false;
	}
	m_reader=reader;
	return true;

}


FgzPackage::FgzPackage()
{
	m_reader=NULL;
}

FgzPackage::~FgzPackage()
{
	if(m_reader)
	{
		m_reader->decRef();
		m_reader=NULL;
	}
}



NS_FS_END
