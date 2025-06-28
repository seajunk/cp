#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll n, ll k){
    return (n % k + k) % k;
}


void solve(){
    ll n, m; cin >> n >> m;

    /*
       n x m

       ans <= m
       ans <= n + 1

       3 4

       3 0 1 2
       2 3 0 1
       1 2 3 0

       0 1 2 3

       4 3
       2 0 1 
       1 2 0
       1 2 0
       1 2 0

       0 1 2






    */

    vector<vector<ll>> ans(n, vector<ll>(m));
    ll temp[m];

    for(int i = 0; i < m; i++) temp[i] = i; // 0 1 2 3 ... m


    for(int r = 0; r < min(n, m - 1); r++){
        for(int c = 0; c < m; c++){
            ans[r][c] = temp[mod((c - (r + 1)), m)];
        }
    }


    for(int r = min(n, m - 1); r < n; r++){
        for(int c = 0; c < m; c++){
            ans[r][c] = temp[mod((c - (min(n, m - 1))), m)];
        }
    }

    if(m == 1) cout << 0 << '\n';
    else cout << min(n + 1, m) << '\n';

    for(auto r : ans){
        for(auto c : r) cout << c << ' ';
        cout << '\n';
    }









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
