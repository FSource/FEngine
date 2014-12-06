# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -DLINUX -std=c++11
FLAGS_RELEASE= -O3 -DTOLUA_RELEASE  -DLINUX -std=c++11

#Project infor 
PROJECT_PATH= ../../../library/osx/
PROJECT=lib3rdextends

SRC_DIR=../src
INCLUDE_DIR=-I../src \
			-I../../../libfaeris/src \
			-I../../../lib3rdparty/tolua++/include \
			-I../../../lib3rdparty/Box2D/ \
			-I../../../libextends/libluaexport/src \


#Source File 
SRC= box2d/fb2ContactListener.cc \
	 box2d/fb2Draw.cc  \
	 box2d/fb2Transform.cc \
	

include ../../../MK_BUILD_STATIC_LIB 


	 

