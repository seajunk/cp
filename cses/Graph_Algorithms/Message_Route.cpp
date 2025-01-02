#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n, false);
    vector<ll> parent(n, -1);

    queue<ll> bfs;
    bfs.push(0);

    while(bfs.size()){
        ll curr = bfs.front();
        bfs.pop();
        visited[curr] = true;

        for(ll neigh : adj[curr]){
            if(!visited[neigh]){
                parent[neigh] = curr;
                visited[neigh] = true;
                bfs.push(neigh);
            }             
        }
    }

    if(!visited[n - 1]) cout << "IMPOSSIBLE\n";
    else{
        stack<ll> res;
        res.push(n - 1);
        ll curr = parent[n - 1];
        while(curr != -1){
            res.push(curr);
            curr = parent[curr];
        }
        cout << res.size() << '\n';
        while(res.size()){
            cout << res.top() + 1 << ' ';
            res.pop();
        }
        cout << '\n';
    }




}
