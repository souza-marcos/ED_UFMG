#ifndef INTREE_HPP
#define INTREE_HPP

int max(int a, int b);

class InNode{
public:
    int key;
    int height;
    InNode *left, *right;

    InNode(int key) : key(key), height(1), left(nullptr), right(nullptr){}

};

class InTree{

    InNode* root;

    void destruct(InNode* Innode);
    void printInOrder(InNode* Innode);

    InNode* insert(InNode* node, int key);

public:
    InTree();

    ~InTree();

    // Aqui temos altura de folha == 1
    int height(InNode* Innode);

    int balanceFactor(InNode* Innode);

    InNode* leftRotate(InNode* curHead);

    InNode* rightRotate(InNode* curHead);

    InNode* searchNode(InNode* Innode, int key);

    void insert(int key);

    void printInOrder();
};

#endif
