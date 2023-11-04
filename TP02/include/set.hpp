#ifndef SET_HPP
#define SET_HPP

#include <cstddef> // size_t
#include <iostream>
#include "stack.hpp"

template <typename T>
struct Node
{
    T value;
    Node *left;
    Node *right;
    Node *parent;
    Node(T value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    // ~Node<T>()
    // {
    //     delete left;
    //     delete right;
    // }
};


template <typename T>
class SetIterator
{
public:
    using ValueType = T;


public:

    SetIterator(Node<ValueType>* ptr): m_Ptr(ptr) {
        // Adiciona todos os nos da arvore a esquerda do no atual na pilha
        while(m_Ptr != nullptr){
            stack.push(m_Ptr);
            m_Ptr = m_Ptr->left; // Vai para o menor indice
        }
    }

    bool operator!=(const SetIterator& other) const
    {
        return m_Ptr != other.m_Ptr;
    }

    bool operator==(const SetIterator& other) const
    {
        return m_Ptr == other.m_Ptr;
    }

    const ValueType& operator*() const
    {
        return *(m_Ptr);
    }

    SetIterator& operator++()
    {

        // if(m_Ptr == nullptr) return;
        // while(!stack.isEmpty() || m_Ptr != nullptr){
        //     if(cur != nullptr){
        //         stack.push(cur);
        //         cur = cur->left;
        //     }else{
        //         cur = stack.top(); stack.pop();
        //         print(cur->value);
        //         cur = cur->right;
        //     }
        // }   

        if(stack.isEmpty()) {
            m_Ptr = nullptr; 
            return *this;
        }

        // Vai para o no pai
        m_Ptr = stack.top(); stack.pop();

        // Vai para o no a direita do pai e adiciona todos os nos a esquerda
        Node<ValueType>* aux = m_Ptr->right;
        while(aux != nullptr){
            stack.push(aux);
            aux = aux->left;
            std::cout << "aux: "<< aux->value << "\n";
        }
        m_Ptr = stack.top(); stack.pop();
        std::cout << "m_Ptr: "<< m_Ptr->value << "\n";
        return *this;
    }

private:
    Node<ValueType> *m_Ptr;             // Ponteiro para o no atual
    Stack<Node<ValueType>*> stack; // Pilha para percorrer a arvore
};


template <typename T>
class Set
{
public:
    using ValueType = T;
    using Iterator = SetIterator<Set<T>>;
    friend class Node<T>;
    friend class SetIterator<Set<T>>;

private:
    Node<T> *root;
    size_t size ;

    /**
     * @brief Insere um valor na arvore binaria de busca
     * 
     * @param node no da raiz da arvore (Opcional)
     * @param value Valor que deve ser inserido
     */
    void insert(T value, Node<T> *node)
    {
        if (root == nullptr) // Arvore vazia
        {
            root = new Node<T>(value);
            this->size++;
            return;
        }
        if (value < node->value) // Inserindo na subarvore esquerda
        {

            if (node->left == nullptr) // Chegou na folha
            {
                node->left = new Node<T>(value);
                node->left->parent = node;
                this->size++;
            }
            else insert(value, node->left);
        }
        else if (value > node->value) // Inserindo na subarvore direita
        {
            if (node->right == nullptr) // Chegou na folha
            {
                node->right = new Node<T>(value);
                node->right->parent = node;
                this->size++;
            }
            else insert(value, node->right);
        }
        // Caso seja Igual nao inserimos o valor na arvore
    }

    void walk(Node<T> *node, void (*callback)(T))
    {
        if (node != nullptr)
        {
            walk(node->left, callback);
            callback(node->value);
            walk(node->right, callback);
        }
    }


    /**
     * @brief Limpa a subarvore
     * 
     * @param node no da raiz da subarvore
     */
    void clear(Node<T> *node)
    {
        if (node != nullptr)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    /**
     * @brief Procura um valor na arvore
     * 
     * @param node No da raiz da arvore
     * @param value Valor a ser procurado
     * @return Node<T>* Ponteiro para o no que contem o valor, nullptr caso nao exista
     */
    Node<T> *find(Node<T> *node, T value)
    {
        if (node == nullptr)           return nullptr;
        else if (node->value == value) return node;
        else if (value < node->value)  return find(node->left, value);
        else                           return find(node->right, value);
    }

    /**
     * @brief Procura o no com o menor valor da arvore
     * 
     * @param node raiz da subarvore
     * @return Node<T>* Ponteiro para o no com o menor valor
     */
    Node<T> *findMin(Node<T> *node)
    {
        if (node->left == nullptr) return node;
        else return findMin(node->left);
    }

    /**
     * @brief Procura o no com o maior valor da arvore
     * 
     * @param node raiz da subarvore
     * @return Node<T>* Ponteiro para o no com o maior valor
     */
    Node<T> *findMax(Node<T> *node)
    {
        if (node->right == nullptr) return node;
        else return findMax(node->right);
    }

    /**
     * @brief Remove um valor da arvore
     * 
     * @param node raiz da subarvore
     * @param value valor a ser removido
     * @return true caso o valor tenha sido removido
     * @return false caso o valor nao tenha sido removido
     * ATENCAO: Nao funciona para o no raiz -> Nao usar
     * TODO: Arrumar para funcionar com o no raiz
     */
    bool remove(Node<T> *node, T value)
    {
        if(node == nullptr) return false;
        Node<T> *aux = find(node, value); // Procura o no com o valor

        if (aux == nullptr) return false;
        if (aux->left == nullptr && aux->right == nullptr) // No folha
        {
            if (aux->parent->left == aux) aux->parent->left = nullptr;
            else aux->parent->right = nullptr;
            delete aux;
        }
        else if (aux->left == nullptr) // No com um filho a direita
        {
            if (aux->parent->left == aux) aux->parent->left = aux->right;
            else aux->parent->right = aux->right;
            delete aux;
        }
        else if (aux->right == nullptr) // No com um filho a esquerda
        {
            if (aux->parent->left == aux) aux->parent->left = aux->left;
            else aux->parent->right = aux->left;
            delete aux;
        }
        else // No com dois filhos
        {
            Node<T> *min = findMin(aux->right);
            aux->value = min->value;
            if (min->parent->left == min) min->parent->left = nullptr;
            else min->parent->right = nullptr;
            delete min;
        }
        this->size--;
        return true;
    }
    

public:
    
    Set()
    {
        root = nullptr;
        size = 0;
    }

    ~Set()
    {
        clear(root);
    }

    /**
     * @brief Retorna o tamanho do conjunto
     * 
     * @return size_t Tamanho do conjunto
     */
    size_t getSize()
    {
        return this->size;
    }

    /**
     * @brief Insere um valor na arvore binaria de busca
     * 
     * @param value Valor que deve ser inserido
     */
    void insert(T value)
    {
        insert(value, root);
    }

    /**
     * @brief Percorre a arvore em ordem
     * 
     * @param callback Funcao que sera chamada para cada no
     */
    void walk(void (*callback)(T))
    {
        walk(root, callback);
    }

    /**
     * @brief Procura um valor na arvore
     * 
     * @param value Valor a ser procurado
     * @return Node<T>* Ponteiro para o no que contem o valor, nullptr caso nao exista
     */
    Node<T>* find(T value)
    {
        return find(root, value);
    }

    /**
     * @brief Procura o no com o menor valor da arvore
     * 
     * @return Node<T>* Ponteiro para o no com o menor valor
     */
    Node<T> *findMin()
    {
        return findMin(root);
    }

    /**
     * @brief Procura o no com o maior valor da arvore
     * 
     * @return Node<T>* Ponteiro para o no com o maior valor
     */
    Node<T> *findMax()
    {
        return findMax(root);
    }

    /**
     * @brief Remove um valor da arvore
     * 
     * @param value valor a ser removido
     * @return true caso o valor tenha sido removido
     * @return false caso o valor nao tenha sido removido
     */
    bool remove(T value)
    {
        return remove(root, value);
    }

    /**
     * @brief Clear the set
     * 
     */
    void clear()
    {
        clear(root);
        root = nullptr;
        size = 0;
    }

    Iterator begin(){
        return Iterator(this->root);
    }

    Iterator end(){
        return Iterator(nullptr);
    }

};

#endif

