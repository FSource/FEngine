main: glslext_scanner.cc glslext_grammer.cc 
	g++  ../src/glslext_scanner.cc   ../src/glslext_grammer.cc \
		 ../src/glslext_parser.cc main.cc  -I../src



glslext_scanner.cc : ../src/rule/glslext_scanner.l 
	flex --bison-bridge --nounistd  -o ../src/glslext_scanner.cc --header-file=../src/glslext_scanner.h  ../src/rule/glslext_scanner.l

glslext_grammer.cc : ../src/rule/glslext_grammer.y 
	bison      -o ../src/glslext_grammer.cc --defines=../src/glslext_grammer.h ../src/rule/glslext_grammer.y




clean:
	rm -f *.out *.o *.tab *.dot *.output
