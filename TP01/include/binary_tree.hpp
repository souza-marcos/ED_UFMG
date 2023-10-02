#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <string>

#include "stack.hpp"

#ifndef MAX_STACK
#define MAX_STACK 100
#endif
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

    // Destrutor para desalocar memória
    ~TreeNode() {
        delete left;
        delete right;
    }
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
    static void printTreePreorder(TreeNode<T>* node, void (*print)(T data)){
        if(node == nullptr) return;

        Stack<TreeNode<T>*> stack(MAX_STACK);
        stack.push(node);

        while(!stack.isEmpty()){
            TreeNode<T>* cur = stack.top(); stack.pop();

            print(cur->value);

            if(cur->right != nullptr) stack.push(cur->right);
            if(cur->left != nullptr) stack.push(cur->left);
        }
    }
    
    /**
     * @brief Imprime a árvore em ordem
     * 
     * @param node Nó raiz da árvore ou subárvore
     */
    static void printTreeInorder(TreeNode<T>* node, void (*print)(T data)){
        if(node == nullptr) return;

        Stack<TreeNode<T>*> stack(MAX_STACK);
        TreeNode<T>* cur = node;

        while(!stack.isEmpty() || cur != nullptr){
            if(cur != nullptr){
                stack.push(cur);
                cur = cur->left;
            }else{
                cur = stack.top(); stack.pop();
                print(cur->value);
                cur = cur->right;
            }
        }
    }

    /**
     * @brief Imprime a árvore em pós-ordem
     * 
     * @param node Nó raiz da árvore ou subárvore
     */
    static void printTreePosorder(TreeNode<T>* node, void (*print)(T data)){
        if(node == nullptr) return;

        Stack<TreeNode<char>*> stack(MAX_STACK);
        TreeNode<char>* cur = node;
        TreeNode<char>* last = nullptr;

        while (!stack.isEmpty() || cur != nullptr) {
            if (cur) {
                stack.push(cur);
                cur = cur->left;
            } else {
                TreeNode<char>* aux = stack.top();

                // Se o nó do topo da pilha tem um filho direito e esse filho direito
                // não foi visitado ainda, então vamos para o filho direito.
                // Posordem -> esquerda, direita, raiz 
                if (aux->right != nullptr && last != aux->right) {
                    cur = aux->right;
                } else {
                    print(aux->value);
                    last = stack.top();
                    stack.pop();
                }
            }
        }
    }

};

#endif // TREE_HPP