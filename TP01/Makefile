CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
# Oldest $(OBJ)/stack.o 
OBJS = $(OBJ)/utils.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/msgassert.h $(INC)/memlog.h $(INC)/stack.h $(INC)/binary_tree.h $(INC)/utils.h
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/tp01

all: $(EXE)

test: $(EXE)
	echo "\nTESTES NO EVALUATOR\n"
	$(EXE) -a "0 | 1" 01
	$(EXE) -a "0 | 1 & 2" 010
	$(EXE) -a "~ ( 0 | 1 ) & 2" 101
	$(EXE) -a "~ ~ 0 | 1" 10

	$(EXE) -s "0 | 1 & 2" 0e0
	$(EXE) -s "0 | 1 & 2" e00
	$(EXE) -s "0 | 1" ea 
	$(EXE) -s "0 | ~ ~ 1" ea
	$(EXE) -s "0 | 1 & 2" e11
	$(EXE) -s "0 | 1 & 2 & 3" e11e
# a111 ou 111a ????

$(EXE): $(OBJS)
	$(CC) -pg -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

# $(OBJ)/stack.o: $(HDRS) $(SRC)/stack.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.cpp

# $(OBJ)/binary_tree.o: $(HDRS) $(SRC)/binary_tree.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/binary_tree.o $(SRC)/binary_tree.cpp

$(OBJ)/utils.o: $(HDRS) $(SRC)/utils.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/utils.o $(SRC)/utils.cpp

$(OBJ)/memlog.o: $(HDR\S) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	