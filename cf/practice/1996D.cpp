#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, x; cin >> n >> x;

    /*
       need number of triplets (a, b, c) such that 
       (1) a + b + c <= x 
       (2) ab + ac + bc <= n

       fix a

       we know ab <= n
       -> b <= n/a 
       -> # of b's <= n/1 + n/2 + ... + n/n = n (1/1 + 1/2 + ... + 1/n) 
       -> since harmonic series is O(logn), # of b is O(nlogn)
       -> so its posssible to iterate over all possible a and b in nlogn time
       -> with fixed a and b, we can get number of possible c in contant time.
       -> O(nlogn) time
    */
    ll ans = 0;
    for(int a = 1; a <= x - 2; a++){
        for(int b = 1; b <= min(n/a, x - a - 1); b++){
            /*
               we have fixed a and b. 
               need # of c such that
               
               c >= 1
               x - a - b >= 1

               (1) a + b + c <= x 
               (2) ab + ac + bc <= n
               ab + c(a + b) <= n
               c <= (n - ab) / (a + b)
            */

            ans += min(x - a - b, (n - a*b) / (a + b));
        }
    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

/*
   idea is to iterate over a and b efficiently 

   brute force would be O(max(n, x)^2)

   key is to realize that with fixed a, number of possible b is bounded by n/a

   so if we iterate a from 1 to x, the total number of b's we need to check is x/1, x/2, ..., x/x which is xlogx since harmonic series is logx 

   so we can iterate over all valid a and b in xlogx time

*/

