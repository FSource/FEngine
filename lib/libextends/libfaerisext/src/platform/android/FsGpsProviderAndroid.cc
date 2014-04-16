#include "FsGpsProviderAndroid.h"

#include "sys/platform/android/FsJniUtil.h"


static const char* JNI_GPS_PROVIDER_CLASS_NAME="com/faeris/lib/Fs_GpsProvider";

static const char* JNI_LOCATION_CLASS_NAME="android/location/Location";



NS_FS_BEGIN

GpsProvider* GpsProvider::create()
{
	GpsProvider* ret=new GpsProvider();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}


GpsProvider::GpsProvider()
{
	m_object=0;

}


GpsProvider::~GpsProvider()
{
	destory();
}


const char* GpsProvider::className()
{
	return "GpsProvider";
}


bool GpsProvider::init()
{
	JNIEnv* env=JniUtil::getEnv();
	FS_JNI_CALL_STATIC_METHOD(JNI_GPS_PROVIDER_CLASS_NAME,"create","()Lcom/faeris/lib/Fs_GpsProvider;",Object,m_object);

	if(m_object) 
	{
		env->NewGlobalRef(m_object);
		return true;
	}

	return false ;
}

void GpsProvider::destory()
{
	JNIEnv* env=JniUtil::getEnv();
	if(m_object) 
	{
		env->DeleteGlobalRef(m_object);
		m_object=0;
	}
}

void GpsProvider::getLastKnownLocation(float* latitude,float* longitude)
{
	JniUtil::attachCurrentThread();

	FS_JNI_CALL_VOID_METHOD(m_object,JNI_GPS_PROVIDER_CLASS_NAME,"updateLocation","()V");

	jdouble j_latitude;
	jdouble j_longitude;

	FS_JNI_CALL_METHOD(m_object,JNI_GPS_PROVIDER_CLASS_NAME,"getLatitude","()D",Double,j_latitude);

	FS_JNI_CALL_METHOD(m_object,JNI_GPS_PROVIDER_CLASS_NAME,"getLongitude","()D",Double,j_longitude);

	*latitude=j_latitude;
	*longitude=j_longitude;

}



NS_FS_END






































