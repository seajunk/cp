#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    map<vector<ll>, ll> weight;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(v);
        weight[{u, v}] = w;
    }
    vector<ll> x(n, 0);

    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        if(visited[i]) continue;



        queue<vector<ll>> bfs; // node, value

        bfs.push({i, 0});

        while(bfs.size()){
            vector<ll> front = bfs.front();
            x[front[0]] = front[1];
            visited[front[0]] = true;
            bfs.pop();

            for(ll neigh : adj[front[0]]){
                if(!visited[neigh]){
                    bfs.push({neigh, front[1] + weight[{front[0], neigh}]});
                }
            }


        }
    }

    for(int i = 0; i < n; i++) cout << x[i] << ' ';
    cout << '\n';
}


