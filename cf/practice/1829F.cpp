#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n);

    for(int i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<ll, ll> cnt;
    for(int i = 0; i < n; i++){
        if(adj[i].size() > 1){
            cnt[adj[i].size()]++;
        }
    }

    if(cnt.size() == 1){
        ll x, y;
        for(auto p : cnt){
            x = p.second - 1;
            y = p.first - 1;
            cout << x << ' ' << y << '\n';
        }
    }
    else if(cnt.size() == 2){
        ll x, y;
        for(auto p : cnt){
            if(p.second == 1) x = p.first;
        }
        for(auto p : cnt){
            if(p.first != x) y = p.first - 1;
        }

        cout << x << ' ' << y << '\n';

    }
    else{
        cout << "shit went wrong\n";
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

