#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include "treenode.h"

// Function to initialize a binary tree node
struct TreeNode* initTreeNode();

// Functions to insert child nodes
void insertRight(struct TreeNode* parent, struct TreeNode* child);
void insertLeft(struct TreeNode* parent, struct TreeNode* child);

// Functions to print tree nodes
void printTreeNode(struct TreeNode* node);

void printTreePreorder(struct TreeNode* node);
void printTreeInorder(struct TreeNode* node);
void printTreePosorder(struct TreeNode* node);

// Functions for expression parsing and evaluation
void toASTCopy(char* exp);
struct TreeNode* toASTNew(char* exp);

char* infixToPostfix(const char* infix);
int evaluateExpression(struct TreeNode* root);
bool evaluate_expression(char* exp, int arr[100]);


#endif
