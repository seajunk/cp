#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    map<set<ll>, ll> idx;
    vector<ll> dp(n, -1);
    dp[0] = 1;

    for(ll i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        idx[{u, v}] = i;
    }

    stack<ll> dfs;
    vector<bool> visited(n, false);
    visited[0] = true;
    dfs.push(0);
    vector<ll> earliest(n, LLONG_MAX);
    earliest[0] = -1;

    while(dfs.size()){
        ll top = dfs.top();
        dfs.pop();

        for(ll neigh : adj[top]){
            if(visited[neigh]) continue;
            visited[neigh] = true;

            ll u = top, v = neigh;
            ll i = idx[{u, v}];

            earliest[v] = i;
            if(i >= earliest[u]) dp[v] = dp[u] + 1; 
            else dp[v] = dp[u]; 

            dfs.push(neigh);
        }
    }

    ll ans = LLONG_MIN;

    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
