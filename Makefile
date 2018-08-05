#OBJS specifies which files to compile
MAIN_OBJ = src/main.cpp
OBJS = src/resource_loader/image_loader.cpp
TEST_OBJS_DIR = src/test
#CC specifies which compiler
CC = g++

#COMPILER_FLAGS specifies additional compilation options
COMPILER_FLAGS = --std=c++11 -Wall -Werror -pedantic

#TEST_COMPILER_FLAGS for the test target
TEST_COMPILER_FLAGS = -Isrc/ -Isrc/test

#LINKER_FLAGS specifies libraries
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of exectuable
OBJ_NAME = sdlproj
TEST_OBJ_NAME = sdltests
all: build

build: $(MAIN_OBJ) $(OBJS)
	$(CC) $(MAIN_OBJ) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)

test: $(OBJS) $(TEST_OBJS_DIR)/*.cpp
	$(CC) $(OBJS) $(TEST_OBJS_DIR)/*.cpp $(COMPILER_FLAGS) $(TEST_COMPILER_FLAGS) $(LINKER_FLAGS) -o $(TEST_OBJ_NAME)
	./$(TEST_OBJ_NAME)

style: 
	astyle --suffix=none -A1 -s4 -C -S -N -Y -m0 -p -xg -D -k1 -W3i -xf -xh -c src/*

clean:
	rm $(OBJ_NAME)
