LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=ljson_static

LOCAL_SRC_FILES := ../../src/fpconv.c  \
				   ../../src/lua_cjson.c \
				   ../../src/strbuf.c \

LOCAL_CFLAGS   := -I$(LOCAL_PATH)../../../../lua/include \
				  -I$(LOCAL_PATH)../../src


include $(BUILD_STATIC_LIBRARY)


