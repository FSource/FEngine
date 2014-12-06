#ifndef _FS_JNI_UTIL_H_
#define _FS_JNI_UTIL_H_

#include <jni.h>

NS_FS_BEGIN
class JniUtil
{
	public:
		static JavaVM* getJavaVM();
		static void setJavaVM(JavaVM* jvm);

		static JNIEnv* getEnv(bool attach=true);
		static void attachCurrentThread();

		static jclass getClass(const char* cls_name);
		static jmethodID getStaticMethodID(jclass cls,const char* method_name,const char* sig);
		static jmethodID getMethodID(jclass cls,const char* method_name,const char* sig);
};


#define FS_JNI_NEW_OBJECT(cls_name,sig,ret,...) \
	do{ \
		jmethodID method_id=0; \
		jclass class_id=0; \
		JNIEnv* env=0;  \
		env=JniUtil::getEnv(false); \
		class_id=JniUtil::getClass(cls_name); \
		FS_TRACE_ERROR_ON(class_id==NULL,"Can't Get Class(%s)",cls_name);  \
		method_id=JniUtil::getMethodID(class_id,"<init>",sig); \
		FS_TRACE_ERROR_ON(method_id==NULL,"Can't Get  Sig(%s) Method(%s) in Class(%s)",sig,"init",cls_name);  \
		ret=env->NewObject(class_id,method_id,##__VA_ARGS__); \
		env->DeleteLocalRef(class_id); \
	}while(0)





#define FS_JNI_CALL_METHOD(job,cls_name,md_name,sig,type,ret,...) \
	do{ \
		jmethodID method_id=0; \
		jclass class_id=0; \
		JNIEnv* env=0; \
		env=JniUtil::getEnv(false); \
		FS_TRACE_ERROR_ON(env==NULL,"Can't Get Env"); \
		class_id=JniUtil::getClass(cls_name); \
		FS_TRACE_ERROR_ON(class_id==NULL,"Can't Get Class(%s)",cls_name); \
		method_id=JniUtil::getMethodID(class_id,md_name,sig); \
		FS_TRACE_ERROR_ON(method_id==NULL,"Can't Get  Sig(%s) Method(%s) in Class(%s)",sig,md_name,cls_name); \
		ret=env->Call##type##Method(job,method_id,##__VA_ARGS__); \
		env->DeleteLocalRef(class_id); \
	}while(0)



#define FS_JNI_CALL_VOID_METHOD(job,cls_name,md_name,sig,...) \
	do{ \
		jmethodID method_id=0; \
		jclass class_id=0; \
		JNIEnv* env=0; \
		env=JniUtil::getEnv(false); \
		FS_TRACE_ERROR_ON(env==NULL,"Can't Get Env"); \
		class_id=JniUtil::getClass(cls_name); \
		FS_TRACE_ERROR_ON(class_id==NULL,"Can't Get Class(%s)",cls_name); \
		method_id=JniUtil::getMethodID(class_id,md_name,sig); \
		FS_TRACE_ERROR_ON(method_id==NULL,"Can't Get  Sig(%s) Method(%s) in Class(%s)",sig,md_name,cls_name); \
		env->CallVoidMethod(job,method_id,##__VA_ARGS__); \
		env->DeleteLocalRef(class_id); \
	}while(0)


#define FS_JNI_CALL_STATIC_METHOD(cls_name,md_name,sig,type,ret,...) \
	do{ \
		jmethodID method_id=0; \
		jclass class_id=0; \
		JNIEnv* env=0; \
		env=JniUtil::getEnv(false); \
		FS_TRACE_ERROR_ON(env==NULL,"Can't Get Env"); \
		class_id=JniUtil::getClass(cls_name); \
		FS_TRACE_ERROR_ON(class_id==NULL,"Can't Get Class(%s)",cls_name); \
		method_id=JniUtil::getStaticMethodID(class_id,md_name,sig); \
		FS_TRACE_ERROR_ON(method_id==NULL,"Can't Get  Sig(%s) Method(%s) in Class(%s)",sig,md_name,cls_name); \
		ret=env->CallStatic##type##Method(class_id,method_id,##__VA_ARGS__); \
		env->DeleteLocalRef(class_id); \
	}while(0)

#define FS_JNI_CALL_VOID_STATIC_METHOD(cls_name,md_name,sig,...) \
	do{ \
		jmethodID method_id=0; \
		jclass class_id=0; \
		JNIEnv* env=0; \
		env=JniUtil::getEnv(false); \
		FS_TRACE_ERROR_ON(env==NULL,"Can't Get Env"); \
		class_id=JniUtil::getClass(cls_name); \
		FS_TRACE_ERROR_ON(class_id==NULL,"Can't Get Class(%s)",cls_name); \
		method_id=JniUtil::getStaticMethodID(class_id,md_name,sig); \
		FS_TRACE_ERROR_ON(method_id==NULL,"Can't Get  Sig(%s) Method(%s) in Class(%s)",sig,md_name,cls_name); \
		env->CallStaticVoidMethod(class_id,method_id,##__VA_ARGS__); \
		env->DeleteLocalRef(class_id); \
	}while(0)

NS_FS_END 

#endif /*_FS_JNI_UTIL_H_ */


