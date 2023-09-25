#ifndef TREE_H
#define TREE_H

#include "node.h"

Node* init_node();
void insert_right(Node* parent, Node* child);
void insert_left(Node* parent, Node* child);

void print_tree_node(Node* node);

void print_tree_preorder(Node* node);
void print_tree_inorder(Node* node);
void print_tree_posorder(Node* node);

Node* to_ast(char* exp);
Node* to_ast_new(char* exp);

#endif