#include <iostream>

#include "binary_tree.h"
#include "utils.h"

#define endl '\n'

using std::cout, std::string;

void printNodeData(char data){
    cout << data << " ";
}

int main(int argc, char *argv[]){

    if(argc != 4){
        // cout << "Usage: " << argv[0] << " <type> <expression> <values> " << endl;
        return 1;
    }
    
    char* infix = argv[2];

    // Removendo as aspas
    for(int i = 0; infix[i] != '\0'; i++)
        if(infix[i] == '\"') infix[i] = ' ';

    std::string postfix = infixToPostfix(infix);
    string vals = argv[3];

    if(string(argv[1]) == "-s"){
        string res = sat_tree(postfix, vals);
        cout << (res == ""? "0": "1 " + res) << endl;
        return 0;
    }
    else if(string(argv[1]) == "-a"){
        bool res = evaluateExpression(postfix, vals);
        cout << res << endl;
    } 
    else{
        // cout << "Invalid type, '-s' for "  << endl;
        return 1;
    }
    return 0;
}

