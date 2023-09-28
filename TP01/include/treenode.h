#ifndef TREENODE_H
#define TREENODE_H

// Define enum for different node types
enum NodeType {
    OPERATOR,
    VALUE
};

// Define a union to store either an operator or a value
union NodeData {
    char operator;
    int value;
};

// Define a struct for the binary tree node
struct TreeNode{
    enum NodeType type;
    union NodeData data;
    struct TreeNode* left;
    struct TreeNode* right;
};


#endif