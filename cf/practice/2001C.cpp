#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    set<vector<ll>> edges;
    set<vector<ll>> seen;
    stack<vector<ll>> dfs;
    for(int i = n; i >= 2; i--){
        vector<ll> in = {1, i};
        dfs.push(in);
    }
    while(dfs.size()){
        vector<ll> top = dfs.top();
        dfs.pop();
        seen.insert(top);
        seen.insert({top[1], top[0]});
        cout << "? " << top[0] << ' ' << top[1] << '\n';
        ll in; cin >> in;
        if(in == top[0]){
            edges.insert({top[0], top[1]});
        }
        else{
            if(seen.find({top[0], in}) == seen.end()) dfs.push({top[0], in});
            if(seen.find({top[1], in}) == seen.end()) dfs.push({top[1], in});
        }
    }
    cout << "!\n";
    for(vector<ll> e : edges){
        cout << e[0] << ' ' << e[1] << '\n';
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
