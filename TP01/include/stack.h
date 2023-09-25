#ifndef STACK_H
#define STACK_H

#include "node.h"

#define MAX_STACK 100

typedef struct Stack{
    int size;
    Node *arr[MAX_STACK];
} Stack;

Stack* init_stack();
Node* top(Stack* s);
void pop(Stack* s);
int push(Stack* s, Node* n);

int empty(Stack* s);
void clear(Stack* s);

void print_stack(Stack* stack);

#endif