#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"

int solve(int *arr, int size){
    return -1;
}

int main(){

    char expression[100] = "(1 & ~ 2 | 1 & 0) \0";

    Node* root = to_ast(expression); 

    print_tree_preorder(root);
    printf("\n");
    print_tree_inorder(root);
    printf("\n");
    print_tree_posorder(root);
    // int s[100], s_size = 0;
    // printf("%s", expression);

    // while(scanf("%c", &temp)) s[s_size++] = (int) temp;


    return 0;
}