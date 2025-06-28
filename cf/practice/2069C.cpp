#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       beautiful seq are of the form 1, 2 ..., 2, ..., 2, 3
       ie, must start with 1, end with 3. can only have 2 in between
    */

    vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));

    for(int i = 1; i <= n; i++){
        if(a[i - 1] == 1){
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
        }
        else if(a[i - 1] == 2){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0]; 
            dp[i][2] = dp[i - 1][2];
        }
        else{
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1]; 
            dp[i][2] = dp[i - 1][2] + dp[i - 1][1];
        }
        dp[i][0] %= 998244353;
        dp[i][1] %= 998244353;
        dp[i][2] %= 998244353;
    }

    cout << dp[n][2] << '\n';


    /*
       fact which wasnt fully utilized was a[i] /in [1, 2, 3]

       a corollary is that every sequence is in one of 3 phases. the phases can not be reversed ie phase 3 cant go to phase 1 and phase 2 cant go to phase 1

       this lets us count transitions easily
    */
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
