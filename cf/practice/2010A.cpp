#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) ans += a[i];
        else ans -= a[i];
    }

    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
