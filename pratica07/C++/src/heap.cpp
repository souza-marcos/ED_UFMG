#include "../include/heap.hpp"
#include <iostream>
using namespace std;

Heap::Heap(int maxsize){
    this->tamanho = 0;
    this->data = new int[maxsize];
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

void Heap::Inserir(int x){
    
    this->data[this->tamanho ++] = x; 

    // Heapfy MIN
    int idx_cur = this->tamanho - 1; // Last
    int parent_idx = (idx_cur - 1)/2;

    while(this->data[parent_idx] > this->data[idx_cur]){

        // SWAP
        int aux = this->data[parent_idx];
        this->data[parent_idx] = this->data[idx_cur];
        this->data[idx_cur] = aux;

        idx_cur = parent_idx;
        parent_idx = (idx_cur - 1)/2;
    }
}
int Heap::Remover() {
    if (this->tamanho <= 0) {
        // Handle the case of an empty heap (add appropriate error handling).
        return -1; // You can choose an appropriate return value or throw an exception.
    }
    
    int res = this->data[0];
    this->data[0] = this->data[--this->tamanho];
    
    int idx_cur = 0;
    
    while (true) {
        int left_child = 2 * idx_cur + 1;
        int right_child = 2 * idx_cur + 2;
        
        int min_child = idx_cur; // Assume the current index is the minimum.
        
        if (left_child < this->tamanho && this->data[left_child] < this->data[min_child]) {
            min_child = left_child;
        }
        
        if (right_child < this->tamanho && this->data[right_child] < this->data[min_child]) {
            min_child = right_child;
        }
        
        if (min_child == idx_cur) {
            break; // The heap property is satisfied.
        }
        
        // SWAP
        int aux = this->data[idx_cur];
        this->data[idx_cur] = this->data[min_child];
        this->data[min_child] = aux;
        
        idx_cur = min_child;
    }
    
    return res;
}


bool Heap::Vazio(){
    return (this->tamanho <= 0);
}