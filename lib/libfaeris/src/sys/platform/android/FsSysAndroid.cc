/*************************************************************************/
/*  FsSysAndroid.cc                                                      */
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


#include <sys/stat.h>

#include <unistd.h>
#include <errno.h>
#include <time.h>

#include "FsMacros.h"
#include "sys/FsSys.h"

#include "FsJniUtil.h"

NS_FS_BEGIN

JavaVM* Sys::m_jvm=NULL;

void Sys::setJavaVM(JavaVM* jvm)
{
	m_jvm=jvm;
}


JavaVM* Sys::getJavaVM()
{
	return m_jvm;
}


const char* Sys::packageName()
{
	JNIEnv* env=JniUtil::getEnv();
	jobject ob_ret;
	FS_JNI_CALL_STATIC_METHOD("com/faeris/lib/Fs_Application",
							  "getPackageName",
							  "()Ljava/lang/String;",
							  Object,
							  ob_ret);
	jstring j_str=(jstring)ob_ret;
	const char* apk_name=env->GetStringUTFChars(j_str,NULL);
	strncpy(m_tempBuf,apk_name,FS_SYS_TEMP_BUF_SIZE);
	env->ReleaseStringUTFChars(j_str,apk_name);
	return m_tempBuf;
}

const char* Sys::apkPath()
{
	JNIEnv* env=JniUtil::getEnv();
	jobject ob_ret;
	FS_JNI_CALL_STATIC_METHOD("com/faeris/lib/Fs_Application",
							  "getApkPath",
							  "()Ljava/lang/String;",
							  Object,
							  ob_ret);
	jstring j_str=(jstring)ob_ret;
	const char* apk_path=env->GetStringUTFChars(j_str,NULL);
	strncpy(m_tempBuf,apk_path,FS_SYS_TEMP_BUF_SIZE);
	env->ReleaseStringUTFChars(j_str,apk_path);
	return m_tempBuf;
}


const char* Sys::currentDir()
{
	JNIEnv* env=JniUtil::getEnv();
	jobject ob_ret;
	FS_JNI_CALL_STATIC_METHOD("com/faeris/lib/Fs_Application",
							  "getDataDir",
							  "()Ljava/lang/String;",
							  Object,
							  ob_ret);
	jstring j_str=(jstring)ob_ret;
	const char* apk_path=env->GetStringUTFChars(j_str,NULL);
	strncpy(m_tempBuf,apk_path,FS_SYS_TEMP_BUF_SIZE);
	env->ReleaseStringUTFChars(j_str,apk_path);
	return m_tempBuf;
}


void Sys::usleep(long time)
{
	struct timespec req= { time/1000, (time%1000)*1000000 };
	struct timespec rem;
	int ret=0;
	while(1)
	{
		ret=nanosleep(&req,&rem);
		if(ret==-1)
		{
			if(errno==EINTR)
			{
				req=rem;
				nanosleep(&req,&rem);
				continue;
			}
		}
		break;
	}
}


int Sys::mkdir(const char* dir_name)
{
	int ret=::mkdir(dir_name,0775);
	return ret;
}


bool Sys::isDir(const char* dir_name)
{
	struct stat st;
	if (stat(dir_name, &st) != 0)
    {
		return false;
    }
    else if (!S_ISDIR(st.st_mode))
    {
		return false;
    }
	return true;

}

void Sys::openInputTextDialog(const char* title,const char* msg,
							int input_mode,int input_flag,
							int return_type,int max_length)
{
	const char* p_title=title!=NULL? title:"InputTextDialog";
	const char* p_msg=msg!=NULL?msg:"";

	JNIEnv* env=JniUtil::getEnv();

	jstring j_title=env->NewStringUTF(p_title);
	jstring j_msg=env->NewStringUTF(p_msg);

	FS_JNI_CALL_VOID_STATIC_METHOD("com/faeris/lib/Fs_Application",
							  "showInputBoxDialog",
							  "(Ljava/lang/String;Ljava/lang/String;IIII)V",
							  j_title,j_msg,input_mode,input_flag,return_type,max_length);

	env->DeleteLocalRef(j_title);
	env->DeleteLocalRef(j_msg);

}

void Sys::openNetSettingInterface()
{
	FS_JNI_CALL_VOID_STATIC_METHOD("com/faeris/lib/Fs_Application",
								   "showNetSettingInterface","()V");

}


							
NS_FS_END 










