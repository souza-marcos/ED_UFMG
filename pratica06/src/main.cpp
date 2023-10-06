#include <iostream>
#include "graph.hpp"

using namespace std;

#define endl '\n'

int main(int argc, char *argv[]){

    std::string type = argv[1];

    int n; cin >> n;
    Grafo grafo(false);
    for(int i = 0; i < n; i++) grafo.InsereVertice();
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            int v; cin >> v;
            grafo.InsereAresta(i, v);
        }
    }

    if(type == "-d"){
        cout << grafo.QuantidadeVertices() << endl
             << grafo.QuantidadeArestas() << endl
             << grafo.GrauMinimo() << endl
             << grafo.GrauMaximo() << endl;
    }
    else if(type == "-n"){
        for(int i = 0; i < grafo.QuantidadeVertices(); i++)
            grafo.ImprimeVizinhos(i);
    }
    else if(type == "-k"){

        // (k - 1) * k / 2 == grafo.QuantidadeArestas()
        int k = grafo.QuantidadeVertices();
        cout << (grafo.QuantidadeArestas() == (k - 1) * k / 2) << endl; 
    }

    return 0;
}