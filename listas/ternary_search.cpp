#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

/* Ternary search is a divide and conquer algorithm that can be used to find an element in an array.
 * It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element).
 * We can divide the array into three parts by taking mid1 and mid2 which can be calculated as shown below.
 *
 */
int ternary_search(int l, int r, int x){
    if(l == r) return l;

    int mid1 = (l + r) / 3; if(mid1 < l) mid1 = l;
    int mid2 = 2 * (l + r) / 3; if(mid2 > r) mid2 = r;

    cout << l << " " << mid1 << " " << mid2 << " " << r << endl;

    if(r - l == 1) return (arr[l] == x) ? l : (arr[r] == x ? r : -1);

    if(arr[mid1] >= x){
        if(arr[mid1] == x) return mid1;
        return ternary_search(l, mid1, x);
    }else{
        if(arr[mid2] >= x){
            if(arr[mid2] == x) return mid2;
            return ternary_search(mid1, mid2, x);
        }else{
            return ternary_search(mid2, r, x);
        }
    }
}

int main (){

    cout << ternary_search(0, arr.size() - 1, 12) << endl;
    return 0;
}

