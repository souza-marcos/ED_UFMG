#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "types.h"
#include "stack.h"

void initStack(struct Stack *stack, int capacity) {
    stack->elements = malloc(sizeof(struct Element) * capacity);
    stack->capacity = capacity;
    stack->top = -1;
}

bool push(struct Stack *stack, enum DataType type, union GenericData data) {
    if (stack->top >= stack->capacity - 1) {
        return false; // Stack is full
    }

    stack->top++;
    stack->elements[stack->top].type = type;
    stack->elements[stack->top].data = data;

    return true;
}

bool pop(struct Stack *stack, enum DataType *type, union GenericData *data) {
    if (stack->top < 0) {
        return false; // Stack is empty
    }

    *type = stack->elements[stack->top].type;
    *data = stack->elements[stack->top].data;
    stack->top--;

    return true;
}

bool isEmpty(struct Stack *stack) {
    return stack->top < 0;
}

bool top(struct Stack *stack, enum DataType *type, union GenericData *data) {
    if (stack->top < 0) {
        return false; // Stack is empty
    }

    *type = stack->elements[stack->top].type;
    *data = stack->elements[stack->top].data;

    return true;
}
