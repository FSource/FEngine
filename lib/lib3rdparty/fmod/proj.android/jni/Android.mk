LOCAL_PATH := $(call my-dir)

#
# FMOD Ex Shared Library
# 
include $(CLEAR_VARS)

LOCAL_MODULE            := fmodex
LOCAL_SRC_FILES         := ../../../../library/android/3rdparty/fmodex/$(TARGET_ARCH_ABI)/libfmodex.so

include $(PREBUILT_SHARED_LIBRARY)
