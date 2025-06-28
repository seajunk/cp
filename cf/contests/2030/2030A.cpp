#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // b[i] = pfmin[i]
    // c[i] = pfmax[i]

    ll mn = LLONG_MAX, mx = LLONG_MIN;

    for(int i = 0; i < n; i++){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    cout << (n - 1) * (mx - mn) << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
