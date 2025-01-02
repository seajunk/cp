#include <bits/stdc++.h>
using namespace std;

int countVowelPermutation(int n){

    long long dp[n][5];
    int MOD = 1000000007;

    dp[0][0] = 1; // a
    dp[0][1] = 1; // e
    dp[0][2] = 1; // i
    dp[0][3] = 1; // o
    dp[0][4] = 1; // u

    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][1] % MOD;
        dp[i][1] = (dp[i-1][0] % MOD + dp[i-1][2] % MOD) % MOD;
        dp[i][2] = (dp[i-1][0] % MOD + dp[i-1][1] % MOD + dp[i-1][3] % MOD + dp[i-1][4] % MOD) % MOD;
        dp[i][3] = (dp[i-1][2] % MOD + dp[i-1][4] % MOD) % MOD;
        dp[i][4] = (dp[i-1][0] % MOD) % MOD;
    }



    return (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4]) % MOD;
}
