#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, r; cin >> n >> r;
    ll a[n];

    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        r -= a[i] / 2;
        ans += 2 * (a[i] / 2); 
        a[i] %= 2;
        sum += a[i];
    }

    if(r >= sum) ans += sum;
    else ans += 2*r - sum;

    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
