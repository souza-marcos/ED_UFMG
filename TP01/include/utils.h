#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "vector.h"
#include "binary_tree.h"


/**
 * @brief Função que converte uma expressão lógica em forma infixa para uma expressão lógica em forma posfixada
 * 
 * @param infix Expressão lógica em forma infixa
 * @return Vector<int> Vetor da Expressão lógica em forma posfixada
 */
Vector<int> infixToPostfix(const char* infix);

/**
 * @brief Função que avalia uma expressão lógica
 * 
 * @param exp Expressão lógica em forma posfixada
 * @param arr Valores para as variáveis da expressão
 * @return true Se a expressão for verdadeira
 * @return false Se a expressão for falsa
 */
bool evaluateExpression(Vector<int> exp, int arr[100]);

/**
 * @brief Função que avalia uma expressão lógica
 * 
 * @param exp Expressão lógica em forma posfixada
 * @param vals Valores para as variáveis da expressão
 * @return true Se a expressão for verdadeira
 * @return false Se a expressão for falsa
 */
bool evaluateExpression(Vector <int> exp, std::string vals);

/**
 * @brief Função que avalia a satisfatibilidade de uma expressão lógica
 * 
 * @param postfix_exp string posfixada da espressão
 * @param vals Valores para as variáveis da expressão (a -> "para todo", e -> "existe", 0 -> "falso", 1 -> "verdadeiro")
 * @return std::string Resultado da avaliação da expressão, 
 * se for verdadeira, retorna os valores das variáveis que 
 * satisfazem a expressão, quando não importa o valor da variável, 
 * retorna 'a' na posição da string analisada. Retorna string vazia
 * se a expressão for falsa.
 */
std::string sat_tree(Vector<int> postfix_exp, std::string vals);

#endif // UTILS_HPP