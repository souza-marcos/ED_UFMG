#include <vector>
#include <iostream>

/**
 * 
 * Estabilidade                 Nao
 * Adaptavel                    Sim~Nao
 * Complexidade de Comparacoes  O(n^2)
 * Complexidade de Trocas       O(n)
 * 
 */
template <typename T>
void merge_sort(std::vector<T> &arr){
    int size = arr.size();

    
}


int main(){

    std::vector<int> arr = {8, 5, 10, 2, 3, 1, 6};
    merge_sort(arr);

    for(auto el : arr) std::cout << el << " "; 
    std::cout << std::endl;

    return 0;
}