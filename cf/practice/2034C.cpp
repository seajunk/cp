#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int r = 0; r < n; r++) for(int c = 0; c < m; c++) cin >> grid[r][c];

    // when does ? lead out?
    // conj: ? leads out <-> all adjcaent grids are either out of bound or leads out

    // first pass.
    // initially mark every cell as a cycle 2
    // then search and mark the cells that lead out as 1

    // second pass
    // for each ? cell, check if it leads out and mark accordingly


    unordered_map<ll, ll> size, type, parent;

    function<void(ll)> make_set = [&](ll a){
        parent[a] = a;
        size[a] = 1;
    };

    function<ll(ll)> find_set = [&](ll a){
        if(parent[a] == a) return a;
        parent[a] = find_set(parent[a]);
        return parent[a];
    };

    function<void(ll, ll)> union_set = [&](ll a, ll b){
        a = find_set(a);
        b = find_set(b);
        if(size[a] < size[b]) swap(a, b); // a >= b
        size[a] += size[b];
        parent[b] = a;
    };


    unordered_set<ll> vis;


    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            ll x = (r + c)*(r + c + 1)/2 + r;
            if(vis.find(x) != vis.end()) continue;
            if(grid[r][c] == '?') continue;

            stack<vector<ll>> dfs;
            dfs.push({r, c});
            vis.insert(x);
            make_set(x);
            type[find_set(x)] = 2; // initialized to cycle(2)  

            while(dfs.size()){
                vector<ll> top = dfs.top();
                dfs.pop();

                ll cpf = (top[0] + top[1])*(top[0] + top[1] + 1)/2 + top[0];

                ll dr, dc;
                if(grid[top[0]][top[1]] == 'U'){dr = -1; dc = 0;}
                if(grid[top[0]][top[1]] == 'R'){dr = 0; dc = 1;}
                if(grid[top[0]][top[1]] == 'D'){dr = 1; dc = 0;}
                if(grid[top[0]][top[1]] == 'L'){dr = 0; dc = -1;}
                ll newr = top[0] + dr;
                ll newc = top[1] + dc;

                ll newcpf = (newr + newc)*(newr + newc + 1)/2 + newr;


                if(!(0 <= newr && newr < n && 0 <= newc && newc < m)){
                    type[find_set(cpf)] = 1;
                    continue;
                }

                if(grid[newr][newc] == '?') continue;

                if(vis.find(newcpf) != vis.end()){
                    type[find_set(cpf)] = type[find_set(newcpf)];
                    union_set(cpf, newcpf);
                    continue;
                }

                vis.insert(newcpf);
                make_set(newcpf); 
                union_set(cpf, newcpf);
                type[find_set(newcpf)] = 2;
                dfs.push({newr, newc});


            }
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(grid[r][c] != '?') continue;

            bool out = true;

            ll dr[4] = {-1, 0, 1, 0};
            ll dc[4] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                ll newr = r + dr[i];
                ll newc = c + dc[i];
                if(!(0 <= newr && newr < n && 0 <= newc && newc < m)) continue;

                if(grid[newr][newc] == '?') out = false;
                else if(type[find_set((newr + newc) * (newr + newc + 1)/2 + newr)] == 2) out = false;
            }

            ll cpf = (r + c) * (r + c + 1) / 2 + r;
            if(out){ // every adj cell is either oob or leads out
                make_set(cpf);
                type[find_set(cpf)] = 1;
            }
            else{ // exists adj cell which is cycle or ?
                make_set(cpf);
                type[find_set(cpf)] = 2;  
            }
        }
    }

    ll ans = 0;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            ll cpf = (r + c) * (r + c + 1) / 2 + r;
            ans += type[find_set(cpf)] == 2;
        }
    }

    cout << ans << '\n';









}



int main(){
    ll t; cin >> t;
    while(t--) solve();
}






























void gg(){
    // catastrophically lost


    ll n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> grid[i][j];
    }

    // directed graph
    // want to maximize nodes that end up in a cycle

    // every cell is one of
    // 1. leads out
    // 2. leads to ?
    // 3. cycle

    // some kind of dfs on adjacent ? cells? 

    map<vector<ll>, vector<ll>> parent;
    map<vector<ll>, ll> size;
    map<vector<ll>, ll> type; 

    function<void(vector<ll>)> ms = [&](vector<ll> a){
        parent[a] = a;
        size[a] = 1;
    };
    function<vector<ll>(vector<ll>)> fs = [&](vector<ll> a){
        if(parent[a] == a) return a;
        parent[a] = fs(parent[a]);
        return parent[a];
    };
    function<void(vector<ll>, vector<ll>)> us = [&](vector<ll> a, vector<ll> b){
        a = fs(a);
        b = fs(b);
        if(size[a] < size[b]) swap(a, b); // a >= b
        size[a] += size[b];
        parent[b] = a;
    };

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(vis[r][c]) continue;
            if(grid[r][c] == '?') continue;

            queue<vector<ll>> bfs; // (row, col)
            bfs.push({r, c});
            ms({r, c});
            type[fs({r, c})] = 3; // initialized to leads in

            while(bfs.size()){
                vector<ll> front = bfs.front();
                bfs.pop();
                vis[front[0]][front[1]] = true; // fact: {front[0], front[1]} is already in a dsu
                ll dc, dr;

                if(grid[front[0]][front[1]] == 'U'){dc = 0; dr = -1;};
                if(grid[front[0]][front[1]] == 'R'){dc = 1; dr = 0;};
                if(grid[front[0]][front[1]] == 'D'){dc = 0; dr = 1;};
                if(grid[front[0]][front[1]] == 'L'){dc = -1; dr = 0;};

                ll newr = front[0] + dr;
                ll newc = front[1] + dc; 

                if(!(0 <= newr && newr < n && 0 <= newc && newc < m)){ // leads out
                    type[fs({front[0], front[1]})] = 1;
                }
                else if(grid[newr][newc] == '?'){ // leads to ?
                    ms({newr, newc});
                    us({newr, newc}, {front[0], front[1]});
                    type[fs({newr, newc})] = 2;
                }
                else{ // leads to another cell
                    ms({newr, newc});
                    type[fs({newr, newc})] = type[fs({front[0], front[1]})]; 
                    us({newr, newc}, {front[0], front[1]});

                    if(!vis[newr][newc]){
                        bfs.push({newr, newc});
                        vis[newr][newc] = true; 
                    }
                }
            }
        }
    }

    for(int r = 0; r  < n; r++){
        for(int c = 0; c < m; c++){
            cout << type[fs({r, c})] << ' ';
        }
        cout << '\n';
    }






    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(grid[r][c] != '?') continue;
            if(vis[r][c]) continue;
            ms({r, c});
            type[{r, c}] = 1; // initialized to leads out

            function<void(vector<ll>)> dfs = [&](vector<ll> top){
                ll dr[4] = {1, 0, -1, 0};
                ll dc[4] = {0, 1, 0, -1};

                vis[top[0]][top[1]] = true;

                for(int i = 0; i < 4; i++){
                    ll newr = r + dr[i];
                    ll newc = c + dc[i];


                    if(!(0 <= newr && newr < n && 0 <= newc && newc < m)) continue;

                    if(grid[newr][newc] == '?'){
                        ms({newr, newc});
                        us({newr, newc}, {top[0], top[1]});
                        type[fs({newr, newc})] = 3;
                        vis[newr][newc] = true;
                        dfs({newr, newc});
                    }
                    else if(type[fs({newr, newc})] == 3 || type[fs({newr, newc})] == 2){
                        us({newr, newc}, {top[0], top[1]});
                        type[fs({newr, newc})] = 3;
                    }
                }
            };
            dfs({r, c});
        }
    }


}
