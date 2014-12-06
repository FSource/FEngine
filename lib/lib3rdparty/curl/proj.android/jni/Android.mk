LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := curl_static

LOCAL_SRC_FILES := ../../../../library/android/3rdparty/curl/$(TARGET_ARCH_ABI)/libcurl.a 


include $(PREBUILT_STATIC_LIBRARY)


