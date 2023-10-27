#include "Vector.h"

/**
 * Estabilidade                 Sim 
 * Adaptavel                    Nao
 * Complexidade de Comparacoes  O(n^2)
 * Complexidade de Trocas       O(n^2) 
 * 
 */
template <typename T>
void bubble_sort(Vector<T> &arr){
    int size = arr.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j + i < size - 1; j++){
            if(arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
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
    int size = arr.size();

    for(int i = 0; i < size; i++){
        T element = arr[i];
        int j = i;
        while(j > 0 && element < arr[j - 1]){ 
            arr[j] = arr[j - 1];    
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
    int size = arr.size();

    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++) 
            if(arr[min] > arr[j]) min = j;    
        
        if(i != min) std::swap(arr[i], arr[min]);
    }
};

