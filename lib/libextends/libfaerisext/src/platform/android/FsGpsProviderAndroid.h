#ifndef _FS_GPS_PROVIDER_ANDROID_H_
#define _FS_GPS_PROVIDER_ANDROID_H_ 

#include "FsMacros.h"
#include "FsObject.h"
#include <jni.h>

NS_FS_BEGIN

class GpsProvider:public FsObject 
{
	public:
		static GpsProvider* create();

	public:
		void getLastKnownLocation(float* latitude,float* longitude);

	public:
		const char* className();


	protected:
		GpsProvider();
		virtual ~GpsProvider();


	protected:
		bool init();
		void destory();

	private:
		jobject m_object;
};




NS_FS_END



#endif /*_FS_GPS_PROVIDER_ANDROID_H_*/

