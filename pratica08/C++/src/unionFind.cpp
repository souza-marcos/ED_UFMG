#include "unionFind.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos) {
    this->tamanho = quantidade_subconjuntos;
    this->subconjuntos = new Subconjunto[quantidade_subconjuntos];
}

UnionFind::~UnionFind() {
    delete[] this->subconjuntos;
}

void UnionFind::Make(int x) {
    this->subconjuntos[x].representante = x;
    this->subconjuntos[x].rank = 0;
}

int UnionFind::Find(int x) {
    int ptx = x;

    while(ptx != this->subconjuntos[ptx].representante){
        ptx = this->subconjuntos[ptx].representante;
    }
    
    // Otimizacao Parcial 
    this->subconjuntos[x].representante = ptx; 

    return ptx; 
}

void UnionFind::Union(int x, int y) {
    
    Subconjunto *parent, *child;
    
    Subconjunto* s_x = &this->subconjuntos[x];
    Subconjunto* s_y = &this->subconjuntos[y];

    // Escolhe conjunto de maior rank para ser o representante
    if(s_x->rank >= s_y->rank){
        parent = &this->subconjuntos[Find(s_x->representante)];
        child = &this->subconjuntos[Find(s_y->representante)];
    }
    else{
        parent = &this->subconjuntos[Find(s_y->representante)];
        child = &this->subconjuntos[Find(s_x->representante)];
    }

    child->representante = parent->representante;
    if(parent->rank == child->rank) parent->rank++;

}

