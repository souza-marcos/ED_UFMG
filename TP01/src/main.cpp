#include <iostream>

#include "binary_tree.h"
#include "utils.h"

#include "memlog.h"

#define endl '\n'

using std::cout, std::string;
char logname[100] = "registro_acesso_a.txt";

int main(int argc, char *argv[]){

    if(argc != 4){
        // cout << "Usage: " << argv[0] << " <type> <expression> <values> " << endl;
        return 1;
    }
    
    char* infix = argv[2];

    // Removendo as aspas
    for(int i = 0; infix[i] != '\0'; i++)
        if(infix[i] == '\"') infix[i] = ' ';

    iniciaMemLog(logname); 
    ativaMemLog();

    defineFaseMemLog(0); // Transformar infixo -> posfixo

    std::string postfix = infixToPostfix(infix);

    // cout << postfix << endl;

    string vals = argv[3];

    defineFaseMemLog(1); // Evaluate ou sat_tree

    if(string(argv[1]) == "-s"){
        string res = sat_tree(postfix, vals);
        cout << (res == ""? "0": "1 " + res) << endl;
    }
    else if(string(argv[1]) == "-a"){
        bool res = evaluateExpression(postfix, vals);
        cout << res << endl;
    } 
    else{
        // cout << "Invalid type, '-s' for "  << endl;
        return 1;
    }

    finalizaMemLog();

    return 0;
}

