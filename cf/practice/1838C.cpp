#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    // 3 1 4 2

    vector<vector<ll>> ans(n, vector<ll>(m));

    ll i = 1;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            ans[r][c] = i;
            i++;
        }
    }

    // print all the even rows in decreasing order
    for(int r = 2*((n - 1)/2); r >= 0; r -= 2){
        for(ll e : ans[r]) cout << e << ' ';
        cout << '\n';
    }
    
    // print all the odd rows in decreasing order
    for(int r = 2*((n)/2) - 1; r >= 0; r -= 2){
        for(ll e : ans[r]) cout << e << ' ';
        cout << '\n';
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
