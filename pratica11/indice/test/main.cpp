#include <iostream>

using std::cout, std::endl;

class InNode {
public:
    int key;
    int height;
    InNode* left;
    InNode* right;

    InNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class InTree {
private:
    InNode* root;

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int height(InNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(InNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    InNode* leftRotate(InNode* curHead) {
        InNode* newHead = curHead->right;
        InNode* subTree = newHead->left;

        curHead->right = subTree;
        newHead->left = curHead;

        curHead->height = 1 + max(height(curHead->left), height(curHead->right));
        newHead->height = 1 + max(height(newHead->left), height(newHead->right));

        return newHead;
    }

    InNode* rightRotate(InNode* curHead) {
        InNode* newHead = curHead->left;
        InNode* subTree = newHead->right;

        curHead->left = subTree;
        newHead->right = curHead;

        curHead->height = 1 + max(height(curHead->left), height(curHead->right));
        newHead->height = 1 + max(height(newHead->left), height(newHead->right));

        return newHead;
    }

    InNode* searchNode(InNode* node, int key) {
        if (node == nullptr) return nullptr;

        if (key == node->key) return node;

        if (key < node->key) return searchNode(node->left, key);
        else return searchNode(node->right, key);
    }

    InNode* insert(InNode* node, int key) {
        if (node == nullptr) return new InNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // No duplicates allowed

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void printInOrder(InNode* node) {
        if (node == nullptr) return;
        printInOrder(node->left);
        cout << node->key << " ";
        printInOrder(node->right);
    }

    void destruct(InNode* node) {
        if (node == nullptr) return;
        destruct(node->left);
        destruct(node->right);
        delete node;
    }

public:
    InTree() : root(nullptr) {}

    ~InTree() {
        destruct(root);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void printInOrder() {
        printInOrder(root);
        cout << endl;
    }
};

int main() {
    InTree avlTree;
    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(10);
    avlTree.insert(15);

    cout << "Inorder traversal of the AVL tree: ";
    avlTree.printInOrder();

    return 0;
}
