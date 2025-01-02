#include <bits/stdc++.h>
using namespace std;

int uniquePathsIII(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    // grid size <= 20
    // turbo brute force possible?
    // upperbound 4^20 = 2^40 ~= 10^12 

    stack<pair<vector<int>, vector<vector<bool>>>> dfs; // r, c, count, vis

    vector<int> start(2);
    int needed = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(grid[r][c] == 0) needed++;
            if(grid[r][c] == 1) start = {r, c};
        } 
    }

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[start[0]][start[1]] = true;
    dfs.push({{start[0], start[1], 0}, vis});


    while(dfs.size()){
        pair<vector<int>, vector<vector<bool>>> top = dfs.top();
        dfs.pop();

        int r = top.first[0];
        int c = top.first[1];
        int count = top.first[2];




        vector<vector<bool>> oldvis = top.second;


        for(int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];

            if(!((0 <= newr) && (newr < n) && (0 <= newc) && (newc < m))) continue;
            if(oldvis[newr][newc]) continue;
            if(grid[newr][newc] == -1)  continue;
            if(grid[newr][newc] == 2){
                if(count == needed) ans++;
                continue;
            }

            // can this be better?
            vector<vector<bool>> newvis = oldvis;
            newvis[newr][newc] = true;
            dfs.push({{newr, newc, count + 1}, newvis});
        }
    }

    return ans;





}




int main(){
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    cout << uniquePathsIII(grid) << '\n';;
}

