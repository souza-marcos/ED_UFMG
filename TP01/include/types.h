#ifndef TYPES_H
#define TYPES_H

#include "treenode.h"

// Define an enum for different data types
enum DataType {
    INT,
    DOUBLE,
    CHAR,
    TREENODE
};

// Define a union to store values of different data types
union GenericData {
    int intData;
    double doubleData;
    char charData;
    struct TreeNode* treeNodeData;
};

// Define a struct for the element
struct Element {
    enum DataType type;
    union GenericData data;
};

#endif