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

    avl.remove(100);
    avl.remove(2);
    avl.remove(3);

    avl.printInOrder();

    return 0;
}
