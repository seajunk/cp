#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // conj: opt[i] = max(include a[i] in opt[i + 1], exclude a[i] in opt[i + 1])
    // conj: dp works going right to left but not left to right

    ll sfs[n + 1];
    sfs[n] = 0;
    for(int i = n - 1; i >= 0; i--) sfs[i] = sfs[i + 1] + a[i];

    ll dp[n + 1]; // dp[i] = optimal value for subarray [i, n)
    dp[n] = 0;

    for(int i = n - 1; i >= 0; i--){
        dp[i] = max(a[i] + dp[i + 1] + sfs[i + 1], dp[i + 1] + a[i]);
    }

    for(ll e : dp) cout << e << ' ';
    cout << '\n';






    



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
