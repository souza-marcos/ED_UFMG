#ifndef AVL_HPP
#define AVL_HPP

int max(int a, int b);

class Node{
public:
    int value;
    int height;
    Node *left, *right, *parent;

    Node(int val) : value(val), height(1), left(nullptr), right(nullptr), parent(nullptr) {}

};

class Tree{

    Node* root;

    void destruct(Node* node);
    void printInOrder(Node* node);
    void remove(Node* subtree, int value);

public:
    Tree();

    ~Tree();

    // Aqui temos altura de folha == 1
    int height(Node* node);

    int balanceFactor(Node* node);

    Node* leftRotate(Node* curHead);

    Node* rightRotate(Node* curHead);

    Node* searchNode(Node* node, int value);

    void insert(int value);
    void remove(int value);

    void printInOrder();
};

#endif
