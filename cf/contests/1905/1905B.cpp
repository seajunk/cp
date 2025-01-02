#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll leaf_cnt = 0;

    vector<bool> vis(n, false);
    stack<ll> dfs;
    dfs.push(0);
    vis[0] = true;

    while(dfs.size()){
        ll top = dfs.top();
        dfs.pop();

        ll neigh_cnt = 0;

        for(ll neigh : adj[top]){
            neigh_cnt++;
        }
        
        if(neigh_cnt < 2) leaf_cnt++;

        for(ll neigh : adj[top]){
            if(vis[neigh]) continue;
            vis[neigh] = true;
            dfs.push(neigh);
        }
    }


    // guess: each operation reduces leaf cnt by 2 for leafcnt > 3 
    // for leafcnt <= 3 reduces by one





    cout << (leaf_cnt + 1) /  2 << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
