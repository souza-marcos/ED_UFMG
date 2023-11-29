#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "../include/matrix2.hpp"

class SegTree{
private:
    // Arvore de segmentos na forma de um vetor
    Matrix2* seg;
    int n;

    /**
     * @brief Consulta à segtree para o intervalo pedido
     * 
     * @param a Inicio do intervalo de consulta
     * @param b Final do intervalo de consulta 
     * @param p Valor da posição na segtree (raiz => 1)
     * @param l Inicio do intervalo que o elemento da posicao p da segtree representa
     * @param r Fim do intervalo que o elemento da posicao p da segtree representa
     * @return Matrix2 Resultado da consulta
     */
    Matrix2 query(int a, int b, int p, int l, int r){
        if(a > r or b < l) return Matrix2(); // Intervalos disjuntos
        if(a <= l and b >= r) return seg[p]; // Intervalo [l, r] inteiramente contido em [a, b]

        int m = (l + r)/2;
        return query(a, b, 2 * p, l, m) * query(a, b, 2 * p + 1, m + 1, r);
    }

    /**
     * @brief Atualiza a segtree quando atualizamos uma posicao do array original
     * 
     * @param i Indice da atualizacao
     * @param x Matriz2 - Novo valor da posição
     * @param p Valor da posição da segtree
     * @param l Inicio do intervalo que o elemento da posicao p da segtree representa
     * @param r Fim do intervalo que o elemento da posicao p da segtree representa
     * @return Matrix2 Novo valor para a raiz da subarvore passada (quando p inicial eh 0 temos para a arvore inteira)
     */
    Matrix2 update(int i, Matrix2 x, int p, int l, int r){
        if(i < l or i > r) return seg[p]; // Indice nao presente no intervalo
        if(l == r) return seg[p] = x; // Chegou na folha == Array principal

        int m = (l + r)/2;
        return seg[p] = update(i, x, 2 * p, l, m) * update(i, x, 2 * p + 1, m + 1, r);
    }

public:

    /**
     * @brief Construtor da árvore de segmentos
     * 
     * @param n Tamanho do array original
     */
    SegTree(int n){
        this->n = n;
        seg = new Matrix2[4 * n + 1];
    }

    /**
     * @brief Destrutor da árvore de segmentos
     * 
     */
    ~SegTree(){
        delete[] seg;
    }

    /**
     * @brief Consulta à segtree para o intervalo pedido
     * 
     * @param a Inicio do intervalo de consulta
     * @param b Final do intervalo de consulta 
     * @return Matrix2 Resultado da consulta
     */
    Matrix2 query(int a, int b){
        return query(a, b, 1, 0, n - 1);
    }

    /**
     * @brief Atualiza a segtree quando atualizamos uma posicao do array original
     * 
     * @param i Indice da atualizacao
     * @param x Matriz2 - Novo valor da posição
     * @return Matrix2 Novo valor para a raiz da árvore
     */
    Matrix2 update(int i, Matrix2 x){
        return update(i, x, 1, 0, n - 1);
    }
};

#endif