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

vector<int> s;

bool solve(int n, int sum){
    auto it = s.begin();
    while(it != s.end()){

        auto pos = lower_bound(it + 1, s.end(), (sum - (*it))); // lower bound less or equal(not greater)
        if(pos != s.end() and (*pos) == sum - (*it)) {
            cout << "At Positions: " << (it - s.begin()) << ", " << (pos - s.begin()) << endl;
            return true;
        }
        ++it;
    }
    cout << "Not found!" << endl;
    return false;
}

int main(){ _
    int n, sum; cin >> n >> sum;
    s.resize(n);
    for(auto& el : s) cin >> el;

    sort(s.begin(), s.end());

    solve(n, sum);
    return 0;
} 
