#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

// tree size;
vector<int> ts;

// subtree distance sum
vector<int> sds;

// distance sum
vector<int> ds;


// calculate ts of each subtree rooted at 0
void dfs1(int curr, int parent){
    ts[curr] = 1;

    for(int child : adj[curr]){
        if(child != parent){
            dfs1(child, curr);

            ts[curr] += ts[child];
        }
    }
}


// calculate sum of distance of subtrees for each subtree rooted at 0
void dfs2(int curr, int parent){
    sds[curr] = 0;
    // sds[curr] = sds[children] + ts[children] (?)

    for(int child : adj[curr]){
        if(child != parent){
            dfs2(child, curr);
            sds[curr] += sds[child] + ts[child];
        }
    }
}

// calculate ds with rerooting
void dfs3(int curr, int parent, int n){

    // ds[curr] = n + ds[p] - 2*ts[curr];

    ds[curr] = n + ds[parent] - 2 * ts[curr];
    for(int child : adj[curr]){
        if(child != parent){
            dfs3(child, curr, n);
        }
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    adj = vector<vector<int>>(n);

    for(vector<int> edge : edges){
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ts = vector<int>(n, 0);
    sds = vector<int>(n, 0);
    ds = vector<int>(n, 0);

    dfs1(0, -1);
    dfs2(0, -1);
    ds[0] = sds[0];
    for(int child : adj[0]){
        dfs3(child, 0, n);
    }

    return ds;

}

int main(){
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}};
    int n = 8;

    vector<int> ans = sumOfDistancesInTree(n, edges);

    for(int e : ans) cout << e << ' ';
    cout << '\n';


}

