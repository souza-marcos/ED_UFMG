#include "heap.hpp"
#include <iostream>
using namespace std;

Heap::Heap(int maxsize){
    this->tamanho = 0;
    this->data = new Aresta[maxsize];
}

Heap::~Heap(){
    delete[] this->data;
}

int Heap::GetAncestral(int position){
    return (position -1)/2;
}

int Heap::GetSucessorDir(int position){
    return (2 * position + 2);
}

int Heap::GetSucessorEsq(int position){
    return (2 * position + 1);
}

void Heap::Inserir(Aresta x){
    
    this->data[this->tamanho ++] = x; 

    // Heapfy MIN
    int idx_cur = this->tamanho - 1; // Last
    int parent_idx = (idx_cur - 1)/2;

    while(this->data[parent_idx].custo > this->data[idx_cur].custo){

        // SWAP
        Aresta aux = this->data[parent_idx];
        this->data[parent_idx] = this->data[idx_cur];
        this->data[idx_cur] = aux;

        idx_cur = parent_idx;
        parent_idx = (idx_cur - 1)/2;
    }
}
Aresta Heap::Remover() {
    if (this->tamanho <= 0) {
        // Handle the case of an empty heap (add appropriate error handling).
        return Aresta{-1, -1, -1}; // You can choose an appropriate return value or throw an exception.
    }
    
    Aresta res = this->data[0];
    this->data[0] = this->data[--this->tamanho];
    
    int idx_cur = 0;
    
    while (true) {
        int left_child = 2 * idx_cur + 1;
        int right_child = 2 * idx_cur + 2;
        
        int min_child = idx_cur; // Assume the current index is the minimum.
        
        if (left_child < this->tamanho && this->data[left_child].custo < this->data[min_child].custo) {
            min_child = left_child;
        }
        
        if (right_child < this->tamanho && this->data[right_child].custo < this->data[min_child].custo) {
            min_child = right_child;
        }
        
        if (min_child == idx_cur) {
            break; // The heap property is satisfied.
        }
        
        // SWAP
        Aresta aux = this->data[idx_cur];
        this->data[idx_cur] = this->data[min_child];
        this->data[min_child] = aux;
        
        idx_cur = min_child;
    }
    
    return res;
}


bool Heap::Vazio(){
    return (this->tamanho <= 0);
}