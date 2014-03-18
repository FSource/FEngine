LOCAL_PATH :=$(call my-dir)

IMPORT_PATH := $(LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := faeris

LOCAL_SRC_FILES :=  ../../src/FsAndroidMain.cc \

LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../../../../lib/3rdparty/lua/include \
					 -I$(LOCAL_PATH)/../../../../lib/3rdparty/tolua++/include \
					 -I$(LOCAL_PATH)/../../../../lib/libfaeris/src \
					 -I$(LOCAL_PATH)/../../../../lib/libfaeris/src/support  \
					 -I$(LOCAL_PATH)/../../../../lib/libextends/libluaexport/src \
					 -I$(LOCAL_PATH)/../../../../lib/libextends/libluaexport/src/luaext \
					 -I$(LOCAL_PATH)/../../../../lib/libxAccess/src  \

					 



LOCAL_WHOLE_STATIC_LIBRARIES := zlib_static 
LOCAL_WHOLE_STATIC_LIBRARIES += freetype_static 
LOCAL_WHOLE_STATIC_LIBRARIES += minizip_static 
LOCAL_WHOLE_STATIC_LIBRARIES += libpng_static
LOCAL_WHOLE_STATIC_LIBRARIES += libjpeg_static
LOCAL_WHOLE_STATIC_LIBRARIES += lua_static 
LOCAL_WHOLE_STATIC_LIBRARIES += tolua_static
LOCAL_WHOLE_STATIC_LIBRARIES += curl_static

LOCAL_WHOLE_STATIC_LIBRARIES += faeris_static 
LOCAL_WHOLE_STATIC_LIBRARIES += luaexport_static
LOCAL_WHOLE_STATIC_LIBRARIES += spinesprite_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += lib3rdextends_static

LOCAL_WHOLE_STATIC_LIBRARIES += libthirdParty_static
LOCAL_WHOLE_STATIC_LIBRARIES += libsensor_static



LOCAL_LDLIBS    += -llog -lGLESv2  -lEGL


include $(BUILD_SHARED_LIBRARY)

$(call import-add-path,$(IMPORT_PATH))

$(call import-module,../../../../lib/libfaeris/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/curl/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/freetype/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/libpng/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/libjpeg/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/lua/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/tolua++/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/minizip/proj.android/jni)
$(call import-module,../../../../lib/lib3rdparty/zlib/proj.android/jni)
$(call import-module,../../../../lib/libextends/libluaexport/proj.android)
$(call import-module,../../../../lib/libextends/libspinesprite/proj.android)
$(call import-module,../../../../lib/lib3rdparty/Box2D/proj.android)
$(call import-module,../../../../lib/libextends/lib3rdextends/proj.android/jni)
$(call import-module,../../../../lib/libextends/libsensor/proj.android)





































