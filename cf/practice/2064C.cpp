#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll pfps[n + 1];
    pfps[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a[i - 1] > 0) pfps[i] = pfps[i - 1] + a[i - 1];
        else pfps[i] = pfps[i - 1];
    }

    ll sfns[n + 1];
    sfns[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] < 0) sfns[i] = sfns[i + 1] + abs(a[i]);
        else sfns[i] = sfns[i + 1];
    }

    ll ans = 0;

    for(int i = 0; i <= n; i++){
        ans = max(ans, pfps[i] + sfns[i]);
    }
    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
