#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <string>

/**
 * @brief Classe que representa um nó de uma árvore binária
 * 
 * @tparam T Tipo de dado a ser armazenado no nó
 */
template <typename T>
class TreeNode {
public:
    // Construtor para inicializar um nó de árvore com um valor
    TreeNode(const T& value): value(value), left(nullptr), right(nullptr) {}

    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
};


/**
 * @brief Classe com funções para manipulação de uma árvore binária
 * 
 * @tparam T Tipo de dado a ser armazenado na árvore
 */
template <typename T>
class BinaryTree {
public:
    
    /**
     * @brief Insere um nó filho como filho direito de um nó pai
     * 
     * @param parent Nó pai
     * @param child Nó filho
     */
    static void insertRight(TreeNode<T>* parent, TreeNode<T>* child) {
        if (parent) {
            parent->right = child;
        }
    }
    /**
     * @brief Insere um nó filho como filho esquerdo de um nó pai
     * 
     * @param parent Nó pai
     * @param child Nó filho
     */
    static void insertLeft(TreeNode<T>* parent, TreeNode<T>* child){
        if (parent) {
            parent->left = child;
        }
    }

    /**
     * @brief Imprime a árvore em pré-ordem
     * 
     * @param node Nó raiz da árvore ou subárvore
     */
    static void printTreePreorder(TreeNode<T>* node){
        if (node) {
            std::cout << node->value << " ";
            printTreePreorder(node->left);
            printTreePreorder(node->right);
        }
    }
    
    /**
     * @brief Imprime a árvore em ordem
     * 
     * @param node Nó raiz da árvore ou subárvore
     */
    static void printTreeInorder(TreeNode<T>* node){
        if (node) {
            printTreeInorder(node->left);
            std::cout << node->value << " ";
            printTreeInorder(node->right);
        }
    }

    /**
     * @brief Imprime a árvore em pós-ordem
     * 
     * @param node Nó raiz da árvore ou subárvore
     */
    static void printTreePosorder(TreeNode<T>* node){
        if (node) {
            printTreePosorder(node->left);
            printTreePosorder(node->right);
            std::cout << node->value << " ";
        }
    }

};

#endif // TREE_HPP