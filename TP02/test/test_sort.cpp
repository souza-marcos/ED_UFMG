#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <iostream>

#include "sort.hpp"
#include "vector.hpp"
#include "pair.hpp"

void instanceTest(Vector<Pair<int, int>> &v){
    v.push_back(makePair(1, 3));
    v.push_back(makePair(1, 1));
    v.push_back(makePair(3, 3));
    v.push_back(makePair(5, 4));
    v.push_back(makePair(5, 5));
    v.push_back(makePair(2, 10));
    v.push_back(makePair(2, 2));
}

TEST_CASE("Bubble Sort"){

    Vector<Pair<int, int>> v;
    instanceTest(v);

    bubble_sort(v);

    for(size_t i = 0; i < v.getSize(); i ++){
        std::cout << v[i].first << " " << v[i].second << "\n"; 
    }
    std::cout << std::endl;
}

TEST_CASE("Insertion Sort"){

    Vector<Pair<int, int>> v;
    instanceTest(v);

    insertion_sort(v);

    for(size_t i = 0; i < v.getSize(); i ++){
        std::cout << v[i].first << " " << v[i].second << "\n"; 
    }
    std::cout << std::endl;
}

TEST_CASE("Selection Sort"){

    Vector<Pair<int, int>> v;
    instanceTest(v);

    selection_sort(v);

    for(size_t i = 0; i < v.getSize(); i ++){
        std::cout << v[i].first << " " << v[i].second << "\n"; 
    }
    std::cout << std::endl;
}

TEST_CASE("Merge Sort"){

    Vector<Pair<int, int>> v;
    instanceTest(v);

    merge_sort(v, 0, v.getSize() - 1);

    for(size_t i = 0; i < v.getSize(); i ++){
        std::cout << v[i].first << " " << v[i].second << "\n"; 
    }
    std::cout << std::endl;
}

TEST_CASE("Quick Sort"){

    Vector<Pair<int, int>> v;
    instanceTest(v);

    quick_sort(v, 0, v.getSize() - 1);

    for(size_t i = 0; i < v.getSize(); i ++){
        std::cout << v[i].first << " " << v[i].second << "\n"; 
    }
    std::cout << std::endl;
}

TEST_CASE("Heap Sort"){

    Vector<Pair<int, int>> v;
    instanceTest(v);

    heap_sort(v);

    for(size_t i = 0; i < v.getSize(); i ++){
        std::cout << v[i].first << " " << v[i].second << "\n"; 
    }
    std::cout << std::endl;
}



