#include "FsMacros.h"

#include "FsGlobal.h"
#include "sys/platform/android/FsJniUtil.h"


NS_FS_BEGIN

const char* S_FS_JNI_PAYMENT_CLASS_NAME= "com/faeris/payment/Fs_Payment";
void Payment::init(const char* msg)
{
	JNIEnv* env=JniUtil::getEnv();

	jstring j_msg=env->NewStringUTF(msg);


	FS_JNI_CALL_VOID_STATIC_METHOD(S_FS_JNI_PAYMENT_CLASS_NAME,"init",
				"(JLjava/lang/String;)V",
				j_msg
				);
	env->DeleteLocalRef(j_msg);
}


void Payment::setConfig(const char* config)
{
	JNIEnv* env=JniUtil::getEnv();

	jstring j_config=env->NewStringUTF(config);


	FS_JNI_CALL_VOID_STATIC_METHOD(S_FS_JNI_PAYMENT_CLASS_NAME,"setConfig",
			"(Ljava/lang/String;)V",
			j_config
			);

	env->DeleteLocalRef(j_config);
}


int Payment::billing(const char* msg)
{
	JNIEnv* env=JniUtil::getEnv();
	jstring j_msg=env->NewStringUTF(msg);

	jint ret;

	FS_JNI_CALL_STATIC_METHOD(S_FS_JNI_PAYMENT_CLASS_NAME,"billing",
			"(Ljava/lang/String;Ljava/lang/String)I",
			Int,
			ret,
			j_msg
			);

	env->DeleteLocalRef(j_msg);

	return ret;

}

void Payment::billingFinish(int trade_id,int ret_code,const char* msg)
{
	/* Note: no thing here 
	 * Subclass Must Override it 
	 */
}


Payment::Payment()
{
}

Payment::~Payment()
{
}


NS_FS_END






