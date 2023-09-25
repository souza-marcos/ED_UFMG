#ifndef NODE_H
#define NODE_H
#include <stdlib.h>

typedef struct Node{
    char value;
    //struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

#endif
