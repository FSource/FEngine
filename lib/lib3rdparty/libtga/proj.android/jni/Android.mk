LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=libtga_static 

LOCAL_SRC_FILES := ../../src/tga.c \
				   ../../src/tgaio.c \
				   ../../src/tgaread.c \
				   ../../src/tgawrite.c \


LOCAL_CFLAGS   := -I$(LOCAL_PATH)../../src/ 
				 


include $(BUILD_STATIC_LIBRARY)

