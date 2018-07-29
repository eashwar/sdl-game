#OBJS specifies which files to compile
OBJS = src/main.cpp

#CC specifies which compiler
CC = g++

#COMPILER_FLAGS specifies additional compilation options
COMPILER_FLAGS = -Wall -Werror -pedantic

#LINKER_FLAGS specifies libraries
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of exectuable
OBJ_NAME = sdlproj
all: build

build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)

style: 
	astyle --suffix=none -A1 -s4 -C -S -N -Y -m0 -p -xg -D -k1 -W3i -xf -xh -c src/*

clean:
	rm $(OBJ_NAME)