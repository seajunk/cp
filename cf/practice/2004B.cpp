#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll l, r, L, R; cin >> l >> r >> L >> R;

    ll a = max(l, L);
    ll b = min(r, R);

    if(a > b){
        cout << 1 << '\n';
        return;
    }

    ll ans = b - a;

    if(l != L) ans += 1;
    if(r != R) ans += 1;

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
