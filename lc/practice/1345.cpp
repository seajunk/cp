#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr){

    // from i, -> i + 1, i - 1, j st a[i] = a[j]

    // n <= 50000

    // bfs?

    int n = arr.size();

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < n; i++) adj[arr[i]].push_back(i); 


    vector<bool> vis(n, false);


    queue<pair<int, int>> bfs; // index, # of jumps
    bfs.push({0, 0});
    vis[0] = true;

    while(bfs.size()){
        pair<int, int> front = bfs.front();
        bfs.pop();

        if(front.first == n - 1){
            return front.second;
        }


        int nxt = front.first + 1;
        int prev = front.first - 1;

        if(0 <= nxt && nxt < n){
            if(!vis[nxt]){
                vis[nxt] = true;
                bfs.push({nxt, front.second + 1});
            }
        }
        if(0 <= prev && prev < n){
            if(!vis[prev]){
                vis[prev] = true;
                bfs.push({prev, front.second + 1});
            }
        }

        for(int neigh : adj[arr[front.first]]){
            if(neigh == front.first) continue;
            if(vis[neigh]) continue;


            vis[neigh] = true;
            bfs.push({neigh, front.second + 1});
        }

        adj.erase(arr[front.first]);
    }


    cout << "uh oh\n";
    return -1; // shit went wrong
}
