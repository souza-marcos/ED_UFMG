CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
# Oldest $(OBJ)/stack.o 
OBJS = $(OBJ)/main.o 
HDRS = $(INC)/vector.h
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/tp2.out

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
