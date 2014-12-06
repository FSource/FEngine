#ifndef _FS_SYS_H_
#define _FS_SYS_H_

#include "FsMacros.h"
#define FS_SYS_TEMP_BUF_SIZE 2048

#if FS_PLATFORM_OS(FS_OS_ANDROID)
	#include <jni.h>
#endif 


NS_FS_BEGIN 
class FsDict;

enum 
{
	FS_INPUT_MODE_ANY=0,
	FS_INPUT_MODE_EMAIL_ADDR=1,
	FS_INPUT_MODE_NUMERIC=2,
	FS_INPUT_MODE_PHONE_NUMBER=3,
	FS_INPUT_MODE_URL=4,
	FS_INPUT_MODE_DECIMAL=5,
	FS_INPUT_MODE_SINGLE_LINE=6,
};

enum 
{
	FS_INPUT_FLAG_PASSWORD=0,
	FS_INPUT_FLAG_SENSITIVE=1,
	FS_INPUT_FLAG_INITIAL_CAPS_WORD=2,
	FS_INPUT_FLAG_INITIAL_CAPS_SENTENCE=3,
	FS_INPUT_FLAG_INITIAL_CAPS_ALL_CHARACTERS=4,
};

enum 
{
	FS_KEYBOARD_RETURN_TYPE_DEFAULT=0,
	FS_KEYBOARD_RETURN_TYPE_DONE=1,
	FS_KEYBOARD_RETURN_TYPE_SEND=2,
	FS_KEYBOARD_RETURN_TYPE_SEARCH=3,
	FS_KEYBOARD_RETURN_TYPE_GO=4,
};


class Sys
{
	public:
		static bool moduleInit();
		static bool moduleExit();

		/* common */
		static void usleep(long time);
		static const char* currentDir();

		static const char* deviceName();
		static const char* imei();
		static const char* getEnv(const char* key);
		static void setEnv(const char* key,const char* value); 

		/* io function */
		static int mkdir(const char* name);
		static bool isDir(const char* name);

		static void openInputTextDialog(const char* title,const char* msg,
										int input_mode=FS_INPUT_MODE_ANY,int input_flag=FS_INPUT_FLAG_SENSITIVE,
										int return_type=FS_KEYBOARD_RETURN_TYPE_DEFAULT,
										int max_length=-1);

		static void openNetSettingInterface();



	private:
		static FsDict* m_env;
		static char m_tempBuf[FS_SYS_TEMP_BUF_SIZE];



		/*  android interface  */
#if FS_PLATFORM_OS(FS_OS_ANDROID)
	public:
		static void setJavaVM(JavaVM* jvm);
		static JavaVM* getJavaVM();
		static const char* packageName();
		static const char* apkPath();
	private:
		static JavaVM* m_jvm;
#endif 

};

NS_FS_END 
#endif /* _FS_SYS_H_ */




