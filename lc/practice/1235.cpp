#include <bits/stdc++.h>
using namespace std;


int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

    int n = profit.size();
    vector<vector<int>> a(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        a[i][0] = i;
        a[i][1] = endTime[i];
    }

    sort(a.begin(), a.end(), [](auto l, auto r){
            return l[1] < r[1];
            });

    vector<int> dp(n);

    dp[0] = profit[a[0][0]];
    for(int i = 1; i < n; i++){
        // want largest j in [0, i) st a[j][1] <= startTime[a[i][0]]

        int lo = 0, hi = i;

        while(lo < hi){
            int mid = (hi - lo)/2 + lo;

            if(a[mid][1] <= startTime[a[i][0]]) lo = mid + 1;
            else hi = mid;
        }
        int j = lo - 1;
        if(j == -1) dp[i] = profit[a[i][0]];
        else dp[i] = profit[a[i][0]] + dp[j];
        dp[i] = max(dp[i], dp[i - 1]);
    }
    return dp[n - 1];
}
