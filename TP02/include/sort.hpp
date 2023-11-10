#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include "vector.hpp"
#include "pair.hpp"
#include "set.hpp"

#ifndef ID_AUX_VECTOR
#define ID_AUX_VECTOR 2
#endif

/**
 * @brief Função auxiliar para trocar dois elementos de lugar
 * 
 * @tparam T Tipo dos elementos
 */
template <typename T>
void swap(T &a, T &b){
    T aux = a;
    a = b;
    b = aux;
}

/**
 * Estabilidade                 Sim 
 * Adaptavel                    Nao
 * Complexidade de Comparacoes  O(n^2)
 * Complexidade de Trocas       O(n^2) 
 * 
 */
template <typename T>
void bubble_sort(Vector<T> &arr){
    int size = arr.getSize();

    for(int i = 0; i < size; i++){
        for(int j = 0; j + i < size - 1; j++){
            if(arr.at(j) > arr.at(j + 1)) swap(arr[j], arr[j + 1]);
        }
    }
};

/**
 * 
 * Estabilidade                 Sim
 * Adaptavel                    Sim
 * Complexidade de Comparacoes  O(n) - Melhor Caso. O(n^2) - Pior Caso.
 * Complexidade de Trocas       O(n) - Melhor Caso. O(n^2) - Pior Caso.
 */
template <typename T>
void insertion_sort(Vector<T> &arr){
    int size = arr.getSize();

    for(int i = 0; i < size; i++){
        T element = arr.at(i);
        int j = i;
        while(j > 0 && element < arr.at(j - 1)){ 
            arr[j] = arr.at(j - 1);    
            j --;
        }
        arr[j] = element;
    }
};

/**
 * 
 * Estabilidade                 Nao
 * Adaptavel                    Sim~Nao
 * Complexidade de Comparacoes  O(n^2)
 * Complexidade de Trocas       O(n)
 * 
 */
template <typename T>
void selection_sort(Vector<T> &arr){
    int size = arr.getSize();

    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++) 
            if(arr.at(min) > arr.at(j)) min = j;    
        
        if(i != min) swap(arr[i], arr[min]);
    }
};

// Quick Sort - Implementacao com pivo central
void partition(Vector<Pair<int,int>> &arr, int left, int right, int& i, int& j){
    Pair<int, int> pivot = arr.at((left + right) / 2);
    i = left; j = right;

    do{
        while(arr.at(i) < pivot) i ++;
        while(arr.at(j) > pivot) j --;

        if(i <= j) {
            // Swap them
            Pair<int,int> aux = arr.at(i);
            arr[i] = arr.at(j);
            arr[j] = aux;

            i ++, j --;
        }
    }while(i <= j);
}

/**
 * 
 * Estabilidade                 Nao
 * Adaptavel                    Nao
 * Complexidade de Comparacoes  O(n log n) - Melhor Caso. O(n^2) - Pior Caso.
 * 
 */
template <typename T>
void quick_sort(Vector<T> &arr, int left, int right){
    if(left < right){
        int i, j;
        partition(arr, left, right, i, j);
        if(left < j) quick_sort(arr, left, j);
        if(right > i) quick_sort(arr, i, right);
    }
}

// Merge Sort
template <typename T>
void merge(Vector<T> &arr, int left, int middle, int right){
    int size_left = middle - left + 1;
    int size_right = right - middle;

    Vector<T> left_arr(size_left, ID_AUX_VECTOR);
    Vector<T> right_arr(size_right, ID_AUX_VECTOR);

    for(int i = 0; i < size_left; i++) left_arr[i] = arr.at(left + i);
    for(int i = 0; i < size_right; i++) right_arr[i] = arr.at(middle + 1 + i);

    int i = 0, j = 0, k = left;
    while(i < size_left && j < size_right){
        if(left_arr.at(i) <= right_arr.at(j)){
            arr[k] = left_arr.at(i);
            i ++;
        } else {
            arr[k] = right_arr.at(j);
            j ++;
        }
        k ++;
    }

    while(i < size_left){
        arr[k] = left_arr.at(i);
        i ++;
        k ++;
    }

    while(j < size_right){
        arr[k] = right_arr.at(j);
        j ++;
        k ++;
    }
}

/**
 * 
 * Estabilidade                 Sim
 * Adaptavel                    Não
 * Complexidade de Comparacoes  O(n log n)
 * 
 * Complexidade de Espaço       O(n)
 * 
 */
template <typename T>
void merge_sort(Vector<T> &arr, int left, int right){
    if(left < right){
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Heap Sort
template <typename T>
void heapify(Vector<T> &arr, int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr.at(left) > arr.at(largest)) largest = left;
    if(right < size && arr.at(right) > arr.at(largest)) largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

/**
 * 
 * Estabilidade                 Nao
 * Adaptavel                    Nao
 * Complexidade de Comparacoes  O(n log n) - Independente do caso
 * 
 */
template <typename T>
void heap_sort(Vector<T> &arr){
    int size = arr.getSize();

    for(int i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);

    for(int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/**
 * Método de Ordenação feito exclusivamente para o problema do TP02 
 * Utiliza a ideia de Counting Sort para ordenar os vértices de acordo com a cor
 * de modo que os vértices de mesma cor fiquem juntos. Note que ao inserir no vec de indice i,
 * esse subvetor já está ordenado.
 * 
 */
void my_sort(Vector<Pair<int, int>> &arr, int maxColor){
    Vector<Vector<int>> sets(maxColor, ID_AUX_VECTOR); // Cria um vetor de conjuntos de tamanho maxColor + 1

    for(size_t i = 0; i < arr.getSize(); i ++){ // Percorre o array de cores
        sets[arr.at(i).first - 1].push_back(arr.at(i).second); // Insere no conjunto da cor
    }
    
    int cont = 0;
    for(int i = 0; i < maxColor; i ++){ 
        auto vec = sets.at(i); // Pega o conjunto da cor i + 1

        int size = vec.getSize();
       
        for(int j = 0; j < size; j ++){
            arr[cont ++] = makePair(i + 1, vec.at(j));
        }
    }
}

#endif