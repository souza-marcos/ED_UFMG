#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
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

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/matop.o $(OBJ)/mat.o $(OBJ)/memlog.o
HDRS = $(INC)/mat.h $(INC)/memlog.h $(INC)/msgassert.h
OBJSM = $(OBJ)/pilhaindexada.o $(OBJ)/analisamem.o
HDRSM = $(INC)/pilhaindexada.h $(INC)/msgassert.h
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/matop
DIROUT = pratica04

all:  bin mem perf gprof

mem: $(EXE)
	rm -rf /tmp/${DIROUT}
	mkdir /tmp/${DIROUT}
	mkdir /tmp/${DIROUT}/gprof
	mkdir /tmp/${DIROUT}/mult
	$(EXE) -m -p /tmp/${DIROUT}/mult/multlog.out -x 80 -y 80 
	$(BIN)/analisamem -i /tmp/${DIROUT}/mult/multlog.out -p /tmp/${DIROUT}/mult/mult
	gnuplot /tmp/${DIROUT}/mult/*.gp

perf: $(EXE)
	$(EXE) -m -c /tmp/${DIROUT}/mult10x10.out


gprof: $(BIN)/matop
	$(EXE) -m -c /tmp/${DIROUT}/gprof/mult1500x1500gprof.out 
	gprof $(EXE) gmon.out > /tmp/${DIROUT}/gprof/mult1500x1500gprof.txt

$(BIN)/matop: $(OBJS)
	$(CC) -pg -o $(BIN)/matop $(OBJS) $(LIBS)

$(OBJ)/matop.o: $(HDRS) $(SRC)/matop.c
	$(CC) $(CFLAGS) -o $(OBJ)/matop.o $(SRC)/matop.c

$(OBJ)/mat.o: $(HDRS) $(SRC)/mat.c
	$(CC) $(CFLAGS) -o $(OBJ)/mat.o $(SRC)/mat.c 

$(OBJ)/memlog.o: $(HDRSM) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 

bin: $(BIN)/analisamem

$(BIN)/analisamem: $(OBJSM)
	$(CC) -pg -o $(BIN)/analisamem $(OBJSM) $(LIBS)

$(OBJ)/analisamem.o: $(HDRSM) $(SRC)/analisamem.c
	$(CC) $(CFLAGS) -o $(OBJ)/analisamem.o $(SRC)/analisamem.c 

$(OBJ)/pilhaindexada.o: $(HDRSM) $(SRC)/pilhaindexada.c
	$(CC) $(CFLAGS) -o $(OBJ)/pilhaindexada.o $(SRC)/pilhaindexada.c 
	
clean:
	rm -f $(EXE) $(OBJS) $(OBJSM) $(BIN)/analisamem *.out
	rm -rf /tmp/${DIROUT}