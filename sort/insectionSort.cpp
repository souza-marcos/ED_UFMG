#include <vector>
#include <iostream>

/**
 * 
 * Estabilidade                 Sim
 * Adaptavel                    Sim
 * Complexidade de Comparacoes  O(n) - Melhor Caso. O(n^2) - Pior Caso.
 * Complexidade de Trocas       ---
 *     -> Código do Professo:   O(n) - Melhor Caso. O(n^2) - Pior Caso.
 */
// template <typename T>
// void insection_sort(std::vector<T> &arr){
//     int size = arr.size();

//     for(int i = 0; i < size; i++){
//         int j = i;
//         while(j > 0 && arr[j] < arr[j - 1]){ 
//             std::swap(arr[j], arr[j - 1]);    
//             j --;
//         }
//     }
// }


template <typename T>
void insection_sort(std::vector<T> &arr){
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
}

int main(){

    std::vector<int> arr = {8, 5, 10, 2, 3, 1, 6};
    insection_sort(arr);

    for(auto el : arr) std::cout << el << " "; 
    std::cout << std::endl;

    return 0;
}