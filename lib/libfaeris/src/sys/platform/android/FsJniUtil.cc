#include "FsMacros.h"

#include "sys/FsSys.h"
#include "FsJniUtil.h"

NS_FS_BEGIN


JavaVM* JniUtil::getJavaVM()
{
	return Sys::getJavaVM();
}
void JniUtil::setJavaVM(JavaVM* jvm)
{
	Sys::setJavaVM(jvm);
}

JNIEnv* JniUtil::getEnv(bool attach)
{
	JNIEnv* env=0;
	JavaVM* jvm=Sys::getJavaVM();
	if(jvm->GetEnv((void**)&env,JNI_VERSION_1_4)!=JNI_OK)
	{
		FS_TRACE_WARN("Failed To get JNI Environment");
		return NULL;
	}
	if(attach)
	{
		if(jvm->AttachCurrentThread(&env,NULL)<0)
		{
			FS_TRACE_WARN("Failed to Attach Current Thread");
		}
	}

	return env;
}

void JniUtil::attachCurrentThread()
{
	JavaVM* jvm=Sys::getJavaVM();
	JNIEnv* env=getEnv(false);
	if(jvm->AttachCurrentThread(&env,0)<0)
	{
		FS_TRACE_WARN("Failed to Attach Current Thread");
	}
}



jclass JniUtil::getClass(const char* cls_name)
{
	JNIEnv* env=JniUtil::getEnv();
	jclass ret=0;
	ret=env->FindClass(cls_name);
	FS_TRACE_WARN_ON(ret==0,"Can't Find Class(cls_name)");
	return ret;
}


jmethodID JniUtil::getStaticMethodID(jclass cls,const char* method_name,const char* sig)
{
	JNIEnv* env=JniUtil::getEnv();
	jmethodID method_id=env->GetStaticMethodID(cls,method_name,sig);
	FS_TRACE_WARN_ON(method_id==0,"Can't Find Method(%s) Sig(%s)",method_name,sig);
	return method_id;
}

jmethodID JniUtil::getMethodID(jclass cls,const char* method_name,const char* sig)
{
	JNIEnv* env=JniUtil::getEnv();
	jmethodID method_id=env->GetMethodID(cls,method_name,sig);
	FS_TRACE_WARN_ON(method_id==0,"Can't Find Method(%s) Sig(%s)",method_name,sig);
	return method_id;
}


NS_FS_END 

