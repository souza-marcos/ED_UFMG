#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-01 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#--------------------------------------------------------------------- 

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/f_math.o $(OBJ)/main.o # $(OBJ)/memlog.o
HDRS = $(INC)/f_math.hpp # $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -pg -Wall -c -I$(INC) # -O2 # The O2 optimization  Wowww

GPROF_DIR = ./tmp/gprof

EXE = $(BIN)/main

run: $(EXE)
	$(EXE) 1 5
	$(EXE) 2 5
	$(EXE) 3 5
	$(EXE) 4 5

gprof: $(BIN)/main
	mkdir -p $(GPROF_DIR)
	$(EXE) 1 10
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fib_recur_10.txt
	$(EXE) 1 20
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fib_recur_20.txt
	$(EXE) 1 40
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fib_recur_40.txt
	$(EXE) 2 10000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fib_itera_10000.txt
	$(EXE) 2 100000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fib_itera_100000.txt
	$(EXE) 2 1000000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fib_itera_1000000.txt
	$(EXE) 3 1000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fat_recur_1000.txt
	$(EXE) 3 10000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fat_recur_10000.txt
	$(EXE) 3 100000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fat_recur_100000.txt
	$(EXE) 4 10000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fat_itera_10000.txt
	$(EXE) 4 100000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fat_itera_100000.txt
	$(EXE) 4 1000000
	gprof $(EXE) gmon.out > $(GPROF_DIR)/fat_itera_1000000.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/f_math.o: $(HDRS) $(SRC)/f_math.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/f_math.o $(SRC)/f_math.cpp 


clean:
	rm -f $(EXE) $(OBJS) gmon.out
	rm -rf ./tmp
