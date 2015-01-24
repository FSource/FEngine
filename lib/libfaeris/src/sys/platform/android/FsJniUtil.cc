/*************************************************************************/
/*  FsJniUtil.cc                                                         */
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

