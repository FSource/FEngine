#include "com_faeris_payment_Fs_PaymentJni.h"

#include "FsPayment.h"

NS_FS_BEGIN

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_faeris_payment_Fs_PaymentJni
 * Method:    billingFinish
 * Signature: (IILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_faeris_payment_Fs_1PaymentJni_billingFinish
  (JNIEnv* env, jclass, jint trade_id, jint ret_code, jstring msg)
  {
	  Payment* payment=FsPayment_GetGlobal();
	  if(payment)
	  {
		  FS_TRACE_WARN("Global Payment Not Set");
		  return;
	  }

	  const char* t_msg=env->GetStringUTFChars(msg,NULL);

	  payment->billingFinish(trade_id,ret_code,t_msg);

	  env->ReleaseStringUTFChars(msg,t_msg);

  }

#ifdef __cplusplus
}
#endif


NS_FS_END

