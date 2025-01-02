#include <bits/stdc++.h>
using namespace std;





int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time){

    vector<vector<int>> children (n);
    vector<vector<int>> parent (n);



    for(vector<int> edge : relations){
        int prev = edge[0], nxt = edge[1];
        prev--; nxt--;
        children[prev].push_back(nxt);
        parent[nxt].push_back(prev);
    }


    vector<int> terminal;
    for(int i = 0; i < n; i++){
        if(children[i].size() == 0) terminal.push_back(i);
    }

    // time needed for course 
    vector<int> tn(n);
    vector<bool> vis (n, false);

    for(int t : terminal){
        if(vis[t]) continue;

        stack<int> dfs;
        dfs.push(t);

        while(dfs.size()){
            bool valid = true;
            for(int p : parent[dfs.top()]){
                if(!vis[p]) valid = false;
            }


            if(valid){
                int mx = 0;

                for(int p : parent[dfs.top()]){
                    mx = max(mx, tn[p]);
                }

                tn[dfs.top()] = time[dfs.top()] + mx;
                vis[dfs.top()] = true;
                dfs.pop();
            }
            else{
                for(int p : parent[dfs.top()]){
                    if(vis[p]) continue;
                    dfs.push(p);
                }
            }
        }
    }


    int ans = -1;

    for(int t : terminal) ans = max(ans, tn[t]);

    return ans;






}

int main(){
    vector<vector<int>> edges =  {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> times = {1, 2, 3, 4, 5};

    cout << minimumTime(5, edges, times) << '\n';



}
