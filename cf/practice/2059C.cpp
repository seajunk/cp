#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    /*
       for each i in [0, n - 1] moment of time,

       a[i] gets added to the queues.
       we choose exactly one queue and clear it

       want to maximize mex of count of people in queues.

       for each queue, some suffix of the column contributes to its final count

       claim. if we are to achieve a mex of x or greater, then for each i in [1, x - 1], the sum i must be obtained from suffix of size i
       proof. suppose we are to acheive mex >= x.
       base case, i = 1. clearly suffix array needs to be size 1 to achieve 1 since each a[i] >= 1 so if suffix is bigger than 1 then sum is bigger.
       inductive case, suppose true for all j < i. then we have that suffix of value < i is already taken. so if we want to find suffix with sum i, we need to look at suffixes with size >= i. then its clear we must take suffix of size i since any larger and our sum would exceed i. 



       iterate from row = 0 to row n

       for(int r = n - 1, r >= 0, r--){
       ll cnt = 0;
       for(int c = 0; c < n; c++) if(sfs[r][c] == n - r) cnt++;

       if(cnt == 0) end


       man fuck this just binary search

       }
    */


    ll sfs[n][n + 1];
    for(int i = 0; i < n; i++) sfs[i][n] = 0;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--) sfs[i][j] = sfs[i][j + 1] + a[i][j];
    }


    ll lo = 0, hi = n;
    while(lo < hi){
        ll mex = (hi - lo + 1)/2 + lo;
        bool works = true;

        for(int j = n - mex + 1; j <= n; j++){
            ll cnt = 0;
            for(int i = 0; i < n; i++) if(sfs[i][j] == n - j) cnt++;
            if(cnt < j - (n - mex + 1) + 1) works = false;
        }
        if(works) lo = mex;
        else hi = mex - 1;
    }
    assert(lo != 0);
    cout << lo << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
