#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept> // std::underflow_error

const int MAXSIZE_STACK = 100;

/**
 * @brief Classe que representa uma pilha na forma de um vetor de tamanho fixo
 * 
 * @tparam T Tipo de dado a ser armazenado na pilha
 */
template <typename T>
class Stack {
private:
    T* elements;
    size_t max_size;
    size_t top_index;

public:

    /**
     * @brief Constroi um novo objeto Stack
     * 
     */
    Stack(): max_size(MAXSIZE_STACK), top_index(0) {
        elements = new T[max_size];
    }

    /**
     * @brief Constroi um novo objeto Stack
     * 
     * @param max_size Tamanho máximo da pilha
     */
    Stack(size_t max_size) : max_size(max_size), top_index(0) {
        elements = new T[max_size];
    }

    /**
     * @brief Destrói o objeto Stack
     * 
     */
    ~Stack() {
        delete[] elements;
    }

    /**
     * @brief Insere um elemento no topo da pilha
     * @throw std::overflow_error Se a pilha estiver cheia
     * @param value Valor a ser inserido
     */
    void push(const T& value) {
        if (top_index < max_size) {
            elements[top_index++] = value;
            return ;
        }
        // Stack overflow
        throw std::overflow_error("Stack is full");
    }

    /**
     * @brief Remove o elemento do topo da pilha
     * @throw std::underflow_error Se a pilha estiver vazia
     */
    void pop() {
        if (top_index > 0) {
            --top_index;
            return;
        }
        // Stack underflow
        throw std::underflow_error("Stack is empty");
    }

    /**
     * @brief Retorna o elemento do topo da pilha
     * @throw std::underflow_error Se a pilha estiver vazia
     * @return T Elemento do topo da pilha
     */
    T top() const {
        if (top_index > 0) {
            return elements[top_index - 1];
        }
        throw std::underflow_error("Stack is empty"); // Stack is empty
    }

    /**
     * @brief Verifica se a pilha está vazia
     * 
     * @return true Se a pilha estiver vazia
     * @return false Se a pilha não estiver vazia
     */
    bool isEmpty() const {
        return top_index == 0;
    }

    /**
     * @brief Retorna o tamanho da pilha
     * 
     * @return size_t Tamanho da pilha
     */
    size_t size() const {
        return top_index;
    }
};


#endif // STACK_HPP
