#include <iostream>
#include "../include/matrix2.hpp"
#include "../include/msgassert.h"
#include "../include/segtree.hpp"
#include "../include/utils.hpp"

// #include "memlog.h"

#define endl '\n'
#define INF 0x3f3f3f3f

using namespace std;

int main(){

    int n, q; cin >> n >> q;
    
    erroAssert(n > 0, "Número de transformações deve ser positivo");
    erroAssert(q > 0, "Número de jogadas deve ser positivo");

    // Arvore de segmentos
    SegTree seg(n);

    char type;
    while(q --){
        cin >> type;

        erroAssert(type == 'u' || type == 'q', "Tipo de jogada inválida");

        if(type == 'u'){ // update
            int pos; cin >> pos;

            erroAssert(pos >= 0 && pos <= n, "Posição inválida");

            Matrix2 up; cin >> up.a11 >> up.a12 >> up.a21 >> up.a22;
            up.a11 %= MOD, up.a12 %= MOD, up.a21 %= MOD, up.a22 %= MOD;

            seg.update(pos, up);
        }
        else{ // Consulta
            int tinicio, tfinal, x, y;
            cin >> tinicio >> tfinal >> x >> y;

            erroAssert(tinicio >= 0 && tinicio <= n, "Tempo inicial inválido");
            erroAssert(tfinal >= 0 && tfinal <= n, "Tempo final inválido");
            erroAssert(tinicio <= tfinal, "Tempo inicial deve ser menor ou igual ao tempo final");

            Matrix2 res = seg.query(tinicio, tfinal);

            cout << sum(mult(x, res.a11), mult(y, res.a12)) << " " 
                 << sum(mult(x, res.a21), mult(y, res.a22)) << endl; 
        }
    }

    return 0;
}
