#include <iostream>
#include <climits>
#define ll long long
using namespace std;

void solve(){
    ll n, m; cin >> n >> m;
    m--;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll ans = LLONG_MAX;
    ll at = 0;
    ll over = 0;
    for(int i = n - 1; i >= 0; i--){
        at = a[i] + min(at, over);
        over = over + min(a[i], b[i]);
        if(i <= m) ans = min(ans, at);
    }

    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
