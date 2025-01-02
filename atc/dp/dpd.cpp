#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    // dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]])

    ll N, W; cin >> N >> W;
    ll w[N], v[N];
    for(int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }

    ll dp[N][W + 1];
    for(int i = 0; i < N; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= W; i++){
        if(w[0] <= i) dp[0][i] = v[0];
        else dp[0][i] = 0;
    }



    for(int i = 1; i < N; i++){
        for(int j = 1; j <= W; j++){
            if(w[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }
    cout << dp[N - 1][W] << '\n';


}
