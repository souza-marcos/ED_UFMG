#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


template <typename T>
class Node{
    public:
        Node(T data){
            this->data = data;
            next = nullptr;
        }
        T data;
        Node<T> *next;
};

template <typename T>
class LinkedList{
    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~LinkedList(){
            // Node<T> *aux = head;
            // while(aux != nullptr){
            //     Node<T> *next = aux->next;
            //     delete aux;
            //     aux = next;
            // }
        }

        void Insert(T data){
            Node<T> *new_node = new Node<T>(data);
            if(head == nullptr){ // Lista vazia
                head = new_node;
                tail = new_node;
            }else{
                tail->next = new_node;
                tail = new_node;
            }
            size++;
        }

        void Remove(T data){
            Node<T> *aux = head;
            Node<T> *prev = nullptr;
            while(aux != nullptr){
                if(aux->data == data){
                    if(prev == nullptr){ // Removendo o primeiro elemento
                        head = aux->next;
                    }else{
                        prev->next = aux->next;
                    }
                    delete aux;
                    size--;
                    return;
                }
                prev = aux;
                aux = aux->next;
            }
        }

        Node<T> *head;
        Node<T> *tail;
        int size;
};


#endif