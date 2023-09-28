#include "tree.h"
#include "stack.h"
#include "types.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_STACK 100

struct TreeNode* initTreeNode() {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->type = VALUE;
    node->left = NULL;
    node->right = NULL;
    node->data.value = 0;

    return node;
}

void insertRight(struct TreeNode* parent, struct TreeNode* child) {
    assert(parent->right == NULL);
    parent->right = child;
}

void insertLeft(struct TreeNode* parent, struct TreeNode* child) {
    assert(parent->left == NULL);
    parent->left = child;
}

void printTreeNode(struct TreeNode* node) {
    if (node->type == OPERATOR) {
        printf("%c ", node->data.operator);
    } else if (node->type == VALUE) {
        printf("%d ", node->data.value);
    }
}

void printTreePreorder(struct TreeNode* node) {
    if (node == NULL)
        return;

    Stack* stack;
    initStack(stack, MAX_SIZE_STACK);

    struct TreeNode* cur = node;
    while (!isEmpty(stack) || cur != NULL) {
        if (cur != NULL) {
            printTreeNode(cur);
            union GenericData data;
            if (cur->right != NULL){
                data.treeNodeData = cur->right;
                push(stack, TREENODE, data);
            }
            cur = cur->left;
        } else {
            pop(stack, TREENODE, &cur);
        }
    }
}

void printTreeInorder(struct TreeNode* node) {
    if (node == NULL)
        return;

    Stack* stack;
    initStack(stack, MAX_SIZE_STACK);

    struct TreeNode* cur = node;
    while (isEmpty(stack) || cur != NULL) {
        union GenericData data;
        if (cur != NULL) {
            data.treeNodeData = cur;
            push(stack, TREENODE, data);
            cur = cur->left;
        } else {
            pop(stack, TREENODE, &cur);
            printTreeNode(cur);
            cur = cur->right;
        }
    }
}

void printTreePosorder(struct TreeNode* node) {
    if (node == NULL)
        return;

    Stack* stack;
    initStack(stack, MAX_SIZE_STACK);
    struct TreeNode* prev = NULL;

    union GenericData aux;
    while (node != NULL || !isEmpty(stack)) {
        if (node != NULL) {
            aux.treeNodeData = node;
            push(stack, TREENODE, aux);
            node = node->left;
            continue;
        }
        struct TreeNode* cur;
        top(stack, TREENODE, &cur);
        if (cur->right != NULL && cur->right != prev) {
            node = cur->right;
        } else {
            printTreeNode(cur);
            prev = cur;
            pop(stack, TREENODE, &cur);
        }
    }
}

int priority(char el) {
    if (el == '|')
        return 1;
    if (el == '&')
        return 2;
    if (el == '~')
        return 3;
    return 0;
}
/*
void reduce(Stack* stack, struct TreeNode* root, struct TreeNode* *arr, int idx) {
    while (!empty(stack) && priority(top(stack)->data.operator) >= priority(arr[idx]->data.operator)) {
        struct TreeNode* operatorNode = top(stack);
        pop(stack);

        struct TreeNode* rightOperand = top(stack);
        pop(stack);

        struct TreeNode* leftOperand = top(stack);
        pop(stack);

        operatorNode->left = leftOperand;
        operatorNode->right = rightOperand;

        push(stack, operatorNode);
    }

    push(stack, arr[idx]);
}

struct TreeNode* toASTNew(char* exp) {
    struct TreeNode* arr[100];
    int arr_size = 0;

    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        struct TreeNode* cur = initTreeNode();
        cur->data.operator = exp[i++];
        if (cur->data.operator == '&') {
            cur->type = OPERATOR;
        }
        if (cur->data.operator == '|') {
            cur->type = OPERATOR;
        }
        if (cur->data.operator == '~') {
            cur->type = OPERATOR;
        }
        arr[arr_size++] = cur;
    }

    struct TreeNode* root = NULL;
    Stack* stack = initStack();

    for (int i = 0; i < arr_size; i++) {
        if (empty(stack)) {
            root = arr[i];
            push(stack, arr[i]);
            continue;
        }

        if (arr[i]->data.operator == '&' || arr[i]->data.operator == '|' || arr[i]->data.operator == '~') {
            push(stack, arr[i]);
            continue;
        }

        struct TreeNode* next = NULL;
        if (i + 1 < arr_size)
            next = arr[i + 1];
        else {
            reduce(stack, root, arr, i);
            continue;
        }

        if (priority(top(stack)->data.operator) >= priority(next->data.operator)) {
            reduce(stack, root, arr, i);
        } else {
            push(stack, arr[i]);
        }
    }

    while (stack->size > 0) {
        reduce(stack, root, arr, arr_size - 1);
    }

    return root;
}*/




/*
// 0 - False, 1 - True
bool evaluate_expression(char* exp, int arr[100]){

    int i = 0;
    Stack* s = init_stack();
    while(exp[i] != '\0'){
        if(exp[i] == '~'){
            // Is negation
            int val = arr[top(s)->value - '1']; 
            pop(s);
            push(s, !val);
        }
        else if(exp[i] == '|' || exp[i] == '&'){
            // Is operator
            int val1 = arr[top(s)->value - '1'];
            pop(s);
            int val2 = arr[top(s)->value - '1']; 
            pop(s);
            push(s, exp[i] == '|'? (val1 || val2): (val1 && val2));
        }
    }
    int val = arr[top(s)->value - '1']; pop(s); 
    free(s);
    return val;
}

int evaluateExpression(struct TreeNode* root, int arr[100]) {
    if (root->type == VALUE) {
        return arr[root->data.value - '1'];
    } else if (root->type == OPERATOR) {
        int leftValue = evaluateExpression(root->left, arr);
        int rightValue = evaluateExpression(root->right, arr);
        switch (root->data.operator) {
            case '&':
                return leftValue && rightValue;
            case '|':
                return leftValue || rightValue;
            case '~':
                return !rightValue;
            default:
                return 0; // Invalid operator
        }
    } else {
        return 0; // Invalid node type
    }
}
*/
/*


#include "tree.h"
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>


Node* init_node(){
    Node* n = malloc(sizeof(Node));
    n->type = VAL;
    n->left = 0;
    n->right = 0;
    n->value = 0;

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
    // switch (node->value)
    // {
    // case AND_OP:
    //     printf("& ");
    //     break;
    
    // case OR_OP:
    //     printf("| ");
    //     break;

    // case NEG_OP:
    //     printf("~ ");
    //     break;

    // default:
    //     printf("%d ", node->value); 
    //     break;
    // }
    printf("%d ", node->value); 
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

int priority(char el){
    if(el == OR_OP) return 1;
    if(el == AND_OP) return 2;
    if(el == NEG_OP) return 3;
    return 0;
}

/**
 * @brief Reduce method for resolve the top of stack operation 
 * 
 * @param stack 
 * @param root 
 * @param arr 
 * @param idx 
 *
void reduce(Stack* stack, Node* root, Node* *arr, int idx){
    // root = top(stack); pop(stack);
    // if(root->value != NEG_OP){
    //     insert_right(root, arr[idx]);
    //     insert_left(root, top(stack)); pop(stack);
    // }
    // else{
    //     insert_left(root, arr[idx]); // NOT nodes has only left node
    // }
    // push(stack, root);

    while (!empty(stack) && priority(top(stack)->value) >= priority(arr[idx]->value)) {
        Node* operatorNode = top(stack);  // Pop the operator from the stack
        pop(stack);

        Node* rightOperand = top(stack);  // Pop the right operand from the stack
        pop(stack);

        Node* leftOperand = top(stack);   // Pop the left operand from the stack
        pop(stack);

        // Create a new subtree with operatorNode as the root
        operatorNode->left = leftOperand;
        operatorNode->right = rightOperand;

        // Push the new subtree back onto the stack
        push(stack, operatorNode);
    }

    // Push the current token onto the stack
    push(stack, arr[idx]);

}
/**
 * @brief Tokenize and Parsing for a tree
 * 
 * @param exp Expression
 * @return Node* root of the tree
 *
Node* to_ast_new(char* exp){
    
    Node* arr[100];
    int arr_size = 0;

    

    int i = 0;
    while(exp[i] != '\0'){
        if(exp[i] == ' ') {i ++; continue; }

        Node* cur = init_node();
        cur->value = exp[i ++];
        if(cur->value == '&') {
            cur->value = AND_OP;
            cur->type = PROD;
        }
        if(cur->value == '|') {
            cur->value = OR_OP;
            cur->type = SUM;
        }
        if(cur->value == '~') {
            cur->value = NEG_OP;
            cur->type = VAL;
        }
        arr[arr_size ++] = cur;
    }

    Node* root = NULL;
    Stack* stack = init_stack();

    // printf("TOKENS SIZE: %d\n", arr_size);

    for(int i = 0; i < arr_size; i ++){

        printf("%d", i);
        if(empty(stack)){ // Shift
            root = arr[i];
            push(stack, arr[i]);
            continue;
        } // "~ 1 | 2 & 2 \0"

        if(arr[i]->value == '&' || arr[i]->value == '|' || arr[i]->value == '~'){ // Shift
            push(stack, arr[i]);
            continue;
        }

        Node* next = NULL;
        if (i + 1 < arr_size) next = arr[i + 1]; // Fix here
        else{ // Reduce
            // Reduce until it cannot be more

            reduce(stack, root, arr, i);
            continue;
        }
        // top(stack) <==> previous operator
        if(priority(top(stack)->value) >= priority(next->value)){ // Reduce
            reduce(stack, root, arr, i);
            // push(stack, root);
        }
        else{ // Shift
            push(stack, arr[i]);
        }
    }
    printf("Size of stack -> %d\n", stack->size);
    print_stack(stack);
    // // Here must reduce until it's impossible reduce more, i.e. priority.prev < priority.next
    // assert(stack->size <= 1); // Remove this
    while(stack->size > 0){
        print_tree_posorder(top(stack)); pop(stack);
        printf(" - - - - \n");
    }

    return root;
}

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


// Function to convert infix to postfix
char* infixToPostfix(const char* infix) {
    Stack* stack = init_stack();
    char* postfix = malloc(strlen(infix) * 2); // Allocate memory for result
    
    int postfixIndex = 0;
    
    for (int cont = 0; infix[cont] != '\0'; cont++) {
        if (infix[cont] == ' ') {
            continue;
        }
        char c = infix[cont];

        Node *node = init_node();
        node->value = c;
        switch (c) {
            case '|':
            case '&':
            case '~':
                while (!empty(stack) && getPrecedence(c) <= getPrecedence(top(stack)->value)) {
                    postfix[postfixIndex++] = top(stack)->value;
                    pop(stack);
                }
                push(stack, node);
                break;

            case '(':
                push(stack, node);
                break;

            case ')':
                while (top(stack)->value != '(') {
                    postfix[postfixIndex++] = top(stack)->value;
                    pop(stack);
                }
                if (top(stack)->value == '(') pop(stack);
                break;

            default:
                postfix[postfixIndex++] = c;
                break;
        }
    }
    
    while (!empty(stack)) {
        postfix[postfixIndex++] = top(stack)->value;
        pop(stack);
    }
    
    // Null-terminate the result
    postfix[postfixIndex] = '\0';
    
    return postfix;
}

// 0 - False, 1 - True
int evaluate_expression(char* exp, int arr[100]){

    int i = 0;
    Stack* s = init_stack();
    while(exp[i] != '\0'){
        if(exp[i] == '~'){
            // Is negation
            int val = arr[top(s)->value - '1']; 
            pop(s);
            push(s, !val);
        }
        else if(exp[i] == '|' || exp[i] == '&'){
            // Is operator
            int val1 = arr[top(s)->value - '1'];
            pop(s);
            int val2 = arr[top(s)->value - '1']; 
            pop(s);
            push(s, exp[i] == '|'? (val1 || val2): (val1 && val2));
        }
    }
    int val = arr[top(s)->value - '1']; pop(s); 
    free(s);
    return val;
}*/