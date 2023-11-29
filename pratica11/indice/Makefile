CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/main.o $(OBJ)/maintree.o $(OBJ)/intree.o
HDRS = $(INC)/maintree.hpp $(INC)/intree.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/pa11.out

run: $(EXE)
	./$(EXE)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -g -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(SRC)/main.cpp $(OBJ)/maintree.o $(OBJ)/intree.o
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/maintree.o: $(SRC)/maintree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/maintree.o $(SRC)/maintree.cpp

$(OBJ)/intree.o: $(SRC)/intree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/intree.o $(SRC)/intree.cpp

