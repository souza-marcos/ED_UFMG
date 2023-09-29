#include "utils.hpp"
#include "binary_tree.hpp"
#include "stack.hpp"

#include <string>

const size_t MAX_SIZE_STACK  = 100;

// Function to get the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '|':
            return 1;
        case '&':
            return 2;
        case '~':
            return 3;
        default:
            return 0; // Default precedence for other characters
    }
}

std::string infixToPostfix(const char* infix) {
    Stack<char> stack = Stack<char>(MAX_SIZE_STACK);

    char postfix[100]; 
    
    int postfixIndex = 0;
    
    for (int cont = 0; infix[cont] != '\0'; cont++) {
        if (infix[cont] == ' ') {
            continue;
        }
        char c = infix[cont];

        switch (c) {
            case '|':
            case '&':
            case '~':
                while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.top())) {
                    postfix[postfixIndex++] = stack.top();
                    stack.pop();
                }
                stack.push(c);
                break;

            case '(':
                stack.push(c);
                break;

            case ')':
                while (stack.top() != '(') {
                    postfix[postfixIndex++] = stack.top();
                    stack.pop();
                }
                if (stack.top() == '(') stack.pop();
                break;

            default:
                postfix[postfixIndex++] = c;
                break;
        }
    }
    
    while (!stack.isEmpty()) {
        postfix[postfixIndex++] = stack.top();
        stack.pop();
    }
    
    // Null-terminate the result
    postfix[postfixIndex] = '\0';
    
    return std::string(postfix);
}

TreeNode<char>* postfixToAST(const std::string& postfix) {
    Stack<TreeNode<char>*> stack = Stack<TreeNode<char>*>(MAX_SIZE_STACK);
    TreeNode<char>* node;

    for (int cont = 0; postfix[cont] != '\0'; cont++) {
        char c = postfix[cont];
        node = new TreeNode<char>(c);
        if (c == '~'){
            node->left = stack.top();
            stack.pop();
        }
        else if (c == '|' || c == '&') {
            node = new TreeNode<char>(c);
            node->right = stack.top();
            stack.pop();
            node->left = stack.top();
            stack.pop();
        }
        stack.push(node);
    }
    return stack.top();
}

// Evaluate from AST
bool evaluateExpression(TreeNode<char>* root, int arr[100]){
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr){
        return arr[root->value - '0'];
    }
    else if(root->value == '~'){
        return !evaluateExpression(root->left, arr);
    }
    else if(root->value == '|'){
        return evaluateExpression(root->left, arr) || evaluateExpression(root->right, arr);
    }
    else if(root->value == '&'){
        return evaluateExpression(root->left, arr) && evaluateExpression(root->right, arr);
    }
    return false;
}

// Evaluate from postfix expression 
bool evaluateExpression(std::string exp, int arr[100]){

    size_t i = 0;

    struct Element{
        bool isresolved = false;
        int el;
        Element(bool val, int el): isresolved(val), el(el){}
        Element(){}
    };

    Stack<Element> stack(MAX_SIZE_STACK);
    while(i < exp.size()){
        Element aux;
        if(exp[i] == '~'){
            aux = stack.top(); 
            int val = (aux.isresolved ? aux.el : arr[aux.el]); 
            stack.pop();
            stack.push(Element{true, !val});
        }
        else if(exp[i] == '|' || exp[i] == '&'){
            // Is operator
            aux = stack.top();
            int val1 = (aux.isresolved ? aux.el : arr[aux.el]); 
            stack.pop();

            aux = stack.top();
            int val2 = (aux.isresolved ? aux.el : arr[aux.el]); 
            stack.pop();
            
            int res = (exp[i] == '|'? (val1 || val2): (val1 && val2));

            stack.push(Element{true, res});
        }
        else {
            stack.push(Element{false, exp[i] - '0'});
        }
        i++;
    }
    Element aux = stack.top(); 
    stack.pop();
    return (aux.isresolved?aux.el:arr[aux.el]);
}


