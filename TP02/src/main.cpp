#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool verify_greedy(vector<vector<int>> g,vector<pair<int, int>> colors){
    // Verifying the color graph is greedy

    for(auto w: g) {
        for(auto el: w) cout << el << " "; 
        cout << endl;
    }

    set<int> colors_used;
    for(int i = 0; i < g.size(); i++){ // 
        
        // Iterate the neigh and add to a set
        colors_used.clear();
        for(auto it: g[i]) colors_used.insert(colors[it].first);
        
        cout << colors_used.size() << endl; 
        if(colors_used.size() < colors[i].first -1) return false;

        auto it = colors_used.begin();
        for(int j = 1; j < colors[i].first; j++){
            if((*it) != j) return false;
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

    sort(colors.begin(), colors.end());
    for(auto el: colors) 
        cout << el.second << " "; 
        
    cout << endl;

    return 0;
}