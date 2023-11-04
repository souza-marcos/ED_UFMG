#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <iostream>
#include "../include/set.hpp"

TEST_CASE("Testando o construtor")
{
    Set<int> set;
    CHECK(set.getSize() == 0);
}

TEST_CASE("Testando o insert")
{
    Set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);
    set.insert(3);
    set.insert(4);
    set.insert(5);
    set.insert(1);
    set.insert(2);
    CHECK(set.getSize() == 5);
}

TEST_CASE("Testando o walk")
{
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);
    // Por enquanto so imprime
    set.walk([](int value) {
        //std::cout << value << std::endl;
    });
}

TEST_CASE("Testando o find")
{
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);
    CHECK(set.find(3) != nullptr);
    CHECK(set.find(4) != nullptr);
    CHECK(set.find(2) != nullptr);
    CHECK(set.find(1) != nullptr);
    CHECK(set.find(5) != nullptr);
    CHECK(set.find(6) == nullptr);
    CHECK(set.find(7) == nullptr);
    CHECK(set.find(8) == nullptr);
    CHECK(set.find(9) == nullptr);
    CHECK(set.find(10) == nullptr);
}

TEST_CASE("Testando FindMax e FindMin")
{
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);
    CHECK(set.findMax()->value == 5);
    CHECK(set.findMin()->value == 1);
}

TEST_CASE("Testando o clear")
{
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);
    set.clear();
    CHECK(set.getSize() == 0);
}

/*
TEST_CASE("Testando remove")
{
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);

    CHECK(set.remove(3) == true);
    CHECK(set.find(3) == nullptr);

    CHECK(set.remove(4) == true);
    CHECK(set.find(4) == nullptr);

    CHECK(set.remove(2) == true);
    CHECK(set.find(2) == nullptr);

    CHECK(set.remove(1) == true);
    CHECK(set.find(1) == nullptr);

    CHECK(set.remove(5) == true);
    CHECK(set.find(5) == nullptr);

    CHECK(set.remove(6) == false);

    CHECK(set.remove(1) == false);

    CHECK(set.getSize() == 0);
}*/

TEST_CASE("Testando iterator")
{
    Set<int> set;
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(5);

    
    auto it = set.begin();
    std::cout << *it << std::endl;
    CHECK(*it == 1);
    // ++it;
    // CHECK(*it == 2);
    // ++it;
    // CHECK(*it == 3);
    // ++it;
    // CHECK(*it == 4);
    // ++it;
    // CHECK(*it == 5);
    // ++it;
    // CHECK(it == set.end());


}

