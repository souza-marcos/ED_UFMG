#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr){
    
    for(int j = 0; j < arr.size(); j++){
        int min = j;
        for(int i = j + 1; i < arr.size(); i++){
            if(arr[i] < arr[min]) min = i; 
        }
        swap(arr[j], arr[min]);
    }
}

int main(){

    vector<int> arr = {2, 5, 1, 4, 3, 6, 0, 8, 7, -1};
    sort(arr);
    for (int el : arr) cout << el << " ";

    return 0;
}