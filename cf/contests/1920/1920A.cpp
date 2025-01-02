#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll lb = LLONG_MIN, ub = LLONG_MAX;
    set<ll> ne;
    for(int i = 0; i < n; i++){
        ll type, x; cin >> type >> x;

        if(type == 1) lb = max(lb, x);
        if(type == 2) ub = min(ub, x);
        if(type == 3) ne.insert(x);
    }

    if(lb > ub) cout << 0 << '\n';
    else{
        ll ans = ub - lb + 1;

        for(ll e : ne){
            if(lb <= e && e <= ub) ans--;
        }
        cout << ans << '\n';
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
