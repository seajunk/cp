#include <bits/stdc++.h>
#define ll long long
using namespace std;





int main(){
    ll n; cin >> n;
    vector<vector<ll>> adj(n);

    for(int i = 0; i < n - 1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll last;
    queue<ll> bfs;
    vector<bool> visited(n, false);
    bfs.push(0);

    while(bfs.size()){
        ll front = bfs.front();
        bfs.pop();
        last = front;
        visited[front] = true;
        for(ll neigh : adj[front]){
            if(!visited[neigh]) bfs.push(neigh);
        }
    }

    visited = vector<bool>(n, false);
    vector<ll> distance(n, 0);
    bfs.push(last);
    ll ans = 0;
    while(bfs.size()){
        ll front = bfs.front();
        bfs.pop();
        visited[front] = true;
        for(ll neigh : adj[front]){
            if(!visited[neigh]){
                distance[neigh] = distance[front] + 1;
                bfs.push(neigh);
                ans = max(ans, distance[neigh]);
            }
        }
    }

    cout << ans << '\n';








}


int attempt2(){
    ll n; cin >> n;

    vector<vector<ll>> adj(n);


    for(int i = 0; i < n - 1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    vector<ll> distance(n, 0);
    vector<bool> visited(n);

    queue<ll> bfs;
    bfs.push(0);


    while(bfs.size()){
        ll front = bfs.front();
        bfs.pop();

        for(ll neigh : adj[front]){
            if(!visited[neigh]){
                visited[neigh] = true;
                distance[neigh] = distance[front] + 1;
                bfs.push(neigh);
            }
        }
    }

    // dont acc need to sort
    sort(distance.begin(), distance.end());
    if(distance.size() == 1) cout << 0;
    else cout << distance[n - 1] + distance[n - 2] << '\n';
    return 0;
}









































int attempt1(){
    ll n; cin >> n;
    vector<vector<ll>> children(n); 
    vector<ll> height(n, 0), diameter(n, 0);
    vector<bool> visited(n, false);


    for(int i = 1; i < n; i++){
        ll a, b; cin >> a >> b; a--; b--;
        // assuming child of a is b
        children[a].push_back(b);
    }


    stack<ll> dfs;
    dfs.push(0);

    while(dfs.size()){

        ll top = dfs.top();


        ll finished = true;
        for(ll child : children[top]) if(!visited[child]) finished = false; 


        if(finished){
            for(ll child : children[top]) height[top] = max(height[top], height[child] + 1);
            for(ll child : children[top]) diameter[top] += height[child] + 1;
            for(ll child : children[top]) diameter[top] = max(diameter[top], diameter[child]);
            visited[top] = true;
            dfs.pop();
        }
        else{
            for(ll child: children[top]) if(!visited[child]) dfs.push(child);
        }




    }

    cout << diameter[0] << '\n';








    return 0;
}
