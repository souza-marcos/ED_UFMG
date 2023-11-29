#include "../include/maintree.hpp"
#include <iostream>

using std::cout, std::endl;

void MainTree::destruct(Node* node){
    if(node == nullptr) return;
    destruct(node->left);
    destruct(node->right);
    delete node;
}

void MainTree::printInOrder(Node* node){
    if(node == nullptr) return;
    printInOrder(node->left);
    cout << node->key << ": ";
    node->tree.printInOrder();
    cout << endl;
    printInOrder(node->right); 
}

MainTree::MainTree(): root(nullptr){}

MainTree::~MainTree(){
    destruct(root);
}

// Aqui temos altura de folha == 1
int MainTree::height(Node* node){
    if(node == nullptr) return 0;
    return node->height;
}

int MainTree::balanceFactor(Node* node){
    if(node == nullptr) return 0;

    return height(node->right) - height(node->left);
}

Node* MainTree::leftRotate(Node* curHead){
    Node *newHead = curHead->right;
    Node *subTree = newHead->left;

    curHead->right = subTree;
    newHead->left = curHead;

    curHead->height = 1 + max(height(curHead->left), height(curHead->right));
    newHead->height = 1 + max(height(newHead->left), height(newHead->right));

    return newHead;
}

Node* MainTree::rightRotate(Node* curHead){
    Node *newHead = curHead->left;
    Node *subTree = newHead->right;

    curHead->left = subTree;
    newHead->right = curHead;

    curHead->height = 1 + max(height(curHead->left), height(curHead->right));
    newHead->height = 1 + max(height(newHead->left), height(newHead->right));

    return newHead;
}

Node* MainTree::searchNode(Node* node, std::string key){
    if(node == nullptr) return nullptr;
    
    if(key == node->key) return node;

    if(key < node->key) return searchNode(node->left, key);
    else return searchNode(node->right, key);
}

Node* MainTree::insert(Node* node, std::string key, int page){
    if (node == nullptr) {
        Node *newNode = new Node(key);
        newNode->tree.insert(page);
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key, page);
    else if (key > node->key)
        node->right = insert(node->right, key, page);
    else{
        node->tree.insert(page);
        return node; // No duplicates allowed
    }
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left Case
    if (balance < -1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance > 1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance < -1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance > 1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    node->height = 1 + max(height(node->left), height(node->right));

    return node;
}


void MainTree::insert(std::string key, int page){ root = insert(root, key, page); }

void MainTree::printInOrder(){ printInOrder(root); }
