#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int binary_to_int(vector<int> b){
    int res = 0;
    for(int i = 0; i < b.size(); i++) res += b[b.size() - i - 1] * pow(2, i);
    return res;  
}


int main(){
    vector<int> a = {1, 0, 0, 1};
    vector<int> b = {1, 1, 1, 0};
    vector<int> res = {0, 0, 0, 0, 0};

    int carry = 0;
    for(int i = a.size() - 1; i >= 0; i--){
        int sum = carry + a[i] + b[i];
        res[i + 1] = sum % 2;
        carry = sum / 2;
    }
    res[0] = carry;

    for(int el: res) cout << el << " ";
    cout << endl << binary_to_int(a) 
         << " + " << binary_to_int(b) 
         << " = " << binary_to_int(res);

    return 0;
}