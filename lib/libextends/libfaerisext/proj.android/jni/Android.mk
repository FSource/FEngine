LOCAL_PATH :=$(call my-dir)


include $(CLEAR_VARS)

LOCAL_MODULE := libpayment_static 

LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../../src \
					 -I$(LOCAL_PATH)/../../../../../lib/libfaeris/src \
					 -I$(LOCAL_PATH)/../../../../../lib/libfaeris/src/support  \
					 -I$(LOCAL_PATH)../src/

LOCAL_SRC_FILES := ../../src/FsPayment.cc \
				   ../../src/platform/android/com_faeris_payment_Fs_PaymentJni.cc \


include $(BUILD_STATIC_LIBRARY)





