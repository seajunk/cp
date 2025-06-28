#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(k == 1){
        ll ans = a[0]+ a[n - 1];
        for(int i = 1; i < n - 1; i++){
            ans = max(ans, a[i] + max(a[0], a[n - 1]));
        }
        cout << ans << '\n';
        return;

    }

    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = n - 1; i >= n - 1 - k; i--){
        ans += a[i];
    }
    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
