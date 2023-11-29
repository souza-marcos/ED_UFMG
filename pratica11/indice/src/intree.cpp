#include "../include/intree.hpp"
#include <iostream>

using std::cout, std::endl;


int max(int a, int b) {
    return (a > b) ? a : b;
}

int InTree::height(InNode* node) {
    if(node == nullptr) return 0;
    return node->height;
}

int InTree::balanceFactor(InNode* node) {
    if (node == nullptr) return 0;
    return height(node->right) - height(node->left);
}

InNode* InTree::leftRotate(InNode* curHead) {
    InNode* newHead = curHead->right;
    InNode* subTree = newHead->left;

    curHead->right = subTree;
    newHead->left = curHead;

    curHead->height = 1 + max(height(curHead->left), height(curHead->right));
    newHead->height = 1 + max(height(newHead->left), height(newHead->right));

    return newHead;
}

InNode* InTree::rightRotate(InNode* curHead) {
    InNode* newHead = curHead->left;
    InNode* subTree = newHead->right;

    curHead->left = subTree;
    newHead->right = curHead;

    curHead->height = 1 + max(height(curHead->left), height(curHead->right));
    newHead->height = 1 + max(height(newHead->left), height(newHead->right));

    return newHead;
}

InNode* InTree::searchNode(InNode* node, int key) {
    if (node == nullptr) return nullptr;

    if (key == node->key) return node;

    if (key < node->key) return searchNode(node->left, key);
    else return searchNode(node->right, key);
}

InNode* InTree::insert(InNode* node, int key) {
    if (node == nullptr) return new InNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // No duplicates allowed

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

void InTree::printInOrder(InNode* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    cout << node->key << " ";
    printInOrder(node->right);
}

void InTree::destruct(InNode* node) {
    if (node == nullptr) return;
    destruct(node->left);
    destruct(node->right);
    delete node;
}


InTree::InTree() : root(nullptr) {}

InTree::~InTree() {
    destruct(root);
}

void InTree::insert(int key) {
    root = insert(root, key);
}

void InTree::printInOrder() {
    printInOrder(root);
}

