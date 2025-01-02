#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n);
    unordered_map<ll, set<ll>> adj;
    set<ll> nodes;
    unordered_set<ll> fast_nodes;

    vector<ll> mexes;

    for(int i = 0; i < n; i++){
        ll l; cin >> l;
        for(int j = 0; j < l; j++){
            ll in; cin >> in;
            a[i].push_back(in);
        }

        vector<bool> seen(l + 2, false);

        for(int j = 0; j < l; j++){
            if(a[i][j] < l + 2) seen[a[i][j]] = true;
        }
        ll u, v;

        for(int j = 0; j < l + 2; j++){
            if(!seen[j]){
                u = j;
                seen[j] = true;
                break;
            }
        }
        for(int j = 0; j < l + 2; j++){
            if(!seen[j]){
                v = j;
                break;
            }
        }
        mexes.push_back(u);
        nodes.insert(u);
        nodes.insert(v);
        fast_nodes.insert(u);
        fast_nodes.insert(v);
        adj[u];
        adj[v].insert(u);
    }

    /*
    for(auto pair : adj){
        cout << pair.first << ": ";
        for(ll neigh : pair.second) cout << neigh << ' ';
        cout << '\n';
    }
    */


    unordered_map<ll, ll> max_transition;
    for(ll node : nodes) max_transition[node] = -1;


    unordered_map<ll, bool> visited;
    for(ll node : nodes) visited[node] = false;

    for(auto it = nodes.rbegin(); it != nodes.rend(); it++){
        ll curr = *it;
        if(visited[curr]) continue;
        
        max_transition[curr] = max(max_transition[curr], curr);
        visited[curr] = true;
        queue<ll> bfs;
        bfs.push(curr);

        while(bfs.size()){
            ll  front = bfs.front();
            bfs.pop();
            for(ll neigh : adj[front]){
                if(visited[neigh]) continue;
                visited[neigh] = true;
                max_transition[neigh] = max(max_transition[neigh], curr);
                bfs.push(neigh);
            }
        }
    }



    ll max_mex = -1;
    for(ll mex : mexes) max_mex = max(max_mex, max_transition[mex]);





    ll ans = 0;
    for(ll i = 0; i <= m; i++){
        if(fast_nodes.find(i) == fast_nodes.end()){
            ans += max(i, max_mex);
        }
        else{
            ans += max(max_transition[i], max_mex);
        }
    }

    cout << ans << '\n';












}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
