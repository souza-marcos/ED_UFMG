#include <iostream>
#include "set.hpp"
#include "pair.hpp"
#include "graph.hpp"

#include "sort.hpp"

#define endl '\n'
using namespace std;
using std::cout;

/*
bool verify_greedy(vector<vector<int>> g, vector<pair<int, int>> colors){
    
    // sort(colors.begin(), colors.end());
    
    // Percorrer cada 


    for(size_t i = 0; i < g.size(); i ++){
        vector<int> w = g[i];

        
        // Ordenacao pela cor nos vertices adjacentes
        std::sort(w.begin(), w.end(), [colors](const int &el1, const int &el2){
            if(colors[el1].first == colors[el2].second)
                return colors[el1].second < colors[el2].second;
            return colors[el1].first < colors[el2].second;
        });

        // for(auto el: w) cout << el << " ";
        // cout << endl;
        // TODO:
        // Verificacao se nao temos 'buracos' entre menor cor ate cor do representante

        int cont = 1; // 1 1 2 3 3 5 ->(cont)=> 2 2 3 4 4 
        size_t j = 0;
        for(; j < w.size(); j++){
            if(colors[w[j]].first >= colors[i].first -1) {
                break;
            }
            if(cont < colors[w[j]].first) return false; // Temos um buraco -> ex: 4 [5] 6, cont = 4 => 4 + 1 < 6 OK
            if(cont == colors[w[j]].first) cont ++; // else
        }

        // BUG: NAO TA ATUALIZANDO CONT
        // Caso nao tenha, verificamos se a cor do representante eh 1 a mais do que a maior cor presente
        
        // if(j == w.size()) {cout << "CHEGOU NO FINAL" << endl;}
        

        cout << "CONT: " << cont << ", " << w[i] << " " << colors[w[i]].first << " - " << w[j] << " " << colors[w[j]].first << endl;
        

        if(colors[w[j]].first + 1 < colors[w[i]].first){
            // LOG
            cout << "OUTRO" << endl;
            return false;
        } 
    }

    return true;    
}*/

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
        quick_sort(colors, 0, colors.getSize() - 1);
        break;
    
    case 'h':
        heap_sort(colors);
        break;

    default:
        cout << "METODO INVALIDO\n";
        break;
    }

}

bool operator<(const Pair<int, int> &a, const Pair<int, int> &b){
    // Color, Index
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
};

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
    for(int i = 0; i < n_vert; i ++){
        cout << g.vertices[i].index << " - ";
        for(size_t j = 0; j < g.vertices[i].adjacent.getSize(); j ++){
            cout << g.vertices[i].adjacent[j] << " ";
        }
        cout << endl;
    }

    

    sort(method, colors);

    cout << " AQUI" << endl;
    // if(!verify_greedy(g, colors)){
    //     cout << "0" << endl; 
    //     return 0;
    // }

    return 0;
}