#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> bridge;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);


    ll components = 0; 
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        components += 1;
        bridge.push_back(i + 1);
        stack<ll> dfs;
        dfs.push(i);
        while(dfs.size()){
            ll top = dfs.top();
            dfs.pop();
            visited[top] = true;
            for(ll neigh : adj[top]){
                if(!visited[neigh]) dfs.push(neigh);
            }
        }
    }


    cout << components - 1 << '\n';
    for(int i = 1; i < components; i++){
        cout << bridge[i - 1] << ' ' << bridge[i] << '\n';
    }


}
