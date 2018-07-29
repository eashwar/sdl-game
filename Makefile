#OBJS specifies which files to compile
OBJS = src/main.cpp

#CC specifies which compiler
CC = g++

#COMPILER_FLAGS specifies additional compilation options
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies libraries
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of exectuable
OBJ_NAME = sdlproj
all: build

build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)

style: 
	astyle src/*
