#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    /*
       array of length n

       binary search possible mex ?
       makes sense that if mex of x isnt possible, x + 1 is also not possible


       when is mex of x possible ?

       each number below x appears atleast once

       need to arrange a such that every element < x can appear at least one time after any way the adversary does m oeprations


       optimal strat for adv to stop mex of x happening is for him to first choose some guy y < x and make sure that after m operations, every y has been removed


       when can adv find such y ?


       8 5 1
       0 1 2 0 1 2 0 1

       note in one operation adv can remove all instances of 2 but if we do

       0 1 2 100 100 0 1 2

       then adv cant find y < x that he can remove completely

       optimal arrangement for mex x is 

       0 1 2 ... x - 1 repeated and spaced out as much as possible ? eg 

       n = 13, x = 3
       0 1 2 x x 0 1 2 x x 0 1 2
       0 1 2 0 1 2 0 1 2 0 1 2 0

       n = 8, x = 3
       0 1 2 100 100 0 1 2

       n = 10, x = 3
       0 1 2 100 0 1 2 0 1 2 0 

       for n and x, how to arrange a?

       idea is that we dont need more than m + 1 copies of any number so
       arrange a such that we have m + 1 copies of 0 1 2 ... x - 1 seperated by misc value with the remaining elements 

       concretely,
       ll m, x, n, k

       if(x * (m + 1) > n) doesnt work

       ll buflen = (n - x*(m + 1))/m // length of buffer between each consec ss
       // 0 1 2 x x 0 1 2 -> len = 2

       // each segment has x + len elements
       ll perop = (k + x + len - 1) / (x + len) // number duplicates adv can remove in one operation


       if(perop > 1){} // doesnt work
       else{} // works

    */

    // maximizing [1, n]
    ll lo = 0, hi = n;
    while(lo < hi){
        ll x = (hi - lo + 1)/2 + lo;
        bool works = true;

        if(x * (m + 1) > n){
            hi = x - 1;
            continue;
        }
        ll buflen = (n - x*(m + 1)) / m;
        ll perop = (k + x + buflen - 1) / (x + buflen);

        if(perop <= 1) lo = x;
        else hi = x - 1;
    }
    if(lo == 0){
        cout << "shit went wrong\n";
        return;
    }
    ll buflen = (n - lo*(m + 1)) / m;

    //cout << "mex = " << lo << '\n';
    for(int i = 0; i < n; i++) cout << (i % (lo + buflen)) << ' ';
    cout << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
