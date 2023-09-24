#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-18 - arquivo criado
#		: 2021-10-21 - estrutura de diretórios
#               : 2021-11-15 - Versao 1.1 memlog
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
OBJS = $(OBJ)/main.o $(OBJ)/Matrix.o $(OBJ)/Vector.o $(OBJ)/memlog.o
HDRS = $(INC)/Matrix.h $(INC)/Vector.h $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  mem perf gprof
run : $(EXE)
	$(EXE) 20

mem: $(EXE)
	$(EXE) 20

perf: $(EXE)
	$(EXE) 20

gprof: $(BIN)/main
	$(EXE) 20
	gprof $(EXE) gmon.out > /tmp/determinante20gprof.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o main.cpp 

$(OBJ)/Vector.o: $(HDRS) $(SRC)/Vector.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Vector.o $(SRC)/Vector.cpp

$(OBJ)/Matrix.o: $(HDRS) $(SRC)/Matrix.cc
	$(CC) $(CFLAGS) -o $(OBJ)/Matrix.o $(SRC)/Matrix.cc 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	
clean:
	rm -f $(EXE) $(OBJS)
