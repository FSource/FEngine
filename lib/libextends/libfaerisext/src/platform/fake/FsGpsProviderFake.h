#ifndef _FS_PGS_PROVIDER_WIN32_H_
#define _FS_PGS_PROVIDER_WIN32_H_

NS_FS_BEGIN 
class GpsProvider:public FsObject 
{
	public:
		static GpsProvider* create();

	public:
		void getLastKnownLocation(float* latitude,float* longitude);

	public:
		virtual const char* className();

	protected:
		GpsProvider();
		virtual ~GpsProvider();
};

NS_FS_END 


#endif /*_FS_PGS_PROVIDER_WIN32_H_*/

