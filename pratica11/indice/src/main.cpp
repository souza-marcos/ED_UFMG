#include <iostream>
#include "maintree.hpp"

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    MainTree avl;

    string palavra;
    int pagina;

    while (cin.peek() != EOF){
        cin >> palavra >> pagina;
        avl.insert(palavra, pagina);
    }	 

    avl.printInOrder();

    return 0;
}
