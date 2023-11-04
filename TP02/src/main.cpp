#include <iostream>
#include "set.hpp"
#include "pair.hpp"
#include "graph.hpp"

#include "sort.hpp"

#define endl '\n'
#define INF 0x3f3f3f3f

using namespace std;

/**
 * @brief Verifica se o grafo esta colorido gulosamente
 * 
 * @param g O grafo
 * @param colors O vetor de cores 
 * @return true Colorido gulosamente
 * @return false Não colorido gulosamente
 */
bool verify_greedy(Graph& g, Vector<Pair<int,int>> &colors){

    for(size_t i = 0; i < g.getSize(); i ++){
        auto& v_adj = g[i].adjacent;

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
 * @param maxColor Maior cor
 */
void sort(char method, Vector<Pair<int,int>>& colors, int maxColor){

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
    
    case 'p':
        heap_sort(colors);
        break;
    
    case 'y':
        my_sort(colors, maxColor);
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
        g[i].adjacent = Vector<int>();
        for(int j = 0; j < n_adjac; j ++){
            int temp; cin >> temp;
            g[i].adjacent.push_back(temp);
        }
    }
    
    int maxColor = -INF;
    Vector<Pair<int,int>> colors(n_vert); // color - id
    int cont = 0;

    // Leitura das cores e calculo da maior cor
    for(int i = 0; i < n_vert; i ++) {
        cin >> colors[i].first;
        if(colors[i].first > maxColor) maxColor = colors[i].first;
        colors[i].second = cont ++;
    }

    // Verifica se o grafo esta colorido gulosamente
    if(!verify_greedy(g, colors)){
        cout << "0" << endl; 
        return 0;
    }

    // Ordena o vetor de cores
    sort(method, colors, maxColor);
    cout << "1 ";
    for(int i = 0; i < n_vert; i ++)
        cout << colors[i].second << " ";
    
    cout << endl;
    return 0;
}