/*************************************************************************/
/*  FsJniUtil.h                                                          */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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


