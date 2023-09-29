#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "binary_tree.hpp"


// Function to get the precedence of an operator
int getPrecedence(char op);

std::string infixToPostfix(const char* infix);

TreeNode<char>* postfixToAST(const std::string& postfix);

bool evaluateExpression(TreeNode<char>* root, int arr[100]);

bool evaluateExpression(std::string exp, int arr[100]);


#endif // UTILS_HPP