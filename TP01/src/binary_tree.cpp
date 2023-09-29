#include "binary_tree.hpp"

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

template class TreeNode<char>;