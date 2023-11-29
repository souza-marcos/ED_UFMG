#include <iostream>
using namespace std;

// Max Heap

void heapfy(int left, int right, int* arr){
    int i = left;
    int j = 2 * i + 1;
    int x = arr[i]; // x é o pai inicial 

    while(j <= right){
        if(j < right) // Se tiver dois filhos
            if(arr[j] < arr[j+1]) j++;
            
        if(x >= arr[j]) break;
        
        arr[i] = arr[j];
        i = j;
        j = 2 * i + 1;
    }
    arr[i] = x;
}

void build(int *arr, int n){
    int left = n/2 + 1;

    while(left-- > 0) heapfy(left, n, arr);
}

int remove(int *arr, int &n){
    if(n < 1) return -1; // Heap vazio

    int x = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapfy(0, n - 1, arr);
    return x;
}

void print(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int *arr, int n){
    build(arr, n);
    while(n > 0){
        arr[n - 1] = remove(arr, n);
    }
}

int main(){
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};  

    int n = sizeof(arr)/sizeof(arr[0]);
    build(arr, n);

    heapSort(arr, n);

    print(arr, n);
    
}

