# Normal Information 
CC=gcc
FLAGS= -g -Wall  -DLINUX
FILE_EXT=c

#Project infor 
PROJECT_PATH=./
PROJECT=luabind++

# User Config Information 
LIB_DIR=$(PROJECT_PATH)lib
OBJ_DIR=$(PROJECT_PATH)obj
BIN_DIR=bin

SRC_DIR=../src

INCLUDE_DIR= -I./  \
			 -I../../../../lib/lib3rdparty/lua/include \
			 -I../../../../lib/lib3rdparty/tolua++/include \
			 -I../../../../lib/libfaeris/src  \

LINK_DIR= -L../../../../lib/library/osx/3rdparty

LINK_LIB=  -ltolua++ \
		   -llua \
		   -lm

#Source File 
SRC= tolua.c \
	 toluabind.c \


	





#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.$(FILE_EXT)=%.o) 
OBJ_NAME_WITH_PATH=$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))




main:$(BIN_DIR)/$(PROJECT).exe

$(BIN_DIR)/$(PROJECT).exe: $(LIB_DIR)/lib$(PROJECT).a
	$(CC) -o $(BIN_DIR)/$(PROJECT).exe $(LINK_DIR) -L$(LIB_DIR) -l$(PROJECT) $(LINK_LIB)  

$(LIB_DIR)/lib$(PROJECT).a: $(OBJ_NAME_WITH_PATH) 
	ar cr $@ $(OBJ_NAME_WITH_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILE_EXT)
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE_DIR) 


