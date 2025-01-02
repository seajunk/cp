#include <bits/stdc++.h>
using namespace std;


int minSwap(vector<int> &num1, vector<int> &num2){
    int n = num1.size();
    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = 0;
    dp[0][1] = 1; 

    for(int i = 1; i < n; i++){
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;

        if(num1[i] > num1[i-1] && num2[i] > num2[i-1]){
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
            dp[i][1] = min(dp[i][1], dp[i-1][1] + 1); 
        }

        if(num1[i] > num2[i-1] && num2[i] > num1[i-1]){
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
            dp[i][1] = min(dp[i][1], dp[i-1][0] + 1); 
        }
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}

int main(){
    vector<int> num1 = {0, 3, 5, 8, 9};
    vector<int> num2 = {2, 1, 4, 6, 9};
    cout << minSwap(num1, num2) << '\n';
}

// 0 4 4 5 9 
// 0 1 6 8 10
