#ifndef TREE_HPP
#define TREE_HPP

template <typename T>
class Node {
    public:
        T data;
        Node<T> *left;
        Node<T> *right;

        Node(T data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
        Node(T data, Node<T> *left, Node<T> *right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }

    friend class BinaryTree<T>;
};

template <typename T>
class BinaryTree {

    private:
        Node<T> *root;

    public:
        BinaryTree();
        ~BinaryTree();
        void insert(T data);
        

};

#endif