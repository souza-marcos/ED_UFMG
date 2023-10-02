#include "utils.hpp"
#include "binary_tree.hpp"
#include "stack.hpp"

#include <cstring>
#include <string>

const size_t MAX_SIZE_STACK  = 100;

int getPrecedence(char op) {
    switch (op) {
        case '|':
            return 1;
        case '&':
            return 2;
        case '~':
            return 3;
        default:
            return 0;
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
            node->right = stack.top();
            stack.pop();
            node->left = stack.top();
            stack.pop();
        }
        stack.push(node);
    }
    return stack.top();
}

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

bool evaluateExpression(TreeNode<char>* root, std::string vals){
    // Transformar a string de valores em um array de inteiros
    int arr[100];
    for(size_t i = 0; i < vals.size(); i++) arr[i] = vals[i] - '0';
    return evaluateExpression(root, arr);
}

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

bool evaluateExpression(std::string exp, std::string vals){

    // Transformar a string de valores em um array de inteiros
    int arr[100];
    for(size_t i = 0; i < vals.size(); i++) arr[i] = vals[i] - '0';
    return evaluateExpression(exp, arr);
}

std::string sat_tree(TreeNode<char> *ast_exp, std::string vals){

    // Lista dos indices dos quantificadores
    int idx_quantifier[5]; 
    memset(idx_quantifier, -1, sizeof(idx_quantifier)); // -1 significa que não há mais quantificadores
    
    for(size_t i = 0, idx = 0; idx < vals.size(); idx++) 
        if(vals[idx] == 'e' || vals[idx] == 'a') 
            idx_quantifier[i ++] = idx;

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
        Element(std::string data, int idx): idx(idx){
            this->data = data;
            res = 0;
        }
    };

    TreeNode<Element> *root = new TreeNode<Element>(Element{vals, -1});
    TreeNode<Element> *cur = root;

    Stack<TreeNode<Element>*> stack(MAX_SIZE_STACK);

    stack.push(root);
    while(!stack.isEmpty()){
        cur = stack.top(); stack.pop();
        int i = cur->value.idx + 1; // Indice de controle sobre a posicao dos quantificadores

        // Se o nó atual é uma folha, podemos resolvê-lo 
        if(i >= 5 || idx_quantifier[i] == -1){
            cur->value.res = evaluateExpression(ast_exp, cur->value.data);

            // LOG
            std::cout << "FOLHA " << cur->value.data << ", RES: " << cur->value.res << "\n";
            continue;
        }

        // Caso não seja uma folha, e já possua filhos resolvidos, podemos resolver o nó atual
        if(cur->left != nullptr && cur->right != nullptr){ // Talvez ocorra algum erro aqui !!!
            
            // LOG
            std::cout << "NO INTERNO " << (cur->value.type == AND?"AND ":"OR ") << cur->value.data << "\n";

            bool left = cur->left->value.res, right = cur->right->value.res;
            cur->value.res = (cur->value.type == AND ? (left && right) : (left || right));

            // Compondo a string de satisfatibilidade
            // if(left && right) {
            //     cur->value.data = cur->left->value.data;
            //     cur->value.data[idx_quantifier[cur->value.idx]] = 'a';
            // }
            // else if (left){ // left é o nó que possui o valor falso
            //     cur->value.data = cur->left->value.data;
            //     cur->value.data[idx_quantifier[cur->value.idx]] = '0';
            // }else if(right){ // right é o nó que possui o valor verdadeiro
            //     cur->value.data = cur->right->value.data;
            //     cur->value.data[idx_quantifier[cur->value.idx]] = '1';
            // }

            // Deletando os filhos 
            delete cur->left; delete cur->right;
            cur->left = nullptr; cur->right = nullptr;
            continue;
        }

        // Caso não seja uma folha, e não possua filhos resolvidos, devemos criar os filhos

        char val = vals[idx_quantifier[i]]; 
        cur->value.type = (val == 'a' ? AND : OR); // Tipo de operação que deverá ser realizada após obter os valores dos filhos

        std::string copy = cur->value.data; copy[i] = '0';
        TreeNode<Element> *left_node = new TreeNode<Element>(Element{copy, i}); 
        
        copy[i] = '1';
        TreeNode<Element> *right_node = new TreeNode<Element>(Element{copy, i});
        
        BinaryTree<Element>::insertLeft(cur, left_node);
        BinaryTree<Element>::insertRight(cur, right_node);

        stack.push(cur); stack.push(right_node); stack.push(left_node); // Empilhando os nós
    }
    
    std::cout << "ROOT: " << (root->value.type == AND ? "AND": root->value.type == OR? "OR": "NONE") << " " << root->value.res << "\n";
    Element aux = cur->value;
    delete cur;
    if(!(aux.res)) return "";
    return aux.data;
}
