#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll m, k, a1, ak; cin >> m >> k >> a1 >> ak;

    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(2, vector<ll>(4))); // dp[i][0] = {# of fancy 1 coins used, # of fancy ak coins used, # of regular 1 coins used, # of regular k coins used}
    dp[1][0] = {0, 0, 0, 0};  
    // dp[0][1] = {0, 0, 0, 0}; // doesnt exist until i >= k 

    for(int i = 2; i <= m; i++){
        if(i < k){
            if(dp[i - 1][0][]){}

        }
        else{

        }
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
