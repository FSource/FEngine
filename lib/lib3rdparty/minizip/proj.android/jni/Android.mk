LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)


LOCAL_MODULE :=minizip_static

LOCAL_SRC_FILES := ../../src/ioapi.c  \
				   ../../src/unzip.c \

LOCAL_C_INCLUDES := -I../../src


include $(BUILD_STATIC_LIBRARY)



