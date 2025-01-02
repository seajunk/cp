#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, k, x; cin >> n >> k >> x;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll ps[n + 1];
    ps[0] = 0;

    for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i - 1];


    ll ans = LLONG_MIN;

    for(int i = 0; i <= k; i++){
        ll first = ps[n - i] - ps[max(0ll, n - i - x)];
        ll second = ps[max(0ll, n - i - x)];
        ans = max(ans, second - first);

    }


    cout << ans << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
