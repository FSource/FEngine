#include "FsSpineSpriteData.h"
#include "sys/io/FsFile.h"
#include "sys/io/FsVFS.h"
#include "FsTextureAttachmentLoader.h"
#include "FsTextureAttachment.h"

NS_FS_BEGIN


const char* SpineSpriteData::className()
{
	return "SpineSpriteData";
}


SpineSpriteData* SpineSpriteData::create(FsFile* file)
{
	SpineSpriteData* data=new SpineSpriteData();
	if(!data->init(file))
	{
		delete data;
		data=NULL;
	}
	return data;
}

bool SpineSpriteData::init(FsFile* file)
{
	long length=file->getLength();
	char* buf=new char[length];
	SkeletonJson* json=NULL;
	TextureAttachmentLoader* loader=NULL;
	SkeletonData* data=NULL;

	file->read(buf,length);

	loader=TextureAttachmentLoader_Create();
	json=SkeletonJson_createWithLoader((AttachmentLoader*)loader);

	if(json==NULL)
	{
		FS_TRACE_WARN("Create SkeletonJson Failed");
		goto error;
	}

	data=SkeletonJson_readSkeletonData(json,buf);
	if(data==NULL)
	{
		FS_TRACE_WARN("Create SkeletonData Failed");
		goto error;
	}


	SkeletonJson_dispose(json);
	delete[] buf;
	delete loader;

	m_data=data;

	return true;

error:
	if(buf)
	{
		delete[] buf;
	}
	if(loader)
	{
		delete loader;
	}
	if(json)
	{
		SkeletonJson_dispose(json);
	}
	return false;
}


void SpineSpriteData::destroy()
{
	if(m_data)
	{
		SkeletonData_dispose(m_data);
		m_data=NULL;
	}
}

SpineSpriteData::SpineSpriteData()
{
	m_data=NULL;
}

SpineSpriteData::~SpineSpriteData()
{
	destroy();
}

NS_FS_END 



