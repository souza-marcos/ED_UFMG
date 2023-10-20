#include "utils.h"
#include "binary_tree.h"
#include "stack.h"
#include "vector.h"

#include <cstring>
#include <string>
#include <sstream>

#include <cassert>

#define ANDOP -1
#define OROP -2
#define NOTOP -3
#define LPAR -4
#define RPAR -5

const int MAX_SIZE_QUANTIFIERS = 30;
const size_t MAX_SIZE_STACK    = 1e6;
const size_t MAX_SIZE_EXP      = 1e6;

int getPrecedence(int op) {
    switch (op) {
        case OROP:
            return 1;
        case ANDOP:
            return 2;
        case NOTOP:
            return 3;
        default:
            return 0;
    }
}

int operatorToInt(std::string op) {
    switch (op[0]) {
        case '|':
            return OROP;
        case '&':
            return ANDOP;
        case '~':
            return NOTOP;
        case '(':
            return LPAR;
        case ')':
            return RPAR;
        default:
            return std::stoi(op);
    }
}

Vector<int> infixToPostfix(const char* infix) {
    std::stringstream ss(infix);
    Vector<int> postfix(MAX_SIZE_EXP);

    // Pilha para armazenar os operadores e parenteses
    Stack<int> stack = Stack<int>(MAX_SIZE_STACK);

    std::string word;
    
    // Percorrendo a expressão infixa
    while(ss >> word) {
        int op = operatorToInt(word);

        if(op == OROP || op == ANDOP || op == NOTOP){
            // Se for um operador, verifica se eh necessario resgatar valores da pilha
            while (!stack.isEmpty() && getPrecedence(op) < getPrecedence(stack.top())) {
                postfix.push_back(stack.top());
                stack.pop();
            }

            stack.push(op);
        }
        else if(op == LPAR){
            stack.push(op);
        }
        else if(op == RPAR){
            // Resgata a expressão entre parenteses
            while (stack.top() != LPAR) {
                postfix.push_back(stack.top());
                stack.pop();
            }
            if (stack.top() == LPAR) stack.pop();
        }
        else{
            // Se for uma variavel, ja a adiciona na pilha
            postfix.push_back(op);
        }

    }
    
    // Resgata o restante dos operadores
    while (!stack.isEmpty()) {
        postfix.push_back(stack.top());
        stack.pop();
    }
    
    return postfix;
}

bool evaluateExpression(Vector<int> exp, int arr[100]){
    size_t i = 0;

    // Struct para armazenar os dados de cada elemento da pilha
    struct Element{
        bool isresolved = false;
        int el;
        Element(bool val, int el): isresolved(val), el(el){}
        Element(){}
    };

    Stack<Element> stack(MAX_SIZE_STACK);
    while(i < exp.getSize()){
        Element aux;

        if(exp[i] == NOTOP){ // Resolve o topo da pilha -> Inverte ele
            aux = stack.top(); 
            int val = (aux.isresolved ? aux.el : arr[aux.el]); 
            stack.pop();
            stack.push(Element{true, !val});
        }
        else if(exp[i] == OROP || exp[i] == ANDOP){ // Resolve os dois nós do top da pilha -> empilha o resultado 

            aux = stack.top();
            int val1 = (aux.isresolved ? aux.el : arr[aux.el]); 
            stack.pop();

            aux = stack.top();
            int val2 = (aux.isresolved ? aux.el : arr[aux.el]); 
            stack.pop();
            
            int res = (exp[i] == OROP? (val1 || val2): (val1 && val2));

            stack.push(Element{true, res});
        }
        else {
            stack.push(Element{false, exp[i]});
        }

        // LOG
        // if(exp[i] == "~" || exp[i] == "&" || exp[i] == "|"){
        //     std::cout << stack.top().el << " "; 
        // }

        i++;
    }
    Element aux = stack.top(); 
    stack.pop();
    return (aux.isresolved?aux.el:arr[aux.el]);
}

bool evaluateExpression(Vector<int> exp, std::string vals){

    // Transformar a string de valores em um array de inteiros
    int arr[100];
    for(size_t i = 0; i < vals.size(); i++) arr[i] = vals[i] - '0';
    return evaluateExpression(exp, arr);
}

std::string sat_tree(Vector<int> postfix_exp, std::string vals){

    // Lista dos indices dos quantificadores
    int idx_quantifier[MAX_SIZE_QUANTIFIERS]; 
    memset(idx_quantifier, -1, sizeof(idx_quantifier)); // -1 significa que não há mais quantificadores
    
    int qtd_quantifier = 0; 
    for(size_t idx = 0; idx < vals.size(); idx++) 
        if(vals[idx] == 'e' || vals[idx] == 'a') 
            idx_quantifier[qtd_quantifier ++] = idx; 
    
    // Tipos para verficarmos qual operação deve ser feita após obter os valores dos nós filhos
    enum types {    
        AND, OR, NONE
    };

    // Struct para armazenar os dados de cada nó
    struct Element{
        int idx; // indice do quantificador, entre os demais quantificadores (ex: 0 -> primeiro quantificador)
        enum types type;
        std::string data;
        bool res;
        Element(std::string data, int idx): idx(idx), res(false){
            this->data = data;
        }
    };

    TreeNode<Element> *root = new TreeNode<Element>(Element{vals, qtd_quantifier});
    TreeNode<Element> *cur = root;

    Stack<TreeNode<Element>*> stack(MAX_SIZE_STACK);

    stack.push(root);
    while(!stack.isEmpty()){
        cur = stack.top(); stack.pop();
        int i = cur->value.idx - 1; // Indice de controle sobre a posicao dos quantificadores
        
        // Se o nó atual é uma folha, podemos resolvê-lo 
        if(i == -1){ // || idx_quantifier[i] == -1
            cur->value.res = evaluateExpression(postfix_exp, cur->value.data);

            // LOG
            // std::cout << "FOLHA " << cur->value.data << ", RES: " << cur->value.res << "\n";
            continue;
        }

        // Caso não seja uma folha, e já possua filhos resolvidos, podemos resolver o nó atual
        if(cur->left != nullptr && cur->right != nullptr){ // Talvez ocorra algum erro aqui !!!
            
            // LOG
            // std::cout << "NO INTERNO " << (cur->value.type == AND?"AND ":"OR ") << cur->value.data << "\n";

            bool left = cur->left->value.res, right = cur->right->value.res;
            cur->value.res = (cur->value.type == AND ? (left && right) : (left || right));

            // Compondo a string de satisfatibilidade
            if(left && right) { // Tanto faz o valor da variavel
                std::string val_left = cur->left->value.data, val_right = cur->right->value.data; 

                cur->value.data = val_left;

                // Faz a verificação até o quantificador anterior
                for(int i = 0; i < cur->value.idx && idx_quantifier[i] != -1; i++){
                    int idx = idx_quantifier[i];
                    if(val_left[idx] != val_right[idx]){
                        // *** 1 *** , *** a *** -> *** 1 ***
                        // *** 0 *** , *** a *** -> *** 0 ***
                        // *** 1 *** , *** 0 *** -> *** a ***
                        // *** 0 *** , *** 1 *** -> *** a ***

                        cur->value.data[idx] = (val_left[idx] == 'a'? val_right[idx]: val_left[idx]);

                    }
                }
                
                cur->value.data[idx_quantifier[cur->left->value.idx]] = 'a';
            }
            else if (left){ // left é o nó que possui o valor falso
                cur->value.data = cur->left->value.data;
                cur->value.data[idx_quantifier[cur->left->value.idx]] = '0';
            }else if(right){ // right é o nó que possui o valor verdadeiro
                cur->value.data = cur->right->value.data;
                cur->value.data[idx_quantifier[cur->right->value.idx]] = '1';
            }

            // Deletando os filhos 
            delete cur->left; delete cur->right;
            cur->left = nullptr; cur->right = nullptr;
            continue;
        }

        // Caso não seja uma folha, e não possua filhos resolvidos, devemos criar os filhos

        char val = vals[idx_quantifier[i]]; 
        cur->value.type = (val == 'a' ? AND : OR); // Tipo de operação que deverá ser realizada após obter os valores dos filhos

        std::string copy = cur->value.data; copy[idx_quantifier[i]] = '0';
        TreeNode<Element> *left_node = new TreeNode<Element>(Element{copy, i}); 
        
        copy[idx_quantifier[i]] = '1';
        TreeNode<Element> *right_node = new TreeNode<Element>(Element{copy, i});
        
        BinaryTree<Element>::insertLeft(cur, left_node);
        BinaryTree<Element>::insertRight(cur, right_node);

        stack.push(cur); stack.push(right_node); stack.push(left_node); // Empilhando os nós
    }
    
    // std::cout << "ROOT: " << (root->value.type == AND ? "AND": root->value.type == OR? "OR": "NONE") << " " << root->value.res << "\n";
    Element aux = cur->value;
    delete cur;
    if(!(aux.res)) return "";
    return aux.data;
}
