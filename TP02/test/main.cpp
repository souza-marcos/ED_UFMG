#include <iostream>
#include "../include/set.hpp"

using std::cout, std::endl;

int main()
{
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);
    
    Node<int>* res;

    cout << set.remove(3) << endl;
    res = set.find(3);
    cout << (res == nullptr? "nullptr" : std::to_string(res->value)) << endl;

    cout << set.remove(5) << endl; // Must be 1 but it is 0
    res = set.find(5);
    cout << (res == nullptr? "nullptr" : std::to_string(res->value)) << endl;


    cout << set.remove(6) << endl; // Must be 0

    cout << set.remove(1) << endl; // Must be 0

    cout << set.getSize() << endl; // Must be 3
}