#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // dfs?
    ll n; cin >> n;
    char a[2][n];
    for(int i = 0; i < n; i++) cin >> a[0][i]; 
    for(int i = 0; i < n; i++) cin >> a[1][i]; 

    map<vector<ll>, vector<vector<ll>>> adj;

    ll dr[4] = {-1, 0, 1, 0};
    ll dc[4] = {0, 1, 0, -1};
    for(int r = 0; r < 2; r++){
        for(int c = 0; c < n; c++){
            for(int i = 0; i < 4; i++){
                ll nr = r + dr[i];
                ll nc = c + dc[i];
                if(!(0 <= nr && nr < 2 && 0 <= nc && nc < n)) continue;
                if(a[nr][nc] == '<') nc--;
                else if(a[nr][nc] == '>') nc++;
                if(!(0 <= nr && nr < 2 && 0 <= nc && nc < n)) continue;
                if(r == nr && c == nc) continue;
                adj[{r, c}].push_back({nr, nc});
            }
        }
    }



    queue<vector<ll>> bfs;
    set<vector<ll>> vis;

    bfs.push({0, 0});
    vis.insert({0, 0});

    while(bfs.size()){
        vector<ll> front = bfs.front();
        bfs.pop();

        for(auto neigh : adj[front]){
            if(vis.find(neigh) != vis.end()) continue;
            if(neigh[0] == 1 && neigh[1] == (n - 1)){
                cout << "YES\n";
                return;
            }
            vis.insert(neigh);
            bfs.push(neigh);
        }
    }

    cout << "NO\n";
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
