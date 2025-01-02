#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve2(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(n % 2 == 0){
            ans = max(ans, a[i] + n / 2);
        }
        else{
            if(i % 2 == 0){
                ans = max(ans, a[i] + n/2 + 1);
            }
            else{
                ans = max(ans, a[i] + n/2);
            }
        }
    }
    cout << ans << '\n';


}


void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2, 0))); 
    // dp[i][j][j]


    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[0][1][0] = a[0];
    dp[0][1][1] = 1;

    for(int i = 1; i < n; i++){
        // dont take
        if(dp[i - 1][0][0] + dp[i - 1][0][1]  > dp[i - 1][1][1] + dp[i - 1][1][0]){
            dp[i][0][1] = dp[i - 1][0][1];
            dp[i][0][0] = dp[i - 1][0][0]; 
        }
        else{
            dp[i][0][1] = dp[i - 1][1][1];
            dp[i][0][0] = dp[i - 1][1][0];
        }
        // take
        dp[i][1][0] = max(a[i], dp[i - 1][0][0]);
        dp[i][1][1] = dp[i - 1][0][1] + 1;

    }

    cout << max(dp[n - 1][0][1] + dp[n - 1][0][0], dp[n - 1][1][1] + dp[n-1][1][0]) << '\n';



    





}

int main(){
    ll t; cin >> t;
    while(t--) solve2();
}
