#ifndef MATRIX2_HPP
#define MATRIX2_HPP

#define ll long long
#include "utils.hpp"

/**
 * @brief Abstração de uma matriz 2x2
 * 
 */
class Matrix2 {
    public:
        // elementos da matriz, a<linha><coluna>
        ll a11, a12, a21, a22;
        
        /**
         * @brief Construtor padrão, inicializa com uma matriz identidade
         * 
         */
        Matrix2() : a11(1), a12(0), a21(0), a22(1) {};  

        /**
         * @brief Construtor com valores iniciais
         * 
         * @param a Valor do elemento coluna 1 linha 1
         * @param b Valor do elemento coluna 1 linha 2
         * @param c Valor do elemento coluna 2 linha 1
         * @param d Valor do elemento coluna 2 linha 2
         */
        Matrix2(ll a, ll b, ll c, ll d) : a11(a), a12(b), a21(c), a22(d) {};


        /**
         * @brief Sobrecarga do operador de multiplicação
         * 
         * @param other Matriz a ser multiplicada
         * @return Matrix2 Resultado da multiplicação
         */
        Matrix2 operator*(const Matrix2& other){
            Matrix2 res;

            res.a11 = sum(mult(a11, other.a11), mult(a12, other.a21));
            res.a12 = sum(mult(a11, other.a12), mult(a12, other.a22));
            res.a21 = sum(mult(a21, other.a11), mult(a22, other.a21));
            res.a22 = sum(mult(a21, other.a12), mult(a22, other.a22));

            return res;
        }
};

#endif