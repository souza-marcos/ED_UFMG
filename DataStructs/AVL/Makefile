CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/main.o $(OBJ)/tree.o
HDRS = $(INC)/tree.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/main

all: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CC) -g -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(SRC)/main.cpp $(OBJ)/tree.o
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/tree.o: $(SRC)/tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tree.o $(SRC)/tree.cpp

