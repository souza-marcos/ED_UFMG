#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr){

    for(int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 and arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){

    vector<int> arr = {2, 5, 1, 4, 3, 6, 0};
    sort(arr);
    for (int el : arr) cout << el << " ";

    return 0;
}