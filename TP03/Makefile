CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o
HDRS = $(INC)/vector.hpp $(INC)/matrix2.hpp
CFLAGS = -g -std=c++17 -Wall -c -I$(INC)

EXE = $(BIN)/tp3.out
# TEST = $(BIN)/test.out

all: $(EXE)

# test: $(TEST)
# 	$(TEST) <input.txt
	

$(EXE): $(OBJS)
	$(CC) -g -std=c++11 -o $(EXE) $(OBJS) $(LIBS)

# $(TEST): $(OBJ)/test.o
# 	$(CC) -g -std=c++11 -o $(TEST) $(OBJ)/test.o $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

# $(OBJ)/test.o: $(HDRS) test/test_set.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/test.o test/test_set.cpp

# $(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
# 	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 