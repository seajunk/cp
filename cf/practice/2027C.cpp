#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    set<ll> nodes;
    map<ll, set<ll>> adj;


    // 2 4 6 2 5 
    // 2 < 5 cant
    // needs 0, adds 1
    // needs 3, adds 2
    // needs 0, adds 3 
    // needs 4, adds 4

    // 0 -> 1
    // 0 -> 3
    // 3 -> 5
    // 4 -> 8
    

    // 5 4 4 5 1
    // needs 0 adds 0
    // needs 0 adds 1
    // needs 1 adds 2
    // needs 3 adds 3
    // cant

    // 0 -> 0
    // 0 -> 1
    // 1 -> 3
    // 3 -> 6


    for(int i = 0; i < n; i++){
        if(a[i] < (n - i)) continue;

        adj[a[i] - (n - i)].insert(a[i] - (n - i) + i);
        nodes.insert(a[i] - (n - i));
        nodes.insert(a[i] - (n - i) + i);
    }

    ll mx = 0;


    set<ll> visited;

    queue<ll> bfs;

    bfs.push(0);
    visited.insert(0);

    while(bfs.size()){
        ll front = bfs.front();
        bfs.pop();
        mx = max(mx, front);
        
        for(ll neigh : adj[front]){
            if(visited.find(neigh) == visited.end()){
                visited.insert(neigh);
                bfs.push(neigh);
            }
        }
    }


    cout << n + mx << '\n';



}


































void solve1(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 2 4 6 2 5 
    // 2 < 5 cant
    // needs 0, adds 1
    // needs 3, adds 2
    // needs 0, adds 3 
    // needs 4, adds 4

    // 0 -> 1
    // 0 -> 3
    // 3 -> 5
    // 4 -> 8
    

    // 5 4 4 5 1
    // needs 0 adds 0
    // needs 0 adds 1
    // needs 1 adds 2
    // needs 3 adds 3
    // cant

    // 0 -> 0
    // 0 -> 1
    // 1 -> 3
    // 3 -> 6



    
    unordered_map<ll, vector<ll>> m; // needs, makes/id


    for(int i = 0; i < n; i++){
        if(a[i] < n - i) continue;

        m[a[i] - (n - i)].push_back(i);

    }


    stack<pair<ll, ll>> dfs; // makes, curr
    unordered_set<ll> visited;

    for(ll makes : m[0]){
        dfs.push({makes, 0});
        visited.insert(makes);
    }

    ll ans = 0;
    while(dfs.size()){
        pair<ll, ll> top = dfs.top();
        dfs.pop();
        ll curr = top.first + top.second;
        cout << curr << '\n';
        ans = max(curr, ans);

        if(m.find(curr) != m.end()){
            for(ll makes : m[curr]){
                if(visited.find(makes) == visited.end()){
                    visited.insert(makes);
                    dfs.push({makes, curr});
                }
            }
        }
    }

    cout << n + ans << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
