#include <iostream>
#include "graph.hpp"
#include "pair.hpp"
#include "set.hpp"
#include "sort.hpp"

#include "memlog.h"

#define endl '\n'
#define INF 0x3f3f3f3f

#ifndef ID_GRAPH
#define ID_GRAPH 0
#endif

#ifndef ID_AUX_VECTOR
#define ID_AUX_VECTOR 2
#endif


#define ID_COLORS_VECTOR 1

using namespace std;

char log_name[100] = "registro_acesso_a.txt";

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
        auto& v_adj = g.at(i).adjacent;
        // LOG
        // cout << colors.id << endl;
        if(colors.at(i).first == 1) continue;
        
        Set<int> set;

        // Inserindo em um conjunto
        for(size_t j = 1; j <= v_adj.getSize(); j ++) {
            if(colors.at(v_adj.at(j)).first < colors.at(i).first){
                set.insert(colors.at(v_adj.at(j)).first);
            }
        }

        // Para nao ter 'buracos', o tamanho do conjunto deve ser igual ao valor da cor -1
        if((int)set.getSize() != colors.at(i).first - 1) return false;
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

int main(int argc, char** argv){

    // desativaMemLog();
    // if(argc > 1) {
    //     string s = argv[1];
    //     if(s == "l"){
    //         ativaMemLog();
    //     }
    // }

    iniciaMemLog(log_name);
    ativaMemLog();
    defineFaseMemLog(0); // Fase 0: Leitura dos dados

    char method; cin >> method;

    int n_vert; cin >> n_vert;
    Graph g(n_vert, ID_GRAPH);
    

    // Leitura dos dados do grafo
    int n_adjac;
    for(int i = 0; i < n_vert; i ++){
        cin >> n_adjac;
        g[i].adjacent = Vector<int>(1, ID_GRAPH);

        g[i].adjacent.setId(ID_GRAPH);

        for(int j = 0; j < n_adjac; j ++){
            int temp; cin >> temp;
            g[i].adjacent.push_back(temp);
        }
    }
    
    int maxColor = -INF;
    Vector<Pair<int,int>> colors(n_vert, ID_COLORS_VECTOR); // color - id

    int cont = 0;

    // Leitura das cores e calculo da maior cor
    for(int i = 0; i < n_vert; i ++) {
        cin >> colors[i].first;
        if(colors.at(i).first > maxColor) maxColor = colors.at(i).first;
        colors[i].second = cont ++;
    }

    defineFaseMemLog(1); // Fase 1: Gulosidade

    // Verifica se o grafo esta colorido gulosamente
    if(!verify_greedy(g, colors)){
        cout << "0" << endl; 

        finalizaMemLog();

        return 0;
    }

    defineFaseMemLog(2); // Fase 2: Ordenacao

    // Ordena o vetor de cores
    sort(method, colors, maxColor);
    cout << "1 ";
    for(int i = 0; i < n_vert; i ++)
        cout << colors.at(i).second << " ";
    
    cout << endl;

    finalizaMemLog();
    
    return 0;
}