CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/pa8.o $(OBJ)/heap.o  $(OBJ)/unionFind.o
HDRS = $(INC)/heap.hpp $(INC)/unionFind.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/pa8.out

all: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CC) -g -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/pa8.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pa8.o $(SRC)/main.cpp

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.cpp

$(OBJ)/unionFind.o: $(HDRS) $(SRC)/unionFind.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/unionFind.o $(SRC)/unionFind.cpp

