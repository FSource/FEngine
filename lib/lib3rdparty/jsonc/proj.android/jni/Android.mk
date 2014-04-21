LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=jsonc_static 

LOCAL_SRC_FILES := ../../src/cJSON.c


LOCAL_CFLAGS   := -I$(LOCAL_PATH)../../src/ 
				 


include $(BUILD_STATIC_LIBRARY)

