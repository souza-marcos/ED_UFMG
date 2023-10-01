#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "binary_tree.hpp"

/**
 * @brief Função que retorna a precedência de um operador
 * 
 * @param op Operador (& -> AND, | -> OR, ~ -> NOT)
 * @return int Precedência do operador
 */
int getPrecedence(char op);

/**
 * @brief Função que converte uma expressão lógica em forma infixa para uma expressão lógica em forma posfixada
 * 
 * @param infix Expressão lógica em forma infixa
 * @return std::string Expressão lógica em forma posfixada
 */
std::string infixToPostfix(const char* infix);

/**
 * @brief Função que converte uma expressão lógica em forma posfixada para uma árvore de expressão lógica
 * 
 * @param postfix Expressão lógica em forma posfixada
 * @return TreeNode<char>* Raiz da Árvore de expressão lógica
 */
TreeNode<char>* postfixToAST(const std::string& postfix);

/**
 * @brief Função que avalia uma expressão lógica
 * 
 * @param root Árvore de expressão lógica
 * @param arr Valores para as variáveis da expressão
 * @return true Se a expressão for verdadeira
 * @return false Se a expressão for falsa
 */
bool evaluateExpression(TreeNode<char>* root, int arr[100]);

/**
 * @brief Função que avalia uma expressão lógica
 * 
 * @param root Árvore de expressão lógica
 * @param vals Valores para as variáveis da expressão
 * @return true Se a expressão for verdadeira
 * @return false Se a expressão for falsa
 */
bool evaluateExpression(TreeNode<char>* root, std::string vals);

/**
 * @brief Função que avalia uma expressão lógica
 * 
 * @param exp Expressão lógica em forma posfixada
 * @param arr Valores para as variáveis da expressão
 * @return true Se a expressão for verdadeira
 * @return false Se a expressão for falsa
 */
bool evaluateExpression(std::string exp, int arr[100]);

/**
 * @brief Função que avalia uma expressão lógica
 * 
 * @param exp Expressão lógica em forma posfixada
 * @param vals Valores para as variáveis da expressão
 * @return true Se a expressão for verdadeira
 * @return false Se a expressão for falsa
 */
bool evaluateExpression(std::string exp, std::string vals);

/**
 * @brief Função que avalia a satisfatibilidade de uma expressão lógica
 * 
 * @param ast_exp Árvore de expressão lógica
 * @param vals Valores para as variáveis da expressão (a -> "para todo", e -> "existe", 0 -> "falso", 1 -> "verdadeiro") 
 * @param res Resultado da avaliação da expressão, se for verdadeira, retorna os valores das variáveis que satisfazem a expressão, quando não importa o valor da variável, retorna 'a'
 * @return true Se a expressão for verdadeira
 * @return false Se a expressão for falsa
 */
bool sat_tree(TreeNode<char> *ast_exp, std::string vals, std::string &res);

#endif // UTILS_HPP