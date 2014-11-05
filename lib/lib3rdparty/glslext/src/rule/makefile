main:
	flex --bison-bridge --nounistd  -o ../glslext_scanner.cc --header-file=../glslext_scanner.h  glslext_scanner.l 
	bison -o ../glslext_grammer.cc --defines=../glslext_grammer.h glslext_grammer.y
