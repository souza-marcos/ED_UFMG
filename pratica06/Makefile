CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
# Oldest $(OBJ)/stack.o 
OBJS = $(OBJ)/graph.o $(OBJ)/pa6.o 
HDRS = $(INC)/graph.hpp $(INC)/lista_adjacencia.hpp $(INC)/linkedlist.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/pa6.out

all: $(EXE)


$(BIN)/pa6.out: $(OBJS)
	$(CC) -g -std=c++11 -o $(BIN)/pa6.out $(OBJS) $(LIBS)

$(OBJ)/pa6.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pa6.o $(SRC)/main.cpp

# $(OBJ)/stack.o: $(HDRS) $(SRC)/stack.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.cpp

# $(OBJ)/binary_tree.o: $(HDRS) $(SRC)/binary_tree.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/binary_tree.o $(SRC)/binary_tree.cpp

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

