#include "utils.hpp"
#include "binary_tree.hpp"
#include "stack.hpp"

#include <string>

const size_t MAX_SIZE_STACK  = 100;

template class TreeNode<char>;

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

// Not yet implemented 
template <typename T>
int evaluateExpression(TreeNode<T>* root, int arr[100]) {
    // Implementation here
    return 0; // Placeholder
}

// Evaluate from postfix expression // FIX HERE
bool evaluateExpression(std::string exp, int arr[100]){

    int i = 0;
    Stack<char> stack(MAX_SIZE_STACK);
    while(exp[i] != '\0'){
        if(exp[i] == '~'){
            int val = arr[stack.top() - '1']; 
            stack.pop();
            stack.push(!val);
        }
        else if(exp[i] == '|' || exp[i] == '&'){
            // Is operator
            int val1 = arr[stack.top() - '1']; 
            stack.pop();
            int val2 = arr[stack.top() - '1']; 
            stack.pop();
            stack.push(exp[i] == '|'? (val1 || val2): (val1 && val2));
        }
    }
    int val = arr[stack.top() - '1']; 
    stack.pop();
    return val;
}
