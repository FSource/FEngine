LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=libobjmodel_static 

LOCAL_SRC_FILES := ../../src/LibObjMeshGrammer.cc  \
				   ../../src/LibObjMeshScanner.cc \
				   ../../src/LibObjModel.cc \
				   ../../src/LibObjMtlGrammer.cc \
				   ../../src/LibObjMtlScanner.cc \


LOCAL_CFLAGS   := -I$(LOCAL_PATH)../../src/ 
				 


include $(BUILD_STATIC_LIBRARY)

