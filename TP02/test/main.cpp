#include <iostream>
#include "../include/set.hpp"

using std::cout, std::endl;

void func(SetIterator<Set<int>> it){
    cout << (*it << endl;
}

int main()
{ 
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);

    
    auto it = set.begin();
    func(it);
 //   CHECK(*it == 1);
}