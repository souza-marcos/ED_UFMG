#include "stack.h"
#include <stdio.h>

#define MAX_STACK 100

Stack* init_stack(){
    Stack* s = malloc(sizeof(Stack));
    s->size = 0;
    return s;
}

Node* top(Stack* s){
    return s->arr[s->size -1];
}

void pop(Stack* s){
    s->arr[-- s->size] = 0; // Assign NULL don't work
}

int push(Stack* s, Node* n){
    if(s->size >= MAX_STACK) return 0;
    s->arr[s->size ++] = n;
    return 1;
}

int empty(Stack* s){
    return (s->size == 0);
}

void clear(Stack* s){
    s->size = 0;
}

void print_stack(Stack* stack){
    for(int i = 0; i < stack->size; i++){
        printf("%c\n", stack->arr[i]->value);
    }
}
