CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/stack.o $(OBJ)/tree.o 
HDRS = $(INC)/treenode.h $(INC)/stack.h $(INC)/tree.h $(INC)/queue.h $(INC)/types.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
	$(EXE) < ./data/input.txt

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) main.c
	$(CC) -g $(CFLAGS) -o $(OBJ)/main.o main.c

$(OBJ)/stack.o: $(HDRS) $(SRC)/stack.c
	$(CC) -g $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.c

$(OBJ)/tree.o: $(HDRS) $(SRC)/tree.c
	$(CC) -g $(CFLAGS) -o $(OBJ)/tree.o $(SRC)/tree.c 

$(OBJ)/queue.o: $(HDRS) $(SRC)/queue.c
	$(CC) -g $(CFLAGS) -o $(OBJ)/queue.o $(SRC)/queue.c
