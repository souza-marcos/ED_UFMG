CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/pa10.o $(OBJ)/Set.o
HDRS = $(INC)/Set.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/pa10.out

all: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CC) -g -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/pa10.o: $(SRC)/main.cpp $(OBJ)/Set.o
	$(CC) $(CFLAGS) -o $(OBJ)/pa10.o $(SRC)/main.cpp

$(OBJ)/Set.o: $(SRC)/Set.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Set.o $(SRC)/Set.cpp

