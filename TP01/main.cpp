#include <iostream>

#include "binary_tree.hpp"
#include "utils.hpp"

#define endl '\n'

using std::cout, std::string;

int main(){

    char expression[100] = "0 | 2 | 2 & 1 \0";
    std::string postfix = infixToPostfix(expression);
    std::cout << "POSTFIX EXPRESSION -> " << postfix << endl;

    TreeNode<char>* root = postfixToAST(postfix);
    BinaryTree<char>::printTreeInorder(root);
    
    int arr[100] = {1, 0, 0};
    
    std::cout << "\nVAL -> "<< evaluateExpression(postfix, arr) << endl;
    std::cout << "\nVAL2-> "<< evaluateExpression(root, arr) << endl;



    
    return 0;
}