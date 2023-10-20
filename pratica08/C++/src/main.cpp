#include <iostream>
#include "heap.hpp"
#include "unionFind.hpp"

using namespace std;
int main(){

    int n, m, u, v, c; cin >> n >> m;

    Heap heap(m);
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        heap.Inserir({u, v, c});
    }

    UnionFind disjoint_set(n);
    for(int i = 0; i < n; i ++) disjoint_set.Make(i);

    int edges_added = 0, cost = 0;
    Aresta cur;
    while(edges_added < n - 1){
        cur = heap.Remover();

        // Se estao em conjunto diferentes adiciona a aresta
        if(disjoint_set.Find(cur.u) != disjoint_set.Find(cur.v)){
            disjoint_set.Union(cur.u, cur.v);
            cost += cur.custo; edges_added ++;
        }
    }
    cout << cost << endl;
    return 0;
}