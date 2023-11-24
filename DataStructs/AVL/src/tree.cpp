#include "tree.hpp"
#include <iostream>

using std::cout, std::endl;

void Tree::destruct(Node* node){
    if(node == nullptr) return;
    destruct(node->left);
    destruct(node->right);
    delete node;
}

void Tree::printInOrder(Node* node){
    if(node == nullptr) return;
    printInOrder(node->left);
    std::cout << node->value << std::endl;
    printInOrder(node->right); 
}

Tree::Tree(): root(nullptr){}

Tree::~Tree(){
    destruct(root);
}


// Aqui temos altura de folha == 1
int Tree::height(Node* node){
    if(node == nullptr) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int Tree::balanceFactor(Node* node){
    if(node == nullptr) return 0;
    return (node->right == nullptr? 0: node->right->height) 
            - (node->left == nullptr? 0: node->left->height);
}

Node* Tree::leftRotate(Node* curHead){
    Node *newHead = curHead->right;
    Node *subTree = newHead->left;

    curHead->right = subTree;
    newHead->left = curHead;

    curHead->height = height(curHead);
    newHead->height = height(newHead);


    newHead->parent = curHead->parent;
    curHead->parent = newHead;
    if(subTree != nullptr) subTree->parent = curHead;

    return newHead;
}

Node* Tree::rightRotate(Node* curHead){
    Node *newHead = curHead->left;
    Node *subTree = newHead->right;

    curHead->left = subTree;
    newHead->right = curHead;

    curHead->height = height(curHead);
    newHead->height = height(newHead);


    newHead->parent = curHead->parent;
    curHead->parent = newHead;
    if(subTree != nullptr) subTree->parent = curHead;

    return newHead;
}

void Tree::insert(int value){

    if(root == nullptr){
        root = new Node(value);
        return;
    }

    Node *cur = root, *last = root;

    while(cur != nullptr){
        last = cur;
        if(value < cur->value) cur = cur->left;
        else cur = cur->right;  // Valores já presentes na árvore são inseridos a direita 
    }


    Node *node = new Node(value);

    bool right = false;

    cur = last;
    if(value < cur->value) cur->left = node;
    else cur->right = node, right = true;
    node->parent = cur;

    last = node;
    
    while(cur != nullptr){
        
        if(cur->height == last->height) cur->height ++;

        int balance = balanceFactor(cur);

        Node* newCur;

        if(balance < -1){
            if(!right) // Inseriu na esquerda do parent 
                newCur = rightRotate(cur);
            else {  // Inseriu na direita do parent
                cur->left = leftRotate(cur->left);
                newCur = rightRotate(cur);
            }
        }
        else if(balance > 1){
            if(right){ // Inseriu na direita do parent
                newCur = leftRotate(cur);
            }else{ // Inseriu na esquerda do parent
                cur->right = rightRotate(cur->right);
                newCur = leftRotate(cur);
            }
        }

        if(balance < -1 or balance > 1){
            if(newCur->parent == nullptr){// Raiz
                root = newCur;
            }else{
                if(newCur->parent->left == cur) newCur->parent->left = newCur;
                else newCur->parent->right = newCur;
            }
        }
        cur = cur->parent;
    }
}

void Tree::printInOrder(){ printInOrder(root); }

int max(int a, int b){
    if(a > b) return a;
    return b;
}
