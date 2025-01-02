#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    ll dp[n];

    sort(a, a + n);


    dp[0] = (a[0] == 1) ? 2 : 1;


    for(int i = 1; i < n; i++){
        if(a[i] <= dp[i - 1]) dp[i] = dp[i - 1] + a[i];
        else dp[i] = dp[i - 1];
    }

    cout << dp[n - 1] << '\n';


}
