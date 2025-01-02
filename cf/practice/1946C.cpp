#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, k; cin >> n >> k;



    vector<vector<ll>> edges;
    vector<vector<ll>> adj(n);
    for(int i = 0 ; i < n - 1; i++){
        ll u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
