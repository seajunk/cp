#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve1(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       dp[i] = min cost to make a[i, n) beautiful without removing a[i], if impossible to make a[i, n) beautiful without removing a[i], dp[i] = LLONG_MAX;


       then dp[i] + i is the min cost to turn a beautfiul while fixing a[i] as the first element of the sequence 

       then ans is min(n, min(i + dp[i])) ?





       how to calculate dp[i] ?



       dp[n - 1] = LLONG_MAX; 

       dp[i] = ...

       if(a[i] > n - (i + 1)) dp[i] = LLONG_MAX; // array isnt big enough to fit a[i] guys
       else if(a[i] == n - (i + 1)) dp[i] = 0; // array is beautiful already
       else if(a[i] < n - (i + 1)){
       // array is too big, 

       // dp[i] = min(dp[j] + a[i] + i + 1 - j) for j in [a[i] + i + 1, n - 1]

       // dp[i + a[i] + 1], dp[i + a[i] + 2] + 1, dp[i + a[i] + 3] + 2, ..., dp[n - 1] + (n - (a[i] + i)) 
       // ie 
       // dp[j] + (a[i] + i + 1 - j), for j in [a[i] + i + 1, n - 1]


       // how to get this value ?
       // brute force would be to iterate ove all previous indices j and check dp[j] + (a[i] + i + 1 - j)

       // instead just keep track of min ?

       }
    */



    vector<ll> dp(n);

    dp[n - 1] = INT_MAX;

    for(ll i = n - 2; i >= 0; i--){
        if(a[i] > n - (i + 1)) dp[i] = INT_MAX; // not enough elements in a for a[i] to work (?)
        else if(a[i] == n - (i + 1)) dp[i] = 0; // exactly enough elemts in a for a[i] to work
        else{
            /*
               // O(n^2) approach
               dp[i] = n - (a[i] + i + 1);
               for(ll j = a[i] + i + 1; j < n; j++){
               dp[i] = min(dp[i], dp[j] + j - (a[i] + i + 1));
               }
            */



        } 
    }


    ll ans = n;
    for(int i = 0; i < n; i++){
        cout << dp[i] << ' ';
        ans = min(ans, dp[i] + i);
    }
    cout << '\n';

    cout << ans << '\n';



}


void solve(){
    ll n; cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++) cin >> a[i];


    /*
       dp[i] = min cost to make a[i, n - 1] beautiful


       dp[n - 1] = 1;

       dp[i] = ...

       either 
       (1) a[i, n - 1] is beautiful, ie a[i] == n - (i + 1), dp[i] = 0;
       (2) a[i] is too big. then we are forced to remove a[i] so dp[i] = dp[i + 1] + 1;
       (3) a[i] fits, ie a[i] < n - (i + 1). then we can either remove a[i] or keep a[i] so dp[i] = min(dp[i + 1] + 1, dp[i + 1 + a[i]]);


    */

    vector<ll> dp(n, 0);
    dp[n - 1] = 1;


    for(ll i = n - 2; i >= 0; i--){
        if(a[i] == n - (i + 1)) dp[i] = 0;
        else if(a[i] > n - (i + 1)) dp[i] = dp[i + 1] + 1; 
        else dp[i] = min(dp[i + 1] + 1, dp[i + 1 + a[i]]);
    }


    //for(int i = 0; i < n; i++) cout << dp[i] << ' ';
    //cout << '\n';

    cout << dp[0] << '\n';

}





int main(){
    ll t; cin >> t;
    while(t--) solve();
}
