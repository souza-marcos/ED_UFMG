#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "types.h"

// Define the stack structure
typedef struct Stack{
    struct Element *elements;
    int capacity;
    int top;
} Stack;

// Function to initialize the stack
void initStack(struct Stack *stack, int capacity);

// Function to push an element onto the stack
bool push(struct Stack *stack, enum DataType type, union GenericData data);

// Function to pop an element from the stack
bool pop(struct Stack *stack, enum DataType *type, union GenericData *data);

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack);

// Function to get the top element of the stack
bool top(struct Stack *stack, enum DataType *type, union GenericData *data);



#endif