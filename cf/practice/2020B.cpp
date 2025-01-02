#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll helper(ll n){
    return floor(sqrtl(n));
}

ll f(ll n){
    return n - helper(n);
}


void solve(){
    ll k; cin >> k;


    ll lo = 1, hi = LLONG_MAX;

    while(lo < hi){
        ll mid = (hi - lo) / 2 + lo;

        if(f(mid) >= k) hi = mid; 
        else lo = mid + 1;
    }


    cout << lo << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


