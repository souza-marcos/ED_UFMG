#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> arr;

void solve(){
    // arr[0 # i - 1] -> sorted

    for(int i = 1; i < arr.size(); i++){
        // BiSearch 0 # i-1. Find it, swaping until finish at ok position. Melhoria no custo das comparações apenas.
        auto pos = upper_bound(arr.begin(), arr.begin() + i, arr[i]) - arr.begin();
        if(pos == i) continue;
        for(int j = i; j > pos; j--){
            swap(arr[j], arr[j - 1]);
        }
    }
}

int main(){ _
    int n; cin >> n;
    arr.resize(n);
    for(auto& el: arr) cin >> el;

    solve();
    for(auto el: arr) cout << el << " ";
    return 0;
} 
