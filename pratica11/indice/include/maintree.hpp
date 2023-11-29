#ifndef MAINTREE_HPP
#define MAINTREE_HPP

#include <string>
#include "intree.hpp"

using std::string;

class Node{
public:
    string key;
    InTree tree;
    int height;
    Node *left, *right;

    Node(string key) : key(key), height(1), left(nullptr), right(nullptr) {}

};

class MainTree{

    Node* root;

    void destruct(Node* node);
    void printInOrder(Node* node);
    Node* insert(Node* node, string key, int page);

public:
    MainTree();

    ~MainTree();

    // Aqui temos altura de folha == 1
    int height(Node* node);

    int balanceFactor(Node* node);

    Node* leftRotate(Node* curHead);

    Node* rightRotate(Node* curHead);

    Node* searchNode(Node* node, string key);

    void insert(string key, int page);

    void printInOrder();
};

#endif
