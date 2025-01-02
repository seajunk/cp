#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2)); // value, index
    for(int i = 0; i < n; i++){
        cin >> a[i][0];
        a[i][1] = i;
    }

    sort(a.begin(), a.end(), [](auto l, auto r){
            return l[0] < r[0];
            });

    ll pfs[n + 1];
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = a[i - 1][0] + pfs[i - 1];

    vector<vector<ll>> dp(n, vector<ll>(2));

    dp[n - 1][0] = pfs[n];
    dp[n - 1][1] = n - 1;

    for(int i = n - 2; i >= 0; i--){
        if(pfs[i + 1] >= a[i + 1][0]){
            dp[i][0] = dp[i + 1][0];
            dp[i][1] = dp[i + 1][1];
        }
        else{
            dp[i][0] = pfs[i + 1];
            dp[i][1] = i;
        }
    }

    vector<ll> ans(n);
    for(int i = 0; i < n; i++){
        ans[a[i][1]] = dp[i][1];
    }

    for(ll e : ans) cout << e << ' ';
    cout << '\n';











}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

