#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k; cin >> n >> k;
    ll h[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    ll dp[n];
    dp[0] = 0;
    for(int i = 1; i < min(n, k); i++){
        dp[i] = abs(h[0] - h[i]);
    }

    for(int i = min(n, k); i < n; i++){
        ll mn = LLONG_MAX;
        for(int j = 1; j <= k; j++){
            mn = min(abs(h[i] - h[i - j]) + dp[i - j], mn);
        }
        dp[i] = mn;
    }
    cout << dp[n - 1] << '\n';
}
