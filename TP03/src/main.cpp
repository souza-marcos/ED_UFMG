#include <iostream>
#include "matrix2.hpp"
#include "utils.hpp"

// #include "memlog.h"

#define endl '\n'
#define INF 0x3f3f3f3f

using namespace std;

Matrix2* seg;

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


int main(){

    int n, q; cin >> n >> q;
    
    // Arvore de segmentos
    seg = new Matrix2[4 * n + 1];

    char type;
    while(q --){
        cin >> type;
        if(type == 'u'){ // update
            int pos; cin >> pos;
            Matrix2 up; cin >> up.a11 >> up.a12 >> up.a21 >> up.a22;

            up.a11 %= MOD, up.a12 %= MOD, up.a21 %= MOD, up.a22 %= MOD;

            update(pos, up, 1, 0, n - 1);
        }
        else{ // Consulta
            int tinicio, tfinal, x, y;
            cin >> tinicio >> tfinal >> x >> y;

            Matrix2 res = query(tinicio, tfinal, 1, 0, n - 1);

            cout << sum(mult(x, res.a11), mult(y, res.a12)) << " " 
                 << sum(mult(x, res.a21), mult(y, res.a22)) << endl; 
        }
    }

    delete[] seg;

    return 0;
}
