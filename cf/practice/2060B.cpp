#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    vector<vector<ll>> cards(n, vector<ll>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> cards[i][j];
    }


    for(int i = 0; i < n; i++){
        sort(cards[i].begin(), cards[i].end());
    }

    vector<vector<ll>> p(n, vector<ll>(2));

    for(int i = 0; i < n; i++){
        p[i][0] = i + 1;
        p[i][1] = cards[i][0];
    }


    sort(p.begin(), p.end(), [](auto l, auto r){
            return l[1] < r[1];
            });
    sort(cards.begin(), cards.end(), [](auto l, auto r){
            return l[0] < r[0];
            });

    ll curr = 0;
    for(int c = 0; c < m; c++){
        for(int r = 0; r < n; r++){
            if(cards[r][c] != curr){
                cout << -1 << '\n';
                return;
            }
            curr += 1;
        }
    }

    for(auto e : p){
        cout << e[0] << ' ';
    }
    cout << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

