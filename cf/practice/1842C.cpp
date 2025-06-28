#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       in one operation we can choose distinct indicies i, j st a[i] == a[j] and remove elements in interval [i, j]

       want minimum size of a after any number of operations



       dp[i] = min size achivable on array [0, i)
       dp[i] = min(dp[i - 1] + 1, dp[j] for all j < i - 1 st a[i - 1] = a[j]) 
       mn[x] = min {dp[j] : a[j] = x} 
    */


    ll dp[n + 1];
    dp[0] = 0; 
    vector<ll> mn(n + 1, LLONG_MAX);


    for(int i = 1; i <= n; i++){
        dp[i] = min(dp[i - 1] + 1, mn[a[i - 1]]);
        mn[a[i - 1]] = min(mn[a[i - 1]], dp[i - 1]);
    }

    cout << n - dp[n] << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
