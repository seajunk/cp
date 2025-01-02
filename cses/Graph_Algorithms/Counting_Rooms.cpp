#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    ll n, m; cin >> n >> m;
    char grid[n][m];
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> grid[r][c];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    ll cnt = 0;

    for(ll r = 0; r < n; r++){
        for(ll c = 0; c < m; c++){
            if(visited[r][c]) continue;
            if(grid[r][c] != '.') continue;

            cnt++;

            queue<vector<ll>> bfs;
            bfs.push({r, c});
            visited[r][c] = true;
            while(bfs.size()){
                vector<ll> front = bfs.front();
                bfs.pop();
                ll R = front[0], C = front[1];

                vector<vector<ll>> temp = {{R - 1, C}, {R + 1, C}, {R, C - 1}, {R, C + 1}};
                for(vector<ll> t : temp){
                    R = t[0];
                    C = t[1];
                    if(0 <= R && R <= n - 1 && 0 <= C && C <= m - 1 && !visited[R][C] && grid[R][C] == '.'){
                        visited[R][C] = true;
                        bfs.push({R, C});
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}
