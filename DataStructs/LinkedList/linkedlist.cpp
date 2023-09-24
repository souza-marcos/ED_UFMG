#include "linkedlist.hpp"
#include <ostream>

LinkedList::LinkedList(): head(nullptr), last(nullptr){}

template <typename T>
void LinkedList::insert(T e)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T>; 
        this->last = this->head;
        this->head->next = nullptr;
        this->last->data = e;
        return;
    }
    this->last->next = new Node<T>;
    this->last = this->last->next;
    this->last->next = nullptr;
    this->last->data = e;
}

bool LinkedList::isEmpty()
{
    return (this->head == nullptr);
}

template <typename T>
Node<T> LinkedList::*searchItem(T val, bool (*compare)(T, T))
{
    if (this->isEmpty())
    {
        return nullptr;
    }

    Node<T> *current = this->head;
    do
    {
        if (compare(current->data, val)) return current;
    
        current = current->next;
    } while (current != nullptr);
    return nullptr;
}
template <typename T>
void LinkedList::operator<<(std::ostream out)
{
    Node<T> *current = list->head;
    out << "[ \n";
    while (current != nullptr)
    {
        out << current->data;
        current = current->next;
    }
    out << "\n ]\n";
}

template <typename T>
bool LinkedList::deleteItem(Node<T> *&node)
{
    if (node == nullptr) return false;
    if (node == this->head)
    {
        this->head = node->next;
        if (node->next == nullptr) this->last = this->head;
    }
    else
    {
        Node<T> *prev = this->head;
        while (prev->next != node) prev = prev->next;
        
        prev->next = node->next;
        if (node->next == nullptr)
        {
            this->last = prev;
        }
    }
    delete node; 
    return true;
}
