#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <typename T>
struct Node
{
    T data;
    Node<T> *next = NULL;
};

template <typename T>
class LinkedList{   
    Node<T> *head;
    Node<T> *last;

    LinkedList();

    void insert(T e);
    bool isEmpty();
    Node<T> *searchItem(T val, bool (*compare)(T, T));
    void operator<<(ostream out);
    bool deleteItem(Node<T> *&node)
      
};

#endif