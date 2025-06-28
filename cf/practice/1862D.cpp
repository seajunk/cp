#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void solve(){
    ll n; cin >> n;

    // i distinct balls -> i(i - 1)/2 possible cones
    // want largest i such that i(i - 1)/2 <= n

    ll temp = INT_MAX; // barely any thought behind this
    ll lo = 1, hi = temp;
    while(lo < hi){
        ll i = (hi - lo + 1)/2 + lo;
        if((i*(i-1))/2 <= n) lo = i;
        else hi = i - 1;
    }
    if(lo == 1){
        cout << "shit went wrong\n";
        return;
    }

    ll ans = lo + n - lo*(lo - 1)/2;
    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

