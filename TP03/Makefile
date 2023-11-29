CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o
HDRS = $(INC)/utils.hpp $(INC)/matrix2.hpp $(INC)/segtree.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/tp3.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -g -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

# $(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
# 	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 