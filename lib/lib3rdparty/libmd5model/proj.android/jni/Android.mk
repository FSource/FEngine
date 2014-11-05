LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=libmd5model_static 

LOCAL_SRC_FILES := ../../src/libmd5model.cc  \
				   ../../src/md5anim_grammer.cc \
				   ../../src/md5anim_scanner.cc \
				   ../../src/md5mesh_scanner.cc \
				   ../../src/md5mesh_grammer.cc \


LOCAL_CFLAGS   := -I$(LOCAL_PATH)../../src/ 
				 


include $(BUILD_STATIC_LIBRARY)

