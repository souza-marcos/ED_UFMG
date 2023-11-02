#ifndef SORT_HPP
#define SORT_HPP

#include "vector.hpp"

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
            if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
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
    int size = arr.getSize();

    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++) 
            if(arr[min] > arr[j]) min = j;    
        
        if(i != min) swap(arr[i], arr[min]);
    }
};


// Quick Sort
template <typename T>
int partition(Vector<T> &arr, int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++){
        if(arr[j] < pivot){
            i ++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

template <typename T>
void quick_sort(Vector<T> &arr, int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

// Merge Sort
template <typename T>
void merge(Vector<T> &arr, int left, int middle, int right){
    int size_left = middle - left + 1;
    int size_right = right - middle;

    Vector<T> left_arr(size_left);
    Vector<T> right_arr(size_right);

    for(int i = 0; i < size_left; i++) left_arr[i] = arr[left + i];
    for(int i = 0; i < size_right; i++) right_arr[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while(i < size_left && j < size_right){
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i ++;
        } else {
            arr[k] = right_arr[j];
            j ++;
        }
        k ++;
    }

    while(i < size_left){
        arr[k] = left_arr[i];
        i ++;
        k ++;
    }

    while(j < size_right){
        arr[k] = right_arr[j];
        j ++;
        k ++;
    }
}

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

    if(left < size && arr[left] > arr[largest]) largest = left;
    if(right < size && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

template <typename T>
void heap_sort(Vector<T> &arr){
    int size = arr.getSize();

    for(int i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);

    for(int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Falta função propria de ordenamento

#endif