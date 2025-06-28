#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    /*
       1 2 3 4 5 6 7 8 9 10 11 12 13 14 15


                     8                    
             4       8         12         
         2   4   6   8   10    12    14   
       1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

       1 2 3 4 5 6 7 8 9
               5
    
               
       1 2 3 4 5 6 7 8 9



       1 2 3 4 5 6 7 8 9 10

           3         8

       1 2 3 4 5 6 7 8 9 10

       0 2 0 8 




       O. number of 1's bits in n is the number of times n is odd after dividing. This makes sense since n is odd if lsb is 1 and dividing segments is same as n/2 which is same as lshfit by 1


       O. symmetric sums add up to n+1
       eg,
       1 2 3 4 5
       2 + 4 = 6
       1 + 5 = 6

       O. on the i > 1 th operation,  if n is odd, number of symmetric pairs increase by 2^(i - 2)
    */

    ll ans = 0;
    ll symm = n + 1;
    ll pairs = 1;

    if(n % 2 == 1 && n >= k) ans += n/2 + 1; 
    n /= 2;

    while(n >= k){
        if(n % 2 == 1){
            ans += pairs * symm;
        }
        pairs *= 2;
        n /= 2;
    }

    cout << ans << '\n';

}



int main(){
    ll t; cin >> t;
    while(t--) solve();
}
/*
   symmetric pairs sum to n + 1 
   -> number of arrays doubles after each operation 
   -> if we have 2^i arrays currently and each array is odd length, we get 2^(i - 1) new symmetric pairs
   -> can calculate how much sum increase by all segments in constant time 
*/
