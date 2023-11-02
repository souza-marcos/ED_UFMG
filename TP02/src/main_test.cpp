#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;
using std::cout;

/*
    IDEIA: Os vertices adjacentes sao organizados em um heap
    De toda forma temos que ordenar para uma busca eficiente
*/

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
}


int main(){
    string method; cin >> method;

    int vertices; cin >> vertices;
    vector<vector<int>> g(vertices);
    
    int n_adjac;
    for(auto& el: g){
        cin >> n_adjac;
        el.resize(n_adjac);
        for(auto& it:el) cin >> it; 
    }

    vector<pair<int, int>> colors(vertices); // color - id
    int cont = 0;
    for(auto& [color, id]: colors) {
        cin >> color;
        id = cont ++;
    }

    if(!verify_greedy(g, colors)){
        cout << "0" << endl; 
        return 0;
    }

    cout << "1 ";
    std::sort(colors.begin(), colors.end());
    for(auto el: colors) 
        cout << el.second << " "; 
        
    cout << endl;

    return 0;
}