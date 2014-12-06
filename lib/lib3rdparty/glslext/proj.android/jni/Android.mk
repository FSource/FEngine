LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=glslext_static 

LOCAL_SRC_FILES := ../../src/glslext_grammer.cc  \
				   ../../src/glslext_parser.cc \
				   ../../src/glslext_scanner.cc \


LOCAL_CFLAGS   := -I$(LOCAL_PATH)../../src/ 
				 


include $(BUILD_STATIC_LIBRARY)

