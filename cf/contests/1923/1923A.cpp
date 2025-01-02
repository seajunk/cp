#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = LLONG_MAX;
    stack<pair<vector<ll>, ll>> dfs; // array, depth
    dfs.push({a, 0});
    while(dfs.size()){
        vector<ll> state = dfs.top().first;
        ll curr = dfs.top().second;
        dfs.pop();

        bool valid = true;

        bool finished = false;
        for(int i = 1; i < n; i++){
            if(finished && state[i] == 1) valid = false;
            if(state[i - 1] == 1 && state[i] == 0) finished = true;
        }

        if(valid) ans = min(curr, ans);
        else{
            for(int i = 0; i < n; i++){
                if(state[i] == 1){
                    for(int j = i - 1; j >= 0; j--){
                        if(state[j] == 0){
                            vector<ll> next = state;
                            next[i] = 0;
                            next[j] = 1;
                            dfs.push({next, curr + 1});
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
