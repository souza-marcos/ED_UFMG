CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/stack.o $(OBJ)/tree.o 
HDRS = $(INC)/node.h $(INC)/stack.h $(INC)/tree.h 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
	$(EXE) < ./data/input.txt

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o main.c

$(OBJ)/stack.o: $(HDRS) $(SRC)/stack.c
	$(CC) $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.c

$(OBJ)/tree.o: $(HDRS) $(SRC)/tree.c
	$(CC) $(CFLAGS) -o $(OBJ)/tree.o $(SRC)/tree.c 

