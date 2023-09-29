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

#endif // STACK_HPP
