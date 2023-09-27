#include "tree.h"
#include "stack.h"

#include <assert.h>
#include <stdio.h>

#define AND_OP 111
#define OR_OP 112
#define NEG_OP 113

Node* init_node(){
    Node* n = malloc(sizeof(Node));
    //n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->value = NULL;

    return n;
}

void insert_right(Node* parent, Node* child){
    assert(parent->right == NULL);
    parent->right = child;
}

void insert_left(Node* parent, Node* child){
    assert(parent->left == NULL);
    parent->left = child;
}

void print_tree_node(Node* node){
    switch (node->value)
    {
    case AND_OP:
        printf("& ");
        break;
    
    case OR_OP:
        printf("| ");
        break;

    case NEG_OP:
        printf("~ ");
        break;

    default:
        printf("%d ", (node->value - '0')); 
        break;
    }
}

void print_tree_preorder(Node* node){
    if(node == NULL) return;

    Stack *s = init_stack();
    Node* cur = node;
    while(s->size != 0 || cur != NULL){
        
        if(cur != NULL){
            print_tree_node(cur);

            if(cur->right != NULL) push(s, cur->right);

            cur = cur->left;
        }else{
            cur = top(s); 
            pop(s);
        }
    }
}

void print_tree_inorder(Node* node){
    if(node == NULL) return;

    Stack *s = init_stack();
    Node* cur = node;
    while(s->size != 0 || cur != NULL){
        
        if(cur != NULL){

            push(s, cur);
            cur = cur->left;
        }else{
            cur = top(s); pop(s);          
            print_tree_node(cur);
            cur = cur->right;
        }
    }
}


void print_tree_posorder(Node* node){
    if(node == NULL) return;
    Stack *stack = init_stack();
    Node* prev = NULL;
    
    while(node != NULL || stack->size > 0){
        if(node != NULL){
            push(stack, node);
            node = node->left;
            continue;
        }
        Node* cur = top(stack);
        if(cur->right != NULL && cur->right != prev){ 
            // Vai para o galho a direita se ele não foi visitado e existe
            node = cur->right;
        }
        else{
            // Vista o node atual
            print_tree_node(cur);
            prev = cur;
            pop(stack);
        }
    }
}
typedef struct _tokens{
    Node* arr[100];
    int size;
} Tokens;

Tokens tokenize(char* exp){
    Tokens t;
    int i = 0;
    while(exp[i] != '\0'){
        if(exp[i] == ' ') continue;

        Node* cur = init_node();
        cur->value = exp[i ++];

        t.arr[t.size ++] = cur;
    }

    return t;
}

int priority(char el){
    if(el == '|') return 1;
    if(el == '&') return 2;
    if(el == '~') return 3;
    return 0;
}

/**
 * @brief Reduce method for resolve the top of stack operation 
 * 
 * @param stack 
 * @param root 
 * @param arr 
 * @param idx 
 */
void reduce(Stack* stack, Node* root, Node* *arr, int idx){
    root = top(stack); pop(stack);
    if(root->value != '~'){
        insert_right(root, arr[idx]);
        insert_left(root, top(stack)); pop(stack);
    }
    else{
        insert_left(root, arr[idx]); // NOT nodes has only left node
    }
    push(stack, root);
}
/**
 * @brief Tokenize and Parsing for a tree
 * 
 * @param exp Expression
 * @return Node* root of the tree
 */
Node* to_ast_new(char* exp){
    Tokens t = tokenize(exp);

    Node **arr = &t.arr; 

    Node* root = NULL;
    Stack* stack = init_stack();
    for(int i = 0; i < t.size;){

        if(empty(stack)){ // Shift
            root = arr[i ++];
            push(stack, arr[i ++]);
            continue;
        } 

        if(arr[i]->value == '&' || arr[i]->value == '|' || arr[i]->value == '~'){ // Shift
            push(stack, arr[i ++]);
            continue;
        }

        Node* next = NULL;
        if (i + 1 < t.size) next = arr[i + 1]; // Fix here
        else{ // Reduce //  
            reduce(stack, root, arr, i ++);
            continue;
        }
        // top(stack) <==> previous operator
        if(priority(top(stack)->value) >= priority(next->value)){ // Reduce
            reduce(stack, root, arr, i ++);
            push(stack, root);
        }else{ // Shift
            push(stack, arr[i++]);
        }
    }


    // Here must reduce until it's impossible reduce more, i.e. priority.prev < priority.next
    assert(stack->size <= 1); // Remove this
    while(stack->size > 1){
        // TODO
    }

    return root;
}

int prioridade(char elemento)
{
    int prioridade;
    switch(elemento)
    {
        case '+':
        case '-':
            prioridade = 1;
            break;
            
        case '*':
        case '/':
            prioridade = 2;
            break;
            
        case '^':
            prioridade = 3;
            break;
            
        default:
                prioridade = 0;
                break;
    }
    
    return prioridade;
}


Node* to_ast_copy(char* exp){
    Node* root = init_node();
    

    char posfixa[200] = "";
	Stack *stack = init_stack();
    int cont = 0;
    char c;
    
    int i = 0 ;
    while(exp[cont] != '\0')
    {
        c = exp[cont];
        switch(c)
        {
            case '~':
            case '|':
            case '&':
                while((!empty(stack)) && prioridade(c) <= prioridade(top(stack)->value))
                    posfixa[i++] = top(stack)->value;
                
                push(stack, c);
                break; 
                
            case '(':
                push(stack, c);
                break;
                
            case ')':
                while(top(stack)->value != '('){
                    posfixa[i++] = top(stack)->value; pop(stack);
                }
                if(top(stack)->value == '(') pop(stack);
                break;
                
            default:
                posfixa[i++] = exp[cont];
                break;
        }
        cont++;
    }
    while(stack->size > 0){
        if(top(stack)->value != '('){
            posfixa[i++] = top(stack);
        }
        pop(stack);
    }
    
    for(int j = 0; j < i; j++){
        printf("%c ", posfixa[j]);
    }
};