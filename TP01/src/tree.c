#include "tree.h"
#include "stack.h"

#include <assert.h>
#include <stdio.h>

#define AND_OP -1
#define OR_OP -2
#define NEG_OP -3

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


Node* to_ast_new(char* exp){
    Node* root = init_node();
    // Iterate the subsequence getting the most priority elements
    // 1.Par 2.Not 3.And 4.Or


    //Tokenize elements



}

Node* to_ast(char* exp){ // FIX HERE

    Node* root = init_node();
    // Node* parent = NULL;

    Stack* stack = init_stack();
    push(stack, root);


    int i = 0;
    Node *left = init_node();
    insert_left(root, left);
    push(stack, root);
    Node* cur = left;
    
    while(exp[i] != '\0'){

        if(exp[i] == ' '){i ++; continue;}

        if(exp[i] == '&' || exp[i] == '|' ){ //AND OR NOT
            cur->value = (exp[i] == '&'?AND_OP:OR_OP);
            Node* right = init_node();
            insert_right(cur, right);
            push(stack, cur);
            cur = right;
        }
        else if(exp[i] == '(' || exp[i] == '~'){
            if(exp[i] == '~') cur->value = NEG_OP;
            Node *left = init_node();
            insert_left(cur, left);
            push(stack, cur);
            cur = left;
        }
        else if(exp[i] == ')'){ //RPAR
            cur = top(stack); pop(stack); // Getting the parent
        }
        else{
            cur->value = exp[i];
            if(top(stack)->value == NEG_OP) pop(stack); // The not operator is unary
            cur = top(stack); pop(stack); // Getting the parent
        }

        i++;
    }

    return root;
}