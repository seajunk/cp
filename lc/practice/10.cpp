#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p){

    int n = s.size();
    int m = p.size();

    /*
       dp[i][j] = true iff s[0, i) matches p[0, j).

       considering dp[i][j].

       if(p[j - 1] != '*'){
       // works iff dp[i - 1][j - 1] = true and s[i - 1] = p[j - 1]
       continue;
       }


       // p[j - 1] == '*'


       star lets us
       (1) erase p[j - 2] <=> true if dp[i][j - 2] // j - 2 is find since stars cant appear as first character of p
       (2) use p[j - 2] again <=> true iff dp[i - 1][j] and p[j - 2] == s[i - 2] and s[i - 2] == s[i - 1]
       (3) use p[j - 2] once <=> true iff dp[i][j - 1]

    */

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, true));
    dp[0][0] = true;

    // empty pattern
    for(int i = 1; i <= n; i++) dp[i][0] = false;

    // empty string
    for(int j = 1; j <= m; j++){
        if(p[j - 1] != '*') dp[0][j] = false; 
        else dp[0][j] = dp[0][j - 2];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(p[j - 1] != '*'){
                dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                continue;
            }


            // c* = ""
            bool case1 = dp[i][j - 2];

            // c* = cc*
            bool case2 = dp[i - 1][j] && (p[j - 2] == '.' || (p[j - 2] == s[i - 1] && i == 1) || (p[j - 2] == s[i - 1] && s[i - 1] == s[i - 2]));

            // c* = c
            bool case3 = dp[i][j - 1];

            dp[i][j] = case1 || case2 || case3;
        }
    }




    return dp[n][m];
}
