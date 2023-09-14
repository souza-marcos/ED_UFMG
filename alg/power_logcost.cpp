#include <iostream>
using namespace std;

double power(double x, unsigned int n){
    if(n == 0) return 1;
    
    double retValue = 1;
    while(n){
        cout << x << " ";
        if(n % 2) retValue *= x;
        
        x *= x;
        n /= 2;
    } // Quando n == 1, retValue assume o valor de x^n.
    return retValue;

}

int main(){
    int a, b;
    cin >> a >> b;
    cout << endl << power(a, b);
    return 0;
}