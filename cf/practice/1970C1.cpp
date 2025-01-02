#include <bits/stdc++.h> 
#define ll long long
using namespace std;

void solve(){
    ll n, t; cin >> n >> t;
    vector<vector<ll>> g(n);
    vector<bool> visited(n, false);
    vector<ll> distance(n);

    for(int i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll stone; cin >> stone; stone--;


    stack<ll> dfs;
    distance[stone] = 0;
    dfs.push(stone);

    while(dfs.size()){
        ll top = dfs.top();
        dfs.pop();
        visited[top] = true;

        for(ll neigh : g[top]){
            if(!visited[neigh]){
                dfs.push(neigh);
                distance[neigh] = distance[top] + 1;
            }
        }

    }

    vector<ll> mxdist;
    for(int i = 0; i < n; i++){
        if(g[i].size() == 1){
            mxdist.push_back(distance[i]);
        }
    }

    if(mxdist[0] % 2 == 1 || mxdist[1] % 2 == 1) cout << "Ron" << '\n';
    else cout << "Hermione" << '\n'; 




}

int main(){
    solve();
}
