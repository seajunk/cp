#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*

       1D case.

       Claim. no a[i] will have to be increased more than once ?
       Proof. tba
       

       dp[i][0] = min cost of fixing [0, i] where a[i] gets left alone
       dp[i][1] = min cost of fixing [0, i] where a[i] gets increased

       0 0 0 0 0
       1 2 3 2 1

       dp[0] = {0, 1}
       dp[1] = {1, 2}
       dp[2] = {2, 4}
       dp[3] = {4, 4}
       dp[4] = {4, 5}

       concretely, 

       dp[0] = {0, b[0]};

       if(a[i] == a[i - 1]){
       dp[i][0] = dp[i - 1][1];
       dp[i][1] = cost[i] + dp[i - 1][0];
       }
       else if(a[i] == a[i] - 1){
       dp[i][0] = dp[i - 1][0];
       dp[i][1] = cost[i] + dp[i - 1][1];
       }
       else{
       dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
       dp[i][1] = cost[i] + min(dp[i - 1][0], dp[i - 1][1]);
       }


       2D case.

       how to extend to 2D ?
       since we cant increase each cell, and instead need to increase whole rows and columns, doesnt actually generalize nicely

       1 1 1 = cost
       1 1 1

       1 2 2 = h
       2 2 1
       2 1 1

       1 2
       2 2
       2 1

       dp[i][j][0] = min cost for h[i:j] + nothing
       dp[i][j][1] = min cost for h[i:j] + row
       dp[i][j][2] = min cost for h[i:j] + col
       dp[i][j][3] = min cost for h[i:j] + row col

       transition is gonna be gnarly

       (0 1 1 2) (0 1 1 2) (1 2 1 2)
       (0 1 1 2) (0 0 0 2) (0 0 0 0)
       (1 1 2 2) (0 0 0 0) (0 0 0 0)


    */

    ll n; cin >> n;
    vector<vector<ll>> h(n, vector<ll>(n));
    ll a[n], b[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> h[i][j];
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];


    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(4)));

    for(int i = 0; i < n; i++){
        // fill in top row of dp
    }

    for(int j = 0; j < n; j++){
        // fill in left col of dp
    }



    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){

            /*
               1 2 2
               2 2 1
               2 1 1
            */
            if(h[i][j] == h[i - 1][j]){
                if(h[i][j] == h[i][j - 1]){
                    // we need to increase twice OR
                    // up guy does a row increae AND left guy does a col increase





                }
                else if(h[i][j] == h[i][j - 1] + 1){}
                else{}
            }
            else if(h[i][j] == h[i - 1][j] + 1){
                if(h[i][j] == h[i][j - 1]){}
                else if(h[i][j] == h[i][j - 1] + 1){}
                else{}
            }
            else{
                if(h[i][j] == h[i][j - 1]){}
                else if(h[i][j] == h[i][j - 1] + 1){}
                else{}
            }

        }
    }






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
