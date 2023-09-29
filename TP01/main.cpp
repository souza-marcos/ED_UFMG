#include <iostream>

#include "binary_tree.hpp"
#include "utils.hpp"

#define endl '\n'
int main(){

    char expression[100] = "0 | 2 | 2 & 1 \0";
    std::string postfix = infixToPostfix(expression);
    std::cout << "POSTFIX EXPRESSION -> " << postfix << endl;

    TreeNode<char>* root = postfixToAST(postfix);
    BinaryTree<char>::printTreePreorder(root);
    

    // int arr[100] = {0, 1, 1};
    // std::cout << "VAL -> "<< evaluateExpression(postfix.c_str(), arr) << endl;
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