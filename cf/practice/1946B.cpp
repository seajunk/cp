#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod(ll n, ll k){
    return ((n % k) + k) % k;
}

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll mx = LLONG_MIN;
    ll curr = LLONG_MIN;

    for(int i = 0; i < n; i++){
        curr = max(a[i], curr + a[i]);
        mx = max(mx, curr);
    }
    mx = max(0ll, mx);
    ll ans = sum - mx + mx*(1 << k);
    ans = mod(ans, 1000000007);

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
