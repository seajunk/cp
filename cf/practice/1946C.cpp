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





    /*
       want largest number x such that it is possible to remove k edges from the tree and each cc of the tree has size >= x




       note if some x works, x - 1 also works, so binary search for largest x



       then problem is for some fixed x, how to check if there is a way to remove k edges st each cc has size >= x





       No fucking idea









    */












}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
