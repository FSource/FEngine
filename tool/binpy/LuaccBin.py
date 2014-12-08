from libpy.lua import LuaCompiler

LUACC_BIN_NAME="../binexe/win32/luac.exe"
LUACC_WORKING_DIR=["../tmp/fsources"]



luacc=LuaCompiler(LUACC_WORKING_DIR)
luacc.setBinName(LUACC_BIN_NAME)

print "compile lua,please wait ... "
luacc.compile()












