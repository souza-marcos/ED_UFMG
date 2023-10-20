CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
# Oldest $(OBJ)/stack.o 
OBJS = $(OBJ)/utils.o $(OBJ)/main.o 
HDRS =  $(INC)/stack.h $(INC)/binary_tree.h $(INC)/utils.h $(INC)/vector.h
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/tp1.out

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

time: $(EXE)
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" eeeeeeeeeeeeeeeeeeee
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" 1eeeeeeeeeeeeeeeeeee
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" 11eeeeeeeeeeeeeeeeee
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" 111eeeeeeeeeeeeeeeee
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" 1111eeeeeeeeeeeeeeee
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" 11111eeeeeeeeeeeeeee
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" 111111eeeeeeeeeeeeee
	time -p $(EXE) -s "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19" 1111111eeeeeeeeeeeee

$(EXE): $(OBJS)
	$(CC) -g -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

# $(OBJ)/stack.o: $(HDRS) $(SRC)/stack.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.cpp

# $(OBJ)/binary_tree.o: $(HDRS) $(SRC)/binary_tree.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/binary_tree.o $(SRC)/binary_tree.cpp

$(OBJ)/utils.o: $(HDRS) $(SRC)/utils.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/utils.o $(SRC)/utils.cpp