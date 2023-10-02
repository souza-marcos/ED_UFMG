#include <iostream>

#include "binary_tree.hpp"
#include "utils.hpp"

#define endl '\n'

using std::cout, std::string;

void printNodeData(char data){
    cout << data << " ";
}

int main(){

    char expression[100] = "0 | 1 & 2\0";
    std::string postfix = infixToPostfix(expression);
    std::cout << "POSTFIX EXPRESSION -> " << postfix << endl;

    TreeNode<char>* root = postfixToAST(postfix);

    BinaryTree<char>::printTreePreorder(root, printNodeData);
    cout << endl;
    BinaryTree<char>::printTreeInorder(root, printNodeData);
    cout << endl;
    BinaryTree<char>::printTreePosorder(root, printNodeData);
    cout << endl;

    std::string vals = "e0e";
    std::string res = sat_tree(root, vals);

    cout << "SAT: " << (res == ""? "IMPOSSIBLE": res) << endl;
    
    delete root;

    return 0;
}

