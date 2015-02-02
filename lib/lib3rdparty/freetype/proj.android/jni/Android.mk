LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=freetype_static 

LOCAL_SRC_FILES := ../../src/base/ftbbox.c  \
				   ../../src/base/ftbase.c \
				   ../../src/base/ftbitmap.c \
				   ../../src/base/ftfstype.c \
				   ../../src/base/ftgxval.c \
				   ../../src/base/ftgasp.c \
				   ../../src/base/ftglyph.c \
				   ../../src/base/ftinit.c \
				   ../../src/base/ftlcdfil.c \
				   ../../src/base/ftmm.c \
				   ../../src/base/ftotval.c \
				   ../../src/base/ftpatent.c \
				   ../../src/base/ftpfr.c \
				   ../../src/base/ftsynth.c \
				   ../../src/base/ftstroke.c \
				   ../../src/base/ftsystem.c \
				   ../../src/base/fttype1.c \
				   ../../src/base/ftwinfnt.c \
				   ../../src/base/ftxf86.c \
				   ../../src/pcf/pcf.c \
				   ../../src/pfr/pfr.c \
				   ../../src/psaux/psaux.c \
				   ../../src/pshinter/pshinter.c \
				   ../../src/psnames/psmodule.c \
				   ../../src/raster/raster.c \
				   ../../src/sfnt/sfnt.c \
				   ../../src/truetype/truetype.c \
				   ../../src/type1/type1.c \
				   ../../src/cid/type1cid.c \
				   ../../src/type42/type42.c \
				   ../../src/winfonts/winfnt.c \
				   ../../src/autofit/autofit.c \
				   ../../src/bdf/bdf.c \
				   ../../src/cff/cff.c \
				   ../../src/cache/ftcache.c \
				   ../../src/gzip/ftgzip.c \
				   ../../src/lzw/ftlzw.c \
				   ../../src/smooth/smooth.c \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include  

LOCAL_CFLAGS := -DANDROID_NDK \
				-DFT2_BUILD_LIBRARY=1


include $(BUILD_STATIC_LIBRARY)



