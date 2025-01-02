#include <bits/stdc++.h>
using namespace std;

/*
   generates powerset of {0, 1, 3, ..., n - 1}
*/
vector<vector<int>> genereatePowerset(int n){
    vector<vector<int>> ans;

    queue<pair<vector<int>, int>> bfs;
    bfs.push({{}, 0});

    while(bfs.size()){
        pair<vector<int>, int> front = bfs.front();
        bfs.pop();

        ans.push_back(front.first);



        for(int i = front.second; i < n; i++){
            vector<int> nxt = front.first;
            nxt.push_back(i);
            bfs.push({nxt, i + 1});
        }
    }
    return ans;
}

vector<int> countSubgraphForEachDiameter(int n, vector<vector<int>> &edges){

    vector<vector<int>> adj(n);
    for(vector<int> edge : edges){
        int u = edge[0], v = edge[1];
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> powerset = genereatePowerset(n);
    int diameter = INT_MIN;


    unordered_map<int, int> cnt;

    for(vector<int> subset : powerset){
        if(subset.size() < 2) continue;

        vector<bool> vis(n, true);
        for(int e : subset) vis[e] = false;
        bool connected = true;

        int lastseen;

        // check if subset of cities is connected
        for(int i = 0; i < subset.size(); i++){
            if(vis[subset[i]]) continue;

            if(i > 0){
                connected = false;
                break;
            }

            queue<int> bfs;
            bfs.push(subset[i]);
            vis[subset[i]] = true;

            while(bfs.size()){
                int front = bfs.front();
                bfs.pop();
                lastseen = front;

                for(int neigh : adj[front]){
                    if(vis[neigh]) continue;
                    vis[neigh] = true;
                    bfs.push(neigh);
                }
            }
        }
        if(!connected) continue;

        // second bfs to find diameter
        vector<bool> vis2(n, true);
        for(int e : subset) vis2[e] = false;
        vis2[lastseen] = true;
        queue<pair<int, int>> bfs2;
        bfs2.push({lastseen, -1}); // node, depth
        int curr_diameter = -1;


        while(bfs2.size()){
            pair<int, int> front = bfs2.front();
            bfs2.pop();

            curr_diameter = max(curr_diameter, front.second + 1);


            for(int neigh : adj[front.first]){
                if(vis2[neigh]) continue;
                vis2[neigh] = true;
                bfs2.push({neigh, front.second + 1});
            }
        }


        diameter = max(diameter, curr_diameter);
        if(cnt.find(curr_diameter) == cnt.end()) cnt[curr_diameter] = 1;
        else cnt[curr_diameter]++;
    }


    vector<int> ans;
    for(int i = 1; i <= n - 1; i++){
        if(cnt.find(i) == cnt.end()) ans.push_back(0);
        else ans.push_back(cnt[i]);
    } 

    return ans;
}

int main(){
    vector<vector<int>> edges ={{1, 2}, {2, 3}, {2, 4}};
    vector<int> ans = countSubgraphForEachDiameter(4, edges);

    for(int e : ans) cout << e << ' ';
    cout << '\n';


}
