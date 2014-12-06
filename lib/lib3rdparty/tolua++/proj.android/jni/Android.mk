LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=tolua_static 

LOCAL_SRC_FILES := ../../src/tolua_event.c \
				   ../../src/tolua_is.c \
				   ../../src/tolua_map.c \
				   ../../src/tolua_push.c \
				   ../../src/tolua_to.c \


LOCAL_CFLAGS   := -I$(LOCAL_PATH)../../../../lua/include \
				 


include $(BUILD_STATIC_LIBRARY)

