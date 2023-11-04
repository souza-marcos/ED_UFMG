#ifndef SET_HPP
#define SET_HPP

#include <cstddef> // size_t
#include <iostream>

/**
 * @brief Struct que representa um no da arvore binaria de busca
 * 
 * @tparam T Tipo do valor armazenado no no
 */
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
};

/**
 * @brief Classe que representa um conjunto (set) implementado com arvore binaria de busca
 * 
 * @tparam T Tipo do valor armazenado no conjunto
 */
template <typename T>
class Set
{
public:
    friend class Node<T>;

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

    /**
     * @brief Percorre a arvore em ordem
     * 
     * @param node No da raiz da arvore
     * @param callback Funcao que sera chamada para cada no
     */
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

    /**
     * @brief Construtor padrão da classe Set
     * 
     */    
    Set()
    {
        root = nullptr;
        size = 0;
    }

    /**
     * @brief Destrutor da classe Set
     * 
     */
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
     * @brief Limpa todo o conjunto
     * 
     */
    void clear()
    {
        clear(root);
        root = nullptr;
        size = 0;
    }
};

#endif

