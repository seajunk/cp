#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       20 10 4

       from i = n - 2 to 0, 
       want to split a[i] such that each piece is <= a[i + 1] and min of pieces is maximized


       if we split a[i] into x bins, optimal way to pack is to go left from right drop guys in bin until a[i] is 0

       binary search for min number of bins in [1, a[i]]


       for a fixed x, x bins are possible if a[i] / x + (a[i] % x != 0) <= a[i + 1]
    */


    ll ans = 0;


    for(int i = n - 2; i >= 0; i--){
        if(a[i] <= a[i + 1]) continue;
        // min for x in [1, a[i]]
        ll lo = 1, hi = a[i] + 1;
        while(lo < hi){
            ll x = (hi - lo) / 2 + lo;
            if(a[i] / x + (a[i] % x != 0) <= a[i + 1]) hi = x;
            else lo = x + 1;
        }
        if(lo == a[i] + 1){
            cout << "shit went wrong\n";
            return;
        }

        ans += lo - 1;
        a[i] = a[i] / lo;
    }

    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';

    printf("%lld\n", ans);
    return;
}

void solve2(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = n - 2; i >= 0; i--){
        // want largest x such that ceil(a[i] / x) <= a[i + 1]
        // makes sense if geometrically in R

        if(a[i] <= a[i + 1]) continue;

        ll x = (a[i] + a[i + 1] - 1)/a[i + 1];
        ans += x - 1;
        a[i] = a[i] / x;
    }


    cout << ans << '\n';


}


int main(){
    ll t; cin >> t;
    while(t--) solve2();
}


/*
   this ones kinda like kar salesman

   idea is, the minimum width w of a rectangle whose height is bounded by some h nad area must be some a is a/h
   which is pretty obvious in R but in N not as obvious that minimal w is ceil(a/h).





*/

