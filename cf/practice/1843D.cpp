#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(){
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<ll> parent(n);
    vector<ll> size(n);

    function<void(ll)> make_set = [&](ll a){
        parent[a] = a;
        size[a] = 1;
    };
    function<ll(ll)> find_set = [&](ll a){
        if(a == parent[a]) return a;
        ll leader = find_set(parent[a]);
        parent[a] = leader;
        return leader;
    };
    function<void(ll, ll)> union_set = [&](ll a, ll b){
        a = find_set(a);
        b = find_set(b);
        if(a == b) return;
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    };


    vector<vector<ll>> children(n);

    {
        stack<pair<ll, ll>> dfs;
        vector<bool> seen(n, false);
        dfs.push({0, -1});
        while(dfs.size()){
            pair<ll, ll> top = dfs.top();
            dfs.pop();
            for(ll child : adj[top.first]){
                if(child == top.second) continue;
                seen[child] = true;
                children[top.first].push_back(child);
                dfs.push({child, top.first});
            }
        }
    }


    
    stack<ll> dfs;
    vector<bool> seen(n, false);
    vector<ll> leafcnt(n);

    dfs.push(0);
    while(dfs.size()){
        ll top = dfs.top();
        bool finished = true;
        for(ll child : children[top]){
            finished &= seen[child];
        }
        if(!finished){
            for(ll child : children[top]){
                if(!seen[child]) dfs.push(child);
            }
        }
        else{
            seen[top] = true;
            dfs.pop();
            if(children[top].size() == 0){
                leafcnt[top] = 1;
            }
            else{
                leafcnt[top] = 0;
                for(ll child : children[top]){
                    leafcnt[top] += leafcnt[child];
                }
            }
        }
    }



















    ll q; cin >> q;

    for(int i = 0; i < q; i++){
        ll x, y; cin >> x >> y;
        x--; y--;
        cout << leafcnt[x] * leafcnt[y] << '\n';

    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
