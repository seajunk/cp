#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    ll mx = 0;
    ll total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        total += a[i];
    }


    ll ans = 1;
    for(ll d = 1; d <= n; d++){
        // check if possible to make total divisible by d after spending <= k coins
        if((d - total % d) % d > k) continue;
        // check if total after using maximum number of coins fits max(a)
        ll cnt = ((total + k) / d);
        if(mx > cnt) continue;
        ans = max(d, ans);
    }

    cout << ans << '\n';
}



int main(){
    ll t; cin >> t;
    while(t--) solve();
}


