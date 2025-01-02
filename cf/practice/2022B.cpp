#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, x; cin >> n >> x;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // fact: needs atleast max(a) customers

    // fact: ans * x >= sum(a) so ans >= sum(a)/x => ans >= ceil(sum(a)/x)

    ll mx = 0;
    for(ll e : a) mx = max(mx, e);
    ll sum = 0;
    for(ll e : a) sum += e;
    ll b = (sum + x - 1)/x; // sum/x + x/x - 1/x
    cout << max(mx, b) << '\n';

    // stupid question





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
