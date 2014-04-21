# Normal Information 
CC=gcc
FILE_EXT=c

FLAGS_DEBUG= -g -Wall -Werror 
FLAGS_RELEASE= -O3 

#Project info
PROJECT_PATH= ../../../library/linux/3rdparty
PROJECT=ljson

SRC_DIR= ../src/
INCLUDE_DIR= -I../src/ -I../../lua/include

#Source File 
SRC=  fpconv.c \
	  lua_cjson.c \
	  strbuf.c \

include  ../../../MK_BUILD_STATIC_LIB
