#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){


    /*
       array a[n]. x and y. we want to count number of pairs (i, j) st i < j and removing a[i], a[j] makes sum of a in [x, y].

       brute force would be to fix i and search over all j > i and check if the sum - a[i] - a[j] is in [x, y].
       
       want to do this efficiently

       sort a, fix i, then bs for j? (note order of i and j dont matter since we can just swap them)  

       does this create duplicates? 

       restrict binary search space to (i, n) instead of [0, n) 

       so basically,

       sort a
       fix i
       bs for largest j in (i, n) st sum - a[i] - a[j] >= x 
       bs for smallest j in (i, n) st sum - a[i] - a[j] <= y  

    */


    ll n, x, y; cin >> n >> x >> y;

    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);


    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll curr = sum - a[i];

        ll lo, hi;

        ll lb, ub;


        // get largest j in (i, n) st sum - a[i] - a[j] >= x

        // search space = [i + 1, n - 1]
        lo = i, hi = n - 1;

        while(lo < hi){
            ll j = (hi - lo + 1)/2 + lo;
            if(curr - a[j] >= x) lo = j;
            else hi = j - 1;
        }

        if(lo == i) continue; // no j exists st sum - a[i] - a[j] >= x
        ub = lo;


        // get smallest j in (i, n) st sum - a[i] - a[j] <= y

        // search space = [i + 1, n - 1]

        lo = i + 1, hi = n;

        while(lo < hi){
            ll j = (hi - lo)/2 + lo;
            if(curr - a[j] <= y) hi = j;
            else lo = j + 1;
        }
        if(lo == n) continue; // no j exists st sum - a[i] - a[j] <= y
        lb = lo;

        ans += ub - lb + 1; // add to ans # of guys in [lb, ub]
    }

    cout << ans << '\n';














}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
