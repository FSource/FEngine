LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=png_static 

LOCAL_SRC_FILES := ../../src/png.c \
				   ../../src/pngerror.c \
				   ../../src/pngget.c \
				   ../../src/pngmem.c \
				   ../../src/pngpread.c \
				   ../../src/pngread.c \
				   ../../src/pngrio.c \
				   ../../src/pngrtran.c \
				   ../../src/pngrutil.c \
				   ../../src/pngset.c \
				   ../../src/pngtrans.c \
				   ../../src/pngwio.c \
				   ../../src/pngwrite.c \
				   ../../src/pngwtran.c \
				   ../../src/pngwutil.c \

LOCAL_C_INCLUDES := -I../../src 

include $(BUILD_STATIC_LIBRARY)


