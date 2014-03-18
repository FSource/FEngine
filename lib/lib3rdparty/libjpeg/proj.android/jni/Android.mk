LOCAL_PATH := $(call my-dir)

#
# Jpeg Ex Shared Library
# 
include $(CLEAR_VARS)

LOCAL_MODULE            := libjpeg_static 
LOCAL_SRC_FILES         := ../../../../library/android/3rdparty/libjpeg/$(TARGET_ARCH_ABI)/libjpeg.a

include $(PREBUILT_STATIC_LIBRARY)
