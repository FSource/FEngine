#include "FsGpsProvider.h"

NS_FS_BEGIN

GpsProvider* GpsProvider::create()
{
	return new GpsProvider();
}

GpsProvider::GpsProvider()
{

}

GpsProvider::~GpsProvider()
{

}

void GpsProvider::getLastKnownLocation(float* latitude,float* longitude)
{
	*latitude=0;
	*longitude=0;
}


const char* GpsProvider::className()
{
	return "GpsProvider";
}



NS_FS_END
