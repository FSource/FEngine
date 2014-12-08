# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -DLINUX -std=c++11
FLAGS_RELEASE= -O3 -DTOLUA_RELEASE  -DLINUX -std=c++11

#Project infor 
PROJECT_PATH= ../../../library/osx/
PROJECT=luaexport

SRC_DIR=../src
INCLUDE_DIR=-I../src \
			-I../../../libfaeris/src \
			-I../../../lib3rdparty/tolua++/include \
			-I../../../lib3rdparty/Box2D/ \
			-I../../../libextends/lib3rdextends/src \
			-I../../../lib3rdparty/lua/include \
			-I../../../libextends/libaudio/src \
			-I../../../libextends/libnetwork/src \
			-I../../../libextends/libspinesprite/src \
			-I../../../lib3rdparty/cjson/src \
			-I../../../lib3rdparty/ljson/src \


#Source File 
SRC=  	toluaext++.cc \
		luaext/FsLuaScene.cc \
		luaext/FsLuaSysEventListener.cc \
		luaext/FsLuaTouchEventListener.cc \
		luaext/FsLuaHttpRequest.cc \
		luaext/FsLuaSchedulerTarget.cc \
		FsLuaEngine.cc \
		luaexport/FsLibFaerisExport.cc \
		luaexport/FsLibLuaScript.cc \
		luaexport/FsLuaFuncExport.cc \
		luaexport/FsLibSpineSprite.cc \
		luaexport/FsLibBox2d.cc  \




include ../../../MK_BUILD_STATIC_LIB 




