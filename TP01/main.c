#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"

int main(){

    char expression[100] = "~1 | ~2 & (~2 | 1) \0";
    char* postfix = infixToPostfix(expression);
    printf("POSTFIX EXPRESSION -> %s\n", postfix);
    //int arr[100] = {0, 1, 1};
    // printf("VAL -> %d\n", evaluateExpression(postfix, arr));
    // to_ast_copy(expression); 

    // print_tree_preorder(root);
    // printf("\n");
    // print_tree_inorder(root);
    // printf("\n");
    // print_tree_posorder(root);
    // int s[100], s_size = 0;
    // printf("%s", expression);

    // while(scanf("%c", &temp)) s[s_size++] = (int) temp;


    return 0;
}