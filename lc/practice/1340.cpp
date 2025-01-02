#include <bits/stdc++.h>
using namespace std;

int maxJumps(vector<int> &arr, int d){

    int n = arr.size();
    vector<vector<int>> children(n), parents(n);



    /*
    for(int i = 0; i < n; i++){
        int mx = INT_MIN; // max on [i + 1, j)
        for(int j = i + 1; j <= min(i + d, n - 1); j++){
            if(mx >= arr[i]) break;
            if(arr[i] > arr[j]){
                parents[j].push_back(i);
                children[i].push_back(j);
            }
            mx = max(mx, arr[j]);
        }
        mx = INT_MIN; // max on (j, i - 1]
        for(int j = i - 1; j >= max(0, i - d); j--){ 
            if(mx >= arr[i]) break;
            if(arr[i] > arr[j]){
                parents[j].push_back(i);
                children[i].push_back(j);
            }
            mx = max(mx, arr[j]);
        }
    }
    */
    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        if(s.size() == 0){
            s.push({i, arr[i]});
        }
        else{
            while(s.size() && s.top().second <= arr[i]) s.pop();
            if(s.size() != 0 && abs(s.top().first - i) <= d){
                parents[i].push_back(s.top().first);
                children[s.top().first].push_back(i);
            }
            s.push({i, arr[i]});
        }
    }

    while(s.size()) s.pop();

    for(int i = n - 1; i >= 0; i--){
        if(s.size() == 0){
            s.push({i, arr[i]});
        }
        else{
            while(s.size() && s.top().second <= arr[i]) s.pop();
            if(s.size() != 0 && abs(s.top().first - i) <= d){
                parents[i].push_back(s.top().first);
                children[s.top().first].push_back(i);
            }
            s.push({i, arr[i]});
        }
    }

    


    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int parent : parents[i]) cout << parent << ' ';
        cout << '\n';
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int child : children[i]) cout << child << ' ';
        cout << '\n';
    }
    cout << '\n';

    vector<int> roots;

    vector<bool> vis(n, false);

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;


        stack<int> dfs; 
        dfs.push(i);
        vis[i] = true;

        while(dfs.size()){
            int top = dfs.top();
            dfs.pop();

            if(parents[top].size() == 0) roots.push_back(top);


            for(int parent : parents[top]){
                if(vis[parent]) continue;
                vis[parent] = true;
                dfs.push(parent);
            }
        }
    }


    for(int root : roots) cout << root << ' ';
    cout << '\n';





    for(int i = 0; i < n; i++) vis[i] = false;

    int ans = 0;

    vector<int> mxjump(n, -1);

    for(int root : roots){
        if(vis[root]) continue;


        stack<int> dfs2;

        dfs2.push(root); // index, # of nodes in path
        vis[root] = true;

        while(dfs2.size()){
            int top = dfs2.top();
            
            bool finished = true;

            for(int child : children[top]){
                if(!vis[child]) finished = false;
            }

            if(finished){
                mxjump[top] = 1;
                int add = 0;
                for(int child : children[top]) add = max(add, mxjump[child]);
                mxjump[top] += add;
                vis[top] = true;
                dfs2.pop();
                ans = max(ans, mxjump[top]);
            }
            else{
                for(int child : children[top]) dfs2.push(child);
            }
        }
    }
    return ans;
}



















int main(){

    vector<int> arr = {3, 3, 3, 3, 3};
    cout << maxJumps(arr, 3) << '\n';

}
int maxJumpsold(vector<int> &arr, int d){
    int n = arr.size();

    int temp = n;
    int k = 0; // msb of n
    while(temp > 1){
        temp /= 2;
        k++;
    }

    vector<vector<int>> st(k + 1, vector<int>(n, -1)); // sparse table

    for(int i = 0; i < n; i++) st[0][i] = arr[i];

    for(int i = 1; i <= k; i++){
        for(int j = 0; j + (1 << i) - 1 < n; j++){
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    
    int lgt[n + 1]; // log table
    lgt[1] = 0;
    for(int i = 2; i <= n; i++){
        lgt[i] = lgt[i/2] + 1;
    }


    vector<vector<int>> children(n);

    for(int i = 0; i < n; i++){

        // check each j in [i + 1, min(n - 1, i + d)] that we can jump to from i
        for(int j = i + 1; (j < n) && (j <= (i + d)); j++){
            // check max in [i + 1, j]
            int l = i + 1, r = j;
            int lg = lgt[r - l + 1];  
            int mx = max(st[lg][l], st[lg][r - (1 << lg) + 1]);
            if(mx < arr[i]) children[i].push_back(j);
        }
        // check each j in [max(0, i - d) , i - 1] that we can jump to from i
        for(int j = i - 1; (j >= 0) && (j >= (i - d)); j--){
            // check max in [j, i - 1]
            int r = i - 1, l = j;
            int lg = lgt[r - l + 1];  
            int mx = max(st[lg][l], st[lg][r - (1 << lg) + 1]);
            if(mx < arr[i]) children[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int e : children[i]) cout << e << ' '; 
        cout << '\n';
    }


    // ans[parent] = 1 + max(ans[children]) ? 

    vector<int> mx_jump(n);
    vector<bool> vis(n, false);

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;



        stack<int> dfs;
        dfs.push(i);

        while(dfs.size()){

            bool finished = true;

            for(int child : children[dfs.top()]) if(!vis[child]) finished = false;

            if(finished){
                mx_jump[dfs.top()] = 1;
                int temp = 0;
                for(int child : children[dfs.top()]) temp = max(temp, mx_jump[child]);
                mx_jump[dfs.top()] += temp;
                vis[dfs.top()] = true;
                dfs.pop();
            }
            else{
                for(int child : children[dfs.top()]){
                    if(!vis[child]) dfs.push(child);
                }
            }
        }
    }

    int ans = -1;

    for(int i = 0; i < n; i++) ans = max(ans, mx_jump[i]);

    return ans;
}
