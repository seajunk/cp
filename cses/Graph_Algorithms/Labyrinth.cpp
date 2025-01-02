#include <bits/stdc++.h>
#define ll long long
using namespace std;


bool inrange(ll r, ll c, ll n, ll m){
    return (0 <= r && r < n) && (0 <= c && c < m);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<ll> start, end;
    char grid[n][m];
    for(ll r = 0; r < n; r++){
        for(ll c = 0; c < m; c++){
            cin >> grid[r][c];
            if(grid[r][c] == 'A') start = {r, c};
            else if(grid[r][c] == 'B') end = {r, c};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<vector<ll>, vector<char>>> bfs;
    bfs.push({start, {}});
    visited[start[0]][start[1]] = true;

    while(bfs.size()){
        vector<ll> coord = bfs.front().first;
        vector<char> path = bfs.front().second;
        bfs.pop();

        if(coord == end){
            cout << "YES\n";
            cout << path.size() << '\n';
            for(char c : path) cout << c;
            cout << '\n';
            return 0;
        }

        map<ll, char> direction;
        direction[0] = 'U';
        direction[1] = 'L';
        direction[2] = 'D';
        direction[3] = 'R';

        for(int d = 0; d < 4; d++){
            vector<ll> nxt_coord = {coord[0] + (d == 2) - (d == 0), coord[1] + (d == 3) - (d == 1)};
            if(inrange(nxt_coord[0], nxt_coord[1], n, m) && !visited[nxt_coord[0]][nxt_coord[1]] && grid[nxt_coord[0]][nxt_coord[1]] != '#'){
                vector<char> nxt_path = path;
                nxt_path.push_back(direction[d]);
                visited[nxt_coord[0]][nxt_coord[1]] = true;
                bfs.push({nxt_coord, nxt_path});
            }
        }
    }
    cout << "NO\n";
}




