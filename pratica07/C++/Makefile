CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
# Oldest $(OBJ)/stack.o 
OBJS = $(OBJ)/pa7.o $(OBJ)/heap.o 
HDRS = $(INC)/heap.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/pa7.out

all: $(EXE)
	$(EXE)

$(BIN)/pa7.out: $(OBJS)
	$(CC) -g -std=c++11 -o $(BIN)/pa7.out $(OBJS) $(LIBS)

$(OBJ)/pa7.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pa7.o $(SRC)/main.cpp

# $(OBJ)/stack.o: $(HDRS) $(SRC)/stack.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.cpp

# $(OBJ)/binary_tree.o: $(HDRS) $(SRC)/binary_tree.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/binary_tree.o $(SRC)/binary_tree.cpp

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.cpp

