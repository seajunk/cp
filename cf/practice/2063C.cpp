#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<set<ll>> adj(n);

    for(int i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v;
        //u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }


    // c: vertex v -> ccc += #edge of v - 1. call this value of v
    // c: if removing vertex v, value of each of v's neighbours decreases by 1

    // choose max degree vertex v st the degree of graph after removing v is maximized

    // want dp[i] = degree of graph after i is removed




    // if we have degree[j], dp[j], for children j of i,

    // if dp[j] == degree[j] then j there exists max degree node in tree rooted at j that isnt j
    // then the degree of tree at j shouldnt change after removing i ie = degree[j]

    // if dp[j] != degree[j] then j is only max degree node in the tree j
    // then the degree of tree at j should change after removing i ie = degree[j] - 1 (minus 1 for the edge to i that was lost)

    // dp[i] = max among the above value for each child j

    ll root = 0; // arbitrary
    
    // degree[i] = 
    // for child j of i 
    // count = if(# of edge of j == degree[j]) degree[j] + 1 else degree[j]

    vector<ll> degree(n, -1);
    vector<ll> parent(n);
    vector<set<ll>> children(n);

    {
        parent[0] = -1; // root
        vector<bool> seen(n, false);
        stack<ll> dfs;
        dfs.push(0);
        seen[0] = true;
        while(dfs.size()){
            ll top = dfs.top();
            dfs.pop();
            for(ll child : adj[top]){
                if(seen[child]) continue;
                seen[child] = true;
                children[top].insert(child);
                parent[child] = top;
                dfs.push(child);
            }
        }
    }


    function<void(ll)> dfs = [&](ll node){
        if(children[node].size() == 0){
            degree[node] = 0;
            return;
        }

        ll mx = LLONG_MIN;
        for(ll child : children[node]){
            dfs(child);
            ll count = (children[child].size() == degree[child]) ? degree[child] + 1 : degree[child];
            mx = max(mx, count);
        }
        mx = max(mx, (ll)children[node].size());
        degree[node] = mx;
    };
    dfs(0);

    //for(int i = 0; i < n; i++) printf("degree tree rooted at %d = %lld\n", i, degree[i]);
    //for(int i = 0; i < n; i++) printf("parent of %d = %lld\n", i, parent[i]);


    vector<ll> dp(n); // max degree in graph after node i and its edges are removed
}

void solve2(){
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> degrees;

    for(int i = 0; i < n; i++) degrees.push_back(adj[i].size());
    sort(degrees.begin(), degrees.end());

    ll mx = degrees[n - 1];
    ll smx = degrees[n - 2];


    map<ll, vector<ll>> mxNeighCnt;
    ll smxcnt = 0;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == smx) smxcnt += 1;
        if(adj[i].size() == mx){
            mxNeighCnt[i] = {};
            for(ll neigh : adj[i]){
                if(adj[neigh].size() == smx) mxNeighCnt[i].push_back(neigh);
            }
        }
    }

    // mxNeighCnt[i] -> i has mx degree and mxNeighCnt[i] is vector of its neighbours with smx degree
    // ans = mx - 1 + smx - 1, if exists i st mxNeighCnt[i].size() != smxcnt Else, 
    // ans = mx - 1 + sms - 1 - 1

    bool higher = false;
    if(mx != smx){
        for(int i = 0; i < n; i++){
            if(mxNeighCnt.find(i) != mxNeighCnt.end()){
                if(mxNeighCnt[i].size() != smxcnt) higher = true;
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(mxNeighCnt.find(i) != mxNeighCnt.end()){
                if(mxNeighCnt[i].size() != smxcnt - 1) higher = true;
            }
        }
    }

    //printf("mx = %lld, smx = %lld\n", mx, smx);
    //printf("higher = %d\n", higher);

    ll ans = 1 + mx - 1 + smx - 1;

    if(!higher) ans -= 1;

    cout << ans << '\n';









    // sort nodes by degree, need to maximize sum of (degree - 1) two nodes with caveat that if two nodes are connected, then sum gets reduced by 1(?) from the lost edge between u and v where u and v are the deleted nodes. 

    // ans will always be either (highest deg - 1 + second higheset deg - 1) or (highest deg - 1 + second higheset deg - 1 - 1)

    // first case if there exist two nodes u v with deg(u) = highest, deg(v) = second highest and two arent connected
    // second case if not first case 

    // ie we want to find if there exist u and v st first case





}


int main(){
    ll t; cin >> t;
    while(t--) solve2();
}
