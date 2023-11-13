#include <iostream>
#include "matrix2.hpp"
#include "vector.hpp"

// #include "memlog.h"

#define endl '\n'
#define INF 0x3f3f3f3f

using namespace std;

const int MAX = 1e5 + 10;

Vector<Matrix2> arr(MAX);
Vector<Matrix2> seg(4 * MAX);

/**
 * @brief Construcao da arvore de segmentos utilizada no problema
 * 
 * @param p Valor da posicao da segtree
 * @param l Inicio do intervalo que o elemento da posicao p da segtree representa
 * @param r Fim do intervalo que o elemento da posicao p da segtree representa
 * @return Matrix2 
 */
Matrix2 build(int p, int l, int r){
    if(l == r) seg[p] = arr[l]; // Folha

    int m = (l + r)/2;
    return seg[p] = build(2 * p, l, m) * build(2 * p + 1, m + 1, r); // Multiplicação de Matrizes eh uma operação associativa
}

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
    

    // for(int i = 0; i < n; i ++){
    //     Matrix2& aux = arr[i];
    //     cout << aux.a11 << " " << aux.a12 << endl << aux.a21 <<  " " << aux.a22 << endl;
    // }
    // build(1, 0, n - 1);

    char type;
    while(q --){
        cin >> type;
        if(type == 'u'){ // update
            int pos; cin >> pos;
            Matrix2 up; cin >> up.a11 >> up.a12 >> up.a21 >> up.a22;

            update(pos, up, 1, 0, n - 1);
        }
        else{
            int tinicio, tfinal, x, y;
            cin >> tinicio >> tfinal >> x >> y;

            Matrix2 res = query(tinicio, tfinal, 1, 0, n - 1);
            cout << (((x * res.a11) % MOD) + ((y * res.a12) % MOD) % MOD) << " " 
                 << (((x * res.a21) % MOD) + ((y * res.a22) % MOD) % MOD) << endl; 

            // cout << res.a11 << " " << res.a12 << endl << res.a21 << " " << res.a22 << endl;
        }
    }
    return 0;
}
