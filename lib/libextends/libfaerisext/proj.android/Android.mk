LOCAL_PATH :=$(call my-dir)


include $(CLEAR_VARS)

LOCAL_MODULE := libsensor_static 


LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src/support  \


LOCAL_SRC_FILES := ../src/FsGpsProvider.cc  \
					 

include $(BUILD_STATIC_LIBRARY)










