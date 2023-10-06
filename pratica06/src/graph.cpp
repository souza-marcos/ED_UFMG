#include "graph.hpp"

#ifndef GRAPH_SIZE
#define GRAPH_SIZE 100
#endif

Grafo::Grafo(bool debug): vertices(GRAPH_SIZE){}

Grafo::~Grafo(){
}

void Grafo::InsereAresta(int v, int w){
    this->vertices.InsereAresta(v, w);
}

void Grafo::InsereVertice(){
    this->vertices.InsereVertice();
}

int Grafo::QuantidadeVertices(){
    return this->vertices.QuantidadeVertices();
}
int Grafo::QuantidadeArestas(){
    return this->vertices.QuantidadeArestas();
}

int Grafo::GrauMinimo(){
    return this->vertices.GrauMinimo();
}

int Grafo::GrauMaximo(){
    return this->vertices.GrauMaximo();
}

void Grafo::ImprimeVizinhos(int v){
    this->vertices.ImprimeVizinhos(v);
}

