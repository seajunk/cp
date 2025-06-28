#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll l, r; cin >> l >> r;

    /*
       find distinct a, b, c /in [l, r] which maximizes (a^b) + (b^c) + (a^c) 

       10101010
       10000000
       10101111

       for each bit, at least one of (a^b), (b^c), (a^c) will be 0


       want each bit to have one or two 1's

       000110101 lower bound

       011100101 // dont touch this guy
       000001000 // use this guy to optimize answer
       011110110 // dont touch this guy

       011101111 upper bound

       we want middle guy to correct any column with no bits

       how to gurantee middle is between l and r?

       m must share the maximal prefix shared between l and r? otherwise m would be smaller than l


       011100101 
       011110000
       011110110


       



       let m have the maximal shared prefix of l and r after which,

       for each index where l[i] == r[i] == 0, set m[i] = 1
       for each index where l[i] == r[i] == 1, set m[i] = 0





       111010 01111

       111010 01111

       111010 10000

       greedy from bottom up?

    */



    bitset<64> lbs(l), rbs(r), xbs(0);

    // first = first index that l and r differ
    int first = 63;
    for(int i = 63; i >= 0 && lbs[i] == rbs[i]; i--){
        xbs[i] = lbs[i];
        first = i - 1;
    }

    /*
       1111 0010111
       1111 1001001

       1111 1000000
       1111 0111111
    */


    xbs[first] = 1;
    ll x = xbs.to_ullong();
    ll y = x - 1;

    ll z = -1;
    for(int i = l; i <= r; i++){
        if(i != x && i != y){
            z = i;
            break;
        }
    }


    cout << x << ' ' << y << ' ' << z << '\n'; 


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

/*
   need column to have eithe one or two 1's && each of x y z need to have the maximal shared prefix of l and r 
   -> idea is to create something like (1000000 ^ 0111111) ie 2^x and 2^x - 1 
   -> give x the shared prefix then for the remaining bits set it to 100000... 
   -> set y to x - 1 so we get 0111111... 
   -> then x and y share no bits after the max prefix, so the choice of z cant mess anything up. then just take z as the smallest number >= l thats not equal to x or y, checks at most two numbers so constant time.
*/
