#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    ll h[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    ll dp[n];
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for(int i = 2; i < n; i++){
        dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
    }
    cout << dp[n - 1] << '\n';
}

