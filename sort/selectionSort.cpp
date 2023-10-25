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
void selection_sort(std::vector<T> &arr){
    int size = arr.size();

    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++) 
            if(arr[min] > arr[j]) min = j;    
        
        if(i != min) std::swap(arr[i], arr[min]);
    }
}


int main(){

    std::vector<int> arr = {8, 5, 10, 2, 3, 1, 6};
    selection_sort(arr);

    for(auto el : arr) std::cout << el << " "; 
    std::cout << std::endl;

    return 0;
}