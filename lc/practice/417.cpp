#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<vector<vector<int>>>> adj(n, vector<vector<vector<int>>>(m));


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int di[4] = {-1, 0, 1, 0};
            int dj[4] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int newi = i + di[k];
                int newj = j + dj[k];
                if(!(0 <= newi && newi < n && 0 <= newj && newj < m)) continue;
                if(heights[newi][newj] >= heights[i][j]) adj[i][j].push_back({newi, newj});
                if(heights[i][j] >= heights[newi][newj]) adj[newi][newj].push_back({i, j});
            }
        }
    }


    vector<vector<bool>> atlantic(n, vector<bool>(m, false)), pacific(n, vector<bool>(m, false));

    // left, pacific
    for(int i = 0; i < n; i++){
        if(pacific[i][0]) continue;
        pacific[i][0] = true;

        stack<vector<int>> dfs;
        dfs.push({i, 0});
        while(dfs.size()){
            vector<int> top = dfs.top();
            dfs.pop();

            for(auto neigh : adj[top[0]][top[1]]){
                if(pacific[neigh[0]][neigh[1]]) continue;
                pacific[neigh[0]][neigh[1]] = true;
                dfs.push(neigh);
            }
        }
    }

    // up, pacific
    for(int j = 0; j < m; j++){
        if(pacific[0][j]) continue;
        pacific[0][j] = true;

        stack<vector<int>> dfs;
        dfs.push({0, j});
        while(dfs.size()){
            vector<int> top = dfs.top();
            dfs.pop();

            for(auto neigh : adj[top[0]][top[1]]){
                if(pacific[neigh[0]][neigh[1]]) continue;
                pacific[neigh[0]][neigh[1]] = true;
                dfs.push(neigh);
            }
        }
    }


    // right, atlantic
    for(int i = 0; i < n; i++){
        if(atlantic[i][m - 1]) continue;
        atlantic[i][m - 1] = true;

        stack<vector<int>> dfs;
        dfs.push({i, m - 1});
        while(dfs.size()){
            vector<int> top = dfs.top();
            dfs.pop();

            for(auto neigh : adj[top[0]][top[1]]){
                if(atlantic[neigh[0]][neigh[1]]) continue;
                atlantic[neigh[0]][neigh[1]] = true;
                dfs.push(neigh);
            }
        }
    }

    // down, atlantic
    for(int j = 0; j < m; j++){
        if(atlantic[n - 1][j]) continue;
        atlantic[n - 1][j] = true;

        stack<vector<int>> dfs;
        dfs.push({0, j});
        while(dfs.size()){
            vector<int> top = dfs.top();
            dfs.pop();

            for(auto neigh : adj[top[0]][top[1]]){
                if(atlantic[neigh[0]][neigh[1]]) continue;
                atlantic[neigh[0]][neigh[1]] = true;
                dfs.push(neigh);
            }
        }
    }


    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(atlantic[i][j] && pacific[i][j]) ans.push_back({i, j});
        }
    }




    return ans;
}
