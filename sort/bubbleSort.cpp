#include <vector>
#include <iostream>


/**
 * Estabilidade                 Sim 
 * Adaptavel                    Nao
 * Complexidade de Comparacoes  O(n^2)
 * Complexidade de Trocas       O(n^2) 
 * 
 */
template <typename T>
void bubble_sort(std::vector<T> &arr){
    int size = arr.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j + i < size - 1; j++){
            if(arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
        }
    }
}


int main(){

    std::vector<int> arr = {8, 5, 10, 2, 3, 1, 6};
    bubble_sort(arr);

    for(auto el : arr) std::cout << el << " "; 
    std::cout << std::endl;

    return 0;
}