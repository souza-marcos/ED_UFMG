#include <iostream>
#include "tree.hpp"

int main(){
    
    Tree avl;

    avl.insert(1);
    avl.insert(3);
    avl.insert(2);
    avl.insert(-1);
    avl.insert(0);
    avl.insert(100);
     
    avl.printInOrder();

    return 0;
}
