#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <typename T>
class Stack {
private:
    T* elements;
    size_t max_size;
    size_t top_index;

public:
    Stack(size_t max_size);
    ~Stack();

    bool push(const T& value);
    bool pop();
    T top() const;
    bool isEmpty() const;
    size_t size() const;

};

template <typename T>
Stack<T>::Stack(size_t max_size) : max_size(max_size), top_index(0) {
    elements = new T[max_size];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] elements;
}

template <typename T>
bool Stack<T>::push(const T& value) {
    if (top_index < max_size) {
        elements[top_index++] = value;
        return true;
    }
    return false; // Stack overflow
}

template <typename T>
bool Stack<T>::pop() {
    if (top_index > 0) {
        --top_index;
        return true;
    }
    return false; // Stack underflow
}

template <typename T>
T Stack<T>::top() const {
    if (top_index > 0) {
        return elements[top_index - 1];
    }
    throw std::underflow_error("Stack is empty"); // Stack is empty
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top_index == 0;
}

template <typename T>
size_t Stack<T>::size() const {
    return top_index;
}

#endif // STACK_HPP
