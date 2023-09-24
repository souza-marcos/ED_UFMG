#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define AND_OP -1
#define OR_OP -2
#define NEG_OP -3

#define CINF 0x7f

typedef struct Node{
    char value;
    //struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;


// Stack
#define MAX_STACK 100

typedef struct Stack{
    int size;
    Node *arr[MAX_STACK];

} Stack;

Stack* init_stack(){
    Stack* s = malloc(sizeof(Stack));
    s->size = 0;
    return s;
}

Node* top(Stack* s){
    return s->arr[s->size -1];
}

void pop(Stack* s){
    s->arr[-- s->size] = NULL;
}

int push(Stack* s, Node* n){
    if(s->size >= MAX_STACK) return 0;
    s->arr[s->size ++] = n;
    return 1;
}

void empty(Stack* s){
    s->size = 0;
}

void print_stack(Stack* stack){
    for(int i = 0; i < stack->size; i++){
        printf("%c\n", stack->arr[i]->value);
    }
}


// AST
Node* init_node(){
    Node* n = malloc(sizeof(Node));
    //n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->value = CINF;

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

void print_tree_preorder(Node* node){
    if(node == NULL) return;

    Stack *s = init_stack();
    Node* cur = node;
    while(s->size != 0 || cur != NULL){
        
        if(cur != NULL){
            printf("%d ", cur->value);

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
            printf("%d ", cur->value);
            cur = cur->right;
        }
    }
}


void print_tree_posorder(Node* node){
    if(node == NULL) return;

    Stack *main_s = init_stack(), *right_s = init_stack();
    Node* cur = node;
    while(main_s->size != 0 || cur != NULL){
        
        if(cur != NULL){
            if(cur->right != NULL) push(right_s, cur);
            push(main_s, cur);
            cur = cur->left;
        }else{
            cur = top(main_s);
            if(right_s->size > 0 && cur->right == top(right_s)){
                cur = top(right_s); pop(right_s); 
            }
            else{
                printf("%d ", cur->value);
                pop(main_s);
                cur = NULL;
            }
        }
    }
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
        //printf("-%c-", exp[i]); //TODO: remove

        if(exp[i] == ' '){i ++; continue;}

        if(exp[i] == '&' || exp[i] == '|' || exp[i] == '~'){ //AND OR NOT
            cur->value = (exp[i] == '&'?AND_OP:(exp[i] == '|'?OR_OP:NEG_OP));
            Node* right = init_node();
            insert_right(cur, right);
            push(stack, cur);
            cur = right;
        }else if(exp[i] == '('){ //LPAR
            Node *left = init_node();
            insert_left(cur, left);
            push(stack, cur);
            cur = left;
        }else if(exp[i] == ')'){ //RPAR
            cur = top(stack); pop(stack); // Getting the parent
        }else{
            cur->value = exp[i];
            cur = top(stack); pop(stack); // Getting the parent
        }

        i++;
    }

    return root;
}

int solve(int *arr, int size){
    return -1;
}

int main(){

    char expression[100] = "(1 & ~ 2 | 1 & 0) \0";

    Node* root = to_ast(expression); 

    print_tree_preorder(root);
    printf("\n");
    print_tree_inorder(root);
    printf("\n");
    print_tree_posorder(root);
    // int s[100], s_size = 0;
    // printf("%s", expression);

    // while(scanf("%c", &temp)) s[s_size++] = (int) temp;


    return 0;
}