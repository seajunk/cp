#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll l = 0, r = n - 1;

    sort(a, a + n, [](ll l, ll r){ return l > r;});
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans += a[i - 1] - a[i];
    }

    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
