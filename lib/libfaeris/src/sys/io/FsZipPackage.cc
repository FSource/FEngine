#include <stdlib.h>
#include <string.h>

#include "sys/io/FsFile.h"
#include "sys/io/FsZipPackage.h"
#include "support/data/FsZipReader.h"

NS_FS_BEGIN

ZipPackage* ZipPackage::create(FsFile* file)
{
	ZipPackage* ret=new ZipPackage;
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FsFile* ZipPackage::takeBlock(const char* filename)
{
	return m_reader->takeFile(filename);
}


const char* ZipPackage::className()
{
	return FS_ZIP_PACKAGE_CLASS_NAME;
}


bool ZipPackage::init(FsFile* file)
{
	ZipReader* reader=ZipReader::create(file);
	if(reader==NULL)
	{
		return false;
	}
	else 
	{
		m_reader=reader;
		return true;
	}

}

ZipPackage::ZipPackage()
{
	m_reader=NULL;
}


ZipPackage::~ZipPackage()
{
	if(m_reader)
	{
		m_reader->decRef();
		m_reader=NULL;
	}
}


NS_FS_END







































