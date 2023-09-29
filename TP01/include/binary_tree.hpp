#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <string>
// #include <vector>

// TreeNode class
template <typename T>
class TreeNode {
public:
    // Constructor to initialize a tree node with a value
    TreeNode(const T& value);

    // Member variables
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
};


// Binary tree class
template <typename T>
class BinaryTree {
public:
    // Constructor to initialize an empty binary tree
    BinaryTree();

    // Function to insert a child node as the right child of a parent node
    static void insertRight(TreeNode<T>* parent, TreeNode<T>* child);

    // Function to insert a child node as the left child of a parent node
    static void insertLeft(TreeNode<T>* parent, TreeNode<T>* child);

    static void printTreePreorder(TreeNode<T>* node);
    static void printTreeInorder(TreeNode<T>* node);
    static void printTreePosorder(TreeNode<T>* node);

    // Function for expression parsing and evaluation
    // void toASTCopy(const std::string& exp);
    // TreeNode<T>* toASTNew(const std::string& exp);

private:
    TreeNode<T>* root;

};


// BinaryTree implementation
template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
void BinaryTree<T>::insertRight(TreeNode<T>* parent, TreeNode<T>* child) {
    if (parent) {
        parent->right = child;
    }
}

template <typename T>
void BinaryTree<T>::insertLeft(TreeNode<T>* parent, TreeNode<T>* child) {
    if (parent) {
        parent->left = child;
    }
}

template <typename T>
void BinaryTree<T>::printTreePreorder(TreeNode<T>* node) {
    if (node) {
        std::cout << node->value << " ";
        printTreePreorder(node->left);
        printTreePreorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::printTreeInorder(TreeNode<T>* node) {
    if (node) {
        printTreeInorder(node->left);
        std::cout << node->value << " ";
        printTreeInorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::printTreePosorder(TreeNode<T>* node) {
    if (node) {
        printTreePosorder(node->left);
        printTreePosorder(node->right);
        std::cout << node->value << " ";
    }
}

// TreeNode implementation
template <typename T>
TreeNode<T>::TreeNode(const T& value) : value(value), left(nullptr), right(nullptr) {}

// template class TreeNode<char>;

#endif // TREE_HPP