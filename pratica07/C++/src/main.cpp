#include <iostream>
#include "../include/heap.hpp"

using std::cin, std::cout;
#define endl '\n'

int main(){
    int n; cin >> n;

    Heap h(n);
    int in;
    for(int i = 0; i < n; i++){
        cin >> in;
        h.Inserir(in); 
    }

    while (!h.Vazio())
    {
        cout << h.Remover() << " ";
    }
    cout << endl;
    
    return 0;
}