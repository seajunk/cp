#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    /*
       dp[i][0] number of configurations of a[0, i] where a[i] is honest
       dp[i][1] number of configurations of a[0, i] where a[i] is a liar whose telling the truth
       dp[i][2] number of configurations of a[0, i] where a[i] is a liar whose lying




       //dp[i][0] ...

       ll possible = 0;

       if(a[i] > i){
       // impossible for a[i] to be true
       dp[i][0] = 0; 


       // impossible for a[i] to be true
       dp[i][1] = 0;



       // liar cant be next to another liar
       dp[i][2] = dp[i - 1][0];

       }
       else if(a[i] == a[i - 1]){
       // possible that a[i - 1] is honest
       // also possible that a[i - 1] is a liar telling a lie
       // impossible for a[i - 1] to be a liar telling the truth, (since then a[i - 1] should be a[i] - 1)
       dp[i][0] = dp[i - 1][0] + dp[i - 1][2];


       // truth
       dp[i][1] = dp[i - 1][0];


       // if a[i] is a lying liar, nessecarily a[i - 1] is honest, but then what a[i] is the truth 
       dp[i][2] = 0;
       }
       else if(a[i] - 1 == a[i - 1]){
       // possible that a[i - 1] is a liar telling the truth
       // impossible for a[i - 1] to be honest
       // impossible for a[i - 1] to be a liar lying
       dp[i][0] = dp[i - 1][1];



       dp[i][1] = 0;


       dp[i][2] = dp[i - 1][0];



       }
       else{ // either a[i - 1] > a[i] or a[i - 1] < a[i] - 1
       // a[i - 1] cant be true since number of liars cant increase and number of liars cant decrease by more tyan one
       dp[i][0] = dp[i - 1][2];


       dp[i][1] = 0;

       dp[i][2] = dp[i - 1][0];


       }
    */


    vector<vector<ll>> dp(n, vector<ll>(2, 0));




    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]){
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = 
        }
    }











}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
    
