#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){


    // 0 2 3
    // 0 0 0
    // 3 1 0

    // 5 0 4
    // 3 3 3 


    ll n, m; cin >> n >> m;

    ll a[n][m];
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++) cin >> a[r][c];
    }


    vector<vector<ll>> path;

    stack<vector<ll>> dfs;
    vector<vector<bool>> seen;
    dfs.push({0, 0});
    ll dr[4] = {-1, 0, 1, 0};
    ll dc[4] = {0, 1, 0, -1};

    while(dfs.size()){
        vector<ll> top = dfs.top();


        bool finished = true;

        for(int i = 0; i < 4; i++){
            ll newr = top[0] + dr[i];
            ll newc = top[1] + dc[i];
            if(!(0 <= newr && newr <= n && 0 <= newc && newc <= m)) continue;
            if(!seen[newr][newc]) finished = false;
        }


        if(finished){
            dfs.pop();
            seen[top[0]][top[1]] = true;
            path.push_back(top);
        }
        else{
            for(int i = 0; i < 4; i++){
                ll newr = top[0] + dr[i];
                ll newc = top[1] + dc[i];
                if(!(0 <= newr && newr <= n && 0 <= newc && newc <= m)) continue;
                if(seen[newr][newc]) continue;
                if(a[newr][newc] != 0) continue;
                dfs.push({newr, newc});
            }
        }
    }



    // dp

    ll dp[n];


    // 0 1 0 2 3
    // 0 0 0 0 0
    // -1 0 -3 -3 0
    // 0 0 0 -1 0

    // 0 7 6 


    

    








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
