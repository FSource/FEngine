LOCAL_PATH :=$(call my-dir)


include $(CLEAR_VARS)

LOCAL_MODULE := luaexport_static


LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../src \
					 -I$(LOCAL_PATH)/../src/luaext \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/lua/include \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/tolua++/include \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/fmod/include \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/Box2D  \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/ljson/src \
					 -I$(LOCAL_PATH)/../../../libextends/lib3rdextends/src \
					 -I$(LOCAL_PATH)/../../../libextends/libsensor/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src/support  \
					 -I$(LOCAL_PATH)/../../libaudio/src \
					 -I$(LOCAL_PATH)/../../libnetwork/src \
					 -I$(LOCAL_PATH)/../../libspinesprite/src 


LOCAL_SRC_FILES :=  ../src/toluaext++.cc \
					../src/luaext/FsLuaScene.cc \
					../src/luaext/FsLuaSysEventListener.cc \
					../src/luaext/FsLuaTouchEventListener.cc \
					../src/luaext/FsLuaHttpRequest.cc \
					../src/luaext/FsLuaSchedulerTarget.cc \
					../src/luaext/FsLuaAction.cc \
					../src/FsLuaEngine.cc \
					../src/luaexport/FsLibFaerisExport.cc \
					../src/luaexport/FsLibLuaScript.cc \
					../src/luaexport/FsLuaFuncExport.cc \
					../src/luaexport/FsLibSpineSprite.cc \
					../src/luaexport/FsLibBox2d.cc  \
					../src/luaexport/FsLibSensorExport.cc \



					 



include $(BUILD_STATIC_LIBRARY)









