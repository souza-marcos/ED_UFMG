#include <iostream>
#include "set.hpp"
#include "pair.hpp"
#include "graph.hpp"

#include "sort.hpp"

#define endl '\n'
using namespace std;
using std::cout;

bool verify_greedy(Graph& g, Vector<Pair<int,int>> &colors){

    for(size_t i = 0; i < g.vertices.getSize(); i ++){
        auto& v_adj = g.vertices[i].adjacent;

        if(colors[i].first == 1) continue;
        
        Set<int> set;

        // Inserindo em um conjunto
        for(size_t j = 0; j < v_adj.getSize(); j ++) {
            if(colors[v_adj[j]].first < colors[i].first){
                set.insert(colors[v_adj[j]].first);
            }
        }

        // Para nao ter 'buracos', o tamanho do conjunto deve ser igual ao valor da cor -1
        if((int)set.getSize() != colors[i].first - 1) return false;
    }
    return true;    
}

/**
 * @brief Escolhe o metodo de ordenacao com base no caractere escolhido e chama a funcao
 * 
 * @param method Metodo de ordenacao
 * @param colors Vetor de Cores
 */
void sort(char method, Vector<Pair<int,int>>& colors){

    switch (method)
    {
    case 'b':
        bubble_sort(colors);
        break;

    case 'i':
        insertion_sort(colors);
        break;
    
    case 's':
        selection_sort(colors);
        break;

    case 'm':
        merge_sort(colors, 0, colors.getSize() - 1);
        break;

    case 'q':
        cout << "NOT WORKING YET\n"; exit(-1);
        // quick_sort(colors, 0, colors.getSize() - 1);
        break;
    
    case 'p':
        heap_sort(colors);
        break;

    default:
        cout << "METODO INVALIDO\n";
        break;
    }

}

int main(){
    char method; cin >> method;

    int n_vert; cin >> n_vert;
    Graph g(n_vert);
    

    // Leitura dos dados do grafo
    int n_adjac;
    for(int i = 0; i < n_vert; i ++){
        cin >> n_adjac;
        
        g.vertices[i].index = i;
        g.vertices[i].adjacent = Vector<int>();
        for(int j = 0; j < n_adjac; j ++){
            int temp; cin >> temp;
            g.vertices[i].adjacent.push_back(temp);
        }
    }

    Vector<Pair<int,int>> colors(n_vert); // color - id
    int cont = 0;
    for(int i = 0; i < n_vert; i ++) {
        cin >> colors[i].first;
        colors[i].second = cont ++;
    }


    // Printing graph
    /*for(int i = 0; i < n_vert; i ++){
        cout << g.vertices[i].index << " - ";
        for(size_t j = 0; j < g.vertices[i].adjacent.getSize(); j ++){
            cout << g.vertices[i].adjacent[j] << " ";
        }
        cout << endl;
    }*/

    // print_array(colors);


    // print_array(colors);

    if(!verify_greedy(g, colors)){
        cout << "0" << endl; 
        return 0;
    }

    sort(method, colors);
    cout << "1 ";
    for(int i = 0; i < n_vert; i ++)
        cout << colors[i].second << " ";
    
    cout << endl;

    return 0;
}